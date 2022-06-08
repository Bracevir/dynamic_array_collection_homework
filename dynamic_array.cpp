#include "dynamic_array.h"
#include <vector>

dynamic_array::dynamic_array()
{
}

dynamic_array::dynamic_array(int size, int* data)
{
	this->size = size;
	this->capacity = size;
	this->data = new int[size];
	for (int i = 0; i < size; i++)
		this->data[i] = data[i];
}
void dynamic_array::PrintArray()const {
	for (int i = 0; i < size; i++)
		cout << data[i] << " ";
}

dynamic_array::~dynamic_array()
{
	if (data != nullptr)
		delete[]data;
}

dynamic_array::dynamic_array(const dynamic_array& other)
{
	this->size = other.size;
	this->capacity = size;
	this->data = new int[other.size]{};
	for (int i = 0; i < this->size; i++)
		this->data[i] = other.data[i];
}

const int* dynamic_array::Data() const
{
	return data;
}

dynamic_array& dynamic_array::operator=(const dynamic_array& other)
{
	this->size = other.size;
	if (this->data != nullptr) 
	{
		delete[]this->data;
	}
	this->data = new int[other.size]{};
	for (int i = 0; i < this->size; i++)
		this->data[i] = other.data[i];
	return *this;
}

int& dynamic_array::at(int index)
{
	return data[index];
}

int& dynamic_array::front() const
{
	return data[0];
}

int& dynamic_array::back() const
{
	return data[size - 1];
}

int dynamic_array::Capacity() const
{
	return capacity;
}

bool dynamic_array::empty()
{
	if (capacity > 0) return false;  
	else return true;
}

int dynamic_array::Size() const
{
	return this->size;
}

void dynamic_array::reserve(int value)
{
	size = this->size;
	int* tmp = new int[size];
	for (int i = 0; i < size; i++) {
		tmp[i] = data[i];
	}
	delete[]data;
	this->capacity = size + value;
	this->size = this->capacity;
	data = new int[capacity] {};
	for (int i = 0; i < capacity - value; i++) {
		data[i] = tmp[i];
	}
	delete[]tmp;
}

void dynamic_array::shrink_to_fit()
{
	int* tmp = new int[size];
	for (int i = 0; i < size; i++) {
		tmp[i] = data[i];
	}
	capacity = size;
	delete[]data;
	data = new int[capacity];
	for (int i = 0; i < capacity; i++) {
		data[i] = tmp[i];
	}
	delete[]tmp;
}

void dynamic_array::clear()
{
	delete[]data;
	size = 0;
}

vector<int>::iterator dynamic_array::insert(vector<int>::const_iterator _Where, initializer_list<int> _Ilist)
{
	return vector<int>::iterator();
}

//void insert() {
//
//}

void dynamic_array::erase(int begin, int end)
{
	int count = 0;
	int* tmp = new int[size];
	for (int i = 0; i < size; i++) {
		tmp[i] = data[i];
	}
	delete[]data;
	data = new int[size - (end - begin)];
	for (int i = 0; i < size; i++)
	{
		if (i >= begin && i <= end)
		{
			count++;
			continue;
		}
		data[i - count] = tmp[i];
	}
	size -= (end - begin + 1);
}

void dynamic_array::push_back(int value)
{
	int* tmp = new int[size + 1];

	for (int i = 0; i < size; i++) {
		tmp[i] = this->data[i];
	}
	size += 1;
	for (int i = 0; i < this->size - 1; i++) {
		this->data[i] = tmp[i];
	}
	data[size - 1] = value;
	delete[]tmp;
}

void dynamic_array::emplace_back(int value)
{
	int* tmp = new int[size + 1];

	for (int i = 0; i < size; i++) {
		tmp[i] = this->data[i];
	}
	size += 1;
	for (int i = 0; i < this->size - 1; i++) {
		this->data[i] = tmp[i];
	}
	data[size - 1] = value;
	delete[]tmp;
}

void dynamic_array::pop_back()
{
	int* tmp = new int[size];
	for (int i = 0; i < size; i++) {
		tmp[i] = data[i];
	}
	delete[]data;
	size -= 1;
	data = new int[size] {};
	for (int i = 0; i < size; i++) {
		data[i] = tmp[i];
	}
	delete[]tmp;
}

void dynamic_array::resize(int newsize)
{
	if (newsize > capacity)
		this->reserve(newsize - capacity);
	else
	{
		int* tmp = new int[size];
		for (int i = 0; i < size; i++)
		{
			tmp[i] = data[i];
		}
		delete[]data;
		capacity = newsize;
		data = new int[capacity];
		if (size > capacity)
			size = capacity;
		for (int i = 0; i < size; i++)
		{
			data[i] = tmp[i];
		}
	}
}

void dynamic_array::swap(dynamic_array& other, dynamic_array& other2)
{
	dynamic_array tmp;
	tmp = other;
	other = other2;
	other2 = tmp;
}

bool dynamic_array::operator==(const dynamic_array&& other)
{
	if (this->size != other.size)return false;
	if (this->size == other.size) {
		for (int i = 0; i < this->size; i++) {
			if (this->data[i] != other.data[i])
				return false;
		}
		return true;
	}
}
//
//vector<int>::iterator insertArray(vector<int>::const_iterator _Where, initializer_list<int> _Ilist)
//{
//	return vector<int>::iterator();
//}
