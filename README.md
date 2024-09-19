<div align = "center">

# Fract_ol
![Static Badge](https://img.shields.io/badge/115%2F100-green?style=for-the-badge&logo=42&logoColor=%23F0EDCC&label=Score&labelColor=%2302343F&color=%23F0EDCC
)
![Static Badge](https://img.shields.io/badge/Language-green?style=for-the-badge&logo=C&logoColor=%23F0EDCC&labelColor=%2302343F&color=%23F0EDCC
)

[![Static Badge](https://img.shields.io/badge/Music%20Suggestion-Click%20Me?style=for-the-badge&logo=YouTube&logoColor=%23000000&labelColor=%23FFFFFF&color=%23FF0000)](https://www.youtube.com/watch?v=kd-8yZ1hhko)

Fract_ol, the first C graphical project that i developed and one of the least subscribed 42 projects on the common core

---

</div>

<div align="center">

# Minilibx and Fract_ol

</div>


MiniLibX is a piece of garbage library that comes with no documentation whatsoever and the little comments left on the code are all either in French or don't say anything on how to actually use the functions.

The student HAS to use it and the guide on the official repository doesn't say anything about compilation flags which is brilliant.

Technical stuff now.

```C
/*==== Makefile ====*/

-L/usr/X11R6/lib -lX11 -lXext -lm #this has to be on the compiler

/*====Fractals.c====*/

/*This is the file where basically everything happens, and anything before this is just error checking and value initialization.
The math is quite simple, the code cycles from X and Y 0 untill it reaches X and Y *window size* and sends wherever point it's on to a formula that calculates whether or not that point belongs to said fractal
Fractal limits are down to the . so I use a formula to transform the window coordinates value into floats that fit the XYgraph with the limits that I want, for example the coordinate (750,320) on the screen translates to (1.(3), -0.5(7)) on the XY graph
*/

int	mandelbrot_start(t_win_info *wininfo)
{
	while (wininfo->c_x < X)
	{
		wininfo->c_y = 0;
		while (wininfo->c_y < Y)
		{
			draw_mandelbrot(wininfo);
			wininfo->c_y++;
		}
		wininfo->c_x++;
	}
	mlx_put_image_to_window(wininfo->mlx_ptr, wininfo->win_ptr,
		wininfo->img.img_ptr, 0, 0);
	refresh(wininfo);
	return (0);
}

void	draw_mandelbrot(t_win_info *wininfo)
{
	double	x_temp;
	double	x;
	double	y;

	wininfo->times_it = 0;
	wininfo->x = 0;
	wininfo->y = 0;
	x = (scale(wininfo->c_x, -2, 2, 0) * wininfo->zoom) + wininfo->move_x;
	y = (scale(wininfo->c_y, -2, 2, 0) * wininfo->zoom) + wininfo->move_y;
	while (++wininfo->times_it < wininfo->max_iter)
	{
		x_temp = (wininfo->x * wininfo->x) - (wininfo->y * wininfo->y) + x;
		wininfo->y = (2.0 * wininfo->x * wininfo->y) + y;
		wininfo->x = x_temp;
		if (wininfo->x * wininfo->x + wininfo->y * wininfo->y >= __DBL_MAX__)
			break ;
	}
	if (wininfo->times_it == wininfo->max_iter)
		fs_pixel_put(wininfo, wininfo->c_x, wininfo->c_y, 0x000000);
	else
		fs_pixel_put(wininfo, wininfo->c_x, wininfo->c_y,
			choice_color(wininfo));
}

/*draw.c*/
//I was very picky with the colors that i wanted to use and it's something that I spend way to much time dealing with but I ended up with a fairly simple function that cycles through the colors that i want and supports 3 modes, all white where everything is white except the fractal set, a gradiant mode where everything is a nice color grandiant except the fractal set and the default color mode which every point that's iterated X times is a defined color and everything else is a purple gradiant. On top of the three modes the user can press _J_ or _K_ on the keyboard to cycle different color palletes, this is done through a simple change of values that are later used o calculate which color should a pixel be

int	choice_color(t_win_info *wininfo)
{
	int	i;

	i = wininfo->times_it;
	if (wininfo->pressed_m == 1)
		return (color(255, i * wininfo->color.red_mul,
				i * wininfo->color.gre_mul,
				i * wininfo->color.blu_mul));
	else if (wininfo->pressed_h == 0)
		return (color(255, 255, 255, 255));
	else if (i > 25)
		return (color(255, wininfo->color.red_val,
				wininfo->color.gre_val,
				wininfo->color.blu_val));
	else
		return (color(255, i * wininfo->color.red_mul,
				i * wininfo->color.gre_mul,
				i * wininfo->color.blu_mul));
}

void	change_render(t_win_info *wininfo)
{
	if (wininfo->pressed_m == 0)
	{
		wininfo->pressed_m = 1;
		wininfo->color.red_mul = 10;
		wininfo->color.gre_mul = 6;
		wininfo->color.blu_mul = 12;
	}
	else
	{
		wininfo->color.red_mul = 2;
		wininfo->color.gre_mul = 0;
		wininfo->color.blu_mul = 4;
		wininfo->pressed_m = 0;
	}
	maps_select(wininfo);
```