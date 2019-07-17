#include<bits/stdc++.h>
using namespace std;

int main() {
    string text, pat;
    cin >> text >> pat;
    
    int n = text.size(), m = pat.size();

    int lps[m], i = 1, l = 0;
    lps[0] = 0;

    while (i < m) {
        if (pat[l] == pat[i]) {
            l++;
            lps[i] = l;
            i++;
        }
        else {
            if (l) l = lps[l - 1];
            else lps[i] = 0, i++;
        }
    }

    int j = 0; i = 0;

    while (i < n) {
        if (text[i] == pat[j]) i++, j++;
        if (j == m) break;
        else if (i < n && text[i] != pat[j]) {
            if (j) j = lps[j - 1];
            else i++;
        }
    }

    cout << i - j;
    
    return 0;
}
