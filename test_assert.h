#ifndef __TEST_ASSERT_H__
#define __TEST_ASSERT_H__

#include <stdbool.h>
#include <stdio.h>

#define OK        ((puts("OK"), true))
#define FAILED    ((puts("FAILED"), false))
#define ASSERT(e) ((printf(("ASSERT (" #e ") ... ")), ((e) ? OK : FAILED)))

#endif /* __TEST_ASSERT_H__ */
