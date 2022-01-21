#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<forward_list>
#include<list>
#include<iterator>
//using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"

//#define STL_ARRAY
#define STL_VECTOR
//#define STL_DEQUE
//#define STL_FORWARD_LIST
//#define STL_LIST

void main()
{
	setlocale(LC_ALL, "Rus");
#ifdef STL_ARRAY
	const int n = 5;
	std::array<int, 5>arr = { 3,5,8 };
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
#endif // STL_ARRAY

#ifdef STL_VECTOR
	std::vector<int> vec = { 0,1,1,2,3,5,8,13,21,34 };
	cout << "Size: " << vec.size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;
	cout << "MaxSize: " << vec.max_size() << endl;

	vec.push_back(55);

	//vec.shrink_to_fit();
	try
	{
		for (int i = 0; i < vec.capacity(); i++)
		{
			//cout << vec.data()[i] << tab;//Метод data() возвращает указатель на динамический массив, 
			//который обворачивает vector

			//cout << vec[i] << tab;
			cout << vec.at(i) << tab;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << endl << e.what() << endl;
	}
	cout << endl;
	cout << "Size: " << vec.size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;
	cout << "MaxSize: " << vec.max_size() << endl;

	/*std::vector<char> vec2;
	cout << "Size: " << vec2.size() << endl;
	cout << "Capacity: " << vec2.capacity() << endl;
	cout << "MaxSize: " << vec2.max_size() << endl;*/

	int index;
	int count;
	int value;
	/*cout << "Введите индекс добовляемого элемента:"; cin >> index;
	cout << "Введите кол-во добавлений:"; cin >> count;
	cout << "Введите значение добовляемого элемента:"; cin >> value;


	if (index <= vec.size())vec.insert(vec.begin() + index,count, value);
	else std::cerr << "Error: out of range." << endl;*/

	vec.insert(vec.begin() + 11, { 256,512,168 });

	for (std::vector<int> ::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	for (std::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;

	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	if (index <= vec.size())vec.erase(vec.begin() + index);
	else std::cerr << "Error: out of range." << endl;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it <<tab;
	}
	cout << endl;
	for (std::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;


#endif // STL_VECTOR

#ifdef STL_DEQUE
	std::deque<int>deque = { 3,5,8,13,21 };
	deque.push_back(34);
	deque.push_back(55);

	deque.push_front(2);
	deque.push_front(1);
	deque.push_front(1);
	deque.push_front(0);
	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	for (std::deque<int>::reverse_iterator it = deque.rbegin(); it != deque.rend(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;

#endif // STL_DEQUE

#ifdef STL_FORWARD_LIST
	std::forward_list<int>list1 = { 3,5,8,13,21 };
	list1.push_front(2);
	list1.push_front(1);
	list1.insert_after(list1.begin(), 1);
	list1.insert_after(list1.before_begin(), 0);
	list1.push_front(0);

	for (std::forward_list<int>::iterator it = list1.begin(); it != list1.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;

	std::forward_list<int>list2 = { 256,512,768 };
	for (int i : list2)cout << i << tab; cout << endl;

	list1.swap(list2);
	for (int i : list1)cout << i << tab; cout << endl;
	for (int i : list2)cout << i << tab; cout << endl;

#endif // STL_FORWARD_LIST

#ifdef STL_LIST
	std::list<int> list = { 3,5,8,13,21 };
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	for (std::list<int>::reverse_iterator it = list.rbegin(); it != list.rend(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;

	int index;
	int value;
	cout << "Введите индекс добовляемого элемента: "; cin >> index;
	cout << "Введите значение добовляемого элемента: "; cin >> value;

	std::list<int>::iterator position = list.begin();
	//for (int i = 0; i < index; i++)position++;
	if (index < list.size())
	{
		std::advance(position, index);
		list.insert(position, value);
	}
	else cout << "Error: out of range.\n";

	for (int i : list)cout << i << tab; cout << endl;

#endif // STL_LIST


}