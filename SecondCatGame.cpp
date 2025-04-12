#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h> // For system call
#include <vector>

using namespace std;

// Function to play the kitten video
void playKittensVideo() {
    string videoPath = "media/kittens2_video.mp4"; // Modify the path if needed
#ifdef _WIN32
    system(("start " + videoPath).c_str());
#else
    system(("vlc " + videoPath).c_str());
#endif
}

// Function to display the rooms using their current status
// Each room is shown inside brackets. For example, [D] for a door, [X] for a wrong guess, [C] for the cat.
void displayRooms(const vector<char>& roomStatus) {
    cout << "\nRooms: \n";
    for (int i = 0; i < roomStatus.size(); i++) {
        cout << "[" << roomStatus[i] << "] ";
    }
    cout << "\n";
}

// Function to reset the game state if a trap is triggered
// It resets both the positions for the cat and the trap as well as the room display (all back to [D])
void resetGame(int& catRoom, int& trapRoom, vector<char>& roomStatus) {
    catRoom = rand() % 5 + 1;  // New random room for the cat (1 to 5)
    trapRoom = rand() % 5 + 1; // New random trap room (1 to 5)
    while (trapRoom == catRoom) {  // Ensure trap and cat are not in the same room
        trapRoom = rand() % 5 + 1;
    }
    for (int i = 0; i < roomStatus.size(); i++) {
        roomStatus[i] = 'D'; // Reset every room to show door
    }
}

// Main game function
void startSimpleCatGame() {
    srand(time(0));

    // Randomly select a room (1 to 5) for the cat and for the trap
    int catRoom = rand() % 5 + 1;
    int trapRoom = rand() % 5 + 1;
    while (trapRoom == catRoom) {
        trapRoom = rand() % 5 + 1;
    }

    // Initialize room statuses. Index 0 corresponds to room 1, etc.
    vector<char> roomStatus(5, 'D');

    int attempts = 0;
    int guess = 0;

    cout << "Welcome to the Simple Cat Finder Game!" << endl;
    cout << "The cat is hiding in one of the rooms (rooms 1 to 5)." << endl;
    cout << "Beware of traps! If you step into a trap, the game will reset!" << endl;

    while (true) {
        displayRooms(roomStatus);
        cout << "Guess the room number where the cat is hiding (1-5): ";
        cin >> guess;

        if (guess < 1 || guess > 5) {
            cout << "Invalid input! Please guess a room number between 1 and 5." << endl;
            continue;
        }

        // If the player steps into the trap, reset the game.
        if (guess == trapRoom) {
            cout << "Oh no! You stepped into a trap! The game will reset..." << endl;
            resetGame(catRoom, trapRoom, roomStatus);
            attempts = 0; // Reset attempt counter
            continue;
        }

        attempts++;  // Increase attempt counter for valid guesses

        // If the guess is correct, mark the room with 'C' and break out of the loop.
        if (guess == catRoom) {
            roomStatus[guess - 1] = 'C';
            displayRooms(roomStatus);
            cout << "Congratulations! You found the cat in " << attempts << " attempts." << endl;
            break;
        }
        // Otherwise, mark the guessed room with 'X' (if it isn't already marked)
        else {
            roomStatus[guess - 1] = 'X';
            cout << "No cat here! Try again." << endl;
        }
    }

    // Play the kitten video once the cat is found
    playKittensVideo();
}

int main() {
    startSimpleCatGame();
    return 0;
}
