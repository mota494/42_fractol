/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_equ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:19:12 by mloureir          #+#    #+#             */
/*   Updated: 2024/02/01 10:44:14 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandelbrot_equ.h"

int main()
{
	fractals test;
	int i = 0;
	double xtemp;
	const double c = -2;
	const double y = 0;
	test.c_x = 0;
	test.c_y = 0;
	test.z_old = 0;
	test.z_new = 0;
	while(i < 2) {
		xtemp = (test.c_x * test.c_x) - (test.c_y * test.c_y) + c;
		test.c_y = (2 * test.c_x * test.c_y) + y;
		test.c_x = xtemp;
		printf("(%.3f,%.2f)\n", test.c_x,test.c_y);
		i++;
	}
	return (0);
}