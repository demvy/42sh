/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_wait.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:05:35 by vdemeshk          #+#    #+#             */
/*   Updated: 2017/10/01 15:05:39 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec_private.h"

int			ft_exec_wait(t_proc **proc)
{
	int			status;
	t_proc		*tmp;
	int			result;

	result = 0;
	tmp = (*proc);
	ft_exec_proc_up(proc);
	while ((*proc))
	{
		if ((*proc)->pid)
		{
			waitpid((*proc)->pid, &status, WUNTRACED);
			(*proc)->status = status;
			if (status != 0)
				result = status;
		}
		(*proc) = (*proc)->next;
	}
	(*proc) = tmp;
	return (result);
}
