#include "../fractol.h" 

void	map_mandelbrot(t_win_info *wininfo)
{
	while(wininfo->c_x < X)
	{
		while(wininfo->c_y < Y)
		{
			mandelbrot_set(wininfo);
			wininfo->c_y = 0;
		}
		wininfo->c_x++;
		wininfo->c_y = 0;
	}	
}

void	mandelbrot_set(t_win_info *wininfo)
{
	double	i;
	double	x_temp;

	i = 0;
	while (i < wininfo->max_iter)
	{
		x_temp = power(wininfo->x, 2) - power(wininfo->y, 2);
		x_temp += wininfo->c_x;
		wininfo->y =  2 * wininfo->x * wininfo->y;
		wininfo->y += wininfo->c_y;
		wininfo->x = x_temp;
		if (power(wininfo->x, 2) + power(wininfo->y, 2) > __DBL_MAX__)
			break;
		i++;
	}
	if (i == wininfo->max_iter)
	{	
		mlx_pixel_put(wininfo->mlx_ptr, wininfo->win_ptr, 
		wininfo->c_x, wininfo->c_y, color(0,0,0,0));
	}
	else
	{
		x_temp = wininfo->c_x;
		mlx_pixel_put(wininfo->mlx_ptr, wininfo->win_ptr,
		wininfo->c_x, wininfo->c_y, color(0, 255, 0, 0));
	}
}

int	maps_select(t_win_info *wininfo)
{
	if (ft_strcmp("MANDELBROT", wininfo->name) == 1)
		map_mandelbrot(wininfo);
	return (0);
}

