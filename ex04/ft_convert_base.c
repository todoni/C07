/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 00:36:12 by sohan             #+#    #+#             */
/*   Updated: 2021/04/09 01:09:09 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

void	put_nbr_by_base(char *base, int nbr, int n)
{
	if (nbr == 0)
		return ;
	put_nbr_by_base(base, nbr / n, n);
	if (nbr < 0)
		write(1, &base[-(nbr % n)], 1);
	else
		write(1, &base[nbr % n], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int n;


	n = is_valid_case(base);
	if (n == 0 || n == 1 || is_overlap(base) == 0)
	{
		return ;
	}
	else if (nbr == 0)
	{
		write(1, &base[nbr % n], 1);
		return ;
	}
	if (nbr < 0)
		write(1, "-", 1);
	put_nbr_by_base(base, nbr, n);
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

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*nbr_copy;
	int	len_nbr;
	int	nbr_to_int;
	int	i;
	
	i = 0;
	len_nbr = ft_strlen(nbr);
	nbr_copy = (char *)malloc(len_nbr * sizeof(char) + 1);
	if (nbr_copy == 0)
		return (0);
	while (*nbr)
	{
		nbr_copy[i] = nbr[i];
		i++;
	}
	nbr_to_int = ft_atoi_base(nbr_copy, base_from);
	ft_putnbr_base(nbr_to_int, base_to);

}
