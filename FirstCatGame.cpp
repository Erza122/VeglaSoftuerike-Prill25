#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>
#include <windows.h>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;

// Function to display the grid with ASCII art
void displayGrid(vector<vector<char>>& grid) {
    int gridSize = grid.size();  // Determine the grid size dynamically

    cout << "\nCurrent Grid: \n";
    cout << "    ";
    for (int i = 0; i < gridSize; i++) {
        cout << i << "   ";  // Column headers
    }
    cout << endl;

    for (int i = 0; i < gridSize; i++) {
        cout << i << " ";  // Row headers
        for (int j = 0; j < gridSize; j++) {
            cout << "[" << grid[i][j] << "] ";
        }
        cout << endl;
    }
}

// Function to play the kitten video asynchronously
void playKittensVideo() {
    string videoPath = "media/kittens_video.mp4"; // Modify the path if needed

#ifdef _WIN32
    // Open the video in the default player asynchronously
    system(("start /min " + videoPath).c_str());
#else
    // For Linux/MacOS, using VLC or default video player
    system(("vlc " + videoPath + " &").c_str());
#endif
}

// Function to give a hint about the cat's position
void giveHint(int catRow, int catCol, int guessRow, int guessCol) {
    int rowDiff = abs(catRow - guessRow);
    int colDiff = abs(catCol - guessCol);

    cout << "\nHint: ";
    if (rowDiff > colDiff) {
        cout << "The cat is further " << (catRow > guessRow ? "down" : "up") << "." << endl;
    }
    else {
        cout << "The cat is further " << (catCol > guessCol ? "right" : "left") << "." << endl;
    }
}

// Function to set up obstacles randomly in the grid
void placeObstacles(vector<vector<char>>& grid, int gridSize, int numObstacles) {
    srand(time(0));
    int obstaclesPlaced = 0;

    // Use a more efficient approach for placing obstacles
    while (obstaclesPlaced < numObstacles) {
        int row = rand() % gridSize;
        int col = rand() % gridSize;

        if (grid[row][col] == '-') {  // If the cell is empty
            grid[row][col] = '#'; // Place an obstacle
            obstaclesPlaced++;
        }
    }
}

// Function to start a countdown timer in the main loop (non-blocking)
void startTimer(int timeLimit, bool& timeUpFlag) {
    for (int i = timeLimit; i > 0; --i) {
        cout << "\nTime remaining: " << i << " seconds" << endl;
        this_thread::sleep_for(chrono::seconds(1)); // Sleep for 1 second
        if (i == 1) {
            timeUpFlag = true;  // Set flag when time is up
            cout << "\nTime's up!" << endl;
            break;
        }
    }
}

int main() {
    int gridSize = 5;  // Easy difficulty: 5x5 grid
    int timeLimit = 30; // Easy difficulty: 30 seconds
    int numObstacles = 5;  // Easy difficulty: 5 obstacles

    // Dynamically create the grid based on the chosen gridSize
    vector<vector<char>> grid(gridSize, vector<char>(gridSize, '-'));  // Create a 2D vector (gridSize x gridSize)

    int catRow = rand() % gridSize;
    int catCol = rand() % gridSize;

    // Place obstacles on the grid
    placeObstacles(grid, gridSize, numObstacles);

    // Display instructions
    cout << "Find the hidden cat in the grid. Avoid obstacles!" << endl;
    cout << "Enter coordinates between 0 and " << gridSize - 1 << " for both row and column." << endl;

    // Start the timer in a separate thread
    bool timeUpFlag = false;
    thread timerThread(startTimer, timeLimit, ref(timeUpFlag));

    int guessRow, guessCol;
    int guessCount = 0;  // To count the number of guesses

    while (!timeUpFlag) {
        displayGrid(grid);  // Display the current grid

        // Take input from the user
        cout << "\nEnter row (0-" << gridSize - 1 << "): ";
        cin >> guessRow;
        cout << "Enter column (0-" << gridSize - 1 << "): ";
        cin >> guessCol;

        // Check if the guess is within bounds
        if (guessRow < 0 || guessRow >= gridSize || guessCol < 0 || guessCol >= gridSize) {
            cout << "Invalid coordinates! Please try again." << endl;
            continue;
        }

        // Check for obstacles
        if (grid[guessRow][guessCol] == '#') {
            cout << "Oops! There's an obstacle here. Try again!" << endl;
            continue;
        }

        // Check if the guess is correct
        if (guessRow == catRow && guessCol == catCol) {
            cout << "Congratulations! You found the cat!" << endl;
            grid[catRow][catCol] = 'C';  // Mark the cat's position
            displayGrid(grid);  // Show updated grid with cat found

            // Play kitten video asynchronously
            playKittensVideo();
            break;  // End the game once the cat is found
        }
        else {
            cout << "No cat here. Try again!" << endl;

            // Mark the guess on the grid
            grid[guessRow][guessCol] = 'X';
            displayGrid(grid);  // Show updated grid with the guess

            // Provide a hint after 3 incorrect guesses
            guessCount++;
            if (guessCount >= 3) {
                giveHint(catRow, catCol, guessRow, guessCol);
                guessCount = 0;  // Reset guess count after hint
            }
        }
    }

    // Ensure the timer thread completes
    if (timerThread.joinable()) {
        timerThread.join();
    }

    return 0;
}
