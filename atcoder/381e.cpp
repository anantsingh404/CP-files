#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector<pair<int, vector<char>>> segPatterns = {
    {92229, {'A', 'D'}}, {93339, {'B'}}, {92222, {'C', 'F'}}, {93333, {'E'}}, {92336, {'G'}},
    {91119, {'H', 'N', 'U'}}, {22322, {'I'}}, {62229, {'J'}}, {92226, {'K'}}, {91111, {'L'}},
    {91519, {'M', 'W'}}, {72227, {'O'}}, {92225, {'P'}}, {92339, {'Q'}}, {93336, {'R'}},
    {63336, {'S'}}, {11911, {'T'}}, {71117, {'V'}}, {22122, {'X'}}, {62226, {'Y'}}, {23332, {'Z'}}
};

char decodeSegment(int pos, const vector<string>& led) {
    string segValue = "";
    for (int i = 0; i < 5; i++) {
        int sum = 0;
        for (int j = 0; j < 9; j++) {
            sum += led[j][pos + i] - '0';
        }
        segValue += to_string(sum);
    }
    int segmentKey = stoi(segValue);

    if (segmentKey == 91519) {
        if (led[0].substr(pos, 5) == "11111") {
            return 'M';
        } else {
            return 'W';
        }
    } else if (segmentKey == 91119) {
        if (led[8].substr(pos, 5) == "11111") {
            return 'U';
        } else if (led[4].substr(pos, 5) == "11111") {
            return 'H';
        } else {
            return 'N';
        }
    } else if (segmentKey == 92222) {
        if (led[4].substr(pos, 5) == "11111") {
            return 'F';
        } else {
            return 'C';
        }
    } else if (segmentKey == 92229) {
        if (led[8].substr(pos, 5) == "11111") {
            return 'D';
        } else {
            return 'A';
        }
    } else {
        for (auto& p : segPatterns) {
            if (p.first == segmentKey) {
                return p.second[0];
            }
        }
    }
    return '?'; 
}

string decodeDisplay(const vector<string>& led) {
    int totalColumns = led[0].size();
    string mergedDisplay = led[0];
    
    for (int i = 1; i < 9; i++) {
        for (int j = 0; j < totalColumns; j++) {
            if (mergedDisplay[j] == '0' && led[i][j] == '1') {
                mergedDisplay[j] = '1';
            }
        }
    }

    string result = "";
    int idx = 0;
    while (idx < totalColumns) {
        if (mergedDisplay[idx] == '1') {
            result += decodeSegment(idx, led);
            idx += 5;
        } else {
            idx++;
        }
    }
    return result;
}

int main() {
    int rows = 9;
    vector<string> led(rows);
    for (int i = 0; i < rows; i++) {
        cin >> led[i];
    }
    cout << decodeDisplay(led) << endl;
    return 0;
}
