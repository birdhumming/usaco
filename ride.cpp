/*
ID: drayale1
TASK: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int string_calc(string str);



int main()
{
    ofstream outfile ("ride.out");
    ifstream infile ("ride.in");
    string comet;
    string group;
    infile >> comet >> group;
    int comet_num = string_calc(comet);
    int group_num = string_calc(group);
    if (comet_num % 47 == group_num % 47)
    {
        outfile << "GO"<<endl;
        return 0;
    }
    else
    {
        outfile << "STAY"<<endl;
        return 0;
    }


}

int string_calc(string str)
{
    int final = 1;
    int i = 0;
    while (str[i] != '\0')
    {
        char c = str[i];
        final = final * ((int)c - 64);
        i++;
    }
    return final;
}
