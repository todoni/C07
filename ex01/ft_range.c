/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:17:39 by sohan             #+#    #+#             */
/*   Updated: 2021/04/08 01:31:17 by sohan            ###   ########.fr       */
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
	array_integer = (int *)malloc(range * sizeof(int));
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
	int *array = ft_range(20,10);
	
	printf("%p\n", array);	
	return 0;
}
