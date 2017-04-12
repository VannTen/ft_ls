/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_long_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:30:38 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/12 19:01:33 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long_format.h"
#include "file_defs.h"
#include "libft.h"
#include <sys/types.h>

void		fill_file_field(struct s_file *file,
		struct s_long_form_field *field)
{
	field->hard_link = itoa_len_signed(file->file_infos.st_nlink, 10);
	field->user = file->user == NULL ?
		itoa_len_signed(file->file_infos.st_uid, 10) :
		ft_strlen(file->user->pw_name);
	field->group = file->group == NULL ?
		itoa_len_signed(file->file_infos.st_gid, 10) :
		ft_strlen(file->group->gr_name);
	field->device_major =
		itoa_len_signed(major(file->file_infos.st_rdev), 10);
	field->device_minor =
		itoa_len_signed(is_block_or_char_file(file) ?
				minor(file->file_infos.st_rdev) : file->file_infos.st_size, 10);
	field->device_sep = is_block_or_char_file(file) ? 2 : 1;
}

void		get_bigger_field_width(struct s_long_form_field *to_mod,
		const struct s_long_form_field *ref)
{
	to_mod->hard_link = MAX(to_mod->hard_link, ref->hard_link);
	to_mod->user = MAX(to_mod->user, ref->user);
	to_mod->group = MAX(to_mod->group, ref->group);
	to_mod->device_major = MAX(to_mod->device_major, ref->device_major);
	to_mod->device_minor = MAX(to_mod->device_minor, ref->device_minor);
	to_mod->device_sep = MAX(to_mod->device_sep, ref->device_sep);
}

void		init_fields(struct s_long_form_field *to_mod)
{
	to_mod->hard_link = 0;
	to_mod->user = 0;
	to_mod->group = 0;
	to_mod->device_major = 0;
	to_mod->device_minor = 0;
	to_mod->device_sep = 0;
}

t_fields	*check_fields(struct s_file *file, t_fields *ref)
{
	t_fields	this_file;

	file->user = getpwuid(file->file_infos.st_uid);
	file->group = getgrgid(file->file_infos.st_gid);
	fill_file_field(file, &this_file);
	get_bigger_field_width(ref, &this_file);
	return (ref);
}
