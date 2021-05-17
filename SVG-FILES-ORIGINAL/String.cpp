#include "String.h"

String::String()
{
	buffer = nullptr;
	size = 0;
}

String::String(const String& other)
{
	size = other.size;
	if (size == 0)
	{
		buffer = nullptr;
	}
	else {
		buffer = new char[size];
		for (int i = 0; i < size; i++) {
			buffer[i] = other.buffer[i];
		}
	}

}


String::String(const char* other)
{
	size = 0;
	while (other[size] != '\0') {
		size++;
	}

	buffer = new char[size];
	for (int i = 0; i < size; i++) {
		buffer[i] = other[i];
	}
}


String::~String()
{
	if (size > 0)
		delete[] buffer;
	size = 0;
}

String& String::operator=(const String& other)
{
	if (buffer != nullptr)
	{
		delete[]buffer;
	}
	size = other.size;
	buffer = new char[size];
	for (size_t i = 0; i < size; i++)
	{
		buffer[i] = other.buffer[i];
	}

	return *this;
}


int String::length() const
{
	return size;
}

int String::at(int index, char& element) const
{
	int returnCode = 0;
	if (index >= 0 && index < size)
	{
		element = buffer[index];
		returnCode = 1;
	}
	return 0;
}
;

String& String::operator+=(char ch)
{
	char* newBuffer = new char[size + 2];
	for (size_t i = 0; i < size; i++)
	{
		newBuffer[i] = buffer[i];
	}
	newBuffer[size] = ch;
	newBuffer[size + 1] = '\0';
	size++;

	delete[] buffer;
	buffer = newBuffer;

	return *this;
}



char& String::operator[](size_t i)
{
	return buffer[i];
}

char String::operator[](size_t i) const
{
	return buffer[i];
}

void String::stringCopy(char* destination)
{
	
	for (size_t i = 0; i < length(); i++)
	{
		destination[i] = buffer[i];
	}
	destination[length()] = '\0';
}

int String::parseToInt()
{
	int res = 0;
	int sign = 1;
	int i = 0;

	char* str = new char[length() + 1];
	stringCopy(str);

	
	if (str[0] == '-') {
		sign = -1;
		i++;
	}

	
	for (i; str[i] != '\0'; ++i)
		res = res * 10 + str[i] - '0';

	delete[]str;
	return sign * res;
}

bool String::isNumber()
{
	char* str = new char[length() + 1];
	stringCopy(str);

	for (int i = 0; i < length(); i++) {
		
		if (str[i] < '0' || str[i]>'9') {
			delete[]str;
			return false;
		}
	}
	delete[]str;
	return true;
}

String String::operator+(const String& other) const
{
	String result;
	if (size == 0 && other.size == 0)
	{
		result.size = 0;
		result.buffer = nullptr;
	}
	else {
		result.size = size + other.size;
		result.buffer = new char[result.size];

		int i;
		for (i = 0; i < size; i++)
		{
			result.buffer[i] = buffer[i];
		}
		int j = 0;
		while (j < other.size)
		{
			result.buffer[i] = other.buffer[j];
			i++;
			j++;
		}
	}
	return result;
}


std::ostream& operator<<(std::ostream& os, const String& other)
{
	for (size_t i = 0; i < other.size; i++)
	{
		os << other.buffer[i];
	}
	return os;
}

bool operator==(const String& first, const String& second)
{
	if (first.size != second.size) {
		return false;
	}
	else {
		for (size_t i = 0; i < first.size; i++)
		{
			if (first.buffer[i] != second.buffer[i])
			{
				return false;
			}
		}
	}
	return true;
}

bool operator==(const String& first, const char* word)
{
	if (first.size != strlen(word)) {
		return false;
	}
	else {
		for (size_t i = 0; i < first.size; i++)
		{
			if (first.buffer[i] != word[i])
			{
				return false;
			}
		}
	}
	return true;
}
