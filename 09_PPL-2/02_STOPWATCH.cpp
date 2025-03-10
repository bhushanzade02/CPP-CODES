#include <iostream>
#include <unistd.h> 

using namespace std;

int main() {
    int minutes, seconds;
    
    cout << "Enter minutes: ";
    cin >> minutes;
    cout << "Enter seconds: ";
    cin >> seconds;

    // Convert everything into total seconds
    int totalTime = (minutes * 60) + seconds;

    while (totalTime > 0) {
        minutes = totalTime / 60;
        seconds = totalTime % 60;

        // Manually handle leading zero formatting
        cout << "\rTime Remaining: ";
        if (minutes < 10) cout << "0";
        cout << minutes << ":";

        if (seconds < 10) cout << "0";
        cout << seconds << flush;

        sleep(1); // Delay for 1 second
        totalTime--; // Decrement time
    }

    cout << "\nTimer Ended! \a" << endl;
    return 0;
}
