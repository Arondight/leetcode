TEST	= test
TEST_C	= $(wildcard $(TEST).c)
SOURCES	= $(sort $(filter-out $(TEST)%, $(wildcard *.c)))
TESTS	= $(sort $(wildcard $(TEST)_*.c))

CC	= gcc
RM	= rm -f
CFLAGS	= -iquote ./utils/ -iquote ./uthash/src/ -std=gnu99 -Wall -Wextra -O1

repeat	= $(shell printf "%0.s$(strip $(1))" {1..$(strip $(2))})


.PHONY: all
all: $(TEST_C)

$(patsubst %.c, %.d, $(SOURCES:%.c=%.d) $(TESTS:%.c=%.d)):%.d:%.c
	$(CC) $(CFLAGS) -o $@ -MM $^

include $(SOURCES:%.c=%.d) $(TESTS:%.c=%.d)

$(TEST_C): $(SOURCES:%.c=%.o) $(TESTS:%.c=%.o)
	$(CC) ${CFLAGS} -o $(TEST_C:%.c=%) $^ $@


.PHONY: $(TEST)
$(TEST): all
	@for id in $(foreach t, $(filter-out $(TEST)_tests.c, $(TESTS)), $(shell echo $(t) | cut -c 6-9)); do \
		echo -e "$(call repeat, =, 80)\nTest for ID $${id}\n$(call repeat, -, 80)"; \
		./$(TEST) -n "$$id" || exit 1; \
	done; \
	\
	echo -e "$(call repeat, =, 80)\nAll passed!\n$(call repeat, =, 80)";


.PHONY: clean
clean:
	@${RM} $(TEST_C:%.c=%) $(SOURCES:%.c=%.o) $(TESTS:%.c=%.o) $(SOURCES:%.c=%.d) $(TESTS:%.c=%.d)
