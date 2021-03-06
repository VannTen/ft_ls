/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 18:13:18 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/13 20:12:59 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LONG_FORMAT_H
# define LONG_FORMAT_H
# include "file_interface.h"
# include "mode_and_perms_interface.h"
# include <grp.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <sys/syslimits.h>

enum			e_type_of_string
{
	USUAL,
	NO_USER_NAME,
	NO_GROUP_NAME,
	NEITHER
};

typedef struct	s_long_form_field
{
	int	hard_link;
	int	user;
	int group;
	int	device_major;
	int	device_minor;
	int	device_sep;
}				t_fields;

void			long_format_usual(struct s_file *file, char *link_path);
void			long_format_no_user_name(struct s_file *file, char *link_path);
void			long_format_no_group_name(struct s_file *file, char *link_path);
void			long_format_neither(struct s_file *file, char *link_path);

/*
** Field struct functions : compare, init, fill.
** Implementation file : field_long_format.c
*/

void			get_bigger_field_width(struct s_long_form_field *to_mod,
			const struct s_long_form_field *ref);
void			fill_file_field(struct s_file *file,
			struct s_long_form_field *field);
void			init_fields(struct s_long_form_field *to_mod);
t_fields		*check_fields(struct s_file *file, t_fields *ref);

#endif
