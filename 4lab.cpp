/*Вариант 12
Объект для разработки структуры – ноутбук.
Объявить поля:
– Название фирмы
– Вес
– Цена.
_________________________________________
Для разработанной ранее структуры написать и протестировать
функции:
- Выборка из массива структур по указанным ключам (по
вариантам). Функция должна вывести на экран найденные
структуры, а в качестве результата передает сигнал, найдены ли
структуры.
Объект для разработки структуры – ноутбук.
Произвести выборку ноутбуков, чей вес и цена не превышают
заданных величин.
*/
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

struct pc {
	string company;
	double weight;
	double price;
};
void input(pc& p) {
	const int i = 30;
	cout << " Название фирмы: ";
	cin.ignore();
	getline (cin,p.company);
	//cin.ignore();
	//cin >> p.company;
	cout << " Вес: ";
	cin >> p.weight;
	cout << " Цена: ";
	cin >> p.price;


}

void output(const pc& p) {
	cout << " Название фирмы: ";
	cout << p.company;
	cout << endl << " Вес: ";
	cout << p.weight;
	cout << endl << " Цена: ";
	cout << p.price << endl;
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool flag = false;
	int lenghtar;//array lenght
	cout << "Добро пожаловать в систему учета данных ноутбуков." << endl;
	cout << "   Сколько ноутбуков будем регистрировать : ";
	cin >> lenghtar;
	pc* laptop = new pc[lenghtar];

	int var = 0;
	string otv;
	double lw;
	double lp;
	cout << "	Меню" << endl;
	cout << "	1.Ввод в систему." << endl;
	cout << "	2.Выход из системы." << endl;
	cin >> var;
	if (var == 1) {
		//input
		system("color 2");
		int count = 0;
		for (int i = 0; i < lenghtar;i++) {
			cout << endl;
			count++;
			cout << "Ноутбук № " << count << endl;
			input(laptop[i]);
		}

		//sorted output
		cout << "Хотите продолжить сортировку введенной информации или покинуть программу ?"<<endl;
		cout << "yes/no: ";
		cin >> otv;
		
		if (otv == "yes" || otv == "no") {
			if (otv == "yes") {
				cout <<endl << "Введите максимальный возможный вес ноутбука: ";
				cin >> lw;
				cout << "Введите максимальный возможyю цену ноутбука: ";
				cin >> lp;
				int count = 0;
				cout <<endl << "Отсортированный вывод." << endl << endl;
				cout << "Название фирмы ноутбуков цены и вес котрых не превышает введенных значений! " << endl;

				for (int i = 0;i < lenghtar;i++) {
					count++;
					if ((laptop[i].weight <= lw) and (laptop[i].price <= lp)) 
					{	
						flag == true;
						cout << "Ноутбук № " << count << endl;
						output(laptop[i]);
						cout << endl;
						
					}
				}
				if (flag == false) {
					cout << endl << "По данным критериям не наййдены ноутубки!";
				}
				cout << endl << "Выполнено....";
			}
			if (otv == "no")
				return 0;
		}
		else {
			system("color 2");
			cout << "Error....";
			Sleep(500);
			return 0;
		}
			

	}
	else {
		cout << endl << endl << "Выход....";
		Sleep(1200);
		return 0;
	}
	return 0;
}
	