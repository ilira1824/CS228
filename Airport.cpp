// Airport.cpp

#include "Airport.h"
#include <queue>
#include <cstdlib>
#include <iostream>

using namespace std;

void Airport(
        int landingTime, // Time segments needed for one plane to land
        int takeoffTime, // Time segs. needed for one plane to take off
        double arrivalProb, // Probability that a plane will arrive in
        // any given segment to the landing queue
        double takeoffProb, // Probability that a plane will arrive in
        // any given segment to the takeoff queue
        int maxTime, // Maximum number of time segments that a plane
        // can stay in the landing queue
        int simulationLength// Total number of time segs. to simulate
        ) 


{
    queue<int> takeoffQ, landingQ;
    int landingWaits = 0, takeoffWaits = 0, timeFree = 0, crashes = 0;
    int numLandings = 0, numTakeoffs = 0;

    srand(time(NULL));

    for (int curTime = 0; curTime < simulationLength; curTime++) {      // Run code for desired length of simulation

        if (((double) rand() / (double) RAND_MAX) < arrivalProb) {      // Randomly decides if a new plane is added to landing queue
                                                                        // arrivalProb(parameter input), determines likelihood
            landingQ.push(curTime);

        }
        if (((double) rand() / (double) RAND_MAX) < takeoffProb) {      // Randomly decides if a new plane is added to takeoff queue
                                                                        // takeoffProb(parameter input), determines likelihood
            takeoffQ.push(curTime);

        }

        if (timeFree <= curTime) {                                      // Check to see if a plane is in the process of landing or taking off
                                                                        // Plane cannot land or takeoff if timeFree is greater than curTime

            if (!landingQ.empty()) {                                    // If the landing queue is not empty

                if ((curTime - landingQ.front()) > maxTime) {           // Check if the plane still has fuel
                    crashes++;                                          // Tracks the total number of crashes, adds by 1 if it does
                    landingQ.pop();                                     // Crash the plane and remove it from queue
                    cout << "Plane has crashed at time " << curTime << endl;
                } else {                                                // Plane still has fuel
                    landingWaits += (curTime - landingQ.front());       // Time plane in landing queue has been waiting is added total time planes in landing queue have waited
                    landingQ.pop();                                     // Remove the plane about to land from queue
                    timeFree += landingTime;                            // Time it takes to land is accounted for
                    numLandings++;                                      // Total number of landings is tracked and added by 1
                    cout << "Plane has landed at time " << curTime << endl;
                }

            }
            else if (!takeoffQ.empty()) {                               // If the takeoff queue is not empty, ONLY RUNS IF LANDING QUEUE IS EMPTY

                takeoffWaits += (curTime - takeoffQ.front());           // Total time planes for takeoff have been waiting is added by time the next plane for take off has been waiting
                takeoffQ.pop();                                         // Remove the plane about to takeoff 
                timeFree += takeoffTime;                                // time it takes to takeoff is accounted for
                numTakeoffs++;                                          // Total number of takeoffs is tracked and added by 1
                cout << "Plane has took off at time " << curTime << endl;

            }

        }

    }

    // If there are still planes in landing queue after simulation is over AND they are operating but not supposed to (no fuel)
    // Crash them and remove them from queue
    // Ignores any non-crashed planes still left in the queue
    while (!landingQ.empty() && (simulationLength - landingQ.front()) > maxTime) {
        crashes++;
        landingQ.pop();
    }

    cout << "Number of crashes: " << crashes << "\n";
    cout << "Number of takeoffs: " << numTakeoffs << " (avg delay " <<
            ((double) takeoffWaits) / ((double) numTakeoffs) << ")\n";
    cout << "Number of landings: " << numLandings << " (avg delay " <<
            ((double) landingWaits) / ((double) numLandings) << ")\n";
    cout << "Number of planes in takeoff queue: " << takeoffQ.size() << "\n";
    cout << "Number of planes in landing queue: " << landingQ.size() << "\n";

}
