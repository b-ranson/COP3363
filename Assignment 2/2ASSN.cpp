/* ========================================================================== */
/* PROGRAM ISP Bill Calculator
   AUTHOR: <Branson Bailey>
   FSU MAIL NAME: <bmb22g>
   RECITATION SECTION NUMBER: <1>
   RECITATION INSTRUCTOR NAME: <Noah O'Connor>
   COP 3363 - Fall 2022
   PROJECT NUMBER: 2
   DUE DATE: Thursday 9/22/2022
   PLATFORM: g++ / UNIX OS
SUMMARY:

An ISP company wants to calculate the prices of bills automatically after a user inputs the data. The prices of the packages they provide are $9.95, $14.95, and $19.95 for A, B, and C respectively.
Package A comes with 10 hours + 2 dollars for every overage hour. Package B comes with 20 hours + 1 dollar for every overage hour. Package C is unlimited hours. To determine the cost of the current
package along with savings the user could have, the user inputs what package and the number of hours they use. The program then outputs costs of the selected package along with any savings that could be
applicable by switching to a different package.

INPUT:

Input consists of two variables. The user inters the first, which is a single character value representing which package the user has, then the second, which is an integer value representing the number
of hours the user has used rounder to the nearest whole hour.


OUTPUT:

Asking for the user to input selected package, asking the user for total hours, and the total bill for the selected user package. If applicable, the savings a user could have with a new package,
along with the new total if they selected that package.

Assumptions:

When asked for a package, the user will input a single, non-blank character value. When asked for the usage hours, the user will input the total hours as a single, integer value rounded to
the nearest hour.

/
/* ========================================================================== */
/* HEADER FILES */

#include <iostream>
using namespace std;                 /* Standard header files */

/* ========================================================================== */
/* MAIN FUNCTION */

int main()
{
   const int AHOURS = 10,          /* given hours with package A */

    BHOURS = 20,                   /* given hours with package B */

    AHOURSPRICE = 2,               /* price of overage hours for package A */

    BHOURSPRICE = 1;               /* price of overage hours for package B */

   const float PACKA = 9.95,       /* base price of package A */

   PACKB = 14.95,                  /* base price of package B */

   PACKC = 19.95;                  /* base price of package C */

   bool dataOK;                      /* regulates flow of program. If anywhere is false, program ends. */

   char userPackage;                 /* user input for Pacake A B or C */

   int userHours;                    /* all int values for the program. Input is user hours. All else are constants. */

   float result, savings1, savings2;                 /* costs of the packages and final result; stores savings price also */

   cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

   cout << "Welcome to the Package Billing Calculator" << endl;

   cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;            /* welcome message */


   cout << "Which Package was used by the customer? (A, B, C) " << endl;   /* output to console requesting package character */

   cin >> userPackage;                                                     /* user input of selected package */

   dataOK = true;                                                         /* starting program with true statement to initiate run */
   switch (userPackage)
   {
      case 'A' :
      case 'a' :
      case 'B' :
      case 'b' :
      case 'C' :
      case 'c' : cout << endl;
                 cout << "Please input the customer's hours." << endl;      /* if proper character is input, asks for hours */
                 cin >> userHours;
                 break;
      default  : cout << endl;
                 cout << "Sorry, please input the correct package.";
                 cout <<endl;
                 dataOK = false;
                 break;
   }                                                                        /* switch allows user to input hours after correct package input */
                                                                            /* any other input outputs error and false bool, ending program */
   if (dataOK)
{

   if (userHours <= 744 && userHours >= 0)                                  /* total hours in a 31 day month */
{
      dataOK = true;                                                        /* if hours are correct, bool set true */
}

   else
{
      cout << endl;
      cout << "Please input correct hours." << endl;                        /* asks to restart program and input correct hours, bool set false */
      dataOK = false;
}

                                                                           /* if hours are in correct scope, program continues. If not, program ends */
   switch (userPackage)
   {
      case 'A' :
      case 'a' : if (userHours >= 10 && userHours <= 744)
                 {
                   result = ((userHours - AHOURS) * AHOURSPRICE) + PACKA;  /* calculations for package a */
                 }
                 else if (userHours <= 10 && userHours >= 0)                 /* calculations for package a if hours stay under given hours */
                 {
                    result = PACKA;        //result of calculations for package A
                 }
                 else
                    dataOK = false;                                        /* incorrect hours switches bool to end program */
                 break;
      case 'B' :
      case 'b' : if (userHours >= 20 && userHours <= 744)
                 {
                    result = ((userHours - BHOURS) * BHOURSPRICE) + PACKB;  /* calculations for package b if hours go over given hours */
                 }
                 else if (userHours <=20 && userHours >= 0)                 /* calculations for package b if hours stay under given hours */
                 {
                    result = PACKB;       //result of calculations for package B
                 }
                 else
                    dataOK = false;                                         /* incorrect hours switches bool to end program */

                 break;
      case 'C' :
      case 'c' : if (userHours <= 744 && userHours >= 0)
                 {
                    result = PACKC;        //result of calculations for package C
                 }
                 else
                    dataOK = false;                                         /* incorrect hours switches bool to end program */
                 break;
      default  : ;                                            /* blank default to not be redundant. this data has already been checked */


   }                                                                          /* switch logic directs to correct package, then calculates price based on input hours. */
}
   if (dataOK)
{
   cout << endl;
   cout << "The customer's total is: $" << result << endl;                    /* printing total bill to console */

   if (userPackage == 'A' || userPackage == 'a' && result > PACKB)            /* calculating savings if applicable for pack a */
{
      cout << endl;

      cout << "The customer could switch packages and save money." << endl;

      savings1 = ((userHours - BHOURS) * BHOURSPRICE) + PACKB;                /* calculating new price with package b */

      savings2 = PACKC;                                                       /* savings 2 is just price of c */

      cout << endl;

      cout << "Pacakge B would cost: $" << savings1 << " saving the customer: $" << result - savings1 << endl;

      cout << endl;

      cout << "Package C would cost: $" << savings2 << " saving the customer: $" << result - savings2 << endl;
}                                                                                                                            /* printing calculated savings to console */
   else if (userPackage == 'B' || userPackage == 'b' && result > PACKC)              /* calculating savings if applicable for package b */

{
      cout << endl;

      cout << "The customer could switch packages and save money." << endl;

      savings1 = PACKC;                                                       /* savings 1 is just price of c */

      cout << endl;

      cout << "Package C would cost: $" << savings1 << " saving the customer: $" << result - savings1 << endl;
}                                                                                                                             /* printing calculated savings to console */


}




      cout << endl;
      cout << "=-=-=-=-=-=-=-=-=--=-=-" << endl;
      cout << "-----Program Ended-----" << endl;
      cout << "=-=-=-=-=-=-=-=-=-=-=-=" << endl;
      cout << endl;
                                                                                                                             /* termination message for end of program */


   return 0;                                                                                                                  /* return main function, end program */
}

