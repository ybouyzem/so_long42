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


static void	show_window(t_mlx *game, char **argv)
{
	t_map map;

	map.map = ft_split(ft_get_content(argv[1]), '\n');
	if (!map.map)
	{
		(ft_freestrs(map.map), write(1, "map failed!\n", 12));
		exit(1);
	}
	game->map = &map;
	ft_get_player_position(&game->map->player_pos, game->map->map);
	game->width_win = ft_strlen(game->map->map[1]) * width;
	game->height_win = ft_strslen(game->map->map) * height;
	count_collectives(game);
	game->mlx_ptr = mlx_init(game->width_win, game->height_win,"so_long", false);
	if (!game->mlx_ptr)
		free_game(game, "mlx failed\n");
	init_imgs(game);
	render_map(game);
	mlx_key_hook(game->mlx_ptr, key_press, game);
	mlx_loop(game->mlx_ptr);
}

static void parssing(int argc, char **argv, t_map *map)
{
	if (argc != 2)
		ft_error(argv[1]);
	path_parssing(argv[1]);
	map_parssing(argv[1], map);
}

int	main(int argc, char **argv)
{
	t_mlx game;
	
	parssing(argc, argv, game.map);
	show_window(&game, argv);
	ft_freestrs(game.map->map);
	delete_textures(&game);
	delete_images(&game);
	mlx_terminate(game.mlx_ptr);
	// atexit(leaks);
}

