#ifndef SCORES_H
#define SCORES_H

#include "GameEntry.h"
#include <vector>
#include <iostream>
class Scores {
public:
    Scores(int maxEnt = 10);
    ~Scores();
    void add(const GameEntry& e);
    GameEntry remove(int i);
    const vector<GameEntry>& getGameEntries() const;
    void printScores() const;
    int numEnt() const;
    void insertionSort1(bool ascending);
    int searchScore(const std::string& playerName) const;
    double averageMaxScores() const;
    std::pair<int, int> findMinMaxScores() const;

private:
    int maxEntries;
    int numEntries;
    vector<GameEntry> entries;
};

#endif // SCORES_H