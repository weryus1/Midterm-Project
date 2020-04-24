#include <algorithm>
#include <iostream>
#include <random>
#include <string>
using namespace std;

void flip(string flipIn) {
    string flip(flipIn);

    reverse(flip.begin(), flip.end());
    cout << "Reversed string: " << flip << endl;
}

void scramble() {
    string scram = flip;

    random_shuffle(scram.begin(), scram.end());
    cout << "Shuffled string: " << scram << endl;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    if (input.empty()) {
        cout << "Please enter a string" << endl;
    } else {
        flip(input);
        scramble();
    }
}