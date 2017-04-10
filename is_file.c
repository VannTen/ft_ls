/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:28:09 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/10 13:30:06 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_defs.h"
#include "mode_and_perms_interface.h"

t_bool	is_dir(struct s_file *file)
{
	return (file_type(file->file_infos.st_mode) == 'd');
}
