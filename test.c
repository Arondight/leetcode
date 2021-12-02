#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define OK        ((puts("OK"), true))
#define FAILED    ((puts("FAILED"), false))
#define ASSERT(e) ((printf(("ASSERT (" #e ") ... ")), ((e) ? OK : FAILED)))

typedef struct mapping {
  int number;
  bool (*callback)();
} mapping_t;

extern int * twoSum(int * nums, int numsSize, int target, int * returnSize);

bool testTwoSum(void);

int usage(void)
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
  const mapping_t maps[] = {
    { 1, testTwoSum },
  };

  if (argc < 2) {
    exit(usage());
  }

  while (-1 != (opt = getopt_long(argc, (char * const *)argv, optstr, opts, NULL))) {
    switch (opt) {
      case 'n':
        number = atoi(optarg);
        break;
      case 'h':
      default:
        exit(usage());
    }
  }

  for (size_t i = 0; i < sizeof(maps) / sizeof(mapping_t); ++i) {
    if (number == maps[i].number) {
      exit(!(*(maps[i].callback))());
    }
  }

  printf("Unknown problem number %d.\n", number);
  exit(-1);
}

bool testTwoSum(void)
{
  const int target = 9;
  int nums[] = { 2, 7, 11, 15 };
  int returnSize = 0;
  const int * const result = twoSum(nums, sizeof(nums) / sizeof(int), target, &returnSize);

  return ASSERT(NULL != result) &&
         ASSERT(2 == returnSize) &&
         ASSERT(0 == result[0] && 1 == result[1]);
}
