/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 10:55:27 by olyuboch          #+#    #+#             */
/*   Updated: 2017/09/28 10:56:28 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_history.h"

void	ft_history_error(t_proc **proc, char *er)
{
	int	old2;

	old2 = 0;
	if ((*proc)->dup[2] != 2)
	{
		old2 = dup(2);
		dup2((*proc)->dup[2], 2);
	}
	ft_putstr_fd("wtf?: ", 2);
	ft_putstr_fd(er, 2);
	// ft_putendl_fd((*proc)->argv[0], 2);
	if (old2)
	{
		dup2(old2, 2);
		// close((*proc)->dup[2]);
	}
}
