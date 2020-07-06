//  Include the test framework.
#include "unity.h"

// Include the header file with the declarations of the functions you create.
#include "ft_atoi.h"

// Runs before every test.
void setUp(void)
{
}

// Runs after every test.
void tearDown(void)
{
}

void zero(void)
{
    TEST_ASSERT_EQUAL_INT(atoi("0"), ft_atoi("0"));
}

void forty_two(void)
{
    TEST_ASSERT_EQUAL_INT(atoi("42"), ft_atoi("42"));
}

void minus_forty_two(void)
{
    TEST_ASSERT_EQUAL_INT(atoi("-42"), ft_atoi("-42"));
}

void word_in_front(void)
{
    TEST_ASSERT_EQUAL_INT(atoi("school21"), ft_atoi("school21"));
}

void word_after(void)
{
    TEST_ASSERT_EQUAL_INT(atoi("21school"), ft_atoi("21school"));
}

void float_num(void)
{
    TEST_ASSERT_EQUAL_INT(atoi("42.21"), ft_atoi("42.21"));
}

void neg_float_num(void)
{
    TEST_ASSERT_EQUAL_INT(atoi("-0.00003"), ft_atoi("-0.00003"));
}

void plus_after_zeroes(void)
{
    TEST_ASSERT_EQUAL_INT(atoi("0000+3"), ft_atoi("0000+3"));
}

void plus_before_zeroes(void)
{
    TEST_ASSERT_EQUAL_INT(atoi("+00003"), ft_atoi("+00003"));
}

void just_spaces(void)
{
    TEST_ASSERT_EQUAL_INT(atoi("     "), ft_atoi("     "));
}

void number_after_spaces(void)
{
    TEST_ASSERT_EQUAL_INT(atoi("     42"), ft_atoi("     42"));
}

void max(void)
{
    TEST_ASSERT_EQUAL_INT(atoi("2147483647"), ft_atoi("2147483647"));
}

void min(void)
{
    TEST_ASSERT_EQUAL_INT(atoi("-2147483648"), ft_atoi("-2147483648"));
}
