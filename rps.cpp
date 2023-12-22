#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// functoin to display the results of each round
void displayResults(int player, int robot, int round){
    cout << "Round: " << round << endl;
    cout << "Player Points: " << player << endl;
    cout << "Robot Points: " << robot << endl;
    cout << "------------------------" << endl << endl;
}

int main() {
    
    // infinite loop until the user types q
    for(;;){
        string type;
        int bestOf;
        
        // ask the user the type of gamemode they want
        cout << "bo3 or bo5 (q if you want to quit): ";
        getline(cin, type);
        
        // end the game if the user types q
        if(type == "q"){
            return 0;
        }
        
        // error case for if the user neither typed bo3 nor bo5
        if(type != "bo3" && type != "bo5"){
            cout << "HEY YOU DIDN'T TYPE \"bo3\" NOR \"bo5\" DUMMY STINKY HEAD" << endl << "------------------------" << endl << endl;
            continue;
        }
            // set the gamemodes
            if(type == "bo3"){
                bestOf = 3;
            }
            else{
                bestOf = 5;
            }
            
            // initialize the variables
            int playerPoints = 0;
            int robotPoints = 0;
            int rounds = 0;
            
            // play the game based on the rounds set
            while(rounds < bestOf){
                
                // cases where player or robot wins the game before reaching the 3rd or 5th round
                if(type == "bo3" && (playerPoints == 2 || robotPoints == 2)){
                    break;
                }
                
                if(type == "bo5" && (playerPoints == 3 || robotPoints == 3)){
                    break;
                }
                
                // asking the user for their input
                string option;
                cout << "What's your move (type in lowercase): ";
                getline(cin, option);
                
                // error case for when the user does not type a vaild option
                if(option != "rock" && option != "paper" && option != "scissors"){
                    cout << "HEY THAT'S NOT VALID... try again" << endl;
                    continue;
                }
                
                // randomizer for the robot to make a choice
                time_t x = time(0);
                int k = static_cast<int>(x);
                srand(k);
                
                int robAnswer = 1 + rand() % 3;
                
                // rock is 1, scissors is 2, paper is 3
                switch(robAnswer){
                    case 1:
                        // robot wins, player loses
                        if(option == "scissors"){
                            rounds++;
                            robotPoints++;
                            cout << "------------------------" << endl << "HEH I CHOSE ROCK LLLLLL" << endl << endl;
                            displayResults(playerPoints, robotPoints, rounds);
                            continue;
                        // draw
                        } else if(option == "rock"){
                            cout << "------------------------" << endl << "dang I chose rock too" << endl << endl;
                            displayResults(playerPoints, robotPoints, rounds);
                            continue;
                        // robot loses, player wins
                        } else{
                            rounds++;
                            playerPoints++;
                            cout << "------------------------" << endl << "NOOOO I chose rock :C" << endl << endl;
                            displayResults(playerPoints, robotPoints, rounds);
                            continue;
                        }
                        break;
                    case 2:
                        // robot loses, player wins
                        if(option == "rock"){
                            rounds++;
                            playerPoints++;
                            cout << "------------------------" << endl << "NOOOO I chose scissors :C" << endl << endl;
                            displayResults(playerPoints, robotPoints, rounds);
                            continue;
                        }
                        
                        // draw
                        else if(option == "scissors"){
                            cout << "------------------------" << endl << "dang I chose scissors too" << endl << endl;
                            displayResults(playerPoints, robotPoints, rounds);
                            continue;
                        }
                        
                        // robot wins, player loses
                        else{
                            rounds++;
                            robotPoints++;
                            cout << "------------------------" << endl << "HEH I CHOSE SCISSORS LLLLLL" << endl << endl;
                            displayResults(playerPoints, robotPoints, rounds);
                            continue;
                        }
                        break;
                    case 3:
                        // robot loses, player wins
                        if(option == "scissors"){
                            rounds++;
                            playerPoints++;
                            cout << "------------------------" << endl << "NOOOO I chose paper :C" << endl << endl;
                            displayResults(playerPoints, robotPoints, rounds);
                            continue;

                        }
                        
                        // draw
                        else if(option == "paper"){
                            cout << "------------------------" << endl << "dang I chose paper too" << endl << endl;
                            displayResults(playerPoints, robotPoints, rounds);
                            continue;
                        }
                        
                        // robot wins, player loses
                        else{
                            rounds++;
                            robotPoints++;
                            cout << "------------------------" << endl << "HEH I CHOSE PAPER LLLLLL" << endl << endl;
                            displayResults(playerPoints, robotPoints, rounds);
                            continue;
                        }
                        break;
                    default:
                        break;
                }
            }
        
        // game results
        if (playerPoints > robotPoints){
            cout << "******************" << endl << "YOU WIN GRRRRR" << endl << "******************" << endl << endl;
        }
        else{
            cout << "******************" << endl << "YOU LOSE HAHHAHAHA" << endl << "******************" << endl << endl;
        }
        
        }
        
        // end the program
        return 0;
        
}
