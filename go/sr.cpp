#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to simulate sending a frame
void sendFrame(int frameNumber) {
    cout << "Sending Frame " << frameNumber << endl;
}

// Function to simulate receiving an acknowledgment with a 50% chance of success
bool receiveAck(int frameNumber) {
    return rand() % 2 == 0; // 50% chance to successfully receive an acknowledgment
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    int totalFrames, windowSize;
    
    // Taking user input for total number of frames and window size
    cout << "Enter total number of frames: ";
    cin >> totalFrames;
    cout << "Enter window size: ";
    cin >> windowSize;

    bool ackReceived[totalFrames] = { false }; // Track acknowledgment status of each frame
    int base = 0; // The base of the current window
    int totalTransmissions = 0; // Counter for total transmissions

    while (base < totalFrames) {
        // Send all frames in the current window
        for (int i = 0; i < windowSize && (base + i) < totalFrames; ++i) {
            int frameNumber = base + i;
            if (!ackReceived[frameNumber]) {
                sendFrame(frameNumber);
                totalTransmissions++;
            }
        }

        // Check for acknowledgments
        for (int i = 0; i < windowSize && (base + i) < totalFrames; ++i) {
            int frameNumber = base + i;
            if (!ackReceived[frameNumber] && receiveAck(frameNumber)) {
                cout << "Acknowledgment received for Frame " << frameNumber << endl;
                ackReceived[frameNumber] = true;
            }
        }

        // Slide the window forward
        while (base < totalFrames && ackReceived[base]) {
            base++;
        }

        cout << endl;
    }

    cout << "Total number of transmissions: " << totalTransmissions << endl;

    return 0;
}
