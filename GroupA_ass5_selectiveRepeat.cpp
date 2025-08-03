#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void selectiveRepeat(int totalFrames, int windowSize, int &totalTransmissions) {
    bool ack[100] = {false};
    int sent=0;
    srand(time(0)); // Seed for randomness

    while (sent < totalFrames) {
        int endWindow = sent + windowSize;
        for (int i = sent; i < endWindow && i < totalFrames; i++) {
            if (!ack[i]) {
                cout << "Sending Frame " << i + 1 << "...\n";
                totalTransmissions++;
            }
        }
      for (int i = sent; i < endWindow && i < totalFrames; i++) {
            if (!ack[i]) {
                int success = rand() % 2;
                if (success == 0) {
                    cout << "Acknowledgment for Frame " << i + 1 << " received.\n";
                    ack[i] = true;
                } else {
                    cout << "Timeout!! Frame " << i + 1 << " not received.\n";
                }
            }
        }
        while (sent < totalFrames && ack[sent]) {
            sent++;
        }

        cout << endl;
    }
}

int main() {
    int totalFrames, windowSize, totalTransmissions = 0;

    cout << "Enter the total number of frames: ";
    cin >> totalFrames;

    cout << "Enter the window size: ";
    cin >> windowSize;

    selectiveRepeat(totalFrames, windowSize, totalTransmissions);
    cout << "Total number of transmissions (including resends): " << totalTransmissions << endl;
    return 0;

}
