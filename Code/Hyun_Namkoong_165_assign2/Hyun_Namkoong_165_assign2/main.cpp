//
//  main.cpp
//  Hyun_Namkoong_165_assign2
//
//  Created by Hyun Namkoong on 2/18/22.
//

#include <iostream>
#include <cmath>
#include <time.h>
#include <cstdlib>
using namespace std;
// starting main function

const int ROCK = 1;
const int PAPER = 2;
const int SCISSORS = 3;
const int QUIT = 4;

int getUserChoice();
int getComputerChoice();
void determineOutcome (int, int);
void displayChoice(int);

int main()
{
    // set the char variable for the y/n while loop. I have learned since that a bool statement
    // might have been a little better for the loop
    char ch;
    // set up my variables for the scores
    int win = 0;
    int tie = 0;
    int lose = 0;
    // start of game loop, the loop will run untill ch == n
    do{
    int choice;
    // Fancy printed title, well as fancy as I can do.
    cout << "Game Menu"<< endl;
    cout << "--------" << endl;
    cout << "1) Rock" << endl;
    cout << "2) Paper" << endl;
    cout << "3) Scissors" << endl;
    cout << "4) Quit" << endl;
    // Ask the player to choose Rock, Paper, Scissors
    cout << "Enter your choice: ";
        cin >> choice;
            // gets a random number between 1 and 3 and tell the player what was chosen
            int ai = rand() % 3 + 1;
            cout <<  "The computer selected: " << ai << endl;
            // starts possible outcome sequence in rock paper scissors there are 9 possible out comes 3 wins 3 ties and 3 losses.
            if(choice == 1 && ai == 1){
                 cout << "Tie. No winner." << endl;
                 tie++;
                 }
            else if(choice ==1 && ai== 2){
                 cout << "Computer wins! Paper wraps rock." << endl;
                 lose++;
                 }
            else if(choice == 1 && ai == 3){
                 cout << "YOU wins! Rock smashes Scissors." << endl;
                 win++;
                 }
            else if(choice == 2 && ai == 1){
                 cout << "YOU wins! Paper wraps rock." << endl;
                 win++;
                 }
            else if(choice == 2 && ai == 2){
                 cout << "Tie. No winner." << endl;
                 tie++;
                 }
            else if(choice == 2 && ai == 3){
                 cout << "Computer wins! Scissors cuts paper." << endl;
                 lose++;
                 }
            else if( choice == 3 && ai == 1){
                 cout << "YOU wins! Rock smashes Scissors." << endl;
                 lose++;
                 }
            else if( choice == 3 && ai == 2){
                 cout << "YOU wins! Scissors cuts paper." << endl;
                win++;
                         }
                    else if(choice == 3 && ai == 3){
                         cout << "Tie. No winner." << endl;
                         tie++;
                         }
                         // this is what happens if the player doesn't hit 1 2 or 3
                    else{
                         cout << "Invalid selected. Enter 1, 2, 3, or 4: " << endl;
                         }
                         // displays your score so far and asks if you want to play again then clears screen
                         cout << "Wins: " << win << endl;
                         cout << "Ties:" << tie << endl;
                         cout << "Losses:" << lose << endl;
                         cout << "Would you like to play again? Y/N" << endl;
                         cin >> ch;
                         system("CLS");
                         }while(ch == 'Y' || ch == 'y');
}
