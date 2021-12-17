/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:08:14 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/16 11:05:51 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../full_libft.h"

char	*ft_substr(char	const *s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		size;

	if (!s)
		return (NULL);
	size = ft_strlen(s + start);
	if (len > size)
		len = size;
	sub = ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	if (start < ft_strlen(s) && len > 0)
		ft_memcpy(sub, s + start, len);
	return (sub);
}
