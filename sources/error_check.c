/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:13:55 by mloureir          #+#    #+#             */
/*   Updated: 2024/05/02 14:03:17 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	error_befal(t_win_info *wininfo)
{
	ft_putstr_fd("!INPUT ERROR!\n", 2);
	free(wininfo->name);
	exit(0);
}

void	error_aftal(t_win_info *wininfo)
{
	ft_putstr_fd("!INPUT ERROR!\n", 2);
	kill_window(wininfo);
}

int	checkstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 65 || str[i] > 90)
			return (0);
		i++;
	}
	return (1);
}

int	map_checker(char *str)
{
	if (ft_strcmp("MANDELBROT", str) == 1)
		return (1);
	if (ft_strcmp("JULIA", str) == 1)
		return (1);
	return (0);
}

int	error_main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	strup(argv[1]);
	if (checkstr(argv[1]) != 1)
		return (0);
	if (map_checker(argv[1]) != 1)
		return (0);
	return (1);
}
