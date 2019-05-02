/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:38:18 by slisandr          #+#    #+#             */
/*   Updated: 2019/04/18 20:46:11 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define MIN_OF_TWO(Value1, Value2) ((Value1 < Value2) ? (Value1) : (Value2))
# define MAX_OF_TWO(Value1, Value2) ((Value1 > Value2) ? (Value1) : (Value2))
# define ABS(Value) ((Value >= 0) ? (Value) : (Value * (-1)))

void		ft_putchar(char c);
void		ft_putstr(char const *str);
void		ft_putnbr(int n);

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char const *str, int fd);
void		ft_putnbr_fd(int n, int fd);

void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *restrict dst, void const *restrict src, size_t n);
void		*ft_memccpy(void *dest, void const *src, int c, size_t n);
void		*ft_memmove(void *dest, void const *src, size_t n);

int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);

int		ft_isdigit(int c);

int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(char const *str);
char		*ft_itoa(int n);

size_t		ft_strlen(char const *str);
char		*ft_strdup(const char *s1);

char		*ft_strcat(char *restrict s1, char const *restrict s2);
char		*ft_strncat(char *restrict s1, char const *restrict s2, size_t n);
size_t		ft_strlcat(char *dst, char const *src, size_t size);

int		ft_strcmp(char const *s1, char const *s2);
int		ft_strncmp(char const *s1, char const *s2, size_t n);
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);

char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);

char		*ft_strstr(char const *haystack, char const *needle);
char		*ft_strnstr(char const *haystack, char const *needle, size_t len);

char		*ft_strcpy(char *dst, char const *src);
char		*ft_strncpy(char *dst, char const *src, size_t len);
size_t		ft_strlcpy(char *dst, char const *src, size_t size);

void		ft_memdel(void **ap);
void		ft_strdel(char **as);
void		ft_strclr(char *s);

void		*ft_memalloc(size_t size);
char		*ft_strnew(size_t size);

void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s);
char		**ft_strsplit(char const *s, char c);

#endif
