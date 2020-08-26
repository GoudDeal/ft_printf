/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:28:40 by dcyprien          #+#    #+#             */
/*   Updated: 2020/08/20 16:20:47 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define TYPE "cspdiuxX%"
# define FLAGS "-.*0"
# define HEXA "0123456789abcdef"
# define HEXA_MAJ "0123456789ABCDEF"
# define INT_M 2147483647
# define MIN_I -2147483648

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_format
{
	char			type;
	int				prec_size;
	int				padding;
	int				inversed;
	int				width;
	int				precision;
	int				min;
	char			fill;
	int				width_star;
	int				precision_star;
	int				writecount;
	int				precision_default;
	int				int_zero;
	int				set_width;
	int				set_min;
}					t_format;

void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_bzero(void *s, size_t n);
size_t				ft_strlen(const char *s);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strnstr(const char *haystack, const char *needle,
size_t len);
int					ft_atoi(const char *str);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start,
size_t len);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_putchar_fd(char c, int fd, t_format format);
int					ft_putstr_fd(char *s, int fd, t_format format);
void				ft_putendl_fd(char *s, int fd, t_format format);
int					ft_putnbr_fd(int n, int fd, t_format format);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *));
t_list				*ft_lstlast(t_list *lst);
int					ft_cinset(const char c, const char *set);
t_format			ft_initialize(t_format *format);
t_format			ft_setflags(t_format format, const char *str, va_list *va);
int					ft_isflag(const char *flag);
char				*ft_getflags(const char *str);
int					ft_printf(const char *str, ...);
t_format			ft_set_width(t_format format, const char *flags);
t_format			ft_set_info_prec(t_format format, const char *flags);
int					ft_print(t_format format, va_list *va);
int					ft_print_char(t_format format, va_list *va);
t_format			ft_set_stars(t_format format, va_list *va);
int					ft_print_str(t_format format, va_list *va);
int					ft_print_padding_str(t_format format, char *arg);
int					ft_print_ptr(t_format format, va_list *va);
int					ft_putnbr_base(long int nb, char *base, t_format format);
int					ft_print_padding_int(t_format format, int arg);
int					ft_print_padding_char(t_format format);
int					ft_size(long arg);
int					ft_print_int(t_format format, va_list *va);
int					ft_size_int(int arg);
t_format			ft_set_padding_int(t_format format, int arg);
int					ft_putnbr_unsigned(long int nb, t_format format);
char				*ft_itoa_unsigned(unsigned int arg);
int					ft_print_unsigned(t_format format, va_list *va);
int					ft_power(int n, int exp);
int					get_size(unsigned int n);
int					ft_size_uns(long int arg);
void				printest(t_format format);
int					ft_print_pourcent(t_format format);
char				*ft_putnbr_base_to_str(unsigned int nb, char *base,
char *str);
char				*ft_int_to_hex(unsigned int arg);
int					ft_print_hex(t_format format, va_list *va);
int					ft_print_hex_maj(t_format format, va_list *va);
char				*ft_toupper_str(char *str);
int					ft_size_hexa(long int arg);
int					ft_print_padding_ptr(t_format format);
int					ft_set_padding_ptr(t_format format, long int arg);
t_format			ft_reset(t_format format);
int					ft_putstr_int(char *s, int fd, t_format format, int arg);
t_format			ft_set_precision_int(t_format format, int arg);
int					ft_putstr_unsigned(char *s, int fd,
					t_format format, unsigned int arg);
t_format			ft_set_padding_unsigned(t_format format, unsigned int arg);
t_format			ft_set_precision_unsigned(t_format format,
					unsigned int arg);
t_format			ft_set_padding_hexa(t_format format, long int arg);
t_format			ft_set_precision_hexa(t_format format, long int arg);
t_format			ft_set_precision_str(t_format format, char *arg);
t_format			ft_set_padding_str(t_format format, char *arg);
t_format			ft_set_precision_null(t_format format);
t_format			ft_set_padding_null(t_format format);
int					ft_print_padding_null(t_format format);
int					ft_print_null(t_format format, char *arg);
int					ft_print_precision_int(t_format format, int arg);
int					ft_print_padding_unsigned(t_format format, long int arg);
int					ft_putptr_fd(long int arg, int fd, t_format format);
t_format			ft_set_precision_ptr(t_format format, long int arg);
int					ft_print_precision_ptr(t_format format, long int arg);

#endif
