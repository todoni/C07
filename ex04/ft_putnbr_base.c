/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 23:41:36 by sohan             #+#    #+#             */
/*   Updated: 2021/04/06 02:45:11 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		get_base_len(char *base)
{
	int i;

	i = 0;
	while (*base != '\0')
	{
		if (*base == '+' || *base == '-')
			return (0);
		base++;
		i++;
	}
	return (i);
}

int		is_overlap(char *base)
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

void	display_nbr_by_base(char *base, int nbr, int n)
{
	if (nbr == 0)
		return ;
	display_nbr_by_base(base, nbr / n, n);
	if (nbr < 0)
		write(1, &base[-(nbr % n)], 1);
	else
		write(1, &base[nbr % n], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int n;

	n = get_base_len(base);
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
	display_nbr_by_base(base, nbr, n);
}
