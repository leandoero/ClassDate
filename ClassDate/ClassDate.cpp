
#include "ClassDate.h";

Date::Date() {					//конструктор без параметров
	year = 0;
	month = 0;
	day = 0;
}
Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}			//констуктор с параметрами
Date::Date(string date) {
	Set(date);
}
void Date::Set(string date) {
	std::istringstream dateStream(date);		//используем для разбора строки 
	char delimiter;
	dateStream >> this->year >> delimiter >> this->month >> delimiter >> this->day;
	if (month < 1 || month > 12) {
		start();
	}
	else if (day < 1 || day > 31) {
		start();
	}
	else if (year < 0) {
		start();
	}
}
unsigned int Date::GetYear() {
	return year;
}
unsigned int Date::GetMonth() {
	return month;
}
unsigned int Date::GetDay() {
	return day;
}
void Date::dateInDays(unsigned int daysToBeRealized, unsigned int year, unsigned int month, unsigned int day) {
	int count = 0;
	int daysForOutput = 0;
	bool flag = true;
	while (flag) {
		for (int i = year; ; i++)
		{
			for (int i = month; i < 13; i++)
			{
				if (month % 2 == 0) {
					count = 30;
					if (Months::February == static_cast<Months>(month)) {
						if (leapYear(year) == 1) {
							count = 29;
						}
						else {
							count = 28;
						}
					}
					else if (Months::August == static_cast<Months>(month) || Months::October == static_cast<Months>(month) || Months::December == static_cast<Months>(month)) {
						count = 31;
					}
				}
				else {
					count = 31;
					if (Months::September == static_cast<Months>(month) || Months::November == static_cast<Months>(month)) {
						count = 30;
					}
				}
				if ((day + daysToBeRealized) <= count && day > 0) {
					daysForOutput = day + daysToBeRealized;
					flag = false;
					break;
				}
				else if ((day + daysToBeRealized) > count && day > 0) {
					daysToBeRealized -= (count - day);
					month++;
					day = 0;
					continue;
				}
				else if (day == 0 && daysToBeRealized > count) {
					daysToBeRealized -= count;
					month++;
					continue;
				}
				else if (day == 0 && daysToBeRealized <= count) {
					daysForOutput = daysToBeRealized;
					flag = false;
					break;
				}

			}
			if (month >= 13) {
				year++;
				month = 1;
			}
			if (flag == false) {
				break;
			}
		}
	}
	cout << year << "." << (month < 10 ? "0" : "") << month << "."
		<< ((daysForOutput) < 10 ? "0" : "") << daysForOutput << endl;

}
void Date::DateInDaysBack(unsigned int daysToBeRealized, unsigned int year, unsigned int month, unsigned int day) {
	int count = 0;
	int daysForOutput = 0;
	bool flag = true;
	while (flag) {
		for (int i = year; i > 0; i--)
		{
			for (int j = month; j > 0; j--)
			{
				if (j % 2 == 0) {
					count = 30;
					if (Months::February == static_cast<Months>(j)) {
						if (leapYear(i) == 1) {
							count = 29;
						}
						else {
							count = 28;
						}
					}
					else if (Months::August == static_cast<Months>(j) || Months::October == static_cast<Months>(j) || Months::December == static_cast<Months>(j)) {
						count = 31;
					}
				}
				else {
					count = 31;
					if (Months::September == static_cast<Months>(j) || Months::November == static_cast<Months>(j)) {
						count = 30;
					}
				}
				if (day > 0 && daysToBeRealized >= day) {
					daysToBeRealized -= day;
					month--;
					day = 0;
					continue;
				}
				else if (day > 0 && daysToBeRealized < day) {
					day -= daysToBeRealized;
					daysForOutput = day;
					flag = false;
					break;
				}
				else if (day == 0 && daysToBeRealized >= count) {
					daysToBeRealized -= count;
					month--;
					count = 0;
					continue;
				}
				else if (day == 0 && daysToBeRealized < count) {
					count -= daysToBeRealized;
					daysForOutput = count;
					flag = false;
					break;
				}
			}
			if (month <= 1) {
				year--;
				month = 12;
			}
			if (flag == false) {
				break;
			}
		}

	}
	cout << year << "." << (month < 10 ? "0" : "") << month << "."
		<< (daysForOutput < 10 ? "0" : "") << daysForOutput << endl;

}
void Date::ConvertDateToDays(unsigned int year, unsigned int month, unsigned int day, Date date, int& days)
{
	int count = 0;
	for (int i = year; i > 0; i--)
	{
		for (int j = month; j > 0; j--)
		{
			if (j % 2 == 0) {
				count = 30;
				if (Months::February == static_cast<Months>(j)) {
					if (date.leapYear(i) == 1) {
						count = 29;
					}
					else {
						count = 28;
					}
				}
				else if (Months::August == static_cast<Months>(j) || Months::October == static_cast<Months>(j) || Months::December == static_cast<Months>(j)) {
					count = 31;
				}
			}
			else {
				count = 31;
				if (Months::September == static_cast<Months>(j) || Months::November == static_cast<Months>(j)) {
					count = 30;
				}
			}
			if (day > 0) {
				days += day;
				day = 0;

				continue;
			}
			else {
				days += count;
			}
		}
		month = 12;
	}
}
bool Date::leapYear(unsigned int year) {
	if (year % 4 == 0) {
		if (year % 100 != 0) {
			return true;
		}
		else {
			if (year % 400 != 0) {
				return false;
			}
			else {
				return true;
			}
		}
	}
	else {
		return false;
	}
}
bool Date::DateComparison(Date date, unsigned int year, unsigned int month, unsigned int day, bool& flag) {
	if (date.GetYear() > year) {
		return true;
	}
	else if (date.GetYear() < year) {
		return false;
	}
	else if (date.GetYear() == year) {
		if (date.GetMonth() > month) {
			return true;
		}
		else if (date.GetMonth() < month) {
			return false;
		}
		else if (date.GetMonth() == month) {
			if (date.GetDay() > day) {
				return true;
			}
			else if (date.GetDay() < day) {
				return false;
			}
			else if (date.GetDay() == day) {
				flag = true;
				return flag;
			}
		}
	}
}
string Date::toString() {	//информация об объекте в виде строки
	return "class Date(year = " + to_string(GetYear()) + ", month = " + to_string(GetMonth()) + ", day = " + to_string(GetDay()) + ")";
}


