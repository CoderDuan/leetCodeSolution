#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int str_len = s.length();
    if (str_len == 0) return 0;
    int start_ptr;
    string curr_str;
    int substr_len = 1;
    int maxlen = 0;
    for (start_ptr = 0; start_ptr + substr_len < str_len; start_ptr ++) {
        curr_str = s[start_ptr];
        for (; start_ptr + substr_len < str_len;) {
            char next_char = s[start_ptr + substr_len];
            cout<<"curr_str:"<<curr_str<<'\t'<<"next_char:"<<next_char<<endl;
            if (curr_str.find(next_char) == -1) {
                curr_str += next_char;
                substr_len ++;
                if (substr_len > maxlen) maxlen = substr_len;
            } else break;
        }
        substr_len = 1;
    }
    return maxlen;
}

int main() {
	string input;
    while (true) {
        cin>>input;
        if (input == "q") break;
        cout<<lengthOfLongestSubstring(input)<<endl;
    }
    return 0;
}