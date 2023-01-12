#include <iostream>
#include <cstdlib>
#include <time.h>
#include <Windows.h>
#include <fstream>
#include <string>
#include <exception>
#include <memory>
#include<ctime>

using namespace std;

int los();
int getSzyfr();
string plik();
string getNazwaPliku();
string getHaslo();
string szyfrowanie(int wybor, string haslo, int randNum);
string getZapis();
void zapis(string zaszyfrowaneHaslo);

int main()
{
	system("chcp 1250");
	system("cls");
	int wybor = 0;
	int randNum = los();
	
	while (true)
	{
		wybor = getSzyfr();
		//TEN IF JEST, ŻEBY PROGRAM WYŁĄCZYŁ SIĘ NATYCHMIAST PO WYBRANIU 4, A NIE PO JEDNYM OBROCIE
		if (wybor == 4)
		{
			exit(0);
		}
		else
		{
			string plik2 = plik();
			string hasloPlik;

			if (plik2 == "TAK" || plik2 == "tak" || plik2 == "Tak" || plik2 == "t" || plik2 == "T" || plik2 == "y" || plik2 == "Y" || plik2 == "yes" || plik2 == "Yes" || plik2 == "YES")
			{
				fstream file;
				file.open(getNazwaPliku(), ios::in);
				if (file.good())
				{
					while (!file.eof())
					{
						getline(file, hasloPlik); 
						cout << "HASŁEM JEST: " << hasloPlik << endl;
					}
				}
				else
				{
					cout << "Nie udało się otworzyć pliku :/ \n";
					cout << "Spróbuj ponownie! \n";
					cout << "PLIK MUSI MIEĆ FORMAT .txt! \n";
					exit(0);
				}
				cout << endl;
				file.close();

				string szyfr = szyfrowanie(wybor, hasloPlik, randNum);
				zapis(szyfr);
			}
			else
			{
				string haslo = getHaslo();
				cout << "Twoim Tajemniczym Mysim Szyfrem Spacji jest: " << randNum << " <- ASCII : CHAR -> " << (char)randNum << endl << endl;
				string szyfr = szyfrowanie(wybor, haslo, randNum);
				zapis(szyfr);
			}
		}
	} 
}

int los()
{
	srand(time(NULL));
	int tajemniczyMysiZnak = rand() % 127;

	if (tajemniczyMysiZnak < 33)
	{
		tajemniczyMysiZnak += 65;
	}
	/*
	if (tajemniczyMysiZnak > 65)
	{
		tajemniczyMysiZnak += 65;
	*/
	//cout << "Spacja to: " << tajemniczyMysiZnak << " " << (char)tajemniczyMysiZnak << endl;
	return tajemniczyMysiZnak;
}

int getSzyfr()
{
	int wybor = 0;
	cout << "Wybierz swój szyfr: \n";
	cout << "1. NOWE BUTY LISA \n";
	cout << "2. SZYFR CEZARA \n";
	cout << "3. KACEMINUTOWY \n";
	cout << "4. ZAKOŃCZ SZYFROWANIE \n";
	cin >> wybor;

	system("cls");

	switch (wybor)
	{
	case 1:
		cout << "Wybrałeś NOWE BUTY LISA \n";
		break;
	case 2:
		cout << "Wybrałeś SZYFR CEZARA \n";
		break;
	case 3:
		cout << "Wybrałeś KACEMINUTOWY \n";
		break;
	case 4:
		cout << "ZAKOŃCZYŁEŚ SZYFROWANIE \n";
		break;
	default:
		cout << "Nosz kurwa od 1 do 4 \n";
		exit(0);
	}
	cout << endl;
	return wybor;
}

string plik()
{
	string wczytywanie;
	cout << "Czy chcesz wczytać hasło z pliku? \n";
	cout << "TAK/NIE \n";
	cin >> wczytywanie;
	//cout << wczytywanie << "\n";
	system("cls");
	return wczytywanie;
}

