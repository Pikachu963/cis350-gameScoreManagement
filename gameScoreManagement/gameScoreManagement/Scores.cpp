// Implementation of Scores class
#include "Scores.h"

Scores::Scores(int maxEnt) : maxEntries(maxEnt), numEntries(0), entries(vector<GameEntry>(maxEnt)) {}

Scores::~Scores() {
    // No need for manual memory management since we use std::vector
}

void Scores::add(const GameEntry& e) {
    if (numEntries < maxEntries) {
        entries[numEntries] = e;
        numEntries++;
        // insertionSort1();
    }
    else if (e.getScore() > entries[maxEntries - 1].getScore()) {
        entries[maxEntries - 1] = e;
        //insertionSort1();
    }
}

GameEntry Scores::remove(int i) {
    if (i < 0 || i >= numEntries) {
        throw out_of_range("Invalid index");
    }
    GameEntry removed = entries[i];
    for (int j = i; j < numEntries - 1; j++) {
        entries[j] = entries[j + 1];
    }
    numEntries--;
    return removed;
}

const vector<GameEntry>& Scores::getGameEntries() const {
    return entries;
}

void Scores::printScores() const {
    for (int i = 0; i < numEntries; i++) {
        cout << entries[i].getName() << " : " << entries[i].getScore() << endl;
    }
}

int Scores::numEnt() const {
    return numEntries;
}

void Scores::insertionSort1(bool ascending = true) {
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

int Scores::searchScore(const std::string& playerName) const {
    for (int index = 0; index < entries.size(); index++) { // iterating through the vector of entries
        if (entries.at(index).getName() == playerName) { // checking if specific entry is the specific player whose score was requested
            return entries.at(index).getScore(); // returns that score if the player is found
        }
    }
}

double Scores::averageMaxScores() const {
    double total = 0;
    double totalEntries = 0;
    for (int index = 0; index < entries.size(); index++) { // iterating through the vector of entries
        int entryScore = entries.at(index).getScore();
        if (entryScore > 0) { // this is used to determine if the score at the index is empty (0) or not
            total += entryScore;
            totalEntries += 1;
        }
    }
    return (total / totalEntries); // calculating average
}

std::pair<int, int> Scores::findMinMaxScores() const {
    pair<int, int> minMax;
    int tempMin = entries.at(0).getScore(); // setting temporary minimum as first value to compare to rest of scores
    int tempMax = entries.at(0).getScore(); // setting temporary maximum as first value to compare to rest of scores
    for (int index = 1; index < entries.size(); index++) {
        if (tempMin > entries.at(index).getScore() && entries.at(index).getScore() > 0) { // checking if score right after is lower than the temporary minimum. this statement also checks to make sure the score is valid (not 0)
            tempMin = entries.at(index).getScore(); // changes tempMin if the next score is found to be smaller
        }
        if (tempMax < entries.at(index).getScore() && entries.at(index).getScore() > 0) { // checking if score right after is lower than the temporary maximum. this statement also checks to make sure the score is valid (not 0)
            tempMax = entries.at(index).getScore(); // changes tempMax if the next score is found to be smaller
        }
    }
    minMax.first = tempMin;
    minMax.second = tempMax;
    return minMax;
}

