#include "libft.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

// -L. -lft
char transform__toupper(unsigned int i, char c)
{
    if (i % 2 == 0)
        return (ft_toupper(c));
    return (c);
}

void to_upper_even(unsigned int i, char *c)
{
    if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
        *c = (char)ft_toupper(*c);
}

static int	count_words(char const *s, char c)
{
	int	count;
	int	key;

	count = 0;
	key = 1;
	while (*s)
	{
		if (*s != c && key)
		{
			count++;
			key = !key;
		}
		if (*s == c && !key)
			key = !key;
		s++;
	}
	return (count);
}


int main(void)
{
	// ===> ft_substr
	// char s[] = "Bonjour comment ca va?"; // ur comme
	// char *substr = ft_substr(s, 5, 30);
	// printf("%s\n", substr);
	// free(substr);

	// ===> ft_strjoin
	// char *s1 = "tyu";
	// char *s2 = NULL;
	// char *s_join;

	// s_join = ft_strjoin(s1, s2);
	// printf("%s\n", s_join);
	// free(s_join);
	// printf("%lu", ft_strlen(s2));
    // char last  = 'r';
    // printf("%zu\n", ft_strlen(&last));
    // char *ptr = ft_strjoin(name, &last);

	// ===> ft_strtrim
	// char *s = NULL;
    // char *set = "456_";
    // char *trim;

    // trim = ft_strtrim(s, set);
    // printf("%s\n", s);
    // printf("%s\n", trim);
    // free(trim);
	// ===> ft_split
	char *s = "hello!";
	char **split;

	split = ft_split(s, ' ');
	int i = 0;
	while (i < count_words(s, ' ') + 1)
		printf("%s\n", split[i++]);
	i = 0;
	while (i < count_words(s, ' ') + 1)
		free(split[i++]);
	free(split);

	// ===> ft_itoa
	// int x = 1;
    // char *str = ft_itoa(x);
    // printf("%s\n", str);

	// ft_strmapi
	// char *original = "hello world";
    // char *modified;

    // modified = ft_strmapi(original, transform__toupper);
    // if (!modified )
	// 	return (-1);

    // printf("Original: %s\n", original);
    // printf("Modified: %s\n", modified);
    // free(modified);
	
	// ===> ft_striteri
	// char s[] = "hello world!";
    
    // printf("%s\n", s);
    // ft_striteri(s, to_upper_even);
    // printf("%s\n", s);

	/*
	O_RDONLY: 0
	O_WRONLY: 1
	O_RDWR: 2
	O_CREAT: 3
		/
		4: R
		2: w
		1: E (execution)

		Owner
		Group
		Others

		0 O G O
		/
	O_EXCL: 128 => used wiht O_CREAT for not create the file if it exists
	O_TRUNC: 512 => remove fill centent
	O_APPEND: 1024 => add centent im end of fill
	*/

	// ===> ft_putchar_fd
	// int fd = open("test.txt", O_WRONLY);
	// ft_putchar_fd('c', fd);
	// close(fd);

	// ===> ft_putstr_fd
	// int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// ft_putstr_fd("Wiiiiiiiiiiiiiiii3", fd);
	// close(fd);

	// // ===> ft_putendl_fd
	// int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// ft_putendl_fd("Wiiiiiiiiiiiiiiii3", fd);
	// close(fd);

	// ===> ft_putnbr_fd
	// int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// ft_putnbr_fd(-2147483648, fd);
	// close(fd);

}
