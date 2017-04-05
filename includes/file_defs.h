/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_defs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:12:25 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/05 17:59:09 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_DEFS_H
# define FILE_DEFS_H
# include "file_interface.h"
# include <sys/stat.h>

struct s_file
{
	struct stat		file_infos;
	struct dirent	*dir_entry;
	char			*parent_path;
	int				path_len;
};

#endif
