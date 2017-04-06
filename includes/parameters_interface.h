/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters_interface.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 16:35:10 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/06 18:55:19 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETERS_INTERFACE_H
# define PARAMETERS_INTERFACE_H
# define CONST_SYNOPSIS_INITIALIZER "alrRt"

enum	e_ls_opt
{
	ALL_FILES,
	LONG_FORMAT,
	REVERSE_ORDER,
	RECURSIVE,
	SORT_BY_MODIF_TIME,
	OPT_NBR
};

typedef struct s_ls_param	t_ls_param;

t_ls_param *settle_param(int arg_count, char **arg_values);

#endif
