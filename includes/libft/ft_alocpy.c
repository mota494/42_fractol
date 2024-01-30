/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alocpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:05:01 by mloureir          #+#    #+#             */
/*   Updated: 2024/01/30 17:35:19 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*alocpy(char *dest, char *src)
{
	size_t 	len;
	size_t	i;
	char *newstr;

	i = 0;
	free(dest);
	len = ft_strlen(src);
	newstr = malloc(len + 1);
	while(i < len)
	{
		newstr[i] = newstr[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}