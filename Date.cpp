#include "Date.h"

Date::Date() {}

Date::Date(int day, int month, int year)
{
	if (is_valid_day(&day))
	{
		this->day = day;
	}
	if (is_valid_month(&month))
	{
		this->month = month;
	}
	if (is_valid_year(&year))
	{
		this->year = year;
	}
}

bool Date::is_valid_day(int* const& day)
{
	if (*day > 0 && *day < 32)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Date::is_valid_month(int* const& month)
{
	if (*month > 0 && *month < 13)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Date::is_valid_year(int* const& year)
{
	if (*year > 1901 && *year < 9999)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Date::set_day(int* const& day)
{
	if (is_valid_day(day))
	{
		this->day = *day;
	}
}

void Date::set_month(int* const& month)
{
	if (is_valid_month(month))
	{
		this->month = *month;
	}
}

void Date::set_year(int* const& year)
{
	if (is_valid_year(year))
	{
		this->year = *year;
	}
}

int Date::get_day()
{
	return this->day;
}

int Date::get_month()
{
	return this->month;
}

int Date::get_year()
{
	return this->year;
}

std::string Date::to_string()
{
	return  std::to_string(get_day()) + "/" + std::to_string(get_month()) + "/" + std::to_string(get_year());
}
