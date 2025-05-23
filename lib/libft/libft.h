/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:56:50 by nicolmar          #+#    #+#             */
/*   Updated: 2024/11/05 10:09:23 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <bsd/string.h>
# include <unistd.h>
# include <fcntl.h>
# include <ctype.h>
# include <stdarg.h>
# include <limits.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int			ft_atoi(const char *nptr);
void		*ft_bzero(void *str, size_t n );
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
void		*ft_memchr(const void *mB, int sC, size_t size);
int			ft_memcmp(const void *str1, const void *str2, size_t size);
void		*ft_memcpy(void *dest, const void *src, size_t size);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *str, int v, size_t n);
char		*ft_strchr(const char *str, int schar);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
int			ft_strlen(const char *str);
int			ft_strncmp( const char *first, const char *second, size_t length);
char		*ft_strnstr(const char *find, const char *search, size_t len);
char		*ft_strrchr(const char *str, int schar);
int			ft_tolower(int c);
int			ft_toupper(int c);
void		*ft_calloc(size_t elementCount, size_t elementSize);
char		*ft_strdup(const char *src);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(long n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strldup(const char *src, size_t len);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void		ft_putchar(char c);
void		ft_putstr(char *s);
char		*ft_usitoa(unsigned int n);
long		printpoint(char c, unsigned long d);
int			printhexa(char c, unsigned int d);
int			printchar(char c);
int			ft_printf(const	char *format, ...);
int			printint(int d);
int			printusint(unsigned int d);
int			printspace(int minlen, int countemp);
int			printstr(char *str);
int			pre_printpoint(char c, unsigned long p);
int			printzero(int minlen, int countemp);
char		*get_next_line(int fd);
int			ft_not_in_set(char const *s, char const *set);
long		ft_atol(const char *nptr);
void		ft_free_array(void **array);

#endif // FT_PRINTF_H