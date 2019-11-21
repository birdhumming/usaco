/*
ID: drayales
TASK: dualpal
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cstring>


using namespace std;

void base_conv(int num, int base, char *final);
int is_pal(char *s);


int main()
{
    int n, s;
    ifstream input1;
    input1.open("dualpal.in");
    input1>>n;
    input1>>s;
    input1.close();

    int nums[n]; //stores answers

    //test for base_conv
    /* 
    char final[20];
    int x = 14;
    int b = 2;
    base_conv(x, b, final);
    cout<<final<<"\n";
    */

   //test for is_pal
   /*
   char test[6] = "ABCBA";
   if (is_pal(test) == 1)
   {
       cout<<"TRUE\n";
   }
   else
   {
       cout<<"FALSE\n";
   }
   */
   
  int bigcount = 0; //counts on outside loop (the i loop)
  char final[20];
  for (int i = s + 1; bigcount < n; i++) //n numbers greater than s
    {
        //cout<<"i = " <<i<<"\n";
        int smallcount = 0; //counts on inside loop (the j loop), counts the >= 2
        for (int j = 2; j < 11; j++) //binary to base 10
        {
            //cout<<"j = " <<j<<"\n"; 
            base_conv(i, j, final);
            if (is_pal(final) == 1)
            {
                smallcount++;
            }
        }
        if (smallcount >= 2)
        {
            nums[bigcount] = i;
            bigcount++;
        }
    }


ofstream outfile("dualpal.out");
for (int i = 0; i < n; i++)
{
    outfile<<nums[i]<<"\n";
}
   
 
}

void base_conv(int num, int base, char *final)
{
    int len;

    if (num == 0) //base case
    {
        strcpy(final, ""); //set string to empty, strlen now equals 0
        return; //start coming back up
    }

    base_conv(num/base, base, final);

    len = strlen(final); 
    //because recursion, base_conv divides num until = 0. then, it retraces back up
    //therefore, if base = 8, base_conv comes back up through 64, then 8, then 1
    //so placement goes [0] [1] [2], but we come back up backwards
    final[len] = "0123456789ABCDEFG"[num % base];
    final[len + 1] = '\0';
}

int is_pal(char *s)
{
    char *t;

    t = s + strlen(s) - 1; //t points to end of char *
    for (t = s + strlen(s) - 1; s < t; s++, t--) //s increase, t decreases
    	if (*s != *t)
	    return 0;

    return 1;
}
