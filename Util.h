#pragma once
#include "Product.h"
class Util
{
public:
	int count_structs(char* filename);
	void print(Product* products, int n);
	Product* open(Product* product, int& size, char filename[]);
	void save(Product* products, int n, char filename[]);
	Product* add(Product* products, int& n);
	int find(Product* products, int n);
	Product* correct(Product* products, int n);
	Product* deletet(Product* products, int& n);
	const int N = 100;
};

