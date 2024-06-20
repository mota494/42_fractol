/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:10:41 by mloureir          #+#    #+#             */
/*   Updated: 2024/06/20 14:09:24 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	color_reset(t_win_info *wininfo)
{
	if (wininfo->pressed_h == 1)
	{
		wininfo->color.red_val = 150;
		wininfo->color.gre_val = 170;
		wininfo->color.blu_val = 250;
		wininfo->color.red_mul = 2;
		wininfo->color.gre_mul = 0;
		wininfo->color.blu_mul = 4;
		wininfo->pressed_h = 0;
	}
	else
		wininfo->pressed_h = 1;
}

void	mega_render(t_win_info *wininfo)
{
	if (wininfo->pressed_e == 0)
	{
		wininfo->max_iter = 100;
		wininfo->color.red_val = 255;
		wininfo->color.gre_val = 255;
		wininfo->color.blu_val = 255;
		wininfo->pressed_e = 1;
	}
	else
	{
		wininfo->max_iter = 42;
		wininfo->color.red_val = 150;
		wininfo->color.gre_val = 170;
		wininfo->color.blu_val = 250;
		wininfo->pressed_e = 0;
	}
}

void	color_cycle(int keysym, t_win_info *wininfo)
{
	if (keysym == 106)
	{
		wininfo->color.red_val -= 5;
		wininfo->color.gre_val -= 20;
		wininfo->color.blu_val += 10;
		wininfo->color.red_mul -= 1;
		wininfo->color.gre_mul -= 1;
		wininfo->color.blu_mul -= 1;
	}
	else if (keysym == 107)
	{
		wininfo->color.red_val += 5;
		wininfo->color.gre_val += 20;
		wininfo->color.blu_val -= 10;
		wininfo->color.red_mul += 1;
		wininfo->color.gre_mul += 1;
		wininfo->color.blu_mul += 1;
	}
	else if (keysym == 104)
		color_reset(wininfo);
}
