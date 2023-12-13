/* ========================================================================== */
/* PROGRAM Walking Distance Calculator
   AUTHOR: <Branson Bailey>
   FSU MAIL NAME: <bmb22g>
   RECITATION SECTION NUMBER: <Section 1>
   RECITATION INSTRUCTOR NAME: <Noah O'Connor>
   COP 3363 - Fall 2022
   PROJECT NUMBER: 1 
   DUE DATE: Thursday 9/8/2022
   PLATFORM: g++ / UNIX OS
SUMMARY
A visitor to a city plans to go to two tourist attractions in one day, starting
at a hotel and returning to the hotel at the end of the day.  The visitor has a
map showing where all of these places are located, and wants to determine how
far apart they are and how far a person would have to walk in one day (round
trip) to see both tourist attractions.  One inch on the map equals one quarter 
mile on the ground.
INPUT
Three distances, as measured from the map by the user, in inches.  The user is
asked to enter values only to the nearest tenth of an inch.
- first distance is distance from hotel to first tourist attraction
- second distance is distance from first tourist attraction to second attraction
- third distance is from second attraction back to hotel
OUTPUT
The distance, in miles, between each of the places and the total distance, all
rounded to the nearest tenth of a mile.
ASSUMPTIONS
All input data is valid and correctly entered by the user.  
The visitor has measured the distances on the map using a ruler, in inches.
All distance values in miles are to be rounded to the nearest tenth of a mile.
/
/* ========================================================================== */
/* HEADER FILES */
#include <iostream>
#include <iomanip>
using namespace std;
/* ========================================================================== */ 
/* MAIN FUNCTION */
int main()
{
    // NAMED CONSTANTS
    const int PRECISION = 1;    // output precision for real numbers
    const double SCALE = 0.25;  // map scale (miles per inch)
    double distance1,           // the three distances measured by the user
           distance2,
           distance3,
           totMiles,            // round trip mileage, rounded to nearest tenth
           miles;               // an individual rounded mileage
    // print output heading and set up real number output format
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Welcome to the Walking Distance Calculator Program" << endl;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl 
         << endl;
    cout << fixed << showpoint << setprecision(PRECISION);   
    
    // input the three distances as measured by the user
    cout << "Please enter your distance measurements to the nearest "
         << "tenth of an inch!" << endl;
    cout << endl << "Enter the distance between the hotel and the first site: ";
    cin >> distance1;
    cout << "Enter the distance between the first and second site: ";
    cin >> distance2;
    cout << "Enter the distance between the second site and the hotel: ";
    cin >> distance3;
                  
    // initialize the total miles for a round trip
    totMiles = 0.0;
    // calculate distance between hotel and first location and add to total
    miles = double(int(distance1 * SCALE * 10.0 + 0.5)) / 10.0;
    cout << endl << "Given a measurement of " << distance1
         << " the first distance is " << miles << " mile(s) long." << endl;
    totMiles = totMiles + miles;
    // calculate distance between first and second location and add to total
    miles = double(int(distance2 * SCALE * 10.0 + 0.5)) / 10.0;
    cout << "Given a measurement of " << distance2
         << " the second distance is " << miles << " mile(s) long." << endl;
    totMiles = totMiles + miles;
    
    // calculate distance between second location and hotel and add to total
    miles = double(int(distance3 * SCALE * 10.0 + 0.5)) / 10.0;
    cout << "Given a measurement of " << distance3
         << " the third distance is " << miles << " mile(s) long." << endl;
    totMiles = totMiles + miles;
    // print the total miles
    cout << endl << "Total mileage for the day is " << totMiles 
         << " miles." << endl;
    
    // print closing message
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" 
         << endl;
    cout << "Program run completed. Have a nice walk!" << endl;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
         
    return 0;
}
/* ========================================================================== */ 
/*                      E N D   O F   P R O G R A M                           */
/* ========================================================================== */
