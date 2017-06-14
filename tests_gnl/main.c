/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:39:51 by rlecart           #+#    #+#             */
/*   Updated: 2017/04/05 18:00:40 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/tmp/kboucaud/get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	*line;

	line = NULL;
	ret = 0;
	fd = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((ret = get_next_line(fd, &line)) == 1)
		{
			ft_putstr(line);
			ft_putstr("\n");
			ft_strdel(&line);
		}
	}
	close(fd);
	sleep(300);
	return (0);
}
