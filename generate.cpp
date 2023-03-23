#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using std::cout;
using std::cerr;
using std::ifstream;
using std::string;
using std::sort;
using std::endl;
using std::vector;

void readfile(vector<string>& list, const char* filename) {
    ifstream in(filename);
    string word;
    while(in) {
        in >> word;
        list.push_back(word);
    }
    in.close();
}

int main(int argc, const char *argv[]) {

    srand(time(0));
    vector<string> selections;
    vector<string> text;
    readfile(text, "text.txt");
    int textwords = rand() % 3 + 3;
    int textstart = rand() % text.size();  

    bool solvable = (rand() % 10 < 5);
    for(int i=textstart; i < textstart + textwords; ++i) {
        if (solvable) selections.push_back(text[i]);
        cout << text[i];
    }
    cout << endl;

    vector<string> dictionary;
    readfile(dictionary, "words.txt");

    int numwords = rand() % (200 - textwords) + textwords;
    for(int i=0; i < numwords; ++i) {
        selections.push_back(dictionary[rand() % dictionary.size()]);
    }
    sort(selections.begin(), selections.end());

    for(auto w: selections) {
        cout << w << endl;
    }

    return 0;
}