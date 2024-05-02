/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:03:17 by mloureir          #+#    #+#             */
/*   Updated: 2024/05/02 14:03:17 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double  scale(double num, double n_mi, double n_ma, double o_mi, double o_ma)
{
    double scaled_number;

    scaled_number = (n_ma - n_mi) * (num - o_mi) / (o_ma - o_mi) + n_mi;
    return (scaled_number);
}