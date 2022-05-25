#include <iostream>
#include <string>
using namespace std;


/*
	1. возможность создания от класса std::string
	2. операторы к реализации: ==, +=, !
	3. доступ к отдельным символам строки
		std::string str{"qwerty"};
		str[2]
		str.at(2);
	4. предоставлять доступ к сырым данным
*/

class String {
public:
	String():data(nullptr),size(0),capacity(0)
	{

		cout << this << " Base object created\n";
	}

	String(string str): String() {
		//узнать сколько символов в str
		capacity = str.size();
		size = str.size();
		//выделить под них память
		data = new char[size] {};
		//скопировать данные из str
		::memcpy(data, &(str[0]), size);

	}

	//операторы
	bool operator==(const String&& other) {
		if (this->size != other.size) return false;
		for (int i = 0; i < this->size; i++){
			if (this->data[i] != other.data[i]) return false;
		}
		return true;
	}

	bool operator!=(const String&& other) {
		if (this->size == other.size) return false;
		for (int i = 0; i < this->size; i++) {
			if (this->data[i] == other.data[i]) return false;
		}
		return true;
	}

	bool operator+=();


	//bool operator!();
	operator (bool)(String str);
	char& operator[](int i);
	const char& operator[](int i)const;

	explicit String(int length) : String() {
		capacity = length;
		data = new char[length] {};
		//size = 0;
	}
	String(const char* str) {
		size = ::strlen(str)+1;
		capacity = size;
		data = new char[size] {};
		::memcpy(data, str, size);
	}

	String(const String& other) {
		size = other.size;
		capacity = other.capacity;
		data = new char[other.size] {};
		::memcpy(data, other.data, size);
		cout << this << " Base object created by copy\n";
	}

	String(String&& other):String() {
		swap(data, other.data);
		size = other.size;
		other.size = 0;
		swap(capacity, other.capacity);
	}

	const String& operator = (const String& other) {
		if (capacity >= other.size) {
			for (int i = 0; i < size; i++){
				data[i] = '\0';
			}
		}else
		{ 
			if (data) {
				delete[] data;
			}
			data = new char[other.size + 1];
			capacity = other.size + 1;
		}
		size = other.size;
		::memcpy(data, other.data, size);
		//процесс копирования
		return *this;
	}

	~String(){
		if (data) {
			delete[] data;
		}
		cout << this << " Base object destroyed\n";
	}

	void setString(const char* str) {
		(*this) = String(str);
	}

	friend String operator+(String a, String b) {
		String result(a.size + b.size);
		::memcpy(result.data, a.data, a.size);
		::memcpy(result.data + a.size, b.data, b.size);
		result.size = a.size + b.size;
		return result;
	}
private:
	char* data;
	int size;
	int capacity;
};

void F00(String obj) {

}

int main() {
	setlocale(LC_ALL, "Russian");

	String a;
	String b(5);
	//a = b = static_cast<String>(8);
	a = move(String("qwerty0") + String("asdfg"));
	String * point = new String(4);
	F00(b);
	delete point;
	double r = (1 / double(6));
	double e;
	e = r = 5.6;
	return 0;
}