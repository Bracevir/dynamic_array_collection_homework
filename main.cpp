#include <iostream>
#include "dynamic_array.h"
#include <stdlib.h>
#include <ctime>
#include <vector>

int main()
{
    srand(time(NULL));
    dynamic_array first_array(3, new int[] {5, 7, 3});
    cout << "First array:" << endl;
    first_array.PrintArray();
    dynamic_array second_array(8, new int[] {10, 23, 1, 42, 15, 6, 27, 3});
    cout << "\nSecond array:" << endl;
    second_array.PrintArray();
    dynamic_array third_array(10, new int[] {10, 23, 1, 42, 51, 13, 15, 6, 27, 3});
    cout << "\nThird array:" << endl; 
    third_array.PrintArray();
	cout << "at = " << first_array.at(2) << endl;;
	cout << "front = " << first_array.front() << endl;
	cout << "back = " << first_array.back() << endl;
	cout << "Capacity = " << first_array.Capacity() << endl;
	cout << "empty = " << first_array.empty() << endl;
	cout << "size = " << first_array.Size() << endl;
	cout << "c = "; second_array.PrintArray(); 
	cout << endl;
	cout << "first_array = "; 
	first_array.PrintArray(); 
	cout << endl;
	cout << "swap\n";
	swap(first_array, second_array);
	cout << "c = "; second_array.PrintArray(); 
	cout << endl;
	cout << "first_array = "; 
	first_array.PrintArray(); 
	cout << endl;
	first_array.push_back(100);
	cout << "push_back\n";
	cout << "first_array = "; first_array.PrintArray(); cout << endl;
	cout << endl;
	cout << "data = " << first_array.Data();
	cout << endl;
	cout << "third_array = "; 
	third_array.PrintArray();
	cout << "\nreserve"; 
	third_array.reserve(3);
	cout << "\nfirst_array = "; 
	third_array.PrintArray();
	cout << "\npop_back = "; 
	third_array.pop_back();
	third_array.PrintArray();
	cout << "\nq = "; 
	third_array.PrintArray();
	cout << "\nresize\n"; 
	third_array.resize(15);
	third_array.PrintArray();
	cout << "\nerase\n"; 
	third_array.erase(6, 15); 
	third_array.PrintArray();
	cout << "\ninsert = "; 
	vector<int> vector_array;
	vector_array.assign(5, 2);
	initializer_list<int> vector_array_list = { 2, 3 };
	vector<int>::iterator it = vector_array.begin() + 2;
	vector<int>::iterator it2;
	it2 = vector_array.insert(it, vector_array_list);
	cout << "vector_array = ";
	for (int i = 0; i < vector_array.size(); i++)
		cout << vector_array[i] << " ";
	cout << endl;
	cout << "it2 => ";
	while (it2 != vector_array.end())
	{
		cout << *it2 << " ";
		it2++;
	}
}

	return 0;
}