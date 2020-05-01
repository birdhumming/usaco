/*
problem:
    we want to build the largest possible triangular pasture for the cows
    1. one side must be parallel to the x-axis, the other to the y-axis (perpendicular)
given:
    int N = number of fence posts (3-100)
    N coordinates (x, y)
find: the area of the largest possible right triangle that can be formed with three of the given points
    return area * 2, because area may not be a whole integer
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<int, int> point; //point.first = x, point.second = y
typedef pair <int, pair <point, point> > length; //length.first = length, length.second is the two points it spans

int N;
vector <point> points;

vector <length> vert_segs;
vector <length> horiz_segs;

void find_lengths();
int comp_points(point a, point b);
int lengths_meet(length a, length b);

int main()
{
    ifstream fin ("triangles.in");
    ofstream fout ("triangles.out");
    fin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        fin >> x >> y;
        point temp;
        temp.first = x;
        temp.second = y;
        points.push_back(temp);
    }

    find_lengths();

    //cout << vert_segs.size() << " " << horiz_segs.size() << endl;

    int biggest_area = 0;

    for (int i = 0; i < vert_segs.size(); i++)
    {
        for (int j = 0; j < horiz_segs.size(); j++)
        {
            //cout << '(' << i << "," << j << ')' << endl;
            length vertical = vert_segs[i];
            length horizontal = horiz_segs[j];
            if (lengths_meet(vertical, horizontal)) //valid triangle
            {
                int area = vertical.first * horizontal.first; //don't divide by two to get integer
                if (area > biggest_area)
                {
                    biggest_area = area;
                }
            }
        }
    }
    fout << biggest_area << endl;
}

void find_lengths() //finds all possible vertical/horizontal lengths
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            point one = points[i];
            point two = points[j];
            if (one.first == two.first && one.second != two.second) //in a vertical line
            {
                length temp;
                int len = abs(one.second - two.second);
                temp.first = len;
                temp.second.first = one;
                temp.second.second = two;
                vert_segs.push_back(temp);
            }
            if (one.second == two.second && one.first != two.first) //in a horizontal line
            {
                length temp;
                int len = abs(one.first - two.first);
                temp.first = len;
                temp.second.first = one;
                temp.second.second = two;
                horiz_segs.push_back(temp);
            }
        }
    }
}

int comp_points(point a, point b) //are points the same
{
    if (a.first == b.first && a.second == b.second)
    {
        return 1;
    }
    return 0;
}

int lengths_meet(length a, length b) //do the two segments share a vertex
{
    point aone = a.second.first;
    point atwo = a.second.second;
    point bone = b.second.first;
    point btwo = b.second.second;
    if (comp_points(aone, bone) || comp_points(aone, btwo) || comp_points (atwo, bone) || comp_points (atwo, btwo))
    //if any of their endpoints are the same
    {
        return 1;
    }
    return 0;
}

