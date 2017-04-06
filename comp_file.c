/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 16:03:15 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/06 14:44:46 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "file_defs.h"
#include <sys/types.h>
#include <sys/dir.h>
#include <dirent.h>

int		comp_alpha(void *entry_1, void *entry_2)
{
	struct s_file *file_1;
	struct s_file *file_2;

	file_1 = entry_1;
	file_2 = entry_2;
	return (ft_strcmp(file_1->dir_entry->d_name, file_2->dir_entry->d_name));
}

int		comp_time(void *entry_1, void *entry_2)
{
	struct s_file *file_1;
	struct s_file *file_2;

	file_1 = entry_1;
	file_2 = entry_2;
	if (file_1->file_infos.st_mtime > file_2->file_infos.st_mtime)
		return (-1);
	else if (file_1->file_infos.st_mtime < file_2->file_infos.st_mtime)
		return (1);
	else if (ft_strcmp(
				file_1->dir_entry->d_name, file_2->dir_entry->d_name) > 0)
		return (1);
	else
		return (-1);
}
