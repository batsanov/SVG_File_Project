#pragma once
#include <iostream>

template <typename T>
class Vector
{
private:
    T* arr;
    int capacity;
    int size;

public:
    Vector();
    Vector(const Vector<T>& other);
    Vector& operator=(const Vector<T>& other);
    ~Vector();

    void resize(); // increases the capacity
    void push(size_t index, T element);// adds element at wanted index
    void pushAtBack(T element); // adds element at the back
    T get(int index); // gets the element at wanted index
    void pop(); // removes the last element 
    int getsize() const; // returns the size
    void print(); // prints the vector
    void clearVector();
	void eraseAt(int index);

    T& operator[](size_t i);
    T operator[](size_t i) const;

    template <typename E>
    friend std::ostream& operator<<(std::ostream&, Vector<E>);
  
};


template <typename T>
Vector<T>::Vector()
{
	capacity = 8;
	size = 0;
	arr = new T[capacity];
}


template<typename T>
Vector<T>::Vector(const Vector<T>& other)
{
	size = other.size;
	capacity = other.capacity;
	arr = new T[capacity];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = other.arr[i];
	}
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other)
	{
		delete[] arr;

		size = other.size;
		capacity = other.capacity;
		arr = new T[capacity];

		for (size_t i = 0; i < size; i++)
		{
			arr[i] = other.arr[i];
		}
	}

	return *this;
}

template<typename T>
Vector<T>::~Vector()
{
	if (arr != nullptr)
		delete[]arr;
	size = capacity = 0;
}


template<typename T>
void Vector<T>::resize()
{
	capacity *= 2;
	T* temporary = new T[capacity];

	for (size_t i = 0; i < size; i++)
	{
		temporary[i] = arr[i];
	}
	delete[] arr;
	arr = temporary;
}



template<typename T>
void Vector<T>::push(size_t index, T element)
{
	if (size >= capacity)
	{
		this->resize();
	}

	size++;

	for (size_t i = size - 1; i > index; i--)
	{
		arr[i] = arr[i - 1];
	}

	arr[index] = element;
}

template<typename T>
void Vector<T>::pushAtBack(T element)
{
	if (size >= capacity)
	{
		this->resize();
	}

	arr[size] = element;
	size++;

}

template<typename T>
T Vector<T>::get(int index)
{
	return arr[index];
}

template<typename T>
void Vector<T>::pop()
{
	size--;
}

template<typename T>
int Vector<T>::getsize() const
{
	return size;
}

template<typename T>
void Vector<T>::print()
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}

}

template<typename T>
void Vector<T>::clearVector()
{
	if (arr != nullptr)
		delete[]arr;

	capacity = 8;
	size = 0;
	arr = new T[capacity];
}

template<typename T>
inline void Vector<T>::eraseAt(int index)
{
	size--;
	for (index; index < size; index++)
	{
		arr[index] = arr[index + 1];
	}

}

template<typename T>
T& Vector<T>::operator[](size_t i)
{
	return arr[i];
}

template<typename T>
T Vector<T>::operator[](size_t i) const
{
	return arr[i];
}


template<typename E>
inline std::ostream& operator<<(std::ostream& out, Vector<E> vec)
{
	out << "{";
	for (size_t i = 0; i < vec.size; ++i)
	{
		out << vec.arr[i] << " ";
	}
	out << "}";
	return out;
}