/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:12:04 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/03 18:42:44 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_defs.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/dir.h>

void	*get_dir_entry(DIR *dir, char *parent_path, int path_len)
{
	(void)parent_path;
	(void)path_len;
	return (readdir(dir));
}

void	*get_stat_dir(DIR *dir, char *parent_path, int path_len)
{
	struct s_file	*file;
	struct dirent	*dir_entry;

	dir_entry = readdir(dir);
	if (dir_entry == NULL)
		return (NULL);
	file = ft_memalloc(sizeof(struct s_file));
	file->dir_entry = dir_entry;
	parent_path[path_len] = '/';
	path_len++;
	ft_strcpy(parent_path + path_len, file->dir_entry->d_name);
	lstat(parent_path, &file->file_infos);
	path_len--;
	ft_strclr(parent_path + path_len);
	return (file);
}
