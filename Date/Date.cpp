//====================================================================================
// CS 173
// Spring 2025
// Date.cpp
// A date class implementation.
// Contains definitions for all methods
// declared in Date.h
// Note: this program does not have a main function! Compiling this file on its own
//          will not create a runnable executable file.
//          This file will need to be compiled along with client code (like main.cpp) that
//          includes a main function and creates Date objects.
// TO-DO: implement private helper functions!
//====================================================================================

#include "Date.h" // need to include function declarations before definitions
#include <iostream>

//====================================================================================
// Constructors
// Used to create objects (specific instances of a class)
//====================================================================================

//====================================================================================
// Default Date constructor
// Sets date to 1/1/2025
// Called when no parameters are given
//====================================================================================
Date::Date()
{
    // normally we wouldn't print in a constructor, but this lets us see when the
    // constructor is called.
    std::cout << "Default constructor called. Setting date to 1/1/2025." << std::endl; // You generally do not put cout in the constructor

    // set data members for the created Date object
    month = JAN;
    day = 1;
    year = 2025;
}

//====================================================================================
// Standard Date constructor
// Sets data members based on specified parameters
// Uses helper functions to check if specified values are valid; uses default values
// if not
//====================================================================================
Date::Date(Month m, int d, int y)
{
    // normally we wouldn't print in a constructor, but this lets us see when the
    // constructor is called.
    std::cout << "Standard constructor called. Setting date to " << m << "/" << d << "/" << y << "." << std::endl;

    // set data members for the created Date object
    month = m;
    day = d;
    year = y;

    // check whether values are valid, use default values if not
    if (!isValidYear())
    {
        std::cout << "Invalid year provided. Setting to 2025." << std::endl;
        year = 2025;
    }
    if (!isValidMonth())
    {
        std::cout << "Invalid month provided. Setting to January." << std::endl;
        month = JAN;
    }
    if (!isValidDay())
    {
        std::cout << "Invalid day provided. Setting to 1." << std::endl;
        day = 1;
    }
}

//====================================================================================
// Date copy constructor
// Sets data members based on another Date object passed by address
// const is used to prevent changing the parameter Date object
// We don't need to use helper functions because any Date object can only have valid
// member values
//====================================================================================
Date::Date(const Date &d)
{
    // normally we wouldn't print in a constructor, but this lets us see when the
    // constructor is called.
    std::cout << "Copy constructor called. Setting date to " << d.month << "/" << d.day << "/" << d.year << "." << std::endl;

    // set data members for the created Date object
    // use dot notation to access the parameter Date object's members
    // we can access these directly here even though they are private
    // because we are in the class definition
    month = d.month;
    day = d.day;
    year = d.year;
}

//====================================================================================
// Date destructor
// Called when an object goes out of scope/is destroyed
// Doesn't do much in this class, but this will let us see when the destructor is called
//====================================================================================
Date::~Date()
{
    // normally we wouldn't print in a destructor, but this lets us see when the
    // destructor is called.
    std::cout << "Destructor called. Destroying date object with values: " << month << "/" << day << "/" << year << "." << std::endl;
}

//====================================================================================
// Observers/Accessors/Getters
// Do not change data members but allow client code to access them
//====================================================================================

//====================================================================================
// getMonth()
// Parameters: None
// Returns: Month month (the month member of the calling Date object)
//====================================================================================
Date::Month Date::getMonth() const
{
    return month;
};

//====================================================================================
// getDay()
// Parameters: None
// Returns: int day (the day member of the calling Date object)
//====================================================================================
int Date::getDay() const
{
    return day;
};

//====================================================================================
// getYear()
// Parameters: None
// Returns: int year (the year member of the calling Date object)
//====================================================================================
int Date::getYear() const
{
    return year;
};

//====================================================================================
// printDate()
// Parameters: None
// Returns: void, but prints a string representing the calling Date object in
//          mm/dd/yyyy format
//====================================================================================
void Date::printDate() const
{
    // include leading 0 if month has only one digit
    if (month < OCT)
    {
        std::cout << 0;
    }

    std::cout << month << "/";

    // include leading 0 if day has only one digit
    if (day < 10)
    {
        std::cout << 0;
    }

    std::cout << day << "/";

    // include leading 0s if needed for year
    if (year < 1000)
    {
        std::cout << 0;
        if (year < 100)
        {
            std::cout << 0;
            if (year < 10)
            {
                std::cout << 0;
            }
        }
    }

    std::cout << year;
};

