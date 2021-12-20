/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:56:24 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/19 14:12:30 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../full_libft.h"

char	*extract_cur_line(char *stc_arr)
{
	int	i;

	i = 0;
	if (!stc_arr[i])
		return (NULL);
	i = 0;
	while (stc_arr[i] && stc_arr[i] != '\n')
		i++;
	return (gnl_ft_substr(stc_arr, 0, i + 1));
}

char	*assign_rest(char *stc_arr)
{
	char	*str;
	int		i;

	i = 0;
	if (!stc_arr)
		return (NULL);
	while (stc_arr[i])
	{
		if (stc_arr[i] == '\n')
		{
			str = gnl_ft_substr(stc_arr, i + 1, gnl_ft_strlen(stc_arr));
			free (stc_arr);
			if (str[0] == '\n')
			{
				printf("new line in map\n");
				exit(1);
			}
			return (str);
		}
		i++;
	}
	free (stc_arr);
	return (NULL);
}

int	find_nl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*stc_arr[10240];
	t_storage	unit_1;

	if (fd < 0)
		return (NULL);
	unit_1.rd_len = 1;
	unit_1.buff = malloc(100 + 1);
	while (!(find_nl(stc_arr[fd])) && (unit_1.rd_len))
	{
		unit_1.rd_len = read(fd, unit_1.buff, 100);
		if (unit_1.rd_len < 0)
		{
			free(unit_1.buff);
			return (NULL);
		}
		unit_1.buff[unit_1.rd_len] = '\0';
		stc_arr[fd] = gnl_ft_strjoin(stc_arr[fd], unit_1.buff);
	}
	free(unit_1.buff);
	unit_1.cur_line = extract_cur_line(stc_arr[fd]);
	stc_arr[fd] = assign_rest(stc_arr[fd]);

	return (unit_1.cur_line);
}
