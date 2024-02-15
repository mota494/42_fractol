#include "../fractol.h" 


int	maps_select(t_win_info *wininfo)
{
    if (ft_strcmp(wininfo->name, "MANDELBROT") == 1)
    {
        printf("%s", wininfo->name);
    }
	return (0);
}

