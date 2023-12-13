/* PROGRAM Over/Under Game

         AUTHOR: Branson Bailey
         FSU ID: BMB22G
         RECITATION SECTION NUMBER: 1
         TA NAME: Noah O'connor
         COURSE INFORMATION: COP 3363
         Project Number: 4
         Due Date: 10/27/2022

         SUMMARY

         This program is designed to be a lottery/guessing game for the user
         that tracks bet amounts, total cash, and win percentage during the
         program run. The user has 6 guesses to guess a random integer
         between 1 and 100.

         INPUT

         Input is interactive and filled in by the user. Bet amount, each
         number guess, and asking to play again are all filled with user
         input. There are both integer inputs and character inputs from
         the user.

         BAD DATA CHECKING:
         The program checks all user input for invalid characters and
         prompts the user to input correct data. The program
         also checks for invalid bets and reprompts the user for a
         correct bet. Incorrect guesses are evaluated, but the user is not
         reprompted when an incorrect guess is input.

         OUTPUT

         Output consists of a welcome message displaying starting cash amount
         and guess parameters, then a prompt asking for a bet amount, and then
         a guess prompt that repeats until the correct number has been guessed
         or the user has made 6 guesses. If the user wins, they recieve a
         congratulations message, if not the user is given the correct number.
         After each play through the user is given an updated cash amount and
         a statistic on percentage of games won. The user is then prompted for
         another play through or not.

         DATA STRUCTURES

         No data structures.

         ASSUMPTIONS

         It is assumed the user is able to use this program in Unix. All other
         user input variables are checked for bad data to prevent the program
         from crashing.

         Comments: Comments are right-aligned to the 79th column except when
                   there is overflow.

/* ==================================================================== */

#include <iomanip>
#include <iostream>
#include <random>
using namespace std;

void PrintHeading(int&);                   // function to print intro message.
int PlayGame(int);   // function that handles all of the game running process.
void GetBet (int, int&);         // subfunction that takes input for user bet.
int GetGuess (void);    // subfunction that takes input for user number guess.
int CalcNewMoney(int, int, int);    // subfunction that calculates new current
                                    // money after win or loss.
bool PlayAgain (void);        // function that asks user for input for replay.
void Closer(void);          // function that prints closing program statement.
int RandomNumber (void);         // function that calculates random number for
                                 // each play through.

const int   GUESS_MAX = 100,                          // highest guess number.
            GUESS_MIN = 0,                             // lowest guess number.
            GUESS_NUM = 6;                               // number of guesses.

int main ()                                                  // main function.
{   // main bracket

   int cash = 1000,                                  // inital starting money.
       newCash;                  // updated variable for money after each run.
   bool playAgain;                         // bool to determine re-run or not.
   float calcGames, playedGames, wonGames;   // game won percentage variables.
   PrintHeading(cash);    // call print heading function, pass starting money.
   playedGames = 0;                           // initialize played games to 0.
   wonGames = 0;                                 // initialize games won to 0.
   do
{  // do bracket
      playedGames++;      // each play through, increase played games counter.
      newCash = PlayGame(cash);                  // set new cash to the result
                                                 // of game play through.
      if (newCash >= cash)   // if resulting money is greater than or equal to
                                  // previous money, a win must have happened.
         wonGames++;                         // for win, increase win counter.
      cash = newCash;                 // set starting cash to new cash result.
      calcGames = (wonGames/playedGames) * 100;    // percentage of games won.
      cout << endl << "You have won " << fixed << setprecision(0) << calcGames
      << "% of games played." << endl;
      if (newCash > 0)
{  // if bracket
         playAgain = PlayAgain();     // call function to ask for another run.
}  // if bracket
      else
         playAgain = false;                  // if no money, playthrough ends.
}  // do bracket
   while (playAgain);                         // run game while user wants to.
      Closer();                    // program closing statement function call.
return 0;
}   // main bracket

/* ================================================================ */

/*
   PrintHeading simply prints the introductory output.
   Parameters: initial amount of money received
*/


void PrintHeading(int& money)
{  // PrintHeading

   cout << "==================================================" << endl;
   cout << "----------Welcome to the Over/Under Game----------" << endl;
   cout << "==================================================" << endl;
   cout << endl;
   cout << "You will start with: $" << money << " dollars." << endl;
   cout << endl;
   cout << "Valid guesses are integers between 1 and 100." << endl;
   cout << "==================================================" << endl;
   cout << endl;

}  // PrintHeading
                        // prints welcome message and displays starting money.

/* ======================================================================== */

/*
    GetBet prompts for and reads in a bet.  The function performs all
    error checking necessary to insure that a valid bet is read in
    and does not return until a valid bet is entered.
    Parameters:
        money: the amount of money the player currently has
        bet: the bet chosen by the user
*/
void GetBet(int money, int& bet)
{  // void bracket
   cout << "Please enter your bet: ";
   cin >> bet;                               // asking for bet via user input.
   while (!cin)                       // while loop for incorrect input.
    {
        cin.clear();   // clear input buffer to restore cin to a usable state.
        cin.ignore(400, '\n');                   // ignore last input by user.
        cout << "You can only enter numbers." << endl;
        cout << "Enter an integer value." << endl;
        cin >> bet;              // asks for user input to reset or exit loop.
    }

   while (bet > money || bet <= 0)      // while loop for incorrect bet amount.
{  // while
      cout << "Invalid Bet. Please try again." << endl;
      cin >> bet;
      while (!cin)
    {  // inner while
        cin.clear();   // clear input buffer to restore cin to a usable state.
        cin.ignore(400, '\n');                   // ignore last input by user.
        cout << "You can only enter numbers." << endl;
        cout << "Enter an integer value." << endl;;
        cin >> bet;              // asks for user input to reset or exit loop.
    }  // inner while
                                // error check second bet for incorrect input.
}  // while

}  // void bracket
/* ======================================================================== */



