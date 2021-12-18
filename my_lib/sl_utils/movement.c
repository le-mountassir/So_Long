/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:02:20 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/18 16:43:02 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../full_libft.h"

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
	return (1);
}
