#include "Product.h"

std::ostream& operator<< (std::ostream& out, const Product& product)
{
	out << product.name << ", цена: " << product.price << ", TTX: " << product.tTH << ", кол-во: " << product.k << "\n";

	return out;
}

std::istream& operator>>(std::istream& in, Product& product)
{
	std::cout << "Название: ";
	in >> product.name;
	std::cout << "Цега: ";
	in >> product.price;
	std::cout << "Описание: ";
	in >> product.tTH;
	std::cout << "Количество: ";
	in >> product.k;

	return in;
}
