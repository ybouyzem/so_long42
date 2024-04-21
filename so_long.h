/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 02:21:11 by ybouyzem          #+#    #+#             */
/*   Updated: 2024/04/21 17:12:25 by ybouyzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <mlx.h>

typedef struct s_point {
    int x;
    int y;
} t_point;

typedef struct s_icons {
    void    *player_img;
    void    *exit_img;
    void    *collective_img;
    void    *wall_img;
    void    *road_img;
} t_icons;

void	ft_error();
int     ft_strlen(char *str);
void	ft_strcpy(char *dst, char *src);
void	ft_strcat(char *s1, char *s2);
char	*ft_strdup(char	*str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_content(char *path);

void    path_parssing(char *path);
void	map_parssing(char *path);

void    ft_freestrs(char **str);
char	**ft_split(char  *s, char c);
int	    count_words(const char *s, char charset);
int	    ft_check_newline(char *str, int c);
int     ft_count_newline(char *str);
void	ft_get_player_position(t_point *c,  char **map);
void    floodfill(char **map, int x, int y, int linelength);
int     ft_strslen(char **str);
void	check_boundaries(char **map);

void printstrs(char  **map);
