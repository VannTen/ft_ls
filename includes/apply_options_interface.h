/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_options_interface.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 18:54:41 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/12 18:55:24 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APPLY_OPTIONS_INTERFACE_H
# define APPLY_OPTIONS_INTERFACE_H

void	apply_all_files(void *param);
void	apply_long_format(void *param);
void	apply_reverse_order(void *param);
void	apply_recursive(void *param);
void	apply_sort_by_time(void *param);

#endif
