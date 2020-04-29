#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector <pair <int, int> > cows;
vector <int> healthy_cows;


int main()
{
    ifstream fin("socdist2.in");
    ofstream fout("socdist2.out");

    fin >> N;
    for (int i = 0; i < N; i++)
    {
        int cow, is_sick;
        pair <int, int> temp;
        fin >> cow >> is_sick;
        temp.first = cow, temp.second = is_sick;
        cows.push_back(temp);

        if (is_sick == 0)
        {
            healthy_cows.push_back(cow);
        }
    }

    if (healthy_cows.size() == 0)
    {
        fout << 1 << endl;
    }
    else
    {
        vector <int> Rs;
        
        sort(cows.begin(), cows.end());

        for (int i = 0; i < healthy_cows.size(); i++)
        {
            int x = healthy_cows[i];
            int left_infected = -1;
            int right_infected = -1;
            for (int j = 0; j < N; j++)
            {
                if (cows[j].second == 1 && cows[j].first < x)
                {
                    left_infected = cows[j].first;
                }
                if (cows[j].first > x && cows[j].second == 1)
                {
                    right_infected = cows[j].first;
                    break;
                }
            }
            if (left_infected == -1 || right_infected == -1)
            {
                if (left_infected == -1)
                {
                    Rs.push_back(right_infected - x);
                }
                if (right_infected == -1)
                {
                    Rs.push_back(x - left_infected);
                }
            }
            else
            {
                Rs.push_back(min(x - left_infected, right_infected - x));
            }
        }
        
        sort(Rs.begin(), Rs.end());
        int R = Rs[0] - 1;

        
    }
}