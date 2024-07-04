/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 01:09:32 by ybouyzem          #+#    #+#             */
/*   Updated: 2024/07/04 04:27:07 by ybouyzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    ft_freestrs(char **str)
{
	int i;
	if (!str)
    {
        printf("warah khawya \n");
		return ;
    }
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void    delete_textures(t_mlx *game)
{
    if (game->road_txt)
        mlx_delete_texture(game->road_txt);
    if (game->collective_txt)
        mlx_delete_texture(game->collective_txt);
    if (game->player_txt)
        mlx_delete_texture(game->player_txt);
    if (game->exit_txt)
        mlx_delete_texture(game->exit_txt);
    if (game->wall_txt)
        mlx_delete_texture(game->wall_txt);
}

void    delete_images(t_mlx *game)
{
    if (game->road_img)
        mlx_delete_image(game->mlx_ptr, game->road_img);
    if (game->collective_img)
        mlx_delete_image(game->mlx_ptr, game->collective_img);
    if (game->player_img)
        mlx_delete_image(game->mlx_ptr, game->player_img);
    if (game->exit_img)
        mlx_delete_image(game->mlx_ptr, game->exit_img);
    if (game->wall_img)
        mlx_delete_image(game->mlx_ptr, game->wall_img);
}

void    free_game(t_mlx *game, char *message)
{
    write(1, message, ft_strlen(message));
    ft_freestrs(game->map->map);
    delete_textures(game);
    delete_images(game);
    mlx_terminate(game->mlx_ptr);
    exit(1);
}

void game_over(t_mlx *game, char *message)
{
    write(1, message, ft_strlen(message));
    mlx_close_window(game->mlx_ptr);
}