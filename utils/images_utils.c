/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:04:14 by ybouyzem          #+#    #+#             */
/*   Updated: 2024/07/07 10:48:34 by ybouyzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_txts(t_mlx *game)
{
	game->road_txt = mlx_load_png("images/back.png");
	if (!game->road_txt)
		(write(1, "Error\nroad_txt failed\n", 22), exit(1));
	game->collective_txt = mlx_load_png("images/burger.png");
	if (!game->collective_txt)
		(write(1, "Error\ncollective_txt failed\n", 28),exit(1));
	game->exit_txt = mlx_load_png("images/exit2.png");
	if (!game->exit_txt)
		(write(1, "Error\nexit_txt failed\n", 22),exit(1));
	game->player_txt = mlx_load_png("images/player.png");
	if (!game->player_txt)
		(write(1, "Error\nplayer_txt failed\n", 24),exit(1));
	game->wall_txt = mlx_load_png("images/wall.png");
	if (!game->wall_txt)
		(write(1, "Error\nwall_txt failed\n", 22),exit(1));
}

void	resize_imgs(t_mlx *game)
{
	if (!mlx_resize_image(game->road_img, GRADE, GRADE))
		(write(1, "Error\nresizing img failed\n", 26), exit(1));
	if (!mlx_resize_image(game->collective_img, GRADE, GRADE))
		(write(1, "Error\nresizing img failed\n", 26), exit(1));
	if (!mlx_resize_image(game->exit_img, GRADE, GRADE))
		(write(1, "Error\nresizing img failed\n", 26), exit(1));
	if (!mlx_resize_image(game->player_img, GRADE, GRADE))
		(write(1, "Error\nresizing img failed\n", 26), exit(1));
	if (!mlx_resize_image(game->wall_img, GRADE, GRADE))
		(write(1, "Error\nresizing img failed\n", 26), exit(1));
}

void	init_imgs(t_mlx *game)
{
	init_txts(game);
	game->road_img = mlx_texture_to_image(game->mlx_ptr, game->road_txt);
	game->collective_img
		= mlx_texture_to_image(game->mlx_ptr, game->collective_txt);
	game->exit_img = mlx_texture_to_image(game->mlx_ptr, game->exit_txt);
	game->player_img = mlx_texture_to_image(game->mlx_ptr, game->player_txt);
	game->wall_img = mlx_texture_to_image(game->mlx_ptr, game->wall_txt);
	resize_imgs(game);
}
