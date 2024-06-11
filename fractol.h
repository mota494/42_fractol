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

typedef	struct s_imginfo
{

	void	*img_ptr;
	char	*pix_ptr;
	int     bpp;
	int     endian;
	int     line_len;

}		t_imginfo;

typedef struct s_winfo
{
    //USEROPTS
	char		**flags;
    	char		*name;
    //MLX
	void		*mlx_ptr;
	void		*win_ptr;
    //Fractals
	int         c_x;
	int 		c_y;
    double      x;
    double      y;
	double		max_iter;
    //IMG
	t_imginfo	img;
}			t_win_info;

typedef struct s_flag_ingo
{
	char	flag[2];
	char	*argumment;
}			t_flags;

/***********************************************/
/*					Functions				   */
/***********************************************/

/*main.c*/
int		win_init(t_win_info *wininfo);
int		handle_input(int keysym, t_win_info *wininfo);
int		kill_window( t_win_info *wininfo);
void	setup_hook(t_win_info *wininfo);
/*flags.c*/
void	flag_check(int argc, char **argv, t_win_info *wininfo);
int	check_input(int argc, char **argv);
/*draw.c*/
int	choice_color(t_win_info *wininfo);
int		color(int t, int r, int g, int b);
void    fs_pixel_put(t_win_info *wininfo, int x, int y, int color);
/*error_check.c*/
void	error_befal(t_win_info *wininfo);
void	error_aftal(t_win_info *wininfo);
int 	error_main(int argc, char **argv);
int	map_checker(char *str);
int		checkstr(char *str);
/*fractals.c*/
int		maps_select(t_win_info *wininfo);
void    mandelbrot_start(t_win_info *wininfo);
void    draw_mandelbrot(t_win_info *wininfo);
/*utils.c*/
void        var_init(t_win_info *wininfo);
void	strup(char *str);
int	ft_isspace(int c);
/*math.c*/
double  scale(double num, double n_mi, double n_ma, double o_mi, double o_ma);
#endif
