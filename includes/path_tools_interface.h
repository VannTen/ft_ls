/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_tools_interface.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 17:52:22 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/05 17:56:46 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_TOOLS_INTERFACE_H
# define PATH_TOOLS_INTERFACE_H

void	set_file_path(char *parent_path, int path_len, const char *file_name);
void	restore_path(char *parent_path, int path_len);

#endif
