/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:09:03 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/21 18:06:09 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../bonus_libft.h"

static long	n_or_p(long numb)
{
	if (numb > 0)
		return (numb);
	return (numb * -1);
}

static int	int_len(long number)
{
	int	i;

	i = 0;
	while (number > 0)
	{
		number /= 10;
		i++;
	}
	return (i);
}

static char	*num_zero(void)
{
	char	*ar_z;

	ar_z = (char *)malloc(2 * sizeof(char));
	ar_z[0] = '0';
	ar_z[1] = '\0';
	return (ar_z);
}

char	*ft_itoa(int n)
{
	char	*arr;
	size_t	i;
	size_t	len;
	int		neg;
	long	nb;

	if (n == 0)
		return (num_zero());
	neg = 0;
	i = 0;
	if (n < 0)
		neg = 1;
	nb = n_or_p(n);
	len = int_len(nb);
	arr = ft_calloc((len + 1 + neg), sizeof(char));
	if (!arr)
		return (NULL);
	while (i < len)
	{
		arr[i++] = nb % 10 + 48;
		nb /= 10;
	}
	if (neg)
		arr[i] = '-';
	return (ft_strrev(arr));
}
