#pragma once
#include<iostream>
using namespace std;

class dynamic_array {
public:
	dynamic_array();
	dynamic_array(int size, int* data);
	~dynamic_array();
	dynamic_array(const dynamic_array& other);
	dynamic_array& operator = (const dynamic_array& other);
	const int* Data()const;
	void PrintArray()const;
	int& at(int index);
	int& front()const;
	int& back()const;
	int  Capacity()const;
	bool empty();
	int Size()const;
	void reserve(int value);
	void shrink_to_fit();
	void clear();
	vector<int>::iterator insert(vector<int>::const_iterator _Where, initializer_list<int> _Ilist);
	//void insert();
	void erase(int begin, int end);
	void push_back(int value);
	void emplace_back(int value);
	void pop_back();
	void resize(int newsize);
	void swap(dynamic_array& other, dynamic_array& other2);
	bool operator==(const dynamic_array&& other);
private:
	int size{ 0 };
	int capacity{ 0 };
	int* data = nullptr;
};

//vector<int>::iterator insertArray(vector<int>::const_iterator _Where, initializer_list<int> _Ilist);