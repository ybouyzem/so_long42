/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:04:14 by ybouyzem          #+#    #+#             */
/*   Updated: 2024/06/29 12:12:30 by ybouyzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void terminate_game(mlx_t *mlx_ptr)
{
    mlx_terminate(mlx_ptr);
    exit(1);
}

void init_txts(t_mlx game)
{
    game.road_txt = mlx_load_png("images/back.png");
    if (!game.road_txt)
        terminate_game(game.mlx_ptr);
    game.collective_txt = mlx_load_png("images/burger.png");
    if (!game.collective_txt)
    {
        mlx_delete_texture(game.collective_txt);
        terminate_game(game.mlx_ptr);
    }
    game.exit_txt = mlx_load_png("images/exit.png");
    if (!game.exit_txt)
    {
        mlx_delete_texture(game.collective_txt);
        mlx_delete_texture(game.exit_txt);
        terminate_game(game.mlx_ptr);
    }
    game.player_txt = mlx_load_png("images/player.png");
    if (!game.exit_txt)
    {
        mlx_delete_texture(game.collective_txt);
        mlx_delete_texture(game.exit_txt);
        mlx_delete_texture(game.player_txt);
        terminate_game(game.mlx_ptr);
    }
    game.wall_txt = mlx_load_png("images/player.png");
    if (!game.wall_txt)
    {
        mlx_delete_texture(game.wall_txt);
        mlx_delete_texture(game.collective_txt);
        mlx_delete_texture(game.exit_txt);
        mlx_delete_texture(game.player_txt);
        terminate_game(game.mlx_ptr);
    }
}

void resize_imgs(t_mlx game)
{
    if (!mlx_resize_image(game.road_img, grade, grade))    
        terminate_game(game.mlx_ptr);
    if (!mlx_resize_image(game.collective_img, grade, grade))    
        terminate_game(game.mlx_ptr);
    if (!mlx_resize_image(game.exit_img, grade, grade))    
        terminate_game(game.mlx_ptr);
    if (!mlx_resize_image(game.player_img, grade, grade))    
        terminate_game(game.mlx_ptr);
    if (!mlx_resize_image(game.wall_img, grade, grade))    
        terminate_game(game.mlx_ptr);   
}

void init_imgs(t_mlx game)
{
    init_txts(game);
    game.road_img = mlx_texture_to_image(game.mlx_ptr, game.road_txt);
    game.collective_img = mlx_texture_to_image(game.mlx_ptr, game.collective_txt);
    game.exit_img = mlx_texture_to_image(game.mlx_ptr, game.exit_txt);
    game.player_img = mlx_texture_to_image(game.mlx_ptr, game.player_txt);
    game.wall_img = mlx_texture_to_image(game.mlx_ptr, game.wall_txt);
    resize_imgs(game);
}