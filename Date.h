#include <iostream>
#include <string>

struct Date {
private:
	int day = 0;
	int month = 0;
	int year = 0;

public:
	bool is_valid_day(int* const& day);
	bool is_valid_month(int* const& month);
	bool is_valid_year(int* const& year);

	void set_day(int* const& day);
	void set_month(int* const& month);
	void set_year(int* const& year);

	int get_day();
	int get_month();
	int get_year();
	std::string to_string();



	Date();
	Date(int day, int month, int year);

	~Date() {};
};