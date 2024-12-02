#include <bits/stdc++.h>
using namespace std;
int search(string seq1, char c)
{
    for (int i = 0; i < seq1.length(); i++)
    {
        if (seq1[i] == c)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    char Dir;
    cin >> Dir;
    string sequence;
    cin >> sequence;

    string seq1 = "qwertyuiop";
    string seq2 = "asdfghjkl;";
    string seq3 = "zxcvbnm,./";
    int result;
    for (int i = 0; i < sequence.size(); i++)
    {
        if (Dir == 'R')
        {
            result = search(seq1, sequence[i]);
            if (result != -1)
            {
                cout << seq1[result - 1];
            }
            result = search(seq2, sequence[i]);
            if (result != -1)
            {
                cout << seq2[result - 1];
            }
            result = search(seq3, sequence[i]);
            if (result != -1)
            {
                cout << seq3[result - 1];
            }
        }

        else if (Dir == 'L')
        {
            result = search(seq1, sequence[i]);
            if (result != -1)
            {
                cout << seq1[result + 1];
            }
            result = search(seq2, sequence[i]);
            if (result != -1)
            {
                cout << seq2[result + 1];
            }
            result = search(seq3, sequence[i]);
            if (result != -1)
            {
                cout << seq3[result + 1];
            }
        }
    }

    return 0;
}
