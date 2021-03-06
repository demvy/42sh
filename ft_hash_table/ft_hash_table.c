/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 20:05:02 by olyuboch          #+#    #+#             */
/*   Updated: 2017/07/18 20:05:04 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash_table.h"
#include "ft_free.h"
#include "ft_env.h"

static void	init_table(t_hash **table, char **path)
{
	DIR				*dir;
	struct dirent	*entry;
	char			*filename;
	char			*tmp;
	int				i;

	i = 0;
	while (path[i])
	{
		dir = opendir(path[i]);
		while (dir && (entry = readdir(dir)))
		{
			tmp = ft_strjoin(path[i], "/");
			filename = ft_strjoin(tmp, entry->d_name);
			free(tmp);
			if (!access(filename, X_OK) && \
				(entry->d_type == DT_REG || entry->d_type == DT_LNK))
				ft_hash_set(table, entry->d_name, filename);
			free(filename);
		}
		if (dir)
			closedir(dir);
		i++;
	}
}

t_hash		**ft_hash_table(char **env)
{
	t_hash	**table;
	char	**path;

	if (!(path = ft_strsplit(ft_env_get(env, "PATH"), ':')))
		return (NULL);
	table = ft_memalloc(sizeof(t_hash *) * HASH_SIZE + 1);
	init_table(table, path);
	ft_free_mas(path);
	return (table);
}
