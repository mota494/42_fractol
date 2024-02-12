/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:46:31 by mloureir          #+#    #+#             */
/*   Updated: 2024/01/31 11:58:02 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H
#define X 900
#define Y 900

/***********************************************/
/*					Include					   */
/***********************************************/

# include "includes/ft_printf/ft_printf.h"
# include "includes/libft/libft.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include <math.h>
# include <limits.h>
#include <X11/keysym.h>
#include <X11/X.h>

/***********************************************/
/*					Structs					   */
/***********************************************/

typedef struct fractal
{
	double	c_x;
	double	c_y;
	double	x;
	double	y;
	double	xtemp;
	double	of_x;
	double	of_y;
	double	max_iter;
}	fractals;


typedef struct s_winfo
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*name;
	fractals	img;
}			t_win_info;

/***********************************************/
/*					Functions				   */
/***********************************************/

/*main.c*/
int		win_init(t_win_info *wininfo);
int		handle_input(int keysym, t_win_info *wininfo);
int		kill_window( t_win_info *wininfo);
void	setup_hook(t_win_info *wininfo);
/*draw.c*/
int		color(int t, int r, int g, int b);
/*error_check.c*/
int 	error_main(int argc, char **argv);
int		checkstr(char *str);
/*fractals.c*/
int		maps_select(t_win_info *wininfo);
void	map_mandelbrot(t_win_info *wininfo);
void	mandelbrot_set(t_win_info *wininfo, int color);
/*utils.c*/
void	var_init(t_win_info *wininfo);
double	sum(double num1, double num2);
double	power(double num, double exponent);
double	dl_abs(double num);
#endif
