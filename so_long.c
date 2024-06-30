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


void	key_press(mlx_key_data_t keydata, void *param)
{
	t_mlx *game;
	int	x;
	int	y;

	game = param;
	y = game->map->player_pos.y;
	x = game->map->player_pos.x;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx_ptr);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		if (check_next_step(game , y - 1, x))
		{
			printf("next pos checked\n");
			update_map(game, y - 1, x);
		}
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		if (check_next_step(game , y + 1, x))
			update_map(game, y + 1, x);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		if (check_next_step(game , y, x - 1))
			update_map(game, y, x - 1);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		if (check_next_step(game , y, x + 1))
			update_map(game, y, x + 1);
}

void	show_window(t_mlx *game)
{
	
	init_imgs(game);
	render_map(game);
	mlx_key_hook(game->mlx_ptr, key_press, game);
	mlx_loop(game->mlx_ptr);
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
	{
		write(1, "map failed!", 11);
		exit(1);
	}
	ft_get_player_position(&map.player_pos, map.map);
	game.map = &map;
	// printf("colls: %d\n", map.nbr_collective);
	game.width_win = ft_strlen(map.map[1]) * width;
	game.height_win = ft_strslen(map.map) * height;
	count_collectives(&game);
	game.map->exit = 0;
	game.mlx_ptr = mlx_init(game.width_win, game.height_win,"so_long", false);
	if (!game.mlx_ptr)
		return (0);
	show_window(&game);
	//leaks();
}

