/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 21:13:10 by sohan             #+#    #+#             */
/*   Updated: 2021/04/13 05:29:01 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool	is_seperator(char *charset, char str)
{
	if (*charset == '\0')
		return (false);
	while (*charset)
	{
		if (str == *charset)
			return (true);
		charset++;
	}
	return (false);
}

long long int	count_word(char *str, char *charset)
{
	long long int	word_count;
	
	word_count = 0;
	while(*str)
	{
		while (!is_seperator(charset, *str))
			str++;
		if (!is_seperator(charset, *(str - 1)))
			word_count++;
		str++;
	}
	return (word_count);
}

long long int	count_word_len(char *str, char *charset)
{
	long long int word_len;

	word_len = 0;
	while (!is_seperator(charset, *str))
	{
		str++;
		word_len++;
	}
	return (word_len);
}

char	*put_words(char **strs, char *str, char *charset, long long int i)
{
	long long int j;

	j = 0;
	while (!is_seperator(charset, *str))
	{
		strs[i][j] = *str;
		j++;
		str++;
	}
	strs[i][j] = '\0';
	while (is_seperator(charset, *str))
		str++;
	return (str);
}

char	**ft_split(char *str, char *charset)
{
	char **strs;
	long long int i;
	long long int num_word;
	long long int word_len;

	strs = NULL;
	i = 0;
	while (is_seperator(charset, *str))
		str++;	
	num_word = count_word(str, charset);
	word_len = 0;
	strs = (char **)malloc((num_word + 1) * sizeof(char *));
	if (strs == 0)
		return (0);
	while (true)
	{
		word_len = count_word_len(str, charset);
		strs[i] = (char *)malloc(word_len * sizeof(char) + 1);
		if (strs[i] == 0 || str == 0)
		   return (0);
		str = put_words(strs, str, charset, i);		
		i++;
	}
	strs[i] = NULL;
	return (strs);
}

int	main()
{
	int i = 0;
	char **strs = ft_split("", "");
	//while (strs[i])
	//{
		printf("%s\n", strs[i]);
		//i++;
	//}
	return 0;
}
