#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h> // For system call (Linux/Unix) or #include <windows.h> for Windows

using namespace std;

void playKittensVideo() {
    // Using a relative path to the video located in the 'media' folder
    string videoPath = "media/kittens_video.mp4"; // Relative path

#ifdef _WIN32
    // For Windows, using start command to open the video in default player
    system(("start " + videoPath).c_str());
#else
    // For Linux/MacOS, using the default video player (e.g., VLC)
    system(("vlc " + videoPath).c_str());
#endif
}

int main() {
    srand(time(0));  // Initialize random seed

    const int gridSize = 5; // 5x5 grid
    int catRow = rand() % gridSize;
    int catCol = rand() % gridSize;

    cout << "Welcome to the Cat Finder Game!" << endl;
    cout << "Find the hidden cat in the grid (5x5)." << endl;
    cout << "Enter coordinates between 0 and 4 for both row and column." << endl;

    int guessRow, guessCol;

    while (true) {
        cout << "Enter row (0-4): ";
        cin >> guessRow;
        cout << "Enter column (0-4): ";
        cin >> guessCol;

        if (guessRow == catRow && guessCol == catCol) {
            cout << "Congratulations! You found the cat!" << endl;
            playKittensVideo();
            break;  // End the game once the cat is found
        }
        else {
            cout << "No cat here. Try again!" << endl;
        }
    }

    return 0;
}
