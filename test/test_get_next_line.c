#include "unity.h"
#include "get_next_line.h"

#include "libft.h"
#include <sys/stat.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_four_line_last_empty(void)
{
    size_t	fd;
    char    *line;

    fd = open("test/gnl_test.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    ft_putstr_fd("First line\nSecond line\nThird line\n\n", fd);
    lseek(fd, 0, SEEK_SET);
    TEST_ASSERT_EQUAL_INT(1, get_next_line(fd, &line));
    TEST_ASSERT_EQUAL_STRING("First line", line);
    TEST_ASSERT_EQUAL_INT(1, get_next_line(fd, &line));
    TEST_ASSERT_EQUAL_STRING("Second line", line);
    TEST_ASSERT_EQUAL_INT(1, get_next_line(fd, &line));
    TEST_ASSERT_EQUAL_STRING("Third line", line);
    TEST_ASSERT_EQUAL_INT(1, get_next_line(fd, &line));
    TEST_ASSERT_EQUAL_STRING("", line);
    TEST_ASSERT_EQUAL_INT(0, get_next_line(fd, &line));
    TEST_ASSERT_EQUAL_STRING("", line);
    ft_strdel(&line);
    close(fd);
    remove("test/gnl_test.txt");
}

void test_two_endl(void)
{
    size_t	fd;
    char    *line;

    fd = open("test/gnl_test.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    ft_putstr_fd("\n\n", fd);
    lseek(fd, 0, SEEK_SET);
    TEST_ASSERT_EQUAL_INT(1, get_next_line(fd, &line));
    TEST_ASSERT_EQUAL_STRING("", line);
    TEST_ASSERT_EQUAL_INT(1, get_next_line(fd, &line));
    TEST_ASSERT_EQUAL_STRING("", line);
    TEST_ASSERT_EQUAL_INT(0, get_next_line(fd, &line));
    TEST_ASSERT_EQUAL_STRING("", line);
    ft_strdel(&line);
    close(fd);
    remove("test/gnl_test.txt");
}

void test_sentence_then_two_endl(void)
{
    size_t	fd;
    char    *line;

    fd = open("test/gnl_test.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    ft_putstr_fd("First line\n\n", fd);
    lseek(fd, 0, SEEK_SET);
    TEST_ASSERT_EQUAL_INT(1, get_next_line(fd, &line));
    TEST_ASSERT_EQUAL_STRING("First line", line);
    TEST_ASSERT_EQUAL_INT(1, get_next_line(fd, &line));
    TEST_ASSERT_EQUAL_STRING("", line);
    TEST_ASSERT_EQUAL_INT(0, get_next_line(fd, &line));
    TEST_ASSERT_EQUAL_STRING("", line);
    ft_strdel(&line);
    close(fd);
    remove("test/gnl_test.txt");
}