/*
problem: Bessie the cow has terrible handwriting, as is to be expected from a cow.
    her typed essay must be formatted according to the following rules:
    1. each line should contain up to K characters, not including spaces
    2. if Bessie types a word and it can fit on the current line, put it on that line
    3. if the word can't fit, start a new line and put it at the beginning
    4. there should not be a space at the end of the line
given:
    int N = the number of words (1-100)
    - each word is 1-15 characters long
    int K = the restriction on line length
    one line containing N words, separated by spaces
do: print Bessie's essay, correctly formatted
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int N, K;
vector < vector <string> > essay;
//each vector of strings represents a line of words

int main()
{
    ifstream fin ("word.in");
    ofstream fout ("word.out");

    int char_count = 0; //counts the characters in the line

    fin >> N >> K;
    //cout << K << endl;

    vector <string> line;

    for (int i = 0; i < N; i++)
    {
        string word;
        fin >> word;

        char_count += word.size(); //add on the word
        //cout << word << " " << word.size() << endl;

        if (char_count > K) //word cannot fit
        {
            essay.push_back(line); //record current line
            line.clear(); //end current line
            line.push_back(word); //start new line
            char_count = word.size();
        }
        else if (char_count <= K) //word can fit
        {
            line.push_back(word); //add word to line
        }
    }

    essay.push_back(line); //add final line

    for (int i = 0; i < essay.size(); i++)
    {
        for (int j = 0; j < essay[i].size(); j++)
        {
            if (j == essay[i].size() - 1) //last word in line
            {
                fout << essay[i][j]; //no space
            }
            else
            {
                fout << essay[i][j] << " ";
            }
        }
        fout << endl;
    }
}