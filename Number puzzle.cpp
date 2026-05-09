#include<iostream>
using namespace std;
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

void saveScore(string name, int attempts)
{
    ofstream file("scores.txt", ios::app);

    if(file.is_open())
    {
        file << name << " - Attempts: " << attempts << endl;
        file.close();
    }
}

void showScores()
{
    ifstream file("scores.txt");
    string line;

    cout << "\n===== SCOREBOARD =====\n";

    if(file.is_open())
    {
        while(getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
    }
    else
    {
        cout << "No scores available.\n";
    }
}

int main()
{
    srand(time(0));

    int secretNumber = rand() % 100 + 1;
    int guess, attempts = 0;
    string playerName;

    cout << "===== NUMBER PUZZLE GAME =====\n";
    cout << "Enter your name: ";
    cin >> playerName;

    cout << "\nGuess a number between 1 and 100\n";

    do
    {
        cout << "Enter your guess: ";
        cin >> guess;

        attempts++;

        if(guess > secretNumber)
        {
            cout << "Too high! Try again.\n";
        }
        else if(guess < secretNumber)
        {
            cout << "Too low! Try again.\n";
        }
        else
        {
            cout << "\nCongratulations " << playerName << "!\n";
            cout << "You guessed the number in "
                 << attempts << " attempts.\n";
        }

    } while(guess != secretNumber);

    saveScore(playerName, attempts);

    showScores();

    return 0;
}