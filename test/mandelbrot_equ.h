/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_equ.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:21:34 by mloureir          #+#    #+#             */
/*   Updated: 2024/01/31 14:52:00 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDELBROT_EQU_H
#define MANDELBROT_EQU_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
#define MAX_ITER 8000000

typedef struct fractal
{
	double c_x;
	double c_y;
	double z_old;
	double z_new;
	double x_real;
	double y_imagi;
}	fractals;

#endif
