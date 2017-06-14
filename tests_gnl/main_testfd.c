/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:39:51 by rlecart           #+#    #+#             */
/*   Updated: 2017/02/08 20:59:48 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	int		fd3;
	int		ret;
	int		ret2;
	int		ret3;
	char	*line;

	line = NULL;
	ret = 1;
	ret2 = 2;
	ret3 = 3;
	fd = 0;
	fd2 = 0;
	fd3 = 0;
	if (argc == 4)
	{
		fd = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		fd3 = open(argv[3], O_RDONLY);
		while (ret || ret2 || ret3)
		{
			if ((ret = get_next_line(fd, &line)) > 0)
				printf("## %s\n", line);
			else
				ret = 0;
			if ((ret2 = get_next_line(fd2, &line)) > 0)
				printf("## %s\n", line);
			else
				ret2 = 0;
			if ((ret3 = get_next_line(fd3, &line)) > 0)
				printf("## %s\n", line);
			else
				ret3 = 0;
		}
	}
	close(fd2);
	close(fd3);
	free(line);
	return (0);
}
