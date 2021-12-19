/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:40:55 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/18 18:10:22 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../full_libft.h"

void	up(t_unit *vr3)
{
	t_move	mv;
	void	*img;

	mv.x = vr3->p_x;
	mv.y = vr3->p_y;
	mv.src = "./src/images/r_player.xpm";
	mv.floor = "./src/images/floor.xpm";
	if (vr3->td_map[vr3->p_y / 30 - 1][vr3->p_x / 30] != '1')
	{
		vr3->p_y -= 30;
		img = mlx_xpm_file_to_image(vr3->init, mv.src, &mv.x_img, &mv.y_img);
		mlx_put_image_to_window(vr3->init, vr3->wind, img, vr3->p_x, vr3->p_y);
		if (vr3->td_map[mv.y / 30][mv.x / 30] != 'E')
		{
			img = mlx_xpm_file_to_image(vr3->init, mv.floor, &mv.x_img, &mv.y_img);
			mlx_put_image_to_window(vr3->init, vr3->wind, img, mv.x, mv.y);
		}
	}
}

void	down(t_unit *vr3)
{
	t_move	mv;
	void	*img;

	mv.x = vr3->p_x;
	mv.y = vr3->p_y;
	mv.src = "./src/images/l_player.xpm";
	mv.floor = "./src/images/floor.xpm";
	if (vr3->td_map[vr3->p_y / 30 + 1][vr3->p_x / 30] != '1')
	{
		vr3->p_y += 30;
		img = mlx_xpm_file_to_image(vr3->init, mv.src, &mv.x_img, &mv.y_img);
		mlx_put_image_to_window(vr3->init, vr3->wind, img, vr3->p_x, vr3->p_y);
		if (vr3->td_map[mv.y / 30][mv.x / 30] != 'E')
		{
			img = mlx_xpm_file_to_image(vr3->init, mv.floor, &mv.x_img, &mv.y_img);
			mlx_put_image_to_window(vr3->init, vr3->wind, img, mv.x, mv.y);
		}
	}
}

void	right(t_unit *vr3)
{
	t_move	mv;
	void	*img;

	mv.x = vr3->p_x;
	mv.y = vr3->p_y;
	mv.src = "./src/images/r_player.xpm";
	mv.floor = "./src/images/floor.xpm";
	if (vr3->td_map[vr3->p_y / 30][vr3->p_x / 30 + 1] != '1')
	{
		vr3->p_x += 30;
		img = mlx_xpm_file_to_image(vr3->init, mv.src, &mv.x_img, &mv.y_img);
		mlx_put_image_to_window(vr3->init, vr3->wind, img, vr3->p_x, vr3->p_y);
		if (vr3->td_map[mv.y / 30][mv.x / 30] != 'E')
		{
			img = mlx_xpm_file_to_image(vr3->init, mv.floor, &mv.x_img, &mv.y_img);
			mlx_put_image_to_window(vr3->init, vr3->wind, img, mv.x, mv.y);
		}
	}
}

void	left(t_unit *vr3)
{
	t_move	mv;
	void	*img;

	mv.x = vr3->p_x;
	mv.y = vr3->p_y;
	mv.src = "./src/images/l_player.xpm";
	mv.floor = "./src/images/floor.xpm";
	if (vr3->td_map[vr3->p_y / 30][vr3->p_x / 30 - 1] != '1')
	{
		vr3->p_x -= 30;
		img = mlx_xpm_file_to_image(vr3->init, mv.src, &mv.x_img, &mv.y_img);
		mlx_put_image_to_window(vr3->init, vr3->wind, img, vr3->p_x, vr3->p_y);
		if (vr3->td_map[mv.y / 30][mv.x / 30] != 'E')
		{
			img = mlx_xpm_file_to_image(vr3->init, mv.floor, &mv.x_img, &mv.y_img);
			mlx_put_image_to_window(vr3->init, vr3->wind, img, mv.x, mv.y);
		}
	}
}