//====================================================================================
// Transformers/Mutators/Setters
// Allow client code to change data members
//====================================================================================

//====================================================================================
// setMonth()
// Parameters:  Month m
// Returns: void, but sets the month data member of the calling object to m as long
//          as it is valid
//====================================================================================
void Date::setMonth(Month m)
{
    // hold prior value of month in case the new value is invalid
    Month oldMonth = month;
    // set month member to provided value
    month = m;
    // if new value is not compatible with day and year, reset to previous value
    if (!isValidMonth())
    {
        std::cout << "Provided month: " << m << " is invalid. Resetting to: " << oldMonth << std::endl;
        month = oldMonth;
    }
}

//====================================================================================
// setDay()
// Parameters:  int d
// Returns: void, but sets the day data member of the calling object to d as long
//          as it is valid
//====================================================================================
void Date::setDay(int d)
{
    // hold prior value of day in case the new value is invalid
    int oldDay = day;
    // set day member to provided value
    day = d;
    // if new value is not compatible with month and year, reset to previous value
    if (!isValidDay())
    {
        std::cout << "Provided day: " << d << " is invalid. Resetting to: " << oldDay << std::endl;
        day = oldDay;
    }
}

//====================================================================================
// setYear()
// Parameters:  int y
// Returns: void, but sets the year data member of the calling object to y as long
//          as it is valid
//====================================================================================
void Date::setYear(int y)
{
    // hold prior value of year in case the new value is invalid
    int oldYear = year;
    // set year member to provided value
    year = y;
    // if new value is not compatible with month and year, reset to previous value
    if (!isValidYear())
    {
        std::cout << "Provided year: " << y << " is invalid. Resetting to: " << oldYear << std::endl;
        year = oldYear;
    }
}

//====================================================================================
// setDate()
// Parameters:  Month m, int d, int y
// Returns: void, but sets the data members of the calling object to parameter values
//          as long as they are a valid combo
//====================================================================================
void Date::setDate(Month m, int d, int y)
{
    // hold prior values of data members in case the new date is invalid
    // uses the standard constructor to temporarily create a backup copy Date object
    Date backup(month, day, year); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    // set members to provided values
    month = m;
    day = d;
    year = y;

    // if new date is not valid, reset to previous value
    if (!(isValidDay() && isValidMonth() && isValidYear()))
    {
        std::cout << "Provided date: " << m << "/" << d << "/" << y << " is invalid. Resetting to: ";
        backup.printDate();
        std::cout << std::endl;
        month = backup.month;
        day = backup.day;
        year = backup.year;
    }
}

//====================================================================================
// Private helper functions
// Cannot be used outside Date.cpp (class definition)
// Just stubs for now! Implement the logic for these
//====================================================================================

//====================================================================================
// isLeapYear()
// Parameters:  None
// Returns: true if the calling date object's year member is a leap year, false otherwise
// A year is a leap year if it is EITHER:
//      1) Divisible by 4 but not divisible by 100
//      2) Divisible by 400
// Use this function when implementing the other helper functions
//====================================================================================
bool Date::isLeapYear() const
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

//====================================================================================
// isValidYear()
// Parameters:  None
// Returns: true if the calling date object's year member is valid with the day and
//          month; false otherwise
//====================================================================================
bool Date::isValidYear() const
{
    return year >= 1 && year <= 9999;
}

//====================================================================================
// isValidMonth()
// Parameters:  None
// Returns: true if the calling date object's month member is valid with the day and
//          year; false otherwise
//====================================================================================
bool Date::isValidMonth() const
{
    return month >= JAN && month <= DEC;
}

//====================================================================================
// isValidDay()
// Parameters:  None
// Returns: true if the calling date object's day member is valid with the year and
//          month; false otherwise
//====================================================================================
bool Date::isValidDay() const
{

    if (day <= 0)
        return false;

    switch (month)
    {

    case JAN:
    case MAR:
    case MAY:
    case JUL:
    case AUG:
    case OCT:
    case DEC:
        return day <= 31;

    case APR:
    case JUN:
    case SEP:
    case NOV:
        return day <= 30;

    case FEB:
        if (isLeapYear())
            return day <= 29;
        else
            return day <= 28;

    default:
        return false;
    }
}