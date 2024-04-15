#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#ifndef SETSANDMAPS_H_
#define SETSANDMAPS_H_

class SetsAndMaps {
    
public:
    
    static void bstSort(char *arr, int len) { // complete this method
        map<char, int> orderedMap;
        for (int i = 0; i < len; i++) {
            if (orderedMap.find(arr[i]) == orderedMap.end()) {
                orderedMap[arr[i]] = 1;
            }
            else {
                orderedMap[arr[i]]++;
            }
        }

        int counter = 0;
        for (auto it = orderedMap.begin(); it != orderedMap.end(); ++it) {
            for (int i = 0; i < it->second; ++i) {
                arr[counter++] = it->first;
            }
        }

    }
    
    static vector<string> intersection(vector<string> &arg1, vector<string> &arg2) { // complete this method
        unordered_set<string> set1;
        unordered_set<string> common; 
        vector<string> arr;
        for (auto &s : arg1) {
            set1.insert(s);
        }
        for (auto &s : arg2) {
            if (set1.find(s) != set1.end()) {
                common.insert(s);
            }
        }
        arr.insert(arr.end(), common.begin(), common.end());
        return arr;
    }
};

#endif /* SETSANDMAPS_H_ */
