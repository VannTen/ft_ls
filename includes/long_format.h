/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 18:13:18 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/11 17:36:51 by mgautier         ###   ########.fr       */
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

typedef struct	s_long_form_field
{
	int	hard_link;
	int	user;
	int group;
	int	device_major;
	int	device_minor;
}				t_fields;

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

/*
** Field struct functions : compare, init, fill.
** Implementation file : field_long_format.c
*/

void	get_bigger_field_width(struct s_long_form_field *to_mod,
		const struct s_long_form_field *ref);
void	fill_dir_field(struct s_file *file, struct s_long_form_field *field);
void	init_fields(struct s_long_form_field *to_mod)

#endif
