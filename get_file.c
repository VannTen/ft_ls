/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:12:04 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/13 20:10:13 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_defs.h"
#include "mode_and_perms_interface.h"
#include "path_tools_interface.h"
#include "parameters_defs.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/dir.h>
#include <sys/errno.h>
#include <stdio.h>
#include <stddef.h>

char	*get_file_name(DIR *dir, t_bool take_dotfiles)
{
	struct dirent	*dir_entry;

	dir_entry = readdir(dir);
	while (!take_dotfiles &&
			(dir_entry != NULL && dir_entry->d_name[0] == HIDDEN_MARK_CHAR))
		dir_entry = readdir(dir);
	return (dir_entry == NULL ? NULL : ft_strdup(dir_entry->d_name));
}

void	*get_stat_dir(const char *file_name, t_ls_param *param, size_t path_len)
{
	struct s_file	*file;
	int				ret_stat;

	if (file_name == NULL)
		return (NULL);
	file = ft_memalloc(sizeof(struct s_file));
	if (file != NULL)
	{
		file->dir_entry = file_name;
		errno = 0;
		file->params = param;
		file->path_len = path_len;
		set_file_path(param, path_len, file_name);
		ret_stat = lstat(param->parent_path, &file->file_infos);
		restore_path(param, path_len);
		if (ret_stat == -1)
			param->ft_destroy_file((void**)&file);
	}
	return (file);
}

void	add_to_sub_dirs_list_stat(void *entry, void *list_dir)
{
	struct s_file	*file;
	char			*dir_name;

	file = entry;
	if (file_type(file->file_infos.st_mode) == 'd'
			&& (ft_strcmp(".", file->dir_entry) != 0
				&& ft_strcmp("..", file->dir_entry) != 0))
	{
		dir_name = ft_strdup(file->dir_entry);
		f_fifo_add(list_dir, dir_name);
	}
}
