/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:39:51 by rlecart           #+#    #+#             */
/*   Updated: 2017/04/04 14:56:33 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../get_next_line/get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	int		fd3;
	int		ret;
	char	*line;

	line = NULL;
	ret = 0;
	fd = 0;
	fd2 = 0;
	fd3 = 0;
	argv[0] += 0;
	if (argc == 1)
	{
		system("openssl rand -out tmp_gnl/sandbox/large_file.txt -base64 $((50 * 1000 * 3/4)) 2> /dev/null");
		fd = open("tmp_gnl/sandbox/large_file.txt", O_RDONLY);
		fd2 = open("tmp_gnl/sandbox/large_file.txt.mine", O_CREAT | O_RDWR | O_TRUNC, 0755);
		while (get_next_line(fd, &line) == 1)
		{
			printf("%s\n", line);
			write(fd2, line, strlen(line));
			write(fd2, "\n", 1);
		}
	}
	close(fd);
	close(fd2);
	free(line);
	system("diff tmp_gnl/sandbox/large_file.txt tmp_gnl/sandbox/large_file.txt.mine > tmp_gnl/sandbox/large_file.diff");
	fd3 = open("tmp_gnl/sandbox/large_file.diff", O_RDONLY);
	ret = read(fd3, NULL, 10);
	close(fd3);
	if (ret == 0)
		printf("\n\n########\n\nAUCUNE DIFFERENCE\n\n########\n\n");
	else
		printf("\n\n########\n\nUNE OU PLUSIEURS DIFFERENCES\n\n########\n\n");
	return (0);
}
