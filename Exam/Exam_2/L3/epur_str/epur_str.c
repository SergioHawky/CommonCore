/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 02:54:26 by seilkiv           #+#    #+#             */
/*   Updated: 2025/01/30 03:45:41 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int is_space(char c)
{
    return (c <= 32);  // Retorna 1 se for espaço, tab ou newline, igual ao código exemplo.
}

void space(char *str)
{
    int i = 0;
    int space = 0;

    // Pular espaços iniciais
    while (is_space(str[i]))
        i++;

    while (str[i])
    {
        if (is_space(str[i]))
            space = 1; // Ativar flag de espaço quando encontrar um espaço
        else
        {
            if (space) // Se houve espaço antes de um caractere válido, imprimir um espaço
                ft_putchar(' ');
            space = 0;
            ft_putchar(str[i]);
        }
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
        space(av[1]);
    ft_putchar('\n');
    return 0;
}
