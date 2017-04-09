/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 18:13:18 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/09 11:53:58 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LONG_FORMAT_H
# define LONG_FORMAT_H
# include "file_interface.h"
# include <grp.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <sys/syslimits.h>
# define MODE_ARRAY_SIZE 10

enum	e_type_of_string
{
	USUAL,
	NO_USER_NAME,
	NO_GROUP_NAME,
	NEITHER
};

struct s_long_form_info
{
	char			link_path[PATH_MAX];
	char			*format_string;
	char			file_mode[MODE_ARRAY_SIZE + 1];
	struct passwd	*user;
	struct group	*group;
};

void	long_format_usual(struct s_file *file,
		struct s_long_form_info *long_form);
void	long_format_no_user_name(struct s_file *file,
		struct s_long_form_info *long_form);
void	long_format_no_group_name(struct s_file *file,
		struct s_long_form_info *long_form);
void	long_format_neither(struct s_file *file,
		struct s_long_form_info *long_form);

#endif
