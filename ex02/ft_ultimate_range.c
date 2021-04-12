/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 01:33:55 by sohan             #+#    #+#             */
/*   Updated: 2021/04/12 23:06:28 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	unsigned int	num_range;
	unsigned int	i;
	int				*array;

	num_range = max - min;
	i = 0;
	array = (int *)malloc((num_range + 1) * sizeof(int));
	if (array == 0)
		return (-1);
	else if (min >= max)
		*range = 0;
		return (0);
	*range = array;
	while (i < num_range)
	{
		array[i] = min + i;
		i++;
	}
	return (num_range + 1);
}
