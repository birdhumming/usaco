#include <iostream> 
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cmath>


using namespace std; 

int arr[120][5];
string what(int x);
  
int main() 
{
    cout << what(1) << endl;
}

string what(int x)
{
    if (x == 1)
    {
        return "one";
    }
    if (x == 2)
    {
        return "two";
    }
    return "out";
}