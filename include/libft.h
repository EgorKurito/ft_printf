/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguy <hanguy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 13:09:20 by hanguy            #+#    #+#             */
/*   Updated: 2020/05/22 08:51:40 by hanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef char		t_bool;
typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*
*********************** Mandatory Part 1 ***********************
*/
size_t				ft_strlen(const char *src);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, unsigned int n);
void				*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void				*ft_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack, const char *needle, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *src);
/*
*********************** Mandatory Part 2 ***********************
*/
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *str, char sep);
char				*ft_itoa(long n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *str, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
/*
*********************** Bonus Part *****************************
*/
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *dest, const char *src);
int					ft_abs(int i);
long long			ft_llabs(long long ll);
double				ft_fabs(double d);
/*
***************************** FT_PRINTF Part *****************************
*/
int					ft_max(int first, int second);
int					ft_nbr_len(ssize_t nbr);
void				ft_putchar_n(int c, int n);
void				ft_putnbr(ssize_t n);
int					ft_un_nbr_base_len(size_t nbr, int base);
void				ft_un_putnbr(size_t n, int base, t_bool is_upper);
/*
*********************** CUB3D Part *****************************
*/
int					get_next_line(int fd, char **line);
void				ft_space(char *line, int *i);
int					ft_num_len(char *s);
int					ft_cub_atoi(char *line, int *i);
int					is_char_digit(char *str);
int					char_count(char **str);
int					ft_strcmp(const char *s1, const char *s2);
/*
*********************** Minishell Part *****************************
*/
int					ft_isspace(int c);
char				**ft_split_once(char const *s, char c);
char				*ft_strjoin_delimiter(char *s1, char *s2, char del);
int					ft_haschr(const char *s, int c);
char				*ft_strjoin_doublefree(char *s1, char *s2);
char				*ft_strjoin_free(char *s1, char *s2);
int					is_num(char *str);
void				ft_putstr(char const *str);
void				ft_putchar(char c);
char				*ft_strnew(size_t size);
char				*ft_strndup(const char *s1, size_t size);
int					ft_hasnchar(const char *s, char *c);
long				ft_atol(const char *str);
int					ft_strpbkr(const char *s, const char *s2);

#endif
