/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:05:09 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/21 17:35:53 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mand_libft.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	printf("map error");
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	exit(0);
}

int	check_colums(char *row, int *c, int *p, int *e)
{
	int	i;

	i = 0;
	while (row[i])
	{
		if (row[i] != '1' && row[i] != '0' && row[i] != 'E'
			&& row[i] != 'P' && row[i] != 'C')
			return (0);
		if (row[i] == 'C')
			*c += 1;
		else if (row[i] == 'P')
			*p += 1;
		else if (row[i] == 'E')
			*e += 1;
		i++;
	}
	return (1);
}

int	check_walls(char *row)
{
	int	i;

	i = 0;
	while (row[i])
	{
		if (row[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	map_checker(char **map, int x_total, int y_total)
{
	int	i;
	int	p;
	int	e;
	int	c;

	i = 0;
	p = 0;
	e = 0;
	c = 0;
	while (map[i])
	{
		if (x_total == y_total)
			free_map(map);
		if (map[i][0] != '1' || map[i][x_total - 1] != '1'
				|| gnl_ft_strlen(map[i]) != x_total)
			free_map(map);
		if (i == 0 || i == y_total - 1)
			if (!check_walls(map[i]))
				free_map(map);
		if (!check_colums(map[i], &c, &p, &e))
			free_map(map);
		i++;
	}
	if (p != 1 || c < 1 || e < 1)
		free_map(map);
}
