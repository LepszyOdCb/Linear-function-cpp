#include <iostream>
#include <cmath>

using namespace std;

// Funkcja licząca a i b
void liczenieAiB(double x1, double y1, double x2, double y2, double& a, double& b) {
    if (x1 == x2 && y1 == y2) {
        cout << "Podane wspolrzedne sa punktem!" << endl;
    } 
	else if (x1 != x2 && y1 != y2) {
        a = (y2 - y1) / (x2 - x1);
        b = y1 - (a * x1);
        if (b > 0) {
            cout << "f(x)=" << a << "x+" << b << endl;
        } else if (b < 0) {
            cout << "f(x)=" << a << "x" << b << endl;
        } else {
            cout << "f(x)=" << a << "x" << endl;
        }
    }
}

// Funkcja sprawdzająca czy funkcja rośnie lub maleje
void monotonicznosc(double a, double x1, double y1, double x2, double y2) {
    if (a > 0) {
        cout << "Funkcja rosnie" << endl;
    } else if (a < 0) {
        cout << "Funkcja maleje" << endl;
    } else {
        cout << "Funkcja jest prosta prostopadla do Y0" << endl;
	}
}

// Funkcja licząca dziedzinę oraz zbiór wartości
void dziedzinaZbiorWartosci(double x1, double y1, double x2, double y2) {
	if (x1 < x2) {
		cout << "Df x = <" << x1 << ", " << x2 << ">" << endl;
	}
	else if (x1 > x2) {
		cout << "Df x= <" << x2 << ", " << x1 << ">" << endl;
	}
	else {
		cout << "Df x = " << x1 << endl;
	}
	
	if (y1 < y2) {
		cout << "Zw = <" << y1 << ", " << y2 << ">" << endl;
	}
	else if (y1 > y2) {
		cout << "Zw = <" << y2 << ", " << y1 << ">" << endl;
	}
	else {
		cout << "Zw = " << y1 << endl;
	} 
}

// Funkcja licząca dla których x y jest ujemne i dodatnie
void yUjemneDodatnieX(double a, double b, double x1, double y1, double x2, double y2, double miejscezerowe) {
   miejscezerowe = b*(-1)/a;
		if (x1 <= miejscezerowe && x2 <= miejscezerowe) {
			if (x1 < x2) {
				if (miejscezerowe == x1) {
					cout << "Y ujemne dla x = <" << x2 << ", " << miejscezerowe << ")" << endl;
				}
				else if (miejscezerowe == x2) {
					cout << "Y ujemne dla x = <" << x1 << ", " << miejscezerowe << ")" << endl;
				}
				else {
					cout << "Y ujemne dla x = <" << x1 << ", " << x2 << ">" << endl;
				}
			}				
			else if (x2 < x1) {
				if (miejscezerowe == x1) {
					cout << "Y ujemne dla x = <" << x2 << ", " << miejscezerowe << ")" << endl;
				}
				else if (miejscezerowe == x2) {
					cout << "Y ujemne dla x = <" << x1 << ", " << miejscezerowe << ")" << endl;
				}
				else {
					cout << "Y ujemne dla x = <" << x1 << ", " << x2 << ">" << endl;
				}
			}
		}
		else if (x1 >= miejscezerowe && x2 >= miejscezerowe) {
			if (x1 < x2) {
				if (miejscezerowe == x1) {
					cout << "Y dodatnie dla x = <" << miejscezerowe << ", " << x2 << ")" << endl;
				}
				else if (miejscezerowe == x2) {
					cout << "Y dodatnie dla x = <" << miejscezerowe << ", " << x1 << ")" << endl;
				}
				else {
					cout << "Y dodatnie dla x = <" << x1 << ", " << x2 << ">" << endl;
				}
			}				
			else if (x2 < x1) {
				if (miejscezerowe == x1) {
					cout << "Y dodatnie dla x = <" << miejscezerowe << ", " << x2 << ")" << endl;
				}
				else if (miejscezerowe == x2) {
					cout << "Y dodatnie dla x = <" << miejscezerowe << ", " << x1 << ")" << endl;
				}
				else {
					cout << "Y dodatnie dla x = <" << x2 << ", " << x1 << ">" << endl;
				}
			}
		}
		else {
			if (x2 < x1) {
				cout << "Y ujemne dla x = <" << x2 << ", " << miejscezerowe << ")" << endl;
				cout << "Y dodatnie dla x = (" << miejscezerowe << ", " << x1 << ">" << endl;
				}
			else if (x2 > x1) {
				cout << "Y ujemne dla x = <" << x1 << ", " << miejscezerowe << ")" << endl;
				cout << "Y dodatnie dla x = (" << miejscezerowe << ", " << x2 << ">" << endl;	
			}
		}
}

