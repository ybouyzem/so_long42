/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:38:15 by ybouyzem          #+#    #+#             */
/*   Updated: 2024/06/07 17:20:37 by ybouyzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void ft_convert_images(void *mlx, t_icons *t)
// {
//     int l;

//     l = 70;
//     (*t).wall_img = mlx_xpm_file_to_image(mlx, "wall1.xpm", &l, &l);
//     (*t).road_img =  mlx_xpm_file_to_image(mlx, "back.xpm", &l, &l);
//     (*t).player_img = mlx_xpm_file_to_image(mlx, "player.xpm", &l, &l);
//     (*t).collective_img = mlx_xpm_file_to_image(mlx, "burger.xpm", &l, &l);
//     (*t).exit_img = mlx_xpm_file_to_image(mlx, "exit-close.xpm", &l, &l);
// }

// void ft_render_map(void *mlx, void *win, char **map, t_icons game)
// {
//     t_point p;
//     int     i;
//     int     j;

//     i = 0;
//     ft_get_player_position(&p, map);
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			if (map[i][j] == '0')
// 				mlx_put_image_to_window(mlx, win, game.road_img , j*70, i*70);
// 			if (map[i][j] == '1')
// 				mlx_put_image_to_window(mlx, win, game.wall_img , j*70, i*70);
// 			else if (map[i][j] == 'P')
// 				mlx_put_image_to_window(mlx, win, game.player_img , j*70, i*70);
// 			else if (map[i][j] == 'C')
// 				mlx_put_image_to_window(mlx, win, game.collective_img , j*70, i*70);
// 			else if (map[i][j] == 'E')
// 				mlx_put_image_to_window(mlx, win, game.exit_img , j*70, i*70);
// 			j++;
// 		}
// 		i++;
// 	}
// 	mlx_loop(mlx);
// }