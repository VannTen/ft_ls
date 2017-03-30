/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_interface.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 16:47:05 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/30 16:50:45 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_INTERFACE_H
# define OPTIONS_INTERFACE_H
# include "libft.h"

void	set_all_files(t_bool *opt_array);
void	set_long_format(t_bool *opt_array);
void	set_reverse_order(t_bool *opt_array);
void	set_recursive(t_bool *opt_array);
void	set_modif_time_sort(t_bool *array);

# define CONST_APPLY_OPT_INIT \
	&set_all_files,\
	&set_long_format,\
	&set_reverse_order,\
	&set_recursive,\
	&set_modif_time_sort

#endif
