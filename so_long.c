/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 02:21:05 by ybouyzem          #+#    #+#             */
/*   Updated: 2024/04/15 20:18:34 by ybouyzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "so_long.h"

void leaks(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_error(argv[1]); 
	path_parssing(argv[1]);
	map_parssing(argv[1]);
	//leaks();
}