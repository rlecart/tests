/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:39:51 by rlecart           #+#    #+#             */
/*   Updated: 2017/01/31 17:24:09 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	int		fd3;
	int		ret;
	char	*line;
	char	*str;
	int		len = 50;

	line = NULL;
	str = (char*)malloc(1000 * 1000);
	*str = '\0';
	ret = 0;
	fd = 0;
	fd2 = 0;
	fd3 = 0;
	argv[0] += 0;
	if (argc == 1)
	{
		while (len--)
			strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus.");
		fd = open("tmp/sandbox/medium_file.txt", O_CREAT | O_RDWR | O_TRUNC, 0755);
		write(fd, str, strlen(str));
		close(fd);
		fd = open("tmp_gnl/sandbox/medium_file.txt", O_RDONLY);
		fd2 = open("tmp_gnl/sandbox/medium_file.txt.mine", O_CREAT | O_RDWR | O_TRUNC, 0755);
		while (get_next_line(fd, &line) == 1)
		{
			printf("%s\n", line);
			write(fd2, line, strlen(line));
		}
	}
	close(fd);
	close(fd2);
	free(line);
	system("diff tmp_gnl/sandbox/medium_file.txt tmp_gnl/sandbox/medium_file.txt.mine > tmp_gnl/sandbox/medium_file.diff");
	fd3 = open("tmp_gnl/sandbox/medium_file.diff", O_RDONLY);
	ret = read(fd3, NULL, 10);
	close(fd3);
	if (ret == 0)
		printf("\n\n########\n\nAUCUNE DIFFERENCE\n\n########\n\n");
	else
		printf("\n\n########\n\nUNE OU PLUSIEURS DIFFERENCES\n\n########\n\n");
	return (0);
}
