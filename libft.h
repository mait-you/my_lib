/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:22:05 by mait-you          #+#    #+#             */
/*   Updated: 2025/04/21 13:24:27 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H 
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <pthread.h>
# include <stdarg.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# ifndef MEMORY_FENCING
#  define MEMORY_FENCING false
# endif

# define SUCCESS 0
# define ERROR 1

# define WARN_NEAR_ALLOC_LIMIT "Warning: nearing allocation limit"
# define WARN_FREE_NULL_PTR "Warning: attempt to free a NULL pointer"
# define WARN_PTR_NOT_ALLOCATED "Warning: pointer was not allocated by \
ft_safe_allocate"
# define ERR_ALLOC_TRACK_LIMIT "Error: allocation tracking limit reached"
# define ERR_CORRUPTION_START "Error: memory corruption detected at START \
guard byte"
# define ERR_CORRUPTION_END "Error: memory corruption detected at END \
guard byte"
# define SPECIFIERS	"cspdiuxX%"
# define X_SPECIFIERS	"0123456789#-+ "

# define HASH_TABLE_SIZE 1024
# define GUARD_SIZE 4
# define GUARD_PATTERN 0xAB

typedef struct s_allocation	t_allocation;
typedef enum e_action		t_action;
typedef struct s_list		t_list;
typedef struct t_key		t_key;

enum e_action
{
	ALLOCATE,
	FREE_ALL,
	FREE_ONE,
	GET_USAGE,
	REALLOC
};

struct t_key
{
	int		plus;
	int		minus;
	int		spase;
	int		hash;
	int		paddin;
	int		to_zero;
};

struct s_list
{
	void			*content;
	struct s_list	*next;
};

struct			s_allocation
{
	void		*original_ptr;
	void		*user_ptr;
	size_t		size;
};

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char	*get_next_line(int fd);

void	*allocate_ptr_memory_fencing(size_t size[2], \
	t_allocation *ptr_array);
void	*free_all_memory_fencing(t_allocation *ptr_array);
void	*free_specific_memory_fencing(t_allocation *ptr_array, \
	const void *ptr);

void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_putendl_fd(char *s, int fd);
int		add_to_tracking(t_allocation *ptr_array, void *original_ptr, \
	void *user_ptr, size_t size[2]);

void	*realloc_ptr(size_t size[2], t_allocation *ptr_array, \
	void *ptr);
void	*allocate_ptr(size_t size[2], t_allocation *ptr_array);
void	*free_all(t_allocation *ptr_array);
void	*free_specific(t_allocation *ptr_array, const void *ptr);
int		get_allocation_count(t_allocation *ptr_array);

size_t	hash_ptr(const void *ptr);

void	*ft_safe_allocate(size_t size[2], t_action action, void *ptr);

int			ft_printf(const char *format, ...);
int			ft_putchr(char c);
int			ft_putstr(char *s);
int			ft_putadress(unsigned long nb);
int			ft_putnbr(int nb);
int			ft_putunbr(unsigned int nb);
int			ft_puthexa(unsigned int nb, char c);
int			ft_extra(const char f_search, t_key key, va_list args);
int			ft_paddin(const char **f, const char *f_search, \
	t_key key, va_list args);
int			ft_putnbr_p(int nb, t_key key, long space_len);
int			ft_putchr_p(char c, t_key key, long space_len);
int			ft_putstr_p(char *str, t_key key, long space_len);
int			ft_putadress_p(unsigned long nb, t_key key, long space_len);
int			ft_putunbr_p(unsigned int nb, t_key key, long space_len);
int			ft_puthexa_p(unsigned int nb, t_key key, \
	long space_len, char f_search);
int			ft_perc_p(t_key key, long space_len, char f_search);
char		*ft_strchr(const char *s, int c);
long		ft_atol(const char *str);
int			ft_putnchr(char c, long n);
const char	*ft_skep_search(const char **f, t_key *key);

#endif
