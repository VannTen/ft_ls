/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_tools_interface.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 17:52:22 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/13 18:22:27 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_TOOLS_INTERFACE_H
# define PATH_TOOLS_INTERFACE_H
# include "parameters_interface.h"
# include <stddef.h>

void	set_file_path(t_ls_param *param, size_t path_len,
		const char *file_name);
void	restore_path(t_ls_param *param, size_t path_len);
void	resize_parent_path(t_ls_param *param);

#endif
