/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalana- <ebalana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:44:25 by ebalana-          #+#    #+#             */
/*   Updated: 2025/02/19 13:04:27 by ebalana-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "../lib/ultimate_libft/ultimate_libft.h"

# define WRONG_FROMAT	"Error: Wrong format.\n./client <PID> <mensaje>\n"
# define ERROR_PID		"Error: No response from server.\nCheck PID.\n"
# define ERROR_PID_NUM	"Error: Invalid PID.\nPlease enter valid numeric PID.\n"

#endif