//*********************************************************
// vetClinic.cpp
// CS 173, Spring 2025
// This program demonstrates input/output of enumerated
// types and introduces structs
// TO-DO:
//    1. Create a PatientRecord struct for a vet clinic
//       which contains a patient's name, species, age,
//       weight, associated weight unit, and most recent
//       and next scheduled appointments
//    2. Overload the toString() function to display all
//       the relevant info contained in a PatientRecord
//    3. Write a function that converts a Weight from one
//       Unit to another
//    4. Write functions that enable us to create a
//       PatientRecord from user input (start small:
//       how could we create a Time from user input?)
//*********************************************************
#include <iostream>
#include <string> // For string type
#include <limits> // For numeric_limits
using namespace std;

// Define enum, struct, and union types we will need
enum Month
{
  JAN,
  FEB,
  MAR,
  APR,
  MAY,
  JUN,
  JUL,
  AUG,
  SEP,
  OCT,
  NOV,
  DEC
};
enum Unit
{
  OZ,
  LBS,
  TONS
};

// We need to associate these 3 pieces of information with one another to describe a specific date
struct Date
{
  int day;
  Month month; // the type of month -> Month? or enum?
  int year;
};

struct Time
{
  int hours;
  int minutes;
};

// Hierarchical record: Appointments have a Date and Time
struct Appointment
{
  Time time;
  Date date;
};

// We can represent weight in different units
// but we only need to represent weight in one
// unit at any given time
union Weight
{
  long ounces;
  int pounds;
  float tons;
};

// PatientRecord struct - contains all information for a vet clinic patient
struct PatientRecord
{
  string name;
  string species;
  int age;
  Weight weight;
  Unit weightUnit;
  Appointment lastVisit;
  Appointment nextVisit;
};

// Function declarations
string toString(Month m);
string toString(Unit u);
string toString(Date d);
string toString(Time t);
string toString(Appointment appt);
string toString(PatientRecord patient);

// Weight conversion functions
Weight convertWeight(Weight originalWeight, Unit fromUnit, Unit toUnit);
float getWeightValue(Weight w, Unit u);

// Input functions
Time inputTime();
Date inputDate();
Appointment inputAppointment();
PatientRecord inputPatientRecord();

int main()
{
  // Month m = JUN;
  // Month summer[3] = {JUN, JUL, AUG};

  // Bundle together information about today's date in a struct
  Date today;
  today.day = 3;
  today.month = MAR;
  today.year = 2025;
  cout << "Today's date: " << toString(today) << endl;

  // Bundle together information about the current time in a struct
  Time now;
  now.hours = 11;
  now.minutes = 30;
  cout << "Current time: " << toString(now) << endl;

  // Bundle together information about the current date and time
  Appointment nextAppt;
  nextAppt.date = today;
  nextAppt.time = now;
  cout << "Next appointment: " << toString(nextAppt) << endl;

  // Create a sample patient record
  PatientRecord sopranoTheCat;
  sopranoTheCat.name = "Soprano";
  sopranoTheCat.species = "Cat";
  sopranoTheCat.age = 5;
  // sopranoTheCat.age = -15; ???
  sopranoTheCat.weight.pounds = 12;
  sopranoTheCat.weightUnit = LBS;
  sopranoTheCat.lastVisit = nextAppt;

  // Future appointment for Soprano
  Appointment futureAppt;
  futureAppt.date.day = 15;
  futureAppt.date.month = APR;
  futureAppt.date.year = 2025;
  futureAppt.time.hours = 14;
  futureAppt.time.minutes = 30;
  sopranoTheCat.nextVisit = futureAppt;

  cout << "\nPatient Record:\n"
       << toString(sopranoTheCat) << endl;

  // Demonstrate weight conversion
  cout << "\nConverting Soprano's weight from pounds to ounces:" << endl;
  Weight ozWeight = convertWeight(sopranoTheCat.weight, sopranoTheCat.weightUnit, OZ);
  cout << sopranoTheCat.name << " weighs " << sopranoTheCat.weight.pounds << " pounds, which is "
       << ozWeight.ounces << " ounces." << endl;

  // Create a new patient record from user input
  cout << "\nEnter a new patient record:" << endl;
  PatientRecord newPatient = inputPatientRecord();
  cout << "\nNew Patient Record:\n"
       << toString(newPatient) << endl;

  return 0;
}

