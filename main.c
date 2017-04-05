/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:20:25 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/05 17:01:22 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_dir_interface.h"
#include "file_interface.h"
#include "libft.h"
#include "options_interface.h"
#include <sys/types.h>
#include <sys/dir.h>
#include <sys/ucred.h>
#include <sys/syslimits.h>

int main(void)
{
	char path[PATH_MAX];

	ft_strcpy(path, ".");
	list_dir(path, ft_strlen("."), &comp_alpha);

	return (0);
}
