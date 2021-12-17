/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:49:06 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/16 18:04:14 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./my_lib/full_libft.h"

char *read_map(char *file)
{
    int fd;
    char *line;
    char *map;
    char *tmp;

    // *map = '\0';
    fd = open(file, O_RDONLY);
    printf("%d\n", fd);
    while (1)
    {
        tmp = map;
        line = get_next_line(fd);
        if (!line)
            break ;
        // map = gnl_ft_strjoin(tmp, line);
    }
    return (map);
}
int main()
{
    printf("%s", read_map("map"));
}