#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h> // For system call

using namespace std;

// Function to play the kitten video
void playKittensVideo() {
    string videoPath = "media/kittens3_video.mp4"; // Modify the path if needed

#ifdef _WIN32
    // Open the video in the default player
    system(("start " + videoPath).c_str());
#else
    // For Linux/MacOS, using VLC or default video player
    system(("vlc " + videoPath).c_str());
#endif
}

int main() {
    srand(time(0));  // Seed the random number generator

    cout << "Welcome to Catch The Cat!" << endl;
    cout << "There are three rooms:" << endl;
    cout << "1. Left" << endl;
    cout << "2. Center" << endl;
    cout << "3. Right" << endl;
    cout << "Try to catch the cat before it escapes!" << endl;

    // Randomly decide on the initial cat position (1: Left, 2: Center, 3: Right)
    int catPosition = rand() % 3 + 1;

    int attempts = 0, guess = 0;
    const int maxAttempts = 5;  // You get 5 attempts to catch the cat
    bool caught = false;

    while (attempts < maxAttempts && !caught) {
        cout << "\nAttempt " << (attempts + 1) << " of " << maxAttempts << endl;
        cout << "Choose a room to chase the cat (1 for Left, 2 for Center, 3 for Right): ";
        cin >> guess;

        // Validate input
        if (guess < 1 || guess > 3) {
            cout << "Invalid choice. Please choose 1, 2, or 3." << endl;
            continue;
        }

        attempts++;

        if (guess == catPosition) {
            cout << "You caught the cat!" << endl;
            caught = true;
            break;
        } else {
            cout << "The cat escaped!" << endl;
            // Cat moves randomly to one of the rooms (it can even remain in the same room)
            catPosition = rand() % 3 + 1;
            cout << "Try again!" << endl;
        }
    }

    if (caught) {
        cout << "\nCongratulations! You caught the cat in " << attempts << " attempts." << endl;
        playKittensVideo();
    } else {
        cout << "\nGame Over! The cat got away." << endl;
    }

    return 0;
}
