#ifndef MY_STRING_H
#define MY_STRING_H

class MyString
{
public:
	MyString();//Конструктор стандартный 
	MyString(const char* str); //Конструктор для текста
	~MyString(); //Диструктор

	MyString(const MyString& other); //Конструктор копирования

	MyString& operator =(const MyString& other); //Перегрузка оператора =

	MyString operator +(const MyString& other); //Перегрузка оператора +

	bool operator==(const MyString& other); //Перегрузка оператора ==
	bool operator != (const MyString& other); //Перегрузка оператора !=

	bool operator > (const MyString& other); //Перегрузка оператора >
	bool operator >= (const MyString& other); //Перегрузка оператора >=
	bool operator < (const MyString& other); //Перегрузка оператора <
	bool operator <= (const MyString& other); //Перегрузка оператора <=

	char& operator [] (const int index); //Перегрузка оператора []

	void print();
private:
	char* str;
};
#endif // !MY_STRING_H

