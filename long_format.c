/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 11:28:13 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/13 19:15:59 by mgautier         ###   ########.fr       */
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

char	*adjust_time(const time_t *timestamp)
{
	char	*start;
	char	*time_string;
	int		index;
	time_t	time_of_day;
	time_t	diff;

	time_string = ctime(timestamp);
	time_of_day = time(NULL);
	index = 0;
	while (time_string[index] != ' ')
		index++;
	index++;
	start = time_string + index;
	diff = time_of_day - *timestamp;
	while (time_string[index] != ':')
		index++;
	if (diff > 6 * 30 * 24 * 60 * 60 || diff < 0)
		ft_strncpy(time_string + index - 2, time_string + index + 6, 5);
	time_string[index + 3] = '\0';
	return (start);
}

void	long_format_usual(struct s_file *file, char *link_path)
{
	char	*fmt;
	t_bool	has_device_nb;
	char	mode_field[MODE_ARRAY_SIZE + 1];

	has_device_nb = is_block_or_char_file(file);
	fill_mode_field(mode_field, file->file_infos.st_mode);
	fmt = mode_field[0] == 'l' ?
		"%s  %*d %-*s %-*s %*.*d%-*.*s%*lld %s %s -> %s\n" :
		"%s  %*d %-*s %-*s %*.*d%-*.*s%*lld %s %s\n";
	ft_printf(fmt,
			mode_field,
			file->fields->hard_link,
			file->file_infos.st_nlink,
			file->fields->user,
			file->user->pw_name,
			file->fields->group,
			file->group->gr_name,
			file->fields->device_major,
			has_device_nb ? 1 : 0,
			major(file->file_infos.st_rdev),
			file->fields->device_sep,
			has_device_nb ? 1 : 0,
			",",
			file->fields->device_minor,
			has_device_nb ?
			minor(file->file_infos.st_rdev) : file->file_infos.st_size,
			adjust_time(&file->file_infos.st_mtime),
			file->dir_entry,
			link_path);
}

void	long_format_no_user_name(struct s_file *file, char *link_path)
{
	char	*fmt;
	t_bool	has_device_nb;
	char	mode_field[MODE_ARRAY_SIZE + 1];

	has_device_nb = is_block_or_char_file(file);
	fill_mode_field(mode_field, file->file_infos.st_mode);
	fmt = mode_field[0] == 'l' ?
		"%s  %*d %-*d %-*s %*.*d%-*.*s%*lld %s %s -> %s\n" :
		"%s  %*d %-*d %-*s %*.*d%-*.*s%*lld %s %s\n";
	ft_printf(fmt,
			mode_field,
			file->fields->hard_link,
			file->file_infos.st_nlink,
			file->fields->user,
			file->file_infos.st_uid,
			file->fields->group,
			file->group->gr_name,
			file->fields->device_major,
			has_device_nb ? 1 : 0,
			major(file->file_infos.st_rdev),
			file->fields->device_sep,
			has_device_nb ? 1 : 0,
			",",
			file->fields->device_minor,
			has_device_nb ?
			minor(file->file_infos.st_rdev) : file->file_infos.st_size,
			adjust_time(&file->file_infos.st_mtime),
			file->dir_entry,
			link_path);
}

void	long_format_no_group_name(struct s_file *file, char *link_path)
{
	char	*fmt;
	t_bool	has_device_nb;
	char	mode_field[MODE_ARRAY_SIZE + 1];

	has_device_nb = is_block_or_char_file(file);
	fill_mode_field(mode_field, file->file_infos.st_mode);
	fmt = mode_field[0] == 'l' ?
		"%s  %*d %-*s %-*d %*.*d%-*.*s%*lld %s %s -> %s\n" :
		"%s  %*d %-*s %-*d %*.*d%-*.*s%*lld %s %s\n";
	ft_printf(fmt,
			mode_field,
			file->fields->hard_link,
			file->file_infos.st_nlink,
			file->fields->user,
			file->user->pw_name,
			file->fields->group,
			file->file_infos.st_gid,
			file->fields->device_major,
			has_device_nb ? 1 : 0,
			major(file->file_infos.st_rdev),
			file->fields->device_sep,
			has_device_nb ? 1 : 0,
			",",
			file->fields->device_minor,
			has_device_nb ?
			minor(file->file_infos.st_rdev) : file->file_infos.st_size,
			adjust_time(&file->file_infos.st_mtime),
			file->dir_entry,
			link_path);
}

void	long_format_neither(struct s_file *file, char *link_path)
{
	char	*fmt;
	t_bool	has_device_nb;
	char	mode_field[MODE_ARRAY_SIZE + 1];

	has_device_nb = is_block_or_char_file(file);
	fill_mode_field(mode_field, file->file_infos.st_mode);
	fmt = mode_field[0] == 'l' ?
		"%s  %*d %-*d %-*d %*.*d%-*.*s%*lld %s %s -> %s\n" :
		"%s  %*d %-*d %-*d %*.*d%-*.*s%*lld %s %s\n";
	ft_printf(fmt,
			mode_field,
			file->fields->hard_link,
			file->file_infos.st_nlink,
			file->file_infos.st_uid,
			file->user->pw_name,
			file->fields->group,
			file->file_infos.st_gid,
			file->fields->device_major,
			has_device_nb ? 1 : 0,
			major(file->file_infos.st_rdev),
			file->fields->device_sep,
			has_device_nb ? 1 : 0,
			",",
			file->fields->device_minor,
			has_device_nb ?
			minor(file->file_infos.st_rdev) : file->file_infos.st_size,
			adjust_time(&file->file_infos.st_mtime),
			file->dir_entry,
			link_path);
}
