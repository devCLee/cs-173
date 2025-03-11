//==========================================
// CS 173
// Spring 2025
// Date.h
// A date class specification.
// Here we declare the functions and data
// members for a C++ class representing a
// Date Abstract Data Type (ADT).
//==========================================
#ifndef DATE_H // prevents conflicts if header file is included in multiple cpp files
#define DATE_H

class Date
{
    // public members are accessible in client code (like main.cpp)
    // we define public methods to allow clients to access and modify data members
    // in ways we control
    public:
        // define a month enumeration type, assign numerical values that match
        enum Month {JAN=1, FEB=2, MAR=3, APR=4, MAY=5, JUN=6, JUL=7, AUG=8, SEP=9, OCT=10, NOV=11, DEC=12};
        
        // constructors
        // used to create objects (specific instances of a class)
        Date(); // default constructor
        Date( Month m, int d, int y ); // allows a user to specify initial values for data members
        Date( const Date& d ); // copy constructor -- allows a user to create a Date object from another Date object

        // destructor
        // called when an object goes out of scope and is destroyed
        ~Date();

        // observers/accessors/getters
        Month getMonth() const; // const keyword means the compiler will not allow this method to change any data members
        int getDay() const;
        int getYear() const;
        void printDate() const;
        
        // transformers/mutators/setters
        void setMonth( Month m );
        void setDay( int d );
        void setYear( int y );
        void setDate( Month m, int d, int y );

    // private members can ONLY be used within the class definition (Date.cpp)
    // generally, we keep data members and helper methods private
    // so they can only be accessed/modified with public methods
    // what happens if you try to access these directly in main.cpp?
    private:
        // data members
        Month month;
        int day;
        int year;
        // private helper functions
        bool isLeapYear() const;
        bool isValidYear() const;
        bool isValidMonth() const;
        bool isValidDay() const;
        
};

#endif