/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:08:33 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/16 11:04:15 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../full_libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*str;
	char	*sx;
	size_t	i;

	i = 0;
	sx = (char *)src;
	str = dest;
	while (i < n)
	{
		str[i] = (unsigned char)sx[i];
		if ((unsigned char)sx[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
