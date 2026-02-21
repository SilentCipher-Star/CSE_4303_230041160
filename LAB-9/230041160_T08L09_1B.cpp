#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

bool matching(string word, string abbre)
{
    int wordptr = 0;
    int abbreptr = 0;

    while (wordptr < word.length() && abbreptr < abbre.length())
    {
        if (word[wordptr] == abbre[abbreptr])
        {
            abbreptr++;
            wordptr++;
        }
        else if (isupper(word[wordptr]))
        {
            return false;
        }
        else
        {
            wordptr++;
        }
    }

    if (abbreptr < abbre.length())  //to check whether even after the loop, the abbrev is completed or not
    {
        return false;
    }

    while (wordptr < word.length())
    {
        if (isupper(word[wordptr]))
        {
            return false;
        }
        wordptr++;  // allowed to have extra words leftover, if they r lowercase other wise return false
    }
    return true;
}
int main()
{

    vector<string> words;
    string input;

    while (cin >> input && input != "-1")
    {
        words.push_back(input);
    }

    string abbreviation;
    cin >> abbreviation;

    for (const string &s : words)
    {
        if (matching(s, abbreviation))
        {
            cout << "T" << " ";
        }
        else
        {
            cout << "F" << " ";
        }
    }
    cout << endl;
    return 0;
}