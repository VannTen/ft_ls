/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_defs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:12:25 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/10 11:24:39 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_DEFS_H
# define FILE_DEFS_H
# include "file_interface.h"
# include <sys/stat.h>
# define HIDDEN_MARK_CHAR '.'

struct s_file
{
	struct stat		file_infos;
	char			*dir_entry;
	char			*parent_path;
	int				path_len;
};

#endif
