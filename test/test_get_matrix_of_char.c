#include "unity.h"

#include "get_matrix_of_char.h"

TEST_FILE("ft_strnew.c")
TEST_FILE("wipe_mstr.c")
TEST_FILE("ft_strdel.c")

void setUp(void)
{
}

void tearDown(void)
{
}

void test_dots_2x2(void)
{
    char	**m;

    m = get_matrix_of_char(2, 2, '.');
    TEST_ASSERT_EQUAL_STRING("..", m[0]);
    TEST_ASSERT_EQUAL_STRING("..", m[1]);
    wipe_mstr(m);
}

void test_dots_2x0(void)
{
    char	**m;

    m = get_matrix_of_char(2, 0, '.');
    TEST_ASSERT_EQUAL_STRING("", m[0]);
    TEST_ASSERT_EQUAL_STRING("", m[1]);
    wipe_mstr(m);
}

void test_dots_0x2(void)
{
    char	**m;

    m = get_matrix_of_char(0, 2, '.');
    TEST_ASSERT_NULL(m);
}
