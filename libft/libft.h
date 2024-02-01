/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:31:33 by tbabou            #+#    #+#             */
/*   Updated: 2024/01/29 16:24:48 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define BLACK "\e[0;30m"
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[0;33m"
# define BLUE "\e[0;34m"
# define MAGENTA "\e[0;35m"
# define CYAN "\e[0;36m"
# define WHITE "\e[0;37m"

# define BLACKBG "\e[0;100m"
# define REDBG "\e[0;101m"
# define GREENNBG "\e[0;102m"
# define YELLOWBG "\e[0;103m"
# define BLUEBG "\e[0;104m"
# define MAGENTABG "\e[0;105m"
# define CYANBG "\e[0;106m"
# define WHITEBG "\e[0;107m"

# define RESET "\e[0m"

typedef struct s_free
{
	void			*ptr;
	struct s_free	*next;
}					t_free;

typedef struct s_m_free
{
	struct s_free	*list;
}					t_m_free;

/*Beginning of the part about ft_malloc;*/
void				*ft_malloc(size_t size, t_m_free *m_free);
int					ft_add_malloc(void *ptr, t_m_free *m_free);
void				ft_free(void *ptr, t_m_free *m_free);
void				ft_free_all(t_m_free *m_free);
/*Ending of the part about ft_malloc;*/
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strjoin(char const *s1, char const *s2,
						t_m_free *m_free);
char				*ft_substr(char const *s, unsigned int start, size_t len,
						t_m_free *m_free);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isspace(int c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_intlen(int nbr);
int					ft_atoi(const char *str);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putstr_fd(char *str, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				*ft_bzero(void *b, size_t len);
void				*ft_calloc(size_t nmemb, size_t size, t_m_free *m_free);
void				*ft_memset(void *str, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char),
						t_m_free *m_free);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				**ft_split(char const *s, char c, t_m_free *m_free);
char				*ft_strtrim(char const *s1, char const *set,
						t_m_free *m_free);

#endif
