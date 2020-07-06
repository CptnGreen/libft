#include "unity.h"

#include "ft_isalpha.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_zero(void)
{
    TEST_ASSERT_EQUAL_INT(isalpha('0'), ft_isalpha('0'));
}

void test_a(void)
{
    TEST_ASSERT_EQUAL_INT(isalpha('a'), ft_isalpha('a'));
}

void test_big_a(void)
{
    TEST_ASSERT_EQUAL_INT(isalpha('A'), ft_isalpha('A'));
}

void test_dot(void)
{
    TEST_ASSERT_EQUAL_INT(isalpha('.'), ft_isalpha('.'));
}

/*
** According to man this function expects unsigned char
*/

void test_max(void)
{
    TEST_ASSERT_EQUAL_INT(isalpha(UCHAR_MAX), ft_isalpha(UCHAR_MAX));
}

void test_almost_max(void)
{
    TEST_ASSERT_EQUAL_INT(isalpha(UCHAR_MAX - 1), ft_isalpha(UCHAR_MAX - 1));
}

void test_min(void)
{
    TEST_ASSERT_EQUAL_INT(isalpha(0), ft_isalpha(0));
}
