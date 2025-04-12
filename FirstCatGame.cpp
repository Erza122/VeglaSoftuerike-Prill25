#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h> // For system call

using namespace std;

// Function to display the grid
void displayGrid(char grid[5][5]) {
    cout << "\nCurrent Grid: \n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "[" << grid[i][j] << "] ";
        }
        cout << endl;
    }
}

// Function to play the kitten video
void playKittensVideo() {
    string videoPath = "media/kittens_video.mp4"; // Modify the path if needed

#ifdef _WIN32
    // Open the video in the default player
    system(("start " + videoPath).c_str());
#else
    // For Linux/MacOS, using VLC or default video player
    system(("vlc " + videoPath).c_str());
#endif
}

int main() {
    srand(time(0));  // Initialize random seed

    const int gridSize = 5;  // 5x5 grid
    int catRow = rand() % gridSize;
    int catCol = rand() % gridSize;

    // Initialize grid with '-'
    char grid[5][5];
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            grid[i][j] = '-';
        }
    }

    cout << "Welcome to the Cat Finder Game!" << endl;
    cout << "Find the hidden cat in the grid (5x5)." << endl;
    cout << "Enter coordinates between 0 and 4 for both row and column." << endl;
    displayGrid(grid);  // Display the initial grid

    int guessRow, guessCol;

    while (true) {
        cout << "\nEnter row (0-4): ";
        cin >> guessRow;
        cout << "Enter column (0-4): ";
        cin >> guessCol;

        // Check if the guess is correct
        if (guessRow == catRow && guessCol == catCol) {
            cout << "Congratulations! You found the cat!" << endl;

            // Mark the cat's position on the grid
            grid[catRow][catCol] = 'C';
            displayGrid(grid);  // Show updated grid with cat found

            // Play kitten video
            playKittensVideo();
            break;  // End the game once the cat is found
        }
        else {
            cout << "No cat here. Try again!" << endl;

            // Mark the guess on the grid
            grid[guessRow][guessCol] = 'X';
            displayGrid(grid);  // Show updated grid with the guess
        }
    }

    return 0;
}
