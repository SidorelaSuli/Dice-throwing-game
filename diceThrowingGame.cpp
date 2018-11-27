#include <iostream>
#include <ctime> // gives a random number every second.
#include <cstdlib> // used for the random code.
#include <windows.h> // time delay package.
using namespace std;

int main()
{
    // say hi and ask for how much the player wants to bet.
    cout << "                   Welcome to The Dice Throwing Game" << endl;
    cout << "                   ---------------------------------" << endl << endl;
    cout << "     --------------------------------------------------------------" << endl;
    cout << "     -How much money would you like to bet? press 1,2 or 3 please!-" << endl;
    cout << "     -1. 100$                                                     -" << endl
         << "     -2. 300$                                                     -" << endl
         << "     -3. 500$                                                     -" << endl;
    cout << "     --------------------------------------------------------------" << endl;



        // The menu of money the player want to bet. Solved by a while loop.
        int Menu, Stop=0;
        int Player_Bank =0, PC_Bank =0;  // Two variables for saving money.

        while (Stop <1) {
            cout << "====> ";
            cin >> Menu;
            if (Menu == 1) {
                cout << "plus 100$ for both." << endl << endl;
                Player_Bank = (Player_Bank +100);
                PC_Bank     = (PC_Bank     +100);
                Stop++;
            }
            else if (Menu == 2) {
                cout << "Plus 300$ for both." << endl << endl;
                Player_Bank = (Player_Bank +300);
                PC_Bank     = (PC_Bank     +300);
                Stop++;
            }
            else if (Menu == 3) {
                cout << "Plus 500$ for both." << endl << endl;
                Player_Bank = (Player_Bank +500);
                PC_Bank     = (PC_Bank     +500);
                Stop++;
            }
            else {
                    cout << "Wrong choice, choose again please! " << endl;
            }
    }
    // Separate the bank from the bed. So you can bed a lower mount if you want.
    int Player_Bed, PC_Bed  ;
    Player_Bed = Player_Bank;   //
    PC_Bed     = PC_Bank    ;   //
    int Dice_Player_1,Dice_Player_2, Dice_Player_Max, Dice_PC_1, Dice_PC_2, Dice_PC_Max; // The dices.
    // use random package to make a dice value.
    cout << "We are doing three rounds or two wins in a row. And the the one who wins the most rounds gets the money ;)" <<endl<<endl<<endl;

bool Answear = false;
while (Answear == false) { // Loops the game if the player wants to play another.

    srand(time(NULL));

    int PC_Win =0, Player_Win =0;   // In case someone wins 2 times in a row so to skip the third.
      Stop = 0;

      while ((Stop<3) && (PC_Win <2) && (Player_Win <2)) {
Sleep(3000);
      Dice_Player_1 = (rand() % 6) + 1;
      Dice_Player_2 = (rand() % 6) + 1;
      Dice_PC_1     = (rand() % 6) + 1;
      Dice_PC_2     = (rand() % 6) + 1;

if (Dice_PC_1>Dice_PC_2) { Dice_PC_Max = Dice_PC_1;}
else {Dice_PC_Max = Dice_PC_2;}

if (Dice_Player_1>Dice_Player_2){ Dice_Player_Max = Dice_Player_1;}
else {Dice_Player_Max = Dice_Player_2;}

// cout << Dice_PC_Max << endl << Dice_Player_Max<< endl;
      cout << "Player dice 1 ===> " << Dice_Player_1 << endl << "                          Your highest dice ===> "<<Dice_Player_Max<<endl << "Player dice 2 ===> " << Dice_Player_2 << endl << endl;
      cout << "PC dice 1 =======> "   << Dice_PC_1     << endl <<"                          PC highest dice ===> "<<Dice_PC_Max<< endl << "Player dice 2 ===> " << Dice_PC_2   << endl << endl;

         if (Dice_PC_Max < Dice_Player_Max) { cout << "                            You won!"<< endl<< endl; Stop++, Player_Win++;  }
         else if(Dice_PC_Max > Dice_Player_Max) {cout << "                            PC won!" << endl<< endl; Stop++, PC_Win++; }
         else {cout << "                          No one won!" << endl << endl; Stop++;  }
    }

    // Checking for the winner and giving the money.
    if (Player_Win > PC_Win) {
        cout << "Congrats, You are the winner!" << endl;
        Player_Bank = (Player_Bank + PC_Bed);
        PC_Bank     = (PC_Bank     - PC_Bed);
        cout << "Your money: " <<  Player_Bank  << endl << "PC's money: " << PC_Bank;
    }
     else if (Player_Win < PC_Win) {
        cout << "Sorry! PC won" << endl;
        PC_Bank     = (PC_Bank     + Player_Bed);
        Player_Bank = (Player_Bank - Player_Bed);
        cout << "Your money: " << Player_Bank <<  endl << "PC's money: " << PC_Bank;
     }
     else if (Player_Win == PC_Win) {
        cout << "No wins to both." << endl;
        cout << "Your money: " << Player_Bank <<  endl << "PC's money: " << PC_Bank;
     }
     cout << endl << endl << endl;
     Sleep(5000);

// ask the player if he wants to play again.
char Tecken;
cout << "Do you want to play again (y/n)? ";
cin >> Tecken;
if (Tecken == 'n') {Answear = true;}

}
    return 0;

}

