/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:28:14 by mloureir          #+#    #+#             */
/*   Updated: 2024/01/31 12:46:02 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	maps_select(t_win_info *wininfo)
{
	if (ft_strcmp(wininfo->name, "JULIA") == 1)
		mp_julia(wininfo);
//	if (ft_strcmp(wininfo->name, "MANDELBROT") == 1)
//		mp_mandelbrot(wininfo);
	return (1);
}

void	mp_julia(t_win_info *wininfo)
{
	fractals test;
	const double c = -2;
	const double y = 0.6;
	test.c_x = -2;
	test.c_y = 0.6;
	test.z_old = 0;
	test.z_new = 0;
	while(test.z_new < __DBL_MAX__)
	{
		test.c_x = test.c_x * test.c_x + c;
		test.c_y = (test.c_y * test.c_y)+ y;
		test.z_new = test.c_x + test.c_y;
		mlx_pixel_put(wininfo->mlx_ptr, wininfo->win_ptr, test.c_x, test.c_y, color(0,255,0,0));
	}
}

//void	mp_mandelbrot(t_win_info *wininfo)
//{
//
//}