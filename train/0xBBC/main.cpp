#include <cmath>
#include <iostream>
#include <string>
#include <list>

using namespace std;

list<char> last_word(string word) {
    list<char> list;
    char head = '\0';
    head = word.at(0);
    list.push_front(head);
    for (size_t i = 1; i < word.length(); i++) {
        char letter = word.at(i);
        if (letter >= head) {
            head = letter;
            list.push_front(letter);
        } else {
            list.push_back(letter);
        }
    }
    return list;
}

int main(int argc, const char * argv[]) {
    size_t total, current = 0;
    string word;
    cin >> total;
    while ((current++) != total) {
        cin >> word;
        list<char> result = last_word(word);
        cout << "Case #"<<current<<": ";
        for (auto iter : result) {
            cout<<iter;
        }
        cout<<'\n';
    }
    return 0;
}
