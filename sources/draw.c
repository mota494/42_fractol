/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:04:21 by mloureir          #+#    #+#             */
/*   Updated: 2024/06/20 13:45:29 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	choice_color(t_win_info *wininfo)
{
	int	i;

	i = wininfo->times_it;
	if (wininfo->pressed_m == 1)
		return (color(255, i * wininfo->color.red_mul,
				i * wininfo->color.gre_mul,
				i * wininfo->color.blu_mul));
	else if (wininfo->pressed_h == 0)
		return (color(255, 255, 255, 255));
	else if (i > 25)
		return (color(255, wininfo->color.red_val,
				wininfo->color.gre_val,
				wininfo->color.blu_val));
	else
		return (color(255, i * wininfo->color.red_mul,
				i * wininfo->color.gre_mul,
				i * wininfo->color.blu_mul));
}

int	color(int t, int r, int g, int b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

void	change_render(t_win_info *wininfo)
{
	if (wininfo->pressed_m == 0)
	{
		wininfo->pressed_m = 1;
		wininfo->color.red_mul = 10;
		wininfo->color.gre_mul = 6;
		wininfo->color.blu_mul = 12;
	}
	else
	{
		wininfo->color.red_mul = 2;
		wininfo->color.gre_mul = 0;
		wininfo->color.blu_mul = 4;
		wininfo->pressed_m = 0;
	}
	maps_select(wininfo);
}

void	fs_pixel_put(t_win_info *wininfo, int x, int y, int color)
{
	int	offset;

	offset = (wininfo->img.line_len * y) + (x * (wininfo->img.bpp / 8));
	*((unsigned int *)(offset + wininfo->img.pix_ptr)) = color;
}
