#include <iostream>
#include <string>
using namespace std;

void search(string& pat, string& txt) {
    int M = pat.size();
    int N = txt.size();
  
    for (int i = 0; i <= N - M; i++) {
        int j;
        
        for (j = 0; j < M; j++) {
            if (txt[i + j] != pat[j]) {
                break;
            }
        }
 
        if (j == M) {
            cout << "Pattern found at index " << i << endl;
        }
    }
}

void computeLPSArray(string& pat, int M, vector<int>& lps)
{
    int len = 0;

    lps[0] = 0;

    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else 
        {
            if (len != 0) {
                len = lps[len - 1];
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> KMPSearch(string& pat, string& txt)
{
    int M = pat.length();
    int N = txt.length();


    vector<int> lps(M);

    vector<int> result;

    computeLPSArray(pat, M, lps);

    int i = 0; 
    int j = 0; 
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            result.push_back(i - j + 1);
            j = lps[j - 1];
        }

        else if (i < N && pat[j] != txt[i]) {

            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return result;
}

int main()
{
    string txt = "geeksforgeeks";
    string pat = "geeks";
    vector<int> result = KMPSearch(pat, txt);

   
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    
    string txt2 = "agd";
    string pat2 = "g";
    search(pat2, txt2);
    return 0;
}
