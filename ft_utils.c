/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:44:07 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/02/17 13:47:59 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = -1;
	while (s[++i])
		write(fd, &s[i], 1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(const char *sr1, const char *sr2, size_t n)
{
	size_t			c;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)sr1;
	s2 = (unsigned char *)sr2;
	c = 0;
	if (n == 0)
		return (0);
	while ((s1[c] != '\0') && (s2[c] != '\0') \
			&& (s1[c] == s2[c]) && (c < (n - 1)))
		c++;
	return (s1[c] - s2[c]);
}

static int	ft_nbcount(long int nb)
{
	int	i;

	i = 0;
	if (nb == 0 || nb < 0)
		i++;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*num;
	int			i;
	int			k;
	long int	nb;

	k = 0;
	nb = n;
	i = ft_nbcount(nb);
	num = (char *)malloc(sizeof(char) * (i + 1));
	if (!num)
		return (NULL);
	if (n < 0)
	{
		nb = -nb;
		num[0] = '-';
		k++;
	}
	num[i] = '\0';
	while (i > k)
	{
		num[i - 1] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
	return (num);
}
