#pragma once
#include <string>
#include <iostream>

using std::string;

class Product {
public:

	void setName(string name) {
		this->name = name;
	}

	void setPrice(double price) {
		this->price = price;
	}

	void setTTH(string tTH) {
		this->tTH = tTH;
	}

	void setK(int k) {
		this->k = k;
	}

	string getName() {
		return name;
	}

	double getPrice() {
		return price;
	}

	string getTTH() {
		return tTH;
	}

	int getK() {
		return k;
	}

	friend std::ostream& operator<< (std::ostream& out, const Product& product);
	friend std::istream& operator>> (std::istream& in, Product& product);

private:

	string name;
	double price;
	string tTH;
	int k;
};