/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:39:15 by ybouyzem          #+#    #+#             */
/*   Updated: 2024/07/03 00:38:31 by ybouyzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_get_player_position(t_point *c, char **map)
{
	int x;
	int y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				c->x = x;
				c->y = y;
			}
			x++;	
		}
		y++;
	}
}

void    floodfill(char **map, int x, int y,  int linelength)
{
	if (x < 0 || x >=  ft_strslen(map) || y < 0 || y >= linelength || map[x][y] == '1' || map[x][y] == 'F' || map[x][y] == 'E')
		return ;
	map[x][y] = 'F';
	floodfill(map, x - 1, y, 13);
	floodfill(map, x + 1, y, 13);
	floodfill(map, x, y - 1, 13);
	floodfill(map, x, y + 1, 13);
}

void	check_boundaries(char **map)
{
	int	i;
	int	j;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1' || map[i][j] == 'F' || map[i][j] == 'E' || map[i][j] == '0')
				j++;
			else	
				(ft_freestrs(map), ft_error());
		}
		i++;
	}
}

