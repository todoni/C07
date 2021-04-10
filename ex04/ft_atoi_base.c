/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 20:46:44 by sohan             #+#    #+#             */
/*   Updated: 2021/04/09 00:04:01 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int	is_valid_case(char *base)
{
	int n;

	n = 0;
	while (*base != 0)
	{
		if (*base == '+' || *base == '-' || *base == ' ' || \
				*base == '\t' || *base == '\n' || *base == '\v' || \
										*base == '\f' || *base == '\r')
			return (0);
		base++;
		n++;
	}
	return (n);
}

int	is_overlap(char *base)
{
	int count_char[256];
	int i;

	i = 0;
	while (i < 256)
	{
		count_char[i] = 0;
		i++;
	}
	i = 0;
	while (*base != '\0')
	{
		while (i < 256)
		{
			if (*base == i)
				count_char[i] += 1;
			if (count_char[i] > 1)
				return (0);
			i++;
		}
		base++;
		i = 0;
	}
	return (1);
}

int	find_base_index(char *base, char str)
{
	int index;

	index = 0;
	while (str != *base && *base != '\0')
	{
		base++;
		index++;
	}
	base -= index;
	if (index == is_valid_case(base))
		return (0);
	return (index);
}

int	calculate_result(char *str, char *base, int n_power_of_base)
{
	int index;
	int result;
	int n;

	index = 0;
	result = 0;
	n = is_valid_case(base);
	while (*str != '-' && *str != '+')
	{
		index = find_base_index(base, *str);
		result = result + index * n_power_of_base;
		n_power_of_base *= n;
		str--;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	n_power_of_base;

	n_power_of_base = 1;
	result = 0;
	if (is_valid_case(base) == 0 || is_valid_case(base) == 1 || \
										is_overlap(base) == 0)
		return (0);
	while (*str != '\0' && (*str == ' ' || *str == '\t' || *str == '\n' || \
				*str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	while (*str != '\0' && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			n_power_of_base *= -1;
		str++;
	}
	while (*str != '\0' && find_base_index(base, *str) != 0)
	{
		str++;
	}
	str--;
	result = calculate_result(str, base, n_power_of_base);
	return (result);
}

int	main()
{
	printf("%d\n", ft_atoi_base("   --+-++-7","0123456789ABCDEF"));
	return 0;
}
