/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:47:19 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/18 15:03:19 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./my_lib/full_libft.h"
// w 13
// s 1
// a 0
// d 2
// sp 49
// shift 257

int	main(int c, char **v)
{
	t_unit	vr;

	if (c == 2)
	{
		vr.td_map = read_map_fd(v[1], &vr.y_map, &vr.x_map);
		vr.init = mlx_init();
		if (!vr.init)
			return (0);
		vr.wind = mlx_new_window(vr.init, vr.x_map * 30, vr.y_map * 30, "MineCrap");
		if (!vr.wind)
		{
			free(vr.wind);
			return (0);
		}
		replace_in_map(&vr);
		mlx_hook(vr.wind, 2, (1L<<0), movement, &vr);
		mlx_loop(vr.init);
	}
}
