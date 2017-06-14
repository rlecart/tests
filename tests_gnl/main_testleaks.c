/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_testleaks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:51:53 by rlecart           #+#    #+#             */
/*   Updated: 2017/04/04 13:36:34 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../../abc/get_next_line.h"

int  main(void)
{
	char  *line = NULL;
	int   fd = open("~/42FileChecker/srcs/gnl/gnl10.txt", O_RDONLY);
	get_next_line(fd, &line);
	close(fd);
	sleep(15);
	return (0);
}
