#include <iostream>
#include "console.h"
#include "random.h"
#include "simpio.h"
using namespace std;

bool IsResultValid(int numVoters, double spread, double errorProbability)
{
    int candidateARealVotes = numVoters/2  + spread * numVoters;
    int candidateA = 0, candidateB = 0; // actual votes for each candidate
    for (int i = 0; i < numVoters; i++) {
        bool voteForA;
        if (i < candidateARealVotes)
            voteForA = true;
        else
            voteForA = false;

        // if there is an error
        if (randomChance(errorProbability))
            voteForA = !voteForA;

        // record vote
        if (voteForA)
            candidateA++;
        else
            candidateB++;
    }

    return candidateA > candidateB;
}

double InvalidResultChance(int numVoters, double spread,
                           double errorProbability, int numTrials)
{
    int numInvalid = 0; // number of trials in which election result was invalid
    for (int i = 0; i < numTrials; i++)
        if (!IsResultValid(numVoters, spread, errorProbability))
            numInvalid++;

    return double(numInvalid) / numTrials;
}

int main() {
    // prompt for number of voters
    int numVoters;
    while (true) {
        numVoters = getInteger("Enter number of voters:");
        if (numVoters > 0)
            break;
    }

    // prompt for spread
    double spread;
    while (true) {
        spread = getReal("Enter percentage spread between candidates:");
        if (spread >= 0.0 && spread <= 1.0)
            break;
    }

    // prompt for error
    double votingError;
    while (true) {
        votingError = getReal("Enter voting error percentage:");
        if (votingError >= 0.0 && votingError <= 1.0)
            break;
    }

    cout << "\nChance of an invalid election result after 500 trials = "
         << InvalidResultChance(numVoters, spread, votingError, 500) * 100 << "%"
         << endl;

    return 0;
}
