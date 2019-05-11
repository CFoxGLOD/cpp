#include <iostream>
#include <math.h>

using namespace std;

struct uchastok
{
	double koeff[2][21];
	double trogan;
	int kilom;
	string name;
};

uchastok VlRg;
uchastok VlRez;
uchastok SebRez;
uchastok VlSeb;

double oilcalc(uchastok);
void printKoeff(uchastok);
double nagruzka(int ves);
double sgorelOil();

int main()
{
	double kiloA, kiloB;
	cout << "\033[35mпишем соляру на А\033[0m" << endl;
	kiloA = sgorelOil();
	cout << "\033[35mпишем соляру на Б\033[0m" << endl;
	kiloB = sgorelOil();
	double nagruz, norma;
	cout << "добро пожаловать" << endl;
	VlRg =
	{
	5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 36.26,
			31.42, 27.95, 25.35, 23.33, 21.71, 20.39, 19.28, 18.35, 17.56, 16.87, 16.26, 15.72,
			15.25, 14.81, 14.44, 14.10, 13.76, 13.48, 13.21, 12.97};
	VlRg.trogan = 8.07;
	VlRg.kilom = 241;
	VlRg.name = "ржевский ход";
	VlRez =
	{
	5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 42.94,
			37.21, 33.09, 30.02, 27.62, 25.70, 24.15, 22.83, 21.73, 20.79, 19.97, 19.25, 18.61,
			18.05, 17.53, 17.10, 16.70, 16.30, 15.96, 15.64, 15.36};
	VlRez.trogan = 6.93;
	VlRez.kilom = 222;
	VlRez.name = "с лук до резекне";
	SebRez =
	{
	5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 40.42,
			35.02, 31.15, 28.25, 26.00, 24.19, 22.73, 21.49, 20.45, 19.57, 18.80, 18.12, 17.52,
			16.99, 16.51, 16.09, 15.72, 15.34, 15.02, 14.72, 14.46};
	SebRez.trogan = 6.36;
	SebRez.kilom = 82;
	SebRez.name = "себеж-резекне";
	VlSeb =
	{
	5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 44.75,
			38.78, 34.49, 31.29, 28.79, 26.79, 25.17, 23.79, 22.65, 21.67, 20.82, 20.07, 19.40,
			18.82, 18.28, 17.82, 17.40, 16.99, 16.63, 16.30, 16.01};
	VlSeb.trogan = 7.12;
	VlSeb.kilom = 140;
	VlSeb.name = "луки-себеж";
//	system("cls");
	int menu;
	cout << "плечо какое?" << endl;
	cout << "1 ржевское" << endl;
	cout << "2 лабусовское" << endl;
	cout << "3 до себежа" << endl;
	cout << "4 себеж-резекне" << endl;
	cin >> menu;
	switch (menu)
	{
	case 1:
		cout << oilcalc(VlRg);
		break;
	case 2:
		cout << oilcalc(VlRez);
		break;
	case 3:
		cout << oilcalc(VlSeb);
		break;
	case 4:
		cout << oilcalc(SebRez);
		break;
	default:
		cout << "проспись, таких цифр тут нет";
	}
	return 0;

}

double oilcalc(uchastok uch)
{
	double tmp;
	cout << "выбран " << uch.name << endl;
	int ves;
	cout << "введи вес поезда:";
	cin >> ves;
	double nagruz = nagruzka(ves);
	if (nagruz < 5 || nagruz > 25)
	{
		if (round(nagruz) < 5)
		{
			cout << "воздушный шар везешь? Нагрузка на ось: " <<
				nagruz << endl;
		}
		if (round(nagruz) > 21)
		{
			cout << "Эверест спиздил? Нагрузка на ось:" << nagruz <<
				endl;
			return 0;
		}
	}
	else
	{
		for (int j = 0; j < 21; j++)
		{
			// cout << uch.koeff[0][j] << "|";
			// cout << uch.koeff[1][j] << endl;
			if (round(nagruz) >= uch.koeff[0][j] && round(nagruz) < uch.koeff[0][j + 1])
			{

				cout << "наш клиент по табличке: " << round(nagruz) << endl;
				tmp = uch.koeff[1][j];
				cout << "коэффициент: " << tmp << endl;
			}
		}
	}
	return tmp * ves * uch.kilom / 10000;

}

void printKoeff(uchastok uch)
{
	for (int i = 0; i < 21; i++)
	{
		cout << uch.koeff[0][i] << "|";
		cout << uch.koeff[1][i] << endl;
	}
	cout << "трогание:" << uch.trogan << endl;
	cout << "киллометраж:" << uch.kilom << endl;
}

double nagruzka(int ves)
{
	int osi;
	cout << "введи оси:";
	cin >> osi;
	cout << "нагрузка:" << (double)ves / (double)osi << endl;
	return (double)ves / (double)osi;
}

double sgorelOil()
{
	double pr, sd, koeff, prKg, sdKg;
	cout << "скок принял:";
	cin >> pr;
	cout << "скок сдал:";
	cin >> sd;
	cout << "плотность х1000:";
	cin >> koeff;
	koeff /= 1000;
	cout << "\033[32mпринял в КГ:\t" << pr * koeff << endl;
	cout << "\033[31mсдал в КГ:\t" << sd * koeff << endl;
	cout << "\033[0mушло в литрах:\t" << pr - sd << endl;
	 cout << "спалил в КГ:\t" << pr * koeff - sd * koeff << endl;
}