#include <iostream>
using namespace std;
// w programie nie uwzględniłem uzupełniania tablicy losowymi liczbami, aby każdy mógł wklepać własne i przetestować na swoim przypadku :) uzupełnianie randem wyglądałoby tak: for(int i=0; i<N; i++) tab[i] = 2 * rand()%50 + 1;
// skrótowo, to idea programu jest taka - najpierw szukamy najdłuższego ciągu rosnącego, a potem malejącego, a dzięki odpowiednio napisanym warunkom robimy to w jednym przejściu pętli. Dokładny opis zawarty jest w komentarzach w pętli
int main() {
    int N = 10; // oczywiście tu może być cokolwiek > 1
    int tab[N];
    for(int i=0; i<N; i++) cin >> tab[i];

    int increasing_max_length = 1, decreasing_max_length = 1;
    int current_length = 1; // długość aktualnie rozpatrywanego ciągu, będziemy jej używać w pętli
    int current_difference; // różnica aktualnie rozpatrywanego ciągu arytmetycznego
    // oczywiście obie pętle można zrealizować w jednej, ale dla bardziej zrozumiałego kodu zapisałem to w osobnych
    // jeżeli ktoś chce zobaczyć wersję bardziej ścisłą, to jest ona na wiki (gitlabie). Tę napisałem tak, aby była jak najbardziej zrozumiała i czytelna.
    // znajdźmy najdłuższy ciąg rosnący
    current_difference = -1; // jakakolwiek wartość ujemna, odróżniamy w ten sposób ciąg ujemny
    for(int i=1; i<N; i++) {
        if(tab[i] > tab[i-1] and current_length == 1) { // rozpoczynamy analizowanie nowego podciągu, bo poprzedni się zakończył z powodu wystąpienia ciagu malejącego / dopiero rozpoczęliśmy program
            current_difference = tab[i] - tab[i-1];
            current_length = 2; // ustawiamy na 2, bo mamy dwa elementy tworzące nowy ciąg
        }
        else if(tab[i] - tab[i-1] == current_difference and current_difference > 0){ // jeśli podciąg dalej rośnie o różnicę arytmetyczną oraz różnica ta jest dodatnia
            current_length++;
        }
        else if(tab[i] - tab[i-1] != current_difference and tab[i] > tab[i-1]) { // jeżeli kolejny element ma inną różnicę, ale jest większy od poprzedniego, to rozpoczynamy nowy ciąg rosnący
            current_length = 2; // ustawiamy na 2, bo mamy dwa elementy tworzące nowy podciąg
            current_difference = tab[i] - tab[i-1];
        }
        else { // w przeciwnym wypadku mamy ciąg malejący. Jako następnego wywołamy pierwszego if'a (albo znów tego elsa, jeżeli następny element dalej będzie mniejszy)
            current_length = 1; // ustawiamy na 1, bo dopiero szukamy podciągu
            current_difference = -1;
        }
        if(current_length > increasing_max_length) increasing_max_length = current_length; // jeżeli aktualna długość jest większa od dotychczasowej maksymalnej, to update'ujemy maksymalną
        // poniżej cout wypisuje nam krok po kroku co się dzieje ze zmiennymi w tej pętli, możesz go sobie odkomentować aby to prześledzić. Zwróć uwagę na to, że wypisuje on aktualne wartości po zakończeniu danego obiegu pętli
        // cout << tab[i] << " current_length: " << current_length << ", current_difference: " << current_difference << ", increasing_max_length: " << increasing_max_length << endl;
    }

    // znajdźmy najdłuższy ciąg malejący, kod analogiczny do powyższej pętli
    current_difference = 1; // jakakolwiek wartość dodatnia
    current_length = 1;
    for(int i=1; i<N; i++) {
        if(tab[i] < tab[i-1] and current_length == 1) { // rozpoczynamy analizowanie nowego podciągu, bo poprzedni się zakończył z powodu wystąpienia ciagu malejącego / dopiero rozpoczęliśmy program
            current_difference = tab[i] - tab[i-1];
            current_length = 2; // ustawiamy na 2, bo mamy dwa elementy tworzące nowy ciąg
        }
        else if(tab[i] - tab[i-1] == current_difference and current_difference < 0){ // jeśli podciąg dalej maleje o różnicę arytmetyczną (mówiąc ściślej - maleję o jej wartość bezwględną jej różnicy) oraz różnica ta jest ujemna
            current_length++;
        }
        else if(tab[i] - tab[i-1] != current_difference and tab[i] < tab[i-1]) { // jeżeli kolejny element ma inną różnicę, ale jest mniejszy od poprzedniego, to rozpoczynamy nowy ciąg malejący
            current_length = 2; // ustawiamy na 2, bo mamy dwa elementy tworzące nowy podciąg
            current_difference = tab[i] - tab[i-1];
        }
        else { // w przeciwnym wypadku mamy ciąg malejący. Jako następnego wywołamy pierwszego if'a (albo znów tego elsa, jeżeli następny element dalej będzie mniejszy)
            current_length = 1; // ustawiamy na 1, bo dopiero szukamy podciągu
            current_difference = 1;
        }

        if(current_length > decreasing_max_length) decreasing_max_length = current_length; // jeżeli aktualna długość jest większa od dotychczasowej maksymalnej, to update'ujemy maksymalną
        // poniżej cout wypisuje nam krok po kroku co się dzieje ze zmiennymi w tej pętli, możesz go sobie odkomentować aby to prześledzić. Zwróć uwagę na to, że wypisuje on aktualne wartości po zakończeniu danego obiegu pętli
        // cout << tab[i] << " current_length: " << current_length << ", current_difference: " << current_difference << ", increasing_max_length: " << decreasing_max_length << endl;
    }

    cout << "increasing_max_length = " << increasing_max_length << ", decreasing_max_length = " << decreasing_max_length << endl;
    cout << increasing_max_length - decreasing_max_length << endl;

    return 0;
}
