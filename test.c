#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "test.h"

extern const mapping_t tests[];
extern size_t testsSize;

static int usage(void)
{
  const char * const text[] = {
    "Options:",
    "  --problem-number, -n\t\tLeetCode problem id",
    "  --help, -h\t\t\tshow this help",
    NULL
  };

  for (size_t i = 0; text[i]; ++i) {
    puts(text[i]);
  }

  return -1;
}

int main(const int argc, const char * const * argv)
{
  int opt = 0;
  int number = 0;
  const char optstr[] = "n:h";
  const struct option opts[] = {
    { "problem-number", required_argument, 0, 'n' },
    { "help", no_argument, 0, 'h' },
    { 0, 0, 0, 0 }
  };

  if (argc < 2) {
    return usage();
  }

  while (-1 != (opt = getopt_long(argc, (char * const *)argv, optstr, opts, NULL))) {
    switch (opt) {
      case 'n':
        number = atoi(optarg);
        break;
      case 'h':
      default:
        return usage();
    }
  }

  for (size_t i = 0; i < testsSize; ++i) {
    if (number == tests[i].number) {
      return !(*(tests[i].callback))();
    }
  }

  printf("Unknown problem number %d.\n", number);
  return -1;
}
