#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int ves, osi;
	double nagruz, norma;

	cout << "добро пожаловать" << endl;
	cout << "введи вес поезда:";
	cin >> ves;
	cout << "введи оси:";
	cin >> osi;
	cout << "нагрузка на ось:";
	nagruz = (double)ves / (double)osi;
	cout << nagruz << endl;
	cout << "ищем в гугле нормы" << endl;

	double VLKabel[2][21] =
		{ {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25},
	{36.26, 31.42, 27.95, 25.35, 23.33, 21.71, 20.39, 19.28, 18.35, 17.56, 16.87, 16.26, 15.72,
	 15.25, 14.81, 14.44, 14.10, 13.76, 13.48, 13.21, 12.97}
	};
	if (round(nagruz) < 5 || round(nagruz) > 21)
	{

	}
	else
	{
		for (int j = 0; j < 21; j++)
		{
			cout << VLKabel[0][j] << "|";
			cout << VLKabel[1][j] << endl;
			if (round(nagruz) >= VLKabel[0][j] && round(nagruz) < VLKabel[0][j + 1])
			{

				cout << "^наш клиент " << round(nagruz) << endl;
			}
		}
	}
	return 0;

}