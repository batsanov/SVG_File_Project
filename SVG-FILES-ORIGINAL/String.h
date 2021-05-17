#pragma once
#include <iostream>

class String {
private:
	int size;
	char* buffer;
public:
	String();
	String(const String& other);
	String(const char*);
	String& operator=(const String& other); // string gets the value of other 
	~String();


	int length() const; // returns the size
	int at(int index, char& element) const; // returns true if the index is correct and false if not, element param get the value of buffer[index]

	friend std::ostream& operator<<(std::ostream& os, const String& other); // cout 
	friend bool operator==(const String& first, const String& second); // returns true if 2 strings are equal and false if they aren't
	friend bool operator==(const String& first, const char* word);
	String& operator += (const char ch);

	char& operator[](size_t i);
	char operator[](size_t i) const;
	void stringCopy(char* destination);
	int parseToInt();
	bool isNumber();

	String operator+(const String&) const; // concats 2 strings

};