/* ========================================================================== */
/* PROGRAM Delta Tau Escape Simulation
   AUTHOR: <Branson Bailey>
   FSU MAIL NAME: <bmb22g>
   RECITATION SECTION NUMBER: <1>
   RECITATION INSTRUCTOR NAME: <Noah O'Connor>
   COP 3363 - Fall 2022
   PROJECT NUMBER: 3
   DUE DATE: Thursday 10/6/2022
   PLATFORM: g++ / UNIX OS
SUMMARY:

The Starship Enterprise is landing at the Planet Delta Tau, but the inhabitants
of the planet, the Deltoids, are evil and attack the Enterprise with a tractor
beam to pull the ship to the planet
to crash it. The program is designed to calculate the necessary fuel to escape
the enemy tractor beam using variable inputs from the user. The program can
display a table of expected fuel calculations and a minute-by-minute
simulation of what to expect if there is not enough fuel readily
available at once to take off.

INPUT:

User input of 3 integer values, the current altitude of the Enterprise (Km.),
the current fuel amount (Kg.), and the strength of the enemy tractor beam
(Km/min/min.) These values must be positive
integer values entered one after another in their respective order. The
program checks for positive input values, but does not check for them
being integers, this is assumed.

OUTPUT:

Output consists soley of console prints to the users command line. Outputs will
ask the user to input certain values, display confirmation of variable inputs,
recommendations on what actions to take,and a table displaying the projected
fuel calculations if there is not enough fuel to escape at once.
Table example:

Time   Current Fuel     Current Altitude    Fuel Required
-------------------------------------------------------------
xxx         xxx               xxx                 xxx
                 ^ data calculated ^


Assumptions:

It will be assumed that when asked for an integer value that the user will
enter a single integer value consisting of no decimal places.


/* ========================================================================== */
/* HEADER FILES */

#include <iostream>
#include <iomanip>
using namespace std;

/* ========================================================================== */
/* Main Function */

