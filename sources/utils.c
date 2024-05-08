/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:03:17 by mloureir          #+#    #+#             */
/*   Updated: 2024/05/02 14:35:58 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

long double	sum(double num1, double num2)
{
	return (num1 + num2);
}

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || (c == 32) || ft_isprint(c) == 0)
		return (1);
	return (0);
}

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

void	var_init(t_win_info *wininfo)
{
    wininfo->mlx_ptr = NULL;
    wininfo->win_ptr = NULL;
    wininfo->img.img_ptr = NULL;
    wininfo->img.pix_ptr = NULL;
	wininfo->c_x = 0;
	wininfo->c_y = 0;
    wininfo->x = 0;
    wininfo->y = 0;
	wininfo->max_iter = 120;
}
