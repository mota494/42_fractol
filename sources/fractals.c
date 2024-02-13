#include "../fractol.h" 

void	map_mandelbrot(t_win_info *wininfo)
{
	while(wininfo->img.c_x < X)
	{
		while(wininfo->img.c_y < Y)
		{
			mandelbrot_set(wininfo);
			wininfo->img.c_y = 0;
		}
		wininfo->img.c_x++;
		wininfo->img.c_y = 0;
	}	
}

void	mandelbrot_set(t_win_info *wininfo)
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
	{	
		mlx_pixel_put(wininfo->mlx_ptr, wininfo->win_ptr, 
		wininfo->img.c_x, wininfo->img.c_y, color(0,0,0,0));
	}
	else
	{
		x_temp = wininfo->img.c_x;
		mlx_pixel_put(wininfo->mlx_ptr, wininfo->win_ptr,
		wininfo->img.c_x, wininfo->img.c_y, color(0, 255, 0, 0));
	}
}

int	maps_select(t_win_info *wininfo)
{
	if (ft_strcmp("MANDELBROT", wininfo->name) == 1)
		map_mandelbrot(wininfo);
	return (0);
}

