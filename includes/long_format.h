/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 18:13:18 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/08 18:30:39 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LONG_FORMAT_H
# define LONG_FORMAT_H
# include <grp.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <sys/syslimits.h>

struct s_long_form_info
{
	char			link_path[PATH_MAX];
	char			*format_string;
	char			file_mode[MODE_ARRAY_SIZE + 1];
	struct passwd	*user;
	struct group	*group;
};

#endif
