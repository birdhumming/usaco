/*
problem: Farmer John, being the sadistic agricultural enthusiast he is, is making his cows exercise
    they must repeat the following two steps K times:
    1. all cows from A1 to A2 must reverse their order
    2. all cows from B1 to B2 must reverse their order
    we start with an array of N cows {1, 2, 3, ... , N}
given:
    int N = number of cows (1-100)
    int K = number of times exercise is done (1-1,000,000,000)
    A1, A2 = the segment that will be reversed
    B1, B2 = the other segment
do: print out the resulting order of cows after exercising K times
note: K can be very large. after a certain number of reversals, though, the order of the cows will
    eventually go back to {1, 2, 3, ... , N}. so if we can just find that number, we can take the mod
    and only reverse that many times. 
*/

#include <iostream> 
#include <fstream>
#include <vector>

using namespace std;

int N, K;
int firstA, secondA;
int firstB, secondB;

vector <int> cows;

void cow_swap(int a, int b);
int modK();
int isgood(vector <int> x);

int main()
{
    ifstream fin ("swap.in");
    ofstream fout ("swap.out");

    fin >> N >> K;
    fin >> firstA >> secondA;
    fin >> firstB >> secondB;

    firstA -= 1;
    secondA -= 1;
    firstB -= 1;
    secondB -= 1;

    //cout << "N = " << N << endl;
    //cout << "K = " << K << endl;
    //cout << "A1 = " << firstA << endl;
    //cout << "A2 = " << secondA << endl;
    //cout << "B1 = " << firstB << endl;
    //cout << "B2 = " << secondB << endl;

    for (int i = 1; i < N+1; i++)
    {
        cows.push_back(i);
    }

    /*for (int i = 0; i < N; i++)
    {
        cout << cows[i] << " ";
    }
    cout << endl;*/

    if (secondA < firstB) //there is no overlap between the reverse segments
    {
        if (K % 2 == 0) //reverse then reverse makes it the same
        {
            //cout << "staying the same" << endl;
            for (int i = 0; i < N; i++)
            {
                fout << cows[i] << endl;
            }
            return 0;
        }
        else 
        {
            //cout << "switching once" << endl;

            cow_swap(firstA, secondA); 
            cow_swap(firstB, secondB);

            //cout << cows.size() << endl;

            for (int i = 0; i < N; i++)
            {
                fout << cows[i] << endl;
            }
            return 0;
        }
    }

    int x = K % modK(); 
    //cout << x << endl;

    for (int i = 0; i < x; i++)
    {
        cow_swap(firstA, secondA);
        cow_swap(firstB, secondB);
    }

    for (int i = 0; i < N; i++)
    {
        fout << cows[i] << endl;
    }
}

int modK()
{
    int count = 1;

    cow_swap(firstA, secondA);
    cow_swap(firstB, secondB);

    while (!isgood(cows)) //while cows is not how it was originally
    {
        cow_swap(firstA, secondA);
        cow_swap(firstB, secondB);
        count++;
    }

    return count;
    //count is the number of times the cows do their exercise before they cycle back to their original order
}

void cow_swap(int a, int b)
{
    int x = a + b;

    vector <int> cows_copy;
    for (int i = 0; i < N; i++)
    { 
        cows_copy.push_back(cows[i]);
    }

    for (int i = a; i < b+1; i++)
    {
        cows_copy[x-i] = cows[i]; //reverses
        //cout << i << " to " << x-i << endl;
    }

    for (int i = 0; i < N; i++)
    {
        cows[i] = cows_copy[i];
    }
}

int isgood(vector <int> x) //is cows in 1, 2, 3 order yet
{
    for (int i = 0; i < N; i++)
    {
        if (x[i] != i+1)
        {
            return 0;
        }
    }
    return 1;
}
