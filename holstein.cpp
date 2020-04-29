/*
ID: drayales
TASK: holstein
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int V;
vector<int> vits (V);
int G;
vector < vector < int > > amounts(G, vector<int> (V, 0));

void combo(int block, int k);
vector<int> G_int;


vector < vector < int > > binary(32768, vector<int> (G+1, 0));
int bin_count = 0;
vector<int> c;

int main()
{
    ifstream infile("holstein.in");
    infile>>V;
    int temp;
    for (int i = 0; i < V; i++)
    {
        infile>>temp;
        vits.push_back(temp);
    }
    infile>>G;
    for (int i = 0; i < G; i++)
    {
        vector <int> row;
        for (int j = 0; j < V; j++)
        {
            infile>>temp;
            row.push_back(temp);
        }
        amounts.push_back(row);
    }
    for (int i = 0; i < G; i++)
    {
        G_int.push_back(i+1);
    }
    cout << "basic setup" << endl;
    for (int i = 1; i < G + 1; i++)
    {
        //cout << "length = " << i << endl;
        combo(0, i);
    }
    cout << "combo" << endl;

    for (int i = 1; i < V; i++)
    {
        for (int j = 0; j < bin_count; j++)
        {
            //cout << '(' << j << ',' << 0 << ')';
            if (binary[j][0] == 1)
            {
                //cout << "65" << endl;
                int sum = 0;
                for (int k = 1; k < G+1; k++)
                {
                    if (binary[j][k] == 1)
                    {
                        int vit = amounts[k-1][i];
                        //stop subtracting 1, might need to shift 
                        sum += vit;
                    }
                    else
                    {
                        binary[j][k] = 0;
                    }
                    cout<<sum<<endl;
                }
                if (sum < vits[i])
                {
                    //cout << "vitamin no. " << i + 1 << endl;
                    //cout << "we want " << vits[i] << endl;
                    //cout << "we have " << sum << endl;
                    //cout << "combo no. " << j << endl;
                    binary[j][0] = 0;
                }
                else
                {
                    binary[j][0] = 1;
                }
            }
        }
    }
    cout << "sum" << endl;

    /*for (int i = 0; i < bin_count; i++)
    {
        for (int j = 0; j < G+1; j++)
        {
            //cout << '(' << i << ',' << j << ')' << " ";
            cout << binary[i][j] << ' ';
        }
        cout << endl;
    }*/
    
    ofstream outfile("holstein.out");
    int x = 1;
    int i = 0;
    while (x == 1)
    {
        if (binary[i][0] == 1)
        {
            int count = 0;
            cout << "116" << endl;
            for (int j = 1; j < G+1; j++)
            {
                if (binary[i][j] == 1)
                {
                    count++;
                }
                else
                {
                    binary[i][j] = 0;
                }
            }
            outfile<<count;
            cout << "128" << endl;
            for (int j = 1; j < G+1; j++)
            {
                cout << "what even " << j << endl;
                if (binary[i][j] == 1)
                {
                    outfile<<" "<<j;
                }
            }
            outfile<<endl;
            cout << "got here" << endl;
            x = 0;
        }
        i++;
    }

} 

void combo(int block, int k)
{
    if (k == 0) 
    {
        /*for (int i = 0; i < c.size(); i++)
        {
            cout << c[i] << " ";
        }
        cout << endl;
        return;*/

        int sum = 0;
        for (int i = 0; i < c.size(); i++)
        {
            int n = c[i] - 1;
            int vitone = amounts[n][0];
            sum += vitone;
        }
        if (sum >= vits[0])
        {
            binary[bin_count][0] = 1;
            for (int i = 0; i < c.size(); i++)
            {
                int n = c[i];
                binary[bin_count][n] = 1;
            }
            //cout << sum << endl;
            //cout << bin_count << endl;
            bin_count++;
        }
        return;
    }
    for (int i = block; i < G - k + 1; i++)
    {
        c.push_back(G_int[i]);
        combo(i+1, k-1);
        c.pop_back();
    }
}
