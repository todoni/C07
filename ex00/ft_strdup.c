/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:36:02 by sohan             #+#    #+#             */
/*   Updated: 2021/04/07 21:16:24 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

char	*ft_strdup(char *str)
{
	int len;
	char *ptr_copy;

	len = 0;
	len = ft_strlen(str);
	ptr_copy = malloc(len);
	printf("%d\n",len);
	while (*str)
	{
		*ptr_copy = *str;
		str++;
		ptr_copy++;
	}
	//*ptr_copy = '\0';
	ptr_copy -= len;
	return (ptr_copy);
}

int	main()
{
	char *str = "asdf";

	printf("%s\n", ft_strdup(str));
	printf("%s\n", strdup(str));
	return 0;
}
