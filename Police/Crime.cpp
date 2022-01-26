#include "Crime.h"

const  std::map<int, std::string>& crime =
{
	std::pair<int,std::string>(1,"Привышение скорости"),
	std::pair<int,std::string>(2,"Проезд на красный"),
	std::pair<int,std::string>(3,"Выезд на встречную полосу"),
	std::pair<int,std::string>(4,"Пересечие сплошной"),
	std::pair<int,std::string>(5,"Парковка в неположенном месте"),
	std::pair<int,std::string>(6,"Оскорбление офицера"),
	std::pair<int,std::string>(7,"Разговор по телефону во время движения"),
	std::pair<int,std::string>(8,"Дрифт на перекрестке"),
};

std::ostream& operator<<(std::ostream& os, const Crime& obj)
{
	return obj.print(os);
}
std::ofstream& operator<<(std::ofstream& os, const Crime& obj)
{
	return obj.print(os);
}

std::istream& operator>>(std::istream& is, Crime& obj)
{
	return obj.scan(is);
}

std::istream& getline(std::istream& is, Crime& obj)
{
	return obj.scan(is);
}
