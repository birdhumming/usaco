 /*
ID: drayales
TASK: milk2
LANG: C++
*/
 #include <vector>

#include <map>

#include <iostream>

#include <new>
#include <fstream>
#include <algorithm>

using namespace std;


int main ()

{
    ifstream infile ("milk2.in");
    ofstream outfile ("milk2.out");

    vector< pair <int,int> > vect;
    map<int,int> mmilk;
    int i,n;
    int * a;
    int * b;
    int cmilk,cgap,pmilk,pgap;
    int sstime, getime; //smallest start time and greatest ending time

    infile >> n;
    a = new (nothrow) int[n];
    b = new (nothrow) int[n];

    for (i = 0; i < n; i++)

    {

      infile >> a[i] >> b[i];

      vect.push_back( make_pair(a[i],b[i]) );

    }

// sort vector according to first value

    sort(vect.begin(), vect.end());


    cmilk = cgap = pmilk = pgap = 0;


    sstime = vect[0].first;

    getime = vect[0].second;

    if (n == 1)
    {
        outfile<<vect[0].first<<" "<<0<<endl;
    }
    else
    {

        for (int i=1; i<n; i++)

        {

            // "first" and "second" are used to access

            // 1st and 2nd element of pair respectively



            if ((vect[i].first <= getime) && (vect[i].first >= sstime) && (vect[i].second > getime) )  {


                    getime = vect[i].second;

                    //update value of cmilk for each round of the loop

                    cgap = 0;

                    //cout << sstime <<"," << getime <<"," << cmilk<<"," << pmilk << "\n";


            } else if ((vect[i].first > getime) && (vect[i].second > getime))

            {

                    cgap = vect[i].first - getime;

                    sstime = vect[i].first;

                    getime = vect[i].second;

                    //cout << sstime <<"," << getime <<"," << cgap<<"," << pgap << "\n";

            }


            cmilk = getime - sstime;



            if (cmilk > pmilk) pmilk = cmilk;

            if (cgap > pgap) pgap = cgap;


        }
        outfile << pmilk << " "<<pgap <<endl;
    }






  return 0;

}
