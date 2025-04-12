// Orignal work submitted by John-Michael Barron
// Correction submitted by Zachary D. White
// COPY: This program takes the user's input of their YouTube video length,
// and how fast they prefer playback. Then displays how long the video 
// truly is, with variable playback speed. / Copy

#include <iostream>
#include <iomanip>
using namespace std;

// Proper function prototype with return type 
double playbackTime(double duration, double speed);

// This has been corrected to match return type of void
void showTime(double result) {
    cout << fixed << setprecision(2);
    cout << "Adjusted video length: " << result << " minutes" << endl;
}

int main() {
    double videoLength, playbackSpeed;

    cout << "Enter video length in minutes: ";
    cin >> videoLength;

    cout << "Enter playback speed (1.5 for 1.5x): ";
    cin >> playbackSpeed;

    double newTime = playbackTime(videoLength, playbackSpeed);
    showTime(newTime);

    return 0;
}

// Redefined after usage
double playbackTime(double duration, double speed) {
    return duration / speed;
}
