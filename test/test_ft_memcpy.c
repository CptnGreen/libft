#include "unity.h"

#include "ft_memcpy.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_thirty_bytes(void)
{
    void    *src;
    void    *dst;

    src = ft_memalloc(50);
    dst = ft_memalloc(50);
    memset(src, 'a', 50);
    ft_memcpy(dst, src, 30);
    TEST_ASSERT_EQUAL_MEMORY(src, dst, 30);
}