/*
    GetGuess reads in a guess.  The user is not prompted for the guess in
    this function. The user only gets one chance to input a guess value.
    Return Value: the value of the guess if the input is valid
                  0 if the input guess was not valid
*/
int GetGuess(void)
{  // GetGuess bracket

   int response;
   cin >> response;                                   // user input for guess.
   while (!cin)                 // while loop to clear user input error.
    {
        cin.clear();   // clear input buffer to restore cin to a usable state.
        cin.ignore(400, '\n');                   // ignore last input by user.
    }
   if (response > GUESS_MAX || response < GUESS_MIN)    // if invalid bet, set response to 0
                                          // for program output.
      response = 0;
return (response);

}  // GetGuess Bracket



/* ======================================================================== */


/*
    CalcNewMoney determines the amount of money the player has won or
    lost during the last game.
    Parameters:
        money:   the amount of money the player had going into the game
        bet:     the amount the player bet on the current game
        guesses: the number of guesses it took the player to win.
                 -1 if the player did not guess correctly
    Return Value: the new amount of money the player has
*/
int CalcNewMoney(int money, int bets, int guess)
{
   int winnings;                             // integer to store bet winnings.
   if (guess < 0)    // guess # is set to -1 if correct number is not guessed.
{  // if bracket
      money = money - bets;           // lose bet amount, new starting amount.
}  // if bracket
   else                                   // means correct number was guessed.
{  // else bracket
   winnings = (bets/guess);    // calculate winnings based on bet and guess #.
   money = money + winnings;                            // update money value.
   cout << "You just won $" << winnings << endl;
}  // else bracket
   cout << endl << "You now have $" << money << endl;

return (money);
}
/* ======================================================================== */

/*
    PlayAgain prompts the user to play the game again and reads in a response,
    using a single character to represent a yes or no reply.
    Error checking is performed on that response.
    Return Value: true if the user wants to play again
                  false if the user does not want to play again.
*/

bool PlayAgain()
{  // PlayAgain Bracket

   bool invalidResp, yesResp;       // bools to store for another program run.
   char response;                      // user input for another play through.
   do
{  // do bracket                              // initial play again statement.
   invalidResp = true;
   yesResp = false;

   cout << endl << "Would you like to play again?" << endl;
      cin >> response;                                      // user input Y/N.
      if (response == 'Y' || response == 'y' || response == 'n' ||
      response == 'N')
         invalidResp = false;
 // if proper response is given, loop ends and either repeats or ends program.
      else
         cout << "Please input the correct response. (Y/N)" << endl;
                        // else statement outputs error message, loop repeats.

      if (response == 'Y' || response == 'y')
         yesResp = true;
           // secondary if statement to check for Y/y response to repeat loop.

} //do bracket
   while (invalidResp);                 // repeat outputs until proper Y or N.

return (yesResp);


}  // PlayAgain Bracket

/* ======================================================================== */

/* Random Number Function does all of the necessary random generation inside
 its own funciton to keep PlayGame function from being cluttered. No
parameters, return value is the winning number, winNum. */

int RandomNumber ()
{
   random_device myEngine;
   uniform_int_distribution<int> winNum(0,100);

                                 // short function to calculate random number.
            // I know it is short, but it saves room in the playGame function.
return (winNum(myEngine));
}

/* ======================================================================== */

/*
    PlayGame plays a single game, performing all the necessary calculations,
    input, and output.
    Parameters:
        money: the amount of money the player has at the start of the game.
    Return Value: how much the player has after the game.
*/
int PlayGame(int money)
{  // PlayGame
   int bets, guess, winNum, response; // int declarations for bet amount,
                                      // guess number, the winning number,
                                      // and the user input number.
   bool notWinner;                                // bool to track win status.
   winNum = RandomNumber();                  // set variable to random number.

   GetBet(money, bets);                                  // call for user bet.

   guess = 0;                                 // initialize guess number to 0.
   notWinner = true;                            // initialize win status bool.
   do                             // loop to run the guessing portion of game.
{  // do while loop
      guess++;
      cout << "Guess Number " << guess << ":";
      response = GetGuess();

       if (response == winNum)
{  // if bracket
         cout << endl << "Correct Number!" << endl <<endl;
         notWinner = false;                                    // breaks loop.
}  // if bracket
      else if (response > GUESS_MAX ||
               response < GUESS_MIN || response < winNum)
{  // else if bracket
         cout << "Too Low." << endl; // invalid bet default statement along
                                     //with too low response.
}  // else if bracket
      else if (response > winNum && response <= GUESS_MAX)
{  // else if bracket
         cout << "Too High." << endl;
}  // else if bracket
}  // do while loop
      while (notWinner && guess < GUESS_NUM);// ^^ input checking response and
                                             // corresponding outputs.
      if (notWinner)
{  // if bracket
         cout << "The correct number was " << winNum << endl;;
         guess = -1;    // if correct number wasn't guessed, pass -1 to
                        // CalcNewMoney function.
}  // if bracket
      money = CalcNewMoney(money, bets, guess); // set money to new money
                                                // passed by function.
return (money);
}  // PlayGame
/* ======================================================================== */

void Closer()
{  // Closer Bracket

   cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
   cout << "=-=-=-=-=-=-=-=- Program Ended -=-=-=-=-=-=-=-=" << endl;
   cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl << endl;
                                                 // program termination message

}  // Closer Bracket
