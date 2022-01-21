#include<iostream>
#include<array>
#include<vector>
//using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"

//#define STL_ARRAY
#define STL_VECTOR

void main()
{
	setlocale(LC_ALL, " ");
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
	std::vector<int> vec = {0,1,1,2,3,5,8,13,21,34};
	cout << "Size: " << vec.size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;
	cout << "MaxSize: " << vec.max_size() << endl;
	
	vec.push_back(55);

	//vec.shrink_to_fit();
	try
	{
		for (int i = 0; i < vec.capacity(); i++)
		{
			//cout << vec.data()[i] << tab;//����� data() ���������� ��������� �� ������������ ������, 
			//������� ������������ vector
			
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
#endif // STL_VECTOR

}