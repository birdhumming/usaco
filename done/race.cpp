/*
problem: Bessie is running a race. she starts running at a speed of 0 meters/second. 
    in a given second, she can either increase her speed by 1 or decrease her speed by 1. speed will never be < 0.
    Bessie also wants to reach the finish line while running at or below a specific speed X. 
    she wants to know what the minimum time she needs to run to complete the race and end at speed X.
given: 
    int K = distance of race (1-1,000,000,000)
    int N = numbers of different values of X (1-1000)
    N values of X (1-100,000)
do: for each value of X, find the minimum time Bessie needs to run to cover K meters and reach meter K at speed X
note: to achieve minimum time, Bessie should continuously increase her time by 1 to some "peak" value.
    from there, she should start slowing down to get to X.
*/

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
        fout << run(K, speeds[i]) << endl;
    }
    
}

int run(int dist, int stop_speed)
{
    int faster_distance = 0; //distance she covers while speeding up
    int slower_distance = 0; //distance she covers while slowing down
    int time = 0;

    int marker = 0;
    int current_speed = 1;

    while (marker == 0)
    {
        faster_distance += current_speed;
        time++;
        if (faster_distance + slower_distance >= dist) //current speed is peak speed
        {
            return time; 
        }
        if (current_speed >= stop_speed) //speed too great, slow down
        {
            slower_distance += current_speed; //still covering distance while slowing down
            time++;
            if (faster_distance + slower_distance >= dist)
            {
                return time;
            }
        }
        current_speed++; //increase peak speed
    }
}