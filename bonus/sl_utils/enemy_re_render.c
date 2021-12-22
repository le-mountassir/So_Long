/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_re_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:57:48 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/21 17:27:43 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_libft.h"

void	re_render(int i, int j, t_unit *vr2)
{
	check_char(vr2->td_map[i][j], vr2);
	mlx_put_image_to_window(vr2->init, vr2->wind, vr2->img,
		j * 30, i * 30);
	if (vr2->td_map[i][j] == 'P')
	{
		vr2->p_x = j * 30;
		vr2->p_y = i * 30;
	}
	if (vr2->td_map[i][j] == 'C')
		vr2->collect++;
}

int	enemy_anim(t_unit *vr2)
{
	t_move	t;

	t.x = 0;
	while (vr2->td_map[t.x])
	{
		t.y = 0;
		while (vr2->td_map[t.x][t.x])
		{
			if (vr2->td_map[t.x][t.x] == 'X')
			{
				t.floor = "./src/images/enemy1.xpm";
				t.img = mlx_xpm_file_to_image(vr2->init, t.floor,
						&t.x_img, &t.y_img);
				mlx_put_image_to_window(vr2->init, vr2->wind,
					t.img, t.y * 30, t.x * 30);
			}
			t.y++;
		}	
		t.x++;
	}
	return (1);
}
