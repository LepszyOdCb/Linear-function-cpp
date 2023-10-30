#include <iostream>
#include <cmath>

using namespace std;

// Funkcja liczaca a i b
void liczenieAiB(double x1, double y1, double x2, double y2, double &a, double &b)
{
    if (x1 == x2 && y1 == y2)
    {
        cout << "Podane wspolrzedne sa punktem!" << endl;
    }
    else if (x1 != x2)
    {
        a = (y2 - y1) / (x2 - x1);
        b = y1 - (a * x1);
        if (a == 0) {
            if (b > 0)
            {
                cout << "f(x) = " << abs(a) << "x + " << b << endl;
            }
            else if (b < 0)
            {
                cout << "f(x) = " << abs(a) << "x" << b << endl;
            }
            else
            {
                cout << "f(x) = " << abs(a) << "x" << endl;
            }
        }
        else if (b > 0)
        {
            cout << "f(x) = " << a << "x + " << b << endl;
        }
        else if (b < 0)
        {
            cout << "f(x) = " << a << "x" << b << endl;
        }
        else
        {
            cout << "f(x) = " << a << "x" << endl;
        }
    }
}

// Funkcja sprawdzajaca czy funkcja rosnie lub maleje
void monotonicznosc(double a)
{
    if (a > 0)
    {
        cout << "Funkcja rosnie" << endl;
    }
    else if (a < 0)
    {
        cout << "Funkcja maleje" << endl;
    }
    else if (a == 0) {
        cout << "Funkcja jest stala" << endl;
    }
    else
    {
        cout << "Funkcja jest nieprawidlowa" << endl;
    }
}

// Funkcja liczaca dziedzine oraz zbior wartosci
void dziedzinaZbiorWartosci(double a, double b, double x1, double x2)
{
    if (a == 0 && x1 != x2) {
        cout << "Df: x = R" << endl;
    }
    else if (a != 0){
        cout << "Df: x = R" << endl;
    }
    else {
        cout << "Brak Df" << endl;
    }

    if (a == 0 && x1 != x2) {
        cout << "Zw = " << b << endl;
    }
    else if (a != 0) {
        cout << "Zw = R" << endl;
    }
    else {
        cout << "Brak Zw" << endl;
    }
}

// Funkcja liczaca dla ktorych x y jest ujemne i dodatnie
void yUjemneDodatnieX(double a, double b, double x1, double x2)
{
    double miejscezerowe = -b / a;
    if (a == 0 && x1 != x2) {
        if (b < 0) {
            cout << "Y ujemne dla x = R" << endl;
        }
        else if (b > 0) {
            cout << "Y dodatnie dla x = R" << endl;
        }
    }
    else if (x1 != x2) {
        cout << "Y ujemne dla x = ( -nieskonczonosc, " << miejscezerowe << " )" << endl;
        cout << "Y dodatnie dla x = < " << miejscezerowe << ", nieskonczonosc )" << endl;       
    } 
}

// Funkcja liczaca miejsce zerowe
void miejscazerowe(double a, double b, double &przeciecieoy, double x1, double x2, double &miejscezerowe)
{
    if (a == 0 && x1 == x2) {
        if (b == 0 && x1 != x2) {
            cout << "Miejsce zerowe = R" << endl;
        }
        else if (b != 0) {
            cout << "Przeciecie z OY = " << b << endl;
        }
    }
    else if (a != 0) {
        miejscezerowe = -b / a;
        cout << "Miejsce zerowe = " << miejscezerowe << endl;
        cout << "Przeciecie z OY = " << b << endl;
    }
    else if (a == 0 && b == 0) {
        cout << "Miejsce zerowe = 0" << endl;
        cout << "Przeciecie z OY = 0" << endl;
    }
}

// Funkcja liczaca argumenty dla wartosci
void liczenieArgDlaWar(double a, double b)
{
    double x, y;
    cout << "Podaj wartosc (y): " << endl;
    cin >> y;
    x = (y - b) / a; 
    cout << y << " = f(" << x << ")" << endl;
}

// Funkcja liczaca argumenty dla wartosci
void liczenieWarDlaArg(double a, double b)
{
    double x, y;
    cout << "Podaj argument (x): " << endl;
    cin >> x;
    y = (a * x) + b;
    cout << "f(" << x << ") = " << y << endl;
}

// Glówna petla kodu
int main()
{
    // Zmienne
    double x1, y1, x2, y2, a = 0, b = 0, przeciecieoy = 0, miejscezerowe;
    int wybor;
    bool petla = true;

    // Glowny kod
    cout << "=-=-=-=-= Start =-=-=-=-=" << endl;
    cout << "Liczenie funkcji liniowej" << endl;
    cout << "Podaj x i y 1. punktu: " << endl;
    cin >> x1;
    cin >> y1;
    cout << "Podaj x i y 2. punktu: " << endl;
    cin >> x2;
    cin >> y2;
    cout << "=-=-=-=-= Wyniki =-=-=-=" << endl;
    liczenieAiB(x1, y1, x2, y2, a, b);
    monotonicznosc(a);
    dziedzinaZbiorWartosci(a, b, x1, x2);
    yUjemneDodatnieX(a, b, x1, x2);
    miejscazerowe(a, b, przeciecieoy, x1, x2, miejscezerowe);
    
    if (x1 != x2) {
        while (petla)
        {
            cout << "Wybierz opcje: " << endl;
            cout << "- 1 - liczenie argumentu dla wartosci" << endl;
            cout << "- 2 - liczenie wartosci dla argumentu" << endl;
            cout << "- 3 - zakoncz dzialanie programu" << endl;
            cin >> wybor;

            switch (wybor)
            {
                case 1:
                    liczenieArgDlaWar(a, b);
                    break;
                case 2:
                    liczenieWarDlaArg(a, b);
                    break;

                case 3:
                    petla = false;
                    break;

                default:
                    cout << "Niepoprawny wybor." << endl;
                    break;
            }
        }
    }
    cout << "=-=-=-=-= Koniec =-=-=-=";

    return 0;
}
