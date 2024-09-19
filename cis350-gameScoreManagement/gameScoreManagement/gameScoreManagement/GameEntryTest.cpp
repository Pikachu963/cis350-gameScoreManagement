#include <iostream>
#include "Scores.h"  // Assuming this is the header file name

using namespace std;
void insertionSort(vector<GameEntry>& entries, bool ascending);
int main() {
    GameEntry mike("Mike", 1105);
    GameEntry rob("Rob", 750);
    GameEntry paul("Paul", 720);
    GameEntry anna("Anna", 660);
    GameEntry rose("Rose", 590);
    GameEntry jack("Jack", 510);
    GameEntry jill("Jill", 740);

    Scores BAM;
    BAM.add(mike);
    BAM.add(rob);
    BAM.add(paul);
    BAM.add(anna);
    BAM.add(rose);
    BAM.add(jack);
    BAM.add(jill);

    cout << "Paul's score: ";
    cout << BAM.searchScore("Paul") << endl << endl;

    cout << "Average of all scores: ";
    cout << BAM.averageMaxScores() << endl << endl;

    pair <int, int> minMaxBAM = BAM.findMinMaxScores();
    cout << "Minimum Score: ";
    cout << minMaxBAM.first << endl;
    cout << "Maximum Score: ";
    cout << minMaxBAM.second << endl << endl;

    cout << "Num of Entries: " << BAM.numEnt() << endl;
    BAM.printScores();

    cout << endl;

    // Testing removal of an entry
    BAM.remove(3);  // Remove the entry at index 3 (Anna)
    cout << "After removing entry at index 3:" << endl;
    BAM.printScores();

    cout << endl;

    // Explicitly calling insertionSort using getGameEntries()
    // BAM.insertionSort1(true);
    vector<GameEntry> entries = BAM.getGameEntries();
    insertionSort(entries, true);
    cout << "Sorted Entries in Ascending Order:" << endl;

    for (const auto& entry : entries) {
        if (!entry.getName().empty())
            cout << entry.getName() << " : " << entry.getScore() << endl;
    }
    //BAM.printScores();
    return 0;
}

void insertionSort(vector<GameEntry>& entries, bool ascending = true) {
    int numEntries = entries.size();
    for (int i = 1; i < numEntries; i++) {
        GameEntry key = entries[i];
        int j = i - 1;
        if (ascending) {
            // Sort in ascending order
            while (j >= 0 && entries[j].getScore() > key.getScore()) {
                entries[j + 1] = entries[j];
                j--;
            }
        }
        else {
            // Sort in descending order
            while (j >= 0 && entries[j].getScore() < key.getScore()) {
                entries[j + 1] = entries[j];
                j--;
            }
        }
        entries[j + 1] = key;
    }
}
