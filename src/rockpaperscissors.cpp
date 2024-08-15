#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

using namespace std;

void gameMessage()
{
    cout << "Rock, Paper, Scissors!\n";
    cout << "You must enter the help menu you can enter '!'.\n";
    cout << "Please type 'R' for Rock, 'P' for Paper, and 'S' for Scissors.\n\n";
    cout << "Enter 'GO' when you are ready to begin. You will be playing against Maurice the Rock Paper Scissors Bot.\n";
}

void timedDelay()
{
    for(int i = 1; i > 0; --i) 
        {
            // Waiting for 1 second
            this_thread::sleep_for(chrono::seconds(1));
        }
}

void scoreDisplay(int playerScore, int botScore)
{
    if(playerScore > botScore)
    {
        cout << playerScore << " - " << botScore << "   You Are Winning!\n";
    }
    else if(playerScore < botScore)
    {
        cout << botScore << " - " << playerScore << "   Maurice Is Winning.\n";
    }
    else
    {
        cout << playerScore << " - " << botScore << "   It's a tie!\n";
    }
}

void helpMenu(string &userChoice)
{
    cout << "\nHelp Menu\n";
    cout << "\n1. Tutorial\n";
    cout << "2. Settings\n";
    cout << "3. Quit\n";
    cout << "4. Back\n";

    cout << "\nEnter your choice: ";
    cin >> userChoice;
    cout << "\n";
}

void settingsMenu(string &userChoice, bool &defaultPointSetting, int &pointPerX, bool &shootMessage)
{
    cout << "Settings Menu\n\n";

    bool inSettingsMenu = true;
    while(inSettingsMenu)
    {
        //cout << "1. Point Settings\n";
        cout << "1. Start Settings Settings\n";
        cout << "2. Back\n";

        cout << "\nEnter your choice: ";
        cin >> userChoice;
        cout << "\n";

        /*
        if(userChoice == "1")
        {
            cout << "\nPoint Settings\n\n";

            bool inPointSettings = true;
            while(inPointSettings)
            {
                cout << "1. Point Per Win (Default)\n";
                cout << "2. Best Out Of X\n";
                cout << "3. Back\n";

                cout << "\nEnter your choice: ";
                cin >> userChoice;
                cout << "\n";

                if(userChoice == "1")
                {
                    cout << "You and your opponent will now receive 1 point per win.\n";
                    defaultPointSetting = true;
                }
                else if(userChoice == "2")
                {
                    cout << "Enter the number of rounds you would like to play: ";
                    cin >> pointPerX;
                    cout << "You and your opponent will now play the best out of " << pointPerX << " rounds.\n";
                }
                else if(userChoice == "3")
                {
                    inPointSettings = false;
                }
                else
                {
                    cout << "Invalid choice\n";
                }
            }
        }
        */
        if(userChoice == "1")
        {
            cout << "\nStart Settings\n";

            bool inStartSettings = true;
            while(inStartSettings)
            {
                cout << "\n1. Toggle 'Shoot!' Message After Rock Paper Scissors\n";
                cout << "2. Back\n";

                cout << "\nEnter your choice: ";
                cin >> userChoice;
                cout << "\n";

                if(userChoice == "1")
                {
                    if(shootMessage)
                    {
                        cout << "The 'Shoot!' message will no longer be displayed after Rock Paper Scissors.\n";
                        shootMessage = false;
                    }
                    else
                    {
                        cout << "The 'Shoot!' message will now be displayed after Rock Paper Scissors.\n";
                        shootMessage = true;
                    }
                }
                else if(userChoice == "2")
                {
                    inStartSettings = false;
                }
                else
                {
                    cout << "Invalid choice\n";
                }
            }
        }
        else if(userChoice == "2")
        {
            inSettingsMenu = false;
        }
        else
        {
            cout << "Invalid choice\n";
        }
    }
}

