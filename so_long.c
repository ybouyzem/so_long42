/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 02:21:05 by ybouyzem          #+#    #+#             */
/*   Updated: 2024/05/02 17:39:53 by ybouyzem         ###   ########.fr       */
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
	int l;

	l = 70;
	game.wall_img = mlx_xpm_file_to_image(mlx, "wall1.xpm", &l, &l);
	i = 0;
	win = mlx_new_window(mlx, ft_strlen(map[0]) * 70, ft_strslen(map) * 70, "so_long");
	if (!win)
		return ;
		
	ft_get_player_position(&p, map);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
				mlx_put_image_to_window(mlx, win, mlx_xpm_file_to_image(mlx, "back.xpm", &l, &l) , j*70, i*70);
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx, win, game.wall_img , j*70, i*70);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(mlx, win, mlx_xpm_file_to_image(mlx, "player.xpm", &l, &l) , j*70, i*70);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(mlx, win, mlx_xpm_file_to_image(mlx, "burger.xpm", &l, &l) , j*70, i*70);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(mlx, win, mlx_xpm_file_to_image(mlx, "exit-close.xpm", &l, &l) , j*70, i*70);
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
	map = ft_split(ft_get_content(argv[1]), '\n');
	if (!map)
		return (0);
	mlx = mlx_init();
	if (!mlx)
		return (0);
	
	show_window(mlx, map);
	//leaks();
}