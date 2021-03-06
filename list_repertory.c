/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_repertory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 10:38:56 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/13 18:23:10 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "file_defs.h"
#include "list_dir_interface.h"
#include "long_format.h"
#include "parameters_defs.h"
#include "path_tools_interface.h"
#include <sys/types.h>
#include <sys/dir.h>
#include <sys/errno.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <limits.h>

static t_btree	*get_sorted_dir_entries(DIR *directory, t_ls_param *param,
		int path_len)
{
	struct s_file	*current_entry;
	char			*file_name;
	t_btree			*dir_entries;

	dir_entries = btree_create(param->ft_comp);
	if (dir_entries != NULL)
	{
		file_name = get_file_name(directory, param->options[ALL_FILES]);
		current_entry = param->ft_get_file(file_name, param, path_len);
		while (current_entry != NULL)
		{
			current_entry->fields =
				check_fields(current_entry, param->temp_fields);
			if (btree_add(dir_entries, current_entry) == current_entry)
				break ;
			file_name = get_file_name(directory, param->options[ALL_FILES]);
			current_entry =
				param->ft_get_file(file_name, param, path_len);
		}
	}
	return (dir_entries);
}

static t_fifo	*list_one_dir(DIR *directory, struct s_ls_param *param,
		int path_len)
{
	t_btree		*sorted_entries;
	t_fifo		*sub_dirs_list;
	t_fields	fields;

	sub_dirs_list = NULL;
	init_fields(&fields);
	param->temp_fields = &fields;
	sorted_entries = get_sorted_dir_entries(directory, param, path_len);
	if (sorted_entries != NULL)
	{
		if (param->options[LONG_FORMAT])
			ft_printf("total %d\n", btree_sum(sorted_entries, &get_block_nbr));
		param->ft_loop_through(sorted_entries, param->ft_print_entry);
		if (param->options[RECURSIVE])
		{
			sub_dirs_list = f_fifo_create();
			param->ft_loop_through_2(
					sorted_entries, param->ft_subdir, sub_dirs_list);
		}
		btree_destroy(&sorted_entries, param->ft_destroy_file);
	}
	return (sub_dirs_list);
}

static void		list_sub_dirs(size_t path_len,
		t_fifo *subdirs_list, struct s_ls_param *param)
{
	char *dir_name;
	char *dir_path;

	if (path_len + 1 > param->path_len_max)
		resize_parent_path(param);
	param->parent_path[path_len] = '/';
	path_len += 1;
	dir_name = f_fifo_take(subdirs_list);
	while (dir_name != NULL)
	{
		dir_path = ft_strcpy(param->parent_path + path_len, dir_name);
		errno = 0;
		if (list_dir(path_len + ft_strlen(dir_name), param) != 0)
		{
			ft_dprintf(STDERR_FILENO, "%s: %s: %s\n",
					param->prog_name, dir_name, strerror(errno));
			param->has_error = TRUE;
		}
		ft_strclr(param->parent_path + path_len);
		ft_strdel(&dir_name);
		dir_name = f_fifo_take(subdirs_list);
	}
	path_len -= 1;
	param->parent_path[path_len] = '\0';
}

int				list_dir(int path_len, struct s_ls_param *param)
{
	t_fifo	*sub_dirs_list;
	DIR		*subdir;

	if (!param->is_first)
		ft_putchar('\n');
	else
		param->is_first = FALSE;
	if (param->put_dir_name_before)
		ft_printf("%s:\n", param->parent_path);
	else
		param->put_dir_name_before = TRUE;
	errno = 0;
	subdir = opendir(param->parent_path);
	if (subdir != NULL)
	{
		sub_dirs_list = list_one_dir(subdir, param, path_len);
		closedir(subdir);
		list_sub_dirs(path_len, sub_dirs_list, param);
		f_fifo_destroy(&sub_dirs_list, param->ft_destroy_file);
		return (0);
	}
	else
		return (1);
}
