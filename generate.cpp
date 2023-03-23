#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using std::cout;
using std::ifstream;
using std::string;
using std::endl;
using std::vector;

int main(int argc, const char *argv[]) {

    srand(time(0));
    ifstream text("text.txt");

    int textwords = rand() % 3 + 3;
    int textstart = rand() % 122580;  
    string tword;

    for(int i=0; i < textstart; ++i) {
        text >> tword;
    }

    for(int i=0; i < textwords; ++i) {
        text >> tword;
        cout << tword;
    }
    text.close();
    cout << endl;
    
    ifstream words("words.txt");
    vector<string> dictionary;
    while(words) {
        words >> tword;
        dictionary.push_back(tword);
    }
    words.close();

    int numwords = rand() % 194 + 6;
    for(int i=0; i < numwords; ++i) {
        cout << dictionary[rand() % dictionary.size()] << endl;
    }

    return 0;
}