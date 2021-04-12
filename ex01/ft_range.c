/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:17:39 by sohan             #+#    #+#             */
/*   Updated: 2021/04/12 22:41:13 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	unsigned int	range;
	unsigned int	i;
	int				*array_integer;

	range = max - min;
	i = 0;
	array_integer = (int *)malloc((range + 1) * sizeof(int));
	if (array_integer == 0 || min >= max)
		return (0);
	while (i < range)
	{
		array_integer[i] = min + i;
		i++;
	}
	return (array_integer);
}

int main()
{
	int *array = ft_range(-10,10);
	
	for (int i = 0; i< 20; i++)
		printf("%d ", array[i]);	
	return 0;
}
