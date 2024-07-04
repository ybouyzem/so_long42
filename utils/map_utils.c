/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 23:09:56 by ybouyzem          #+#    #+#             */
/*   Updated: 2024/07/04 02:59:38 by ybouyzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void count_collectives(t_mlx *game)
{
    int i;
    int j;
    int nb_c;

    nb_c = 0;
    i = 0;
    while (game->map->map[i])
    {
        j = 0;
        while (game->map->map[i][j])
        {
            if (game->map->map[i][j] == 'C')
                nb_c++;
            j++;
        }
        i++;
    }
    game->map->c = nb_c;
    game->map->nbr_collective = nb_c;
}

void render_image(t_mlx *game, mlx_image_t *image, int x, int y)
{
    if (mlx_image_to_window(game->mlx_ptr, image, x * grade, y * grade) < 0)
        free_game(game, "images rendering failed\n");
}

void render_map(t_mlx *game)
{
    int x;
    int y;
    
    y = 0;
    while (game->map->map[y])
    {
        x = 0;
        while (game->map->map[y][x])
        {
            render_image(game,game->road_img, x, y);
            if (game->map->map[y][x] == '1')
                render_image(game, game->wall_img, x, y);
            else if (game->map->map[y][x] == 'P')
                render_image(game, game->player_img, x, y);
            else if (game->map->map[y][x] == 'C')
                render_image(game, game->collective_img, x, y);
            else if (game->map->map[y][x] == 'E')
                render_image(game, game->exit_img, x, y);
            x++;
        }
        y++;
    }
}

int check_next_step(t_mlx *game, int y, int x)
{

    if (game->map->map[y][x] == '0')
        return (1);
    else if (game->map->map[y][x] == 'C')
    {
        game->map->c--;
        return (1);
    }
    else if (game->map->map[y][x] == 'E' && game->map->c == 0)//free all
        game_over(game, "you ended the game successfuly!");
    return (0);
}

void    update_map(t_mlx *game, int new_y, int new_x)
{
    int x;
    int y;

    x = game->map->player_pos.x;
    y = game->map->player_pos.y;
    game->map->map[y][x] = '0';
    game->map->map[new_y][new_x] = 'P';
    game->map->player_pos.y = new_y;
    game->map->player_pos.x = new_x;
    render_image(game, game->player_img, new_x, new_y);
    render_image(game, game->road_img, x, y);
}