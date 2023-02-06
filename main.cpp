#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string szyfruj(string slowo, int klucz) {
    string output = "";
    for (int i = 0; i < slowo.length(); i++) {
        if ((int) slowo[i] >= 97 && (int) slowo[i] <= 122) {
            output = output + (char) (((((int) slowo[i] - 97) + klucz) % 26) + 97);
        } else if ((int) slowo[i] >= 65 && (int) slowo[i] <= 90) {
            output = output + (char) (((((int) slowo[i] - 65) + klucz) % 26) + 65);
        } else {
            output = output + slowo[i];
        }

    }
    return output;

}

bool czywalfabecie(const char letter, const string alphabet) {
    for (int i = 0; i < alphabet.length(); i++) {
        if (alphabet[i] == letter) {
            return true;
        }
    }
    return false;

}

int znajdzwalfabecie(const char letter, const string alphabet) {
    for (int i = 0; i < alphabet.length(); i++) {
        if (alphabet[i] == letter) {
            return i;
        }
    }
    return -1;
}

string szyfrujpl(string slowo, int klucz) {
    const string alfabet_a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";//"aąbcćdeęfghijklłmnńopqrsśtuvwxyzźż";
    const string alfabet_b = "abcdefghijklmnopqrstuvwxyz"; //"AĄBCĆDEĘFGHIJKLŁMNŃOPQRSŚTUVWXYZŹŻ";
    string output = "";
    cout << alfabet_a.length() << endl;
    for (int i = 0; i < slowo.length(); i++) {
        if (czywalfabecie(slowo[i], alfabet_b)) {
            int pozycja = znajdzwalfabecie(slowo[i], alfabet_b);
            output += alfabet_b[(pozycja + klucz) % alfabet_a.length()];
        } else if (czywalfabecie(slowo[i], alfabet_a)) {
            int pozycja = znajdzwalfabecie(slowo[i], alfabet_a);
            output += alfabet_a[(pozycja + klucz) % alfabet_b.length()];
        } else output = output + slowo[i];
    }
    return output;

}

string smalltoBig(const string small) {
    string big = "";
    for (int i = 0; i < small.length(); i++) {
        if ((int) small[i] >= 97 && (int) small[i] <= 122) {
            big = big + (char) ((int) small[i] - 32);
        } else big = big + small[i];
    }
    return big;
}

void szyfrujzklawiatury() {
    cout << "Wprowadz slowo" << endl;
    string slowo;
    cin >> slowo;
    cout << "Wprowadz klucz" << endl;
    int klucz;
    cin >> klucz;

    cout << szyfrujpl(slowo, klucz);
}

void wczytywaniezpliku() {
    ifstream wejscie("tekst_jawny.txt");
    ofstream wyjscie("szyfrogram.txt");
    string k;
    int klucz;
    cout << "klucz: ";
    cin >> klucz;
    while (!wejscie.eof()) {
        getline(wejscie, k);
        wyjscie << szyfruj(k, klucz) << endl;
    }
    wejscie.close();
    wyjscie.close();
    cout << "Plik szyfrogram.txt zostal utworzony";
}

void loopwithpos(string word) {
    for (int i = 0; i < word.length(); i++) {
        cout << word[i] << " " << i << endl;
    }

}

void loopparzyste(string word) {
    for (int i = 0; i < word.length(); i += 2) {
        cout << word[i] << " " << i << endl;
    }
}

int *sort(int tablica[], int size) {
    int przechowalnia;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (tablica[j] > tablica[j + 1]) {
                przechowalnia = tablica[j];
                tablica[j] = tablica[j + 1];
                tablica[j + 1] = przechowalnia;
            }
        }
    }
    return tablica;
}

string permutacyjny(string klucz, string slowo) {

    //klucz="RSUZOCBEYXWILTMJGDQAPNVFHK";
    string wynik;
    for (int i = 0; i < slowo.length(); i++) {
        if ((int) slowo[i] >= 65 && (int) slowo[i] <= 90) {
            wynik = wynik + klucz[(int) slowo[i] - 65];
        } else if ((int) slowo[i] >= 97 && (int) slowo[i] <= 122) {
            wynik = wynik + klucz[(int) slowo[i] - 97];

        } else
            wynik = wynik + slowo[i];
    }
    return wynik;

}

string permutacyjnyroz(string klucz, string slowo) {
    string wynik;
    for (int i = 0; i < slowo.length(); i++) {
        if ((int) slowo[i] >= 65 && (int) slowo[i] <= 90) {
            int pozycja = znajdzwalfabecie(slowo[i], klucz);
            wynik = wynik + (char) (pozycja + 65);
        } else
            wynik = wynik + slowo[i];
    }
    return wynik;

}

int nwd(int a, int b) {
    if (a != b) {
        if (a > b) {
            a = a - b;
            return nwd(a, b);
        } else {
            b = b - a;
            return nwd(a, b);
        }
    } else {
        return a;
    }

}

int nwddzielenie(int a, int b) {
    while (a != 0 && b != 0) {
        if (a > b) {
            a = a % b;
            cout<<"1 "<<a<<" "<<b<<endl;
        } else {
            b = b % a;
            cout<<"2 "<<a<<" "<<b<<endl;
        }

    }
    if (a != 0) {
        cout<<"3 "<<a<<" "<<b<<endl;
        return a;
    } else {
        cout<<"4 "<<a<<" "<<b<<endl;
        return b;
    }
}

struct ulam{
    int licz;
    int mian;
    string nazwa;
};

int main() {
    int wynik = nwd(14, 10);
//    cout << wynik;
    ulam a;
    a.licz=196;
    a.mian=42;
    a.nazwa="Jas";
    int wynik2=nwddzielenie(a.licz, a.mian);
    a.mian=a.mian/wynik2;
    a.licz=a.licz/wynik2;
    cout<<a.licz<< "/" <<a.mian;
//    string wynik = permutacyjny("RSUZOCBEYXWILTMJGDQAPNVFHK", "abcd");
//    cout << wynik << endl;
//    string ros = permutacyjnyroz("RSUZOCBEYXWILTMJGDQAPNVFHK", wynik);
//    cout<<ros<<endl;

//    int array [5] ={1,3,5,7,4};
//    int *tablica  = sort(array,5);
//      cout<<tablica[i]<<endl;
//    }
    return 0;
}
//TODO 1:
//-plik tekstowy DONE
//- napisać pętlę która wypisze wszystkie litery w stringu wraz z ich pozycją np "abc" -> a-0,b-1,c-2
// void loopwithpos(string word){.. cout<<}
// napisać pętlę która wypisze co drugą literę w stringu  np "abcd" -> a,c
// void loopparzyste(string word){.. cout<<}
// sortowanie bąbelkowe -> przypomnieć co to, posortować tablice
// int[] sort(int[]){for for}
// strona 126 szyfr permutacyjny z kluczem RSU
// string szyfrujRSU(string slowo, string klucz)




//TODO 2:
// napisac nww
// napisac dodawanie ulamkow
// napisac odejmowanie ulamkow
// ulam dodaj (ulam first, ulan second)
// bin to dec
// dec to bin
// ispalindrom
// 6 + zapoznaj się z liczbami losowymi
// funkcja w zadaniu - klucz który trzeba wsadzić w poprzednią funkcję
