/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copeugne <copeugne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:12:51 by datran            #+#    #+#             */
/*   Updated: 2023/07/10 13:01:00 by copeugne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_SIGNAL_H
# define SH_SIGNAL_H

void	init_signal(void);
void	change_signal(void);
void	heredoc_signal(void);
void	multishell_signal(void);

#endif
