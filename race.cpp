#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int N, K;
vector <int> speeds;

int run(int dist, int stop_speed);

int main()
{
    ifstream fin ("race.in");
    ofstream fout ("race.out");

    fin >> K >> N;
    int temp;
    for (int i = 0; i < N; i++)
    {
        fin >> temp;
        speeds.push_back(temp);
    }

    for (int i = 0; i < N; i++)
    {
        fout << run(K, speeds[i]) << endl;;
    }
    
}

int run(int dist, int stop_speed)
{
    int faster_distance = 0;
    int slower_distance = 0;
    int time = 0;

    int marker = 0;
    int current_speed = 1;

    while (marker == 0)
    {
        faster_distance += current_speed;
        time++;
        if (faster_distance + slower_distance >= dist)
        {
            return time;
        }
        if (current_speed >= stop_speed)
        {
            slower_distance += current_speed;
            time++;
            if (faster_distance + slower_distance >= dist)
            {
                return time;
            }
        }
        current_speed++;
    }
}