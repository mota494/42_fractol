/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:38:16 by mloureir          #+#    #+#             */
/*   Updated: 2024/01/23 11:54:52 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	kill_window( t_win_info *wininfo)
{
	mlx_destroy_window(wininfo->mlx_ptr, wininfo->win_ptr);
	mlx_destroy_display(wininfo->mlx_ptr);
	free(wininfo->mlx_ptr);
	exit(0);
}
int handle_input(int keysym, t_win_info *wininfo)
{
	if (keysym == XK_Escape)
		kill_window(wininfo);
	return (0);
}

int		win_init(t_win_info *wininfo)
{
	wininfo->mlx_ptr = mlx_init();
	if (wininfo->mlx_ptr == NULL)
	{
		mlx_destroy_display(wininfo->mlx_ptr);
		return (0);
	}
	wininfo->win_ptr = mlx_new_window(wininfo->mlx_ptr, X_SIZE, Y_SIZE, "fractol");
	if (wininfo->win_ptr == NULL)
	{
		free(wininfo->mlx_ptr);
		return (0);
	}
	return (1);
}

void	setup_hook(t_win_info *wininfo)
{
	mlx_hook(wininfo->win_ptr, KeyPress, KeyPressMask, &handle_input, wininfo);
	mlx_hook(wininfo->win_ptr, 17, 0, &kill_window, wininfo);
	//mlx_loop_hook(wininfo->mlx_ptr, &drawfunc, wininfo);
	mlx_loop(wininfo->mlx_ptr);
}

int main(void)
{
	t_win_info wininfo;

	if(win_init(&wininfo) == 0)
		return (0);
	setup_hook(&wininfo);
	return (0);
}
