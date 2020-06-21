# Temat projektu: Gra memory

Opis:
Prosta gra przypominająca grę w memory polegająca na odrkywaniu kolejnych kart i znajdowaniu ich pasujących par, grę wygrywa się po odkryciu całej talii rozłożonej na planszy.

Funkcjonalność programu:
- Menu główne.
- Adaptacja programu do zmiany rozdzielczości - np rozciągnięcia programu na cały akran.
- Plansza z 15 parami różnych kart.
- Po odkryciu dwóch kart gra przez około sekundę wyświetla je po czym jeśli do siebie pasują zostawia je odkryte 
do końca gry, natomiast jeśli są to niepasujące do siebie karty to je ponownie zakrywa.
- Po odkryciu wszystkich par kart gra się kończy.  
- Gra zlicza ilość odkryć i po zakończeniu wyświetla ilość nietrafionych przez nas odkryć oraz czas jaki nam zajęła rozgrywka.

Jak zagrać?  
Pobieramy folder lub archiwum. Grę uruchamiamy przy pomocy komendy "./Ksmemory". Ważne jest aby nie zmieniać pobranej struktury ponieważ inaczej istnieje możliwość niewczytania tekstur oraz czcionek.

# Opis poszczegolnych klas:
*Opis poszczególnych funkcji w klasach (w przypadku gdy ich nazwa wystarczająco je nie opisuje) można znaleźć w samych plikach nagłówkowych klas

Klasa **game.h**
```
Klasa game.h odpowiada za komunikację pomiędzy 3 głównymi klasami gry (gameboard.h, gamestate.h, menu.h)  
oraz oknem programu które inicjalizowane jest w głównym pliku main.cpp.
```

Klasa **menu.h**
```
Klasa menu.h odpowiada za wyświetlanie menu głównego, "popupu" podczas gry z opcjami powrotu do menu oraz  
wyjścia gry i finalnego okna po skończeniu gry.
```

Klasa **gamestate.h**
```
Klasa gamestate.h jest jedną z dwóch części odpowiadających za działanie samej gry, odpowiada ona za  
przetrzymanie wszelkich ważnych informacji tak jak stanu gry (czyli czy gra jest wygrana), ilości prób  
odkryć kart w trakcie gry i ilościi aktualnie odkrytych kart. Odpowiada ona również za losowe generowanie  
i rozkładanie kart po planszy oraz za restartowanie stanu gry po powrocie do menu głównego.
```

Klasa **gameboard.h**
```
Klasa gameboard.h jest drugą z klas odpowiadającydch za działanie gry, przechowuje ona wszystkie karty w  
wektorze kart (obiektu card z klasy card.h) oraz zajmuje się poleceniami z nimi związanymi jak na przykład  
odkrywanie czy zakrywanie kart. Klasa ta dziedziczy z klasy card.h.
```

Klasa **card.h**
```
Klasa card.h jest odpowiedzialna za pojedyńcze karty na planszy, przetrzymuje ona informacje o ich  
stanie, ich unikalnym numerze id - aby rozponać czy przy odkryciu została odkryta karta pasująca do niej -  
oraz obsługuje wszystkie funkcje związane z tymi zmiennymi.
```
