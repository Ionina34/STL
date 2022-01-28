#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<fstream>
#include<Windows.h>
#include<string>
#include<map>
#include<list>
#include<conio.h>

#include"Crime.h"

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter  "\n-------------------------------------------------------\n"

void menu();
void print(const std::map<std::string, std::list<Crime>>& base);
void save(const std::map<std::string, std::list<Crime>>& base);
void load(std::map<std::string, std::list<Crime>>& base);
int select_crime();
void add_crime(std::map<std::string, std::list<Crime>>& base);

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::map<std::string, std::list<Crime>> base/* =
	{
		std::pair<std::string,std::list<Crime>>("m777ok",{Crime(1,"ул. Ленина"),
		Crime(2,"ул. Ленина"),Crime(8,"Перекресток Ленина и Октябрьской")}),
		std::pair<std::string,std::list<Crime>>("a666bb",{Crime(3,"ул. Фрунзе"),
			Crime(2,"ул. Фрунзе")}),
		std::pair<std::string,std::list<Crime>>("a123ab",{Crime(5,"ТЦ Экватор")}),
		std::pair<std::string,std::list<Crime>>("b555aa",{Crime(7,"ул. Парижской Коммуны")}),
	}*/;

	char key;
	do
	{
		system("CLS");
		menu();
		key = _getch();
		switch (key)
		{
		case '0': load(base);      break;
		case '8': save(base);      break;
		case '1': print(base);     break;
		case '2': add_crime(base); break;
		}
	} while (key != 27);

}
void menu()
{
	system("CLS");
	cout << "0 - Загрузка базы из файла;" << endl;
	cout << "1 - Вывод всей базы;" << endl;
	cout << delimiter;
	cout << "2 - Добавить правонарушение;" << endl;
	cout << "8 - Сохранение базы в файл;" << endl;
	cout << delimiter;
	cout << "Escape - выход" << endl;
}
void print(const std::map<std::string, std::list<Crime>>& base)
{
	for (std::map<std::string, std::list<Crime>>::const_iterator it = base.begin(); it != base.end(); ++it)
	{
		cout << it->first << ":\n";
		for (std::list<Crime>::const_iterator l_it = it->second.begin(); l_it != it->second.end(); ++l_it)
		{
			cout << tab << *l_it << endl;;
		}
		cout << "\n-----------------------------------------------------\n";
	}
	system("PAUSE");
}
void save(const std::map<std::string, std::list<Crime>>& base)
{
	std::ofstream fout("base.txt");
	for (std::map<std::string, std::list<Crime>>::const_iterator it = base.begin(); it != base.end(); ++it)
	{
		fout.width(10);
		fout << std::left;
		fout << it->first + ":";
		for (std::list<Crime>::const_iterator l_it = it->second.begin(); l_it != it->second.end(); ++l_it)
		{
			fout << *l_it << ", ";
		}
		fout.seekp(-2, std::ios_base::cur);
		fout << ";\n";
		//fout << "\n-----------------------------------------------------\n";
	}
	fout.close();
	system(" notepad base.txt");
}
void load(std::map<std::string, std::list<Crime>>& base)
{
	std::ifstream fin("base.txt");
	if (fin.is_open())
	{
		std::string licence_plate;
		std::string all_crimes;
		while (!fin.eof())
		{
			std::getline(fin, licence_plate, ':');
			std::getline(fin, all_crimes);
			if (licence_plate.empty())break;
			/*all_crimes.erase(0, all_crimes.find_first_not_of(' '));
			all_crimes.erase(all_crimes.find(';'),all_crimes.size());
			//npos - конец строки
			if (all_crimes.find(',') == std::string::npos)
			{
				int crime_id = std::stoi(all_crimes);
				std::string place = all_crimes.erase(0, 1);
				base[licence_plate].push_back(Crime(crime_id,place));
				//base[licence_plate].push_back(Crime(std::stoi(all_crimes),all_crimes.erase(0,1)));
			}
			else for (size_t start = -1, end = 0; all_crimes.find(',', end)!=std::string::npos; start = end)
			{
				end = all_crimes.find(',', start+1);
				std::string crime = all_crimes.substr(start+1, end - start);
				crime.erase(0, crime.find_first_not_of(' '));
				if(crime.find(',')!=std::string::npos)crime.erase(crime.find_last_of(','), crime.size());
				int crima_id = std::stoi(crime);
				std::string place = crime.erase(0, 1);
				base[licence_plate].push_back(Crime(crima_id,place));
			}*/
			char* sz_all_crimes = new char[all_crimes.size()]{};
			strcpy(sz_all_crimes, all_crimes.c_str());
			char delimeter[] = ",;";
			for (char* pch = strtok(sz_all_crimes, delimeter); pch; pch = strtok(NULL, delimeter))
			{
				while (*pch == ' ')pch++;
				base[licence_plate].push_back(Crime(atoi(pch), pch + 1));
			}
		}
		fin.close();
	}
	else
	{
		std::cerr << "File not found" << endl;
	}
	cout << "База загружена из файла.";
	system("PAUSE");
}
int select_crime()
{
	for (std::pair<int, std::string>i : crime)
	{
		cout << i.first << tab << i.second << endl;
	}
	int id;
	do
	{
	cout << "Выберите правонарушение: ";
	//	cin >> id;
	id = _getch()-48;
	cout << id << endl;
	} while (id >= crime.size()&& id!=27);
	return id;
}
void add_crime(std::map<std::string,std::list<Crime>>& base)
{
	std::string licence_plate;
	cout << "Введите номер автомобиля: "; std::getline(cin, licence_plate);
	int crime_id;
	crime_id = select_crime();
	std::string place;
	cout << "Введите место происшествия: "; std::getline(cin, place);
	base[licence_plate].push_back(Crime(crime_id, place));
	cout << "Запись добавлена." << endl;
	system("PAUSE");
}