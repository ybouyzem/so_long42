/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 02:21:11 by ybouyzem          #+#    #+#             */
/*   Updated: 2024/07/04 04:10:48 by ybouyzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "include/MLX42/MLX42.h"
#define grade 50
#define width 50
#define height 50

typedef struct s_point {
    int x;
    int y;
} t_point;

typedef struct s_map {
    char    **map;
    int     c;
    int     nbr_collective;
    int    exit;
    t_point player_pos;
} t_map;

typedef struct s_mlx {
    t_map *map;
    mlx_t    *mlx_ptr;
    int     width_win;
    int     height_win;
    mlx_texture_t    *player_txt;
    mlx_texture_t    *exit_txt;
    mlx_texture_t    *collective_txt;
    mlx_texture_t    *wall_txt;
    mlx_texture_t    *road_txt;
    mlx_image_t    *player_img;
    mlx_image_t    *exit_img;
    mlx_image_t    *collective_img;
    mlx_image_t    *wall_img;
    mlx_image_t    *road_img; 
} t_mlx;

void	ft_error();
int     ft_strlen(char *str);
void	ft_strcpy(char *dst, char *src);
void	ft_strcat(char *s1, char *s2);
char	*ft_strdup(char	*str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_content(char *path);

void    path_parssing(char *path);
void	map_parssing(char *path, t_map *map);
void	key_press(mlx_key_data_t keydata, void *param);

void    ft_freestrs(char **str);
char	**ft_split(char  *s, char c);
int	    count_words(const char *s, char charset);
int	    ft_check_newline(char *str, int c);
int     ft_count_newline(char *str);
void	ft_get_player_position(t_point *c,  char **map);
void    floodfill(char **map, int x, int y, int linelength);
int     ft_strslen(char **str);
void	check_boundaries(char **map);

void init_txts(t_mlx *game);
void resize_imgs(t_mlx *game);
void init_imgs(t_mlx *game);
void render_map(t_mlx *game);
void    update_map(t_mlx *game,  int new_y, int new_x);
int check_next_step(t_mlx *game, int y, int x);
void count_collectives(t_mlx *game);
void    delete_textures(t_mlx *game);
void    delete_images(t_mlx *game);
void    free_game(t_mlx *game, char *message);
void    game_over(t_mlx *game, char *message);

void printstrs(char  **map);
