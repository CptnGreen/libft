#include "unity.h"

#include "ft_strjoin.h"

TEST_FILE("ft_strlen.c")
TEST_FILE("ft_strnew.c")
TEST_FILE("ft_strncpy.c")
TEST_FILE("ft_strlcat.c")

void setUp(void)
{
}

void tearDown(void)
{
}

void test_olo_lo(void)
{
    char	*str;

    str = ft_strjoin("olo", "lo");
    TEST_ASSERT_EQUAL_STRING("ololo", str);
    free(str);
    str = (char *)0;
}

void test_o_lolo(void)
{
    char	*str;

    str = ft_strjoin("o", "lolo");
    TEST_ASSERT_EQUAL_STRING("ololo", str);
    free(str);
    str = (char *)0;
}

void test_empty_ololo(void)
{
    char	*str;

    str = ft_strjoin("", "ololo");
    TEST_ASSERT_EQUAL_STRING("ololo", str);
    free(str);
    str = (char *)0;
}

void test_ololo_empty(void)
{
    char	*str;

    str = ft_strjoin("ololo", "");
    TEST_ASSERT_EQUAL_STRING("ololo", str);
    free(str);
    str = (char *)0;
}

void test_empty_empty(void)
{
    char	*str;

    str = ft_strjoin("", "");
    TEST_ASSERT_EQUAL_STRING("", str);
    free(str);
    str = (char *)0;
}

void test_null_ololo(void)
{
    char	*str;

    str = ft_strjoin((char *)0, "ololo");
    TEST_ASSERT_NULL(str);
}

void test_ololo_null(void)
{
    char	*str;

    str = ft_strjoin("ololo", (char *)0);
    TEST_ASSERT_NULL(str);
}
