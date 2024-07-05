/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 05:47:06 by ybouyzem          #+#    #+#             */
/*   Updated: 2024/07/05 08:39:37 by ybouyzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(void)
{
	write(1, "Error parssing\n", 15);
	exit(EXIT_FAILURE);
}

char	*ft_get_content(char *path)
{
	char	*content;
	char	c;
	int		len;
	int		fd;

	len = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		(perror("can't open this file "), exit(EXIT_FAILURE));
	while (read(fd, &c, 1))
		len++;
	close(fd);
	content = (char *)malloc((len + 1) * sizeof(char));
	if (!content)
	{
		write(2, "fail of map allocation!", 24);
		exit(1);
	}
	fd = open(path, O_RDONLY);
	read(fd, content, len);
	content[len] = '\0';
	close(fd);
	return (content);
}

int	ft_strslen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check_newline(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == (char) c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_newline(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			nb++;
		i++;
	}
	return (nb);
}
