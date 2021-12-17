/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:08:40 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/16 11:05:48 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../full_libft.h"

static int	located_in(const char *set, char cara_s1)
{
	while (*set)
		if (cara_s1 == *(set++))
			return (1);
	return (0);
}

static void	length_c(const char *s1, const char *set, size_t *fst, size_t *lst)
{
	char	*str;

	str = (char *)s1;
	*fst = 0;
	while (located_in(set, *(s1++)))
		*fst += 1;
	*lst = 0;
	s1 = str + ft_strlen(str) - 1;
	while (located_in(set, *(s1--)) && s1 != str)
		*lst += 1;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		first;
	size_t		last;
	size_t		len;
	char		*t_arr;

	if (!s1)
		return (NULL);
	length_c(s1, set, &first, &last);
	len = ft_strlen(s1) - last - first;
	if (first + last < ft_strlen(s1))
	{
		t_arr = ft_calloc((len + 1), sizeof(char));
		if (!t_arr)
			return (NULL);
		ft_memmove(t_arr, s1 + first, len);
		return (t_arr);
	}
	t_arr = ft_calloc(1, sizeof(char));
	if (!t_arr)
		return (NULL);
	return (t_arr);
}