//*********************************************************
// toString
// PARAMETER: Month m, an enumerated month value
// RETURN: a string representation of m
//*********************************************************
string toString(Month m)
{
  // returning breaks us out of the function call
  // which means in this situation, we do not need
  // break statements to prevent fallthrough in our
  // switch statement
  switch (m)
  {
  case JAN:
  {
    return "January";
  }
  case FEB:
  {
    return "February";
  }
  case MAR:
  {
    return "March";
  }
  case APR:
  {
    return "April";
  }
  case MAY:
  {
    return "May";
  }
  case JUN:
  {
    return "June";
  }
  case JUL:
  {
    return "July";
  }
  case AUG:
  {
    return "August";
  }
  case SEP:
  {
    return "September";
  }
  case OCT:
  {
    return "October";
  }
  case NOV:
  {
    return "November";
  }
  default:
  { // only one option left
    return "December";
  }
  }
}

//*********************************************************
// toString
// PARAMETER: Unit u, an enumerated weight unit value
// RETURN: a string representation of u
//*********************************************************
string toString(Unit u)
{
  // returning breaks us out of the function call
  // which means in this situation, we do not need
  // break statements to prevent fallthrough in our
  // switch statement
  switch (u)
  {
  case OZ:
  {
    return "ounces";
  }
  case LBS:
  {
    return "pounds";
  }
  default:
  { // only one option left
    return "tons";
  }
  }
}

//*********************************************************
// toString
// PARAMETER: Date d, a date record
// RETURN: a string representation of d
//*********************************************************
string toString(Date d)
{
  // construct string using our Month toString() function,
  // std::to_string() for int values, and string literals
  // with concatenation
  return toString(d.month) + " " + to_string(d.day) + ", " + to_string(d.year);
}

//*********************************************************
// toString
// PARAMETER: Time t, a time record
// RETURN: a string representation of t
//*********************************************************
string toString(Time t)
{
  // Ensure minutes are always displayed with two digits
  string minutes = to_string(t.minutes);
  if (t.minutes < 10)
  {
    minutes = "0" + minutes;
  }

  // construct string using std::to_string() for int values
  // and string literals with concatenation
  return to_string(t.hours) + ":" + minutes;
}

//*********************************************************
// toString
// PARAMETER: Appointment appt, an appointment record
// RETURN: a string representation of appt
//*********************************************************
string toString(Appointment appt)
{
  // construct string using our Date and Time toString functions
  // and string literals with concatenation
  return toString(appt.time) + ", " + toString(appt.date);
}

//*********************************************************
// toString
// PARAMETER: PatientRecord patient, a patient record
// RETURN: a string representation of the patient record
//*********************************************************
string toString(PatientRecord patient)
{
  // Build a string with all patient information
  string result = "Name: " + patient.name + "\n";
  result += "Species: " + patient.species + "\n";
  result += "Age: " + to_string(patient.age) + " years\n";

  // Add weight information with the appropriate unit
  switch (patient.weightUnit)
  {
  case OZ:
    result += "Weight: " + to_string(patient.weight.ounces) + " " + toString(patient.weightUnit) + "\n";
    break;
  case LBS:
    result += "Weight: " + to_string(patient.weight.pounds) + " " + toString(patient.weightUnit) + "\n";
    break;
  case TONS:
    result += "Weight: " + to_string(patient.weight.tons) + " " + toString(patient.weightUnit) + "\n";
    break;
  }

  // Add appointment information
  result += "Last Visit: " + toString(patient.lastVisit) + "\n";
  result += "Next Visit: " + toString(patient.nextVisit);

  return result;
}

//*********************************************************
// getWeightValue
// Helper function to get the actual weight value from a Weight union
// PARAMETERS:
//   Weight w - the weight to extract the value from
//   Unit u - the unit of the weight
// RETURN: the weight value as a float
//*********************************************************
float getWeightValue(Weight w, Unit u)
{
  switch (u)
  {
  case OZ:
    return static_cast<float>(w.ounces);
  case LBS:
    return static_cast<float>(w.pounds);
  case TONS:
    return w.tons;
  default:
    return 0.0f; // Shouldn't reach here
  }
}

//*********************************************************
// convertWeight
// Converts a weight from one unit to another
// PARAMETERS:
//   Weight originalWeight - the weight to convert
//   Unit fromUnit - the original unit
//   Unit toUnit - the target unit
// RETURN: a Weight union containing the converted weight in the target unit
//*********************************************************
Weight convertWeight(Weight originalWeight, Unit fromUnit, Unit toUnit)
{
  // Get the original weight value
  float originalValue = getWeightValue(originalWeight, fromUnit);

  // Convert to a standard unit (ounces) first
  float ouncesValue;
  switch (fromUnit)
  {
  case OZ:
    ouncesValue = originalValue;
    break;
  case LBS:
    ouncesValue = originalValue * 16.0f; // 16 oz in a pound
    break;
  case TONS:
    ouncesValue = originalValue * 32000.0f; // 2000 lbs in a ton, 16 oz in a lb
    break;
  }

  // Convert from ounces to the target unit
  Weight result;
  switch (toUnit)
  {
  case OZ:
    result.ounces = static_cast<long>(ouncesValue);
    break;
  case LBS:
    result.pounds = static_cast<int>(ouncesValue / 16.0f);
    break;
  case TONS:
    result.tons = ouncesValue / 32000.0f;
    break;
  }

  return result;
}

