/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 00:25:58 by ybouyzem          #+#    #+#             */
/*   Updated: 2024/07/10 09:47:07 by ybouyzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	show_window(t_mlx *game, char **argv)
{
	t_map	map;
	char	*content;

	content = ft_get_content(argv[1]);
	map.map = ft_split(content, '\n');
	free(content);
	if (!map.map)
	{
		(ft_freestrs(map.map), write(1, "Error\nmap failed!\n", 18));
		exit(1);
	}
	game->map = &map;
	ft_get_player_position(&game->map->player_pos, game->map->map);
	game->width_win = ft_strlen(game->map->map[1]) * WIDTH;
	game->height_win = ft_strslen(game->map->map) * HEIGHT;
	count_collectives(game);
	if (ft_strlen(game->map->map[0]) > 50 || ft_strslen(game->map->map) > 50)
		(write(2, "Error\ninvalid sizes\n", 21), exit(1));
	game->mlx_ptr
		= mlx_init(game->width_win, game->height_win, "so_long", false);
	if (!game->mlx_ptr)
		free_game(game, "Error\nmlx failed\n");
	(init_imgs(game), render_map(game));
	mlx_key_hook(game->mlx_ptr, key_press, game);
	mlx_loop(game->mlx_ptr);
}

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_mlx	*game;
	int		x;
	int		y;

	game = param;
	y = game->map->player_pos.y;
	x = game->map->player_pos.x;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		game_over(game, "you escaped the game\n");
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		if (check_next_step(game, y - 1, x))
			update_map(game, y - 1, x);
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		if (check_next_step(game, y + 1, x))
			update_map(game, y + 1, x);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		if (check_next_step(game, y, x - 1))
			update_map(game, y, x - 1);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		if (check_next_step(game, y, x + 1))
			update_map(game, y, x + 1);
}
