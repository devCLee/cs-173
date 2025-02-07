//=========================================================
// Daniel Lee, Jason Chen
// January 31, 2025
// DLeeJChen_cs173_project2.cpp
// This program simulates a situation where there are two people, and each person enters the kitchen starting at midnight,
// stays for a certain period, and then leaves for a specific amount of time, repeating this cycle throughout the day.
// At a specific time, starting at midnight, Soprano the cat attempts to hop up on the counter.
// The program determines whether Soprano succeeds if no one is in the kitchen or gets caught if someone is.
//=========================================================

#include <iostream>
#include <string>

using namespace std;

bool checkCaught(int, int, int);                     // function prototypes -- come before main()
string determineHopSuccess(int, int, int, int, int); // function prototypes -- come before main()

int MINUTES_IN_DAY = 24 * 60; // Accounting for the reset of midnight

int main()
{
    int p1_in;
    int p1_out;
    int p2_in;
    int p2_out;

    int t_hop;

    cin >> p1_in;
    cin >> p1_out;
    cin >> p2_in;
    cin >> p2_out;

    cin >> t_hop;

    cout << determineHopSuccess(p1_in, p1_out, p2_in, p2_out, t_hop) << endl;

    return 0;
}

//=================================================
// checkCaught
// This function determines if Soprano is caught by a person.
// Parameters:
//      p_in: an integer of length of time (in minutes) the person stays in the kitchen. It is greater than or equal to 0.
//      p_out: an integer of length of time (in minutes) person stays out of the kitchen. It is greater than or equal to 0.
//      t_hop: an integer of the time in minutes after midnight when Soprano attempts to hop. It is greater than or equal to 0.
// Return Value:
//      A bool, whether p_modulo is smaller than p_in.
//=================================================
bool checkCaught(int p_in, int p_out, int t_hop)
{
    t_hop = t_hop % MINUTES_IN_DAY;

    int p_cycle = p_in + p_out;

    int p_modulo = t_hop % p_cycle; // Check where we are in the cycle

    return p_modulo < p_in;
}

//=================================================
// determineHopSuccess
// This function prints if Soprano the cat gets caught or not.
// Parameters:
//      p1_in: an integer of length of time (in minutes) person 1 stays in the kitchen. It is greater than or equal to 0.
//      p1_out: an integer of length of time (in minutes) person 1 stays out of the kitchen. It is greater than or equal to 0.
//      p2_in: an integer of length of time (in minutes) person 2 stays in the kitchen. It is greater than or equal to 0.
//      p2_out: an integer of length of time (in minutes) person 2 stays out of the kitchen. It is greater than or equal to 0.
//      t_hop: an integer of the time in minutes after midnight when Soprano attempts to hop. It is greater than or equal to 0.
// Return Value:
//      A string of either "CAUGHT" or "SUCCESS".
//=================================================
string determineHopSuccess(int p1_in, int p1_out, int p2_in, int p2_out, int t_hop)
{
    if (checkCaught(p1_in, p1_out, t_hop) || checkCaught(p2_in, p2_out, t_hop))
    {
        return "CAUGHT";
    }
    else
    {
        return "SUCCESS";
    }
}