#ifndef __TEST_H__
#define __TEST_H__

#include <stdbool.h>

typedef struct mapping {
  int number;
  bool (*callback)(void);
} mapping_t;

extern bool testRemoveNthFromEnd(void);                               /*   19 */
extern bool testMergeTwoLists(void);                                  /*   21 */
extern bool testMergeKLists(void);                                    /*   23 */
extern bool testHasCycle(void);                                       /*  141 */
extern bool testDetectCycle(void);                                    /*  142 */
extern bool testMiddleNode(void);                                     /*  876 */

#endif /* __TEST_H__ */
