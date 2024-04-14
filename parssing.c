/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:51:33 by ybouyzem          #+#    #+#             */
/*   Updated: 2024/04/15 00:36:33 by ybouyzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void ft_check_strlen(char **map)
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

void	ft_check(int check_e, int check_p, int check_c, char **map)
{
	static int			i;
	int			j;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((i == 0 || map[i + 1] == 0 || j == 0 || 
				map[i][j + 1] == '\0') && map[i][j] != '1')
					ft_error();
			else if (map[i][j] == 'P')
				check_p++;
			else if (map[i][j] == 'E')
				check_e++;
			else if (map[i][j] == 'C')
				check_c++;
			j++;
		}
		i++;
	}
	if (check_e <= 0 || check_e > 1 || check_p <= 0 
	|| check_p > 1 || check_c <= 0)
		ft_error();
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
	ft_check(0, 0, 0, map);
	(free(content), ft_freestrs(map));
}