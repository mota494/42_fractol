/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:38:16 by mloureir          #+#    #+#             */
/*   Updated: 2024/05/02 14:03:17 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <X11/X.h>

int	kill_window(t_win_info *wininfo)
{
    mlx_destroy_image(wininfo->mlx_ptr, wininfo->img.img_ptr);
	mlx_destroy_window(wininfo->mlx_ptr, wininfo->win_ptr);
	mlx_destroy_display(wininfo->mlx_ptr);
	free(wininfo->mlx_ptr);
	free(wininfo->name);
	exit(0);
    return (0);
}

int	handle_input(int keysym, t_win_info *wininfo)
{
	if (keysym == XK_Escape)
		kill_window(wininfo);
	return (0);
}

int	win_init(t_win_info *wininfo)
{
	wininfo->mlx_ptr = mlx_init();
	if (wininfo->mlx_ptr == NULL)
	{
		mlx_destroy_display(wininfo->mlx_ptr);
		return (0);
	}
	wininfo->win_ptr = mlx_new_window(wininfo->mlx_ptr, X, Y, wininfo->name);
	if (wininfo->win_ptr == NULL)
	{
		free(wininfo->mlx_ptr);
		return (0);
	}
	wininfo->img.img_ptr = mlx_new_image(wininfo->mlx_ptr, X, Y);
	wininfo->img.pix_ptr = mlx_get_data_addr(wininfo->img.img_ptr,
                                             &wininfo->img.bpp,
                                             &wininfo->img.line_len,
                                             &wininfo->img.endian);
	return (1);
}

void	setup_hook(t_win_info *wininfo)
{
	mlx_hook(wininfo->win_ptr, KeyPress, KeyPressMask, &handle_input, wininfo);
	mlx_mouse_hook(wininfo->win_ptr, mouse_hook, wininfo);
	mlx_hook(wininfo->win_ptr, 17, 0, &kill_window, wininfo);
	maps_select(wininfo);
	mlx_loop(wininfo->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_win_info	wininfo;

	wininfo.name = ft_calloc(1, 1);
	flag_check(argc, argv, &wininfo);
	var_init(&wininfo);
	if (win_init(&wininfo) == 0)
		return (0);
	setup_hook(&wininfo);
	return (0);
}
