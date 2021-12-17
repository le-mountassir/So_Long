/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_libft.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:37:42 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/16 18:12:57 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FULL_LIBFT_H
# define FULL_LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>

//----------------------------------so_long
// char		*read_map(char *path);
//----------------------------------Lib_ft
 
char		*ft_strchr(const char *str, int c);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_bzero(void *s, size_t n);
char		*ft_strrchr(const char *s, int c);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *str, char c);
char		*ft_itoa(int n);
char		*ft_strrev(char *add_func);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));

//-------------------------------------get_next_line

typedef struct dipo_dial_lvariablat
{
	int		rd_len;
	char	*cur_line;
	char	*buff;
}			t_storage;

char	*get_next_line(int fd);
int     gnl_ft_strlen(char *cara);
char	*gnl_ft_strjoin(char *s1, char *s2);
char	*gnl_ft_substr(char *cara, int start, int len);

#endif
