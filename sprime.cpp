/*
NAME: drayale1
TASK: sprime
LANG: C++
*/

/*
    in: int N (1-8), length of number
    out: list of superprimes with N digits

    description: superprimes start out as prime numbers. as you chop off digits from the 
    right side, they remain prime all the way until they reach their last digit.

        ex: 7 3 3 1 -prime
            7 3 3   -prime
            7 3     -prime
            7       -prime
*/

#include <iostream>
#include <fstream>

using namespace std;

int isprime(long n);
void sprimegen(int num, int d); //super prime generator

ofstream outfile("sprime.out"); //since outfile is in sprimegen and not main, needed to 
//create file outside of both



int main()
{
    int N;
    ifstream input1;
    input1.open("sprime.in");
    input1>>N;
    input1.close();


    //numbers are the starting digits, all must be prime
    //as they will end up being the last digits
    sprimegen(2, N - 1); 
    sprimegen(3, N - 1);
    sprimegen(5, N - 1);
    sprimegen(7, N - 1);

}



int isprime(long n)
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

void sprimegen(int num, int d) //num is the number given, d is the digits still needed
{
    if (d == 0) //once all digits have been chopped
    {
        outfile<<num<<endl;
    }
    num = num * 10; //to add a digit, multiply by ten and add to the ones

    //all odd, 5 is out
    if (isprime(num + 1) == 1)
    {
        sprimegen(num + 1, d - 1);
    }
    if (isprime(num + 3) == 1)
    {
        sprimegen(num + 3, d - 1);
    }
    if (isprime(num + 7) == 1)
    {
        sprimegen(num + 7, d - 1);
    }
    if (isprime(num + 9) == 1)
    {
        sprimegen(num + 9, d - 1);
    }
}
