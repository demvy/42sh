/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:55:51 by olyuboch          #+#    #+#             */
/*   Updated: 2017/10/01 15:59:38 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	ft_parse_args(char **str, char ***env, t_his **his)
{
	if (*env[0] && *his)
		write(1, "\n", 1);
	ft_putendl(*str);
}
