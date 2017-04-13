/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:28:09 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/13 11:56:27 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_defs.h"
#include "mode_and_perms_interface.h"

t_bool	is_dir(const struct s_file *file)
{
	return (file_type(file->file_infos.st_mode) == 'd');
}

t_bool	is_block_or_char_file(const struct s_file *file)
{
	char type;

	type = file_type(file->file_infos.st_mode);
	return (type == 'b' || type == 'c');
}

t_bool	is_link(const struct s_file *file)
{
	char type;

	type = file_type(file->file_infos.st_mode);
	return (type == 'l');
}
