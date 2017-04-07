/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:12:04 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/07 13:40:29 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_defs.h"
#include "path_tools_interface.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/dir.h>

void	*get_dir_entry(DIR *dir, char *parent_path, int path_len,
		t_bool take_dotfiles)
{
	struct dirent	*dir_entry;
	(void)parent_path;
	(void)path_len;
	dir_entry = readdir(dir);
	while (!take_dotfiles &&
			(dir_entry != NULL && dir_entry->d_name[0] == HIDDEN_MARK_CHAR))
		dir_entry = readdir(dir);
	return (dir_entry);
}

void	*get_stat_dir(DIR *dir, char *parent_path, int path_len,
		t_bool take_dotfiles)
{
	struct s_file	*file;
	struct dirent	*dir_entry;

	dir_entry = get_dir_entry(dir, parent_path, path_len, take_dotfiles);
	if (dir_entry == NULL)
		return (NULL);
	file = ft_memalloc(sizeof(struct s_file));
	file->dir_entry = dir_entry;
	file->parent_path = parent_path;
	file->path_len = path_len;
	set_file_path(parent_path, path_len, file->dir_entry->d_name);
	lstat(parent_path, &file->file_infos);
	restore_path(parent_path, path_len);
	return (file);
}

void	add_to_sub_dirs_list(void *entry, void *list_dir)
{
	struct s_file	*file;
	char			*dir_name;

	file = entry;
	if (file->dir_entry->d_type == DT_DIR &&
			(ft_strcmp(".", file->dir_entry->d_name) != 0 &&
			 ft_strcmp("..", file->dir_entry->d_name) != 0))
	{
		dir_name = ft_strdup(file->dir_entry->d_name);
		f_fifo_add(list_dir, dir_name);
	}
}
