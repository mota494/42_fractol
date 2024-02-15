#include "../fractol.h"

long double	sum(double num1, double num2)
{
	return (num1 + num2);
}

void	var_init(t_win_info *wininfo)
{
    wininfo->mlx_ptr = NULL;
    wininfo->win_ptr = NULL;
    wininfo->img.img_ptr = NULL;
    wininfo->img.pix_ptr = NULL;
	wininfo->x = 0;
	wininfo->y = 0;
	wininfo->c_x = 0;
	wininfo->c_y = 0;
	wininfo->of_x = 450;
	wininfo->of_y = 450;
	wininfo->max_iter = 10;
}
