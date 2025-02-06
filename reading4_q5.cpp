#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fileTemps;
    float temperature;
    float sum = 0.0;
    float average;

    int count = 0;

    fileTemps.open("temperatures.dat");

    for (int i = 0; i < 6; i++)
    {
        fileTemps >> temperature;
        sum += temperature;
    }

    average = sum / 6;

    cout << "The average temperature is: " << average << endl;

    fileTemps.close();

    return 0;
}