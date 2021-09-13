#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


int main() {

    const vector<int> historgam = {1, 3, 2, 1, 4, 3, 2};

    if (historgam.size() <= 2) {
        cout << "Amount of collected water: 0" << endl;
        return 0;
    }

    vector<int> left_max;
    fill_n(back_inserter(left_max), historgam.size(), 0);

    vector<int> right_max;
    fill_n(back_inserter(right_max), historgam.size(), 0);

    left_max[0] = historgam[0];
    for (int i = 1; i < historgam.size(); ++i) {
        left_max[i] = max(left_max[i-1], historgam[i]);
    }

    right_max[right_max.size()-1] = historgam[historgam.size()-1];
    for (int i = historgam.size()-2; i >= 0; --i) {
        right_max[i] = max(right_max[i+1], historgam[i]);
    }

    int result = 0;
    for (int i = 0; i < historgam.size(); ++i) {
        result += min(left_max[i], right_max[i]) - historgam[i];
    }

    cout << "Amount of collected water: " << result << endl;
}