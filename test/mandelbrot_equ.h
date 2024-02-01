/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_equ.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:21:34 by mloureir          #+#    #+#             */
/*   Updated: 2024/02/01 17:03:12 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDELBROT_EQU_H
#define MANDELBROT_EQU_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
#define MAX_ITER 90

typedef struct fractal
{
	long double c_x;
	long double c_y;
	long double z_old;
	long double z_new;
	long double x_real;
	long double y_imagi;
}	fractals;

#endif
