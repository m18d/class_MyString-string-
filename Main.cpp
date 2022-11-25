#include<iostream>
#include"MyString.h"


using namespace std;




int main()
{
	MyString str("string");
	MyString str2(str);
	str2.print();

	return 0;
}