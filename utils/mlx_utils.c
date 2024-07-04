/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 00:25:58 by ybouyzem          #+#    #+#             */
/*   Updated: 2024/07/04 03:53:09 by ybouyzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_mlx *game;
	int	x;
	int	y;

	game = param;
	y = game->map->player_pos.y;
	x = game->map->player_pos.x;

	if (keydata.key == MLX_KEY_ESCAPE)
		game_over(game, "you escaped the game\n");
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		if (check_next_step(game , y - 1, x))
			update_map(game, y - 1, x);
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

