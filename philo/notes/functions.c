
usleep

Opis: Wstrzymuje wykonanie programu na określoną ilość mikrosekund.

Zastosowanie: Symulowanie czasu jedzenia/snu w symulacji filozofów.

gettimeofday

Opis: Pobiera aktualny czas (w sekundach i mikrosekundach).

Zastosowanie: Pomiar czasu startu, śmierci filozofa, synchronizacja działań.

🧵 FUNKCJE WĄTKÓW I MUTEXÓW (POSIX Threads)
pthread_create


Opis: Tworzy nowy wątek i uruchamia w nim daną funkcję.

Zastosowanie: Każdy filozof działa jako osobny wątek.

pthread_detach

Opis: Odłącza wątek – jego zasoby zostaną automatycznie zwolnione po zakończeniu działania.

Zastosowanie: Jeśli nie chcesz czekać na zakończenie wątku (brak pthread_join).

pthread_join

Opis: Czeka na zakończenie działania danego wątku.

Zastosowanie: Synchronizacja zakończenia głównego programu.

pthread_mutex_init

Opis: Inicjalizuje mutex.

Zastosowanie: Tworzenie ochrony dla wspólnych zasobów (np. widelec).

pthread_mutex_destroy

Opis: Usuwa mutex i zwalnia jego zasoby.

Zastosowanie: Czyszczenie po zakończeniu programu.

pthread_mutex_lock

Opis: Blokuje mutex – jeśli jest już zablokowany, wątek czeka.

Zastosowanie: Przed pobraniem widelca, pisaniem na stdout itp.

pthread_mutex_unlock

Opis: Odblokowuje mutex.

Zastosowanie: Po zakończeniu operacji na współdzielonym zasobie.