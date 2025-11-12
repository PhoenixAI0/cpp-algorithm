#include <bits/stdc++.h>
using namespace std;

struct Student {
    int id;
    int score;
} students[5005];

bool compareStudents(Student x, Student y) {
    if (x.score == y.score) 
        return x.id < y.id;
    return x.score > y.score;
}

int numStudents, cutoffCount;
int cutoffScore;

int main() {
    cin >> numStudents >> cutoffCount;
    cutoffCount = 1.5 * cutoffCount;

    for (int i = 1; i <= numStudents; i++) {
        cin >> students[i].id >> students[i].score;
    }
    sort(students + 1, students + numStudents + 1, compareStudents);

    cutoffScore = students[cutoffCount].score;

    while (students[cutoffCount].score == students[cutoffCount + 1].score) {
        cutoffCount++;
    }

    cout << cutoffScore << " " << cutoffCount << "\n";
    for (int i = 1; i <= cutoffCount; i++) {
        cout << students[i].id << " " << students[i].score << "\n";
    }
}