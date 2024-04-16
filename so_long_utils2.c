/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 05:47:06 by ybouyzem          #+#    #+#             */
/*   Updated: 2024/04/16 16:36:05 by ybouyzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error()
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	ft_check_newline(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == (char) c)
			return (1);
		i++;
	}
	return (0);
}

void    ft_freestrs(char **str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_count_newline(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			nb++;
		i++;
	}
	return (nb);
}