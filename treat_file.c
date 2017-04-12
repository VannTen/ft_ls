/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 16:02:53 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/12 17:42:18 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mode_and_perms_interface.h"
#include "file_defs.h"
#include "libft.h"
#include "path_tools_interface.h"
#include "long_format.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/syslimits.h>
#include <dirent.h>
#include <time.h>

static void	pop_long_format(struct s_file *file,
		struct s_long_form_info *long_form)
{
	fill_mode_field(long_form->file_mode, file->file_infos.st_mode);
	long_form->user = getpwuid(file->file_infos.st_uid);
	long_form->group = getgrgid(file->file_infos.st_gid);
	if (long_form->file_mode[0] == 'l')
	{
		set_file_path(
				file->parent_path, file->path_len, file->dir_entry);
		long_form->link_path[readlink(
				file->parent_path, long_form->link_path, PATH_MAX)] = '\0';
		restore_path(file->parent_path, file->path_len);
	}
	else
		long_form->link_path[0] = '\0';
}

static void	long_format(struct s_file *file)
{
	struct s_long_form_info long_form;

	pop_long_format(file, &long_form);
	if (long_form.user != NULL && long_form.group != NULL)
		long_format_usual(file, &long_form);
	else if (long_form.group != NULL)
		long_format_no_user_name(file, &long_form);
	else if (long_form.user != NULL)
		long_format_no_group_name(file, &long_form);
	else
		long_format_neither(file, &long_form);
	long_form.user = NULL;
}

void	print_name_stat(void *entry)
{
	ft_putendl(((struct s_file*)entry)->dir_entry);
}

void	print_long_format(void *entry)
{
	struct s_file	*file;

	file = entry;
	long_format(file);
}
