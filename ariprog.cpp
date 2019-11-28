/*
ID: drayales
TASK: ariprog
LANG: C++
*/

/*
    in: int N (3-25) progression length
        int M (1-250) upper limit on p and q

    out: 
    if no AP can be found ('NONE')
    beginning element of arithmetic progression (space) difference in AP

    description: two mathematical parts of problem
    no 1: bi-squares: p^2 + q^2. ex: 3^2 + 5^2 = 34
            0 - p and q - M
    no 2: arithmetic progression: a, a + b, a + 2b... a + nb
        n is length of progression (0, 1, 2...)
    given boundary of bisquare make-ups (p and q), find AP of length N in all possible
    bisquares
    

    bisquares - an array of numbers that can be rewritten into the form of p^2 + q^2
    in those numbers, find arithmetic progressions that are N long
    ex: 5(4 + 1), 8(4 + 4), 10(9 + 1), 13(9 + 4), 18(9 + 9)
    8, 13, 18 is an AP with an N of 3 and a difference of 5
    

*/


#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
    int N, M;
    int squares[125001]; //set a bit higher than max size (250^2)
    int track[125001] = {0}; //indices will be 0 or 1 depending on presence of square

    ifstream input1;
    input1.open("ariprog.in");
    input1>>N>>M;
    input1.close();
    
    ofstream outfile("ariprog.out");

    int c = 0;
    //find bisquares
    for (int i = 0; i <= M; i++) //this is p
    {
        for (int j = 0; j <= M; j++) //this is q
        {
            if (!track[i*i + j*j]) //if it hasn't already been recorded, record it
            {
                squares[c] = i*i + j*j;
                track[i*i + j*j] = 1;
                c++; //c is length
            }
        }
    }

    sort(squares, squares + c);


/*
    for (int i = 0; i < c; i++)
    {
        cout<<i<<" "<<squares[i]<<endl;
    }
*/

/*
used to have base on outside, steps on difference
this sorted output by base instead of difference

    int prog_c;
    for (int i = 1; i < c; i++)
    {
        int base = squares[i];
        for (int j = 1; j <= 2*M*M/(N-1); j++)
        {
            prog_c = 0;
            for (int k = 0; k < N; k++)
            {
                if (track[base + k*j])
                {
                    prog_c++;
                }
            }
            if (prog_c == N)
            {
                outfile<<base<<" "<<j<<endl;
            }
        }
    }*/
    
    
    int prog_c; //count members of progression
    int output_c = 0; //count numbers of progressions

    int j_end = 2*M*M/(N-1); 
    //end of |difference incrementing|
    //a + b(N-1) <= 2*M*M
    //b -> 2*M*M/(N-1)

    int i_end;
    //a + b(N-1) <= 2*M*M
    //this is calculating a (base). depending on size of step(j), a doesn't need to loop
    //all the way up.

    for (int j = 1; j <= j_end; j++) //steps are on outside
    {
        i_end = 2*M*M - j*(N-1);
        for (int i = 0; squares[i] <= i_end; i++) //base is on inside
        {
            int base = squares[i]; 
            prog_c = 0;
            for (int k = 0; k < N; k++) //length of progression
            {
                if (track[base + k*j]) //if square exists
                {
                    prog_c++;
                }
            }
            if (prog_c == N)
            {
                outfile<<base<<" "<<j<<endl;
                output_c++;
            }
        }    
    }
    if (output_c == 0)
    {
        outfile<<"NONE"<<endl;
    }
}
