/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atimoshenko <atimoshenko@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 10:11:26 by atimoshenko       #+#    #+#             */
/*   Updated: 2020/05/23 17:22:32 by atimoshenko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <wchar.h>

typedef	struct		s_fp
{
	long			integral;
	long			fraction;
	int				len_i;
	int				trail_zeros;
	int				lead_zeros;
	int				len_f;
}					t_fp;
# define SIG_F (f.lead_zeros + f.len_f)
# define SIG_I (f.len_i + f.trail_zeros)

int					ft_atoi(const char *str);
char				*ft_strdup(const char *src);
size_t				ft_strlen(const char *str);
char				*ft_strcpy(char *dest, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcat(char *destptr, const char *srcptr);
char				*ft_strncat(char *restrict s1, const char *restrict s2,
		size_t n);
size_t				ft_strlcat (char *dest, const char *src, size_t size);
char				*ft_strchr(const char *string, int symbol);
char				*ft_strrchr(const char *string, int symbol);
char				*ft_strstr(char *string1, const char *string2);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
int					ft_iswhitespace(char c);
int					ft_wordscount(char const*s, char c);
char				**ft_strsplit(char const *s, char c);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
char				*ft_itoa(int n);
int					ft_getnbsize(long n);
void				ft_putendl(char const *c);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef union		u_double
{
	double			d;
	long			l;
}					t_double;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_isblank(int c);
int					ft_str_is_alpha(char *str);
int					ft_str_is_lowercase(char *str);
int					ft_str_is_numeric(char *str);
int					ft_str_is_printable(char *str);
int					ft_str_is_uppercase(char *str);
char				*ft_strlowcase(char *str);
char				*ft_strupcase(char *str);
int					ft_size_of_word(char const *str, char c);
char				*ft_itoa_base(int n, int base);
size_t				ft_dstrlen(const char *str, char del);
void				ft_lstputstr(t_list *item);
void				ft_lstadd_tail(t_list **alst, t_list *item);
char				*ft_strndup(const char *s1, size_t len);
t_list				*ft_lstinit(void const *content, size_t content_size);
char				*ft_strinitial(size_t size, int c);
int					ft_max(int a, int b);
int					ft_min(int a, int b);
long				ft_abs(long nb);
size_t				ft_numberlen(long long num);
size_t				ft_numberlen_sign(long long num);
size_t				ft_unumberlen(unsigned long long num);
size_t				ft_numberlen_sign_base(long long num, int base);
size_t				ft_numberlen_base(long long num, int base);
size_t				ft_unumberlen_base(unsigned long long nb, int base);
void				ft_lstputstr_len(t_list *item);
void				ft_lstmemdel(void *content, size_t content_sie);
void				ft_strupper(char *str);
void				*ft_nmemset(void *b, int c, size_t len);
int					ft_ceil(double roundee);
int					ft_floor(double roundee);
long				ft_power(int a, int b);
double				ft_power_d(double a, int b);
char				*ft_ftoa(double nb, int precision);
long				ft_round(double roundee);
char				*conv_utf8_str(wchar_t *wstr);
char				*conv_utf8_char(wchar_t wchar, char *str);
size_t				ft_wstrlen(const wchar_t *str);
char				*ft_ftosn(double nb, int precision);

#endif
