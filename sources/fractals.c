/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:28:14 by mloureir          #+#    #+#             */
/*   Updated: 2024/02/01 16:59:43 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	maps_select(t_win_info *wininfo)
{
	if (ft_strcmp(wininfo->name, "JULIA") == 1)
		mp_julia(wininfo);
//	if (ft_strcmp(wininfo->name, "MANDELBROT") == 1)
//		mp_mandelbrot(wininfo);
	return (1);
}

void	mp_julia(t_win_info *wininfo)
{

}

//void	mp_mandelbrot(t_win_info *wininfo)
//{
//
//}