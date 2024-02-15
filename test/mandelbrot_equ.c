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

#include "../fractol.h"

typedef struct img
{
	char	*addr;
	int	bbp;
	int	line_l;
	int	endian;
}	t_img_info;

int main()
{
	t_win_info wininfo;
	t_img_info imginfo;

	wininfo.mlx_ptr = mlx_init();
	wininfo.img_ptr = mlx_new_image(wininfo.win_ptr, X, Y);
	imginfo.addr = mlx_get_data_addr(wininfo.img_ptr, &imginfo.bbp, 
	&imginfo.line_l, &imginfo.endian); 
	
	free(wininfo.mlx_ptr);
	return (0);
}
