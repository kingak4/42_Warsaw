/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:29:00 by kikwasni          #+#    #+#             */
/*   Updated: 2025/01/27 16:57:43 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_printx(int nb)
{
	unsigned int	tmp;
	int				len;

	len = 0;
	tmp = nb;
	// Pętla, która liczy liczbę cyfr w zapisie szesnastkowym.
	// Pamiętaj, żeby zwiększyć zmienną 'len' tylko wtedy, gdy liczba jest większa lub równa 16.
	// Rozpocznij pętlę dzieląc liczbę przez 16.
	// Pamiętaj też o obsłudze przypadku, gdy liczba wynosi 0 (wtedy powinna być tylko 1 cyfra).
	while (temp >= 16)
	{
		temp /= 16;
		len++;  // Liczba cyfr w systemie szesnastkowym
	}

	// Druga pętla - przetwarzanie każdej cyfry i zapisanie jej do 'result'
	// Tu zakładam, że chcesz przechować wynik w jakiejś tablicy, ale nie widzę deklaracji 'result' w kodzie.
	// Jeśli chcesz wypisać wynik bezpośrednio, nie musisz przechowywać wyniku w 'result'.
	// Jeżeli jednak przechowujesz wynik w tablicy, musisz zadeklarować odpowiednią pamięć dla 'result'.
	// Możesz to zrobić przy pomocy malloc lub ustalić rozmiar tablicy przed jej użyciem.
	// Na razie masz tylko `result`, ale nie ma zainicjalizowanej pamięci dla tej zmiennej.
	// Jeśli chcesz przechować wynik, użyj dynamicznej alokacji lub statycznej tablicy.
	while (len > 0)
	{
		// Zwróć uwagę na konwersję liczb szesnastkowych większych niż 9.
		// Zamiast '0' dla cyfr powyżej 9 musisz dodać odpowiednią konwersję na litery 'a'-'f' (dla małych liter).
		// Pamiętaj, że dla %X litery będą w formacie wielkich liter 'A'-'F', a dla %x - małych 'a'-'f'.
		result[len - 1] = (tmp % 16) + '0';  // Zmienna 'tmp' jest wykorzystywana do pobierania reszty z dzielenia przez 16
		tmp = tmp / 16;
		len--;  // Zmniejszaj długość, ponieważ drukujesz jedną cyfrę
	}

	// Pamiętaj o zakończeniu ciągu znaków (jeśli przechowujesz go w tablicy 'result').
	// Na końcu tablicy musisz dodać znak null-terminatora ('\0'), żeby wynik był poprawnym ciągiem C.
	// Jeśli wypisujesz wynik bezpośrednio, nie musisz tego robić.
}
