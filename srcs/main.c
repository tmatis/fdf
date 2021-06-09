/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:07:28 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/09 14:19:49 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

int	load_file(char *file)
{
	char	*find;
	int		map_file;

	find = ft_strrchr(file, '.');
	if (!find || ft_strcmp(find, ".fdf"))
	{
		ft_puterror("fdf", "load_file", "not a .fdf");
		exit(1);
	}
	map_file = open(file, O_RDONLY);
	if (map_file < 0)
	{
		ft_puterror("fdf", "load_file", strerror(errno));
		exit(1);
	}
	return (map_file);
}

int	main(int argc, char **argv)
{
	int		map_file;

	(void)argv;
	if (argc == 2)
	{
		map_file = load_file(argv[1]);
		close(map_file);
	}
	else
	{
		ft_puterror("fdf", "main", "usage is ./fdf path/to/map.fdf");
		return (2);
	}
}