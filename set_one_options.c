/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_one_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 16:39:41 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/30 16:46:42 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parameters_interface.h"

void	set_all_files(t_bool *opt_array)
{
	opt_array[ALL_FILES] = TRUE;
}

void	set_long_format(t_bool *opt_array)
{
	opt_array[LONG_FORMAT] = TRUE;
}

void	set_reverse_order(t_bool *opt_array)
{
	opt_array[REVERSE_ORDER] = TRUE;
}

void	set_recursive(t_bool *opt_array)
{
	opt_array[RECURSIVE] = TRUE;
}

void	set_modif_time_sort(t_bool *array)
{
	opt_array[SORT_BY_MODIF_TIME] = TRUE;
}
