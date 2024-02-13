#include "../fractol.h"

double	sum(double num1, double num2)
{
	return (num1 + num2);
}

void	var_init(t_win_info *wininfo)
{
	wininfo->img.x = 0;
	wininfo->img.y = 0;
	wininfo->img.c_x = 0;
	wininfo->img.c_y = 0;
	wininfo->img.of_x = 450;
	wininfo->img.of_y = 450;
	wininfo->img.max_iter = 10;
}

double	power(double num, double exponent)
{
	double	toret;
	double	i;

	i = 1;
	toret = num;
	while(i < exponent)
	{
		toret = toret * num;
		i++;
	}
	return (toret);
}

double	dl_abs(double num)
{
	if (num >= 0)
		return (num);
	else
		return (num * -1);
}
