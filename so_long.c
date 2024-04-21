/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 02:21:05 by ybouyzem          #+#    #+#             */
/*   Updated: 2024/04/21 17:17:01 by ybouyzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "so_long.h"

void leaks(void)
{
	system("leaks so_long");
}

void printstrs(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;	
		}
		printf("\n");
		i++;
	}
}

void	show_window(void *mlx, char **map)
{
	void	*win;
	int		i;
	int		j;
	t_icons game;
	t_point p;

	game.player_img = "";
	i = 0;
	win = mlx_new_window(mlx, ft_strlen(map[0]) * 50, ft_strslen(map) * 50, "so_long");
	if (!win)
		return ;
	ft_get_player_position(&p, map);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
			{
				mlx_put_image_to_window(mlx, win, game.player_img, p.x, p.y);
			}
			j++;	
		}
		i++;
	}
	mlx_loop(mlx);
	
}

int	main(int argc, char **argv)
{
	void	*mlx;
	char	**map;
	
	if (argc != 2)
		ft_error(argv[1]); 
	path_parssing(argv[1]);
	map_parssing(argv[1]);
	map = ft_split(argv[1], '\n');
	if (!map)
		return (0);
	mlx = mlx_init();
	if (!mlx)
		return (0);
	show_window(mlx, map);
	//leaks();
}