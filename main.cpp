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
            cout << "1 " << a << " " << b << endl;
        } else {
            b = b % a;
            cout << "2 " << a << " " << b << endl;
        }

    }
    if (a != 0) {
        cout << "3 " << a << " " << b << endl;
        return a;
    } else {
        cout << "4 " << a << " " << b << endl;
        return b;
    }
}

int czynniki(int n = 456) {
    int d = 2;
    //zcout<<n<<" = ";
    while (d * d <= n) {
        if (n % d == 0) {
            //cout<<d<<" * ";
            n = n / d;
        } else d++;
    }
    return n;

}

int nww(int a, int b) {

//    cout<<"Czynniki pierwsze pierwszej liczby - "<<czynniki(a)<<endl;
//   cout<<"Czynniki pierwsze drugiej liczby - "<<czynniki(b)<<endl;
    return a * b / nwd(a, b);
    cout << a << endl;
    cout << b << endl;
}

int dodawanie(int licznik, int mianownik) {
    int l1, l2, m1, m2;
    mianownik = nww(m1, m2);
    int i = licznik = mianownik / m1 * l1 + mianownik / m2 * l2;

    licznik /= nwd(i, mianownik);
    mianownik /= nwd(i, mianownik);
    cout << l1 << endl;
    cout << l2 << endl;


    cout << l1 << "/" << m1 << " + " << l2 << "/" << m2 << " = " << licznik << "/" << mianownik;

    return 0;
}

int dodawanie2(int a, int b, int c, int d) {
    int N = nwd(b, d);
    int k = b / N;
    int l = d / N;
    cout << (k * a + l * c) << " / " << (N * k * l);

}

int potegujaca(int liczba, int potega) {
    int wynik = 1;
    for (int i = 0; i < potega; i++) {
        wynik *= liczba;
    }
    return wynik;
}

int bintodec(string a) {
    int potega = 0;
    int wynik = 0;
    for (int i = a.length() - 1; i >= 0; i--) {
        wynik += ((int) a[i] - 48) * potegujaca(2, potega);
        potega++;
    }
    return wynik;
}

string odwrocony(string a) {
    string wynik = "";
    for (int i = a.length(); i >= 0; i--) {
        wynik += a;
    }
    return wynik;
}

string dectobin(int liczba) {
    string a = "";
    while (liczba != 0) {
        a += (char) (liczba % 2 + 48);
        liczba = liczba / 2;
    }
    return odwrocony(a);
}


struct ulam {
    int licz;
    int mian;
    string nazwa;
};

ulam dodaj(ulam first, ulam second) {
    int nd = nwd(first.mian, first.licz);
    int nd2 = nwd(second.mian, second.licz);
    first.licz /= nd;
    first.mian /= nd;
    second.licz /= nd2;
    second.mian /= nd2;;
    ulam result;
    result.licz = first.licz * (second.mian / nwd(first.mian, second.mian)) +
                  second.licz * (first.mian / nwd(first.mian, second.mian));
    result.mian = nww(first.mian, second.mian);
    return result;
}

ulam odejmuj(ulam first, ulam second) {
    int nd = nwd(first.mian, first.licz);
    int nd2 = nwd(second.mian, second.licz);
    first.licz /= nd;
    first.mian /= nd;
    second.licz /= nd2;
    second.mian /= nd2;;
    ulam result;
    result.licz = first.licz * (second.mian / nwd(first.mian, second.mian)) -
                  second.licz * (first.mian / nwd(first.mian, second.mian));
    result.mian = nww(first.mian, second.mian);
    return result;
}

ulam mnozenie(ulam first, ulam second) {
    int nd = nwd(first.mian, first.licz);
    int nd2 = nwd(second.mian, second.licz);
    first.licz /= nd;
    first.mian /= nd;
    second.licz /= nd2;
    second.mian /= nd2;;
    ulam result;
    result.licz = first.licz * second.licz;
    result.mian = first.mian * second.mian;
    result.licz /= nwd(first.mian, first.licz);
    result.mian /= nwd(second.licz, second.mian);
    return result;
}

bool isPalindrom(string a) {
    int k = a.length() - 1;
    for (int i = 0; i < a.length() / 2; i++) {
        cout << a[i] << "|" << a[k] << endl;
        if (a[i] != a[k]) {
            return false;
        }
        k--;
    }
    return true;
}
bool isPierwsza(int a){
    for(int i=2; i<=a/2; i++ ){
        cout<<a<<"|"<<i<<"/"<<a%i<<endl;
        if(a%i==0){
            return false;
        }
    }
    return true;
}

int main() {
    bool res = isPierwsza(1024);
    cout<<res<<endl;
//    bool res = isPalindrom("aaba");
//    cout << res << endl;
//    ulam a;
//    a.licz=1;
//    a.mian=2;
//    ulam b;
//    b.licz=2;
//    b.mian=6;
//    ulam c=mnozenie(a,b);
//    cout<<c.licz<<"/"<<c.mian<<endl;

    return 0;

//    int wynik = bintodec("01001110");
    //   cout << wynik << endl;
//    cout<<potegujaca(2,10)<<endl;
//    return 0;
//    int wynik = nwd(14, 10);
//    cout << wynik;
//    ulam a;
//    a.licz=196;
//   a.mian=42;
//    a.nazwa="Jas";
//    int wynik2=nwddzielenie(a.licz, a.mian);
//    a.mian=a.mian/wynik2;
//    a.licz=a.licz/wynik2;
//    cout<<a.licz<< "/" <<a.mian;
//    string wynik = permutacyjny("RSUZOCBEYXWILTMJGDQAPNVFHK", "abcd");
//    cout << wynik << endl;
//    string ros = permutacyjnyroz("RSUZOCBEYXWILTMJGDQAPNVFHK", wynik);
//    cout<<ros<<endl;

//    int array [5] ={1,3,5,7,4};
//    int *tablica  = sort(array,5);
//      cout<<tablica[i]<<endl;
//    }
    //   return 0;
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
// napisac dodawanie ulamkow - poprawa
// napisac odejmowanie ulamkow - nie ma
// ulam dodaj (ulam first, ulan second)
// bin to dec
// dec to bin - ok
// ispalindrom
// czy liczba jest piewrsza
// funkcja w zadaniu - klucz który trzeba wsadzić w poprzednią funkcję

//TO DO 3;
//czy liczby sa blizniacze 81
//uogólnic oba bin dec
//dec to 16; 16 to dec
//dzielenie ułamków
//szyfr RSU