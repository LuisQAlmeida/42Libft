/* ********************************************************************************************** */
/*                                                                                                */
/*   Libft tests:                                                                                 */
/*                                                                                                */
/*   Recommended usage from the tests directory:                                                  */
/*                                                                                                */
/*   ./run_tests.sh                                                                               */
/*                                                                                                */
/*   Manual compile, from the tests directory:                                                    */
/*   (Requires ../libft/libft.a to exist. Run `make bonus` in ../libft first.)                    */
/*                                                                                                */
/*   cc -Wall -Wextra -Werror -I../libft tests.c ../libft/libft.a -o tests                        */
/*                                                                                                */
/*   Manual Valgrind:                                                                             */
/*                                                                                                */
/*   valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./tests                 */
/*                                                                                                */
/* ********************************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include <unistd.h>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

static int	g_tests = 0;
static int	g_passed = 0;

static void	check_int(const char *name, long got, long expected)
{
	g_tests++;
	if (got == expected)
	{
		g_passed++;
		printf(GREEN "[OK]   " RESET "%s\n", name);
	}
	else
		printf(RED "[FAIL] " RESET "%s | got: %ld expected: %ld\n",
			name, got, expected);
}

static void	check_size(const char *name, size_t got, size_t expected)
{
	g_tests++;
	if (got == expected)
	{
		g_passed++;
		printf(GREEN "[OK]   " RESET "%s\n", name);
	}
	else
		printf(RED "[FAIL] " RESET "%s | got: %zu expected: %zu\n",
			name, got, expected);
}

static void	check_str(const char *name, const char *got, const char *expected)
{
	g_tests++;
	if ((!got && !expected) || (got && expected && strcmp(got, expected) == 0))
	{
		g_passed++;
		printf(GREEN "[OK]   " RESET "%s\n", name);
	}
	else
		printf(RED "[FAIL] " RESET "%s | got: [%s] expected: [%s]\n",
			name, got ? got : "(null)", expected ? expected : "(null)");
}

static void	check_ptr(const char *name, void *got, void *expected)
{
	g_tests++;
	if (got == expected)
	{
		g_passed++;
		printf(GREEN "[OK]   " RESET "%s\n", name);
	}
	else
		printf(RED "[FAIL] " RESET "%s | got: %p expected: %p\n",
			name, got, expected);
}

static void	check_true(const char *name, int condition)
{
	g_tests++;
	if (condition)
	{
		g_passed++;
		printf(GREEN "[OK]   " RESET "%s\n", name);
	}
	else
		printf(RED "[FAIL] " RESET "%s\n", name);
}

static void	free_split_result(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	test_char_functions(void)
{
	printf(YELLOW "\n== Character functions ==\n" RESET);
	check_int("ft_isalpha('A')", ft_isalpha('A'), 1);
	check_int("ft_isalpha('z')", ft_isalpha('z'), 1);
	check_int("ft_isalpha('0')", ft_isalpha('0'), 0);
	check_int("ft_isdigit('5')", ft_isdigit('5'), 1);
	check_int("ft_isdigit('a')", ft_isdigit('a'), 0);
	check_int("ft_isalnum('a')", ft_isalnum('a'), 1);
	check_int("ft_isalnum('7')", ft_isalnum('7'), 1);
	check_int("ft_isalnum('#')", ft_isalnum('#'), 0);
	check_int("ft_isascii(127)", ft_isascii(127), 1);
	check_int("ft_isascii(128)", ft_isascii(128), 0);
	check_int("ft_isprint(32)", ft_isprint(32), 1);
	check_int("ft_isprint(31)", ft_isprint(31), 0);
	check_int("ft_toupper('a')", ft_toupper('a'), 'A');
	check_int("ft_toupper('A')", ft_toupper('A'), 'A');
	check_int("ft_tolower('Z')", ft_tolower('Z'), 'z');
	check_int("ft_tolower('z')", ft_tolower('z'), 'z');
}

static void	test_memory_functions(void)
{
	char	buffer[20];
	char	overlap[20];
	char	overlap2[20];
	char	*calloc_ptr;

	printf(YELLOW "\n== Memory functions ==\n" RESET);
	memset(buffer, 'X', sizeof(buffer));
	check_ptr("ft_memset return value", ft_memset(buffer, 'A', 5), buffer);
	check_true("ft_memset content", memcmp(buffer, "AAAAAX", 6) == 0);
	ft_bzero(buffer, 3);
	check_true("ft_bzero content", buffer[0] == 0 && buffer[1] == 0
		&& buffer[2] == 0 && buffer[3] == 'A');
	strcpy(buffer, "abcdef");
	check_ptr("ft_memcpy return value", ft_memcpy(buffer + 10, buffer, 7),
		buffer + 10);
	check_str("ft_memcpy content", buffer + 10, "abcdef");
	strcpy(overlap, "0123456789");
	ft_memmove(overlap + 2, overlap, 8);
	check_str("ft_memmove forward overlap", overlap, "0101234567");
	strcpy(overlap2, "0123456789");
	ft_memmove(overlap2, overlap2 + 2, 8);
	check_str("ft_memmove backward overlap", overlap2, "2345678989");
	check_ptr("ft_memchr found", ft_memchr("abc", 'b', 3), (void *)("abc" + 1));
	check_ptr("ft_memchr not found", ft_memchr("abc", 'x', 3), NULL);
	check_int("ft_memcmp equal", ft_memcmp("abc", "abc", 3), 0);
	check_true("ft_memcmp different", ft_memcmp("abc", "abd", 3) < 0);
	calloc_ptr = ft_calloc(5, sizeof(char));
	check_true("ft_calloc allocation", calloc_ptr != NULL);
	check_true("ft_calloc zeroed", calloc_ptr && calloc_ptr[0] == 0
		&& calloc_ptr[4] == 0);
	free(calloc_ptr);
	check_ptr("ft_calloc overflow", ft_calloc(SIZE_MAX, 2), NULL);
}

static void	test_string_basic_functions(void)
{
	char	dst[20];
	char	dst2[8];
	char	dst3[4];

	printf(YELLOW "\n== String basic functions ==\n" RESET);
	check_size("ft_strlen empty", ft_strlen(""), 0);
	check_size("ft_strlen hello", ft_strlen("hello"), 5);
	memset(dst, 'X', sizeof(dst));
	check_size("ft_strlcpy return", ft_strlcpy(dst, "hello", sizeof(dst)), 5);
	check_str("ft_strlcpy content", dst, "hello");
	memset(dst2, 'X', sizeof(dst2));
	dst2[0] = '\0';
	check_size("ft_strlcat empty dst", ft_strlcat(dst2, "abc", sizeof(dst2)), 3);
	check_str("ft_strlcat content", dst2, "abc");
	strcpy(dst2, "abc");
	check_size("ft_strlcat append", ft_strlcat(dst2, "defgh", sizeof(dst2)), 8);
	check_str("ft_strlcat truncated content", dst2, "abcdefg");
	strcpy(dst3, "abc");
	check_size("ft_strlcat size too small", ft_strlcat(dst3, "XYZ", 2), 5);
	check_int("ft_strncmp equal", ft_strncmp("abc", "abc", 3), 0);
	check_int("ft_strncmp n zero", ft_strncmp("abc", "xyz", 0), 0);
	check_true("ft_strncmp less", ft_strncmp("abc", "abd", 3) < 0);
	check_ptr("ft_strchr found", ft_strchr("abc", 'b'), (void *)("abc" + 1));
	check_ptr("ft_strchr null terminator", ft_strchr("abc", '\0'),
		(void *)("abc" + 3));
	check_ptr("ft_strchr not found", ft_strchr("abc", 'x'), NULL);
	check_ptr("ft_strrchr last", ft_strrchr("abca", 'a'), (void *)("abca" + 3));
	check_ptr("ft_strrchr not found", ft_strrchr("abc", 'x'), NULL);
	check_ptr("ft_strnstr empty needle", ft_strnstr("abc", "", 3), (void *)"abc");
	check_str("ft_strnstr found", ft_strnstr("hello world", "world", 11), "world");
	check_ptr("ft_strnstr len limited", ft_strnstr("hello world", "world", 5), NULL);
}

static void	test_string_alloc_functions(void)
{
	char	*s;
	char	**split;

	printf(YELLOW "\n== String allocation functions ==\n" RESET);
	s = ft_strdup("hello");
	check_str("ft_strdup", s, "hello");
	free(s);
	s = ft_substr("hello", 1, 3);
	check_str("ft_substr middle", s, "ell");
	free(s);
	s = ft_substr("hello", 10, 3);
	check_str("ft_substr past end", s, "");
	free(s);
	s = ft_substr(NULL, 0, 3);
	check_ptr("ft_substr NULL", s, NULL);
	s = ft_strjoin("hello", " world");
	check_str("ft_strjoin", s, "hello world");
	free(s);
	check_ptr("ft_strjoin NULL left", ft_strjoin(NULL, "x"), NULL);
	check_ptr("ft_strjoin NULL right", ft_strjoin("x", NULL), NULL);
	s = ft_strtrim("xxhelloxx", "x");
	check_str("ft_strtrim trim", s, "hello");
	free(s);
	s = ft_strtrim("xxxx", "x");
	check_str("ft_strtrim all", s, "");
	free(s);
	s = ft_strtrim("", "x");
	check_str("ft_strtrim empty", s, "");
	free(s);
	s = ft_itoa(0);
	check_str("ft_itoa zero", s, "0");
	free(s);
	s = ft_itoa(-2147483648);
	check_str("ft_itoa int min", s, "-2147483648");
	free(s);
	s = ft_itoa(2147483647);
	check_str("ft_itoa int max", s, "2147483647");
	free(s);
	split = ft_split("  hello  world  ", ' ');
	check_true("ft_split allocation", split != NULL);
	if (split)
	{
		check_str("ft_split [0]", split[0], "hello");
		check_str("ft_split [1]", split[1], "world");
		check_ptr("ft_split [2]", split[2], NULL);
		free_split_result(split);
	}
	split = ft_split("", ' ');
	check_true("ft_split empty allocation", split != NULL);
	if (split)
	{
		check_ptr("ft_split empty [0]", split[0], NULL);
		free_split_result(split);
	}
}

static char	map_upper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

static void	iter_upper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

static void	test_string_map_functions(void)
{
	char	*s;
	char	buff[10];

	printf(YELLOW "\n== String map/iter functions ==\n" RESET);
	s = ft_strmapi("abc", map_upper);
	check_str("ft_strmapi", s, "ABC");
	free(s);
	check_ptr("ft_strmapi NULL string", ft_strmapi(NULL, map_upper), NULL);
	check_ptr("ft_strmapi NULL function", ft_strmapi("abc", NULL), NULL);
	strcpy(buff, "abc");
	ft_striteri(buff, iter_upper);
	check_str("ft_striteri", buff, "ABC");
	ft_striteri(NULL, iter_upper);
	ft_striteri(buff, NULL);
	check_true("ft_striteri NULL guards", 1);
}

static int	open_tmp_output_file(void)
{
	int	fd;

	fd = open("libft_output_test_tmp.txt", O_CREAT | O_TRUNC | O_RDWR, 0644);
	check_true("output temp file open", fd >= 0);
	return (fd);
}

static void	read_tmp_output_file(char *buffer, size_t size)
{
	int		fd;
	ssize_t	bytes_read;

	fd = open("libft_output_test_tmp.txt", O_RDONLY);
	check_true("output temp file reopen", fd >= 0);
	if (fd < 0)
	{
		if (size > 0)
			buffer[0] = '\0';
		return ;
	}
	bytes_read = read(fd, buffer, size - 1);
	check_true("output temp file read", bytes_read >= 0);
	if (bytes_read < 0)
		buffer[0] = '\0';
	else
		buffer[bytes_read] = '\0';
	close(fd);
}

static void	test_conversion_and_output_functions(void)
{
	int		fd;
	char	buffer[128];

	printf(YELLOW "\n== Conversion/output functions ==\n" RESET);
	check_int("ft_atoi simple", ft_atoi("42"), 42);
	check_int("ft_atoi spaces", ft_atoi(" \t\n-42abc"), -42);
	check_int("ft_atoi plus", ft_atoi("+123"), 123);
	check_int("ft_atoi no digits", ft_atoi("abc"), 0);
	fd = open_tmp_output_file();
	if (fd < 0)
		return ;
	ft_putchar_fd('A', fd);
	ft_putstr_fd("hello", fd);
	ft_putendl_fd("line", fd);
	ft_putnbr_fd(42, fd);
	close(fd);
	read_tmp_output_file(buffer, sizeof(buffer));
	check_str("fd output functions", buffer, "Ahelloline\n42");
	unlink("libft_output_test_tmp.txt");
}

static void	del_content(void *content)
{
	free(content);
}

static void	*duplicate_int_content(void *content)
{
	int	*src;
	int	*dst;

	src = (int *)content;
	dst = malloc(sizeof(int));
	if (!dst)
		return (NULL);
	*dst = *src + 1;
	return (dst);
}

static void	iter_increment(void *content)
{
	int	*value;

	value = (int *)content;
	(*value)++;
}

static void	test_list_functions(void)
{
	t_list	*list;
	t_list	*mapped;
	int		*a;
	int		*b;

	printf(YELLOW "\n== Linked list functions ==\n" RESET);
	list = NULL;
	a = malloc(sizeof(int));
	b = malloc(sizeof(int));
	check_true("list test allocation", a != NULL && b != NULL);
	if (!a || !b)
	{
		free(a);
		free(b);
		return ;
	}
	*a = 10;
	*b = 20;
	ft_lstadd_front(&list, ft_lstnew(a));
	check_int("ft_lstsize one", ft_lstsize(list), 1);
	ft_lstadd_back(&list, ft_lstnew(b));
	check_int("ft_lstsize two", ft_lstsize(list), 2);
	check_true("ft_lstlast", ft_lstlast(list)->content == b);
	ft_lstiter(list, iter_increment);
	check_int("ft_lstiter first", *(int *)list->content, 11);
	check_int("ft_lstiter second", *(int *)list->next->content, 21);
	mapped = ft_lstmap(list, duplicate_int_content, del_content);
	check_true("ft_lstmap allocation", mapped != NULL);
	if (mapped)
	{
		check_int("ft_lstmap first", *(int *)mapped->content, 12);
		check_int("ft_lstmap second", *(int *)mapped->next->content, 22);
		ft_lstclear(&mapped, del_content);
	}
	ft_lstclear(&list, del_content);
	check_ptr("ft_lstclear result", list, NULL);
	ft_lstadd_front(NULL, NULL);
	check_true("ft_lstadd_front NULL guard", 1);
}

static void	test_printf_functions(void)
{
	int	ret;

	printf(YELLOW "\n== ft_printf functions ==\n" RESET);
	ret = ft_printf("ft_printf visible check: %c %s %d %i %u %x %X %p %%\n",
			'A', "str", -42, 42, 42, 42, 42, (void *)0x1234);
	check_true("ft_printf normal return positive", ret > 0);
	check_int("ft_printf NULL format", ft_printf(NULL), -1);
	check_int("ft_printf invalid format", ft_printf("%q"), -2);
}

static void	test_gnl_functions(void)
{
	int		fd;
	char	*line;

	printf(YELLOW "\n== get_next_line functions ==\n" RESET);
	fd = open("libft_gnl_test_tmp.txt", O_CREAT | O_TRUNC | O_RDWR, 0644);
	check_true("GNL temp file open", fd >= 0);
	if (fd < 0)
		return ;
	write(fd, "first\n\nthird", 12);
	close(fd);
	fd = open("libft_gnl_test_tmp.txt", O_RDONLY);
	check_true("GNL temp file reopen", fd >= 0);
	if (fd < 0)
		return ;
	line = get_next_line(fd);
	check_str("get_next_line first", line, "first\n");
	free(line);
	line = get_next_line(fd);
	check_str("get_next_line empty line", line, "\n");
	free(line);
	line = get_next_line(fd);
	check_str("get_next_line last no newline", line, "third");
	free(line);
	line = get_next_line(fd);
	check_ptr("get_next_line EOF", line, NULL);
	close(fd);
	unlink("libft_gnl_test_tmp.txt");
	check_size("ft_strlen_gnl newline", ft_strlen_gnl("abc\nxyz"), 4);
	check_size("ft_strlen_gnl no newline", ft_strlen_gnl("abc"), 3);
	check_size("ft_strlen_gnl NULL", ft_strlen_gnl(NULL), 0);
}

int	main(void)
{
	printf(YELLOW "Starting Libft tests...\n" RESET);
	test_char_functions();
	test_memory_functions();
	test_string_basic_functions();
	test_string_alloc_functions();
	test_string_map_functions();
	test_conversion_and_output_functions();
	test_list_functions();
	test_printf_functions();
	test_gnl_functions();
	printf(YELLOW "\n== Summary ==\n" RESET);
	printf("%d/%d tests passed\n", g_passed, g_tests);
	if (g_passed == g_tests)
	{
		printf(GREEN "All tests passed.\n" RESET);
		return (0);
	}
	printf(RED "Some tests failed.\n" RESET);
	return (1);
}
