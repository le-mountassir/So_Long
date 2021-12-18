/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_in_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:38:52 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/18 15:02:25 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../full_libft.h"

void	*ex_car_col(char c, void *init)
{
	char	*src;
	void	*img;
	int		y_image;
	int		x_image;

	if (c == 'C')
	{
		src = "./src/images/diamond.xpm";
		img = mlx_xpm_file_to_image(init, src, &x_image, &y_image);
	}
	else if (c == 'P')
	{
		src = "./src/images/l_player.xpm";
		img = mlx_xpm_file_to_image(init, src, &x_image, &y_image);
	}
	else
	{
		src = "./src/images/exit_door.xpm";
		img = mlx_xpm_file_to_image(init, src, &x_image, &y_image);
	}
	return (img);
}

void	*wall_floor(char c, void *init)
{
	char	*src;
	void	*img;
	int		y_image;
	int		x_image;

	if (c == '0')
	{
		src = "./src/images/floor.xpm";
		img = mlx_xpm_file_to_image(init, src, &x_image, &y_image);
	}
	else
	{
		src = "./src/images/walls.xpm";
		img = mlx_xpm_file_to_image(init, src, &x_image, &y_image);
	}
	return (img);
}

void	*check_char(char c, void *init)
{
	void	*img;

	img = NULL;
	if (c == '0' || c == '1')
		img = wall_floor(c, init);
	else if (c == 'C' || c == 'P' || c == 'E')
		img = ex_car_col(c, init);
	return (img);
}

void	replace_in_map(t_unit *vr2)
{
	int		i;
	int		j;
	void	*img;
	
	i = 0;
	while (vr2->td_map[i])
	{
		j = 0;
		while (vr2->td_map[i][j])
		{
			img = check_char(vr2->td_map[i][j], vr2->init);
			mlx_put_image_to_window(vr2->init, vr2->wind, img, j * 30, i * 30);
			if (vr2->td_map[i][j] == 'P')
			{
				vr2->p_x = j * 30;
				vr2->p_y = i * 30;
			}
			if (vr2->td_map[i][j] == 'C')
				vr2->collect++;
			j++;
		}	
		i++;
	}
}