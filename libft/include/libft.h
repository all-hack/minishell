/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 00:13:25 by obelange          #+#    #+#             */
/*   Updated: 2016/10/21 00:13:27 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 1
# define FGUARD(INPUT) if ((INPUT) == -1) return (-1)
# define FILEGUARD(INPUT) if ((INPUT) == -1) return (-1)
# define NULL_GUARD(INPUT) if ((INPUT) == NULL) return (NULL)
# define NULLGUARD(INPUT) if ((INPUT) == NULL) return (-1)

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_line_elem
{
	char		*re;
	int			fd;
	int			st[2];
	size_t		index;
	char const	*delim;
}				t_line_elem;

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
size_t			ft_strlen(const char *s);
int				ft_toupper(int c);
int				ft_tolower(int c);

void			ft_strclr(char *s);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strnstr(const char *big, const char *little, size_t len);

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_memdel(void **ap);

int				ft_atoi(const char *str);
char			*ft_itoa(int n);
void			*ft_memalloc(size_t size);

char			*ft_strnew(size_t size);
char			*ft_strdup(const char *s1);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char *s, char c);
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t			ft_stri_head(char const *s, char c);
size_t			ft_stri_tail(char const *s, char c);

size_t			ftsd(char const *s, char c);
void			ft_strdfree(void **s);
int				ft_isnt32();
int				ft_stric(char const *s, char const *c, size_t *index);
char			*ft_strmcat(char const *s1, const char *s2);
int				ft_1chr_nsym(char const *s, char const *c, char **s_str);
intmax_t		ft_intmax_atoi(char const *str);
char			*ft_fstrappend(char *s1, char c);
void			ft_fstrinsert(char **printit, char *substr,
	size_t strt, size_t end);
char			*ft_fstrmcat(char *s1, char const *s2);
char			*ft_itoa_base(uintmax_t num, int base, int neg);
int				ft_nchr_1sym(char const *s, char const **c, char **s_str);
char const		*ft_shiftstr(char const *s1, char const *s2);
int				ft_strchri(char const *s, char const c, size_t *index);
char			*ft_fstrdup(char *s0, const char *s1);

char			**ft_fstrlist_add(char **strlist, char *str);
char			*ft_fstrmcatf(char *s1, char *s2);
void			ft_strcut_c0(char *s, char c);
char			**ft_strlist_add(char **strlist, char *str);
char			**ft_strlist_build(size_t size);
void			ft_strlist_del(char	***strlist);
int				ft_strlist_findindex(char **strlist, char *str);
size_t			ft_strlist_len(char	**strlist);
char			**ft_strlist_minus(char **strlist);
void			ft_strlist_print(char **strlist);
char			**ft_strlist_remove(char **strlist, char *str);
char			*ft_strmcatf(char const *s1, char *s2);
int				ft_strsearch_ov(char const *s, char const *c);

int				get_next_line(const int fd, char **line);
#endif
