class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded = "";
        
        for (const string& s : strs) {
            string transformed = "";
            for (char c : s) {
                // Apply x - 5 transformation directly
                transformed += static_cast<char>(c - 5);
            }
            
            // Format: <length>#<transformed_string>
            encoded += to_string(transformed.length()) + "#" + transformed;
        }
        
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        
        while (i < s.length()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            
            int length = stoi(s.substr(i, j - i));
            i = j + 1; // Move past '#'
            
            string transformed = s.substr(i, length);
            string original = "";
            
            for (char c : transformed) {
                // Reverse transformation: x + 5
                original += static_cast<char>(c + 5);
            }
            
            result.push_back(original);
            i += length; // Move to next encoded string
        }
        
        return result;
    }
};