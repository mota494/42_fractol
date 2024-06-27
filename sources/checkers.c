#include "../fractol.h"

int	ver_num(char *str)
{
	int	i;
	int	count_dot;

	i = 0;
	count_dot = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) != 1 && str[i] != '.'
			&& str[i] != '+' && str[i] != '-')
			return (0);
		if (str[i] == '.')
			count_dot++;
		if (count_dot > 1)
			return (0);
		i++;
	}
	return (1);
}

int	julia_main(int argc, char **argv, t_win_info *wininfo)
{
	int	i;

	i = 2;
	if (argc != 4)
		return (0);
	while (i < argc && wininfo->map_id == JULIA)
	{
		if (ver_num(argv[i]) != 1)
			return (0);
		i++;
	}
	wininfo->jul_x = string_double(argv[2]);
	wininfo->jul_y = string_double(argv[3]);
	return (1);
}

int	check_dec(char *str)
{
	int	len;
	int	count;

	len = ft_strlen(str);
	count = -1;
	while (str[len] != '.')
	{
		count++;
		len--;
	}
	return (count);
}

void	rm_dot(char *str)
{
	int	y;

	y = 0;
	while (str[y] != '.')
		y++;
	while (str[y] != '\0')
	{
		str[y] = str[y + 1];
		y++;
	}
}

double	string_double(char *str)
{
	double	toret;
	int		dec;
	int		help;
	int		get_dec;

	toret = 0;
	help = 1;
	get_dec = 10;
	dec = check_dec(str);
	rm_dot(str);
	toret = ft_atoi(str);
	while (help < dec)
	{
		get_dec *= 10;
		help++;
	}
	toret = toret / get_dec;
	return (toret);
}
