#include "unity.h"

#include "ft_isalnum.h"

TEST_FILE("ft_isdigit.c")
TEST_FILE("ft_isalpha.c")

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
** Is alnum:
*/

void test_zero_char(void)
{
    TEST_ASSERT_EQUAL_INT(isalnum('0'), ft_isalnum('0'));
}

void test_three_char(void)
{
    TEST_ASSERT_EQUAL_INT(isalnum('3'), ft_isalnum('3'));
}

void test_a(void)
{
    TEST_ASSERT_EQUAL_INT(isalnum('a'), ft_isalnum('a'));
}

void test_big_a(void)
{
    TEST_ASSERT_EQUAL_INT(isalnum('A'), ft_isalnum('A'));
}

/*
** Is not alnum:
*/

void test_three_abs(void)
{
    TEST_ASSERT_EQUAL_INT(isalnum(3), ft_isalnum(3));
}

void test_dot(void)
{
    TEST_ASSERT_EQUAL_INT(isalnum('.'), ft_isalnum('.'));
}

void test_max(void)
{
    TEST_ASSERT_EQUAL_INT(isalnum(UCHAR_MAX), ft_isalnum(UCHAR_MAX));
}

void test_almost_max(void)
{
    TEST_ASSERT_EQUAL_INT(isalnum(UCHAR_MAX - 1), ft_isalnum(UCHAR_MAX - 1));
}

void test_min(void)
{
    TEST_ASSERT_EQUAL_INT(isalnum(0), ft_isalnum(0));
}
