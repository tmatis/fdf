/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 22:57:43 by tmatis            #+#    #+#             */
/*   Updated: 2021/11/02 15:00:07 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	get_color(char *str)
{
	while (ft_isnum(*str))
		str++;
	if (!*str)
		return (0xFFFFFF);
	if (ft_strlen(str) >= 3 && !ft_memcmp(str, ",0x", 3))
		str += 3;
	else
		return (0xFFFFFF);
	return (ft_atoi_hex(str));
}

t_dot	*line_array(char *line, t_map *map)
{
	char	**split;
	int		split_size;
	t_dot	*array;

	split = ft_split(line, ' ');
	if (!split)
		return (NULL);
	split_size = 0;
	while (split[split_size])
		split_size++;
	array = ft_calloc(split_size + 1, sizeof(t_dot));
	if (!array)
	{
		free_table(split);
		return (NULL);
	}
	if (split_size > map->x)
		map->x = split_size;
	array[split_size].end = 1;
	while (split_size--)
	{
		array[split_size].x = split_size;
		array[split_size].y = map->y;
		array[split_size].z = ft_atoi(split[split_size]);
		array[split_size].color = get_color(split[split_size]);
	}
	free_table(split);
	return (array);
}

t_map	parse_map(int map_fd)
{
	int		gnl_ret;
	char	*line;
	t_map	map;

	map.y = 0;
	map.x = 0;
	map.data = NULL;
	line = NULL;
	gnl_ret = get_next_line(map_fd, &line);
	while (gnl_ret > 0)
	{
		t_dot *tmp = line_array(line, &map);
		if (!tmp)
		{
			ft_lstclear(&map.data, ft_safe_free);
			free(line);
			exit(127);
		}
		t_list *new =  ft_lstnew(tmp);
		if (!new)
		{
			free(tmp);
			ft_lstclear(&map.data, ft_safe_free);
			free(line);
			exit(127);
		}
		ft_lstadd_back(&map.data, new);
		free(line);
		gnl_ret = get_next_line(map_fd, &line);
		map.y++;
	}
	ft_safe_free(line);
	if (gnl_ret < 0)
	{
		ft_lstclear(&map.data, free);
		exit(1);
	}
	return (map);
}
