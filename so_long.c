/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:47:19 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/16 17:37:26 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./my_lib/full_libft.h"

int event(int key, void *param)
{
    // 13 move up
    // 1 move down
    // 0 move left
    // 2 move right
    // 49 space
    // 257 shift-left
    param = NULL;
    printf("u pressed : %d\n", key);
    return (0);
}

int main(int c, char **v)
{
    void    *x_init;
    void    *x_window;
    char    *relative_path = "./assets/images/floor.xpm";
    int     i_width;
    int     i_height;
    void    *img;

    printf("%s\n", v[1]);
    if (c == 2)
    {
        // read_map(v[1]);
        x_init = mlx_init();
        if (!x_init)
            return (0);
        x_window = mlx_new_window(x_init, 900, 500, "MineCrap");
        if (!x_window)
        {
            free(x_window);
            return (0);
        }
        img = mlx_xpm_file_to_image(x_init, relative_path, &i_width, &i_height);
        mlx_put_image_to_window(x_init, x_window, img, 0, 0);

        mlx_key_hook(x_window, event, NULL);
        mlx_loop(x_init);
    }
}
