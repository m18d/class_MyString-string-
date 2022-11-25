#ifndef MY_STRING_H
#define MY_STRING_H

class MyString
{
public:
	MyString();//����������� ����������� 
	MyString(const char* str); //����������� ��� ������
	~MyString(); //����������

	MyString(const MyString& other); //����������� �����������

	MyString& operator =(const MyString& other); //���������� ��������� =

	MyString operator +(const MyString& other); //���������� ��������� +

	bool operator==(const MyString& other); //���������� ��������� ==
	bool operator != (const MyString& other); //���������� ��������� !=

	bool operator > (const MyString& other); //���������� ��������� >
	bool operator >= (const MyString& other); //���������� ��������� >=
	bool operator < (const MyString& other); //���������� ��������� <
	bool operator <= (const MyString& other); //���������� ��������� <=

	char& operator [] (const int index); //���������� ��������� []

	void print();
private:
	char* str;
};
#endif // !MY_STRING_H

