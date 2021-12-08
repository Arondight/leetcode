TEST	= test
TEST_C	= ./$(TEST).c
SOURCES	= $(shell find ./ -maxdepth 1 -type f -name '*.c' ! -name '$(TEST)*.c')
TESTS	= $(shell find ./ -maxdepth 1 -type f -name '$(TEST)_*.c')

CC	= gcc
RM	= rm -f
CFLAGS	= -iquote ./utils/ -iquote ./uthash/src/ -std=gnu99 -Wall -Wextra -O1


.PHONY: all
all: $(TEST_C)

$(SOURCES:.c=.d):%.d:%.c
	$(CC) $(CFLAGS) -o $@ -MM $^

$(TESTS:.c=.d):%.d:%.c
	$(CC) $(CFLAGS) -o $@ -MM $^

include $(SOURCES:.c=.d)
include $(TESTS:.c=.d)

$(TEST_C): $(SOURCES:.c=.o) $(TESTS:.c=.o)
	$(CC) ${CFLAGS} -o $(TEST_C:.c=) $^ $@


.PHONY: test
test: all
	for t in $(TESTS); do \
		id=$$(echo "$$t" | grep -oP '(?<=test_)\d+(?=_)'); \
		\
		if [[ -n "$$id" ]]; then \
			echo -e $$_{1..100}"\b="; \
			echo "Test for ID $${id}"; \
			echo -e $$_{1..100}"\b-"; \
			$(TEST_C:.c=) -n "$$id"; \
			\
			if [[ 0 -ne "$$?" ]]; then \
				exit -1; \
			fi \
		fi \
	done


.PHONY: clean
clean:
	@${RM} $(TEST_C:.c=) $(SOURCES:.c=.o) $(TESTS:.c=.o) $(SOURCES:.c=.d) $(TESTS:.c=.d)
