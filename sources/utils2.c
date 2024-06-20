/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:15:47 by mloureir          #+#    #+#             */
/*   Updated: 2024/06/18 16:15:47 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	arrow_check(int keysym)
{
	if (keysym == 65361 || keysym == 65362)
		return (1);
	else if (keysym == 65363 || keysym == 65364)
		return (1);
	return (0);
}

void	restart_mandelbrot(t_win_info *wininfo)
{
	wininfo->zoom = 1.0;
	wininfo->move_x = 0;
	wininfo->move_y = 0;
}
