#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

enum Choice {
    ROCK,
    PAPER,
    SCISSORS
};

void printChoices() {
    cout << "0: Rock" << endl;
    cout << "1: Paper" << endl;
    cout << "2: Scissors" << endl;
}

Choice getUserChoice() {
    int choice;
    cout << "Enter your choice (0-2): ";
    cin >> choice;
    while (choice < 0 || choice > 2) {
        cout << "Invalid choice. Enter your choice (0-2): ";
        cin >> choice;
    }
    return static_cast<Choice>(choice);
}

Choice getComputerChoice() {
    srand(time(NULL));
    int choice = rand() % 3;
    return static_cast<Choice>(choice);
}

void printChoice(Choice choice) {
    switch (choice) {
        case ROCK:
            cout << "Rock";
            break;
        case PAPER:
            cout << "Paper";
            break;
        case SCISSORS:
            cout << "Scissors";
            break;
    }
}

int compareChoices(Choice userChoice, Choice computerChoice) {
    if (userChoice == computerChoice) {
        return 0;
    } else if (userChoice == ROCK && computerChoice == SCISSORS ||
               userChoice == PAPER && computerChoice == ROCK ||
               userChoice == SCISSORS && computerChoice == PAPER) {
        return 1;
    } else {
        return -1;
    }
}

int main() {
    cout << "Rock Paper Scissors" << endl;
    printChoices();
    Choice userChoice = getUserChoice();
    Choice computerChoice = getComputerChoice();
    cout << "You chose ";
    printChoice(userChoice);
    cout << endl << "Computer chose ";
    printChoice(computerChoice);
    cout << endl;
    int result = compareChoices(userChoice, computerChoice);
    if (result == 0) {
        cout << "It's a tie!" << endl;
    } else if (result == 1) {
        cout << "You win!" << endl;
    } else {
        cout << "Computer wins!" << endl;
    }
    return 0;
}
