#include "../fractol.h"
#include <stdio.h>

void	mandelbrot_set(t_win_info *wininfo, int color)
{
	int	x;
	int	y;

	x = wininfo->img.c_x + wininfo->img.of_x;
	y = wininfo->img.c_y + wininfo->img.of_y;
	mlx_pixel_put(wininfo->mlx_ptr, wininfo->win_ptr, x, y, color);
	while(wininfo->img.c_x < X)
	{
		while(wininfo->img.c_y < Y)
		{
			map_mandelbrot(wininfo);
			wininfo->img.c_y++;
		}
		wininfo->img.c_x++;
		wininfo->img.c_y = 0;
	}
}

void	map_mandelbrot(t_win_info *wininfo)
{
	double	i;
	double	x_temp;

	i = 0;
	while (i < wininfo->img.max_iter)
	{
		x_temp = power(wininfo->img.x, 2) - power(wininfo->img.y, 2);
		x_temp += wininfo->img.c_x;
		wininfo->img.y =  2 * wininfo->img.x * wininfo->img.y;
		wininfo->img.y += wininfo->img.c_y;
		wininfo->img.x = x_temp;
		if (power(wininfo->img.x, 2) + power(wininfo->img.y, 2) > __DBL_MAX__)
			break;
		i++;
	}
	if (i == wininfo->img.max_iter)
		mandelbrot_set(wininfo, color(0,0,0,0));
	else
	{
		x_temp = wininfo->img.c_x;
		mandelbrot_set(wininfo, color(0,x_temp,x_temp,x_temp));
	}
}

int	maps_select(t_win_info *wininfo)
{
	if (ft_strcmp("MANDELBROT", wininfo->name) == 1)
		map_mandelbrot(wininfo);
	return (0);
}


