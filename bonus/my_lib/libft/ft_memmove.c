/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:43:14 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/21 18:06:22 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../bonus_libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*srx;
	char	*dst;
	int		i;

	dst = (char *)dest;
	srx = (char *)src;
	if (srx == dst || n == 0)
		return (dest);
	if (dst > srx)
	{
		i = n - 1;
		while (i >= 0)
		{
			dst[i] = srx[i];
			i--;
		}
		return (dest);
	}
	ft_memcpy(dest, src, n);
	return (dest);
}