// Funkcja licząca miejsce zerowe
void miejscazerowe(double a, double b, double x1, double y1, double x2, double y2, double miejscezerowe) {
   	miejscezerowe = b*(-1)/a;
	if (x1 == miejscezerowe || x2 == miejscezerowe) {
		cout << "Miejsce zerowe: " << miejscezerowe << endl;
	}
	else if (((x1>=0&&x2>=0) || (x1<=0&&x2<=0)) || (miejscezerowe>x1)&&(miejscezerowe>x2) || (miejscezerowe<x1)&&(miejscezerowe<x2)) {
		cout << "Brak miejsc zerowych!" << endl;		
   	}
	else {
		cout << "Miejsce zerowe: " << miejscezerowe << endl;
   }
   
}

// Funkcja licząca argumenty dla wartości
void liczenieArgDlaWar(double a, double b, int wybor, double x, double y, bool petla, int kontynuacja, double x1, double y1, double x2, double y2) {
	cout << "Podaj wartosc (y): " << endl;
	cin >> y;
	x = (y - b) / a;
	if ((x<x1&&y<x2) || (x>x1&&x>x2)) {
		cout << "Poza dziedzina!" << endl;
	}
	else {
		cout << y <<" = f(" << x << ")" <<endl;	
	}	
}

// Funkcja licząca argumenty dla wartości
void liczenieWarDlaArg(double a, double b, int wybor, double x, double y, bool petla, int kontynuacja, double x1, double y1, double x2, double y2) {
	cout << "Podaj argument (x): " << endl;
	cin >> x;
	y = (a*x) + b;
	if ((y<y1&&y<y2) || (y>y1&&y>y2)) {
		cout << "Poza dziedzina!" << endl;
	}
	else {
		cout << "f(" << x << ") = " << y <<endl;
	}	
}

// Główna pętla kodu
int main() {
	
    // Zmienne
    double x1, y1, x2, y2, a = 0, b = 0, x, y, miejscezerowe;
    int wybor, kontynuacja;
    bool petla = true;

    // Głowny kod
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
	monotonicznosc(a, x1, x2, y1, y2);	
	dziedzinaZbiorWartosci(x1, y1, x2, y2);
	yUjemneDodatnieX(a, b, x1, y1, x2, y2, miejscezerowe);
	miejscazerowe(a, b, x1, y1, x2, y2, miejscezerowe);
	while (petla) {
        cout << "Wybierz opcje: " << endl;
        cout << "- 1 - liczenie argumentu dla wartosci" << endl;
        cout << "- 2 - liczenie wartosci dla argumentu" << endl;
        cout << "- 3 - zakoncz dzialanie programu" << endl;
        cin >> wybor;

        switch (wybor) {
            case 1:
                liczenieArgDlaWar(a, b, wybor, x, y, petla, kontynuacja, x1, y2, x2, y2);
                break;
            case 2:
                liczenieWarDlaArg(a, b, wybor, x, y, petla, kontynuacja, x1, y2, x2, y2);
                break;

            case 3:
                petla = false;  
                break;

            default:
                cout << "Niepoprawny wybór." << endl;
                break;
        }
    }
	cout << "=-=-=-=-= Koniec =-=-=-=" << endl;	
		return 0;
}
