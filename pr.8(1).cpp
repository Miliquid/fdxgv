#include <iostream>

using namespace std;

class Date
{
private:
int day; 		// день
int month; 	// месяц
int year; 		// годa

public:

// конструктор по умолчанию
Date()
{
day = 1;
month = 1;
year = 1900;
}

// конструктор с параметрами
Date(int d, int m, int y)
{
this->day = d;		// или day = d;		
this->month = m;		// или month = m;
this->year = y;		// илиyear = y;
}

//Ключевое слово this указывает, что обращение идёт к полям данного класса

// конструктор копирования
Date(Date &d)
{
day = d.day;
month = d.month;
year = d.year;
}


// деструктор 
~Date() {}

// set-методы 

void setDay(int d) {if (d < 31) day = d;}

void setMonth(int m){if (m < 12) month = m;}

void setYear(int y){year = y;}

// get-методы 

int getDay() {return day;}

int getMonth(){return month;}

int getYear(){return year;}
// метод вывода названия месяца по его номеру
 
string getMonthName()
    {
if (month == 1) return"январь";
else if (month == 2) return"февраль";
else if (month == 3) return"март";
else if (month == 4) return"апрель";
else if (month == 5) return"май";
else if (month == 6) return"июнь";
else if (month == 7) return"июль";
else if (month == 8) return"август";
else if (month == 9) return"сентябрь";
else if (month == 10) return"октябрь";
else if (month == 11) return"ноябрь";
else if (month == 12) return"декабрь";
else return "";
    }
}
    
// перегрузка оператора префиксного инкремента "++" 
Date  operator ++ ()
{
if (this->day + 1 > 31)
    {
        this->day = 1;
	if (this->month + 1 > 12)
        {
            this->month = 1;
            this->year++;
        }
	else
        {
            this->month++;  
        }
    }
else
    {
        this->day++;
    }
    return *this;      
}

// перегрузка оператора ">"
const bool operator > (Date const & dd)
{
if (dd.year > this->year) return false;
if (dd.year == this->year &&  dd.month > this->month) return false;
if (dd.year == this->year &&  dd.month == this->month &&  dd.day > this->day) return false;
return true;
}

// перегрузка оператора "==" 
const bool operator == (const Date & dd)
{
if (this->year== dd.year  && this->month== dd.month && this->day== dd.day) return 1;
return 0;
}
};

// Главная функция
{

Date d1(1, 1, 2016);
Date d2(2, 2, 2017);
cout<<"Первая дата:\t"<<d1.getDay()<<"."<<d1.getMonthName()<<"."<<d1.getYear();
cout<<"\Вторая дата:\t"<<d2.getDay()<<"."<<d2.getMonthName()<<"."<<d2.getYear();
if (d1 > d2)
    {
cout<<"\nПервая дата больше второй";
    }
    else
    {	
cout<<"\nВторая дата больше первой";
    }

Date d;
d.setDay(12);
d.setMonth(6);
d.setYear(2017);
cout<<"\nЗадана дата:\t"<<d.getDay()<<"."<<d.getMonthName()<<"."<<d.getYear();    

++d;
cout<<"\nСледующая дата:\t"<<d.getDay()<<"."<<d.getMonthName()<<"."<<d.getYear();
 
}
