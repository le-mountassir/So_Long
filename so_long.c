/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:47:19 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/20 18:43:00 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./my_lib/full_libft.h"
// w 		13
// s 		1
// a 		0
// d 		2
// sp		49
// shift 	257
// escp		53

int	free_game(t_unit *vr)
{
	int i = 0;
	printf("Quiting the Game\n");
	while (vr->td_map[i])
	{
		free(vr->td_map[i]);
		i++;
	}
	free(vr->td_map);
	mlx_destroy_image(vr->init, vr->img);
	mlx_destroy_window(vr->init, vr->wind);
	exit(1);
	return(0);
}

int	main(int c, char **v)
{
	t_unit	vr;

	if (c == 2)
	{
		vr.td_map = read_map_fd(v[1], &vr.y_map, &vr.x_map);
		vr.init = mlx_init();
		if (!vr.init)
			free_game(&vr);
		vr.wind = mlx_new_window(vr.init, vr.x_map * 30, vr.y_map * 30, "MineCrap");
		if (!vr.wind)
			free_game(&vr);
		mlx_hook(vr.wind, 2, (1L<<0), movement, &vr);
		mlx_hook(vr.wind, 17, (1L<<2), free_game, &vr);
		mlx_loop_hook(vr.init, replace_in_map, &vr);
		mlx_loop(vr.init);
	}
}
