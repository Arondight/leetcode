CHECK	= check
TEST	= test
TEST_C	= $(wildcard $(TEST).c)
SOURCES	= $(sort $(filter-out $(TEST)%, $(wildcard *.c)))
TESTS	= $(sort $(wildcard $(TEST)_*.c))
UTILS = $(sort $(wildcard utils/*.h))

CC	= gcc
FORMATTER	= clang-format
RM	= rm -f
CFLAGS	= -iquote ./utils/ -iquote ./uthash/src/ -std=gnu99 -Wall -Wextra -O1

repeat	= $(shell printf "%0.s$(strip $(1))" {1..$(strip $(2))})


.PHONY: all
all: $(TEST)


$(patsubst %.c, %.d, $(SOURCES:%.c=%.d) $(TESTS:%.c=%.d) $(TEST_C:%.c=%.d)):%.d:%.c
	$(CC) $(CFLAGS) -o $@ -MM $^

include $(SOURCES:%.c=%.d) $(TESTS:%.c=%.d) $(TEST_C:%.c=%.d)


$(TEST): $(SOURCES:%.c=%.o) $(TESTS:%.c=%.o) $(TEST_C:%.c=%.o)
	for file in $^; do \
		ar -rcs $(TEST_C:%.c=%.a) "$$file"; \
	done;

	$(CC) ${CFLAGS} -o $(TEST_C:%.c=%) $(TEST_C:%.c=%.a)


.PHONY: $(CHECK)
$(CHECK): all
	@for id in $(foreach t, $(filter-out $(TEST)_tests.c, $(TESTS)), $(shell echo $(t) | cut -c 6-9)); do \
		echo -e "$(call repeat, =, 80)\nTest for ID $${id}\n$(call repeat, -, 80)"; \
		./$(TEST) -n "$$id" || exit 1; \
	done; \
	\
	echo -e "$(call repeat, =, 80)\nAll passed!\n$(call repeat, =, 80)";


.PHONY: clean
clean:
	@for file in $(SOURCES:%.c=%.o) $(SOURCES:%.c=%.d) \
		     $(TESTS:%.c=%.o) $(TESTS:%.c=%.d) \
		     $(TEST_C:%.c=%.o) $(TEST_C:%.c=%.d) $(TEST_C:%.c=%.a) \
		     $(TEST); do \
		${RM} -f "$$file"; \
	done;


.PHONY: format
format:
	for file in $(SOURCES) $(TESTS) $(TEST_C) $(UTILS); do \
		${FORMATTER} --style file -i "$$file"; \
	done
