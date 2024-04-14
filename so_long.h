/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 02:21:11 by ybouyzem          #+#    #+#             */
/*   Updated: 2024/04/14 06:08:06 by ybouyzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

void	ft_error();
int	ft_strlen(char *str);
void	ft_strcpy(char *dst, char *src);
void	ft_strcat(char *s1, char *s2);
char	*ft_strdup(char	*str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_content(char *path);

void    path_parssing(char *path);
void	map_parssing(char *path);

void    ft_freestrs(char **str);
char	**ft_split(char  *s, char c);
int	count_words(const char *s, char charset);
