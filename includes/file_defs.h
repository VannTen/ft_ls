/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_defs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:12:25 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/13 11:40:29 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_DEFS_H
# define FILE_DEFS_H
# include "file_interface.h"
# include "long_format.h"
# include <sys/stat.h>
# include <grp.h>
# include <pwd.h>
# include <uuid/uuid.h>
# define HIDDEN_MARK_CHAR '.'

struct s_file
{
	struct stat		file_infos;
	const char		*dir_entry;
	char			*parent_path;
	char			*link_path;
	int				path_len;
	struct passwd	*user;
	struct group	*group;
	t_fields		*fields;
};

#endif
