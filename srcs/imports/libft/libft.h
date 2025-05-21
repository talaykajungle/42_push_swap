/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:05:34 by tamutlu           #+#    #+#             */
/*   Updated: 2025/05/21 18:50:38 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "./ft_printf/ft_printf.h"
# include <ctype.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// typedef struct s_list_lib
// {
// 	int				data;
// 	int				index;
// 	struct s_list	*next;
// }					t_list_lib;

size_t				ft_strlen(const char *s);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strdup(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_bzero(void *s, size_t size);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				**ft_split(const char *s, char c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				ft_putendl_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_itoa(int n);
long				ft_atoi(const char *str, int *error);
// long				ft_atoi(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_putchar(char c, int *len);
void				ft_putstr(char *s, int *len);
void				ft_putnbr(int n, int *len);
void				ft_puthex(unsigned int a, char format, int *len);
void				ft_unsigned(unsigned int a, int *len);
void				ft_pointer(uintptr_t ptr, int *len);
void				ft_handle_format(va_list *args, char c, int *len);
int					ft_printf(const char *format, ...);
int					ft_isspace(int c);
// t_list_lib			*ft_lstnew(int data);
// int					printlist(t_list_lib *head);
// int					ft_lstsize(t_list_lib *head);
// int					ft_lstadd_back(t_list_lib **stack, t_list_lib *new);
// t_list_lib			*ft_lstlast(t_list_lib *head);
// t_list_lib			*ft_lstadd_front(t_list_lib **stack, t_list_lib *new);

#endif
