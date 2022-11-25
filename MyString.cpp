#include<iostream>


using namespace std;


class MyString
{
public:
	MyString()//Конструктор стандартный 
	{
		str = nullptr;
	} 
	MyString(const char *str) //Конструктор для текста
	{
		int lenght = strlen(str);
		this->str = new char [lenght + 1];
		for (int i = 0; i < lenght; i++)
		{
			this->str[i] = str[i];
		}
		this->str[lenght] = '\0';
	}
	MyString(const MyString& other) //Конструктор копирования
	{
		int lenght = strlen(other.str);
		this->str = new char[lenght + 1];
		for (int i = 0; i < lenght; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[lenght] = '\0';
	}
	~MyString() //Диструктор
	{
		delete[] this->str;
	}
	MyString& operator =(const MyString& other) //Перегрузка оператора =
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
	MyString operator +(const MyString& other) //Перегрузка оператора +
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

		for (int j = 0; j < lenOther; j++,i++)
		{
			newStr.str[i] = other.str[j];
		}

		newStr.str[lenThis + lenOther] = '\0';

		return newStr;
	}
	bool operator==(const MyString& other) //Перегрузка оператора ==
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
	bool operator != (const MyString& other) //Перегрузка оператора !=
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
	bool operator > (const MyString& other) //Перегрузка оператора >
	{
		return strlen(this->str) > strlen(other.str) ? true : false;
	}
	bool operator >= (const MyString& other) //Перегрузка оператора >=
	{
		return strlen(this->str) >= strlen(other.str) ? true : false;
	}
	bool operator < (const MyString& other) //Перегрузка оператора <
	{
		return strlen(this->str) < strlen(other.str) ? true : false;
	}
	bool operator <= (const MyString& other) //Перегрузка оператора <=
	{
		return strlen(this->str) <= strlen(other.str) ? true : false;
	}
	char& operator [] (const int index) //Перегрузка оператора []
	{
		if (index < strlen(this->str) && index > -1)
		{
			return this->str[index];
		}
	}
	void print() //kostil
	{
		cout << this->str << endl;
		
	}
private:
	char* str;
};

int main()
{

	return 0;
}