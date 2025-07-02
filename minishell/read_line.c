/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:16:31 by root              #+#    #+#             */
/*   Updated: 2025/07/02 20:17:17 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_cmd
{
	char	*line;
	char	*file;
}	t_cmd;

t_cmd	*read_cmd(t_cmd *read)
{
	if (!read)
		return (NULL);
	read->line = readline("minishell");
	if(!read->line)
		return (NULL);
	return (read);
}
int check_redirect_error(t_cmd *read, int pos)
{
    int     count;
    int     i;
    char    c;

    if (!read || !read->line)
        return (0);
    count = 0;
    i = pos;
    c = read->line[pos];
    while (read->line[i] && read->line[i] == c)
    {
        count++;
        i++;
    }
    if (count >= 3)
    {
        write(2, "minishell: syntax error near unexpected token '", 46);
        write(2, &read->line[pos], count);
        write(2, "'\n", 2);
        return (0);
    }
    return (1);
}
// do naprawy szkieliet to jest 
t_cmd parse_redirect(t_cmd *read, int pos)
{
    int size;
    int i;

    size = 0;
    i = 0;
    if (check_redirect_error(read, pos) == 0)
        return (NULL);
    while (read->line[size])
        size++;
    while (i < size)
    {
        if (read->line[i] == '>')
            read->redi_signal = 1;
        else if (read->line[i + 1] == '>')
             read->redi_signal = 2;
        else if (read->line[i] == '<')
             read->redi_signal = 3;
        else if (read->line[i + 1] == '<')
         read->redi_signal = 3;
        i++;
    }
   return(read);
}
// t_cmd	*check_red(t_cmd *read)
// {
//     int i;

//     i = 0;
//     read->line = read_cmd(read);
//     if (!read->line)
//         return (NULL);
//     while (read->line)
//     {
        
//     }
    
// }
int main(void)
{
    t_cmd cmd;

    while (1)
    {
        if (!read_cmd(&cmd))
        {
            printf("\nKoniec lub blad odczytu. Koncze program.\n");
            break;
        }

        printf("Wczytano linie: %s\n", cmd.line);

        free(cmd.line);
    }
    rl_clear_history();
    return 0;
}
// ❌ Co jest źle lub niedokończone:
// 1. 🔥 Błąd w while (read->line) line++;
// To nie liczy długości linii. Zamiast tego powinnaś użyć ft_strlen(read->line) lub klasycznego strlen().
// 2. 🔥 Błędna logika kolejności warunków
// c
// Kopiuj
// Edytuj
// if (read->line[i] == '>')
// 	read->redi_signal = 1;
// else if (read->line[i + 1] == '>')
// 	read->redi_signal = 2;
// Ten kod zawsze ustawi 1, nawet gdy jest >>, bo i+1 jest sprawdzane dopiero w else if. To błąd logiczny – musisz najpierw sprawdzić >>, a dopiero potem >.
// 3. 🔥 Nadpisywanie read->redi_signal
// Twoja struktura:
// c
// Kopiuj
// Edytuj
// int *redi_signal;
// A więc powinnaś przypisywać do redi_signal[i], a nie do całego wskaźnika. Inaczej nadpisujesz cały wskaźnik intem – to błąd krytyczny.
// 4. 🔥 Brak przesuwania indeksu dla >> i <<
// Jeśli znajdziesz >>, musisz przesunąć i += 2, nie i++. Inaczej złapiesz oba znaki osobno.
// 5. 🔥 Brak obliczenia liczby redirekcji i indeksowania
// Musisz przechowywać count, np. j, żeby wiedzieć na którym indeksie w tablicy redi_signal[j] zapisujesz dany typ redirekcji.
// ✅ RANO (ok. 3–4h)
// 🔹 1. Parsowanie i identyfikacja redirekcji (logika + kod)
//  Przejdź przez każdy znak w read->line
//  Sprawdzaj: >, >>, <, <<
//  Rozróżnij typ redirekcji i zapisz go w redi_signal[i]
//  Zapamiętaj nazwę pliku (lub delimiter dla <<) w redi_file[i]
//  Zwiększaj count_redi
// 🔹 2. Obsługa błędów składniowych (🟥 1–3, 9–10, 11)
// Dodaj funkcje typu check_syntax_errors:
//  Sprawdź brak argumentu po >, >>, <, <<
// Zbyt dużo znaków: >>>, <<<<, >< → błąd składni
//  Redirekcja bez polecenia przed pipe (np. < file |) → błąd
//  Więcej niż jedna redirekcja < lub > → zapamiętaj tylko ostatnią
// 🔹 3. Obsługa błędów systemowych (🟥 4–8, 12–13, 15)
// Dodaj funkcję check_file_errors(char *filename, int redi_type):
//  Sprawdź, czy plik istnieje (access())
//  Czy plik jest katalogiem (stat(), S_ISDIR)
//  Czy masz prawa odczytu/zapisu
//  Czy nazwa pliku po rozwinięciu nie jest pusta (ambiguous redirect)