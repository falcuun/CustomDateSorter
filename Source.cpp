#include "Date.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void split(const std::string& str, std::vector<std::string>& cont, char delim = ' ')
{
	std::size_t current, previous = 0;
	current = str.find(delim);
	while (current != std::string::npos) {
		cont.push_back(str.substr(previous, current - previous));
		previous = current + 1;
		current = str.find(delim, previous);
	}
	cont.push_back(str.substr(previous, current - previous));
}


struct sorting_years
{
	inline bool operator() (Date& date1, Date& date2)
	{
		if (date1.get_year() < date2.get_year())
		{
			return true;
		}
		if (date1.get_year() == date2.get_year() && date1.get_month() < date2.get_month())
		{
			return true;
		}
		if (date1.get_year() == date2.get_year() && date1.get_month() == date2.get_month() && date1.get_day() < date2.get_day())
		{
			return true;
		}
		return false;
	}
};

int main()
{
	std::ifstream dates("dates.txt");

	std::vector<Date> all_dates;

	Date new_date;
	std::string line;


	while (dates.peek() != EOF) {
		std::getline(dates, line);
		std::vector<std::string> dates_array;
		split(line, dates_array, '/');

		int day = std::stoi(dates_array.at(0));
		int month = std::stoi(dates_array.at(1));
		int year = std::stoi(dates_array.at(2));

		int init_size = line.length();

		new_date.set_day(&day);
		new_date.set_month(&month);
		new_date.set_year(&year);

		all_dates.push_back(new_date);
	}

	std::sort(all_dates.begin(), all_dates.end(), sorting_years());

	for (Date d : all_dates)
	{
		std::cout << d.to_string() << std::endl;
	}

	dates.close();
}
