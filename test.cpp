#include <bits/stdc++.h> 
using namespace std; 

struct student {
    int id;
    int a, b, c;
    bool operator< (const student& t) const {
        if (t.a + t.b + t.c != a + b + c) 
            return a + b + c > t.a + t.b + t.c;
        if (t.a != a)
            return a > t.a;
        return id < t.id;
    }
}
  
int main() 
{ 
    vector<int> vect1{ 10, 20, 30 }; 
  
    vector<int> vect2(vect1.begin(), vect1.end()); 
  
    for (int x : vect2) 
        cout << x << " "; 
  
    return 0; 
} 