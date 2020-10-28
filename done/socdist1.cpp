/*
given: 
    N = number of stalls
    string of 1s and 0s N characters long - 1 means there is a cow, 0 means there isn't
do: find the maximum possible value of D when adding two cows
    D is the distance between the two closest stalls 
    basically, find the maximum of the minimum distances apart (social distancing!)
    ex: N = 14, "10001001000010"
    adding two cows => 10X010010X0010 where X are the new cows
    the minimum distance between any two stalls is 2. there is no way to increase this number by re-placing the Xs
    D = 2
note: if 0s start at beginning or end of string (000001...), then cow will just be placed at very beginning
    same with end of string. in a normal gap (1000001) (hey look it's a 101 sandwich. do you even remember that?)
    gap has length 6. when trying to insert a cow, we would divide it by 2 and it'd be split into two length 3s.
    when starting at the beginning, though, we don't have to. 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
string stalls;

int main()
{
    ifstream infile ("socdist1.in");
    ofstream outfile ("socdist1.out");

    infile >> N >> stalls;

    vector <int> cow_index; //stores the indices of stalls with cows
    vector <int> dist; //stores the distances between stalls with cows

    for (int i = 0; i < N; i++)
    {
        if (stalls[i] == '1') //stall has cow
        {
            cow_index.push_back(i); //set up cow_index
        }
    }

    if (cow_index.size() == 0) //there are no 1s in the entire string, which means there are no cows
    {
        //the two cows will be placed on the very end stalls
        outfile << N-1 << endl;
    }
    else if (cow_index.size() == 1) //there is only one cow
    {
        vector <int> ans;
        int beg_dist = cow_index[0] - 0; 
        int end_dist = N-1 - cow_index[0];
        //both on left
        ans.push_back(beg_dist/2); //one cow goes on end and one cow goes in middle of [0 - cow_index[0]]
        //one on left, one on right
        ans.push_back(min(beg_dist, end_dist)); 
        //both on right
        ans.push_back(end_dist/2);

        //cout << "beginning distance: " << beg_dist << endl;
        //cout << "ending distance: " << end_dist << endl;

        /*for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << endl;
        }*/

        sort(ans.begin(), ans.end()); 
        outfile << ans[ans.size()-1] << endl;

    }
    else
    {
        //int distance = i[0] - 0;
        //dist.push_back(distance);
        for (int i = 0; i < cow_index.size() - 1; i++) 
        {
            int distance = cow_index[i+1] - cow_index[i]; //calculate distances between cow-positive stalls
            dist.push_back(distance);
            //cout << distance << '(' << i << ',' << i+1 << ')' << endl;
        }
        sort(dist.begin(), dist.end()); 
        int max_length_fm = dist[dist.size()-1]; //largest
        int smax_length_fm = dist[dist.size()-2]; //second largest
        int min_length_fm = dist[0]; //smallest
        int beg_dist = cow_index[0] - 0; //distance from beginning (is zero if nonexistent)
        int end_dist = N-1 - cow_index[cow_index.size()-1]; //distance from ending (is zero if nonexistent)

        //cout << "distance from beginning: " << beg_dist << endl;
        //cout << "distance from ending: " << end_dist << endl;
        //cout << "max length in middle: " << max_length_fm << endl;
        //cout << "second max length in middle: " << smax_length_fm << endl;
        //cout << "minimum length in middle: " << min_length_fm << endl;

        vector <int> ans;
        //both at beginning
        ans.push_back(min(beg_dist/2, min_length_fm));
        //one at beginning, one at end
        ans.push_back(min(beg_dist, min(end_dist, min_length_fm)));
        //both at end
        ans.push_back(min(end_dist/2, min_length_fm));
        //one at end, one in middle somewhere
        ans.push_back(min(end_dist, min(max_length_fm/2, min_length_fm)));
        //both in middle somewhere in same length
        ans.push_back(min(max_length_fm/3, min_length_fm));
        //both in middle somewhere in different lengths
        ans.push_back(min(max_length_fm/2, min(smax_length_fm/2, min_length_fm)));
        //one in middle, one in end
        ans.push_back(min(end_dist, min(max_length_fm/2, min_length_fm)));

        /*for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << endl;
        }*/
        sort(ans.begin(), ans.end());
        outfile << ans[ans.size()-1] << endl;

    }
}