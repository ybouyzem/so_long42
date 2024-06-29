// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   so_long.c                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/04/13 02:21:05 by ybouyzem          #+#    #+#             */
// /*   Updated: 2024/06/29 10:32:44 by ybouyzem         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "so_long.h"

void leaks(void)
{
	system("leaks so_long");
}

void printstrs(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;	
		}
		printf("\n");
		i++;
	}
}

void	show_window(t_mlx game, t_map map)
{
	init_imgs(game);
	map.c = 0;
}

int	main(int argc, char **argv)
{
	t_mlx game;
	t_map map;
	
	if (argc != 2)
		ft_error(argv[1]);
	path_parssing(argv[1]);
	map_parssing(argv[1]);
	map.map = ft_split(ft_get_content(argv[1]), '\n');
	if (!map.map)
		return (0);
	// printstrs(map.map);
	game.mlx_ptr = mlx_init(70, 70,"so_long", false);
	if (!game.mlx_ptr)
		return (0);
	// show_window(game, map);
	//leaks();
}

