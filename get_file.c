/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:12:04 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/03 17:37:23 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_defs.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/dir.h>

void	*get_dir_entry(DIR *dir)
{
	return (readdir(dir));
}

void	*get_stat_dir(DIR *dir, char *parent_path, int path_len)
{
	struct s_file	*file;

	file = ft_memalloc(sizeof(struct s_file));
	file->dir_entry = readdir(dir);
	parent_path[path_len] = '/';
	ft_strcpy(parent_path + path_len, file->dir_entry->d_name);
	stat(parent_path, &file->file_infos);
	ft_strclr(parent_path + path_len);
	return (file);
}
