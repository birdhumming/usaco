/*
given:
    int N cows
    for each cow: position, infected (1)/healthy (0)
do:
    there is a certain radius R such that any cow standing ≤ R units away from an infected cow will be infected.
    infected cows will then pass on the infection to any cows within R units. we don't know R.
    find the minimum possible number of cows that were initially infected.
note:
    FIRST! the only cows that exist are the ones we are given. there aren't a bunch of cows standing in a line one unit apart. 
    ex: (cow) (17 spaces) (cow) (2 spaces) (cow)
    2. realize that the only constraints we have on R are the positions of the uninfected cows. 
    because they are uninfected, the distance between them and the closest infected cows must be greater than R.
    3. for min number of starting cases, we want R to be as large as possible.
    4. combining 2 and 3: R must be small enough to ensure the uninfected cows but as large as possible
    R is the smallest distance between any uninfected cow and its adjacent infected cows. 
    5. also realize: for any number of infected cows in a row that are all less than R apart, the number of initial infections is 1.
    one cow infects another, and it is passed throughout the entire group. this is true no matter how big the group is.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

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

    if (healthy_cows.size() == 0) //all cows are infected
    {
        fout << 1 << endl;
    }
    else
    {
        vector <int> Rs; //potential lengths of R
        
        sort(cows.begin(), cows.end()); //line the cows up

        for (int i = 0; i < healthy_cows.size(); i++)
        {
            int x = healthy_cows[i]; //position of a healthy cow
            int left_infected = -1; //position of the closest infected cow to the left of cow x
            int right_infected = -1; //position of the closest infected cow to the right of cow x
            for (int j = 0; j < N; j++)
            {
                if (cows[j].second == 1 && cows[j].first < x) //infected and to the left of x
                {
                    left_infected = cows[j].first; //will eventually find the largest
                }
                if (cows[j].first > x && cows[j].second == 1) //infected and to the right of x
                {
                    right_infected = cows[j].first;
                    break; //want smallest, break right after finding
                }
            }
            if (left_infected == -1 || right_infected == -1)
            {
                if (left_infected == -1) //no infected cows to left
                {
                    Rs.push_back(right_infected - x); 
                }
                if (right_infected == -1) //no infected cows to right
                {
                    Rs.push_back(x - left_infected);
                }
            }
            else
            {
                Rs.push_back(min(x - left_infected, right_infected - x)); //we want the smallest distance
                //anything larger than the smallest distance will mean at least one uninfected cow will (should've been) infected
            }
        }
        
        sort(Rs.begin(), Rs.end());
        int R = Rs[0] - 1; //smallest

        //cout << "R = " << R << endl;

        int marker = 0;
        vector <int> groups;

        for (int i = 0; i < N; i++)
        {
            if (cows[i].second == 1 && marker == 0) //form group
            {
                marker = 1;
                //cout << "starting here: " << cows[i].first << endl;
            }
            else if (cows[i].second == 1 && marker != 0 && cows[i].first - cows[i-1].first <= R) //form group
            {
                marker++;
                //cout << "continuing here: " << cows[i].first << endl;
            }
            else if (cows[i].second == 1 && marker != 0 && cows[i].first - cows[i-1].first > R) //end group/start group
            {
                //"length: " << marker << endl;
                //cout << "ending here because this cow is too far away: " << cows[i].first << endl;
                groups.push_back(marker);
                marker = 1; //counts as a starting point as well
            }
            else if (cows[i].second == 0) //end group
            {
                //cout << " length: " << marker << endl;
                //cout << "ending here because this cow is healthy: " << cows[i].first << endl;
                groups.push_back(marker);
                marker = 0;
            }
        }
        if (marker != 0)
        {
            groups.push_back(marker);
            //cout << "length: " << marker << endl;
        }

        int ans = 0;
        for (int i = 0; i < groups.size(); i++)
        {
            int size = groups[i];
            if (size > 0) //for each group, there is one cow that was initially infected
            {
                ans++;
            }
            /*if (size == 1 || size == 2)
            {
                ans++;
            }
            if (size > 2)
            {
                //int x = ceil((float)size/3); //adding feet to the snake
                //did this under the assumption that the maximum number of other sheep an infected sheep could infect was two
                //one to the right, one to the left. see 5 at beginning
                
                //ans += x;
            }*/
        }
        //cout << ans << endl;
        fout << ans << endl;
    }
}
