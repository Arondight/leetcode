TEST_C	= ./test.c
SOURCES	= $(shell find ./ -maxdepth 1 -type f -name '*.c' ! -name $(notdir $(TEST_C)))

CC	= gcc
RM	= rm -f
CFLAGS	= -I ./uthash/src/ -std=gnu99 -Wall -Wextra -O1


.PHONY: all
all: $(TEST_C)

$(SOURCES:.c=.d):%.d:%.c
	$(CC) $(CFLAGS) -o $@ -MM $^

include $(SOURCES:.c=.d)

$(TEST_C): $(SOURCES:.c=.o)
	$(CC) ${CFLAGS} -o $(TEST_C:.c=) $^ $@


.PHONY: clean
clean:
	@${RM} $(TEST_C:.c=) $(SOURCES:.c=.o) $(SOURCES:.c=.d)
