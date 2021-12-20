/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:05:09 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/19 18:39:38 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../full_libft.h"

void		check_colums(char *row, int *c, int *p, int *e)
{
	int i;

	i = 0;
	while (row[i])
	{
		if (row[i] != '1' && row[i] != '0' && row[i] != 'E' && row[i] != 'X' && row[i] != 'P' && row[i] != 'C')
		{
			printf("error in the collums");
			exit(1);
		}
		if (row[i] == 'C')
			*c += 1;
		else if (row[i] == 'P')
			*p += 1;
		else if (row[i] == 'E')
			*e += 1;
		i++;
	}
}
void	check_walls(char *row)
{
	int i = 0;
	while (row[i])
	{
		if (row[i] != '1')
		{
			printf("ERROR in the map walls");
			exit(1);
		}
		i++;
	}
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
		if (map[i][0] != '1' || map[i][x_total-1] != '1')
		{
			printf("map error");
			exit(0);
		}
		if (gnl_ft_strlen(map[i]) != x_total)
		{
			printf("map error");
			exit(0);
		}
		if (i == 0 || i == y_total - 1)
			check_walls(map[i]);
		check_colums(map[i], &c, &p, &e);
		i++;
	}
	if (p < 1 && c < 1 && e < 1)
	{
		printf("missing colums\n");
		exit(1);
	}
}
