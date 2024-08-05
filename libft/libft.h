/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <amuhsen-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:02:19 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/07/23 03:41:38 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <limits.h>
# include <malloc.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int				*content;
	int				index;
	struct s_list	*next;
}					t_list;

typedef struct s_stack
{
	t_list			*a;
	t_list			*b;
	char			*join;
	char			**splited;
	int				*array;
	int				*array_b;
	int				array_size;
	int				array_size_b;
	float			chunk_size;
}					t_stack_a;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

char				*get_next_line(int fd);
char				*ft_strjoint(char *s1, char const *s2);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlen(char const *str);
char				*ft_strdup(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *str, const char *to_find,
						size_t range);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strjoin(char *s1, char const *s2);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strchr(const char *s, int c);
char				**ft_split(char const *s1, char c);
void				ft_putstr_fd(char *s, int fd);
void				*ft_free(char **dest);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				*ft_memset(void *ptr, int x, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_itoa(int n);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
void				*ft_calloc(size_t nitems, size_t size);
void				ft_bzero(void *ptr, size_t n);
long				ft_atoi(const char *nptr);
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **list, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
void				del(void *data);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
void				sa(t_stack_a *a, int flag);
void				rra(t_stack_a *a, int flag);
void				pa(t_stack_a *a, int flag);
void				pb(t_stack_a *a, int flag);
void				rr(t_stack_a *a, int flag);
void				ss(t_stack_a *a, int flag);
void				rrr(t_stack_a *a, int flag);
void				sb(t_stack_a *a, int flag);
void				rrb(t_stack_a *a, int flag);
void				rb(t_stack_a *a, int flag);
void				ra(t_stack_a *a, int flag);
void				check_empty_args(int ac, char **av);
void				join_and_split_args(t_stack_a *a, int ac, char **av);
void				check_digits_in_array(t_stack_a *a);
void				sort_and_check_fill(t_stack_a *a);
void				check_duplicates_in_array(t_stack_a *a);
void				fill_stack_a(t_stack_a *a);
void				ssort_array_elements(t_stack_a *a);
void				sort_it_big(t_stack_a *a);
void				fill_array_b(t_stack_a *a);
void				fill_index_values(t_stack_a *a);
int					find_next(int x, t_stack_a *data);
void				b_to_a(t_stack_a *a);
int					check(t_stack_a *a, int x, int size);
void				algo_chance(t_stack_a *a);
int					find(t_stack_a *a, int x);
void				sort_3(t_stack_a *a);
int					find_smallest(t_stack_a *a);
void				sort_5(t_stack_a *a);

#endif
