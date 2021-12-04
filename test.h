#ifndef __TEST_H__
#define __TEST_H__

#include <stdbool.h>

typedef struct mapping {
  int number;
  bool (*callback)(void);
} mapping_t;

extern bool testMergeTwoLists(void);                                  /*   21 */
extern bool testMergeKLists(void);                                    /*   23 */
extern bool testHasCycle(void);                                       /*  141 */

#endif /* __TEST_H__ */
