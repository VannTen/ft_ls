/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_and_perms_interface.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 13:39:26 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/05 14:43:11 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODE_AND_PERMS_INTERFACE_H
# define MODE_AND_PERMS_INTERFACE_H
# include <sys/stat.h>

enum	e_perm_category
{
	OWNER,
	GROUP,
	OTHER,
	PERM_CAT_NBR
};

enum	e_mode_fields
{
	FILETYPE,
	OWNER_READ,
	OWNER_WRITE,
	OWNER_EXE,
	GROUP_READ,
	GROUP_WRITE,
	GROUP_EXE,
	OTHER_READ,
	OTHER_WRITE,
	OTHER_EXE,
	MODE_ARRAY_SIZE,
};

void	fill_mode_field(char *mode_field, mode_t mode);

#endif
