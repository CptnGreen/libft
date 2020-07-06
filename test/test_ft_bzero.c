#include "unity.h"

#include "ft_bzero.h"

TEST_FILE("ft_memset.c")

void setUp(void)
{
}

void tearDown(void)
{
}

void test_one_byte(void)
{
    void	*ptr1;
    void	*ptr2;

    ptr1 = malloc(1);
    ptr2 = malloc(1);
    bzero(ptr1, 1);
    ft_bzero(ptr2, 1);
    TEST_ASSERT_EQUAL_MEMORY(ptr1, ptr2, 1);
    free(ptr1);
    free(ptr2);
    ptr1 = (void *)0;
    ptr2 = (void *)0;
}

void test_forty_two_bytes(void)
{
    void	*ptr1;
    void	*ptr2;

    ptr1 = malloc(42);
    ptr2 = malloc(42);
    bzero(ptr1, 42);
    ft_bzero(ptr2, 42);
    TEST_ASSERT_EQUAL_MEMORY(ptr1, ptr2, 42);
    free(ptr1);
    free(ptr2);
    ptr1 = (void *)0;
    ptr2 = (void *)0;
}

void test_million_bytes(void)
{
    void	*ptr1;
    void	*ptr2;

    ptr1 = malloc(1000000);
    ptr2 = malloc(1000000);
    bzero(ptr1, 1000000);
    ft_bzero(ptr2, 1000000);
    TEST_ASSERT_EQUAL_MEMORY(ptr1, ptr2, 1000000);
    free(ptr1);
    free(ptr2);
    ptr1 = (void *)0;
    ptr2 = (void *)0;
}
