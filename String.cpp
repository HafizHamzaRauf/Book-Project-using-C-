#include <iostream>
#include "String.h"
using namespace std;
int String::stringLength(const  char* a) const
{
	if (a == nullptr || *a == '\0')
	{
		return 0;
	}
	else
	{
		int i = 0;
		while (a[i] != '\0')
		{
			i++;
		}
		return i;
	}
}
void String::MyMemCopy(void* des, const void* src, int bytes)
{
	if (des == nullptr)
	{
		return;
	}
	if (src == nullptr)
	{
		return;
	}
	char* d = (char*)des;
	char* s = (char*)src;
	for (int i = 0; i < bytes; i++)
	{
		d[i] = s[i];
	}



}
void String::MyMemMove(void* dest, const void* src, int bytes)
{
	if (src == nullptr)
	{
		return;
	}
	char* d = (char*)dest;
	char* s = (char*)src;
	char* temp = new char[bytes];
	MyMemCopy(temp, s, bytes);
	for (int i = 0; i < bytes; i++)
	{
		d[i] = temp[i];
	}
	delete[] temp;
	temp = nullptr;



}
void String::stringCopy(char* dest, const char* src) const
{
	if (src == nullptr || *src == '\0')
	{
		return;
	}
	int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

}
String::String()
{
	size = 0;
	data = nullptr;
}
String::String(const char c) :String()
{
	if (c == '\0')
	{
		return;
	}
	data = new char[2]{ c, '\0' };
	size = 2;

}
String::String(const char* c) :String()
{
	if (c == nullptr || *c == '\0')
	{
		return;
	}
	size = stringLength(c) + 1;
	data = new char[size];
	stringCopy(data, c);

}
String::String(const String& ref) :String()
{
	size = ref.size;
	data = new char[size];
	stringCopy(data, ref.data);

}
String :: ~String()
{
	if (!data)
	{
		return;
	}
	delete[] data;
	data = nullptr;
	size = 0;
}
void String::shrink()
{

	if (data == nullptr || (stringLength(data) + 1 == size))
	{
		return;
	}
	int length = stringLength(data);
	resize(length + 1);
	data[length] = '\0';
	size = length + 1;

}
char& String::operator[](const int index)
{
	if (index >= 0 && index <= (size - 1))
	{
		return data[index];

	}
	else
	{
		cout << "Invalid Index";
		exit(0);
	}

}
const char& String::operator[](const int index) const
{
	if (index >= 0 && index <= (size - 1))
	{
		return data[index];

	}
	else
	{
		cout << "Invalid Index";
		exit(0);


	}
}
bool String::operator!() const
{
	if (data == nullptr || data[0] == '\0')
	{
		return true;
	}
	else
	{
		return false;
	}
}
int String::getSize()const
{
	return size;
}
int String::getLength() const
{
	return stringLength(data);

}
int String::find(const String& subStr, const int  start = 0)const
{
	if (data == nullptr || subStr.data == nullptr)
	{
		return -1;
	}
	int i = start;
	int count = 0;
	int lengthOfSubStr = stringLength(subStr.data);
	int result = 0;
	while (data[i] != '\0')
	{
		if (data[i] == subStr.data[count])
		{
			count++;
			i++;

			if (lengthOfSubStr == count)
			{
				result = i - lengthOfSubStr;
				return result;
			}
		}
		else
		{
			count = 0;
			i++;
		}
	}
	return -1;

}
void String::insert(int index, const String& subStr)
{
	if (subStr.data == nullptr || (index < 0 || index > stringLength(data)))
	{
		return;
	}
	int dataLength = stringLength(data);
	int subStrDataLength = stringLength(subStr.data);
	resize(size + subStrDataLength);
	int bytes = dataLength - index;
	int copyIndex1 = index + subStrDataLength;
	int copyIndex2 = index;
	MyMemMove(&data[copyIndex1], &data[copyIndex2], bytes);
	for (int i = 0; i < subStrDataLength; i++)
	{
		data[index] = subStr.data[i];
		index++;
	}
	data[dataLength + subStrDataLength] = '\0';

}
void  String::remove(int index, int count = 1)
{
	int dataLength = stringLength(data);

	if ((index < 0 || index >= dataLength) || count <= 0)
	{
		return;
	}
	MyMemMove(&data[index], &data[index + count], (dataLength - index - count));
	data[dataLength - count] = '\0';


}
void String::trimRight()
{
	if (data == nullptr)
	{
		return;
	}
	int length = stringLength(data);
	int tabspace = 9;
	int whitespace = 32;

	while (data[length - 1] == tabspace || data[length - 1] == whitespace)
	{
		length--;
	}
	data[length] = '\0';

}
void String::trimLeft()
{
	int  index = 0;
	char space = ' ';
	char tabspace = '\t';
	char enterSpace = '\n';
	while (data[index] == space || data[index] == tabspace || data[index] == enterSpace && index < size)
	{
		index++;
	}
	stringCopy(&data[0], &data[index]);

}
void String::trim()
{
	if (data == nullptr)
	{
		return;
	}
	trimRight();
	trimLeft();


}
void String::makeUpper()
{
	if (data == nullptr)
	{
		return;
	}
	int length = stringLength(data);
	while (length >= 0)
	{
		if (data[length] >= 'a' && data[length] <= 'z')
		{
			data[length] = data[length] - 32;
		}
		length--;
	}

}
void String::makeLower()
{
	if (data == nullptr || data[0] == '\0')
	{
		return;
	}
	int length = stringLength(data);
	while (length >= 0)
	{
		if (data[length] >= 'A' && data[length] <= 'Z')
		{
			data[length] = data[length] + 32;
		}
		length--;
	}

}
void String::reverse()
{
	if (data == nullptr)
	{
		return;
	}

	char temp;
	int length = stringLength(data);
	for (int i = 0; i < length - 1; i++)
	{
		temp = data[i];
		data[i] = data[length - 1];
		data[length - 1] = temp;
		length--;
	}

}
void String::resize(int ns)
{
	if (ns <= 0)
	{
		this->~String();
		return;
	}
	char* temp = new char[ns];
	int i = 0;
	while (i < ns && i < size)
	{
		temp[i] = data[i];
		i++;
	}
	this->~String();
	size = ns;
	data = temp;
}
int String:: operator ==(const String& a)const
{
	int i = 0;
	while (data[i] == a.data[i] && data[i] != '\0')
	{
		i++;
	}
	if (data[i] < a.data[i])
		return -1;
	else if (data[i] > a.data[i])
		return +1;
	else
		return 0;
}
String String::left(const int count)
{
	if (count <= 0 || data == nullptr || (count > stringLength(data)))
	{
		String a;
		return a;
	}
	String result;
	result.size = count + 2;
	result.data = new char[result.size];
	int i;
	for (i = 0; i < count; i++)
	{
		result.data[i] = data[i];
	}
	result.data[i] = '\0';
	return result;

}
String String::right(const int count)
{
	if (data == nullptr || count <= 0 || (count > stringLength(data)))
	{
		String a;
		return a;
	}
	String result;
	result.size = count + 1;
	result.data = new char[result.size];
	int index = stringLength(data);
	int value = count;
	int i = 0;
	while (i <= count)
	{
		result.data[value] = data[index];
		index--;
		value--;
		i++;
	}
	return result;

}
String::operator long long int()const
{
	if (data == nullptr)
	{
		return 0;
	}

	if (data[0] == '-')
	{
		int i = 1;
		long long int num = 0;

		while (data[i] != '\0')
		{
			num = num * 10 + ((long long int)data[i] - '0');
			i++;
		}
		return -1 * num;
	}
	else
	{
		int i = 0;
		long long int num = 0;

		while (data[i] != '\0')
		{
			num = num * 10 + ((long long int)data[i] - '0');
			i++;
		}
		return  num;
	}




}
String  String::operator+(const String& s2) const
{


	String temp;
	temp.size = stringLength(data) + stringLength(s2.data) + 2;
	temp.data = new char[temp.size + 4];
	int index;
	for (index = 0; index < stringLength(data); index++)
	{
		temp.data[index] = data[index];

	}
	for (int j = 0; j < stringLength(s2.data); j++)
	{
		temp.data[index] = s2.data[j];
		index++;
	}
	temp.data[index] = '\0';
	return temp;
}
void  String::concatEqual(const String& s)
{
	if (s.data == nullptr)
	{
		return;

	}
	int index = stringLength(data);
	int subStringLength = stringLength(s.data);
	resize(index + subStringLength + 1);

	for (int i = 0; i < stringLength(s.data); i++)
	{
		data[index] = s.data[i];
		index++;
	}
	data[index] = '\0';
	return;
}
String& String::operator=(const long long int num)
{

	String temp{ '-' };
	int count = 0;
	long long int number = num;
	number = (num < 0) ? num * -1 : num;
	//number of digits 
	while ((number = number / 10) != 0)
	{
		count++;
	}
	count++;
	number = (num < 0) ? num * -1 : num;
	int rev;
	int i;
	resize(count + 1);
	for (i = 0; i < size - 1; i++)
	{
		rev = number % 10;
		data[i] = rev + 48;
		number = number / 10;
	}

	data[i] = '\0';
	this->reverse();
	if (num < 0)
	{
		insert(0, temp);
	}
	String* temp1;
	temp1 = this;

	return *temp1;

}
String::operator double()const
{
	if (data == nullptr)
	{
		return 0;
	}
	int count = 0;
	float num1 = 0;
	float num2 = 0;
	while (data[count] != '.')
	{
		num1 = num1 * 10 + (float)(data[count] - '0');

		count++;
	}
	long long int multiplicationFactor = 1;
	count++;
	while (data[count] != '\0')
	{
		num2 = num2 * 10 + (float)(data[count] - '0');
		count++;
		multiplicationFactor = multiplicationFactor * 10;

	}
	num2 = num2 / (float)multiplicationFactor;
	float finalNumber = num2 + num1;
	return finalNumber;
}
int String::replace(const String& oldString, const String& newString)
{
	if (oldString.data == nullptr && newString.data == nullptr)
	{
		return  0;
	}
	int index = find(oldString);
	int occurences = 0;
	if (index != -1)
	{
		occurences = 1;
	}
	while (index != -1)
	{
		remove(index, stringLength(oldString.data));
		insert(index, newString);
		index = find(oldString, index + stringLength(oldString.data));
		occurences++;
	}
	return occurences - 1;


}
String String :: operator+=(const String& ref)
{
	return *this = *this + ref;
}
String& String :: operator= (const String& ref)
{
	if (this == &ref)
	{
		return *this;
	}
	this->~String();
	if (!ref.data)
	{
		return *this;
	}
	size = ref.size;
	data = new char[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = ref.data[i];
	}
	return *this;
}
istream& operator >>  (istream& is, String& cString)
{
	cString.resize(2);
	int count = 0;
	int multiplyFactor = 4;
	char ch;

	while ((ch = cin.get()) != '\n')
	{
		cString.data[count] = ch;
		count++;
		if (count == (cString.size - 1))
		{
			cString.resize(multiplyFactor);
			multiplyFactor = multiplyFactor * 2;
		}

	}
	cString.data[count] = '\0';
	return is;

}
ostream& operator << (ostream& is, const String& cString)
{
	if (!cString)
	{
		return is;
	}
	else
	{
		cout << &cString[0];
		return is;
	}

}
String ::operator bool()const
{
	if (this->getLength() == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
String String  :: operator ()(const String& delim)
{

	int delimLength = delim.getLength();
	char* delimArray = new char[delimLength + 1];
	int i;
	for (i = 0; i < delimLength; i++)
	{
		delimArray[i] = delim[i];

	}
	delimArray[i] = '\0';
	int index = -1;
	for (int k = 0; k < this->getLength(); k++)
	{
		for (int j = 0; j < delimLength; j++)
		{
			if (data[k] == delimArray[j])
			{

				index = k;
				break;
			}
		}
		if (index != -1)
		{
			break;
		}
	}
	if (index != -1)
	{
		String temp = left(index);
		index++;
		remove(0, index);
		delete[]delimArray;
		return temp;
	}
	else
	{
		String temp = data;
		this->~String();
		delete[]delimArray;
		delimArray = nullptr;
		return temp;
	}

}
String& String :: operator=(String&& ref)
{
	this->~String();
	data = ref.data;
	size = ref.size;
	ref.data = nullptr;
	return *this;
}
String::String(String&& ref)
{
	data = ref.data;
	size = ref.size;
	ref.data = nullptr;

}
String& String:: operator=(const double value)
{
	double tv = 0;
	if (value < 0)
	{
		tv = value * -1;
	}
	else
	{
		tv = value;
	}
	long long int digit = tv;
	String temp = " ";
	temp = digit;
	double val = tv - digit;
	temp.insert(temp.getLength(), ".");
	int a = 0;
	int mod = 0;
	char ch;
	for (int i = 0; i < 6; i++)
	{
		val = val * 10;
		a = val;
		mod = a % 10;
		ch = mod + '0';
		temp.insert(temp.getLength(), ch);

	}
	while (temp[temp.getLength() - 1] == '0')
	{
		temp.remove(temp.getLength() - 1);
	}
	if (value < 0)
	{
		temp.insert(0, "-");
	}
	*this = temp;
	return *this;

}