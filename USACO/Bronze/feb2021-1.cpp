#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> zodiacIndex = {
    {"Ox", 0}, {"Tiger", 1}, {"Rabbit", 2}, {"Dragon", 3},
    {"Snake", 4}, {"Horse", 5}, {"Goat", 6}, {"Monkey", 7},
    {"Rooster", 8}, {"Dog", 9}, {"Pig", 10}, {"Rat", 11}
};

int getDistance(int currentZodiac, int targetZodiac, bool isNext) {
    if (isNext) {
        int forwardDistance = (targetZodiac - currentZodiac + 12) % 12;
        return forwardDistance == 0 ? 12 : forwardDistance;
    } else {
        int backwardDistance = (currentZodiac - targetZodiac + 12) % 12;
        return backwardDistance == 0 ? 12 : backwardDistance;
    }
}

int main() {
    int N;
    cin >> N;

    unordered_map<string, int> cowYearOffset;
    cowYearOffset["Bessie"] = 0;

    while (N--) {
        string newCow, born, in, direction, animal, year, from, knownCow;
        cin >> newCow >> born >> in >> direction >> animal >> year >> from >> knownCow;

        int knownCowZodiac = (zodiacIndex["Ox"] + cowYearOffset[knownCow] % 12 + 12) % 12;
        int newCowZodiac = zodiacIndex[animal];
        bool isNext = (direction == "next");
        
        int distance = getDistance(knownCowZodiac, newCowZodiac, isNext);
        if (direction == "next") {
            cowYearOffset[newCow] = cowYearOffset[knownCow] + distance;
        } else {
            cowYearOffset[newCow] = cowYearOffset[knownCow] - distance;
        }
    }

    cout << abs(cowYearOffset["Elsie"]) << endl;
}