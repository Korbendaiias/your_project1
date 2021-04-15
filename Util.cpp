#include "Util.h"
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;

void Util::print(Product* product, int n) {
	if (n == 0) {
		cout << ("Нет записей\n");
	}
	for (int i = 0; i < n; i++) {
		cout << product[i];
	}
}

void Util::save(Product* product, int n, char filename[]) {
	ofstream file(filename);
	for (int i = 0; i < n; i++) {
		if (i != (n - 1)) {
			file << product[i].getName() << "\n" << product[i].getPrice() << "\n" << product[i].getTTH() << "\n" << product[i].getK() << "\n";
		}
		else {
			file << product[i].getName() << "\n" << product[i].getPrice() << "\n" << product[i].getTTH() << "\n" << product[i].getK();
		}
	}
	file.close();;
}

Product* Util::open(Product* product, int& size, char filename[]) {
	size = count_structs(filename);
	if (size == -1) {
		size = 0;
		return new Product[0];
	}
	Product* fileProducts = new Product[size];
	ifstream file(filename);
	if (!file.is_open()) {
		cout << "File no open";
		size = 0;
		return new Product[0];
	}
	string temp;
	for (int i = 0; i < size; i++) {
		getline(file, temp);
		fileProducts[i].setName(temp);
		getline(file, temp);
		fileProducts[i].setPrice(atof(temp.c_str()));
		getline(file, temp);
		fileProducts[i].setTTH(temp);
		getline(file, temp);
		fileProducts[i].setK(atoi(temp.c_str()));
	}
	file.close();
	return fileProducts;
}


Product* Util::add(Product* products, int& n) {
if (n == 100) {
return products;
}

Product newProduct;
cin >> newProduct;
Product* newProducts = new Product[n + 1];
for (int i = 0; i < n; i++) {
newProducts[i] = products[i];
}
newProducts[n] = newProduct;
n++;
return newProducts;
}

int Util::find(Product* products, int n) {
	if (n == 0) {
		cout << "Нет записей\n";
		return -1;
	}
	int fnd = -1;
	string targetComputer = "";
	cout << "Искомый компьютер: ";
	cin >> targetComputer;
	for (int i = 0; i < n; i++) {
		if (products[i].getName() == targetComputer) {
			fnd = i;
			break;
		}
	}

	return fnd;
}

Product* Util::correct(Product* products, int n) {
	if (n == 0) {
		cout << "Нет записей\n";
		return products;
	}

	int target = -1;
	cout << "Номер редактируемого компьютера: ";
	cin >> target;
	if (n < target || target <= 0) {
		cout << "Неверный номер записи\n";
		return products;
	}
	target--;
	cin >> products[target];
	return products;

}

Product* Util::deletet(Product* products, int& n) {
	if (n == 0) {
		cout << "Нет записей\n";
		return products;
	}

	int fnd = -1;
	cout << "Номер удаляемого компьютера: ";
	cin >> fnd;
	if (n < fnd || fnd <= 0) {
		cout << "Неверный номер записи\n";
		return products;
	}
	fnd--;
	Product* newProducts = new Product[n - 1];
	int counter = 0;
	for (int i = 0; i < n; i++) {
		if (i != fnd) {
			newProducts[counter] = products[i];
			counter++;
		}
	}
	n--;
	return newProducts;
}

int Util::count_structs(char* filename)
{
	ifstream source(filename);
	string tempStr = "";
	int i = 0;
	if (!source.is_open()) {
		cout << "File not opened\n";
		return -1;
	}

	while (std::getline(source, tempStr))
	{
		i++;
	}
	source.close();
	if (i % 4 == 0) {
		return i / 4;
	}
	return -1;
}
