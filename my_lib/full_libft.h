/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_libft.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:37:42 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/20 15:33:34 by ahel-mou         ###   ########.fr       */
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
typedef struct main_function
{
	void	*init;
	void	*wind;
	void	*img;
	char	**td_map;
	int		x_map;
	int		y_map;
	int		p_x;
	int		p_y;
	int		collect;
	int		walls;
	int		unlock;
}			t_unit;

typedef	struct	movements
{
    char	*src;
	char	*floor;
	int		y_img;
	int		x_img;
	void	*img;
	int		x;
	int		y;
}			t_move;

char	**read_map_fd(char *file, int *y_map, int *x_map);
int		replace_in_map(t_unit *vrs);
int		movement(int key, t_unit *vr2);
void	render_player(t_unit *vr3, t_move *mv);
void    map_checker(char **map, int x, int y);
int		free_game(t_unit *vr);
// int		enemy_anim(t_unit *vr);
//====> Direction

void	up(t_unit *vr3);
void	down(t_unit *vr3);
void	left(t_unit *vr3);
void	right(t_unit *vr3);

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
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *str, char c);
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