string getNazwaPliku()
{
	string nazwaPliku;
	cout << "PODAJ NAZWĘ PLIKU BEZ ROZSZERZENIA \n";
	cin >> nazwaPliku;
	/*
	int i = nazwaPliku.length();
	if (nazwaPliku[i-4] == '.')
	{
		if (nazwaPliku[i + 1] == 't' && nazwaPliku[i + 2] == 'x' && nazwaPliku[i + 3] == 't')
		{
			cout << "TWÓJ PLIK TO: " << nazwaPliku << "\n";
		}
		else
		{
			cout << "Wymagany plik w formacie txt!";
			exit(0);
		}
	}
	else
	{
		nazwaPliku += ".txt";
		cout << "TWÓJ PLIK TO: " << nazwaPliku << "\n";
	}
	*/
	nazwaPliku += ".txt";
	//int i = nazwaPliku.length();
	//cout << "Plik ma długość: " << i << endl;
	//cout << nazwaPliku[i-4];
	system("cls");
	return nazwaPliku;
}

string getHaslo()
{
	int i = 0;
	string haslo;
	string temp;
	cout << "NIE POSIADASZ PLIKU DO WCZYTANIA \n";
	cout << "WPISZ SWOJE HASŁO: \n";
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	getline(cin, haslo);
	int dupa = 0;

	system("cls");

	cout << "TWOJE HASŁO TO: " << haslo << "\n";
	return haslo;
}

string szyfrowanie(int wybor, string haslo, int randNum)
{
	string szyfr;
	switch (wybor)
	{
	case 1:
		//NO-WE-BU-TY LI-SA
		for (int i = 0; i < haslo.length(); i++)
		{
			//N n
			if ((int)haslo[i] == 78)
				haslo[i] = 'O';
			if ((int)haslo[i] == 110)
				haslo[i] = 'o';

			//O o
			if ((int)haslo[i] == 79)
				haslo[i] = 'N';
			if ((int)haslo[i] == 111)
				haslo[i] = 'n';

			//W w
			if ((int)haslo[i] == 87)
				haslo[i] = 'E';
			if ((int)haslo[i] == 119)
				haslo[i] = 'e';
			
			//E e
			if ((int)haslo[i] == 69)
				haslo[i] = 'W';
			if ((int)haslo[i] == 101)
				haslo[i] = 'w';

			//B b
			if ((int)haslo[i] == 66)
				haslo[i] = 'U';
			if ((int)haslo[i] == 98)
				haslo[i] = 'u';


			//U u
			if ((int)haslo[i] == 85)
				haslo[i] = 'B';
			if ((int)haslo[i] == 117)
				haslo[i] = 'b';

			//T t
			if ((int)haslo[i] == 84)
				haslo[i] = 'Y';
			if ((int)haslo[i] == 116)
				haslo[i] = 'y';

			//Y y
			if ((int)haslo[i] == 89)
				haslo[i] = 'T';
			if ((int)haslo[i] == 121)
				haslo[i] = 't';

			//L l
			if ((int)haslo[i] == 76)
				haslo[i] = 'I';
			if ((int)haslo[i] == 108)
				haslo[i] = 'i';

			//I i
			if ((int)haslo[i] == 73)
				haslo[i] = 'L';
			if ((int)haslo[i] == 105)
				haslo[i] = 'l';

			//S s
			if ((int)haslo[i] == 83)
				haslo[i] = 'A';
			if ((int)haslo[i] == 115)
				haslo[i] = 'a';

			//A a
			if ((int)haslo[i] == 65)
				haslo[i] = 'S';
			if ((int)haslo[i] == 97)
				haslo[i] = 's';

			//DLA SPACJI
			if ((int)haslo[i] == 32)
				haslo[i] = randNum;
		}
		szyfr = haslo;
		cout << "Zaszyfrowanym hasłem jest: " << szyfr << endl << endl;
		break;
	case 2:
		//SZYFR CEZARA
		for (int i = 0; i < haslo.length(); i++)
		{
			haslo[i] = (int)haslo[i] + 3;
		}
		szyfr = haslo;
		cout << "Zaszyfrowanym hasłem jest: " << szyfr << endl << endl;
		break;
	case 3:
		//KA-CE-MI-NU-TO-WY;
		for (int i = 0; i < haslo.length(); i++)
		{
			//K k
			if ((int)haslo[i] == 75)
				haslo[i] = 'A';
			if ((int)haslo[i] == 107)
				haslo[i] = 'a';

			//A a
			if ((int)haslo[i] == 65)
				haslo[i] = 'K';
			if ((int)haslo[i] == 97)
				haslo[i] = 'k';
			
			//C c
			if ((int)haslo[i] == 67)
				haslo[i] = 'E';
			if ((int)haslo[i] == 99)
				haslo[i] = 'e';

			//E e
			if ((int)haslo[i] == 69)
				haslo[i] = 'C';
			if ((int)haslo[i] == 101)
				haslo[i] = 'c';

			//M m
			if ((int)haslo[i] == 77)
				haslo[i] = 'I';
			if ((int)haslo[i] == 109)
				haslo[i] = 'i';

			//I i
			if ((int)haslo[i] == 73)
				haslo[i] = 'M';
			if ((int)haslo[i] == 105)
				haslo[i] = 'm';

			//N n
			if ((int)haslo[i] == 78)
				haslo[i] = 'U';
			if ((int)haslo[i] == 110)
				haslo[i] = 'u';

			//U u
			if ((int)haslo[i] == 85)
				haslo[i] = 'N';
			if ((int)haslo[i] == 117)
				haslo[i] = 'n';

			//T t
			if ((int)haslo[i] == 84)
				haslo[i] = 'O';
			if ((int)haslo[i] == 116)
				haslo[i] = 'o';

			//O o
			if ((int)haslo[i] == 79)
				haslo[i] = 'T';
			if ((int)haslo[i] == 111)
				haslo[i] = 't';

			//W w
			if ((int)haslo[i] == 87)
				haslo[i] = 'Y';
			if ((int)haslo[i] == 119)
				haslo[i] = 'y';

			//Y y
			if ((int)haslo[i] == 89)
				haslo[i] = 'W';
			if ((int)haslo[i] == 121)
				haslo[i] = 'w';

			//Spacja
			if ((int)haslo[i] == 32)
				haslo[i] = randNum;
		}
		szyfr = haslo;
		cout << "Zaszyfrowanym hasłem jest: " << szyfr << endl << endl;
		break;
	case 4:
		cout << "ZAKOŃCZYŁEŚ SZYFROWANIE \n";
		break;
	default:
		cout << "Nosz kurwa od 1 do 4 \n";
		exit(0);
	}
	return szyfr;
}

