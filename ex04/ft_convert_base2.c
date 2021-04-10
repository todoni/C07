/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 00:41:13 by sohan             #+#    #+#             */
/*   Updated: 2021/04/09 00:42:25 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
