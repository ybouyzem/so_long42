/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:51:33 by ybouyzem          #+#    #+#             */
/*   Updated: 2024/07/04 04:18:46 by ybouyzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    path_parssing(char *path)
{
	int i;

	i = 0;
	if (ft_strlen(path) < 4)
		ft_error();
	while (path[i] && i < (int)ft_strlen(path) - 4)
		i++;
	if (path[i++] != '.' || path[i++] != 'b' \
	|| path[i++] != 'e' || path[i++] != 'r')
		ft_error();
}

void ft_check_strlen(char **map)
{
	int	i;
	
	i = 0;
	while (map[i+1])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i + 1]))
			(ft_freestrs(map), ft_error());
		i++;
	}
}

int	check_chars(char c)
{
	if (c != 'E' && c != 'P' && c != 'C' && c != '0' && c != '1')
		return (0);
	return (1);
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
			if ((i == 0 || map[i + 1] == 0 || j == 0 || map[i][j + 1] == '\0' 
			|| !check_chars(map[i][j])) && map[i][j] != '1')
					(ft_freestrs(map), ft_error());
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
		(ft_freestrs(map),ft_error());
}

void	map_parssing(char *path)
{
	char	*content;
	char	**map;
	t_point c;
	
	content = ft_get_content(path);
	map = ft_split(content, '\n');
	if (count_words(content, '\n') < 3)
		(ft_freestrs(map), ft_error());
	if (count_words(content, '\n') - 1 != ft_count_newline(content))
		(ft_freestrs(map), ft_error());
	ft_check_strlen(map);
	ft_check(0, 0, 0, map);
	ft_get_player_position(&c,map);

	// floodfill(tmp, c.x, c.y, ft_strlen(map[0]));
	// check_boundaries(tmp);
	(free(content), ft_freestrs(map));
}