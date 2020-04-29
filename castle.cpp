/*
ID: drayales
TASK: castle
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
string num_to_wall(int i);

int M;
int N;
int arrone[51][51];

int can_move_up(int r, int c);
int can_move_down(int r, int c);
int can_move_left(int r, int c);
int can_move_right(int r, int c);

int main()
{
    ofstream outfile("castle.out");
    ifstream infile("castle.in");
    infile>>M;
    infile>>N;
    cout << M << ' ' << N << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int x;
            infile>>x;
            arrone[i][j] = x;
        }
    }

    //cout << arrone[0][1] << endl;

    for (int i = 0; i < M; i++)
    {
        //cout << arrone[1][1] << " ";
        string n = num_to_wall(arrone[0][i]);
        //cout << "no " << i << ' ' << n << endl;
        
        if (n[2] == '1')
        {
            cout << "####";
        }
        else
        {
            cout << "    ";
        }
        cout << '|';
    }
    cout << endl;

    for (int i = 0; i < M; i++)
    {
        string n = num_to_wall(arrone[0][i]);
        //cout << n << " ";
        if (n[3] == '1')
        {
            cout << "#";
            //cout << "west ";
        }
        else
        {
            cout << " ";
        }
        cout << "  ";
        if (n[1] == '1')
        {
            cout << "#";
            //cout << "east";
        }
        else
        {
            cout << " ";
        }
        cout << '|';
        //cout << endl;
    }
    cout << endl;

    for (int i = 0; i < M; i++)
    {
        //cout << arrone[1][1] << " ";
        string n = num_to_wall(arrone[0][i]);
        //cout << "no " << i << ' ' << n << endl;
        
        if (n[0] == '1')
        {
            cout << "####";
        }
        else
        {
            cout << "    ";
        }
        cout << '|';
    }
    cout << endl;
    
    vector <int> room_sizes;
    int room_track[51][51] = {0};

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (room_track[i][j] == 0)
            {
                string n = num_to_wall(arrone[i][j]);
            }
        }
    }
}

string num_to_wall(int i)
{
    string res ("0000");
    for (int j = 3; j > -1; j--)
    {
        if (i % 2 == 1)
        {
            res[j] = '1';
        }
        i = i/2;
    }
    return res;
}

int can_move_up(int r, int c)
{
    if (r == 0)
    {
        return 0;
    }
    string n = num_to_wall(arrone[r][c]);
    string m = num_to_wall(arrone[r-1][c]);
    if (n[2] == '1' && m[0] == '1')
    {
        return 1;
    }
    return 0;
}

int can_move_down(int r, int c)
{
    if (r == N-1)
    {
        return 0;
    }
    string n = num_to_wall(arrone[r][c]);
    string m = num_to_wall(arrone[r+1][c]);
    if (n[0] == '1' && m[2] == '1')
    {
        return 1;
    }
    return 0;
}

int can_move_left(int r, int c)
{
    if (c == 0)
    {
        return 0;
    }
    string n = num_to_wall(arrone[r][c]);
    string m = num_to_wall(arrone[r][c-1]);
    if (n[3] == '1' && m[1] == '1')
    {
        return 1;
    }
    return 0;
}

int can_move_right(int r, int c)
{
    if (c == M-1)
    {
        return 0;
    }
    string n = num_to_wall(arrone[r][c]);
    string m = num_to_wall(arrone[r][c+1]);
    if (n[1] == '1' && m[3] == '1')
    {
        return 1;
    }
    return 0;
}