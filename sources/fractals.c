#include "../fractol.h"

void	map_mandelbrot(t_win_info *wininfo)
{
	double	start_x;
	double	start_y;
	double	xtemp;

	start_x = 1;
	start_y = 3;
	wininfo->value.x = 0;
	wininfo->value.y = 0;
	ft_printf("(%d, %d)", wininfo->value.x, wininfo->value.y);
	while (sum(wininfo->value.x, wininfo->value.y) < __DBL_MAX__)
	{
		xtemp = (wininfo->value.x * wininfo->value.x) - (wininfo->value.y * wininfo->value.y) + start_x;
		wininfo->value.y = (2 * wininfo->value.x * wininfo->value.y) + start_y;
		wininfo->value.x = xtemp;
		ft_printf("(%d , %d) \n", wininfo->value.x + 450, wininfo->value.y + 450);
		mlx_pixel_put(wininfo->mlx_ptr, wininfo->win_ptr, wininfo->value.x + 450, wininfo->value.y + 450, color(0,255,0,0));
	}
}

int	maps_select(t_win_info *wininfo)
{
	if (ft_strcmp("MANDELBROT", wininfo->name) == 1)
		map_mandelbrot(wininfo);
	return (0);
}


