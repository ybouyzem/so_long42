/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 00:29:26 by ybouyzem          #+#    #+#             */
/*   Updated: 2024/07/04 23:27:39 by ybouyzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


 int	count_words(const char *s, char charset)
{
	int	i;
	int	nbr;

	if (!s)
		return (0);
	i = 0;
	nbr = 0;
	while (s[i])
	{
		while (s[i] && s[i] == charset)
			i++;
		if (s[i] != '\0')
			nbr++;
		while (s[i] && s[i] != charset)
			i++;
	}
	return (nbr);
}

static char	*ft_mystrdup( const char *s, char charset)
{
	char	*r;
	int		i;
	int		lw;

	i = 0;
	lw = 0;
	while (s[lw] && s[lw] != charset)
		lw++;
	r = (char *)malloc(lw + 1);
	if (r == NULL)
		return (NULL);
	while (i < lw)
	{
		r[i] = s[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}

static void	*ft_myfree(char **result, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

static char	**ft_allocate(int size)
{
	char	**result;

	result = (char **)malloc(sizeof(char *) * (size + 1));
	if (!result)
		return (NULL);
	return (result);
}

char	**ft_split(char *s, char c)
{
	char	**result;
	int		index;
	char	*tmp;

	if (!s)
		return (NULL);
	index = 0;
	result = ft_allocate(count_words(s, c));
	while (*s)
	{
		if (*s != '\0')
		{
			tmp = ft_mystrdup(s, c);
			if (!tmp)
				return (ft_myfree(result, index));
			else
				result[index++] = tmp;
		}
		while (*s && *s != c)
			s++;
		if (*s == '\n')
		 	s++;
	}
	result[index] = 0;
	return (result);
}