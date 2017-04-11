/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_repertory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 10:38:56 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/11 17:34:42 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "file_interface.h"
#include "list_dir_interface.h"
#include "long_format.h"
#include "parameters_defs.h"
#include <sys/types.h>
#include <sys/dir.h>
#include <sys/errno.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <limits.h>

static t_btree	*get_sorted_dir_entries(DIR *directory, t_ls_param *param,
		char *parent_path, int path_len)
{
	void	*current_entry;
	char	*file_name;
	t_btree	*dir_entries;

	dir_entries = btree_create(param->ft_comp);
	if (dir_entries != NULL)
	{
		file_name = get_file_name(directory, param->options[ALL_FILES]);
		current_entry = param->ft_get_file(file_name, parent_path, path_len);
		while (current_entry != NULL)
		{
			if (btree_add(dir_entries, current_entry) == current_entry)
				break ;
			file_name = get_file_name(directory, param->options[ALL_FILES]);
			current_entry =
				param->ft_get_file(file_name, parent_path, path_len);
		}
	}
	return (dir_entries);
}

static t_fifo	*list_one_dir(DIR *directory, struct s_ls_param *param,
		char *parent_path, int path_len)
{
	t_btree	*sorted_entries;
	t_fifo	*sub_dirs_list;


	sub_dirs_list = NULL;
	sorted_entries = get_sorted_dir_entries(directory, param,
			parent_path, path_len);
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

static void		list_sub_dirs(char *parent_path, int path_len,
		t_fifo *subdirs_list, struct s_ls_param *param)
{
	char *dir_name;
	char *dir_path;

	parent_path[path_len] = '/';
	path_len += 1;
	dir_name = f_fifo_take(subdirs_list);
	while (dir_name != NULL)
	{
		dir_path = ft_strcpy(parent_path + path_len, dir_name);
		list_dir(parent_path, path_len + ft_strlen(dir_name), param);
		ft_strclr(parent_path + path_len);
		ft_strdel(&dir_name);
		dir_name = f_fifo_take(subdirs_list);
	}
	path_len -= 1;
	parent_path[path_len] = '\0';
}

void			list_dir(char *name, int path_len, struct s_ls_param *param)
{
	t_fifo	*sub_dirs_list;
	DIR		*subdir;

	errno = 0;
	ft_putchar('\n');
	ft_putendl(name);
	subdir = opendir(name);
	if (subdir != NULL)
	{
		sub_dirs_list = list_one_dir(subdir, param, name, path_len);
		closedir(subdir);
		list_sub_dirs(name, path_len, sub_dirs_list, param);
		f_fifo_destroy(&sub_dirs_list, param->ft_destroy_file);
	}
	else
		perror("test");
}
