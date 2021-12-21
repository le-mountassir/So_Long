/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:40:55 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/20 14:24:22 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../full_libft.h"

void	up(t_unit *vr3)
{
	t_move	mv;

	mv.x = vr3->p_x;
	mv.y = vr3->p_y;
	mv.src = "./src/images/r_player.xpm";
	if (vr3->td_map[vr3->p_y / 30 - 1][vr3->p_x / 30] == 'X')
		free_game(vr3);
	if (vr3->td_map[vr3->p_y / 30 - 1][vr3->p_x / 30] != '1' && vr3->td_map[vr3->p_y / 30 - 1][vr3->p_x / 30] != 'E')
	{
		vr3->p_y -= 30;
		vr3->img = mlx_xpm_file_to_image(vr3->init, mv.src, &mv.x_img, &mv.y_img);
		render_player(vr3, &mv);
	}
	else if (vr3->td_map[vr3->p_y / 30 - 1][vr3->p_x / 30] != '1' && vr3->unlock == 1)
	{
		vr3->p_y -= 30;
		vr3->img = mlx_xpm_file_to_image(vr3->init, mv.src, &mv.x_img, &mv.y_img);
		render_player(vr3, &mv);
	}
}

void	down(t_unit *vr3)
{
	t_move	mv;

	mv.x = vr3->p_x;
	mv.y = vr3->p_y;
	mv.src = "./src/images/l_player.xpm";
	if (vr3->td_map[vr3->p_y / 30 + 1][vr3->p_x / 30] == 'X')
		free_game(vr3);
	if (vr3->td_map[vr3->p_y / 30 + 1][vr3->p_x / 30] != '1' && vr3->td_map[vr3->p_y / 30 + 1][vr3->p_x / 30] != 'E')
	{
		vr3->p_y += 30;
		vr3->img = mlx_xpm_file_to_image(vr3->init, mv.src, &mv.x_img, &mv.y_img);
		render_player(vr3, &mv);
	}
	else if (vr3->td_map[vr3->p_y / 30 + 1][vr3->p_x / 30] != '1' && vr3->unlock == 1)
	{
		vr3->p_y += 30;
		vr3->img = mlx_xpm_file_to_image(vr3->init, mv.src, &mv.x_img, &mv.y_img);
		render_player(vr3, &mv);
	}
}

void	right(t_unit *vr3)
{
	t_move	mv;

	mv.x = vr3->p_x;
	mv.y = vr3->p_y;
	mv.src = "./src/images/r_player.xpm";
	if (vr3->td_map[vr3->p_y / 30][vr3->p_x / 30 + 1] == 'X')
		free_game(vr3);
	if (vr3->td_map[vr3->p_y / 30][vr3->p_x / 30 + 1] != '1' && vr3->td_map[vr3->p_y / 30][vr3->p_x / 30 + 1] != 'E')
	{
		vr3->p_x += 30;
		vr3->img = mlx_xpm_file_to_image(vr3->init, mv.src, &mv.x_img, &mv.y_img);
		render_player(vr3, &mv);
	}
	else if (vr3->td_map[vr3->p_y / 30][vr3->p_x / 30 + 1] != '1' && vr3->unlock == 1)
	{
		vr3->p_x += 30;
		vr3->img = mlx_xpm_file_to_image(vr3->init, mv.src, &mv.x_img, &mv.y_img);
		render_player(vr3, &mv);
	}
}

void	left(t_unit *vr3)
{
	t_move	mv;

	mv.x = vr3->p_x;
	mv.y = vr3->p_y;
	mv.src = "./src/images/l_player.xpm";
	if (vr3->td_map[vr3->p_y / 30][vr3->p_x / 30 - 1] == 'X')
		free_game(vr3);
	if (vr3->td_map[vr3->p_y / 30][vr3->p_x / 30 - 1] != '1' && vr3->td_map[vr3->p_y / 30][vr3->p_x / 30 - 1] != 'E')
	{
		vr3->p_x -= 30;
		vr3->img = mlx_xpm_file_to_image(vr3->init, mv.src, &mv.x_img, &mv.y_img);
		render_player(vr3, &mv);
	}
	else if (vr3->td_map[vr3->p_y / 30][vr3->p_x / 30 - 1] != '1' && vr3->unlock == 1)
	{
		vr3->p_x -= 30;
		vr3->img = mlx_xpm_file_to_image(vr3->init, mv.src, &mv.x_img, &mv.y_img);
		render_player(vr3, &mv);
	}
}
