/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:04:21 by mloureir          #+#    #+#             */
/*   Updated: 2024/05/02 14:03:17 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	choice_color(t_win_info *wininfo)
{
	int i;

	i = wininfo->times_it;
	if (i > 25)
		return (color(255, 150, 170, 250));
	else
		return (color(255, i * 2, 0, i * 4));
}

int	color(int t, int r, int g, int b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

void    fs_pixel_put(t_win_info *wininfo, int x, int y, int color)
{
    int offset;

    offset = (wininfo->img.line_len * y) + (x * (wininfo->img.bpp / 8));

    *((unsigned int *)(offset + wininfo->img.pix_ptr)) = color;
}
