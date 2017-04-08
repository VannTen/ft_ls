/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_infos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 18:07:25 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/08 18:08:13 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_defs.h"

int		get_block_nbr(void *file)
{
	struct s_file	*s_file;

	s_file = file;
	return (s_file->file_infos.st_blocks);
}
