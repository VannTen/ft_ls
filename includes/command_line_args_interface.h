/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line_args_interface.h                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 19:25:05 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/13 19:29:20 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_LINE_ARGS_INTERFACE_H
# define COMMAND_LINE_ARGS_INTERFACE_H
# include "parameters_interface.h"
# include "long_format.h"

void	process_cmd_line_args(const char **argv,
		t_ls_param *params, t_fields *fields);

#endif
