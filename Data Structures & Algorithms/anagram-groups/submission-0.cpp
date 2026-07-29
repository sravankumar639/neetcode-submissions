#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        if (strs.empty()) return {};

        // Step 1: Create a duplicate and sort individual characters
        std::vector<std::string> dub = strs;
        for (int i = 0; i < dub.size(); i++) {
            std::sort(dub[i].begin(), dub[i].end());
        }
        
        std::vector<std::string> dub2 = dub; // Unsorted keys matching strs index order
        std::sort(dub.begin(), dub.end());   // Sorted keys to count unique groups

        // Step 2: Count unique keys
        int count = 1;
        for (int i = 1; i < dub.size(); i++) {
            if (dub[i] != dub[i - 1]) {
                count++;
            }
        }

        // Step 3: Collect unique keys
        std::vector<std::string> keys(count);
        keys[0] = dub[0];
        int c = 1;
        for (int i = 1; i < dub.size(); i++) {
            if (dub[i] != dub[i - 1]) {
                keys[c] = dub[i];
                c++;
            }
        }

        // Step 4: Final compare — group original strings by key match
        std::vector<std::vector<std::string>> ans(count);
        for (int i = 0; i < keys.size(); i++) {
            for (int j = 0; j < dub2.size(); j++) {
                if (keys[i] == dub2[j]) {
                    ans[i].push_back(strs[j]);
                }
            }
        }

        return ans;
    }
};