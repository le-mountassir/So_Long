/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_in_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:38:52 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/21 17:27:59 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_libft.h"

void	*ex_car_col(char c, void *init)
{
	char	*src;
	void	*img;
	int		y_image;
	int		x_image;

	if (c == 'C')
		src = "./src/images/diamond.xpm";
	else if (c == 'P')
		src = "./src/images/l_player.xpm";
	else
		src = "./src/images/exit_door.xpm";
	img = mlx_xpm_file_to_image(init, src, &x_image, &y_image);
	return (img);
}

void	*wall_floor(char c, void *init)
{
	char		*src;
	void		*img;
	int			y_image;
	int			x_image;

	if (c == '0')
		src = "./src/images/floor.xpm";
	else if (c == '1')
		src = "./src/images/walls.xpm";
	else
	{
		usleep(100);
		if (rand() % 17 == 0)
			src = "./src/images/enemy1.xpm";
		else
			src = "./src/images/enemy2.xpm";
	}
	img = mlx_xpm_file_to_image(init, src, &x_image, &y_image);
	return (img);
}

void	check_char(char c, t_unit *vr)
{
	vr->img = NULL;
	if (c == '0' || c == '1' || c == 'X')
		vr->img = wall_floor(c, vr->init);
	else if (c == 'C' || c == 'P' || c == 'E')
		vr->img = ex_car_col(c, vr->init);
}

int	replace_in_map(t_unit *vr2)
{
	int			i;
	int			j;
	static int	call;

	i = 0;
	while (vr2->td_map[i])
	{
		j = 0;
		while (vr2->td_map[i][j])
		{
			if (call == 0)
				re_render(i, j, vr2);
			else if (vr2->td_map[i][j] == 'X' || (i == 0))
			{
				check_char(vr2->td_map[i][j], vr2);
				mlx_put_image_to_window(vr2->init, vr2->wind,
					vr2->img, j * 30, i * 30);
				print_num_of_moves(vr2);
			}
			j++;
		}	
		i++;
	}
	call = 1;
	return (1);
}
