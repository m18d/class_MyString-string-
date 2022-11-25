#include"MyString.h"
#include<iostream>


MyString::MyString()//����������� ����������� 
{
	str = nullptr;
}

MyString::MyString(const char* str) //����������� ��� ������
{
	int lenght = strlen(str);
	this->str = new char[lenght + 1];
	for (int i = 0; i < lenght; i++)
	{
		this->str[i] = str[i];
	}
	this->str[lenght] = '\0';
}

MyString::MyString(const MyString& other) //����������� �����������
{
	int lenght = strlen(other.str);
	this->str = new char[lenght + 1];
	for (int i = 0; i < lenght; i++)
	{
		this->str[i] = other.str[i];
	}
	this->str[lenght] = '\0';
}

MyString::~MyString() //����������
{
	delete[] this->str;
}

MyString& MyString::operator =(const MyString& other) //���������� ��������� =
{
	if (this->str != nullptr)
	{
		delete[] str;
	}
	int lenght = strlen(other.str);
	this->str = new char[lenght + 1];
	for (int i = 0; i < lenght; i++)
	{
		this->str[i] = other.str[i];
	}
	this->str[lenght] = '\0';

	return *this;
}

MyString MyString::operator +(const MyString& other) //���������� ��������� +
{
	MyString newStr;

	int lenThis = strlen(this->str);
	int lenOther = strlen(other.str);
	newStr.str = new char[lenThis + lenOther + 1];

	int i = 0;
	for (; i < lenThis; i++)
	{
		newStr.str[i] = this->str[i];
	}

	for (int j = 0; j < lenOther; j++, i++)
	{
		newStr.str[i] = other.str[j];
	}

	newStr.str[lenThis + lenOther] = '\0';

	return newStr;
}

bool MyString::operator==(const MyString& other) //���������� ��������� ==
{
	if (strlen(this->str) < strlen(other.str) || strlen(this->str) > strlen(other.str))
		return false;
	else
	{
		int count = 0;
		for (int i = 0; i < strlen(this->str); i++)
		{
			if (this->str[i] == other.str[i])
			{
				count++;
				continue;
			}
			break;
		}
		return count == strlen(this->str) ? true : false;
	}
}

bool MyString::operator != (const MyString& other) //���������� ��������� !=
{
	if (strlen(this->str) != strlen(other.str))
		return true;
	else
	{
		int count = 0;
		for (int i = 0; i < strlen(this->str); i++)
		{
			if (this->str[i] != other.str[i])
			{
				count++;
				continue;
			}
			break;
		}
		return count == 0 ? false : true;
	}
}

bool MyString::operator > (const MyString& other) //���������� ��������� >
{
	return strlen(this->str) > strlen(other.str) ? true : false;
}

bool MyString::operator >= (const MyString& other) //���������� ��������� >=
{
	return strlen(this->str) >= strlen(other.str) ? true : false;
}

bool MyString::operator < (const MyString& other) //���������� ��������� <
{
	return strlen(this->str) < strlen(other.str) ? true : false;
}

bool MyString::operator <= (const MyString& other) //���������� ��������� <=
{
	return strlen(this->str) <= strlen(other.str) ? true : false;
}

char& MyString::operator [] (const int index) //���������� ��������� []
{
	if (index < strlen(this->str) && index > -1)
	{
		return this->str[index];
	}
}

void MyString::print()
{
	std::cout << this->str << std::endl;
}