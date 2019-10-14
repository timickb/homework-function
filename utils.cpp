#include <string>
using namespace std;

void replaceAll(string &s, const string &search, const string &replace) {
    for(size_t pos = 0; ; pos += replace.length()) {
        pos = s.find(search, pos);
        if(pos == string::npos) break;
            s.erase(pos, search.length());
            s.insert(pos, replace);
    }
}