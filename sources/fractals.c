/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:10:27 by mloureir          #+#    #+#             */
/*   Updated: 2024/06/20 14:17:56 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	maps_select(t_win_info *wininfo)
{
	if (wininfo->map_id == MANDELBROT)
		mlx_loop_hook(wininfo->mlx_ptr, mandelbrot_start, wininfo);
	if (wininfo->map_id == JULIA)
		mlx_loop_hook(wininfo->mlx_ptr, julia_start, wininfo);
	return (0);
}

int	mandelbrot_start(t_win_info *wininfo)
{
	while (wininfo->c_x < X)
	{
		wininfo->c_y = 0;
		while (wininfo->c_y < Y)
		{
			draw_mandelbrot(wininfo);
			wininfo->c_y++;
		}
		wininfo->c_x++;
	}
	mlx_put_image_to_window(wininfo->mlx_ptr, wininfo->win_ptr,
		wininfo->img.img_ptr, 0, 0);
	refresh(wininfo);
	return (0);
}

int	julia_start(t_win_info *wininfo)
{
	while (wininfo->c_x < X)
	{
		wininfo->c_y = 0;
		while (wininfo->c_y < Y)
		{
			draw_julia(wininfo);
			wininfo->c_y++;
		}
		wininfo->c_x++;
	}
	mlx_put_image_to_window(wininfo->mlx_ptr, wininfo->win_ptr,
		wininfo->img.img_ptr, 0, 0);
	refresh(wininfo);
	return (0);
}

void	draw_julia(t_win_info *wininfo)
{
	double	x_temp;

	wininfo->times_it = 0;
	wininfo->x = (scale(wininfo->c_x, -2, 2, 0) * wininfo->zoom)
		+ wininfo->move_x;
	wininfo->y = (scale(wininfo->c_y, -2, 2, 0) * wininfo->zoom)
		+ wininfo->move_y;
	while (++wininfo->times_it < wininfo->max_iter)
	{
		x_temp = (wininfo->x * wininfo->x)
			- (wininfo->y * wininfo->y) + wininfo->jul_x;
		wininfo->y = (2.0 * wininfo->x * wininfo->y) + wininfo->jul_y;
		wininfo->x = x_temp;
		if (wininfo->x * wininfo->x + wininfo->y * wininfo->y >= __DBL_MAX__)
			break ;
	}
	if (wininfo->times_it == wininfo->max_iter)
		fs_pixel_put(wininfo, wininfo->c_x, wininfo->c_y, 0x000000);
	else
		fs_pixel_put(wininfo, wininfo->c_x, wininfo->c_y,
			choice_color(wininfo));
}

void	draw_mandelbrot(t_win_info *wininfo)
{
	double	x_temp;
	double	x;
	double	y;

	wininfo->times_it = 0;
	wininfo->x = 0;
	wininfo->y = 0;
	x = (scale(wininfo->c_x, -2, 2, 0) * wininfo->zoom) + wininfo->move_x;
	y = (scale(wininfo->c_y, -2, 2, 0) * wininfo->zoom) + wininfo->move_y;
	while (++wininfo->times_it < wininfo->max_iter)
	{
		x_temp = (wininfo->x * wininfo->x) - (wininfo->y * wininfo->y) + x;
		wininfo->y = (2.0 * wininfo->x * wininfo->y) + y;
		wininfo->x = x_temp;
		if (wininfo->x * wininfo->x + wininfo->y * wininfo->y >= __DBL_MAX__)
			break ;
	}
	if (wininfo->times_it == wininfo->max_iter)
		fs_pixel_put(wininfo, wininfo->c_x, wininfo->c_y, 0x000000);
	else
		fs_pixel_put(wininfo, wininfo->c_x, wininfo->c_y,
			choice_color(wininfo));
}
