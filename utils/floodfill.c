/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:39:15 by ybouyzem          #+#    #+#             */
/*   Updated: 2024/07/07 11:05:14 by ybouyzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_get_player_position(t_point *c, char **map)
{
	int	x;
	int	y;

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

void	floodfill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'F' )
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'F';
		return ;
	}
	map[y][x] = 'F';
	floodfill(map, x - 1, y);
	floodfill(map, x + 1, y);
	floodfill(map, x, y - 1);
	floodfill(map, x, y + 1);
}

void	check_boundaries(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != 'F' && map[y][x] != '1' && map[y][x] != '0')
				(ft_freestrs(map), ft_error());
			x++;
		}
		y++;
	}
}
