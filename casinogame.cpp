#include <iostream>
#include <string> // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include <ctime>
using namespace std;

void drawLine(int n, char symbol);
void rules();

struct diceRollType
{
    int dice1;
    int dice2;
    int sumOfDice;
} ;

diceRollType myRoll
{
    .dice1 = 0,
    .dice2 = 0,
    .sumOfDice = 0
};


inline diceRollType roll()
{
    
    auto dice1 = (rand()%6 + 1); // Will return the randomly generated integer between 1 and 6
                                 // we add one so that the dice has a minimum value of 1
    cout << "dice1 = " << dice1 << endl;
    auto dice2 = (rand()%6 + 1);
    cout << "dice2 = " << dice2 << endl;
    myRoll.dice1 = dice1;
    myRoll.dice2 = dice2;
    myRoll.sumOfDice = dice1 + dice2;
  
    return (myRoll);
}
 

int main()
{
    string playerName;
    int amount; // hold player's balance amount
    int bettingAmount; 
    int guess;
    int dice1, dice2, sumOfDice = 0; // roll 2 dice and get their sum
    char choice;
 
    srand(time(0)); // "Seed" the random generator

    drawLine(60,'_');
    cout << "\n\n\n\t\tCASINO GAME\n\n\n\n";
    drawLine(60,'_');
 
    cout << "\n\nEnter Your Name : ";
    getline(cin, playerName);
 
    cout << "\n\nEnter Deposit amount to play game : $";
    cin >> amount;
    
    do
    {
        system("/usr/bin/clear");
        rules();
        cout << "\n\nYour current balance is $ " << amount << "\n";
		
	// Get player's betting amount
        do
        {
            cout << playerName <<", enter money to bet : $";
            cin >> bettingAmount;
            if(bettingAmount > amount)
                cout << "Your betting amount is more than your current balance\n"
                       <<"\nRe-enter data\n ";
        }while(bettingAmount > amount);
 
	// Get dice rolls
        cout << "Roll your dice :";
        auto myRoll = roll();
        cout << "You rolled " << myRoll.sumOfDice << endl;
      

        if(myRoll.sumOfDice == 2)
        {
            cout << "Oh no! You rolled snake eyes! You lost $" << bettingAmount << 
            "\nBetter luck next time!" << endl;
            amount = amount - bettingAmount;
        }
        else if(myRoll.sumOfDice == 12)
        {
            cout << "Congratulations! You won $ "<< bettingAmount*10 <<"\n";
            amount = amount + bettingAmount*10; 
        }
        else if(myRoll.dice1 < myRoll.dice2)
        {
            cout << "Wow! You won $ " << bettingAmount*(myRoll.dice2-myRoll.dice1) << endl;
            amount = amount + bettingAmount*(myRoll.dice2-myRoll.dice1);
        }
        else if(myRoll.dice1 == myRoll.dice2)
        {
            cout << "Nice! You won $ " << myRoll.dice1*myRoll.dice2 << endl;
            amount = amount + myRoll.dice1*myRoll.dice2;
        }  
        else if(myRoll.dice1 > myRoll.dice2)
        {
            cout << "Yikes! You lost $ " << bettingAmount*(myRoll.dice1-myRoll.dice2) << endl;
            amount = amount - bettingAmount*(myRoll.dice1-myRoll.dice2);
        }

        cout << "\n"<<playerName<<", You have $ " << amount << "\n";
        if(amount == 0)
        {
            cout << "You have no money to play ";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";		
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
    
    cout << "\n\n\n";
    drawLine(70,'=');
    cout << "\n\nThanks for playing the game. Your balance amount is $ " << amount << "\n\n";
    drawLine(70,'=');
 
    return 0;
}
 
void drawLine(int n, char symbol)
{
    for(int i=0; i<n; i++)
        cout << symbol;
    cout << "\n" ;
}
 
void rules()
{
    system("/usr/bin/clear");
    cout << "\n\n";
    drawLine(80,'-');
    cout << "\t\tRULES OF THE GAME\n";
    drawLine(80,'-');
    cout << "\t1. Roll two dice\n";
    cout << "\t2. If you roll a sum of 2 you will lose your betting amount\n";
    cout << "\t3. If you roll a sum of 12 you will win 10 times your betting amount\n\n";
    cout << "\t4. If the dice are the same value you will win the value of the dice squared\n";
    cout << "\t5. If the first dice is less than the second dice you will win the product of the difference between the dice and your betting amount\n";
    cout << "\t6. If the first dice is greater than the second dice you will lose the product of the difference between the dice and your betting amount\n";
    drawLine(80,'-');
}
