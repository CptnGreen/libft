#include "unity.h"

#include "ft_strsub.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_easy_peasy(void)
{
    char    s1[] = "ololo";
    char    *s2;

    TEST_ASSERT_NOT_NULL((s2 = ft_strsub(s1, 0, 3)));
    TEST_ASSERT_EQUAL_STRING("olo", s2);
    ft_strdel(&s2);
}

void test_corewar1(void)
{
    char    s1[] = "text # comment\n";
    char    *s2;
    char    *tmp;

    tmp = ft_strchr(s1, '#');
    TEST_ASSERT_NOT_NULL((s2 = ft_strsub(s1, 0, ft_strlen(s1) - ft_strlen(tmp))));
    TEST_ASSERT_EQUAL_STRING("text ", s2);
    ft_strdel(&s2);
}

void test_corewar2(void)
{
    char    s1[] = "text #";
    char    *s2;
    char    *tmp;

    tmp = ft_strchr(s1, '#');
    TEST_ASSERT_NOT_NULL((s2 = ft_strsub(s1, 0, ft_strlen(s1) - ft_strlen(tmp))));
    TEST_ASSERT_EQUAL_STRING("text ", s2);
    ft_strdel(&s2);
}

void test_corewar3(void)
{
    char    s1[] = "# comment";
    char    *s2;
    char    *tmp;

    tmp = ft_strchr(s1, '#');
    TEST_ASSERT_NOT_NULL((s2 = ft_strsub(s1, 0, ft_strlen(s1) - ft_strlen(tmp))));
    TEST_ASSERT_EQUAL_STRING("", s2);
    ft_strdel(&s2);
}