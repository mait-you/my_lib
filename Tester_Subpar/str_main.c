#include "libft.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>


void ft_putnbr_01(int nb)
{
	char	*_01;

	_01 = "01";
	if (nb >= 2)
		ft_putnbr_01(nb / 2);
	write(1, &_01[nb % 2], 1);
}

int ft_atoi_01(const char *binary_str)
{
    int result = 0;
    while (*binary_str)
    {
        if (*binary_str != '0' && *binary_str != '1')
            return -1;
        result = result * 2 + (*binary_str - '0');
        binary_str++;
    }
    return result;
}


// -L. -lft

int main(void)
{
	//  ===> ft_strlen 
	// char	*str;

	// str = "\0";

	// printf("%zu\n", strlen(str));
	// printf("%zu\n", ft_strlen(str));

	//  ===> ft_memset
	// char str[] = "Hello, World!";

	// memset(str, '0', 5);
	// printf("%s\n", str);

	// char ft_str[] = "Hello, World!";

	// ft_memset(ft_str, '0', -5);
	// printf("%s\n", ft_str);

	// int number;
	// int v[] = {199, 250, 255, 255};
    // char *ptr = (char *)&number;

	// for (int i = 0; i < 4; i++)
	// 	ft_memset(ptr + i, i[v], 1);
    // printf("%d\n", number);

	// printf("%d\n", 3[str]);

	//  ===> ft_bzero
	// char str[] = "Hello, World!";

	// bzero(NULL, 0);
	// printf("%s\n", str);

	// char ft_str[] = "Hello, World!";

	// ft_bzero("", 8);
	// printf("%s\n", ft_str);

	//  ===> ft_memcpy
	// char src[] = "Hello, World!";

	// char det[] = "wiiii";

	// printf("memcpy :%s\n", (char *)memcpy(det, src, 6));
	// printf("memcpy :%s\n", det);

	// char ft_det[] = "wiiii";

	// printf("ft_memcpy :%s\n", (char *)ft_memcpy(ft_det, src, 20));
	// printf("ft_memcpy :%s\n", ft_det);

	// ===> ft_memmove
	// char src[14] = "Hello, World!";

	// char det[30] = "mohamed_is_my_name";
	// // char ptr[0] = "";

	// printf("%s\n", memmove(&det[6], &det[0], 11)); //mohamed_is_ 11
	// printf("%s\n", det); //mohamedmohamed_is_ 7 + 11

	// char ft_det[30] = "mohamed_is_my_name";

	// printf("%s\n", ft_memmove(&ft_det[6], &ft_det[0], 11));
	// printf("%s\n", ft_det); //mohamed

	// ===> ft_memcpy VC ft_memmove
	// char det[30] = "01234567";
	// int det[30] = {0, 1, 2, 3, 4, 5, 6, 7};
	// int i = 0;

	// ft_memmove(det + 4, det, 7);
	// printf("memmove :%s\n", det); //0123______6 => 01230123456
	// while (i <= 30)
	// 	printf("%d", det[i++]);

	// printf("\n");

	// char ft_det[30] = "01234567";
	// int ft_det[30] = {0, 1, 2, 3, 4, 5, 6, 7};
	// i = 0;

	// ft_memcpy(ft_det + 4, ft_det, 7);
	// printf("memcpy  :%s\n", ft_det); //01230123012
	// while (i <= 30)
	// 	printf("%d", ft_det[i++]);

	// ===> ft_strlcpy
	// char src[14] = "Hello, World!";

	// char det[14] = "eefds";

	// printf("%lu\n", strlcpy(det, src, 14));
	// printf("%s\n", det);

	// char ft_det[1] = "fdf";

	// printf("%lu\n", ft_strlcpy(ft_det, src, 14));
	// printf("%s\n", ft_det);

	// ===> ft_strlcat
	// char src[] = "pqrs";

	// char det[] = "abcdefghi";

	// printf("%lu\n", strlcat("pqrs", "abcdefghi", 13));
	// printf("%s\n", det);

	// char ft_det[] = "abcdefghi";

	// printf("%lu\n", ft_strlcat("pqrs", "abcdefghi", 13));
	// printf("%s\n", ft_det);

	// ===> ft_toupper
	// char c = 'q';

	// printf("%c\n", toupper(c));
	// char ft_c = 'q';
	// printf("%c\n", ft_toupper(ft_c));

	// ===> ft_tolower
	// char c = 'q';

	// printf("%c\n", tolower(c));
	// char ft_c = 'q';
	// printf("%c\n", ft_tolower(ft_c));

	// ===> ft_strchr
	// const char *str = "teste";
    //     printf("%s\n", strchr(str, '\0'));

	// const char *ft_str = "teste";
	// printf("%s\n", ft_strchr(ft_str, '\0'));
	// ===> ft_strrchr
	// const char *str = "Hello!, World!";
    //     printf("%s\n", strrchr(str, 0));

	// const char *ft_str = "Hello!, World!";
	// printf("%s\n", ft_strrchr(ft_str, 0));

	// ===> ft_strncmp
	// char str1[] = "Hello";
	// char str2[] = "Hello, World!";

	// printf("%d\n", strncmp(str1, str2, 6));

	// char ft_str1[] = "Hello";
	// char ft_str2[] = "Hello, World!";

	// printf("%d\n", ft_strncmp(ft_str1, ft_str2, 6));

	// ===> ft_memchr
	// const char *str = "he what";
    //     printf("%s\n", memchr(str, '\0', 7));

	// const char *ft_str = "he what";
    //     printf("%s\n", ft_memchr(ft_str, '\0', 7));

	// ===> ft_memcmp
	// char str1[] = "Hello. World!!!";
	// char str2[] = "Hello. World!";

	// printf("%d\n", memcmp(str1, str2, 20));

	// char ft_str1[] = "Hello. World!!!";
	// char ft_str2[] = "Hello. World!";

	// printf("%d\n", ft_memcmp(ft_str1, ft_str2, 20));

	// ft_strnstr
	// char haystack[] = "In order to implement the two following functions";
	// printf("%s\n", strnstr(haystack, "t", 50));

	// char ft_haystack[] = "In order to implement the two following functions";
	// printf("%s\n", ft_strnstr(ft_haystack, "t", 50));

	// ft_atoi
	// printf("%d\n", atoi("1"));
	// printf("%d\n", atoi("123456789"));
	// printf("%d\n", atoi("-123456789"));
	// printf("%d\n", atoi("  -123456789")); //
	// printf("%d\n", atoi(" +123456789"));
	// printf("%d\n", atoi(" -+123456789"));

	// printf("-------------------\n");

	// printf("%d\n", ft_atoi("1"));
	// printf("%d\n", ft_atoi("123456789"));
	// printf("%d\n", ft_atoi("-123456789"));
	// printf("%d\n", ft_atoi("  -123456789")); //
	// printf("%d\n", ft_atoi(" +123456789"));
	// printf("%d\n", ft_atoi(" -+123456789"));

	// ft_calloc
	// int *arr;
    // 	arr = (int *)calloc(0, 0);

	// if (arr == NULL)
	// 	return 1;

	// free(arr);

	// int *arr;
    // 	arr = (int *)ft_calloc(0, 0);

	// if (arr == NULL)
	// 	return 1;

	// free(arr);

	// for (size_t i = 0; i < 5; i++) {
	// 	arr[i] = i;
	// }

	// for (size_t i = 0; i < 5; i++) {
	// 	printf("arr[%zu] = %d\n", i, arr[i]);
	// }

	// free(arr);

	// int *ft_arr;
    // 	ft_arr = (int *)calloc(5, sizeof(int));

	// if (ft_arr == NULL) {
	// 	printf("Memory allocation failed\n");
	// 	return 1;
	// }

	// // for (size_t i = 0; i < 5; i++) {
	// // 	ft_arr[i] = i;
	// // }

	// for (size_t i = 0; i < 5; i++) {
	// 	printf("ft_arr[%zu] = %d\n", i, ft_arr[i]);
	// }

	// free(ft_arr);

	// ft_strdup
	// const char *original = NULL;
	
	// char *copy = strdup(original);
	// if (!copy)
	// 	return 1;

	// printf("Original: %s\n", original);
	// printf("Copy: %s\n", copy);

	// free(copy);
	
	// char *ft_copy = ft_strdup(original);

	// if (!ft_copy) 
	// 	return 1;

	// printf("Original: %s\n", original);
	// printf("Copy: %s\n", ft_copy);

	// free(ft_copy);

	// ft_

}