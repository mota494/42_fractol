/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:04:21 by mloureir          #+#    #+#             */
/*   Updated: 2024/01/23 16:43:41 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	color(int t, int r, int g, int b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

//int		render(t_win_info *wininfo)
//{
//	return (0);
//}