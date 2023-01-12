#include <iostream>
#include <cstdlib>
#include <time.h>
#include <Windows.h>
#include <fstream>
#include <string>
#include <exception>
#include <memory>

using namespace std;


//KLUCZ SZYFRU:
//B 98/66=H 72
//U 117=U 117
//T 116/84=J 74


string plik();
string getHaslo();
string getNazwaPliku();
int getSzyfr();


int main()
{
	system("chcp 1250");
	system("cls");

	while (getSzyfr() != 4)
	{
		if (plik() == "TAK" || plik() == "tak" || plik() == "Tak" || plik() == "t" || plik() == "T" || plik() == "y" || plik() == "Y" || plik() == "yes" || plik() == "Yes" || plik() == "YES")
		{
			getNazwaPliku();
			string nazwaPliku = getNazwaPliku();
			cout << nazwaPliku;

			fstream file;
			file.open(nazwaPliku, ios::in);
			if (file.good())
			{
				while (!file.eof())
				{
					string s;
					getline(file, s);
					cout << s;
				}
				cout << endl;
			}
			else
			{
				cout << "Nie uda³o siê otworzyæ pliku :/ \n";
			}
			file.close();
		}
		else
		{
			getHaslo();
		}
	}
}

string plik()
{
	string wczytywanie;
	cout << "Czy chcesz wczytaæ has³o z pliku? \n";
	cout << "TAK/NIE \n";
	cin >> wczytywanie;
	cout << wczytywanie << "\n";
	return wczytywanie;
}

string getHaslo()
{
	string haslo;
	cout << "NIE POSIADASZ PLIKU DO WCZYTANIA \n";
	cout << "PODAJ HAS£O, KTÓRE CHCESZ ZASZYFROWAÆ: \n";
	cin >> haslo;
	//system("cls");
	cout << "TWOJE HAS£O TO: " << haslo << "\n";
	return haslo;
}

string getNazwaPliku()
{
	string nazwaPliku;
	cout << "PODAJ NAZWÊ PLIKU BEZ ROZSZERZENIA \n";
	cin >> nazwaPliku;
	nazwaPliku += ".txt";
	//system("cls");
	cout << "TWÓJ PLIK TO: " << nazwaPliku << "\n";
	return nazwaPliku;
}

int getSzyfr()
{
	int wybor = 0;
	cout << "Wybierz swój szyfr: \n";
	cout << "1. NOWE BUTY LISA \n";
	cout << "2. SZYFR CEZARA\n";
	cout << "3. KACEMINUTOWY\n";
	cout << "4. ZAKOÑCZ SZYFROWANIE \n";
	cin >> wybor;

	//system("cls");

	switch (wybor)
	{
	case 1:
		cout << "Wybra³eœ NOWE BUTY LISA \n";
		break;
	case 2:
		cout << "Wybra³eœ SZYFR CEZARA \n";
		break;
	case 3:
		cout << "Wybra³eœ KACEMINUTOWY \n";
		break;
	case 4:
		cout << "ZAKOÑCZY£EŒ SZYFROWANIE \n";
		break;
	default:
		cout << "Nosz kurwa od 1 do 4\n";
		exit(0);
	}
	return wybor;
}


//POLIGON
/*
	string a = "BUT";
	cout << a << "\n";
	for (int i = 0; i < a.length(); i++)
	{
		//cout << (int)a[i] << " ";
		if ((int)a[i] == 98 || (int)a[i] == 66)
			a[i] = 'H';
		//(int)a[i]=72
		if ((int)a[i] == 116 || (int)a[i] == 84)
			a[i] = 'J';
		//(int)a[i] = 74
	}
	cout << a << "\n";

//ZAPIS DO PLIKU PLIKÓW
/*
fstream file;
file.open("test.txt", ios::out);
if (file.good())
{
	string napis;
	getline(cin, napis)
	cout << napis;
}
else
{
	cout <<"Nie uda³o siê otworzyæ pliku :/"
}
file.close();
*/

//WCZYTYWANIE Z PLIKU
/*
fstream file;
file.open("test.txt", ios::in);
if (file.good())
{
	while (!plik.eof())
	{
		//WCZYTYWANIE STRINGÓW
		string s;
		getline(plik,s);
		cout << s;

		//WCZYTYWANIE CYFEREK
		int a;
		plik >> a;
		cout << a;
	}
}
else
{
	cout <<"Nie uda³o siê otworzyæ pliku :/"
}
file.close();
*/
