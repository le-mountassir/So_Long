/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:49:06 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/17 17:54:54 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../full_libft.h"

char	**read_map_fd(char *file, int *y_map, int *x_map)
{
	int		fd;
	char	*line;
	char	*map;
	char	**td_map;

	fd = open(file, O_RDONLY);
	map = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
			*y_map += 1;
		map = gnl_ft_strjoin(map, line);
	}
	td_map = ft_split(map, '\n');
	*x_map = gnl_ft_strlen(td_map[0]);
	return (td_map);
}
