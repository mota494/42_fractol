/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:32:31 by mloureir          #+#    #+#             */
/*   Updated: 2024/01/23 16:38:38 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(char *tocomp, char *target)
{
	unsigned long i;

	i = 0;
	if (ft_strlen(target) <= 0)
		return (0);
	while (tocomp[i] && target[i] && tocomp[i] == target[i])
		i++;
	if (i == ft_strlen(target))
		return (1);
	if (i != ft_strlen(target))
		return (0);
	return (0);
}
