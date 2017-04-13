/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 16:02:53 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/13 18:16:34 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mode_and_perms_interface.h"
#include "file_defs.h"
#include "parameters_defs.h"
#include "libft.h"
#include "path_tools_interface.h"
#include "long_format.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/syslimits.h>
#include <dirent.h>
#include <time.h>

static void	pop_long_format(struct s_file *file, char *link_path,
		t_ls_param *param)
{
	int	ret_read_link;

	file->user = getpwuid(file->file_infos.st_uid);
	file->group = getgrgid(file->file_infos.st_gid);
	if (is_link(file))
	{
		set_file_path(param, file->path_len, file->dir_entry);
		ret_read_link = readlink(param->parent_path, link_path, PATH_MAX);
		if (ret_read_link != -1)
			link_path[ret_read_link] = '\0';
		restore_path(param, file->path_len);
	}
	else
		link_path[0] = '\0';
}

static void	long_format(struct s_file *file)
{
	char	link_path[PATH_MAX];

	pop_long_format(file, link_path, file->params);
	if (file->user != NULL && file->group != NULL)
		long_format_usual(file, link_path);
	else if (file->group != NULL)
		long_format_no_user_name(file, link_path);
	else if (file->user != NULL)
		long_format_no_group_name(file, link_path);
	else
		long_format_neither(file, link_path);
	link_path[0] = '\0';
}

void		print_name_stat(void *entry)
{
	ft_putendl(((struct s_file*)entry)->dir_entry);
}

void		print_long_format(void *entry)
{
	struct s_file	*file;

	file = entry;
	long_format(file);
}
