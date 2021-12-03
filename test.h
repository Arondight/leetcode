#ifndef __TEST_H__
#define __TEST_H__

#include <stdbool.h>

typedef struct mapping {
  int number;
  bool (*callback)(void);
} mapping_t;

extern bool testTwoSum(void);
extern bool testMergeTwoLists(void);

#endif /* __TEST_H__ */
