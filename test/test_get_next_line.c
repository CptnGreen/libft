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

    remove("test/gnl_test.txt");
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

    remove("test/gnl_test.txt");
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

    remove("test/gnl_test.txt");
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


void test_corewar_death_bot_start(void)
{
    size_t	fd;
    char    *line;

    remove("test/gnl_test.txt");
    fd = open("test/gnl_test.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    ft_putstr_fd(".name \"Death\"\n.comment \"Fork\"\n.extend\n", fd);
    lseek(fd, 0, SEEK_SET);
    TEST_ASSERT_EQUAL_INT(1, get_next_line(fd, &line));
    TEST_ASSERT_EQUAL_STRING(".name \"Death\"", line);
    TEST_ASSERT_EQUAL_INT(1, get_next_line(fd, &line));
    TEST_ASSERT_EQUAL_STRING(".comment \"Fork\"", line);
    TEST_ASSERT_EQUAL_INT(1, get_next_line(fd, &line));
    TEST_ASSERT_EQUAL_STRING(".extend", line);
    TEST_ASSERT_EQUAL_INT(0, get_next_line(fd, &line));
    TEST_ASSERT_EQUAL_STRING(".extend", line);
    ft_strdel(&line);
    close(fd);
    remove("test/gnl_test.txt");
}

// void test_gnl_enhanced_1(void)
// {
//     size_t	fd;
//     char    *line;

//     remove("test/gnl_test.txt");
//     fd = open("test/gnl_test.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
//     ft_putstr_fd("text", fd);
//     lseek(fd, 0, SEEK_SET);
//     if (GNL_ENHANCED)
//         TEST_ASSERT_EQUAL_INT(2, get_next_line(fd, &line));
//     else
//         TEST_ASSERT_EQUAL_INT(1, get_next_line(fd, &line));
//     TEST_ASSERT_EQUAL_STRING("text", line);
//     TEST_ASSERT_EQUAL_INT(0, get_next_line(fd, &line));
//     TEST_ASSERT_EQUAL_STRING("text", line);
//     ft_strdel(&line);
//     close(fd);
//     remove("test/gnl_test.txt");
// }

// void test_gnl_enhanced_2(void)
// {
//     size_t	fd;
//     char    *line;

//     remove("test/gnl_test.txt");
//     fd = open("test/gnl_test.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
//     ft_putstr_fd("first\nsecond", fd);
//     lseek(fd, 0, SEEK_SET);
//     TEST_ASSERT_EQUAL_INT(1, get_next_line(fd, &line));
//     TEST_ASSERT_EQUAL_STRING("first", line);
//     if (GNL_ENHANCED)
//         TEST_ASSERT_EQUAL_INT(2, get_next_line(fd, &line));
//     else
//         TEST_ASSERT_EQUAL_INT(1, get_next_line(fd, &line));
//     TEST_ASSERT_EQUAL_STRING("second", line);
//     TEST_ASSERT_EQUAL_INT(0, get_next_line(fd, &line));
//     TEST_ASSERT_EQUAL_STRING("second", line);
//     ft_strdel(&line);
//     close(fd);
//     remove("test/gnl_test.txt");
}