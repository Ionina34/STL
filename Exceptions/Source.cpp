#include<iostream>
#include<stdexcept>
using namespace std;

///#define DIVISION_BY_ZERO

void main()
{
	setlocale(LC_ALL, "Rus");
#ifdef DIVISION_BY_ZERO
	//cout << 2 / 0 << endl;
	int a;
	int b;
	cout << "¬ведите два числа: "; cin >> a >> b;
	try
	{
		cout << a / b << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	catch (...)
	{
		std::cerr << "Something happened" << endl;
	}
#endif // DIVISION_BY_ZERO

	int n;
		int f = 1;
		cout << "¬ведите число жд€ вычислени€ ‘акториала: "; cin >> n;
		try
		{
			for (int i = 1; i <= n; i++)
			{
				cout << i << " = ";
				f *= i;
				cout << f << endl;
			}
		}
		catch (const std::exception& e)
		{
			cerr << e.what() << endl;
		}
		catch (...)
		{
			cerr << "Something happened" << endl;
		}
}