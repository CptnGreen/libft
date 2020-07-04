//  Include the test framework.
#include "unity_v2_5_1/unity.h"

// Include the header file with the declarations of the functions you create.
#include "libft.h"

//
#include <stdlib.h>

// Runs before every test.
void setUp(void)
{
}

// Runs after every test.
void tearDown(void)
{
}

static void zero(void)
{
    TEST_ASSERT_EQUAL_INT(atoi("0"), ft_atoi("0"));
}

static void forty_two(void)
{
    TEST_ASSERT_EQUAL_INT(atoi("42"), ft_atoi("42"));
}

static void minus_forty_two(void)
{
    TEST_ASSERT_EQUAL_INT(atoi("-42"), ft_atoi("-42"));
}

static void word_in_front(void)
{
    TEST_ASSERT_EQUAL_INT(atoi("school21"), ft_atoi("school21"));
}

static void word_after(void)
{
    TEST_ASSERT_EQUAL_INT(atoi("21school"), ft_atoi("21school"));
}

static void float_num(void)
{
    TEST_ASSERT_EQUAL_INT(atoi("42.21"), ft_atoi("42.21"));
}

static void neg_float_num(void)
{
    TEST_ASSERT_EQUAL_INT(atoi("-0.00003"), ft_atoi("-0.00003"));
}

static void plus_after_zeroes(void)
{
    TEST_ASSERT_EQUAL_INT(atoi("0000+3"), ft_atoi("0000+3"));
}

static void plus_before_zeroes(void)
{
    TEST_ASSERT_EQUAL_INT(atoi("+00003"), ft_atoi("+00003"));
}

static void just_spaces(void)
{
    TEST_ASSERT_EQUAL_INT(atoi("     "), ft_atoi("     "));
}

static void number_after_spaces(void)
{
    TEST_ASSERT_EQUAL_INT(atoi("     42"), ft_atoi("     42"));
}

static void max(void)
{
    TEST_ASSERT_EQUAL_INT(atoi("2147483647"), ft_atoi("2147483647"));
}

static void min(void)
{
    TEST_ASSERT_EQUAL_INT(atoi("-2147483648"), ft_atoi("-2147483648"));
}

// Undefined behaviour
static void over_max(void)
{
    TEST_IGNORE();
    TEST_ASSERT_EQUAL_INT(atoi("2147483648"), ft_atoi("2147483648"));
}

// Undefined behaviour
static void less_then_min(void)
{
    TEST_IGNORE();
    TEST_ASSERT_EQUAL_INT(atoi("-2147483649"), ft_atoi("-2147483649"));
}


// Runs the test(s)
int main(void)
{
   UnityBegin("test/test_ft_atoi.c");

   RUN_TEST(zero);
   RUN_TEST(forty_two);
   RUN_TEST(minus_forty_two);
   RUN_TEST(word_in_front);
   RUN_TEST(word_after);
   RUN_TEST(float_num);
   RUN_TEST(neg_float_num);
   RUN_TEST(plus_after_zeroes);
   RUN_TEST(plus_before_zeroes);
   RUN_TEST(just_spaces);
   RUN_TEST(number_after_spaces);
   RUN_TEST(max);
   RUN_TEST(min);

   RUN_TEST(over_max);
   RUN_TEST(less_then_min);

   return UnityEnd();
}
