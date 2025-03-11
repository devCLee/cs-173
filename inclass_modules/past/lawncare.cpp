//********************************************************************
// CS 173, Spring 2025
// Program LawnCare calculates and writes the bills for a lawn care
// service company. The names of the input and output files are
// prompted for and read from the keyboard.
//********************************************************************

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// Function prototypes
void OpenFiles(ifstream &infile, ofstream &outfile);
void ProcessClients(ifstream &inFile, ofstream &outfile, float hourlyRate);
void ProcessAClient(ifstream &inFile, ofstream &outFile, int &totalTime, float hourlyRate);
void GetAndPrintAddress(ifstream &inFile, ofstream &outFile);
void PrintResults(int numberOfBills, int totalMinutes, float hourlyRate);

int main()
{
  float hourlyRate;
  ifstream inFile;
  ofstream outFile;

  OpenFiles(inFile, outFile);

  if (!inFile || !outFile)
  {
    cout << "Error opening files" << endl;
    return 1;
  }

  cout << "Enter hourly rate." << endl;
  cin >> hourlyRate;

  ProcessClients(inFile, outFile, hourlyRate);

  inFile.close();
  outFile.close();

  return 0;
}

//********************************************************************
// OpenFiles
// Reads in the names of the input file and the
// output file and opens them for processing.
// Parameters: an ifstream (by reference) and an ofstream (by reference)
//    these will be used to open files given file names via cin
// Return: none
// Post: Files have been opened and filesOK reflects the result
//       of the opening process
//********************************************************************
void OpenFiles(ifstream &inFile, ofstream &outFile)
{

  string inFileName;  // User-specified input file name
  string outFileName; // User-specified output file name

  cout << "Enter the name of the input file." << endl;
  cin >> inFileName;

  inFile.open(inFileName.c_str());

  cout << "Enter the name of the output file." << endl;
  cin >> outFileName;

  outFile.open(outFileName.c_str());

  outFile << "Billing for clients on file " << inFileName << endl;
  outFile << fixed;
}

//********************************************************************
// ProcessClients
// Writes bills for all of the clients whose records are oin inFile.
// Parameters: an ifstream inFile, an ofstream outFile,
//    and a float hourlyRate
// Return: none
// Pre:  Files have been opened and the hourly rate has been set
// Post: Each bill has been written and the summary values have
//       been written to the screen.
//********************************************************************
void ProcessClients(ifstream &inFile, ofstream &outFile, float hourlyRate)
{

  int totalTime = 0;
  int numberOfBills = 0;
  string name;

  getline(inFile, name);

  while (inFile)
  {
    outFile << name << endl;
    ProcessAClient(inFile, outFile, totalTime, hourlyRate);
    numberOfBills++;
    getline(inFile, name);
  }

  // Print summary information
  PrintResults(numberOfBills, totalTime, hourlyRate);
}

//********************************************************************
// PrintResults
// Prints total billed, average time per job, and average bill.
// Parameters: int numberOfBills, int totalMinutes, float hourlyRate
// Return: none
// Pre:  number of bills and total minutes have been calculated
// Post: total billing and average time and bill have been printed
//********************************************************************
void PrintResults(int numberOfBills, int totalMinutes, float hourlyRate)
{
  float minutes = static_cast<float>(totalMinutes);
  cout << "Total amount billed this month is " << minutes / 60.0 * hourlyRate
       << endl;
  cout << "Average time worked per job is "
       << minutes / float(numberOfBills) / 60.0 << endl;
  cout << "Average customer bill is "
       << minutes / 60.0 * hourlyRate / float(numberOfBills) << endl;
}

//********************************************************************
// GetAndPrintAddress
// Reads the address from inFile and prints it in outFile.
// Parameters: ifstream inFile, ofstream outFile
// Return: none
// Pre:  files have been opened and name has been read
// Post: address has been read from inFile and
//       written on outFile
//********************************************************************
void GetAndPrintAddress(ifstream &inFile, ofstream &outFile)
{
  string line;
  getline(inFile, line);
  outFile << line << endl;
  getline(inFile, line);
  outFile << line << endl
          << endl;
}

//********************************************************************
// ProcessAClient
// Writes the bill for one client
// Parameters: ifstream inFile, ofstream outFile, int totalTime (by reference),
//    float hourlyRate
// Return: none (but side effect -- see below)
// Pre:  Files have been opened, totalTime is total minutes
//       billed so far, and hourlyRate has been set
// Post: Bill has been written to outFile
//********************************************************************
void ProcessAClient(ifstream &inFile, ofstream &outFile, int &totalTime,
                    float hourlyRate)
{
  int time = 0;
  int hours;
  int minutes;
  float cost;
  int numberOfJobs;

  // Process
  GetAndPrintAddress(inFile, outFile);

  inFile >> numberOfJobs;
  outFile << "Number of jobs: " << numberOfJobs << endl;

  for (int count = 1; count <= numberOfJobs; count++)
  {
    inFile >> hours >> minutes;
    time = hours * 60 + minutes + time;
    outFile << "Job " << count << ": " << hours << " hours and " << minutes
            << " minutes " << endl;
  }

  cost = static_cast<float>(time) / 60.0 * hourlyRate;
  totalTime = totalTime + time;

  outFile << "Amount of bill: $" << setprecision(2) << cost << endl
          << endl;

  string skip;
  getline(inFile, skip);
}