int main() 
{
    bool isGameRunning = true;
    
    bool defaultPointSetting = true;
    int pointPerX;
    bool shootMessage = true;

    string userChoice;

    while(isGameRunning)
    {
        gameMessage();

        cout << "\nEnter your choice: ";
        cin >> userChoice;

        if(userChoice == "!")
        {
            bool inHelpMenu = true;
            while(inHelpMenu)
            {
                helpMenu(userChoice);

                if(userChoice == "1")
                {
                    cout << "Please type 'R' for Rock, 'P' for Paper, and 'S' for Scissors.\n";
                }
                else if(userChoice == "2")
                {
                    settingsMenu(userChoice, defaultPointSetting, pointPerX, shootMessage);
                }
                else if(userChoice == "3")
                {
                    cout << "Quitting...";
                    isGameRunning = false;
                    inHelpMenu = false;
                }
                else if(userChoice == "4")
                {
                    inHelpMenu = false;
                }
                else
                {
                    cout << "Invalid choice\n";
                }
            }
        }
        else if(userChoice == "GO")
        {
            cout << "Game starting...\n\n";
            
            bool isGamePlaying = true;
            int playerScore = 0;
            int botScore = 0;
            while(isGamePlaying)
            {
                cout << "\nRock\n";
                timedDelay();
                cout << "Paper\n";
                timedDelay();
                cout << "Scissors\n";
                
                if(shootMessage)
                {
                    timedDelay();
                    cout << "Shoot!\n\n";
                }

                cout << "Enter your choice: ";
                cin >> userChoice; 

                int botChoice = rand() % 33 + 1;

                if(userChoice == "R")
                {
                    if(botChoice <= 11)
                    {
                        cout << "Maurice chose Rock. It's a tie!\n";
                        scoreDisplay(playerScore, botScore);
                    }
                    else if(botChoice <= 22)
                    {
                        cout << "Maurice chose Paper. You lose!\n";
                        botScore++;
                        scoreDisplay(playerScore, botScore);
                    }
                    else if(botChoice <= 33)
                    {
                        cout << "Maurice chose Scissors. You win!\n";
                        playerScore++;
                        scoreDisplay(playerScore, botScore);
                    }
                }
                else if(userChoice == "P")
                {
                    if(botChoice <= 11)
                    {
                        cout << "Maurice chose Rock. You win!\n";
                        playerScore++;
                        scoreDisplay(playerScore, botScore);
                    }
                    else if(botChoice <= 22)
                    {
                        cout << "Maurice chose Paper. It's a tie!\n";
                        scoreDisplay(playerScore, botScore);
                    }
                    else if(botChoice <= 33)
                    {
                        cout << "Maurice chose Scissors. You lose!\n";
                        botScore++;
                        scoreDisplay(playerScore, botScore);
                    }
                }
                else if(userChoice == "S")
                {
                    if(botChoice <= 11)
                    {
                        cout << "Maurice chose Rock. You lose!\n";
                        botScore++;
                        scoreDisplay(playerScore, botScore);
                    }
                    else if(botChoice <= 22)
                    {
                        cout << "Maurice chose Paper. You win!\n";
                        playerScore++;
                        scoreDisplay(playerScore, botScore);
                    }
                    else if(botChoice <= 33)
                    {
                        cout << "Maurice chose Scissors. It's a tie!\n";
                        scoreDisplay(playerScore, botScore);
                    }
                }
                else if(userChoice == "!")
                {
                    bool inHelpMenu = true;
                    while(inHelpMenu)
                    {
                        helpMenu(userChoice);

                        if(userChoice == "T")
                        {
                            cout << "Please type 'R' for Rock, 'P' for Paper, and 'S' for Scissors.\n";
                        }
                        else if(userChoice == "S")
                        {
                            cout << "Settings\n";
                        }
                        else if(userChoice == "Q")
                        {
                            cout << "Quitting...";
                            isGameRunning = false;
                            inHelpMenu = false;
                            isGamePlaying = false;
                        }
                        else if(userChoice == "B")
                        {
                            inHelpMenu = false;
                        }
                        else
                        {
                            cout << "Invalid choice\n";
                        }
                    }
                }
                else
                {
                    cout << "Invalid choice\n";
                }
            }
        }
        else if(userChoice == "R" || userChoice == "P" || userChoice == "S")
        {
            cout << "You must start the game first!\n";
        }
        else
        {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}