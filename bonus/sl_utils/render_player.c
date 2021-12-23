/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 11:58:15 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/21 17:27:56 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_libft.h"

void	print_num_of_moves(t_unit *vr)
{
	char	*num;

	num = ft_itoa(vr->movements);
	mlx_string_put(vr->init, vr->wind, 5, 5, 0xff0f80, num);
	free(num);
}

void	render_player(t_unit *vr3, t_move *mv)
{
	static int	num_of_mv;

	mv->floor = "./src/images/floor.xpm";
	mlx_put_image_to_window(vr3->init, vr3->wind, vr3->img,
		vr3->p_x, vr3->p_y);
	vr3->img = mlx_xpm_file_to_image(vr3->init, mv->floor,
			&mv->x_img, &mv->y_img);
	mlx_put_image_to_window(vr3->init, vr3->wind, vr3->img, mv->x, mv->y);
	vr3->movements = ++num_of_mv;
	print_num_of_moves(vr3);
}
