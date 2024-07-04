/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:04:14 by ybouyzem          #+#    #+#             */
/*   Updated: 2024/07/04 02:55:59 by ybouyzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void init_txts(t_mlx *game)
{
    game->road_txt = mlx_load_png("images/back.png");
    if (!game->road_txt)
        free_game(game, "road_txt failed\n");
    game->collective_txt = mlx_load_png("images/burger.png");
    if (!game->collective_txt)
        free_game(game, "collective_txt failed\n");
    game->exit_txt = mlx_load_png("images/exit2.png");
    if (!game->exit_txt)
        free_game(game, "exit_txt failed\n");
    game->player_txt = mlx_load_png("images/player.png");
    if (!game->player_txt)
        free_game(game, "player_txt failed\n");
    game->wall_txt = mlx_load_png("images/wall.png");
    if (!game->wall_txt)
       free_game(game, "wall_txt failed\n");
}

void resize_imgs(t_mlx *game)
{
    if (!mlx_resize_image(game->road_img, grade, grade))    
        free_game(game, "resizing road_img failed\n");
    if (!mlx_resize_image(game->collective_img, grade, grade))    
        free_game(game, "resizing collective_img\n");
    if (!mlx_resize_image(game->exit_img, grade, grade))    
        free_game(game, "resizing exit_img\n");
    if (!mlx_resize_image(game->player_img, grade, grade))    
        free_game(game, "resizing player_img\n");
    if (!mlx_resize_image(game->wall_img, grade, grade))    
        free_game(game, "resizing wall_img\n");   
}

void init_imgs(t_mlx *game)
{
    init_txts(game);
    game->road_img = mlx_texture_to_image(game->mlx_ptr, game->road_txt);
    game->collective_img = mlx_texture_to_image(game->mlx_ptr, game->collective_txt);
    game->exit_img = mlx_texture_to_image(game->mlx_ptr, game->exit_txt);
    game->player_img = mlx_texture_to_image(game->mlx_ptr, game->player_txt);
    game->wall_img = mlx_texture_to_image(game->mlx_ptr, game->wall_txt);
    resize_imgs(game);
}