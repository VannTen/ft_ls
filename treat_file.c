/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 16:02:53 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/08 18:53:14 by mgautier         ###   ########.fr       */
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

/*
** That function allow to skip first word in the return of ctime, which is
** day of the week, and skip the end (seconds and year)
*/

char	*adjust_time(char *std_time)
{
	char	*start;
	int		index;

	index = 0;
	while (std_time[index] != ' ')
		index++;
	index++;
	start = std_time + index;
	while (std_time[index] != ':')
		index++;
	std_time[index + 3] = '\0';
	return (start);
}

static void	pop_long_format(struct s_file *file,
		struct s_long_form_info *long_form)
{
	fill_mode_field(long_form->file_mode, file->file_infos.st_mode);
	long_form->user = getpwuid(file->file_infos.st_uid);
	long_form->group = getgrgid(file->file_infos.st_gid);
	if (long_form->file_mode[0] == 'l')
	{
		set_file_path(
				file->parent_path, file->path_len, file->dir_entry->d_name);
		long_form->link_path[readlink(
				file->parent_path, long_form->link_path, PATH_MAX)] = '\0';
		restore_path(file->parent_path, file->path_len);
		long_form->format_string = "%s%4d %s %s %8lld %s %s -> %s\n";
	}
	else
	{
		long_form->link_path[0] = '\0';
		long_form->format_string = "%s%4d %s %s %8lld %s %s\n";
	}
	if (long_form->user == NULL)
		long_form->format_string[7] = 'd';
	if (long_form->user == NULL)
		long_form->format_string[10] = 'd';
}

static void	long_format(struct s_file *file)
{
	struct s_long_form_info long_form;

	pop_long_format(file, &long_form);
	ft_printf(long_form.format_string,
			long_form.file_mode,
			file->file_infos.st_nlink,
			long_form.user->pw_name,
			long_form.group->gr_name,
			file->file_infos.st_size,
			adjust_time(ctime(&file->file_infos.st_mtime)),
			file->dir_entry->d_name,
			long_form.link_path);
}

void	print_name(void *entry)
{
	struct dirent	*file;

	file = entry;
	ft_putendl(file->d_name);
}

void	print_name_stat(void *entry)
{
	print_name(((struct s_file*)entry)->dir_entry);
}

void	print_long_format(void *entry)
{
	struct s_file	*file;

	file = entry;
	long_format(file);
}
