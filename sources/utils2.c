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

void	helper(void)
{
	ft_printf("--Movement--\n");
	ft_printf("Use the arrows key to move\n");
	ft_printf("Scroll Up: Zoom in\nScroll down: Zoom out\n");
	ft_printf("Numpad +: Zoom in\nNumpad -: Zoom out\n");
	ft_printf("--Colors--\n");
	ft_printf("J and K to cycle through different color schemes\n");
	ft_printf("H to restart colors or to change everything to white\n");
	ft_printf("M enables gradient color\n");
}
