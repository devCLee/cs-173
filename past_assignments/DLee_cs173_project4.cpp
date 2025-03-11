//=========================================================
// Daniel Lee
// February 22, 2025
// DLee_cs173_project4.cpp
// This program read in two integer arrays (Need and Inventory) and determine
// if the supply depot represented by array Inventory (B) covers (satisfies or fulfills)
// the needs as represented by array Need (A).
// If Inventory array (B) covers the Needs array (A), the program will output "satisfies"
// otherwise it should output "does not satisfy"
//=========================================================

#include <iostream>
#include <string>

using namespace std;

void bubbleSort(int array[], int size);
bool coversNeeds(int arrayA[], int sizeA, int arrayB[], int sizeB);

const int MAX_ARRAY_SIZE = 10000;

int main()
{
    int sizeA;
    int sizeB;

    int arrayA[MAX_ARRAY_SIZE];
    int arrayB[MAX_ARRAY_SIZE];

    bool res;

    cin >> sizeA;

    cin.ignore(1, '\n');

    for (int i = 0; i < sizeA; i++)
    {
        string inputElt;

        getline(cin, inputElt);

        arrayA[i] = stoi(inputElt);

        if (i == sizeA - 1)
        {
            cin >> sizeB;
            cin.ignore(1, '\n');

            for (int j = 0; j < sizeB; j++)
            {
                getline(cin, inputElt);

                arrayB[j] = stoi(inputElt);
            }
        }
    }

    for (int i = 0; i < sizeA; i++)
    {
        cout << arrayA[i] << " " << endl;
    }
    cout << endl;
    for (int i = 0; i < sizeB; i++)
    {
        cout << arrayB[i] << " " << endl;
    }
    cout << endl;

    bubbleSort(arrayA, sizeA);
    bubbleSort(arrayB, sizeB);

    res = coversNeeds(arrayA, sizeA, arrayB, sizeB);

    if (res == true)
    {
        cout << "satisfies" << endl;
    }
    else
    {
        cout << "does not satisfy" << endl;
    }

    return 0;
}

//=================================================
// bubbleSort
// This function takes an integer array and the intger size of that array as parameters
// and sorts the elements of the array in the ascending order.
// Parameters:
//      array[]: an integer array.
//      size: the intger size of the array.
// Return Value:
//      None
//=================================================
void bubbleSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

//=================================================
// coversNeeds
// This function takes takes the Needs array (A), the size of Needs array,
// the Inventory array (B), and the size of the Inventory array as its four parameters,
// computes the algorithm for matching a single item in the Needs array (A) to a single item in the Inventory array (B),
// and returns true or false depending on whether or not the given inventory list (array B)
// covers the needed list of supplies (array A).
// Parameters:
//      arrayA[]: the integer array that represents the Needs array (A).
//      sizeA: the integer that represents the size of the Needs array (A).
//      arrayB[]: the integer array that represents the Inventory array (B).
//      sizeB: the integer that represents the size of the Inventory array (B).
// Return Value:
//      A boolean true, if the given inventory list (array B) covers the needed list of supplies (array A)
//      or a boolean false, if the given inventory list (array B) does not covers the needed list of supplies (array A).
//=================================================

bool coversNeeds(int arrayA[], int sizeA, int arrayB[], int sizeB)
{
    if (sizeA > sizeB)
    {
        return false;
    }
    else
    {
        int positionMarker = 0;

        for (int i = 0; i < sizeA; i++)
        {
            bool found = false;

            for (int j = positionMarker; j < sizeB; j++)
            {
                if (arrayA[i] == arrayB[j])
                {
                    found = true;
                    positionMarker = j + 1;
                    break;
                }
            }

            if (!found)
            {
                return false;
            }
        }

        return true;
    }
}