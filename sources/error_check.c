/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:13:55 by mloureir          #+#    #+#             */
/*   Updated: 2024/01/23 16:53:26 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	strup(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] = str[i] - 32;
		i++;
	}
}

int	checkstr(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		if(str[i] < 65 || str[i] > 90)
			return (0);
		i++;
	}
	return (1);
}

int	mapchecker(char *str)
{
	if (ft_strcmp("MANDELBROT", str) == 1)
		return (1);
	if (ft_strcmp("JULIA", str) == 1)
		return (1);
	return (0);
}

int 	error_main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	strup(argv[1]);
	if (checkstr(argv[1]) != 1)
		return (0);
	if (mapchecker(argv[1]) != 1)
		return (0);
	return (1);
}