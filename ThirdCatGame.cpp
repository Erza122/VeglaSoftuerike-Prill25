#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>   // For system call to play video
#include <thread>
#include <chrono>

using namespace std;

// Global flag for timer expiration
bool timeUp = false;
bool timerStarted = false; // Flag to ensure the timer starts only once

// Timer function: counts down from timeLimit seconds and sets timeUp when done.
void timerFunction(int timeLimit) {
    for (int i = timeLimit; i > 0; i--) {
        if (timeUp) break;  // Stop the timer if timeUp flag is set (when game ends)
        cout << "\rTime remaining: " << i << " seconds " << flush;
        this_thread::sleep_for(chrono::seconds(1));
    }
    if (!timeUp) {
        cout << "\nTime is up!" << endl;
        timeUp = true;
    }
}

// Function to play the kitten video
void playKittensVideo() {
    string videoPath = "media/kittens3_video.mp4"; // Modify path as needed

#ifdef _WIN32
    // Play video with default player (asynchronously)
    system(("start " + videoPath).c_str());
#else
    system(("vlc " + videoPath).c_str());
#endif
}

// Function to display the rooms with visuals
// Parameters:
//   catRoom: the room that has the cat (1=Left, 2=Center, 3=Right)
//   guessedRoom: the room the player just guessed (0 if none)
//   reveal: if true, then mark the guessed room as correct (C) or wrong (X); otherwise, show room numbers.
void displayRoomsVisual(int catRoom, int guessedRoom, bool reveal) {
    // Define room names for clarity.
    string roomNames[3] = { "Left", "Center", "Right" };

    cout << "\nRooms:" << endl;
    for (int i = 0; i < 3; i++) {
        // If we are in "reveal" mode and this room was guessed:
        if (reveal && (i + 1) == guessedRoom) {
            if (guessedRoom == catRoom) {
                cout << "[C: " << roomNames[i] << "] ";
            }
            else {
                cout << "[X: " << roomNames[i] << "] ";
            }
        }
        else {
            // Show room number instead of 'D'
            cout << "[" << (i + 1) << ": " << roomNames[i] << "] ";
        }
    }
    cout << "\n";
}

int main() {
    srand(time(0));

    // Cat is randomly hidden in one of three rooms: 1=Left, 2=Center, 3=Right.
    int catRoom = rand() % 3 + 1;

    const int maxAttempts = 5;
    int attempts = 0;
    int guess = 0;
    bool caught = false;

    // Ask if player is ready to start
    string ready;
    cout << "Welcome to Catch The Cat!" << endl;
    cout << "There are three rooms:" << endl;
    cout << "1. Left, 2. Center, 3. Right" << endl;
    cout << "You have " << maxAttempts << " attempts and 30 seconds to catch the cat." << endl;
    cout << "Type 'start' to begin: ";
    cin >> ready;

    if (ready == "start" || ready == "Start") {
        // Start timer: player has 30 seconds to catch the cat.
        const int timeLimit = 30;
        thread timerThread(timerFunction, timeLimit);
        timerStarted = true;

        while (attempts < maxAttempts && !caught && !timeUp) {
            cout << "\nAttempt " << (attempts + 1) << " of " << maxAttempts << endl;
            // Show the rooms. Before a guess, no room is revealed.
            displayRoomsVisual(catRoom, 0, false);

            cout << "Enter a room number (1 for Left, 2 for Center, 3 for Right): ";
            cin >> guess;

            if (guess < 1 || guess > 3) {
                cout << "Invalid room selection. Please choose 1, 2, or 3." << endl;
                continue;
            }

            attempts++;

            if (guess == catRoom) {
                caught = true;
                // Reveal the correct guess:
                displayRoomsVisual(catRoom, guess, true);
                cout << "\nYou caught the cat!" << endl;
                timeUp = true; // Stop the timer if the cat is caught
            }
            else {
                cout << "\nNo cat in that room." << endl;
                // Reveal that the guess was wrong:
                displayRoomsVisual(catRoom, guess, true);
            }
        }

        if (caught) {
            cout << "Congratulations! You caught the cat in " << attempts << " attempts." << endl;
            playKittensVideo();
        }
        else if (timeUp) {
            cout << "Time is up! You lost the game." << endl;
        }
        else {
            cout << "Out of attempts! The cat escaped." << endl;
        }

        // Stop the timer thread if it is still running
        timeUp = true;
        timerThread.join(); // Wait for the timer thread to finish
    }
    else {
        cout << "Game not started. Exiting..." << endl;
    }

    return 0;
}
