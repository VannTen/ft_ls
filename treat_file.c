/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 16:02:53 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/03 17:13:35 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_defs.h"
#include "libft.h"
#include <dirent.h>

void	do_something_with_it(void *entry, void *list_dir)
{
	struct dirent	*file;
	char			*dir_name;

	file = entry;
	ft_putendl(file->d_name);
	if (file->d_type == DT_DIR &&
			(ft_strcmp(".", file->d_name) != 0 &&
			ft_strcmp("..", file->d_name) != 0))
	{
		dir_name = ft_strdup(file->d_name);
		f_fifo_add(list_dir, dir_name);
	}
}

void	do_something_with_it_2(void *entry, void *list_dir)
{
	struct s_file	*file;
	char			*dir_name;

	file = entry;
	ft_putendl(file->dir_entry->d_name);
	if (file->dir_entry->d_type == DT_DIR &&
			(ft_strcmp(".", file->dir_entry->d_name) != 0 &&
			ft_strcmp("..", file->dir_entry->d_name) != 0))
	{
		dir_name = ft_strdup(file->dir_entry->d_name);
		f_fifo_add(list_dir, dir_name);
	}
}
