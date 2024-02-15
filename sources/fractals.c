#include "../fractol.h" 

int	maps_select(t_win_info *wininfo)
{
    if (ft_strcmp(wininfo->name, "MANDELBROT") == 1)
    {
        mandelbrot_start(wininfo);
    }
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
}

void    draw_mandelbrot(t_win_info *wininfo)
{

}