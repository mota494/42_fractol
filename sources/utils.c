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
	wininfo->map_id = 0;
	wininfo->x = 0;
	wininfo->y = 0;
	wininfo->max_iter = 40;
	wininfo->zoom = 1.0;
	wininfo->move_x = 0;
	wininfo->move_y = 0;
	wininfo->color.red_val = 150;
	wininfo->color.gre_val = 170;
	wininfo->color.blu_val = 250;
	wininfo->color.red_mul = 2;
	wininfo->color.gre_mul = 0;
	wininfo->color.blu_mul = 4;
	wininfo->pressed_h = 1;
	wininfo->pressed_e = 0;
	wininfo->pressed_m = 0;
}

void	refresh(t_win_info *wininfo)
{
	wininfo->c_y = 0;
	wininfo->c_x = 0;
	wininfo->x = 0;
	wininfo->y = 0;
}
