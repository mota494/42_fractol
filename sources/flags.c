/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:15:47 by mloureir          #+#    #+#             */
/*   Updated: 2024/06/20 13:46:47 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	flag_insert(t_win_info *wininfo)
{
	ft_printf("|--Fract_ol: Computer Graphics Fractals-----|\n");
	ft_printf("|                                           |\n");
	ft_printf("| Just use ./fractol <map_name>             |\n");
	ft_printf("|                                           |\n");
	ft_printf("| Maps available:                           |\n");
	ft_printf("| ./fractol Mandelbrot                      |\n");
	ft_printf("|-------------------------------------------|\n");
	free(wininfo->name);
	exit(0);
}

int	flags_lib(char *str)
{
	if (ft_strcmp("-h", str) == 1)
		return (1);
	return (0);
}

void	flag_verify(char *str, t_win_info *wininfo)
{
	static int	tick;

	if (flags_lib(str) == 1)
		tick = 1;
	else if (tick == 1 && flags_lib(str) == 0)
		tick = 0;
	else if (tick == 0 && flags_lib(str) == 0)
		error_befal(wininfo);
}

void	flag_check(int argc, char **argv, t_win_info *wininfo)
{
	int	i;

	i = 1;
	if (check_input(argc, argv) == 0 || argc < 2)
		error_befal(wininfo);
	strup(argv[argc - 1]);
	while (i < argc - 1)
	{
		flag_verify(argv[i], wininfo);
		i++;
	}
	if (map_checker(argv[argc - 1]) != 1)
		error_befal(wininfo);
	wininfo->name = alocpy(wininfo->name, argv[argc - 1]);
}

int	check_input(int argc, char **argv)
{
	int	i;
	int	y;

	i = 1;
	while (i < argc)
	{
		y = 0;
		while (argv[i][y])
		{
			if (argv[i][y] == '-'
					&& ft_isalpha(argv[i][y + 1]) != 1)
				return (0);
			else if (argv[i][y] == '-')
			{
				if (ft_isalpha(argv[i][y + 1]) == 1
					&& ft_isspace(argv[i][y + 2]) != 1)
					return (0);
			}
			y++;
		}
		i++;
	}
	return (1);
}
