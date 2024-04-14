/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:51:33 by ybouyzem          #+#    #+#             */
/*   Updated: 2024/04/14 06:12:59 by ybouyzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error()
{
	write(1, "ERROR\n", 6);
	exit(EXIT_FAILURE);
}

void    path_parssing(char *path)
{
	int i;

	i = 0;
	if (ft_strlen(path) <= 4)
		ft_error();
	while (path[i] && i < (int)ft_strlen(path) - 4)
		i++;
	if (path[i++] != '.' || path[i++] != 'b' || path[i++] != 'e' || path[i++] != 'r')
		ft_error();
}

void	ft_check_strlen(char **map)
{
	int	i;

	i = 0;
	while (map[i+1])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i + 1]))
			ft_error();
		i++;	
	}
}

void	map_parssing(char *path)
{
	char	*content;
	char	**map;
	content = ft_get_content(path);
	map = ft_split(content, '\n');
	if (count_words(content, '\n') < 3)
		ft_error();
	ft_check_strlen(map);
	(free(content), ft_freestrs(map));
}