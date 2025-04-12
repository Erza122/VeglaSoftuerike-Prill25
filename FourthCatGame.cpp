#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to ask a question and get player's response
string askQuestion(const string& question) {
    string answer;
    cout << question << " (yes/no): ";
    cin >> answer;
    return answer;
}

int main() {
    srand(time(0)); // Seed for random number generation

    // Array of possible rooms where the cat could be hiding
    string rooms[] = { "living room", "kitchen", "bathroom", "bedroom", "attic" };
    int catRoom = rand() % 5; // Randomly select the room where the cat is hiding

    cout << "Welcome to the Cat Finder Game!" << endl;
    cout << "You need to find where the cat is hiding in the house." << endl;

    bool foundCat = false;
    int attempts = 0;

    while (!foundCat && attempts < 3) {
        cout << "\nYou have " << (3 - attempts) << " attempts left." << endl;

        // Ask the player which room they want to search
        string guess = askQuestion("Do you want to search the living room?");
        if (guess == "yes" || guess == "y") {
            if (catRoom == 0) {
                foundCat = true;
                cout << "You found the cat in the living room!" << endl;
            }
            else {
                cout << "The cat is not in the living room." << endl;
            }
        }

        guess = askQuestion("Do you want to search the kitchen?");
        if (guess == "yes" || guess == "y") {
            if (catRoom == 1) {
                foundCat = true;
                cout << "You found the cat in the kitchen!" << endl;
            }
            else {
                cout << "The cat is not in the kitchen." << endl;
            }
        }

        guess = askQuestion("Do you want to search the bathroom?");
        if (guess == "yes" || guess == "y") {
            if (catRoom == 2) {
                foundCat = true;
                cout << "You found the cat in the bathroom!" << endl;
            }
            else {
                cout << "The cat is not in the bathroom." << endl;
            }
        }

        guess = askQuestion("Do you want to search the bedroom?");
        if (guess == "yes" || guess == "y") {
            if (catRoom == 3) {
                foundCat = true;
                cout << "You found the cat in the bedroom!" << endl;
            }
            else {
                cout << "The cat is not in the bedroom." << endl;
            }
        }

        guess = askQuestion("Do you want to search the attic?");
        if (guess == "yes" || guess == "y") {
            if (catRoom == 4) {
                foundCat = true;
                cout << "You found the cat in the attic!" << endl;
            }
            else {
                cout << "The cat is not in the attic." << endl;
            }
        }

        attempts++; // Increment the number of attempts
    }

    if (!foundCat) {
        cout << "\nSorry! You ran out of attempts. The cat was hiding in the "
            << rooms[catRoom] << "." << endl;
    }

    return 0;
}
