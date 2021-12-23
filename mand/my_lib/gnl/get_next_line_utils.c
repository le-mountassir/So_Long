/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:56:31 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/21 18:03:19 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mand_libft.h"

int	gnl_ft_strlen(char *cara)
{
	int	i;

	i = 0;
	if (!cara)
		return (i);
	while (cara[i])
		i++;
	return (i);
}

char	*gnl_ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;
	int		o_len;
	int		d_len;

	o_len = gnl_ft_strlen(s1);
	d_len = gnl_ft_strlen(s2);
	new = malloc((o_len + d_len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (i < o_len)
		new[i++] = s1[j++];
	j = 0;
	while (j < d_len)
		new[i++] = s2[j++];
	new[i] = '\0';
	free(s1);
	return (new);
}

char	*gnl_ft_substr(char *s, int start, int len)
{
	char	*cara;
	int		i;
	int		j;

	if (!s)
		return (0);
	if (start >= gnl_ft_strlen(s))
		len = 0;
	i = 0;
	j = 0;
	while (i < len && s[i])
		i++;
	cara = malloc((i + 1) * sizeof(char));
	if (!cara)
		return (NULL);
	while (j < i)
		cara[j++] = s[start++];
	cara[i] = '\0';
	return (cara);
}
