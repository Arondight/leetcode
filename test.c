#include "test.h"
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern const test_t tests[];
extern const size_t testsSize;

static int usage(void)
{
  const char *const text[] = { "options:", "  --problem-id, -n     LeetCode problem ID",
    "  --help, -h           show this help", NULL };

  for (size_t i = 0; text[i]; ++i) {
    puts(text[i]);
  }

  return -1;
}

int main(const int argc, const char *const *argv)
{
  int opt = 0;
  int id = 0;
  const char optstr[] = "n:h";
  const struct option opts[] = { { "problem-id", required_argument, 0, 'n' }, { "help", no_argument, 0, 'h' },
    { 0, 0, 0, 0 } };

  if (argc < 2) {
    return usage();
  }

  while (-1 != (opt = getopt_long(argc, (char *const *)argv, optstr, opts, NULL))) {
    switch (opt) {
      case 'n':
        id = atoi(optarg);
        break;
      case 'h':
      default:
        return usage();
    }
  }

  for (size_t i = 0; i < testsSize; ++i) {
    if (id == tests[i].id) {
      return !(*(tests[i].handler))();
    }
  }

  printf("Unknown problem id %d.\n", id);
  return -1;
}
