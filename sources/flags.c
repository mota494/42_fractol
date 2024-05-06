#include "../fractol.h"

void	flag_check(int argc, char **argv, t_win_info *wininfo)
{
	if (check_input(argc, argv) == 0)
		error_befal(wininfo);
}

int	check_input(int argc, char **argv)
{
	int	i;
	int	y;

	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		y = 0;
		while (argv[i][y])
		{
			if (argv[i][y] == '-' && ft_isalpha(argv[i][y + 1]) != 1)
				return (0);
			y++;
		}
		i++;
	}
	return (1);
}
