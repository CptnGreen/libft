/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:48:47 by slisandr          #+#    #+#             */
/*   Updated: 2019/04/14 23:01:03 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isupper(int c);
static int	ft_islower(int c);

int				ft_isalpha(int c)
{
	return ((ft_isupper(c) != 0 || ft_islower(c) != 0) ? (1) : (0));
}

static int		ft_isupper(int c)
{
	return ((c >= 'A' && c <= 'Z') ? (1) : (0));
}

static int		ft_islower(int c)
{
	return ((c >= 'a' && c <= 'z') ? (1) : (0));
}