int main ()
{  //main function bracket

   int currentFuel, beamStg, min, currentAlt;
                                                   // 3 input values along with
                                             // the minute counter
   char response;                   // response value for restarting simulation
   double fuelRequired;             // value for the calculated required fuel
   bool ok, invalidResp, yesResp, badAlt, badFuel, badBeam;
                                            // values for data checking/flow of
                                                     // control through program

cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
cout << "---------Delta Tau Escape Simultion--------" << endl;
cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
                                                             // opening message

   do                        // whole program in do/while loop to allow re-runs
{ //do bracket
   badAlt = false;                                          // initialized bool
   cout << "Please enter the current altitude of the ship (Km):" << endl;
                                    // prompt output asking for current altitude
   cin >> currentAlt;                        // user input for current altitude

   if (currentAlt < 0)           // data checking user input for negative value
      badAlt = true;                             // bool intializer if bad data

   while (badAlt)          // loop and ask for correct input until proper input
{ // while bracket

      cout << "Incorrect altitude. Please input a positive altitude." << endl;
                                       // output statement asking for new value
      cin >> currentAlt;                  // user re-input for current altitude

      if (currentAlt > 0)  // if proper input, bool value changes and ends loop
         badAlt = false;

} // while bracket
   badFuel = false;
   cout << "Please enter the current fuel supply of the ship (Kg):" << endl;
                                  // prompt asking for current fuel in the ship
   cin >> currentFuel;                           // user input for current fuel

   if (currentFuel < 0)          // data checking user input for negative value
      badFuel = true;                            // bool initializer if bad data

   while (badFuel)         // loop and ask for correct input until proper input
{ // while bracket

      cout << "Incorrect Fuel. Please input a positive fuel." << endl;
                                       // output statement asking for new value
      cin >> currentFuel;                 // user re-input for current altitude

       if (currentFuel > 0)// if proper input, bool value changes and ends loop
          badFuel = false;
} // while bracket
   badBeam = false;
   cout << "Please enter the strength of the enemy"
   " tractor beam (Km/min/min):" << endl;
                              // prompt asking for strength of the tractor beam
   cin >> beamStg;                          // user input for the beam strength

   if (beamStg < 0)              // data checking user input for negative value
      badBeam = true;                            // bool intializer if bad data

   while (badBeam)          // loop and ask for correct input until proper input
{ //while bracket

      cout << "Incorrect strength. Please"
      " input a positive beam strength." << endl;
                                       // output statement asking for new value
      cin >> beamStg;                // user re-input for current beam strength

      if (beamStg > 0)     // if proper input, bool value changes and ends loop
         badBeam = false;
} // while bracket

   cout << endl;

   cout << "Simulation:" << endl;       // output stating the simulation begins
   cout << endl;

   fuelRequired   = ((1 - static_cast<float>(currentAlt)/200000)  *  beamStg);
                       // equation used to calculate the require fuel to escape

   min = 0;                                // initializing simulation time to 0

   cout << "********************* Computer Report on Ship Status"
   " *******************" << endl << endl;

   cout << "The Enterprise has gone into orbit"
   " around Delta Tau at an altitude of " << currentAlt << " Km." << endl;

   cout << "The ship has a fuel supply of " << currentFuel << " Kg"
   ". of fuel." << endl;

   cout << "The enemy tractor beam has a strength"
   " of " << beamStg << " Km/min/min." << endl;

   cout << "The fuel necessary to escape at this"
   " altitude would be " << fuelRequired << "." << endl << endl;

   cout << "*********************************"
   "***************************************" << endl << endl;
        // Assessment output to confirm all variables have been input correctly

   if (currentFuel < fuelRequired)
       // if statement initializer to print table heading for fuel calculations
{ // if bracket
      cout << "There is not enough fuel to take"
      " off at this time." << endl << endl;
      cout << "Recommendation: Turn the engines"
      " off and tell Scotty to start shoveling fuel." << endl << endl;
      cout << "Report on what to expect:" << endl << endl;

      cout << setw(5) << "Time" << setw(20) << "Current Fuel" << setw(20) <<
      "Current Altitude" << setw(20) << "Fuel Required" << endl;
      cout << "---------------------------------------------------"
      "---------------------"  << endl << endl;
              // if there isn't enough fuel, table of what to expect prints out
} // if bracket

   ok = true;                                             // bool intialization
   while ((ok) && (currentFuel < fuelRequired))
         // loop until enough fuel is required while altitude is greater than 0
{ // while bracket

   min++;                              // starting minute one of the simulation

   currentAlt  = static_cast<float> (currentAlt) - beamStg * min * min;
                 // calculates every new current altitude with every new minute

   if (currentAlt < 0)
      currentAlt = 0;
    // intialize altitude to 0 when negative alt is calculated for table output

   fuelRequired   = ((1 - static_cast<float> (currentAlt)/200000)  *  beamStg);
                                                   // required fuel calculation

   currentFuel = (currentFuel + 10);         // rate at which fuel can be added


   cout << setw(2) << min << " Min" << setw(13) << currentFuel <<  " Kg." <<
   setw(15) << currentAlt <<" Km." <<
   setw(18) << fuelRequired << " Kg." << endl;
                                  // output statement for table showing results

   if (currentAlt > 0) // loop control bool, if alt is positive, loop continues
{ // if bracket
      ok = true;
} // if bracket

   else
      ok = false;                       // if altitude goes negative, loop ends

} //while bracket

   if (ok)                           // bool stating altitude remained positive
{ // if bracket
      cout << endl << "----Sufficient Fuel----" << endl << endl;
                                                   // sufficient fuel statement

      cout << "In " << min << " minutes there will be enough fuel"
         " to take off." << endl;
                           // output stating how many minutes until proper fuel

      cout << "It is recommended that you turn the engines back on and take"
      " off at that time." << endl;
                                                   // simulation recommendation
} // if bracket
   else                   // bool stating altitude reached 0 before enough fuel
{ // else bracket

      cout << endl << "----Insufficient Fuel----" << endl;
                                                 // insuffucient fuel statement
      cout << endl << "In " << min << " minutes the ship will crash."
      " Prepare effectively." << endl;
                // output statement for how many minutes until the ship crashes
} // else bracket

   yesResp = false;                  // initializing loop bool for Y/y response
   invalidResp = true;       // initializing loop bool for incorrect user input
   do
{ // do bracket
      cout << endl << "Would you like to run another simulation?" << endl;
                           // output statement asking to run another simulation
      cin >> response;                                        // user input Y/N
      if (response == 'Y' || response == 'y' || response == 'n' ||
      response == 'N')
         invalidResp = false;
   // if proper response is given, loop ends and either repeats or ends program
      else
         cout << "Please input the correct letter. (Y/N)" << endl;
                          // else statement outputs error message, loop repeats

      if (response == 'Y' || response == 'y')
         yesResp = true;
             // secondary if statement to check for Y/y response to repeat loop

} //do bracket
   while (invalidResp);
                       // loop error statement while incorrect values are given


} //do bracket
   while (yesResp);                 // main program loop repeats if Y/y is input

     cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
     cout << "=-=-=-=-=-=-=-=- Program Ended -=-=-=-=-=-=-=-=" << endl;
     cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl << endl;
                                                 // program termination message

} //main function bracket
/* ====================================================================== */
/* End of Main Function */
