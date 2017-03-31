/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dir_interface.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:45:56 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/31 18:48:51 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_DIR_INTERFACE_H
# define LIST_DIR_INTERFACE_H
# include "libft.h"
# include <sys/types.h>
# include <sys/dir.h>

void	list_dir(DIR *directory, t_compare comp_ft);

#endif
