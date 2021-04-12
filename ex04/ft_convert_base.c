/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 00:36:12 by sohan             #+#    #+#             */
/*   Updated: 2021/04/13 03:20:53 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strdup(char *origin)
{
	char	*copy;
	int		len;
	
	len = ft_strlen(origin);
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (copy == 0)
		return (0);
	while (*origin)
	{
		*copy = *origin;
		copy++;
		origin++;
	}
	*copy = '\0';
	copy -= len;
	return (copy);
}
bool	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
			return (true);
	return (false);
}

bool	is_valid_base(char *base)
{
	char	nth_component_base;
	int		n;

	n = 0;
	if (ft_strlen(base) == 0 || ft_strlen(base) == 1 || is_space(base))
		return (false);
	while (n < base_len)
	{
		nth_component_base = base[n];
		if (base[n] == '+' || base[n] == '-' || is_space(base[n]))
			return (false);
		base += n + 1;
		while (*base)
		{
			if (nth_component_base == *base)
				return (false);
			base++;
		}
		base -= base_len;
		n++;
	}
	return (true);
}

int		find_base_index(char *base, char str)
{
	int index;

	index = 0;
	while (*base)
	{
		if (*base == str)
			return (index);
		base++;
		index++;
	}
	return (-1);
}

int	calculate_result(char *nbr, char *base, int n_power_of_base)
{
	int index;
	int result;
	int n;

	index = 0;
	result = 0;
	n = ft_strlen(base);
	while (find_base_index(base, *nbr) != -1)
	{
		index = find_base_index(base, *str);
		result += index * n_power_of_base;
		n_power_of_base *= n;
		nbr--;
	}
	return (result);
}

int	ft_atoi_base(char *nbr, char *base)
{
	int	result;
	int	n_power_of_base;

	n_power_of_base = 1;
	result = 0;
	while (is_space(*nbr))
		nbr++;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			n_power_of_base *= -1;
		nbr++;
	}
	while (*nbr != '\0' && find_base_index(base, *nbr) != -1)
		nbr++;
	nbr--;
	result = calculate_result(nbr, base, n_power_of_base);
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*new_nbr;
	int		nbr_to_int;
	int		nbr_save;
	int		new_nbr_len;
	int		nbr_len;

	nbr_to_int = 0;
	nbr_save = 0;
	new_nbr_len = 0;
	nbr_len = ft_strlen(base_from);
	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return (0);
	nbr_to_int = ft_atoi_base(nbr, base_from);
	nbr_save = nbr_to_int;
	while (nbr_to_int != 0)
	{
		nbr_to_int /= nbr_len;
		new_nbr_len++;
	}
	if (nbr_save < 0)
		new_nbr = (char *)malloc(new_nbr_len * sizeof(char) + 2);
	else

	if (new_nbr == 0)
		return (0);
	new_nbr[new_nbr_len + 1] = '\0';
	new_nbr[new_nbr_len] = base_to[nbr_save % 
}
