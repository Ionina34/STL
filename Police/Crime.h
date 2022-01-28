#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<map>

const extern  std::map<int, std::string>& crime;

class Crime
{
	int crime_id;  //Правонарушение
	std::string place;  //Место совершения
public:
	const int& get_crime()const
	{
		return crime_id;
	}
	const std::string& get_place()const
	{
		return place;
	}
	Crime() {}
	Crime(const int& crime_id, const std::string place) :crime_id(crime_id), place(place) {}
	~Crime() {}

	std::ostream& print(std::ostream& os)const
	{
		return os << crime.at(crime_id) << ", " << place << ";";
	}
	std::ofstream& print(std::ofstream& os)const
	{
		os << crime_id << place;
		return os;
	}

	std::istream& scan(std::istream& is)
	{
		is.clear();
		std::cout << "Выберите правонарушение:";
		is >> crime_id;
		std::cout << "Введите место совершения:";
		std::getline(is, place);
		return is;
	}
	std::ifstream& scan(std::ifstream& is)
	{
		is >> crime_id;
		std::getline(is, place, ',');
		return is;
	}
};
std::ostream& operator<<(std::ostream& os, const Crime& obj);
std::ofstream& operator<<(std::ofstream& os, const Crime& obj);
std::istream& operator>>(std::istream& is, Crime& obj);
std::ifstream& operator>>(std::ifstream& is, Crime& obj);
std::istream& getline(std::istream& is, Crime& obj);


