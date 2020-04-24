#include <algorithm>
#include <iostream>
#include <random>
#include <string>
using namespace std;

string flip(string flip) {
    reverse(flip.begin(), flip.end());
    return flip;
}

string scramble(string scram) {
    random_shuffle(scram.begin(), scram.end());
    return scram;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    if (input.empty()) {
        cout << "Please enter a string" << endl;
    } else {
    	cout << "Reversed string: " << flip(input) << endl;
        cout << "Shuffled string: " << scramble(input) << endl;
        cout << "All functions: " << scramble(flip(input)) << endl;
    }
}
