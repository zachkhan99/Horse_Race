#include <iostream>
#include <ctime>
#include <cstdlib> 
#include <vector>

using namespace std;

// Define a class named "Horse"
class Horse {
private:
    int number;                                         // the horse's number
    int position;                                       // the horse's current position on the track

public:
    Horse(int number) : number(number), position(0) {}  // constructor: initialize a Horse object with a given number
    int getNumber() const { return number; }            // get the horse's number
    int getPosition() const { return position; }        // get the horse's position
    void move() { position += rand() % 2; }             // simulate the horse's position on the track
};

// Define a class named "Race"
class Race {
private:
int numHorses;                                          // number of horses in the race
    int trackLength;                                    // length of the race track
    vector<Horse> horses;                               // vector of Horse objects to represent the horses in the race

public:
    // constructor: initialize a Race object with the given number of horses and track length
    Race(int numHorses, int trackLength)
        : numHorses(numHorses), trackLength(trackLength) {
        srand(time(nullptr));   // seed the random number generator with the current time
        horses.reserve(numHorses);  // reserve memory for the horse vector
        for (int i = 0; i < numHorses; ++i) {
            horses.push_back(Horse(i + 1));  // create and initialize Horse objects
        }
    }

    // start the race simulation
    void startRace() {
        cout << "Race begins ---" << endl;
        while (true) {
            for (Horse & horse : horses) {
                horse.move();                                                   // move each horse
                if (horse.getPosition() >= trackLength) {
                    cout << "Horse " << horse.getNumber() << " wins!" << endl;  // display the winner
                    return;                                                     // exit the race
                }
            }
            printRaceStatus();                                                  // print the current race status
            cout << endl;
        }
    }

    // print the current race status
    void printRaceStatus() const {
        for (const Horse & horse : horses) {
            for (int i = 0; i < trackLength; ++i) {
                if (i == horse.getPosition()) {
                    cout << horse.getNumber();                                  // display the horse's number at its position
                } else {
                    cout << ".";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int numHorses, trackLength;
    do {                                        // get the number of horses (must be >= 2)
        cout << "Enter the number of horses: ";
        cin >> numHorses;
    } while (numHorses < 2);

    do {                                        // get the track length (must be >= 2)
        cout << "Enter the track's length: ";
        cin >> trackLength;
    } while (trackLength < 2);

    // create a Race object with the specified number of horses and track length
    Race race(numHorses, trackLength);

    // start the race simulation
    race.startRace();

    return 0;
}