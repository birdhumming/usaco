/*
ID: drayales
TASK: skidesign
LANG: C++
*/

/*
    in: int N (1-1000) number of ski hills
        for next N lines:
            height of hill (1-100)

    out: lowest price that Farmer John needs to pay

    description: largest difference between hill heights must be 17 or less. price to 
    adjust hill height is difference^2. 
    ex: if hill is lowered from 9 to 6, price is 9 (3^2 = 9)
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#define MAX_DIFF 17 //max difference in heights of ski hills

using namespace std;

int main(void)
{
    int N; //number of hills
    int * heights; //heights of hills
    
    ifstream input1;
    input1.open("skidesign.in");
    
    input1>>N; 
    heights = new int [N];

    for (int i = 0; i < N; i++)
    {
        input1>>heights[i];
    }
    input1.close();

    sort(heights, heights + N);

    int temp_low;
    int temp_high;
    int min_cost = 30000000; //checking for min, set first as high as possible

    for (int i = 0; i < 84; i++) //move range of 17 up by 1 each time
    // [0-17], [1-18] ... [83, 100]
    {
        int cost = 0; 
        temp_low = i; 
        temp_high = i + 17;

        for (int i = 0; i < N; i++) //loop through each height
        {
            if (heights[i] < temp_low) //if height is less than lowest height (outside of range)
            {
                cost += pow(abs(heights[i] - temp_low), 2); //add the difference^2
            }
            if (heights[i] > temp_high) //height is greater than greatest, outside of range
            {
                cost += pow(abs(temp_high - heights[i]), 2); //add difference^2
            }
        }
        if (cost < min_cost) //check if current cost is lower than minimum recorded cost
        {
            min_cost = cost;
        }
    }


    ofstream outfile("skidesign.out");
    outfile<<min_cost<<endl;
    return 0;





} 
