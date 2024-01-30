/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:46:31 by mloureir          #+#    #+#             */
/*   Updated: 2024/01/30 17:00:34 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H
#define X_SIZE 901
#define Y_SIZE 901

/***********************************************/
/*					Include					   */
/***********************************************/

# include "includes/ft_printf/ft_printf.h"
# include "includes/libft/libft.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include <math.h>
#include <X11/keysym.h>
#include <X11/X.h>
/***********************************************/
/*					Structs					   */
/***********************************************/

typedef struct s_winfo
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*name;
}			t_win_info;

/***********************************************/
/*					Functions				   */
/***********************************************/

/*main.c*/
int		win_init(t_win_info *wininfo, char *mapname);
int		handle_input(int keysym, t_win_info *wininfo);
int		kill_window( t_win_info *wininfo);
void	setup_hook(t_win_info *wininfo);
/*draw.c*/
int		render(t_win_info *wininfo);
int		color(int t, int r, int g, int b);
/*error_check.c*/
int 	error_main(int argc, char **argv);
int		checkstr(char *str);

#endif
