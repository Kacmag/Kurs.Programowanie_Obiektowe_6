Kontynuacja projektu Wizualizacja Przejazdu Łazika Opis Projektu Projekt demonstruje przykład wizualizacji przejazdu łazika marsjańskiego. Przykład ten można wykorzystać jako punkt wyjścia do realizacji bardziej złożonego zadania z zakresu programowania obiektowego. Dostarczony kod służy jako prototyp i wymaga znaczącej przebudowy oraz dostosowania do obiektowych standardów programowania, aby spełnić wymagania zadania. Struktura Katalogów Projekt zawiera dwie główne kartoteki:

pliki_do_rysowania/: Kartoteka robocza zawierająca pliki z wyliczonymi współrzędnymi wierzchołków brył. Pliki te są używane przez program gnuplot do rysowania brył. Katalog ten jest tworzony automatycznie przy pierwszym uruchomieniu polecenia make, jeśli nie istnieje.

bryly_wzorcowe/: Zawiera zestaw brył wzorcowych używanych w projekcie. Zawartość tego katalogu nie ulega zmianie podczas działania programu.
