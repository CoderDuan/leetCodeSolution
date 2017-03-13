#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int hasX(string s) {
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[len-1 - i] == 'X')
            return i;
    }
    return 999;
}

int f(string s1, string s2, int sum) {
    int x1 = hasX(s1);
    int x2 = hasX(s2);
    int ret = 0;
    if (x1 == 999 && x2 == 999) {
        if ((atoi(s1.c_str()) + atoi(s2.c_str())) == sum)
            return 1;
        else
            return 0;
    }
    if (x1 < x2) {
        int len1 = s1.length();
        int len2 = s2.length();
        string sub1 = s1.substr(len1-1 - x1);
        string sub2 = s2.substr(len2-1 - x1);
        string sumstr = to_string(sum);
        string subsum = sumstr.substr(sumstr.length()-1-x1);
        int i = 0;
        if (x1 == (len1-1)) i = 1;
        for (; i < 10; i++) {
            s1[len1-1 - x1] = '0' + i;
            sub1[0] = '0' + i;
            if (((atoi(sub1.c_str()) + atoi(sub2.c_str()))
                == atoi(subsum.c_str()))
                || ((atoi(sub1.c_str()) + atoi(sub2.c_str()))
                == (atoi(("1"+subsum).c_str())))) {
                ret += f(s1, s2, sum); 
            }
        }
    } else if (x1 > x2) {
        int len1 = s1.length();
        int len2 = s2.length();
        string sub1 = s1.substr(len1-1 - x2);
        string sub2 = s2.substr(len2-1 - x2);
        string sumstr = to_string(sum);
        string subsum = sumstr.substr(sumstr.length()-1-x2);
        int i = 0;
        if (x2 == (len2-1)) i = 1;
        for (; i < 10; i++) {
            s2[len1-1 - x2] = '0' + i;
            sub2[0] = '0' + i;
            if (((atoi(sub1.c_str()) + atoi(sub2.c_str()))
                == atoi(subsum.c_str()))
                || ((atoi(sub1.c_str()) + atoi(sub2.c_str()))
                == (atoi(("1"+subsum).c_str())))) {
                ret += f(s1, s2, sum); 
            }
        }
    } else if (x1 == x2) {
        int i = 0;
        if (x1 == (s1.length()-1)) i = 1;
        for (; i < 10; i++) {
            s1[s1.length()-1-x1] = '0' + i;
            ret += f(s1, s2, sum);
        }
    }
    return ret;
}

int main(){
    int n;
    cin>>n;
    while(n) {
        string s1, s2;
        int sum;
        cin>>s1>>s2>>sum;
        cout<<f(s1, s2, sum)<<endl;
        n--;
    }

    return 0;
}