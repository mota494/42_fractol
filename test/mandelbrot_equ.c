/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_equ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:19:12 by mloureir          #+#    #+#             */
/*   Updated: 2024/02/01 16:27:50 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandelbrot_equ.h"
#include <math.h>

int main()
{
	fractals test;
	int i = 0;
	long double xtemp;
	const long double c = -2;
	const long double y = 0;
	test.c_x = -2;
	test.c_y = 0;
	test.z_old = 0;
	test.z_new = 0;
	while(i < 20) {
		xtemp = (test.c_x * test.c_x) - (test.c_y * test.c_y) + c;
		test.c_y = (2 * test.c_x * test.c_y) + y;
		test.c_x = xtemp;
		printf("(%Lf,%Lf)\n", test.c_x,test.c_y);
		i++;
	}
	return (0);
}
