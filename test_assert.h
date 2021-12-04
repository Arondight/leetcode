#ifndef __TEST_ASSERT_H__
#define __TEST_ASSERT_H__

#include <stdbool.h>
#include <stdio.h>

#define ASSERT_OK       ((puts("OK"), true))
#define ASSERT_FAILED   ((puts("FAILED"), false))
#define ASSERT(e)       ((printf(("ASSERT (" #e ") ... ")), ((e) ? ASSERT_OK : ASSERT_FAILED)))

#endif /* __TEST_ASSERT_H__ */
