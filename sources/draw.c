/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:04:21 by mloureir          #+#    #+#             */
/*   Updated: 2024/01/31 10:29:56 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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