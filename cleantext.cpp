#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

using std::istream;
using std::ifstream;
using std::cin;
using std::cerr;
using std::cout;
using std::map;
using std::string;
using std::endl;

void printword(string word) {
    string cleanword = "";
    for(int i=0; i < word.length(); ++i) {
        if (isalpha(word[i])) {
            cleanword += tolower(word[i]);
        }
        if (word[i] == '-') {
            if (cleanword != "") {
                cout << cleanword << endl;
                cleanword = "";
            }
        }
    }

    cout << cleanword << endl;
}

map<string,int> wordsize;

void storeword(string word) {
    if (wordsize.find(word) == wordsize.end()) {
        wordsize[word] = word.length();
    }
}

void nulloutput() {}
void uniqueoutput() {
    for(auto item: wordsize) {
        if (item.second > 0) {
            cout << item.first << endl;
        }
    }
}

int main(int argc, const char *argv[]) {

    if (argc == 1) {
        cerr << "usage: "  << argv[0] << " source.txt" << endl;
        return 1;
    }

    void (*operation)(string) = printword;
    void (*final)() = nulloutput;
    string filename = argv[1];
    if (filename == "--unique") {
        operation = storeword;
        final = uniqueoutput;
        filename = argv[2];
    }

    int depth = 0;
    string word;
    string cleanword;

    ifstream src;

    src.open(filename.c_str());
    while(src) {
        src >>  word;
        
        for(int i=0; i < word.length(); ++i) {
            switch(word[i]) {
                case '[':
                depth++;
                break;
                case ']':
                if (depth > 0) depth--;
                break;
            }
        }
        
        if (depth == 0) {
            operation(word);
        }

    }
    src.close();

    final();

    return 0;
}