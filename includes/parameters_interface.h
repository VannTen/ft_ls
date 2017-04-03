/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters_interface.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 16:35:10 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/03 18:50:23 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETERS_INTERFACE_H
# define PARAMETERS_INTERFACE_H
# define CONST_SYNOPSIS_INITIALIZER "alrRt"
# define MAX_PATH 1024

enum	e_ls_opt
{
	ALL_FILES,
	LONG_FORMAT,
	REVERSE_ORDER,
	RECURSIVE,
	SORT_BY_MODIF_TIME,
	OPT_NBR
};

#endif