string getZapis()
{
	string nazwaPliku;
	cout << "PODAJ NAZWĘ PLIKU BEZ ROZSZERZENIA \n";
	cin >> nazwaPliku;
	nazwaPliku += ".txt";
	system("cls");
	cout << "HASŁO ZOSTAŁO ZAPISANE W PLIKU: " << nazwaPliku << endl << endl;
	return nazwaPliku;
}

void zapis(string zaszyfrowaneHaslo)
{
	string zapis;
	cout << "CZY CHCESZ ZAPISAĆ SWÓJ SZYFR? \n \n";
	cout << "!UWAGA! \n";
	cout << "PLIK DOCELOWY ZOSTANIE NADPISANY! \n";
	cout << "TAK/NIE \n";
	cin >> zapis;
	
	system("cls");

	if (zapis == "TAK" || zapis == "tak" || zapis == "Tak" || zapis == "t" || zapis == "T" || zapis == "y" || zapis == "Y" || zapis == "yes" || zapis == "Yes" || zapis == "YES")
	{
		fstream file;
		file.open(getZapis(), ios::out);

		file << zaszyfrowaneHaslo;
		//cout << zaszyfrowaneHaslo;

		file.close();
	}
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
	cout <<"Nie udało się otworzyć pliku :/"
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
	}
}
else
{
	cout <<"Nie udało się otworzyć pliku :/"
}
file.close();
*/