/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:01:40 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/14 04:39:01 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/includes/ft_printf.h"

int				main(void)
{
	int		ret;

	ret = 42;
	ret = ft_printf("%s %p %d %bonjour\n", "bonjour", ret, ret);
	return (0);
}
