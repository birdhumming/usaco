/*
ID: drayales
TASK: milk
LANG: C++
*/

/*
    obj: purchase N units of milk with M different sellers offering options at the cheapest price
        - do not have to buy from all sellers

    in: int N (0-2M), int M (0-5K)
        for next M lines, each line is a farmer:
            P (0-1K): price per unit
            A (0-2M): amount of units
    out: cheapest price while buying N units
*/

#include <iostream>
#include <fstream>
#include <math.h>
#include <cstring>
#include <vector>
#define MAXCOST 1000 //maximum cost of unit

using namespace std;

int main()
{
    int farms[1001] = {}; //each element represents a farmer. i is the price (0-1K), and farms[i] is the amount

    int N, M; //amount, number of farmers
    ifstream input1;
    input1.open("milk.in");
    input1>>N;
    input1>>M;
    for (int i = 0; i < M; i++)
    {
        int price, amount;
        input1 >> price >> amount;
        farms[price] += amount; //bc we output cost, the only thing that matters is cost. can combine units that cost the same.
    }
    input1.close();

    int famount = N; //final amount, subtract each time milk is bought
    int fcost = 0; //final cost, add each time milk is bought
    for (int i = 0; i <= MAXCOST && famount != 0; i++)
    {
        if (farms[i] >= famount) //is the current amount greater than the amount we need
        {                        //should always be able to reach this point bc famount is always being lowered
            fcost += famount * i; //cost = amount * price
            famount = 0; //break condition
        }
        else if (farms[i] < famount) //still contributes, just not pushing over
        {
            fcost += farms[i] * i; //cost = amount * price
            famount -= farms[i]; //decrease amount
        }
    } 
    ofstream outfile("milk.out");
    outfile<<fcost<<"\n";
}
