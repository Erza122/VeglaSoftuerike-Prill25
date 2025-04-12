#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h> // For system call

using namespace std;

// Function to play the kitten video
void playKittensVideo() {
    string videoPath = "kittens2_video.mp4"; // Modify the path if needed

#ifdef _WIN32
    // Open the video in the default player
    system(("start " + videoPath).c_str());
#else
    // For Linux/MacOS, using VLC or default video player
    system(("vlc " + videoPath).c_str());
#endif
}

// Function to display the rooms with ASCII art
void displayRooms(int catRoom, int guessRoom) {
    cout << "\nRooms: \n";
    for (int i = 1; i <= 5; i++) {
        if (i == guessRoom) {
            cout << "[X] "; // Represent a guessed room with 'X'
        } else {
            cout << "[ ] "; // Empty room
        }
    }
    cout << "\n";
}

// Function to start the simple cat guessing game with visuals
void startSimpleCatGame() {
    srand(time(0));

    // Randomly select a room (1 to 5) for the cat to hide in
    int catRoom = rand() % 5 + 1;

    cout << "Welcome to the Simple Cat Finder Game!" << endl;
    cout << "The cat is hiding in one of the rooms (1 to 5)." << endl;

    int guess = 0; // Initialize guess to a default value
    while (true) {
        displayRooms(catRoom, guess); // Display the current state of the rooms

        cout << "Guess the room number where the cat is hiding (1-5): ";
        cin >> guess;

        if (guess < 1 || guess > 5) {
            cout << "Invalid input! Please guess a room number between 1 and 5." << endl;
            continue;
        }

        if (guess == catRoom) {
            cout << "Congratulations! You found the cat!" << endl;
            break;
        } else {
            cout << "No cat here! Try again." << endl;
        }
    }

    // Play the kitten video once the cat is found
    playKittensVideo();
}

int main() {
    // Start the simple cat game with visuals
    startSimpleCatGame();

    return 0;
}
