/*
ID: drayales
TASK: pprime
LANG: C++
*/

/*
    in: int a (lower), int b (upper) (5-100M)
    out: list of numbers both PALIDROMIC and PRIME between a and b
*/

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

int isprime(long n); //checks if number is prime
void palgen(int a, int b, long &count); //generates palidromes

int nums[10000]; //stores results from palgen
int ones[3] = {5, 7, 11}; //special prime palidromes


int main()
{
    int a, b;
    ifstream input1;
    input1.open("pprime.in");
    input1>>a>>b;
    input1.close();
    
    long count = 0; 
    palgen(a, b, count);
    cout<<count<<endl;

    ofstream outfile("pprime.out");
    for (int i = 0; i < count; i++)
    {
        outfile<<nums[i]<<endl;
    }
}

void palgen(int a, int b, long &count)
//any palindrome with an even number of digits is divisible by 11 and is therefore not prime.
//the only even-digit palidrome prime is 11.
//because of this, we can also only generate odd-digit numbers
//by avoiding the last digit.
//ex: 518, only copy 1 and 5, avoid 8
{
    if (a < 12) //so 5, 7, or 11 may be valid
    {
        for (int i = 0; i < 3; i++) //3 numbers in array
        {
            if (a <= ones[i]) //if number is valid
            {
                nums[count] = ones[i];
                count++;
            }
        }
    }

    for (int i = 10; i <= 9999; i++) //because we are mirroring the numbers
    //1 00,00 0,000 -> 99,99 | 9,999
    {
        string number; //number converted into string
        string temp; //temporary holder for mirror half of string
        string temp2; //holder to add above two together
        long fin; //final number answer

        number = to_string(i);
        int len = number.length();

        for (int i = len - 2; i >= 0; i--) //len returns the size. as an array, to access
        //last element, subtract 1. because we avoid last element, subtract 1 more.
        {
            temp += number[i]; //concatenate
        }

        temp2 = number + temp; //add both mirrors

        fin = stol(temp2);
        if (fin > b)
        {
            break;
        }
        if (isprime(fin) == 1 && fin >= a)
        {
            nums[count] = fin;
            count++;
        }
        
    }
}

int isprime(long n) //int might have to be long
{
    if (n == 2)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return 0;
    }
    for (int i = 3; i * i <= n; i = i + 2)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
