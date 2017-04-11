/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 11:28:13 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/11 17:24:27 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long_format.h"
#include "file_defs.h"
#include "libft.h"
#include "time.h"
#include <sys/types.h>

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

void	long_format_usual(struct s_file *file,
		struct s_long_form_info *long_form)
{
	char	*fmt;
	int		precision_dev;

	if (is_block_or_char_file(file))
		precision_dev = 1;
	else
		precision_dev = 0;
	fmt = long_form->file_mode[0] == 'l' ?
			"%s%4d %s %s %.0d%.*s%.0lld %s %s -> %s\n" :
			"%s%4d %s %s %.0d%.*s%.0lld %s %s\n",
	ft_printf(fmt,
			long_form->file_mode,
			file->file_infos.st_nlink,
			long_form->user->pw_name,
			long_form->group->gr_name,
			major(file->file_infos.st_rdev),
			precision_dev,
			",",
			is_block_or_char_file(file) ? minor(file->file_infos.st_rdev) :
			file->file_infos.st_size,
			adjust_time(ctime(&file->file_infos.st_mtime)),
			file->dir_entry,
			long_form->link_path);
}

void	long_format_no_user_name(struct s_file *file,
		struct s_long_form_info *long_form)
{
	char *fmt;

	fmt = long_form->file_mode[0] == 'l' ?
			"%s%4d %d %s %8lld %s %s -> %s\n" : "%s%4d %d %s %8lld %s %s\n";
	ft_printf(fmt,
			long_form->file_mode,
			file->file_infos.st_nlink,
			file->file_infos.st_uid,
			long_form->group->gr_name,
			file->file_infos.st_size,
			adjust_time(ctime(&file->file_infos.st_mtime)),
			file->dir_entry,
			long_form->link_path);
}

void	long_format_no_group_name(struct s_file *file,
		struct s_long_form_info *long_form)
{
	char *fmt;

	fmt = long_form->file_mode[0] == 'l' ?
			"%s%4d %s %d %8lld %s %s -> %s\n" : "%s%4d %s %d %8lld %s %s\n";
	ft_printf(fmt,
			long_form->file_mode,
			file->file_infos.st_nlink,
			long_form->user->pw_name,
			file->file_infos.st_gid,
			file->file_infos.st_size,
			adjust_time(ctime(&file->file_infos.st_mtime)),
			file->dir_entry,
			long_form->link_path);
}

void	long_format_neither(struct s_file *file,
		struct s_long_form_info *long_form)
{
	char *fmt;

	fmt = long_form->file_mode[0] == 'l' ?
			"%s%4d %d %d %8lld %s %s -> %s\n" : "%s%4d %d %d %8lld %s %s\n";
	ft_printf(fmt,
			long_form->file_mode,
			file->file_infos.st_nlink,
			file->file_infos.st_uid,
			file->file_infos.st_gid,
			file->file_infos.st_size,
			adjust_time(ctime(&file->file_infos.st_mtime)),
			file->dir_entry,
			long_form->link_path);
}
