/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:20:25 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/03 13:41:43 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_dir_interface.h"
#include "dir_entry_interface.h"
#include "libft.h"
#include "options_interface.h"
#include <sys/types.h>
#include <sys/dir.h>
#include <sys/ucred.h>

int main(void)
{
	char path[1024];

	ft_strcpy(path, ".");
	list_dir(path, ft_strlen("."), &comp_alpha);

	return (0);
}
