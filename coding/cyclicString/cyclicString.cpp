#include <iostream>
#include <string>
#include "cyclicString.h"



int main() {
    string input;
    int k;

    cout << "Enter a string: ";
    cin >> input;
    cout << "Enter k: ";
    cin >> k;

    string src = input;
    int i = 0;
    while (true) {
        StringCyclic* sc = new StringCyclic(src);
        src = sc->cyclicSlice(k);
        cout << ++i << " " << src << endl;
        if (src == input) {
            cout << "Found";
            break;
        }
    }
}

