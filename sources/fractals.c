/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:10:27 by mloureir          #+#    #+#             */
/*   Updated: 2024/05/02 15:19:07 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	maps_select(t_win_info *wininfo)
{
    if (ft_strcmp(wininfo->name, "MANDELBROT") == 1)
	mandelbrot_start(wininfo);
    return (0);
}

void    mandelbrot_start(t_win_info *wininfo)
{
    while (wininfo->c_x < X)
    {
        wininfo->c_y = 0;
        while(wininfo->c_y < Y)
        {
            draw_mandelbrot(wininfo);
            wininfo->c_y++;
        }
        wininfo->c_x++;
    }
    mlx_put_image_to_window(wininfo->mlx_ptr, wininfo->win_ptr, wininfo->img.img_ptr, 0, 0);
    refresh(wininfo);
}

void    draw_mandelbrot(t_win_info *wininfo)
{
    double  x_temp;
    double  x;
    double  y;

    wininfo->times_it = 0;
    wininfo->x = 0;
    wininfo->y = 0;
    x = scale(wininfo->c_x, -2 + wininfo->move_x, 2 + wininfo->move_x, 0, X);
    y = scale(wininfo->c_y, -2 + wininfo->move_y, 2 + wininfo->move_y, 0, Y);
    while (++wininfo->times_it < wininfo->max_iter)
    {
        x_temp = (wininfo->x * wininfo->x) - (wininfo->y * wininfo->y) + x;
        wininfo->y = (2.0 * wininfo->x * wininfo->y) + y;
        wininfo->x = x_temp;
        if (wininfo->x * wininfo->x + wininfo->y * wininfo->y >=__DBL_MAX__)
            break;
    }
    if (wininfo->times_it == wininfo->max_iter)
        fs_pixel_put(wininfo, wininfo->c_x, wininfo->c_y, 0x000000);
    else
        fs_pixel_put(wininfo, wininfo->c_x, wininfo->c_y, choice_color(wininfo));
}
