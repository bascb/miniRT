/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:49:57 by smagalha          #+#    #+#             */
/*   Updated: 2023/11/25 18:22:07 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_ft(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

int	ft_limpa_stash(char *buff)
{
	int	i;
	int	j;
	int	is_nline;

	i = 0;
	j = 0;
	is_nline = 0;
	while (buff[i])
	{
		if (is_nline)
			buff[j++] = buff[i];
		if (buff[i] == '\n')
			is_nline = 1;
		buff[i++] = '\0';
	}
	return (is_nline);
}

char	*ft_strjoin_ft(char *str1, char *str2)
{
	int		i;
	char	*newstr;

	i = 0;
	newstr = malloc(ft_strlen_ft(str1) + ft_strlen_ft(str2) + 1);
	if (!newstr)
		return (NULL);
	while (str1 && str1[i])
	{
		newstr[i] = str1[i];
		i++;
	}
	free(str1);
	while (*str2)
	{
		newstr[i++] = *str2;
		if (*str2++ == '\n')
			break ;
	}
	newstr[i] = '\0';
	return (newstr);
}
