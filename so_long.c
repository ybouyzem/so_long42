/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 02:21:05 by ybouyzem          #+#    #+#             */
/*   Updated: 2024/07/07 10:42:39 by ybouyzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leaks(void)
{
	system("leaks so_long");
}

void	ft_putnbr(int nb)
{
	long	n;
	char	c;

	n = nb;
	if (n >= 0 && n <= 9)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	
}

void	printstrs(char **map)
{
	int	i;
	int	j;

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

static void	parssing(int argc, char **argv)
{
	if (argc != 2)
		ft_error();
	path_parssing(argv[1]);
	map_parssing(argv[1]);
}

int	main(int argc, char **argv)
{
	t_mlx	game;

	parssing(argc, argv);
	show_window(&game, argv);

	ft_freestrs(game.map->map);
	delete_textures(&game);
	delete_images(&game);
	mlx_terminate(game.mlx_ptr);
	atexit(leaks);
}
