/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_repertory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 10:38:56 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/06 14:46:12 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "file_interface.h"
#include "list_dir_interface.h"
#include <sys/types.h>
#include <sys/dir.h>
#include <sys/errno.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <limits.h>

t_btree	*get_sorted_dir_entries(DIR *directory, t_compare comp_ft,
		char *parent_path, int path_len)
{
	void			*current_entry;
	t_btree			*dir_entries;
	void			*(*get_entry)(DIR*, char*, int);

	get_entry = &get_stat_dir;
	dir_entries = btree_create(comp_ft);
	if (dir_entries != NULL)
	{
		current_entry = get_entry(directory, parent_path, path_len);
		while (current_entry != NULL)
		{
			if (btree_add(dir_entries, current_entry) == current_entry)
				break ;
			current_entry = get_entry(directory, parent_path, path_len);
		}
	}
	return (dir_entries);
}

t_fifo	*list_one_dir(DIR *directory, t_compare comp_ft,
		char *parent_path, int path_len)
{
	t_btree	*sorted_entries;
	t_fifo	*sub_dirs_list;

	sorted_entries = get_sorted_dir_entries(directory, comp_ft,
			parent_path, path_len);
	sub_dirs_list = f_fifo_create();
	if (sub_dirs_list != NULL && sorted_entries != NULL)
	{
		btree_iter_two_param_in_order(sorted_entries, &do_something_with_it_2,
				sub_dirs_list);
	}
	btree_destroy(&sorted_entries, &no_destroy);
	return (sub_dirs_list);
}

void	list_sub_dirs(char *parent_path, int path_len, t_fifo *subdirs_list,
		t_compare comp_ft)
{
	char *dir_name;
	char *dir_path;

	parent_path[path_len] = '/';
	path_len += 1;
	dir_name = f_fifo_take(subdirs_list);
	while (dir_name != NULL)
	{
		dir_path = ft_strcpy(parent_path + path_len, dir_name);
		list_dir(parent_path, path_len + ft_strlen(dir_name), comp_ft);
		ft_strclr(parent_path + path_len);
		ft_strdel(&dir_name);
		dir_name = f_fifo_take(subdirs_list);
	}
	path_len -= 1;
	parent_path[path_len] = '\0';
}

void	list_dir(char *name, int path_len, t_compare comp_ft)
{
	t_fifo	*sub_dirs_list;
	DIR		*subdir;

	ft_putendl("");
	ft_putstr(name);
	ft_putstr(":\n");
	errno = 0;
	subdir = opendir(name);
	if (subdir != NULL)
	{
		sub_dirs_list = list_one_dir(subdir, comp_ft, name, path_len);
		closedir(subdir);
		//	list_sub_dirs(name, path_len, sub_dirs_list, comp_ft);
		f_fifo_destroy(&sub_dirs_list, &no_destroy);
	}
	else
		perror(NULL);
}
