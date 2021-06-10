/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 22:57:43 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/10 16:21:08 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot	*line_array(char *line, double y)
{
	char	**split;
	int		split_size;
	t_dot	*array;

	split = ft_split(line, ' ');
	split_size = 0;
	while (split[split_size])
		split_size++;
	array = ft_calloc(split_size + 1, sizeof(t_dot));
	if (!array)
	{
		ft_puterror("fdf", "line_array", strerror(errno));
		return (NULL);
	}
	array[split_size].end = 1;
	while (split_size--)
	{
		array[split_size].x = split_size;
		array[split_size].y = y;
		array[split_size].z = ft_atoi(split[split_size]);
		if (array[split_size].z)
			array[split_size].color = 0xfc0f03;
		else
			array[split_size].color = 0xFFFFFFF;
	}
	free_table(split);
	return (array);
}

t_list	*parse_map(int map_fd)
{
	int		gnl_ret;
	char	*line;
	t_list	*map;
	double	y;

	y = 0;
	map = NULL;
	line = NULL;
	gnl_ret = get_next_line(map_fd, &line);
	while (gnl_ret > 0)
	{
		ft_lstadd_back(&map, ft_lstnew(line_array(line, y)));
		free(line);
		gnl_ret = get_next_line(map_fd, &line);
		y++;
	}
	if (gnl_ret < 0)
	{
		ft_lstclear(&map, free);
		return (NULL);
	}
	return (map);
}