void Check(char& choice) {
	char yesNo{};
	do {
		cout << "Продолжить? y/n : ";
		cin >> yesNo;
	} while (toupper(yesNo) != 89 && toupper(yesNo) != 78);
	choice = yesNo;
}
void operations(Date date) {
	unsigned int choiceAnother = 0;
	char choice{};
	do {
		system("cls");
		cout << "Выберите нужную операцию:\n" <<
			"1.Вычисление даты через заданное количество дней\n" <<
			"2.Вычитание заданного количества дней из даты\n" <<
			"3.Определение високосности года\n" <<
			"4.Сравнение дат (равно, до, после)\n" <<
			"5.Вычисление количества дней между датами.\n" <<
			"6.Информацию об объекте.\n\n"
			"7.Выход.\n" << endl;
		cout << "Ввод : ";

		cin >> choiceAnother;
		if (cin.fail()) {
			cin.clear();
			std::cin.ignore(32767, '\n');
		}

		switch (choiceAnother)
		{
		case 1: {
			cout << "Введите количество дней : ";

			int days = 0;
			cin >> days;
			if (cin.fail()) {
				cin.clear();
				std::cin.ignore(32767, '\n');
				break;
			}
			else if (days < 0) {
				break;
			}
			date.dateInDays(days, date.GetYear(), date.GetMonth(), date.GetDay());
			Check(choice);

			break;
		}
		case 2: {
			cout << "Введите количество дней : ";

			int days = 0;
			cin >> days;
			if (cin.fail()) {
				cin.clear();
				std::cin.ignore(32767, '\n');
				break;
			}
			else if (days < 0) {
				break;
			}
			date.DateInDaysBack(days, date.GetYear(), date.GetMonth(), date.GetDay());
			Check(choice);
			break;
		}
		case 3: {
			if (date.leapYear(date.GetYear()) == 1) {
				cout << "Год - високосный" << endl;
			}
			else {
				cout << "Год не високосный" << endl;
			}
			Check(choice);
			break;
		}
		case 4: {
			int year = 0, month = 0, day = 0;
			bool flag = false;
			cout << "Введите год, месяц, день : ";
			cin >> year >> month >> day;
			if (cin.fail()) {
				cin.clear();
				std::cin.ignore(32767, '\n');
				break;
			}
			else if (month < 1 || month > 12) {
				break;
			}
			else if (day < 1 || day > 31) {
				break;
			}
			else if (year < 0) {
				break;
			}
			date.DateComparison(date, year, month, day, flag);
			if (date.DateComparison(date, year, month, day, flag) == 1 && flag == false) {
				cout << date.GetYear() << "." << date.GetMonth() << "." << date.GetDay() << " > " << year << "." <<
					month << "." << day << endl;
			}
			else if (date.DateComparison(date, year, month, day, flag) == 0 && flag == false) {
				cout << date.GetYear() << "." << date.GetMonth() << "." << date.GetDay() << " < " << year << "." <<
					month << "." << day << endl;
			}
			else if (flag == true) {
				cout << date.GetYear() << "." << date.GetMonth() << "." << date.GetDay() << " = " << year << "." <<
					month << "." << day << endl;
			}
			Check(choice);
			break;
		}
		case 5: {
			int days = 0, daysForSecond = 0, year = 0, month = 0, day = 0;
			date.ConvertDateToDays(date.GetYear(), date.GetMonth(), date.GetDay(), date, days);

			cout << "Введите год, месяц, день : ";
			cin >> year >> month >> day;
			if (cin.fail()) {
				cin.clear();
				std::cin.ignore(32767, '\n');
				break;
			}
			else if (month < 1 || month > 12) {
				break;
			}
			else if (day < 1 || day > 31) {
				break;
			}
			else if (year < 0) {
				break;
			}
			Date _date_(year, month, day);
			_date_.ConvertDateToDays(_date_.GetYear(), _date_.GetMonth(), _date_.GetDay(), _date_, daysForSecond);
			cout << abs(days - daysForSecond) << endl;
			Check(choice);
			break;
		}
		case 6: {
			cout << date.toString() << endl;
			Check(choice);
			break;
		}
		case 7: {
			choice = 'n';
			break;
		}
		default: {
			break;
		}
		}
	} while (choiceAnother != 7 && toupper(choice) != 78);
}
void start() {
	setlocale(LC_ALL, "ru");
	unsigned int choice = 0;
	do {
		system("cls");
		cout << "Выберите метод инициализации:\n" <<
			"1. Числами (год, месяц, день)\n" <<
			"2. Строкой вида <год.месяц.день>\n\n" <<
			"3. Перейти к операциям\n\n" <<
			"4. Выход\n" << endl;
		cout << "Ввод : ";
		cin >> choice;
		if (cin.fail()) {
			cin.clear();
			std::cin.ignore(32767, '\n');
		}
		switch (choice)
		{
		case 1: {
			int year = 0, month = 0, day = 0;
			cout << "Введите год, месяц, день : ";
			cin >> year >> month >> day;
			if (cin.fail()) {
				cin.clear();
				std::cin.ignore(32767, '\n');
				break;
			}
			else if (month < 1 || month > 12) {
				break;
			}
			else if (day < 1 || day > 31) {
				break;
			}
			else if (year < 0) {
				break;
			}
			Date date(year, month, day);
			operations(date);
			break;
		}
		case 2: {

			string dateString;
			cout << "Введите строку в формате <год.месяц.день> : ";
			cin >> dateString;
			Date _date(dateString);
			operations(_date);
			break;
		}
		case 3: {
			Date date;
			operations(date);
			break;
		}
		case 4: {
			cout << "Выход..." << endl;
			break;
		}
		default: {
			cout << "Неверный ввод" << endl;
			break;
		}
		}
	} while (choice != 3 && choice != 4);
}