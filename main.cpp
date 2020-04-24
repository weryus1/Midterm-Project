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

string everyOtherCaps(string eostring) {
	bool capitalize = false;
	for(unsigned int i = 0; i < eostring.length(); i++) {
		if(capitalize) {
			eostring[i] = toupper(eostring[i]);
		} else {
			eostring[i] = tolower(eostring[i]);
		}
		capitalize = !capitalize;
	}
	return eostring;
}

string vowelRemover(string devowel) {
	char vowels[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
	for(unsigned int i = 0; i < devowel.length(); i++) {
		for(int v = 0; v < 6; v++) {
			if(tolower(devowel[i]) == vowels[v]) {
				devowel.erase(i, 1);
				i--;
			}
		}
	}
	return devowel;
}

int main(int argc, char *argv[]) {
	while(true) {
		string input;
		cout << "Enter a string or #stop to end program: ";
		getline(cin, input);

		if (input.empty()) {
			cout << "Please enter a string" << endl;
		} else {
			if(input == "#stop") {
				cout << "Program stopping!" << endl;
				break;
			} else {
				cout << "Reversed string: " << flip(input) << endl;
				cout << "Shuffled string: " << scramble(input) << endl;
				cout << "Every Other Capitalized string: " << everyOtherCaps(input) << endl;
				cout << "Vowel Remover string: " << vowelRemover(input) << endl;
				if(argc > 1) {
					if(tolower(argv[1][0]) == 'a') {
						cout << "All Functions string: " << vowelRemover(everyOtherCaps(scramble(flip(input)))) << endl;
					}
				}
				cout << endl;
			}
		}
	}
	return 0;
}
