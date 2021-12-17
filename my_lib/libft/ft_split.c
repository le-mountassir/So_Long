/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:08:50 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/16 11:05:06 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../full_libft.h"

static size_t	n_o_strs(char const *s, char c)
{
	size_t	len;
	size_t	i;
	size_t	check;

	len = 0;
	i = 0;
	check = 1;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (check)
				len++;
			check = 0;
		}
		else
			check = 1;
		i++;
	}
	return (len);
}

static char	*malloc_strs(const char *s, char del)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != del)
		i++;
	str = (char *)malloc(i + 1 * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, i + 1);
	return (str);
}

static char	**free_all(char **arr, size_t index)
{
	while (index > 0)
	{
		free(arr[index]);
		index--;
	}
	free(arr);
	return (NULL);
}

static char	**splitter(char **d_arr, char *str, char del)
{
	size_t	checker;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	checker = 1;
	while (str[++i])
	{
		if (str[i] != del)
		{
			if (checker)
			{
				d_arr[j] = malloc_strs(str + i, del);
				if (d_arr[j] == NULL)
					return (free_all(d_arr, j));
				j++;
			}
			checker = 0;
		}
		else
			checker = 1;
	}
	d_arr[j] = NULL;
	return (d_arr);
}

char	**ft_split(char const *s, char c)
{
	char	**td_arr;

	if (!s)
		return (NULL);
	td_arr = (char **)malloc((n_o_strs(s, c) + 1) * sizeof(char *));
	if (!td_arr)
		return (NULL);
	return (splitter(td_arr, (char *)s, c));
}
