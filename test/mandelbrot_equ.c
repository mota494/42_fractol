/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_equ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:19:12 by mloureir          #+#    #+#             */
/*   Updated: 2024/01/31 16:49:42 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandelbrot_equ.h"

int main()
{
	fractals test;
	int i = 0;
	double xtemp;
	const double c = 0.25;
	const double y = 0.3;
	test.c_x = 0;
	test.c_y = 0;
	test.z_old = 0;
	test.z_new = 0;
	printf("%f", 3 + y);
	while(1)
	{
		xtemp = test.c_x * test.c_x + c;
		test.c_y = 2 * (test.c_x * test.c_y) + y;
		test.c_x = xtemp;
		printf("(%.3f,%.2f)\n", test.c_x,test.c_y);
		i++;
	}
	return (0);
}