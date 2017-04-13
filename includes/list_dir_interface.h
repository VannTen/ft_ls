/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dir_interface.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:45:56 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/13 17:54:09 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_DIR_INTERFACE_H
# define LIST_DIR_INTERFACE_H
# include "parameters_interface.h"
# include "libft.h"
# include <sys/types.h>
# include <sys/dir.h>

int	list_dir(int path_len, t_ls_param *param);

#endif
