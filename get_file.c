/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:12:04 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/03 13:48:06 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dir_entry_interface.h"
#include <sys/types.h>
#include <sys/dir.h>

void	*get_dir_entry(DIR *dir)
{
	return (readdir(dir));
}

void	do_something_with_it(void *entry, void *list_dir)
{
	struct dirent *file;
	char *dir_name;

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

int		comp_alpha(void *entry_1, void *entry_2)
{
	struct dirent *file_1;
	struct dirent *file_2;

	file_1 = entry_1;
	file_2 = entry_2;
	if (ft_strcmp(file_1->d_name, file_2->d_name) > 0)
		return (1);
	else
		return (-1);
}
