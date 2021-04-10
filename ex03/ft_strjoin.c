/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 03:28:28 by sohan             #+#    #+#             */
/*   Updated: 2021/04/08 22:35:54 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

int	find_len(char **strs, int size)
{
	int i;
	int len_joined;

	i = 0;
	len_joined = 0;
	while (i < size - 1)
	{
		len_joined += ft_strlen(*strs);
		i++;
		strs++;
	}
	len_joined += ft_strlen(*strs);
	return (len_joined);
}

void	append_str(char *origin, char *str)
{
	int index;
	int i;
	
	index = ft_strlen(str);
	i = 0;
	while (i < index)
	{	
		origin[i] = str[i];
		i++;
	}
	origin[i] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str_joined;
	int	len_joined;
	int	i;
	
	i = 0;
	len_joined = find_len(strs, size);
	len_joined += (ft_strlen(sep) * (size - 1));
	str_joined = (char *)malloc(len_joined * sizeof(char) + 1);
	if (str_joined == 0)
		return (0);
	else if (size == 0)
		return (str_joined);
	while (i < size - 1)
	{
		append_str(str_joined, *strs);
		str_joined += ft_strlen(*strs);
		append_str(str_joined, sep);
		str_joined += ft_strlen(sep);
		strs++;
		i++;
	}
	append_str(str_joined, *strs);
	str_joined -= len_joined - ft_strlen(*strs);
	return (str_joined);
}

int	main()
{
	char *arrs[7] = {"abc","s","efghi","jk","lmno","pqrstu","xyz"};
	char *sep = "::";
	int size = 0;

	printf("%s\n", ft_strjoin(size, arrs, sep));
	return 0;
}
