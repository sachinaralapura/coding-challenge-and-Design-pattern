#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int pickingNumbers(vector<int> arr);
int main(int argc, char const* argv[]) {
    int lenght;
    vector<int> arr;
    cout << "enter the lenght of arr" << endl;
    cin >> lenght;

    cout << "enter the array" << endl;
    for (int i = 0; i < lenght; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    int max = pickingNumbers(arr);
    cout << max << endl;
}


int pickingNumbers(vector<int> arr) {
    int length = arr.size();
    int maxLength = 0;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < length; i++) {
        int right = 0;

        while (abs(arr[i] - arr[i + right]) <= 1) {
            right++;
            if (right + i  >= length) break;
        }
        if (right > maxLength) maxLength = right;
    }
    return maxLength;
}
