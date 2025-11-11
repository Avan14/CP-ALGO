#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string text, pattern;
    cin >> text >> pattern;
    int n = text.size();
    int m = pattern.size();
    vector<int> lps(m, 0);
    // Preprocess the pattern to create the LPS array
    // Standard KMP LPS preprocessing
    lps[0] = 0;
    int len = 0;
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    while( i < m)
     i= 0 ;
     int j = 0;
     while( i < text.size()){
        if(pattern[j] == text[i]){
            j++;
            i++;
            if(j==m){
                cout<<"found " <<i - m<<"\n";
            }
        }
        else if(  j == 0 ){
            i++;
        }
        else {
            j = lps[j-1];
        }
     }
    

  

    return 0;
}