//*********************************************************
// inputTime
// Prompts the user to input a time
// RETURN: a Time struct with the user-input values
//*********************************************************
Time inputTime()
{
  Time t;

  // Get hours
  cout << "Enter hours (0-23): ";
  cin >> t.hours;

  // Input validation
  while (cin.fail() || t.hours < 0 || t.hours > 23)
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid entry. Please enter hours (0-23): ";
    cin >> t.hours;
  }

  // Get minutes
  cout << "Enter minutes (0-59): ";
  cin >> t.minutes;

  // Input validation
  while (cin.fail() || t.minutes < 0 || t.minutes > 59)
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid entry. Please enter minutes (0-59): ";
    cin >> t.minutes;
  }

  return t;
}

//*********************************************************
// inputDate
// Prompts the user to input a date
// RETURN: a Date struct with the user-input values
//*********************************************************
Date inputDate()
{
  Date d;
  int monthNum;

  // Get year
  cout << "Enter year: ";
  cin >> d.year;

  // Input validation
  while (cin.fail() || d.year < 0)
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid entry. Please enter a valid year: ";
    cin >> d.year;
  }

  // Get month
  cout << "Enter month (1-12): ";
  cin >> monthNum;

  // Input validation
  while (cin.fail() || monthNum < 1 || monthNum > 12)
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid entry. Please enter month (1-12): ";
    cin >> monthNum;
  }

  // Convert month number to Month enum
  d.month = static_cast<Month>(monthNum - 1);

  // Get day
  cout << "Enter day (1-31): ";
  cin >> d.day;

  // Basic input validation (doesn't account for different days in months)
  while (cin.fail() || d.day < 1 || d.day > 31)
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid entry. Please enter day (1-31): ";
    cin >> d.day;
  }

  return d;
}

//*********************************************************
// inputAppointment
// Prompts the user to input an appointment (date and time)
// RETURN: an Appointment struct with the user-input values
//*********************************************************
Appointment inputAppointment()
{
  Appointment appt;

  cout << "Enter appointment date:" << endl;
  appt.date = inputDate();

  cout << "Enter appointment time:" << endl;
  appt.time = inputTime();

  return appt;
}

//*********************************************************
// inputPatientRecord
// Prompts the user to input a complete patient record
// RETURN: a PatientRecord struct with the user-input values
//*********************************************************
PatientRecord inputPatientRecord()
{
  PatientRecord patient;
  int unitChoice;

  // Clear input buffer
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  // Get patient name
  cout << "Enter patient name: ";
  getline(cin, patient.name);

  // Get species
  cout << "Enter species: ";
  getline(cin, patient.species);

  // Get age
  cout << "Enter age in years: ";
  cin >> patient.age;

  // Input validation
  while (cin.fail() || patient.age < 0)
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid entry. Please enter a valid age: ";
    cin >> patient.age;
  }

  // Get weight unit
  cout << "Select weight unit (1 for ounces, 2 for pounds, 3 for tons): ";
  cin >> unitChoice;

  // Input validation
  while (cin.fail() || unitChoice < 1 || unitChoice > 3)
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid entry. Select weight unit (1 for ounces, 2 for pounds, 3 for tons): ";
    cin >> unitChoice;
  }

  // Set the weight unit
  patient.weightUnit = static_cast<Unit>(unitChoice - 1);

  // Get weight value based on selected unit
  cout << "Enter weight in " << toString(patient.weightUnit) << ": ";
  switch (patient.weightUnit)
  {
  case OZ:
    cin >> patient.weight.ounces;
    break;
  case LBS:
    cin >> patient.weight.pounds;
    break;
  case TONS:
    cin >> patient.weight.tons;
    break;
  }

  // Input validation (basic - just checks for failed input)
  while (cin.fail())
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid entry. Enter weight in " << toString(patient.weightUnit) << ": ";

    switch (patient.weightUnit)
    {
    case OZ:
      cin >> patient.weight.ounces;
      break;
    case LBS:
      cin >> patient.weight.pounds;
      break;
    case TONS:
      cin >> patient.weight.tons;
      break;
    }
  }

  // Get appointment information
  cout << "\nEnter last visit information:" << endl;
  patient.lastVisit = inputAppointment();

  cout << "\nEnter next visit information:" << endl;
  patient.nextVisit = inputAppointment();

  return patient;
}