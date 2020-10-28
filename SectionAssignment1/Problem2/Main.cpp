#include <iostream>
#include <fstream>
#include "console.h"
#include "error.h"
using namespace std;

struct gradesT {
    int min;
    int max;
    double average;
};

void PrintGrades(gradesT grades)
{
    cout << "min: " << grades.min << ", max: " << grades.max
         << ", average: " << grades.average << endl;
}

gradesT ReadScores(string filename)
{
    ifstream scoresFile;
    scoresFile.open(filename);

    if (!scoresFile.is_open())
        error("Couldn't open file");

    int score;
    int count = 0, sum = 0;
    gradesT res;
    res.min = 100;
    res.max = 0;
    while (scoresFile >> score) {
        count++;
        sum += score;
        if (score < res.min)
            res.min = score;
        if (score > res.max)
            res.max = score;
    }
    res.average = sum / double(count);

    scoresFile.close();

    return res;
}

int main() {
    gradesT grades = ReadScores("scores.txt");
    PrintGrades(grades);
    return 0;
}
