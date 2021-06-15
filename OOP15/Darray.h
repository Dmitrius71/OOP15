#include<time.h>
#include<iostream>

#pragma once


using namespace std;


template <class T>
class Darray
{
	int length;
	int real_size;

	T* item;
	void resize()
	{
		
		T* temp = new T[real_size]{};
		for (int i = 0; i < length; i++)
			temp[i] = item[i];

		delete[]item;
		item = temp;
	}

public:
	Darray()
	{
		
		length = 0;
		real_size = 2;
		item = new T[real_size]{};
	}

	Darray(int size)
	{ 
		length = size;
		real_size = 2 * size;
		item = new T[real_size]{};
	}

	~Darray()
	{
		if(item)
		delete[] item;
	}

	int Length()
	{
		return length;
	}

	void Insert(int index, T value)
	{
		if (length >= real_size)
		{
			real_size = real_size + real_size / 2;
			resize();
		}

		T* temp = new T[real_size]{};
			for (int i = 0; i < length; i++)
				temp[i] = item[i];
		temp[index] = value;
		for (int i = index; i < length; i++)
			temp[i + 1] = item[i];

		delete[]item;
		item = temp;
		length++;

	}

	void RandomInit(int left, int right)
	{
		srand(time(NULL));
		for (int i = 0; i < length; i++)
		item[i] = left+rand()% (right-left+1);

	}

	void Print()
	{
		for (int i = 0; i < length; i++)
			cout << item[i] << " ";
		cout << endl;
	}

	T  Remove(int index)
	{
		T value{ item[index] };
		if (length <= real_size / 2)
		{
			real_size = real_size - length / 2;
			resize();
		}

		T* temp = new T[real_size]{};
		for (int i = 0; i < index; i++)
			temp[i] = item[i];
		for (int i = index+1; i < length; i++)
			temp[i-1] = item[i];
		length--;
		delete[]item;
		item = temp;

		return value;
	}

	void PushBack(T value)
	{
		if (length >= real_size)
		{
			real_size = real_size + real_size / 2;
			resize();
		}
		item[length++] = value;

	}

	T PopBack()
	{
		T value{ item[--length] };

		if (length <= real_size / 2)
		{
			real_size = real_size - length / 2;
			resize();
		}
		return value;
	}

	Darray(const Darray<T>& array)

	{
		*this = array;
	}

	Darray<T> operator =(const Darray<T> array)
	{
		if (&array == this)
			return;

		if (item)
			delete[] item;

		if (&array == nullptr)
		{
			this->real_size = 2;
			this->length = 0;
			item = new T[real_size]{};
			return;
		}

		this->real_size = array.real_size;
		this->length = array.length;

		item = new T[real_size]{};

		for (int i = 0; i < length; i++)
			item[i] = array.item[i];
	}

	T& At(int index)
	{
		return item[index];
	}

	T& operator[](int index)
	{
		return item[index];
	}




};

