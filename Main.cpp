#define _CRT_SECURE_NO_WARNINGS
#include "Util.h"
#include <iostream>
using std::cout;
using std::cin;

int main(int argc, char* argv[1]) {

        setlocale(LC_ALL, "RUSSIAN");
	Util utilita;
	int size = 0;
	Product* products = new Product[0];
	products = utilita.open(products, size, argv[1]);
	int t = 0;
	do {
		utilita.print(products, size);
		cout << "\n1. Добавить \n2. Поиск\n3. Редактирование\n4. Удаление\n5. Открыть файл\n6. Сохранить в файл\n\n» ";
		cin >> t;
		switch (t) {
		case 1: products = utilita.add(products, size); break;
		case 2: t = utilita.find(products, size);
			if (t != -1) {
				cout << "Запись найдена при индексе" << t << "\nЗапись: " << products[t];
			}
			else {
				cout << "Запись не найдена";
			}
			break;
		case 3: products = utilita.correct(products, size); break;
		case 4: products = utilita.deletet(products, size); break;
		case 5: products = utilita.open(products, size, argv[1]); break;
		case 6: utilita.save(products, size, argv[1]); break;
		}
	} while (t != 0);
}
