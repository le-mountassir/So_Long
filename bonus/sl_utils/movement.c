/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:02:20 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/21 17:27:49 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_libft.h"

void	check_c_or_e(int x, int y, t_unit *vars)
{
	static int	i;

	if (vars->td_map[y][x] == 'C')
	{
		vars->td_map[y][x] = '0';
		i++;
	}
	if (i == vars->collect)
		vars->unlock = 1;
	if (vars->td_map[y][x] == 'E' && vars->unlock)
		free_game(vars);
}

int	movement(int key, t_unit *vr2)
{
	if (key == 0)
		left(vr2);
	else if (key == 1)
		down(vr2);
	else if (key == 13)
		up(vr2);
	else if (key == 2)
		right(vr2);
	else if (key == 53)
		free_game(vr2);
	check_c_or_e(vr2->p_x / 30, vr2->p_y / 30, vr2);
	return (1);
}
