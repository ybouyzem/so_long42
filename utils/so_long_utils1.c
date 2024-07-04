/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 05:29:42 by ybouyzem          #+#    #+#             */
/*   Updated: 2024/07/03 00:38:58 by ybouyzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strlen(char *str)
{
	int	i;
	
	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dst, char *src)
{
	int	srclen;
	int	i;

	if (!dst || !src)
		return ;
	i = 0;
	srclen = ft_strlen(src);
	while (i < srclen)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

void	ft_strcat(char *s1, char *s2)
{
	int	s1len;
	int	i;

	if (!s1 || !s2)
		return ;
	i = 0;
	s1len = ft_strlen(s1);
	while (s2[i])
	{
		s1[s1len] = s2[i];
		i++;
		s1len++;
	}
	s1[s1len] = '\0';
}

char	*ft_strdup(char	*str)
{
	int	l;
	int	i;
	char	*result;

	l = ft_strlen(str);
	result = (char *)malloc(l + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	len;
	char	*result;
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	ft_strcpy(result, s1);
	ft_strcat(result, s2);
	free(s1);
	return (result);
}