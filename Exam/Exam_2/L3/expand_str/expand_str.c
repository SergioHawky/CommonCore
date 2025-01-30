/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 03:52:33 by seilkiv           #+#    #+#             */
/*   Updated: 2025/01/30 04:21:00 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int is_space(char c)
{
    return(c <= 32);
}

void    space(char *str)
{
    int i = 0;
    int space = 0;

    while(is_space(str[i]))
        i ++;
    while(str[i])
    {
        if(is_space(str[i]))
            space = 1;
        else
        {
            if(space)
            {
                ft_putchar(' ');
                ft_putchar(' ');
                ft_putchar(' ');
                space = 0;
            }
            ft_putchar(str[i]);
        }
        i ++;
    }
}

int main(int ac, char **av)
{
    if(ac == 2)
    {
        space(av[1]);
    }
    ft_putchar('\n');
    return 0;
}