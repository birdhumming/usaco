/*
NAME: drayale1
TASK: frac1
LANG: C++
*/

/*
    in: int N (1-160)
    out: sorted list of simple fractions less than one with denominators less than N
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include<algorithm>
#define MAX 160*160 + 1 //maximum N is 160

using namespace std;

typedef struct fraction //create type fraction
{
    int numerator;
    int denominator;
    float dec = 1.0 * numerator/denominator;
}fraction;


int fracgen(int N); //fraction generator
int gcd(int a, int b); //greatest common divisor
bool compare(fraction a, fraction b); //compare function for sort
fraction nums[MAX]; //answer array

int main()
{
    int N;
    
    ifstream input1;
    input1.open("frac1.in");
    input1>>N;
    input1.close();

    int nums_size = fracgen(N);

    sort(nums, nums + nums_size, compare);

    ofstream outfile("frac1.out");
    for (int i = 0; i < nums_size; i++)
    {
        //cout<<nums[i].dec<<endl;
        outfile<<nums[i].numerator<<"/"<<nums[i].denominator<<endl;
    }

}

int fracgen(int N)
{
    int count = 0;
    for (int i = 1; i <= N; i++) //denominator
    {
        for (int j = 0; j <= i; j++) //numerator
        {
            if (gcd(j, i) == 1) //j and i are relatively prime and can't simplify
            {
                nums[count].numerator = j;
                nums[count].denominator = i;
                nums[count].dec = 1.0 * j/i; //multiply by float to convert
                count++;
            }
        }
    }
    return count; //simple way to keep track of count 
}

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

bool compare(fraction a, fraction b)
{
    if (a.dec < b.dec)
    {
        return true;
    }
    return false;
}
