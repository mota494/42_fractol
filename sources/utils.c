#include "../fractol.h"

double	sum(double num1, double num2)
{
	return (num1 + num2);
}

void	var_init(t_win_info *wininfo)
{
	wininfo->x = 0;
	wininfo->y = 0;
	wininfo->c_x = 0;
	wininfo->c_y = 0;
	wininfo->of_x = 450;
	wininfo->of_y = 450;
	wininfo->max_iter = 10;
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
