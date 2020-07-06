#include "unity.h"

#include "ft_isdigit.h"

void setUp(void)
{
}

void tearDown(void)
{
}

/*
** According to man this function expects unsigned char
*/

/*
** Is digit:
*/

void test_zero_char(void)
{
    TEST_ASSERT_EQUAL_INT(isdigit('0'), ft_isdigit('0'));
}

void test_three_char(void)
{
    TEST_ASSERT_EQUAL_INT(isdigit('3'), ft_isdigit('3'));
}

/*
** Is not digit:
*/

void test_three_abs(void)
{
    TEST_ASSERT_EQUAL_INT(isdigit(3), ft_isdigit(3));
}

void test_a(void)
{
    TEST_ASSERT_EQUAL_INT(isdigit('a'), ft_isdigit('a'));
}

void test_big_a(void)
{
    TEST_ASSERT_EQUAL_INT(isdigit('A'), ft_isdigit('A'));
}

void test_dot(void)
{
    TEST_ASSERT_EQUAL_INT(isdigit('.'), ft_isdigit('.'));
}

void test_max(void)
{
    TEST_ASSERT_EQUAL_INT(isdigit(UCHAR_MAX), ft_isdigit(UCHAR_MAX));
}

void test_almost_max(void)
{
    TEST_ASSERT_EQUAL_INT(isdigit(UCHAR_MAX - 1), ft_isdigit(UCHAR_MAX - 1));
}

void test_min(void)
{
    TEST_ASSERT_EQUAL_INT(isdigit(0), ft_isdigit(0));
}
