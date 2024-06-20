/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:09:33 by mloureir          #+#    #+#             */
/*   Updated: 2024/06/20 14:18:40 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mouse_hook(int mousesym, int x, int y, t_win_info *wininfo)
{
	wininfo->mouse_x = x;
	wininfo->mouse_y = y;
	if (mousesym == 4)
		wininfo->zoom *= 0.95;
	else if (mousesym == 5)
		wininfo->zoom *= 1.05;
	return (0);
}

void	key_zoom(int keysym, t_win_info *wininfo)
{
	double	zoom;

	zoom = 0.2;
	if (keysym == 65451)
		wininfo->zoom = wininfo->zoom + zoom;
	else if (keysym == 65453)
		wininfo->zoom = wininfo->zoom - zoom;
}

void	movement(int keysym, t_win_info *wininfo)
{
	if (keysym == 65361)
		wininfo->move_x -= 0.08 * wininfo->zoom;
	else if (keysym == 65363)
		wininfo->move_x += 0.08 * wininfo->zoom;
	else if (keysym == 65362)
		wininfo->move_y -= 0.08 * wininfo->zoom;
	else if (keysym == 65364)
		wininfo->move_y += 0.08 * wininfo->zoom;
}
