/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_repertory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 10:38:56 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/31 17:41:14 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dir_entry_interface.h"
#include <sys/types.h>
#include <sys/dir.h>
#include <stddef.h>

t_btree	*get_sorted_dir_entries(DIR *directory, t_compare comp_ft)
{
	void			*current_entry;
	t_btree			*dir_entries;

	dir_entries = btree_create(comp_ft);
	if (dir_entries != NULL)
	{
		current_entry = get_dir_entry(directory);
		while (current_entry != NULL)
		{
			if (btree_add(dir_entries, current_entry) == current_entry)
				break ;
			current_entry = readdir(directory);
		}
	}
	return (dir_entries);
}

void	list_dir(DIR *directory, t_compare comp_ft)
{
	t_btree	*sorted_entries;
	t_fifo	*sub_dirs_list;
	DIR		*current_sub_dir;

	sub_dirs_list = f_fifo_create();
	sorted_entries = get_sorted_dir_entries(directory, comp_ft);
	if (sub_dirs_list != NULL && sorted_entries != NULL)
	{
		btree_iter_in_order(sorted_entries, &do_something_with_it);
		btree_destroy(&sorted_entries, &no_destroy);
		current_sub_dir = f_fifo_take(sub_dirs_list);
		while (current_sub_dir != NULL)
		{
			list_dir(current_sub_dir, comp_ft);
			current_sub_dir = f_fifo_take(sub_dirs_list);
		}
	}
	f_fifo_destroy(&sub_dirs_list, &no_destroy);
	btree_destroy(&sorted_entries, &no_destroy);
}
