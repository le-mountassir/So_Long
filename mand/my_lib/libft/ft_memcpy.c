/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:59:14 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/21 18:03:48 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mand_libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*srx;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	dst = dest;
	srx = (unsigned char *)src;
	while (i < n)
	{
		dst[i] = srx[i];
		i++;
	}
	return (dest);
}
