#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::sort;


int main(int argc, const char *argv[]) {
    string slug;
    string word;
    vector<string> dictionary;

    cin >> slug;
    while(cin) {
        cin >> word;
        dictionary.push_back(word);
    }

    struct {
        bool operator()(string a, string b) const { return a.length() > b.length(); }
    }
    sortByLength;

    sort(dictionary.begin(), dictionary.end(), sortByLength);

    int idx=0;
    bool found;
    while(idx < slug.length()) {
        string current = slug.substr(idx);
        found = false;
        for(auto candidate: dictionary) {
            if (current.substr(0, candidate.length()) == candidate) {
                idx += candidate.length();
                found = true;
                break;
            }
        }
        if (found == false) {
            cout << "false" << endl;
            return 0;
        }
    }
    cout << "true" << endl;
    return 0;
}