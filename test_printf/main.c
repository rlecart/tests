/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:01:40 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/15 14:26:56 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/includes/ft_printf.h"
#include <limits.h>

int				main(void)
{
	int		ret;

//	ret = ft_printf("%D\n", LONG_MAX);
//	ret = ft_printf("%D\n", LONG_MIN);
	ret = printf("% Zoooo");
	printf("\n%d\n", ret);
	ret = ft_printf("% Zoooo");
	printf("\n%d\n", ret);
	return (0);
}
