```
// usaco training problems - all solutions as sample code

//always consider pre-processing if it makes things faster/eaiser later
//pre-processing everything possible
//pre-processing with prefix sum

//section 1 - simulation 

//circle to string and string duplicate concatenation, color OR flags
//clever simulation

int r1b2(char c)
{
    if(c=='r')return 1;
    return 2;
}

int main()
{
    int n; cin>>n;
    string s; cin>>s;
    //cin>>s2;
    //for (int i=0;i<n;i++)s2[i+n]=s2[i];
    
    string s2=s+s;
    
    int res=0;

    for (int i=0;i<n;i++)
    {
        int left=0, right=0;//flags for r1 b2; w0
        int l=i, r=i+n-1; //pointers for left and right positons;
        int cnt=0;
        //s[i] left to right;
        //cout<<"at start"<<" l is "<<l<<" r is "<<r<<endl;
        while(l<=r && (s2[l]=='w' || (left | r1b2(s2[l]))!=3 ))
        {
            if(s2[l]!='w')left|=r1b2(s2[l]); //this line must be before l++!!!!
            cnt++;
            l++; 
        }
        
        
        //s[i+n-1] right to left;
        
        while(l<=r && (s2[r]=='w' || (right | r1b2(s2[r]))!=3))
        {
            if(s2[r]!='w')right|=r1b2(s2[r]);  //this line must be before r--!!!!
            
            cnt++;
            r--;   
        }
        //cout<<"cnt is "<<cnt<<" l is "<<l<<" r is "<<r<<endl;
        
        res=max(res,cnt);
    }
    //cout<<s2<<endl;
    cout<<res<<endl;
    
    return 0;
}

//segments merge algorithm
//intervals merge

#define x first
#define y second

typedef pair<int, int> PII;

const int N = 5010;

int n;
PII seg[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> seg[i].x >> seg[i].y;
    sort(seg, seg + n);

    int res1 = 0, res2 = 0;
    int l = seg[0].x, r = seg[0].y;
    for (int i = 1; i < n; i ++ )
        if (seg[i].x <= r) r = max(r, seg[i].y);
        else
        {
            res1 = max(res1, r - l);
            res2 = max(res2, seg[i].x - r);
            l = seg[i].x, r = seg[i].y;
        }

    res1 = max(res1, r - l);
    cout << res1 << ' ' << res2 << endl;

    return 0;
}

//https://train.usaco.org/usacoprob2?a=8yeoA2u5MpB&S=transform

//character matrix rotation and mirroring

//use vector string for matrix rotations and mirroring
//rotate = diagonal swap + mirroring

typedef vector<string> VS;

int n;

void mirror(VS& s)
{
    for (int i = 0; i < n; i ++ )
        for (int j = 0, k = n - 1; j < k; j ++ , k -- )
            swap(s[i][j], s[i][k]);
}

void rotate(VS& s)
{
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < i; j ++ )
            swap(s[i][j], s[j][i]);
    mirror(s);
}

int check(VS& a, VS& b)
{
    auto c = a;
    for (int i = 1; i <= 3; i ++ )
    {
        rotate(c);
        if (c == b) return i;
    }
    c = a;
    mirror(c);
    if (c == b) return 4;
    for (int i = 1; i <= 3; i ++ )
    {
        rotate(c);
        if (c == b) return 5;
    }
    if (a == b) return 6;
    return 7;
}

int main()
{
    VS a, b;
    string line;

    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> line, a.push_back(line);
    for (int i = 0; i < n; i ++ ) cin >> line, b.push_back(line);
    printf("%d\n", check(a, b));

    return 0;
}


//https://train.usaco.org/usacoprob2?a=8yeoA2u5MpB&S=namenum

//simulation of old-styled phone dialpad

int get(char c)
{
    if (c <= 'O') return (c - 'A') / 3 + 2;
    if (c <= 'S') return 7;
    if (c <= 'V') return 8;
    return 9;
}

int main()
{
    string num, str;
    cin >> num;

    int cnt = 0;
    while (cin >> str)
    {
        string cur;
        for (auto c: str)
        {
            if (c == 'Q' || c == 'Z')
            {
                cur = "";
                break;
            }
            cur += get(c) + '0';
        }
        if (cur == num)
        {
            cout << str << endl;
            cnt ++ ;
        }
    }

    if (!cnt) puts("NONE");
    return 0;
}

//https://train.usaco.org/usacoprob2?a=8yeoA2u5MpB&S=palsquare

//base conversion and palindrome check

char get(int x)
{
    if (x <= 9) return x + '0';
    return x - 10 + 'A';
}

string base(int n, int b)
{
    string res;
    while (n) res += get(n % b), n /= b;
    reverse(res.begin(), res.end());
    return res;
}

bool palincheck(string s)
{
    for (int i = 0, j = s.size() - 1; i < j; i ++, j -- )
        if (s[i] != s[j])
            return false;
    return true;
}

int main()
{
    int b;
    cin >> b;

    for (int i = 1; i <= 300; i ++ )
    {
        string num = base(i * i, b);
        if (palincheck(num))
            cout << base(i, b) << ' ' << num << endl;
    }

    return 0;
}

//

//more base conversion and palindrome check

string base(int n, int b)
{
    string res;
    while (n) res += n % b + '0', n /= b;
    return res;
}

bool check(string s)
{
    for (int i = 0, j = s.size() - 1; i < j; i ++, j -- )
        if (s[i] != s[j])
            return false;
    return true;
}

int main()
{
    int n, s;
    cin >> n >> s;
    for (int i = s + 1, j = 0; j < n; i ++ )
    {
        int cnt = 0;
        for (int b = 2; b <= 10 && cnt < 2; b ++ )
            if (check(base(i, b)))
                cnt ++ ;
        if (cnt == 2)
        {
            cout << i << endl;
            j ++ ;
        }
    }

    return 0;
}


//greedy algorith to find and use lowest priced milk

const int N = 5010;

int n, m;
struct Milk
{
    int p, a;
    bool operator< (const Milk& t) const
    {
        return p < t.p;
    }
}milk[N];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i ++ ) cin >> milk[i].p >> milk[i].a;
    sort(milk, milk + m);

    int res = 0;
    for (int i = 0; i < m && n; i ++ )
    {
        int cur = min(n, milk[i].a);
        n -= cur;
        res += cur * milk[i].p;
    }

    cout << res << endl;
    return 0;
}


//complementary counting

const int N = 210;

int m, s, c;
int a[N], b[N];

int main()
{
    cin >> m >> s >> c;
    for (int i = 0; i < c; i ++ ) cin >> a[i];
    sort(a, a + c);
    int res = a[c - 1] - a[0] + 1;

    for (int i = 1; i < c; i ++ ) b[i] = a[i] - a[i - 1] - 1;
    sort(b + 1, b + c, greater<int>());

    for (int i = 1; i <= m - 1 && i < c; i ++ )
        res -= b[i];

    cout << res << endl;

    return 0;
}

// Prime Cryptarithm 
//crypt1



const int N = 10;

int n;
bool st[N];

bool check_in(int a)
{
    while (a)
    {
        if (!st[a % 10]) return false;
        a /= 10;
    }
    return true;
}

bool check_len(int a, int k)
{
    return to_string(a).size() == k;
}

bool check(int a, int b)
{
    int c = a * (b % 10), d = a * (b / 10), e = a * b;
    if (!check_in(a) || !check_in(b) || !check_in(c) || !check_in(d) || !check_in(e))
        return false;
    if (!check_len(c, 3) || !check_len(d, 3) || !check_len(e, 4))
        return false;
    return true;
}

int main()
{
    cin >> n;
    for (int i = 0, x; i < n; i ++ )
    {
        scanf("%d", &x);
        st[x] = true;
    }

    int res = 0;
    for (int a = 100; a <= 999; a ++ )
        for (int b = 10; b <= 99; b ++ )
            if (check(a, b))
                res ++ ;

    cout << res << endl;

    return 0;
}

//


const int N = 3;

int n;
int a[N], b[N];

int both() //both combo's valid neighbors
{
    if (n < 5) return n * n * n;
    int res = 1;
    for (int i = 0; i < 3; i ++ )
    {
        int x = a[i], y = b[i];
        int d = min(abs(x - y), n - abs(x - y));
        res *= min(n, max(0, 5 - d));
    }
    return res;
}

int single() //one single combo's valid neighbors
{
    int res = 1;
    for (int i = 0; i < 3; i ++ ) res *= min(n, 5);
    return res;
}

int main()
{
    cin >> n;
    for (int i = 0; i < 3; i ++ ) cin >> a[i]; // loop to 3 not n here!!!
    for (int i = 0; i < 3; i ++ ) cin >> b[i];

    cout << single() + single() - both() << endl;

    return 0;
}


/// wormhole - point split; circle checking; cycle detection;
//
#include <bits/stdc++.h>
using namespace std;

const int N=12;
int n, ans;

int mvright[N], jump[N];

int st[N], used[N][2], cur[N][2];

struct point
{
    int x,y;

    bool operator< (const point& t) const
    {
        if(y!=t.y)return y<t.y;
        return x<t.x;
    }
}q[N];

bool dfs_c(int a, int b)
{
    if(cur[a][b]) return true;
    if(used[a][b]) return false;

    int res=false;

    used[a][b]=true;
    cur[a][b]=true;

    if(!b) //0 is goin point; 1 is goout point
    {
        //a is goin point;
        //jump[a] is next point
        if(dfs_c(jump[a], 1)) res=true;


    } else
    {
        if(mvright[a]!=-1 && dfs_c(mvright[a], 0)) res=true;
    }

    cur[a][b]=false;
    return res;    
}

bool circle(){

    memset(used, 0, sizeof used); //forgot these 2 lines
    memset(cur, 0, sizeof cur);

    for(int i=0;i<n;i++)
        for(int j=0;j<2;j++)
            if(!used[i][j])
                if(dfs_c(i,j)) return true;

    return false;
}

void dfs(int u)
{
    if(u==n/2) if(circle()) {ans++;return;} //must have return here!

    for(int i=0;i<n;i++)
    {
        if(!st[i]){
            for(int j=i+1;j<n;j++)
            {
                if(!st[j])
                {
                    st[j]=true;
                    st[i]=true;
                    jump[i]=j;
                    jump[j]=i;
                    dfs(u+1);
                    jump[i]=-1,jump[j]=-1;
                    st[j]=false,st[i]=false;

                }
                            

            }
            break; //break out of i-loop

        }

    }

}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>q[i].x>>q[i].y;
    sort(q,q+n);

    memset(mvright, -1, sizeof mvright);
    memset(jump, -1, sizeof jump);

    //n wormholes from 

    for(int i=1;i<n;i++)
        if(q[i-1].y==q[i].y)mvright[i-1]=i; 
        //mvright is the next wormhole on the right


    dfs(0);

    cout<<ans<<endl;
    return 0;
}

//

//brutal force complete search all possible heights

const int N = 1010;

int n;
int h[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> h[i];

    int res = 1e8;
    for (int i = 0; i <= 83; i ++ )
    {
        int j = i + 17, cost = 0;
        for (int k = 0; k < n; k ++ )
            if (h[k] > j) cost += (h[k] - j) * (h[k] - j);
            else if (h[k] < i) cost += (i - h[k]) * (i - h[k]);
        res = min(res, cost);
    }

    cout << res << endl;

    return 0;
}

//
//find possible sequences with struct


const int N = 250 * 250 * 2 + 10;

int n, m;
bool st[N];
struct Seq
{
    int a, b;
    bool operator< (const Seq& t) const
    {
        if (b != t.b) return b < t.b;
        return a < t.a;
    }
}seq[10000];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= m; i ++ )
        for (int j = i; j <= m; j ++ )
            st[i * i + j * j] = true;

    int cnt = 0, S = m * m * 2;
    for (int i = 0; i <= S; i ++ )
        if (st[i])
            for (int j = i + 1; j <= S; j ++ )
                if (st[j])
                {
                    int d = j - i, last = i + d * (n - 1);
                    if (last > S) break;
                    bool flag = true;
                    for (int k = j + d; k <= last; k += d)
                        if (!st[k])
                        {
                            flag = false;
                            break;
                        }
                    if (flag) seq[cnt ++ ] = {i, d};
                }

    if (!cnt) puts("NONE");
    else
    {
        sort(seq, seq + cnt);
        for (int i = 0; i < cnt; i ++ )
            printf("%d %d\n", seq[i].a, seq[i].b);
    }

    return 0;
}

//
//bfs with queue 

const int N = 21;

int A, B, C;
bool st[N][N][N];
struct Node
{
    int a, b, c;
}q[N * N * N];
int hh, tt;

void insert(int a, int b, int c)
{
    if (!st[a][b][c])
    {
        q[ ++ tt] = {a, b, c};
        st[a][b][c] = true;
    }
}

void bfs()
{
    q[0] = {0, 0, C};
    st[0][0][C] = true;
    while (hh <= tt)
    {
        auto t = q[hh ++ ];
        int a = t.a, b = t.b, c = t.c;
        insert(a - min(a, B - b), min(a + b, B), c);
        insert(a - min(a, C - c), b, min(a + c, C));
        insert(min(a + b, A), b - min(b, A - a), c);
        insert(a, b - min(b, C - c), min(b + c, C));
        insert(min(a + c, A), b, c - min(A - a, c));
        insert(a, min(b + c, B), c - min(B - b, c));
    }
}

int main()
{
    cin >> A >> B >> C;
    bfs();

    for (int c = 0; c <= C; c ++ )
        for (int b = 0; b <= B; b ++ )
            if (st[0][b][c])
            {
                cout << c << ' ';
                break;
            }

    return 0;
}

//
//simple DP to find max value path for number triangle
//bottom up is easier for transition equation 

const int N = 510;

int n;
int a[N][N], f[N][N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j <= i; j ++ )
            scanf("%d", &a[i][j]);

    for (int i = n - 1; i >= 0; i -- )
        for (int j = 0; j <= i; j ++ )
            f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + a[i][j];

    printf("%d\n", f[0][0]);

    return 0;
}

//
//prime number sieving - linear time


const int N = 1e7 + 10;

int primes[N], cnt;
bool st[N];

void init(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

bool check(int x)
{
    string s = to_string(x);
    for (int i = 0, j = s.size() - 1; i < j; i ++, j -- )
        if (s[i] != s[j])
            return false;
    return true;
}

int main()
{
    init(N - 1);
    int a, b;
    scanf("%d%d", &a, &b);
    for (int i = 0; i < cnt; i ++ )
    {
        int p = primes[i];
        if (p >= a && p <= b && check(p))
            printf("%d\n", p);
    }

    return 0;
}

//prime number check - check if it's a prime number,  not sieving
//


int n;

bool is_prime(int x)
{
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
            return false;
    return true;
}

void dfs(int x, int k)
{
    if (!is_prime(x)) return;
    if (k == n) cout << x << endl;
    else
    {
        int d[] = {1, 3, 7, 9};
        for (int i: d)
            dfs(x * 10 + i, k + 1);
    }
}

int main()
{
    cin >> n;
    dfs(2, 1), dfs(3, 1), dfs(5, 1), dfs(7, 1); //only start with primes
    return 0;
}

// above section 1; 

//below section 2

// castle - two rounds of loops, 1st round answer question 1 and 2; 
//2nd round answer question 3 &4, trying to break all possible walls
//and see which one makes the greatest connected room, record the wall
//and the room area

//to find connected parts in graph
//bfs or dfs can both do but longer codes, aka flood fill
//
//union find - disjoint set also work with shorter code


const int N = 55, M = N * N;

int n, m;
int g[N][N];
int p[M], sz[M]; //union find parents

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            cin >> g[i][j];

//initialize every grid point room first
    for (int i = 0; i < n * m; i ++ )
    {
        p[i] = i;
        sz[i] = 1;
    }

    //wall to north, wall to east
    //room above, and root to the east
    int dx[2] = {-1, 0}, dy[2] = {0, 1}, dw[2] = {2, 4};
    int cnt = n * m, max_area = 1;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            for (int u = 0; u < 2; u ++ )
                if (!(g[i][j] & dw[u]))
                {
                    int x = i + dx[u], y = j + dy[u];
                    if (x < 0 || x >= n || y < 0 || y >= m) continue;
                    int a = i * m + j, b = x * m + y;
                    a = find(a), b = find(b);
                    if (a != b)
                    {
                        cnt -- ;
                        sz[b] += sz[a];
                        p[a] = b;
                        max_area = max(max_area, sz[b]);
                    }
                }

    cout << cnt << endl << max_area << endl;
    max_area = 0;
    int rx, ry, rw;

    for (int j = 0; j < m; j ++ )
        for (int i = n - 1; i >= 0; i -- )
            for (int u = 0; u < 2; u ++ )
                if (g[i][j] & dw[u])
                {
                    int x = i + dx[u], y = j + dy[u];
                    if (x < 0 || x >= n || y < 0 || y >= m) continue;
                    int a = i * m + j, b = x * m + y;
                    a = find(a), b = find(b);
                    if (a != b)
                    {
                        int area = sz[a] + sz[b];
                        if (area > max_area)
                        {
                            max_area = area;
                            rx = i, ry = j, rw = u;
                        }
                    }
                }

    cout << max_area << endl;
    cout << rx + 1 << ' ' << ry + 1 << ' ' << (rw ? 'E': 'N') << endl;

    return 0;
}

//
//easy one if you know stern-brocot tree
//stern brocot tree to print out fractions in the order of their values
//with in-order traversal and dfs recursion

int n;

void dfs(int a, int b, int c, int d)
{
    if (b + d > n) return;
    dfs(a, b, a + c, b + d);
    printf("%d/%d\n", a + c, b + d);
    dfs(a + c, b + d, c, d);
}

int main()
{
    cin >> n;
    puts("0/1");
    dfs(0, 1, 1, 1);
    puts("1/1");
    return 0;
}

//3 value sort - swap count 

//O(n) complexity same idea as official solution at 
// https://train.usaco.org/usacoanal2?a=EN7lp93YoKz&S=sort3

//graph with cycle counting - kind of hard to think of 


/*
先将数组排序得到最终的序列，由当前数组与最终数组之间的位置占用关系建图，如原本一个位置要放1，但是放了2，就增加一条2到1的边，由此得到由当前数组变换到最终数组的映射图， 如图:

观察该图可发现：
每把一个数字放到另一个位置，必然会有一个其他的数放到当前位置，所以该图的每一个节点必然有入度等于出度，所以该图是欧拉图
每当一个数放在了正确的位置上，就会出现一个自环，所以最终的结果是n个数就有n个环。对于每个不是自环的环，都可以通过交换相应位置上的数拆成自环，所以要想使交换次数最少，就要找到图中最多的环的个数m，找到后最优解即为n - m，所以问题就变成了如何找该图中最多环的个数。
如何找最多的环？
首先，最优解一定不同时包含正向大环和逆向大环，因为这种情况我们都可以把它看成更多的小环，然后按照如下过程找环:
1. 自环直接加到答案上
2. 再从两个节点形成的环开始找起，为：min(e[i][j], e[j][i]), 边找边去除，同时加到答案上
3. 将两个节点的环去掉后最终一定剩下完整大环或者没有大环，因为该图为欧拉图，每次都是成对去除一个节点的入度出度，最终一定不存在入度出度之和为奇数的节点，答案只需加上任意两节点之间边的个数即可：m += e[1][2] + e[2][1]

*/

const int N = 1010;

int n, m;
int a[N], b[N], s[4];

int main()
{
    cin >> n;

    for(int i = 0; i < n; i ++)
    {
        cin >> a[i];
        s[a[i]]++;
    }
//original sequence is in a[i], with each digit counts in s[a[i]]
//s[1] of 1's
//s[2] of 2's
//s[3] of 3's

    //count sort with complexity O(n)
    //get a sorted result of sequence in b[k]
    //b[k] is made up of:
    //first s[1] of 1's
    //then s[2] of 2's
    //and s[3] of 3's   

    for(int i = 1, k = 0; i <= 3; i++)
        for(int j = 0; j < s[i]; j++)
            b[k++] = i;

    //set up graph 
    //edges array

    int e[4][4] = {0};
    for(int i = 0; i < n; i++) e[a[i]][b[i]]++;

    //self cycles count size 1 circles:
    //self pointing edges gives that number easily
    for(int i = 1; i <= 3; i++) m += e[i][i];

    //count size 2 circles
    //size 2 circles is mixed with size 3 circles, but the lesser value of e[i][j]
    //and e[j][i] gives the number of size-2 circles
    for(int i = 1; i <= 3; i++)
        for(int j = i + 1; j <= 3; j++)
            {
                int t = min(e[i][j], e[j][i]);
                e[i][j] -= t, e[j][i] -= t;
                m += t;
            }

    //count size 3 circles
    //only need to count 2 sides, one of them must be zero but don't know which one
    m += e[1][2] + e[2][1];
    //take those circles out and what's left is the number of swaps needed

    //any of those circles won't need a swap:
    cout << n - m;

    return 0;
}

作者：LywockeeZ
链接：https://www.acwing.com/solution/content/19822/


//

//holstein - already done
//binary compression representation


const int N = 15, M = 25;

int m, n;
int need[M], s[N][M], sum[M];

int main()
{
    cin >> m;
    for (int i = 0; i < m; i ++ ) cin >> need[i];
    cin >> n;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            cin >> s[i][j];

    vector<int> res;
    for (int i = 0; i < 1 << n; i ++ )
    {
        vector<int> t;
        memset(sum, 0, sizeof sum);
        for (int j = 0; j < n; j ++ )
            if (i >> j & 1)
            {
                t.push_back(j);
                for (int k = 0; k < m; k ++ )
                    sum[k] += s[j][k];
            }

        bool flag = true;
        for (int j = 0; j < m; j ++ )
            if (sum[j] < need[j])
            {
                flag = false;
                break;
            }
        if (flag)
        {
            if (res.empty() || res.size() > t.size() || res.size() == t.size() && res > t)
                res = t;
        }
    }

    cout << res.size() << ' ';
    for (auto x: res) cout << x + 1 << ' ';
    return 0;
}
//


//hamming distance, XOR
//dfs, brutal force complete search - don't use greedy
//

const int N = 256;

int n, b, d;
int path[N];
bool g[N][N];

int get_ones(int x)
{
    int res = 0;
    while (x) res += x & 1, x >>= 1;
    return res;
}

bool dfs(int u, int start)
{
    if (u == n)
    {
        for (int i = 0; i < n; i ++ )
        {
            cout << path[i];
            if ((i + 1) % 10) cout << ' '; //output 10 one line
            else cout << endl;
        }
        return true;
    }

    for (int i = start; i < 1 << b; i ++ )
    {
        bool flag = true; //this line can't be out of for loop
        //
        //try to check all previous codes will work with i;
        for (int j = 0; j < u; j ++ )
            if (!g[i][path[j]])
            {
                flag = false;
                break;
            }
        //i is a valid code for current u
        if (flag)
        {
            path[u] = i;
            if (dfs(u + 1, i + 1)) return true;;
        }
    }

    //restore site before recursion
    return false;
}

int main()
{
    //establish graph first
    cin >> n >> b >> d;
    for (int i = 0; i < 1 << b; i ++ )
        for (int j = 0; j < 1 << b; j ++ )
            if (get_ones(i ^ j) >= d) //hamming distance >=d
                g[i][j] = true;

    dfs(1, 1);   //brutal search; 0 must be in already, so start with one!
    return 0;
}

// hamming code above end of section 2.1



//easier to understand roman code:

//下面的列表分别为个，十，百，千位为1~9的罗马数字的表示方法
//可以发现这个序列存在一定的规律
//每一行只需要三个字母（最小字母，中等字母，最大字母），并且这三个字母的出现次数是相同的
//I II III IV V VI VII VIII IX 第一行的最小字母为I,中等字母为V,最大字母为X,
//X XX XXX XL L LX LXX LXXX XC 最小为X,中等为L,最大为C
//C CC CCC CD D DC DCC DCCC CM 最小为C,中等为D,最大为M
//M MM MMM 

char ch[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
//ans存的是罗马字母总的出现次数
int ans[7];
//cnt数组存的是数字1~9分别所需要的最小、中等、最大字母的个数
int cnt[10][3] = {
             //比如下方的
             //{1, 0, 0}表示的是1(数组cnt的行下标)需要最小字母1个，中等0个，最大0个
    {0, 0, 0},{1, 0, 0},{2, 0, 0},{3, 0, 0},{1, 1, 0},{0, 1, 0},{1, 1, 0},{2, 1, 0},
    {3, 1, 0},{1, 0, 1}
};

//分解数字的每一位，把需要的罗马数字加到ans数组中去
void add(int x){
    //d为偏移量，为什么我们需要一个偏移量？
    //比如数字11，我们可以把他分解为个位上的1 + 十位上的1
    //那么当我们处理完个位上的1之后，我们需要将我们的最小、中等、字母更新
    //处理个位时，这三个字母分别为'I' 'V' 'X'，处理百位时应该为'X' 'L' 'C'......以此类推
    //我们发现每个字母的下标偏移量为2
    int d = 0;
    while (x){
        for (int i = 0; i < 3; ++i){
            //分别计算最小、中等、最大字母的出现次数
            ans[i + d] +=  cnt[x % 10][i];
        }
        d += 2;
        x /= 10;
    }
}


int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        add(i);

    for (int i = 0; i < 7; ++i)
        if (ans[i]) printf("%c %d\n",ch[i],ans[i]);


    return 0;
}

作者：kyo
链接：https://www.acwing.com/solution/content/30992/

//not so good yxc roma code
int n;

int main()
{
    string name[13] = {
        "M", "CM", "D", "CD", "C", "XC", "L",
        "XL", "X", "IX", "V", "IV", "I"
    };
    int num[13] = {
        1000, 900, 500, 400, 100, 90, 50, 40,
        10, 9, 5, 4, 1
    };

    unordered_map<char, int> cnt;
    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 0, x = i; j < 13; j ++ )
            while (x >= num[j])
            {
                x -= num[j];
                for (auto c: name[j])
                    cnt[c] ++ ;
            }
    }

    string cs = "IVXLCDM";
    for (auto c: cs)
        if (cnt[c])
            cout << c << ' ' << cnt[c] << endl;

    return 0;
}

//


typedef long long LL;
const int N = 400;

int n, m;
LL f[N];

int main()
{
    cin >> n;
    int m = n * (n + 1) / 2;
    if (m % 2) puts("0");
    else
    {
        m /= 2;
        f[0] = 1;
        for (int i = 1; i <= n; i ++ )
            for (int j = m; j >= i; j -- )
                f[j] += f[j - i];
        cout << f[m] / 2 << endl;
    }

    return 0;
}

//runaround number

//run around - best solution
const int M = 10;
int n, used[M], cnt[M];

bool check(int i)
{
    string path = to_string(i);
    memset(used, 0, sizeof used);
    memset(cnt, 0, sizeof cnt);
    for (int i = 0, j = 0; i < path.size(); i ++ )
    {
        j += path[j] - '0';

        j %= path.size();
        if (cnt[path[j] - '0']) return false; //digit already used?
        cnt[path[j] - '0']++;
        if (used[j]) return false; //j digit appear again
        used[j] = true;
        //how does this guarantee returning to same digit
        //this code does work and passed all tests
    }

    return true;
}

int main() {
    cin >> n;
    for (int i = n + 1; ; i++) {
        if (check(i)) {
            cout << i << endl;
            break;
        }
    }
}

//runaround number - easier too long
#include<bits/stdc++.h>

using namespace std;

int n;
int num[10]; 
int book[10];//用来标记这个数字循环了几次 

int main() {
    cin >> n;
    for(int i = n + 1; ; i++)//从输入的数的后一个开始查找 
    {
        memset(book, 0, sizeof book);//开始将标记设为零 
        int len = log10(i) + 1;//计算该数的位数 
        int t = i; 
        int flat = 0, glat = 0, hlat=0;
        for(int j = 1; j <= len; j ++)//将这个数分解并存入num数组中 
        {
            num[j] = t / pow(10, len - j);
            if(num[j] == 0)//如果这个数中有零直接结束再寻找下一个 
            {
                flat =  1;
                break;
            }
            t = t % int(pow(10, len - j));
        }
        for(int p = 1; p < len; p ++)//检查这个数组中是否有相等的数 
            for(int q = p + 1; q <= len; q ++)
                if(num[p] == num[q]) //如果有直接结束再寻找下一个 
                {
                    flat = 1;
                    break;
                }
        if(flat == 0)//如果不含零或相等的元素，就进行下一步判断 
        {
        int k = 1;
        book[k] = 1;//从头开始判断并标记 
        while(1)
        {
            //找他的下一个数并标记 
            if(num[k]%len + k <= len) 
            k = num[k] % len + k;
            else
            k = (num[k] % len + k) % len;
            book[k] += 1; 
            for(int o = 1; o <= len; o ++)
                if(book[o] == 2)//如果有一个数循环了两次就结束 
                {
                    hlat=1;
                    break;
                }

            if(hlat == 1)
            break;
        }
        for(int l = 1; l < len; l ++)//如果循环两次的不是第一个数或者有的数没有循环到就不符合条件 
            if(book[1] != 2 || book[l + 1] != 1) glat = 1;

        if(glat == 0)//符合条件就输出 
            for(int m = 1; m <= len; m ++)
            printf("%d",num[m]);

        }
        if(flat == 0 && glat == 0)//不符合条件就找下一个数 
        break;
    }
 } 

作者：a4199
链接：https://www.acwing.com/solution/content/5598/





//yxc roundaround - not so easy
const int N = 10;

int m, ans = 1e9;
string path;
bool st[N], used[N];

bool check()
{
    memset(used, 0, sizeof used);
    for (int i = 0, j = 0; i < path.size(); i ++ )
    {
        j += path[j] - '0';
        j %= path.size();
        if (used[j]) return false;
        used[j] = true;
    }

    return true;
}

void dfs()
{
    if (path.size())
    {
        int n = stoi(path);
        if (n > m && check()) ans = min(ans, n);
    }

    for (int i = 1; i <= 9; i ++ )
        if (!st[i])
        {
            st[i] = true;
            path += i + '0';
            dfs();
            path.pop_back(); //restore site
            st[i] = false;
        }
}

int main()
{
    cin >> m;
    dfs();
    cout << ans << endl;

    return 0;
}

//above runaround number

//
//party lamp

int state[8][6] = {
    {1, 1, 1, 1, 1, 1},  // 无
    {0, 0, 0, 0, 0, 0},  // 1
    {0, 1, 0, 1, 0, 1},  // 2
    {1, 0, 1, 0, 1, 0},  // 3
    {0, 1, 1, 0, 1, 1},  // 4
    {1, 0, 0, 1, 0, 0},  // 14
    {1, 1, 0, 0, 0, 1},  // 24
    {0, 0, 1, 1, 1, 0},  // 34
};

int n, c;
vector<int> on, off;

bool check(int s[6])
{
    for (auto id: on)
        if (!s[id % 6])
            return false;
    for (auto id: off)
        if (s[id % 6])
            return false;
    return true;
}

void work(vector<int> ids)
{
    sort(ids.begin(), ids.end(),[](int a, int b){
        for (int i = 0; i < 6; i ++ )
            if (state[a][i] != state[b][i])
                return state[a][i] < state[b][i];
        return false;
    });

    bool has_print = false;
    for (auto id: ids)
    {
        auto s = state[id];
        if (check(s))
        {
            has_print = true;
            for (int i = 0; i < n; i ++ )
                cout << s[i % 6];
            cout << endl;
        }
    }
    if (!has_print) puts("IMPOSSIBLE");
}

int main()
{
    cin >> n >> c;
    int id;
    while (cin >> id, id != -1) on.push_back(id - 1);
    while (cin >> id, id != -1) off.push_back(id - 1);

    if (!c) work({0});
    else if (c == 1) work({1, 2, 3, 4});
    else if (c == 2) work({0, 1, 2, 3, 5, 6, 7});
    else work({0, 1, 2, 3, 4, 5, 6, 7});

    return 0;
}

//



typedef unsigned long long ULL;
const int N = 200010, P = 131;

string str;
bool f[N];

int main()
{
    unordered_set<ULL> hash;
    while (cin >> str, str != ".")
    {
        ULL h = 0;
        for (int i = str.size() - 1; i >= 0; i -- )
            h = h * P + str[i];
        hash.insert(h);
    }

    str.clear();
    string line;
    while (cin >> line) str += line;

    int res = 0;
    f[0] = true;
    for (int i = 1; i <= str.size(); i ++ )
    {
        ULL h = 0;
        for (int j = i; j > i - 10 && j > 0; j -- )
        {
            h = h * P + str[j - 1];
            if (hash.count(h) && f[j - 1])
            {
                f[i] = true;
                break;
            }
        }
        if (f[i]) res = i;
    }

    cout << res << endl;
    return 0;
}

//



const int N = 210, M = 110, MOD = 9901;

int n, m;
int f[N][M];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i ++ ) f[1][i] = 1;
    for (int i = 2; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            for (int k = 1; k <= i - 2; k ++ )
                (f[i][j] += f[k][j - 1] * f[i - 1 - k][j - 1]) %= MOD;

    cout << (f[n][m] - f[n][m - 1] + MOD) % MOD << endl;

    return 0;
}

//


int n;

bool check(string num)
{
    num = '+' + num;
    int res = 0;
    for (int i = 0; i < num.size(); i ++ )
    {
        int j = i + 1, x = 0;
        while (j < num.size() && num[j] != '+' && num[j] != '-')
        {
            char c = num[j];
            if (c != ' ') x = x * 10 + c - '0';
            j ++ ;
        }
        if (num[i] == '+') res += x;
        else res -= x;
        i = j - 1;
    }
    return res == 0;
}

void dfs(int u, string num)
{
    if (u > n)
    {
        if (check(num)) cout << num << endl;
        return;
    }

    char ops[] = {' ', '+', '-'};
    for (auto op: ops)
        dfs(u + 1, num + op + to_string(u));
}

int main()
{
    cin >> n;
    dfs(2, "1");
    return 0;
}

//
const int N = 100010;
int n, m;
long long int f[N];
int main()
{
    cin >> n >> m;
    f[0] = 1;
    for(int i = 0; i < n; i ++)
    {
        int v;
        cin >> v;
        for(int j = v; j <= m; j ++) f[j] = f[j] + f[j - v];
    }
    cout<< f[m];
}

//



typedef long long LL;

const int N = 10010;

int n, m;
LL f[N];

int main()
{
    cin >> n >> m;
    f[0] = 1;
    for (int i = 1; i <= n; i ++ )
    {
        int v;
        cin >> v;
        for (int j = v; j <= m; j ++ )
            f[j] += f[j - v];
    }
    cout << f[m] << endl;

    return 0;
}

//



const int N = 110;

int n = 100, m;
int w[N][N];
bool g[N][N];

void dfs(int x, int y)
{
    if (g[x][y]) return;
    g[x][y] = true;

    for (int i = 1; i <= n; i ++ ) w[x][i] += w[y][i];
    for (int i = 1; i <= n; i ++ )
        if (g[i][x])
            dfs(i, y);
    for (int i = 1; i <= n; i ++ )
        if (w[x][i] > 50)
            dfs(x, i);
}

int main()
{
    cin >> m;
    for (int i = 1; i <= n; i ++ ) g[i][i] = true;
    while (m -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        for (int i = 1; i <= n; i ++ )
            if (g[i][a])
            {
                w[i][b] += c;
                if (w[i][b] > 50) dfs(i, b);
            }
    }

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            if (i != j && g[i][j])
                cout << i << ' ' << j << endl;

    return 0;
}

//



const int N = 15;

int n, m;
char g[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void move(int& x, int& y, int& d)
{
    int a = x + dx[d], b = y + dy[d];
    if (a < 0 || a >= n || b < 0 || b >= m || g[a][b] == '*')
        d = (d + 1) % 4;
    else x = a, y = b;
}

int main()
{
    while (cin >> g[n]) n ++ ;
    m = strlen(g[0]);

    int x1, y1, d1 = 0, x2, y2, d2 = 0;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            if (g[i][j] == 'F') x1 = i, y1 = j;
            else if (g[i][j] == 'C') x2 = i, y2 = j;

    for (int i = 1; i <= 160001; i ++ )
    {
        move(x1, y1, d1);
        move(x2, y2, d2);
        if (x1 == x2 && y1 == y2)
        {
            cout << i << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}

//


#define x first
#define y second


typedef pair<int, int> PII;
const int N = 210, M = 100;

int n, m;
string g[N];
int dist[2][N][M];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
PII q[N * M];

bool check(int x, int y, int d)
{
    return g[x * 2 - 1 + dx[d]][y * 2 - 1 + dy[d]] == ' ';
}

void bfs(int sx, int sy, int dist[][M])
{
    int hh = 0, tt = 0;
    memset(dist, 0x3f, N * M * 4);
    q[0] = {sx, sy};
    dist[sx][sy] = 1;
    while (hh <= tt)
    {
        auto t = q[hh ++ ];
        for (int i = 0; i < 4; i ++ )
        {
            int x = t.x + dx[i], y = t.y + dy[i];
            if (x < 1 || x > n || y < 1 || y > m) continue;
            if (!check(t.x, t.y, i)) continue;
            if (dist[x][y] > dist[t.x][t.y] + 1)
            {
                dist[x][y] = dist[t.x][t.y] + 1;
                q[ ++ tt] = {x, y};
            }
        }
    }
}

int main()
{
    cin >> m >> n;
    getchar();
    for (int i = 0; i < n * 2 + 1; i ++ ) getline(cin, g[i]);

    int k = 0;
    for (int i = 1; i <= n; i ++ )
    {
        if (check(i, 1, 3)) bfs(i, 1, dist[k ++ ]);
        if (check(i, m, 1)) bfs(i, m, dist[k ++ ]);
    }
    for (int i = 1; i <= m; i ++ )
    {
        if (check(1, i, 0)) bfs(1, i, dist[k ++ ]);
        if (check(n, i, 2)) bfs(n, i, dist[k ++ ]);
    }

    int res = 0;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            res = max(res, min(dist[0][i][j], dist[1][i][j]));

    cout << res << endl;

    return 0;
}

// cow tours, simple floyd-warshall!


#define x first
#define y second


typedef pair<double, double> PDD;
const int N = 160;
const double INF = 1e9;

int n;
PDD q[N];
double dist[N][N], maxd[N];
char g[N][N];

double get_dist(PDD& a, PDD& b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> q[i].x >> q[i].y;
    for (int i = 0; i < n; i ++ ) cin >> g[i];

    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            if (i == j) dist[i][j] = 0;
            else if (g[i][j] == '1') dist[i][j] = get_dist(q[i], q[j]);
            else dist[i][j] = INF;

    for (int k = 0; k < n; k ++ )
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < n; j ++ )
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    double r1 = INF, r2 = 0;
    for (int i = 0; i < n; i ++ )
    {
        for (int j = 0; j < n; j ++ )
            if (dist[i][j] < INF / 2)
                maxd[i] = max(maxd[i], dist[i][j]);
        r2 = max(r2, maxd[i]);
    }

    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            if (dist[i][j] > INF / 2)
                r1 = min(r1, maxd[i] + get_dist(q[i], q[j]) + maxd[j]);

    printf("%lf\n", max(r1, r2));
    return 0;
}

//
const int N = 60;
int n;
int g[N][N], dist[N];
bool st[N];
int get(char c)
{
    if(c <= 'Z') return c - 'A' + 1;
    return c - 'a' + 27;
}
void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[26] = 0;
    for(int i = 0; i < 51; i ++)
    {
        int t = -1;
        for(int j = 1; j <= 52; j ++)
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        st[t] = true;
        for(int j = 1; j <= 52; j ++) dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
}
int main()
{
    cin >> n;
    memset(g, 0x3f, sizeof g);
    while(n --)
    {
        char a, b;
        int c;
        cin >> a >> b >> c;
        int x = get(a), y = get(b);
        g[x][y] = g[y][x] = min(c, g[x][y]);
    }
    dijkstra();
    int k = 1;
    for(int i = 1; i <= 25; i ++)
        if(dist[k] > dist[i])
            k = i;
    cout << (char)(k - 1 + 'A') << ' ' << dist[k] << endl;
    return 0;
}

作者：cht
链接：https://www.acwing.com/activity/content/code/content/1336330/



const int N=60;

int p;
int dist[N];
int g[N][N];
bool vis[N];

int get(char c){
    if(c <= 'Z') return c-'A'+1;
    return c-'a'+27;
}

void dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[26]=0;
    for(int i=0;i<51;++i){
        int t=-1;
        for(int j=1;j<=52;++j)
            if(!vis[j] && (t==-1 || dist[t]>dist[j]))
                t=j;
        vis[t]=true;
        for(int j=1;j<=52;++j)
            dist[j]=min(dist[j],dist[t]+g[t][j]);
    }
}

int main(){
    scanf("%d",&p);
    memset(g,0x3f,sizeof g);
    while(p--){
        char a,b;
        int c;
        cin>>a>>b>>c;
        a=get(a),b=get(b);
        g[a][b]=g[b][a]=min(c,g[a][b]);
    }

    dijkstra();
    int k=1;
    for(int i=1;i<=25;++i)
        if(dist[k] > dist[i])
            k=i;

    printf("%c %d",char(k-1+'A'),dist[k]);
    return 0;
}

作者：cqh
链接：https://www.acwing.com/activity/content/code/content/1442647/

//



const int N = 100010;

int p[N];

int main()
{
    int n, d;
    cin >> n >> d;
    string res;
    res += to_string(n / d) + '.';
    n %= d;
    if (!n) res += '0';
    else
    {
        memset(p, -1, sizeof p);
        string num;
        while (n && p[n] == -1)
        {
            p[n] = num.size();
            n *= 10;
            num += n / d + '0';
            n %= d;
        }
        if (!n) res += num;
        else res += num.substr(0, p[n]) + '(' + num.substr(p[n]) + ')';
    }

    for (int i = 0; i < res.size(); i ++ )
    {
        cout << res[i];
        if ((i + 1) % 76 == 0) cout << endl;
    }
    return 0;
}

// end of section 2

//start section 3





const int N = 110;

int n;
int g[N][N], dist[N];
bool st[N];

int prim()
{
    int res = 0;
    memset(dist, 0x3f, sizeof dist);
    dist[0] = 0;
    for (int i = 0; i < n; i ++ )
    {
        int t = -1;
        for (int j = 0; j < n; j ++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        st[t] = true;
        res += dist[t];
        for (int j = 0; j < n; j ++ )
            dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            cin >> g[i][j];

    cout << prim() << endl;
    return 0;
}

//
const int N = 10010;
int n, m;
int f[N];
int main()
{
    cin >> m >> n;
    for(int i = 0; i < n; i ++)
    {
        int v, w;
        cin >> w >> v;
        for(int j = v; j <= m; j ++) f[j] = max(f[j], f[j - v] + w);
    }
    cout << f[m] << endl;
    return 0;
}

作者：cht
链接：https://www.acwing.com/activity/content/code/content/1390530/



const int N = 10010;

int n, m;
int f[N];

int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i ++ )
    {
        int v, w;
        cin >> w >> v;
        for (int j = v; j <= m; j ++ )
            f[j] = max(f[j], f[j - v] + w);
    }
    cout << f[m] << endl;
    return 0;
}
//



struct Data
{
    int v, p, k;
    bool operator< (const Data& t) const
    {
        return v > t.v;
    }
};

int main()
{
    int n, k;
    cin >> k >> n;
    n ++ ;
    vector<int> q(1, 1);
    priority_queue<Data> heap;

    while (k -- )
    {
        int p;
        cin >> p;
        heap.push({p, p, 0});
    }

    while (q.size() < n)
    {
        auto t = heap.top();
        heap.pop();
        q.push_back(t.v);
        heap.push({t.p * q[t.k + 1], t.p, t.k + 1});
        while (heap.top().v == t.v)
        {
            auto r = heap.top();
            heap.pop();
            heap.push({r.p * q[r.k + 1], r.p, r.k + 1});
        }
    }

    cout << q.back() << endl;
    return 0;
}

//

const int N = 200010, M = 1 << 13;

int A, B, n, m;
int cnt[M];
struct Data
{
    int k, num;
    bool operator< (const Data& t) const
    {
        if (k != t.k) return k > t.k;
        return num < t.num;
    }
    string get_string()
    {
        string res;
        for (int i = num; i; i >>= 1)
            res += i % 2 + '0';
        res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
}q[N];

int main()
{
    string str, line;
    cin >> A >> B >> m;
    while (cin >> line) str += line;
    int n = str.size();
    for (int i = A; i <= B; i ++ )
        for (int j = 0, x = 0; j < n; j ++ )
        {
            x = x * 2 + str[j] - '0';
            if (j - i >= 0) x -= str[j - i] - '0' << i;
            if (j >= i - 1) cnt[x + (1 << i)] ++ ;
        }

    for (int i = 0; i < M; i ++ )
        q[i] = {cnt[i], i};

    sort(q, q + M);
    for (int i = 0, k = 0; i < M && k < m; i ++, k ++ )
    {
        if (!q[i].k) break;
        int j = i;
        while (j < M && q[j].k == q[i].k) j ++ ;
        cout << q[i].k << endl;
        for (int a = i, b = 0; a < j; a ++, b ++ )
        {
            cout << q[a].get_string();
            if ((b + 1) % 6 == 0) cout << endl;
            else cout << ' ';
        }
        if ((j - i) % 6) cout << endl;
        i = j - 1;
    }

    return 0;
}

//
const int N = 2000010;

int n, m = N - 1, k;
int f[N];

int main()
{
    cin >> k >> n;
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    for (int i = 0; i < n; i ++ )
    {
        int v;
        cin >> v;
        for (int j = v; j <= m; j ++ )
            f[j] = min(f[j], f[j - v] + 1);
    }
    int x = 0;
    while (f[x] <= k) x ++ ;
    cout << x - 1 << endl;

    return 0;
}

// factorial

int main()
{
    int n;
    cin >> n;
    int c = 1, d2 = 0, d5 = 0;
    for (int i = 1; i <= n; i ++ )
    {
        int x = i;
        while (x % 2 == 0) x /= 2, d2 ++ ;
        while (x % 5 == 0) x /= 5, d5 ++ ;
        c = c * x % 10;
    }
    for (int i = 0; i < d2 - d5; i ++ )
        c = c * 2 % 10;
    cout << c << endl;
    return 0;
}

//bit string

typedef long long LL;
const int N = 40;

LL n, L, I;
LL c[N][N], f[N][N];

int main()
{
    cin >> n >> L >> I;
    for (int i = 0; i < N; i ++ )
        for (int j = 0; j <= i; j ++ )
            if (!j) c[i][j] = 1;
            else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    for (int i = 0; i < N; i ++ )
        for (int j = 0; j < N; j ++ )
            for (int k = 0; k <= j; k ++ )
                f[i][j] += c[i][k];

    for (int i = 1, s = 0; i <= n; i ++ )
    {
        LL x = f[n - i][L - s];
        if (I > x)
        {
            cout << 1;
            I -= x;
            s ++ ;
        }
        else cout << 0;
    }

    return 0;
}

//spinning wheel

const int N = 360;

int v[5];
bool st[5][N];

int main()
{
    for (int i = 0; i < 5; i ++ )
    {
        int cnt;
        scanf("%d%d", &v[i], &cnt);
        while (cnt -- )
        {
            int start, len;
            scanf("%d%d", &start, &len);
            for (int j = start; j <= start + len; j ++ )
                st[i][j % N] = true;
        }
    }

    for (int i = 0; i < N; i ++ )
        for (int j = 0; j < N; j ++ )
        {
            bool flag = true;
            for (int k = 0; k < 5; k ++ )
            {
                int x = j - i * v[k];
                x = (x % N + N) % N;
                if (!st[k][x])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                printf("%d\n", i);
                return 0;
            }
        }

    puts("none");
    return 0;
}

//

int main()
{
    int g[3];
    for (int i = 0; i < 3; i ++ ) cin >> g[i];
    if (g[0] + g[1] + g[2] == 0) puts("0 0 0 0");
    else
    {
        int a[3][3];
        for (int i = 0; i < 3; i ++ )
            for (int j = 0; j < 3; j ++ )
                cin >> a[i][j];

        int res = 301, r[4];
        for (int x = 0; x <= 100; x ++ )
            for (int y = 0; y <= 100; y ++ )
                for (int z = 0; z <= 100; z ++ )
                {
                    if (x + y + z == 0) continue;
                    int s[3] = {0};
                    s[0] = x * a[0][0] + y * a[1][0] + z * a[2][0];
                    s[1] = x * a[0][1] + y * a[1][1] + z * a[2][1];
                    s[2] = x * a[0][2] + y * a[1][2] + z * a[2][2];
                    int k = (s[0] + s[1] + s[2]) / (g[0] + g[1] + g[2]);
                    if (s[0] == k * g[0] && s[1] == k * g[1] && s[2] == k * g[2])
                    {
                        int t = x + y + z;
                        if (res > t)
                        {
                            res = t;
                            r[0] = x, r[1] = y, r[2] = z, r[3] = k;
                        }
                    }
                }

        if (res == 301) puts("NONE");
        else
        {
            for (int i = 0; i < 4; i ++ ) cout << r[i] << ' ';
            cout << endl;
        }
    }

    return 0;
}

//

#define x first
#define y second

unordered_map<string, int> dist;
unordered_map<string, pair<char, string>> pre;
char g[2][4];

void set(string state)
{
    for (int i = 0; i < 4; i ++ ) g[0][i] = state[i];
    for (int i = 4, j = 3; i < 8; i ++, j -- ) g[1][j] = state[i];
}

string get()
{
    string res;
    for (int i = 0; i < 4; i ++ ) res += g[0][i];
    for (int i = 3; i >= 0; i -- ) res += g[1][i];
    return res;
}

string move0(string state)
{
    set(state);
    for (int i = 0; i < 4; i ++ ) swap(g[0][i], g[1][i]);
    return get();
}

string move1(string state)
{
    set(state);
    char a = g[0][3], b = g[1][3];
    for (int i = 0; i < 2; i ++ )
        for (int j = 3; j; j -- )
            g[i][j] = g[i][j - 1];
    g[0][0] = a, g[1][0] = b;
    return get();
}

string move2(string state)
{
    set(state);
    char t = g[0][1];
    g[0][1] = g[1][1];
    g[1][1] = g[1][2];
    g[1][2] = g[0][2];
    g[0][2] = t;
    return get();
}

int bfs(string start, string end)
{
    queue<string> q;
    q.push(start);
    dist[start] = 0;
    int cnt = 0;
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        string m[3];
        m[0] = move0(t), m[1] = move1(t), m[2] = move2(t);
        for (int i = 0; i < 3; i ++ )
        {
            string str = m[i];
            if (dist.count(str) == 0)
            {
                dist[str] = dist[t] + 1;
                pre[str] = {(char)(i + 'A'), t};
                if (str == end) return dist[str];
                q.push(str);
            }
        }
    }
    return -1;
}

int main()
{
    string start = "12345678", end;
    for (int i = 0; i < 8; i ++ )
    {
        char c;
        cin >> c;
        end += c;
    }

    if (start == end) puts("0");
    else
    {
        cout << bfs(start, end) << endl;
        string res;
        while (end != start)
        {
            res += pre[end].x;
            end = pre[end].y;
        }
        reverse(res.begin(), res.end());
        cout << res << endl;
    }

    return 0;
}

//

typedef pair<int, int> PII;

const int N = 810, M = 3000, null = 0x3f3f3f3f;

int h[N], e[M], w[M], ne[M], idx;
void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int d[N], cows[N], n, p, m;
bool st[N];

int dijkstra(int start)         //以start为起点，返回到达所有牛的距离之和
{
    memset(st, 0, sizeof st);
    memset(d, 0x3f, sizeof d);
    d[start] = 0;

    priority_queue<PII, vector<PII>, greater<PII> > heap;
    heap.push((PII){0, start});

    while(!heap.empty())
    {
        PII t = heap.top();
        heap.pop();

        int u = t.second;

        if(st[u])  continue;
        st[u] = true;

        for(int i = h[u]; ~i; i = ne[i])
        {
            int j = e[i], dist = t.first + w[i];
            if(dist < d[j])
            {
                d[j] = dist;
                heap.push((PII){d[j], j});
            }
        }
    }

    int res = 0;
    for(int i = 1; i <= n; i ++)
    {
        if(d[cows[i]] == null)  return null;
        res += d[cows[i]];
    }
    return res;
}

int main()
{
    memset(h, -1, sizeof h);

    scanf("%d%d%d", &n, &p, &m);
    for(int i = 1; i <= n; i ++)  scanf("%d", &cows[i]);

    while(m --)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }

    int res = 2e9;
    for(int i = 1; i <= p; i ++)  res = min(res, dijkstra(i));

    printf("%d", res);
    return 0;
}

作者：滑稽_ωﾉ
链接：https://www.acwing.com/activity/content/code/content/1135805/

const int N = 810, M = 3000, INF = 0x3f3f3f3f;

int n, P, C;
int h[N], e[M], w[M], ne[M], idx;
int dist[N], q[N], id[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

int spfa(int start)
{
    int hh = 0, tt = 1;
    q[0] = start;
    memset(dist, 0x3f, sizeof dist);
    dist[start] = 0;
    st[start] = true;
    while (hh != tt)
    {
        int t = q[hh ++ ];
        if (hh == N) hh = 0;
        st[t] = false;

        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if (!st[j])
                {
                    q[tt ++ ] = j;
                    if (tt == N) tt = 0;
                    st[j] = true;
                }
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i ++ )
        if (dist[id[i]] == INF) return INF;
        else res += dist[id[i]];
    return res;
}

int main()
{
    cin >> n >> P >> C;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n; i ++ ) cin >> id[i];
    while (C -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    int res = INF;
    for (int i = 1; i <= P; i ++ ) res = min(res, spfa(i));

    cout << res << endl;
    return 0;
}

//
const int N=510;

int n=500,m;
int g[N][N];
int ans[1100],cnt;
int d[N];

void dfs(int u){
    for(int i=1;i<=n;++i)
        if(g[u][i]){
            g[u][i]--,g[i][u]--;
            dfs(i);
        }
    ans[++cnt]=u;
}

int main(){
    scanf("%d",&m);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a][b]++,g[b][a]++;
        d[a]++,d[b]++;
    }

    int st=1;
    while(!d[st]) st++;
    for(int i=1;i<=n;++i)
        if(d[i] % 2){
            st=i;
            break;
        }

    dfs(st);
    for(int i=cnt;i;--i) printf("%d\n",ans[i]);
    return 0;
}

作者：cqh
链接：https://www.acwing.com/activity/content/code/content/1457064/

const int N = 510;

int n = 500, m;
int g[N][N], d[N];
int ans[1030], cnt;

void dfs(int u)
{
    for (int i = 1; i <= n; i ++ )
        if (g[u][i])
        {
            g[u][i] --, g[i][u] -- ;
            dfs(i);
        }
    ans[ ++ cnt] = u;
}

int main()
{
    cin >> m;
    while (m -- )
    {
        int a, b;
        cin >> a >> b;
        g[a][b] ++ , g[b][a] ++ ;
        d[a] ++, d[b] ++ ;
    }

    int root = 0;
    while (!d[root]) root ++ ;
    for (int i = 1; i <= n; i ++ )
        if (d[i] % 2)
        {
            root = i;
            break;
        }
    dfs(root);

    for (int i = cnt; i; i -- ) cout << ans[i] << endl;
    return 0;
}

//
const int N = 6;

int cnt;
int f[N][N][N][N][N];
unordered_map<int, int> ids;

int get(int x)
{
    if (ids.count(x) == 0) ids[x] = cnt ++ ;
    return ids[x];
}

void update(int v[], int p)
{
    for (int a = v[0]; a < 6; a ++ )
        for (int b = v[1]; b < 6; b ++ )
            for (int c = v[2]; c < 6; c ++ )
                for (int d = v[3]; d < 6; d ++ )
                    for (int e = v[4]; e < 6; e ++ )
                        f[a][b][c][d][e] = min(f[a][b][c][d][e], f[a - v[0]][b - v[1]][c - v[2]][d - v[3]][e - v[4]] + p);
}

int main()
{
    int n;
    cin >> n;
    memset(f, 0x3f, sizeof f);
    f[0][0][0][0][0] = 0;
    while (n -- )
    {
        int v[5] = {0};
        int m;
        cin >> m;
        while (m -- )
        {
            int c, k;
            cin >> c >> k;
            v[get(c)] += k;
        }
        int p;
        cin >> p;
        update(v, p);
    }

    int b;
    cin >> b;
    int m[5] = {0};
    while (b -- )
    {
        int c, k, p;
        cin >> c >> k >> p;
        m[get(c)] = k;
        int v[5] = {0};
        v[get(c)] = 1;
        update(v, p);
    }

    cout << f[m[0]][m[1]][m[2]][m[3]][m[4]] << endl;
    return 0;
}

//

#define x first
#define y second

typedef pair<int,int> PII;
const int N = 31, M = N * N, INF = 0x3f3f3f3f;

int n, m;
PII king;
int dist_sum[N][N], dist_min[N][N], dist[N][N][2];
struct Node
{
    int x, y, z;
}q[M];
bool st[N][N][2];
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};


void spfa(int sx, int sy)
{
    int hh = 0, tt = 1;
    memset(dist, 0x3f, sizeof dist);
    dist[sx][sy][0] = 0;
    q[0] = {sx, sy, 0};
    st[sx][sy][0] = true;
    while (hh != tt)
    {
        auto t = q[hh ++ ];
        if (hh == M) hh = 0;
        st[t.x][t.y][t.z] = false;

        for (int i = 0; i < 8; i ++ )
        {
            int x = t.x + dx[i], y = t.y + dy[i];
            if (x < 1 || x > n || y < 1 || y > m) continue;
            if (dist[x][y][t.z] > dist[t.x][t.y][t.z] + 1)
            {
                dist[x][y][t.z] = dist[t.x][t.y][t.z] + 1;
                if (!st[x][y][t.z])
                {
                    q[tt ++ ] = {x, y, t.z};
                    if (tt == M) tt = 0;
                    st[x][y][t.z] = true;
                }
            }

            if (!t.z)
            {
                int d = dist[t.x][t.y][t.z] + max(abs(king.x - t.x), abs(king.y - t.y));
                if (dist[t.x][t.y][1] > d)
                {
                    dist[t.x][t.y][1] = d;
                    if (!st[t.x][t.y][1])
                    {
                        q[tt ++ ] = {t.x, t.y, 1};
                        if (tt == M) tt = 0;
                        st[t.x][t.y][1] = true;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            if (dist[i][j][0] == INF)
                dist_sum[i][j] = INF;
            else
                dist_sum[i][j] += dist[i][j][0];
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            dist_min[i][j] = min(dist_min[i][j], dist[i][j][1] - dist[i][j][0]);
}

int main()
{
    cin >> n >> m;
    int x;
    char y;
    cin >> y >> x;
    y = y - 'A' + 1;
    king = {x, y};

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            dist_min[i][j] = max(abs(i - x), abs(j - y));
    while (cin >> y >> x)
    {
        y = y - 'A' + 1;
        spfa(x, y);
    }

    int res = INF;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            res = min(res, dist_sum[i][j] + dist_min[i][j]);
    cout << res << endl;

    return 0;
}

//
const int N=260;

int n;
char g[N][N];
int f[N][N];
int ans[N];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i) cin>>g[i]+1;

    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(g[i][j] == '1')
                f[i][j]=min(f[i-1][j-1],min(f[i-1][j],f[i][j-1]))+1;

    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            for(int k=1;k<=f[i][j];++k)
                ans[k]++;
    for(int i=2;ans[i];++i) cout<<i<<' '<<ans[i]<<endl;
    return 0;
}

作者：cqh
链接：https://www.acwing.com/activity/content/code/content/1458781/

const int N = 260;

int n;
char g[N][N];
int f[N][N], ans[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> g[i] + 1;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            if (g[i][j] == '1')
                f[i][j] = min(f[i - 1][j], min(f[i][j - 1], f[i - 1][j - 1])) + 1;

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            for (int k = 1; k <= f[i][j]; k ++ )
                ans[k] ++ ;

    for (int i = 2; ans[i]; i ++ ) cout << i << ' ' << ans[i] << endl;
    return 0;
}

//
const int N = 110;

int n;
int w[N], f[N][N];

int main()
{
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i ++ ) cin >> w[i], sum += w[i];

    for (int len = 1; len <= n; len ++ )
        for (int i = 0; i + len - 1 < n; i ++ )
        {
            int j = i + len - 1;
            f[i][j] = max(w[i] - f[i + 1][j], w[j] - f[i][j - 1]);
        }
    cout << (sum + f[0][n - 1]) / 2 << ' ' << (sum - f[0][n - 1]) / 2 << endl;
    return 0;
}

//
void dfs(string preorder,string inorder){
    if(!preorder.size()) return;
    int t=inorder.find(preorder[0]);
    dfs(preorder.substr(1,t),inorder.substr(0,t));
    dfs(preorder.substr(t+1),inorder.substr(t+1));
    cout<<preorder[0];
}

int main(){
    string inorder,preorder;
    cin>>inorder>>preorder;
    dfs(preorder,inorder);
    return 0;
}

作者：cqh
链接：https://www.acwing.com/activity/content/code/content/1459185/

unordered_map<char, int> pos;

string preorder, inorder, postorder;

void build(int il, int ir, int pl, int pr)
{
    if (il > ir) return;
    int k = pos[preorder[pl]];
    build(il, k - 1, pl + 1, pl + 1 + k - 1 - il);
    build(k + 1, ir, pl + 1 + k - 1 - il + 1, pr);
    postorder += preorder[pl];
}

int main()
{
    cin >> inorder >> preorder;
    int n = inorder.size();
    for (int i = 0; i < n; i ++ ) pos[inorder[i]] = i;
    build(0, n - 1, 0, n - 1);
    cout << postorder << endl;

    return 0;
}

//

const int N=10;

pair<int,int> q[N];

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

int main(){
    int n,m,p;
    cin>>n>>m>>p;
    int s=m*p,b=0;
    q[0]={0,0},q[1]={n,m},q[2]={p,0};

    for(int i=0;i<3;++i)
        for(int j=i+1;j<3;++j)
            b+=abs(gcd(q[j].first-q[i].first,q[j].second-q[i].second));
    printf("%d",(s-b+2)/2);
    return 0;
}

作者：cqh
链接：https://www.acwing.com/activity/content/code/content/1459155/

#define x first
#define y second

typedef pair<int, int> PII;

int n, m, p;
PII q[3];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    cin >> n >> m >> p;
    int s = p * m;
    int b = 0;
    q[1] = {p, 0}, q[2] = {n, m};
    for (int i = 0; i < 3; i ++ )
        for (int j = i + 1; j < 3; j ++ )
            b += abs(gcd(q[j].x - q[i].x, q[j].y - q[i].y));

    cout << (s - b + 2) / 2 << endl;
    return 0;
}

//

int n, m, T;
int t[20], v[20];

int main()
{
    cin >> n >> T >> m;

    for (int i = 0; i < n; i++) cin >> t[i];

    int ans = 0;

    for (int i = 0; i < (1 << n); i++) {
        int len = 0;
        for (int j = 0; j < n; j++) 
            if (i >> j & 1) 
                v[len++] = t[j];

        int j = 0;
        for (int i = 0; i < m && j < len; i++) {
            int sum = 0;
            while (j < len && sum + v[j] <= T) sum += v[j++];
            //cout << sum << endl;
        }
        //cout << i << ' ' << j << endl;
        if (j == len) ans = max(ans, len);

    }

    cout << ans << endl;
    return 0;
}

作者：huangda
链接：https://www.acwing.com/activity/content/code/content/1312347/
const int N = 25;

int n, t, m;
int f[N][N][N];

int main()
{
    cin >> n >> t >> m;
    for (int i = 1; i <= n; i ++ )
    {
        int v;
        cin >> v;
        for (int j = 1; j <= m; j ++ )
            for (int k = 0; k <= t; k ++ )
            {
                f[i][j][k] = f[i - 1][j][k];
                if (k >= v)
                {
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - v] + 1);
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][t] + 1);
                }
            }
    }
    cout << f[n][m][t] << endl;

    return 0;
}

// end of section 3

//start of section 4



const int N = 70000;

int n;
bool f[N];

int main()
{
    cin >> n;
    f[0] = true;
    for (int i = 0; i < n; i ++ )
    {
        int v;
        cin >> v;
        for (int j = v; j < N; j ++ )
            f[j] |= f[j - v];
    }

    int k = N - 1;
    while (k && f[k]) k -- ;

    if (k >= N - 256) cout << 0 << endl;
    else cout << k << endl;

    return 0;
}

//another person

#define inf 1000000007
#define mod 1000000007
//#pragma GCC optimize(2)
//#define int long long

template <typename T> void read(T &x){
    x=0;char ch=getchar();int fh=1;
    while (ch<'0'||ch>'9'){if (ch=='-')fh=-1;ch=getchar();}
    while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    x*=fh;
}
template <typename T> void write(T x) {
    if (x<0) x=-x,putchar('-');
    if (x>9) write(x/10);
    putchar(x%10+'0');
}
template <typename T> void writeln(T x) {
    write(x);
    puts("");
}
int n;
int a[15];
bool dp[100005];
signed main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    read(n);
    int gcd=0;
    for(register int i=1;i<=n;++i)
    {
        read(a[i]);
        gcd=__gcd(a[i],gcd);
    }
    if(gcd>1)
    {
        writeln(0);
        return 0;
    }
    dp[0]=1;
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=100000;++j)
            if(j>=a[i]&&dp[j-a[i]])
                dp[j]=1;
    int ans=0;
    for(register int i=1;i<=100000;++i)
        if(!dp[i])
            ans=max(ans,i);
    writeln(ans);
    return 0;
}

作者：adamjinwei
链接：https://www.acwing.com/activity/content/code/content/646325/


const int N = 210, INF = 0x3f3f3f3f;

int n;
int p[N];
struct Edge
{
    int w;
    vector<int> e[2];
}edge[N];
int d[N][N], g[N][N];

int get(int a, int b)
{
    for (int j = 0; j < 2; j ++ )
        for (int k: edge[b].e[j])
            if (a == k)
                return b + j * n;
    return -1;
}

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d", &n);
    for (int k = 0; k < n; k ++ )
    {
        int i;
        scanf("%d", &i);
        int id, cnt1, cnt2;
        scanf("%d%d%d", &edge[i].w, &cnt1, &cnt2);
        while (cnt1 -- )
        {
            scanf("%d", &id);
            edge[i].e[0].push_back(id);
        }
        while (cnt2 -- )
        {
            scanf("%d", &id);
            edge[i].e[1].push_back(id);
        }
    }

    for (int i = 1; i <= n * 2; i ++ ) p[i] = i;
    for (int i = 1; i <= n; i ++ )
        for (int j = 0; j < 2; j ++ )
        {
            for (int k: edge[i].e[j])
            {
                int a = i + j * n, b = get(i, k);
                p[find(a)] = find(b);
            }
        }

    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n * 2; i ++ ) g[i][i] = 0;
    for (int i = 1; i <= n; i ++ )
    {
        int a = find(i), b = find(i + n);
        g[a][b] = g[b][a] = edge[i].w;
    }

    memcpy(d, g, sizeof d);
    int res = INF;
    for (int k = 1; k <= n * 2; k ++ )
    {
        for (int i = 1; i < k; i ++ )
            for (int j = i + 1; j < k; j ++ )
                res = min((long long)res, d[i][j] + (long long)g[j][k] + g[k][i]);
        for (int i = 1; i <= n * 2; i ++ )
            for (int j = 1; j <= n * 2; j ++ )
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }

    cout << res << endl;
    return 0;
}

//

const int N = 210, M = N * 2, INF = 0x3f3f3f3f;

int n, m, S, T;
int h[N], e[M], f[M], ne[M], idx;
int q[N], d[N], cur[N];

void add(int a, int b, int c)
{
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx ++ ;
}

bool bfs()
{
    int hh = 0, tt = 0;
    memset(d, -1, sizeof d);
    q[0] = S, d[S] = 0, cur[S] = h[S];
    while (hh <= tt)
    {
        int t = q[hh ++ ];
        for (int i = h[t]; ~i; i = ne[i])
        {
            int ver = e[i];
            if (d[ver] == -1 && f[i])
            {
                d[ver] = d[t] + 1;
                cur[ver] = h[ver];
                if (ver == T) return true;
                q[ ++ tt] = ver;
            }
        }
    }
    return false;
}

int find(int u, int limit)
{
    if (u == T) return limit;
    int flow = 0;
    for (int i = cur[u]; ~i && flow < limit; i = ne[i])
    {
        cur[u] = i;
        int ver = e[i];
        if (d[ver] == d[u] + 1 && f[i])
        {
            int t = find(ver, min(f[i], limit - flow));
            if (!t) d[t] = -1;
            f[i] -= t, f[i ^ 1] += t, flow += t;
        }
    }
    return flow;
}

int dinic()
{
    int r = 0, flow;
    while (bfs()) while (flow = find(S, INF)) r += flow;
    return r;
}

int main()
{
    cin >> m >> n;
    S = 1, T = n;
    memset(h, -1, sizeof h);
    while (m -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    cout << dinic() << endl;
    return 0;
}

//dinic() above for network flow


const int N = 210;

int n, m;
bool g[N][N], st[N];
int match[N];

int find(int x)
{
    for (int i = 1; i <= m; i ++ )
        if (!st[i] && g[x][i])
        {
            st[i] = true;
            if (!match[i] || find(match[i]))
            {
                match[i] = x;
                return true;
            }
        }
    return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
    {
        int cnt, id;
        cin >> cnt;
        while (cnt -- )
        {
            cin >> id;
            g[i][id] = true;
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i ++ )
    {
        memset(st, 0, sizeof st);
        if (find(i)) res ++ ;
    }

    cout << res << endl;
    return 0;
}



//another person

const int N = 410, M = 100010, INF = 0x3f3f3f3f;

int h[N], e[M], f[M], ne[M], idx;
void add(int a, int b)
{
    e[idx] = b, f[idx] = 1, ne[idx] = h[a], h[a] = idx ++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx ++;
}

int hs[N], d[N], q[N];
int n, m, S, T;

bool bfs()
{
    memset(d, -1, sizeof d);
    d[S] = 0;

    int hh = 0, tt = -1;
    q[ ++ tt] = S;
    hs[S] = h[S];

    while(hh <= tt)
    {
        int u = q[hh ++];

        for(int i = h[u]; ~i; i = ne[i])
        {
            int j = e[i];
            if(d[j] == -1 and f[i])
            {
                d[j] = d[u] + 1;
                hs[j] = h[j];
                if(j == T)  return true;
                q[ ++ tt] = j;
            }
        }
    }
    return false;
}

int find(int u, int limit)
{
    if(u == T)  return limit;

    int flow = 0;
    for(int i = hs[u]; ~i and flow < limit; i = ne[i])
    {
        hs[u] = i;
        int j = e[i];
        if(d[j] == d[u] + 1 and f[i])
        {
            int t = find(j, min(f[i], limit - flow));
            if(!t)  d[j] = -1;
            f[i] -= t, f[i ^ 1] += t, flow += t;
        }
    }
    return flow;
}

int dinic()
{
    int res = 0, flow;
    while(bfs())  while(flow = find(S, INF))  res += flow;
    return res;
}

int main()
{
    memset(h, -1, sizeof h);

    scanf("%d%d", &n, &m);
    S = 0, T = N - 1;
    for(int i = 1; i <= n; i ++)  add(S, i);
    for(int i = 1; i <= m; i ++)  add(n + i, T);

    for(int i = 1; i <= n; i ++)
    {
        int k;
        scanf("%d", &k);
        while(k --)
        {
            int x;
            scanf("%d", &x);
            add(i, n + x);
        }
    }

    printf("%d\n", dinic());
    return 0;
}

作者：滑稽_ωﾉ
链接：https://www.acwing.com/activity/content/code/content/1136014/

//bipartite graph max matching above

//

const int N = 1010;

int n, m1, m2;
int a[N], b[N];
struct Node
{
    int finish_time, cost;
    bool operator< (const Node& t) const
    {
        return finish_time > t.finish_time;
    }
};

void work(int m, int f[])
{
    priority_queue<Node> heap;
    for (int i = 0; i < m; i ++ )
    {
        int cost;
        cin >> cost;
        heap.push({cost, cost});
    }

    for (int i = 1; i <= n; i ++ )
    {
        auto t = heap.top();
        heap.pop();
        f[i] = t.finish_time;
        t.finish_time += t.cost;
        heap.push(t);
    }
}

int main()
{
    cin >> n >> m1 >> m2;
    work(m1, a);
    work(m2, b);

    int res = 0;
    for (int i = 1, j = n; i <= n; i ++ , j -- )
        res = max(res, a[i] + b[j]);

    cout << a[n] << ' ' << res << endl;
    return 0;
}

//
const int N = 5010;

int n;
int a[N], f[N], g[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    g[0] = 1;

    int res = 0;
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 0; j < i; j ++ )
            if (!j || a[j] > a[i])
                f[i] = max(f[i], f[j] + 1);
        for (int j = 1; j < i; j ++ )
            if (a[j] == a[i])
                f[j] = -1;
        for (int j = 0; j < i; j ++ )
            if ((!j || a[j] > a[i]) && f[i] == f[j] + 1)
                g[i] += g[j];
        res = max(res, f[i]);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i ++ )
        if (f[i] == res)
            cnt += g[i];
    cout << res << ' ' << cnt << endl;
    return 0;
}

//

const int N = 55;

int n;
bool g[N][N], st1[N], st2[N];

void dfs(int u, int p, bool st[])
{
    st[u] = true;
    for (int i = 0; i <= n; i ++ )
        if (!st[i] && g[u][i] && i != p)
            dfs(i, p, st);
}

int main()
{
    int b;
    while (cin >> b, b != -1)
    {
        if (b != -2)
        {
            g[n][b] = true;
            while (cin >> b, b != -2) g[n][b] = true;
        }
        n ++ ;
    }
    n -- ;

    vector<int> res1, res2;
    for (int i = 1; i < n; i ++ )
    {
        memset(st1, 0, sizeof st1);
        memset(st2, 0, sizeof st2);
        dfs(0, i, st1);
        if (!st1[n])
        {
            res1.push_back(i);
            dfs(i, -1, st2);
            bool flag = true;
            for (int j = 0; j <= n; j ++ )
                if (j != i && st1[j] && st2[j])
                {
                    flag = false;
                    break;
                }
            if (flag) res2.push_back(i);
        }
    }

    cout << res1.size();
    for (auto x: res1) cout << ' ' << x;
    cout << endl << res2.size();
    for (auto x: res2) cout << ' ' << x;
    cout << endl;

    return 0;
}

//

const int N = 5100;

int n;
int cnt[200];
char str[N][8];
char dk[] = "qwertyuiopasdfghjklzxcvbnm";
int dv[] = {
    7, 6, 1, 2, 2, 5, 4, 1, 3, 5,
    2, 1, 4, 6, 5, 5, 7, 6, 3,
    7, 7, 4, 6, 5, 2, 5,
};
int v[200];

int get_score(char s[])
{
    int res = 0;
    for (int i = 0; s[i]; i ++ )
        res += v[s[i]];
    return res;
}

bool check(char a[], char b[])
{
    bool flag = true;
    for (int i = 0; a[i]; i ++ )
        if ( -- cnt[a[i]] < 0)
            flag = false;
    for (int i = 0; b[i]; i ++ )
        if ( -- cnt[b[i]] < 0)
            flag = false;
    for (int i = 0; a[i]; i ++ ) cnt[a[i]] ++ ;
    for (int i = 0; b[i]; i ++ ) cnt[b[i]] ++ ;
    return flag;
}

int main()
{
    for (int i = 0; i < 26; i ++ ) v[dk[i]] = dv[i];
    char s[10];
    scanf("%s", s);
    for (int i = 0; s[i]; i ++ ) cnt[s[i]] ++ ;

    while (scanf("%s", str[n]), str[n][0] != '.')
    {
        bool flag = true;
        for (int i = 0; str[n][i]; i ++ )
            if ( -- cnt[str[n][i]] < 0)
                flag = false;
        for (int i = 0; str[n][i]; i ++ )
            cnt[str[n][i]] ++ ;
        if (flag) n ++ ;
    }

    int res = 0;
    for (int i = 0; i < n; i ++ )
    {
        int score = get_score(str[i]);
        res = max(res, score);
        for (int j = i + 1; j < n; j ++ )
            if (check(str[i], str[j]))
                res = max(res, score + get_score(str[j]));
    }

    printf("%d\n", res);
    for (int i = 0; i < n; i ++ )
    {
        int score = get_score(str[i]);
        if (score == res)
        {
            puts(str[i]);
            continue;
        }
        for (int j = i + 1; j < n; j ++ )
            if (check(str[i], str[j]) && res == score + get_score(str[j]))
                printf("%s %s\n", str[i], str[j]);
    }

    return 0;
}

//

const int N = 10000;

int n;
int ans[N], top = N;
int path[N];
string state, target;

void dfs(int p, int k)
{
    if (k >= top - 1) return;
    if (state == target)
    {
        memcpy(ans, path, k * 4);
        top = k;
        return;
    }
    if (p - 2 >= 0 && state[p - 2] == 'W' && state[p - 1] == 'B')
    {
        path[k] = p - 2;
        swap(state[p - 2], state[p]);
        dfs(p - 2, k + 1);
        swap(state[p - 2], state[p]);
    }
    if (p - 1 >= 0 && state[p - 1] == 'W')
    {
        path[k] = p - 1;
        swap(state[p - 1], state[p]);
        dfs(p - 1, k + 1);
        swap(state[p - 1], state[p]);
    }
    if (p + 1 <= n * 2 && state[p + 1] == 'B')
    {
        path[k] = p + 1;
        swap(state[p + 1], state[p]);
        dfs(p + 1, k + 1);
        swap(state[p + 1], state[p]);
    }
    if (p + 2 <= n * 2 && state[p + 2] == 'B' && state[p + 1] == 'W')
    {
        path[k] = p + 2;
        swap(state[p + 2], state[p]);
        dfs(p + 2, k + 1);
        swap(state[p + 2], state[p]);
    }
}

int main()
{
    cin >> n;
    state = string(n, 'W') + ' ' + string(n, 'B');
    target = state;
    reverse(target.begin(), target.end());
    dfs(n, 0);

    for (int i = 0; i < top; i ++ )
    {
        cout << ans[i] + 1;
        if ((i + 1) % 20 == 0) cout << endl;
        else cout << ' ';
    }
    return 0;
}
//

typedef long long LL;
const int N = 40, M = 2010;
const LL INF = 1e18;

int n, m, S, T;
int h[N], e[M], ne[M], idx;
LL f[M];
int q[N], d[N], cur[N];

void add(int a, int b, LL c)
{
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx ++ ;
}

bool bfs()
{
    int hh = 0, tt = 0;
    memset(d, -1, sizeof d);
    q[0] = S, d[S] = 0, cur[S] = h[S];
    while (hh <= tt)
    {
        int t = q[hh ++ ];
        for (int i = h[t]; ~i; i = ne[i])
        {
            int ver = e[i];
            if (d[ver] == -1 && f[i])
            {
                d[ver] = d[t] + 1;
                cur[ver] = h[ver];
                if (ver == T) return true;
                q[ ++ tt] = ver;
            }
        }
    }
    return false;
}

LL find(int u, LL limit)
{
    if (u == T) return limit;
    LL flow = 0;
    for (int i = cur[u]; ~i && flow < limit; i = ne[i])
    {
        cur[u] = i;
        int ver = e[i];
        if (d[ver] == d[u] + 1 && f[i])
        {
            LL t = find(ver, min(f[i], limit - flow));
            if (!t) d[ver] = -1;
            f[i] -= t, f[i ^ 1] += t, flow += t;
        }
    }
    return flow;
}

LL dinic()
{
    LL r = 0, flow;
    while (bfs()) while (flow = find(S, INF)) r += flow;
    return r;
}

void init()
{
    for (int i = 0; i < idx; i += 2)
    {
        f[i] += f[i ^ 1];
        f[i ^ 1] = 0;
    }
}

int main()
{
    cin >> n >> m;
    S = 1, T = n;
    memset(h, -1, sizeof h);
    while (m -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c * 10000ll + 1);
    }

    LL res = dinic();
    cout << res / 10000 << ' ' << res % 10000 << endl;
    for (int i = 0; i < idx; i += 2)
    {
        init();
        LL t = f[i];
        f[i] = 0;
        LL r = dinic();
        if (r == res - t)
        {
            cout << i / 2 + 1 << endl;
            res = r;
        }
        else f[i] = t;
    }
    return 0;
}

//

const int N = 40;

int n, m;
char str[N][N];
bool g[N][N], st[N];
int d[N];
string path;

void work(int x1, int y1, int x2, int y2, char c)
{
    for (int i = x1; i <= x2; i ++ )
        for (int j = y1; j <= y2; j ++ )
            if (str[i][j] != c && str[i][j] != '.')
            {
                int a = c - 'A', b = str[i][j] - 'A';
                if (!g[a][b])
                {
                    g[a][b] = true;
                    d[b] ++ ;
                }
            }
}

void dfs(string s)
{
    if (s.empty())
    {
        cout << path << endl;
        return;
    }

    sort(s.begin(), s.end());
    for (int i = 0; i < s.size(); i ++ )
    {
        char c = s[i];
        path += c;
        string w = s.substr(0, i) + s.substr(i + 1);
        for (int j = 0; j < 26; j ++ )
            if (g[c - 'A'][j] && -- d[j] == 0)
                w += j + 'A';
        dfs(w);
        for (int j = 0; j < 26; j ++ )
            if (g[c - 'A'][j])
                d[j] ++ ;
        path.pop_back();
    }
}

void topsort()
{
    string s;
    for (int i = 0; i < 26; i ++ )
        if (st[i] && !d[i])
            s += i + 'A';
    dfs(s);
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++ ) cin >> str[i];
    for (char i = 'A'; i <= 'Z'; i ++ )
    {
        int x1 = N, x2 = -N, y1 = N, y2 = -N;
        for (int j = 0; j < n; j ++ )
            for (int k = 0; k < m; k ++ )
                if (str[j][k] == i)
                {
                    x1 = min(x1, j), x2 = max(x2, j);
                    y1 = min(y1, k), y2 = max(y2, k);
                }
        if (x1 == N) continue;
        work(x1, y1, x1, y2, i);
        work(x1, y1, x2, y1, i);
        work(x1, y2, x2, y2, i);
        work(x2, y1, x2, y2, i);
        st[i - 'A'] = true;
    }

    topsort();

    return 0;
}

//

//another person

const int N=40;

int n,m;
char str[N][N];
bool g[N][N],vis[N];
int d[N];
string path;

void work(int x1,int y1,int x2,int y2,char c){
    for(int i=x1;i<=x2;++i)
        for(int j=y1;j<=y2;++j)
            if(str[i][j]!=c && str[i][j]!='.'){
                int a=c-'A',b=str[i][j]-'A';
                if(!g[a][b]){
                    g[a][b]=true;
                    d[b]++;
                }
            }
}

void dfs(string s){
    if(s.empty()){
        cout<<path<<endl;
        return;
    }

    sort(s.begin(),s.end());
    for(int i=0;i<s.size();++i){
        char c=s[i];
        path+=c;
        string w=s.substr(0,i)+s.substr(i+1);
        for(int j=0;j<26;++j)
            if(g[c-'A'][j] && --d[j]==0)
                w+=j+'A';
        dfs(w);
        for(int j=0;j<26;++j)
            if(g[c-'A'][j]) d[j]++;
        path.pop_back();
    }
}

void topsort(){
    string s;
    for(int i=0;i<26;++i)
        if(vis[i] && !d[i])
            s+=i+'A';
    dfs(s);
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;++i) cin>>str[i];
    for(char i='A';i<='Z';++i){
        int x1=N,x2=-N,y1=N,y2=-N;
        for(int j=0;j<n;++j)
            for(int k=0;k<m;++k)
                if(str[j][k] == i){
                    x1=min(x1,j),x2=max(x2,j);
                    y1=min(y1,k),y2=max(y2,k);
                }
        if(x1 == N) continue;
        work(x1,y1,x1,y2,i);
        work(x1,y1,x2,y1,i);
        work(x1,y2,x2,y2,i);
        work(x2,y1,x2,y2,i);
        vis[i-'A']=true;
    }

    topsort();

    return 0;
}

作者：cqh
链接：https://www.acwing.com/activity/content/code/content/1464926/

//end of seciton 4

//section 5 start

//convex hull

#define x first
#define y second

using namespace std;

typedef pair<double, double> PDD;
const int N = 10010;

int n;
PDD q[N];
int stk[N], top;
bool used[N];

PDD operator- (PDD a, PDD b)
{
    return {a.x - b.x, a.y - b.y};
}

double operator* (PDD a, PDD b)
{
    return a.x * b.y - a.y * b.x;
}

double area(PDD a, PDD b, PDD c)
{
    return (b - a) * (c - a);
}

double get_dist(PDD a, PDD b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double get_convex()
{
    sort(q, q + n);
    for (int i = 0; i < n; i ++ )
    {
        while (top >= 2 && area(q[stk[top - 1]], q[stk[top]], q[i]) <= 0)
        {
            if (area(q[stk[top - 1]], q[stk[top]], q[i]) < 0)
                used[stk[top -- ]] = false;
            else
                top -- ;
        }
        stk[ ++ top] = i;
        used[i] = true;
    }
    used[0] = false;
    for (int i = n - 1; i >= 0; i -- )
    {
        if (used[i]) continue;
        while (top >= 2 && area(q[stk[top - 1]], q[stk[top]], q[i]) <= 0)
            top -- ;
        stk[ ++ top] = i;
    }

    double res = 0;
    for (int i = 1; i < top; i ++ )
        res += get_dist(q[stk[i]], q[stk[i + 1]]);
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%lf%lf", &q[i].x, &q[i].y);
    printf("%.2lf\n", get_convex());
    return 0;
}

//
#define x first
#define y second

using namespace std;
typedef pair<double,double> pdd;
const int N=10010;

pdd q[N];
int n;
int stack[N];
bool used[N];

pdd operator-(pdd a,pdd b){
    return {a.x-b.x,a.y-b.y};
}

double get_dist(pdd a,pdd b){
    double dx=a.x-b.x;
    double dy=a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}

double cross(pdd a,pdd b){
    return a.x*b.y-b.x*a.y;
}

double area(pdd a,pdd b,pdd c){
    return cross(b-a,c-a);
}

double Andrew(){
    sort(q,q+n);
    int top=0;
    for(int i=0;i<n;++i){
        while(top >= 2 && area(q[stack[top-1]],q[stack[top]],q[i]) <= 0){
            if(area(q[stack[top-1]],q[stack[top]],q[i]) < 0)
                used[stack[top--]]=false;
            else top--;
        }
        stack[++top]=i;
        used[i]=true;
    }
    used[0]=false;
    for(int i=n-1;i>=0;--i){
        if(used[i]) continue;
        while(top >= 2 && area(q[stack[top-1]],q[stack[top]],q[i]) <= 0)
            used[stack[top--]]=false;
        stack[++top]=i;
    }

    double res=0;
    for(int i=2;i<=top;++i){
        res+=get_dist(q[stack[i-1]],q[stack[i]]);
    }
    return res;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%lf%lf",&q[i].x,&q[i].y);

    double ans=Andrew();
    printf("%.2lf",ans);
    return 0;
}

作者：cqh
链接：https://www.acwing.com/activity/content/code/content/1465880/

//
typedef pair<int, int> PII;
const int N = 110;
char g[N][N];
PII q[N * N];
int n, m;
int top;

double get_dist(PII a, PII b) {
    double x = a.first - b.first;
    double y = a.second - b.second;
    return sqrt(x * x + y * y);
}

double get_hash() {
    double res = 0;
    for (int i = 0; i < top; ++i) {
        for (int j = i + 1; j < top; ++j) {
            res += get_dist(q[i], q[j]);
        }
    }
    return res;
}

char get_char(double s) {
    static double hash[N];
    static int cnt = 0;
    for (int i = 0; i < cnt; ++i) {
        if (fabs(s - hash[i]) < 1e-6)
            return i + 'a';
    }
    hash[cnt++] = s;
    return cnt - 1 + 'a';
}

void dfs(int a, int b) {
    g[a][b] = '0';
    q[top++] = {a, b};
    for (int x = a - 1; x <= a + 1; ++x) {
        for (int y = b - 1; y <= b + 1; ++y) {
            if (x != a || y != b)
                if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == '1')
                    dfs(x, y);
        }
    }
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; ++i) cin >> g[i];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '1') {
                top = 0;
                dfs(i, j);
                double s = get_hash();
                char ch = get_char(s);
                for (int k = 0; k < top; ++k)
                    g[q[k].first][q[k].second] = ch;
            }
        }
    }

    for (int i = 0; i < n; ++i) cout << g[i] << endl;

    return 0;
}

作者：kzyz
链接：https://www.acwing.com/activity/content/code/content/759002/

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
const int N = 110;

int n, m;
char g[N][N];
PII q[N * N];
int top;

double get_dist(PII a, PII b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double get_hash()
{
    double res = 0;
    for (int i = 0; i < top; i ++ )
        for (int j = i + 1; j < top; j ++ )
            res += get_dist(q[i], q[j]);
    return res;
}

char get_id(double s)
{
    static double hash[N];
    static int cnt = 0;
    for (int i = 0; i < cnt; i ++ )
        if (fabs(s - hash[i]) < 1e-6)
            return i + 'a';
    hash[cnt ++ ] = s;
    return cnt - 1 + 'a';
}

void dfs(int a, int b)
{
    g[a][b] = '0';
    q[top ++ ] = {a, b};
    for (int x = a - 1; x <= a + 1; x ++ )
        for (int y = b - 1; y <= b + 1; y ++ )
            if (x != a || y != b)
            {
                if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == '1')
                    dfs(x, y);
            }
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i ++ ) cin >> g[i];

    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            if (g[i][j] == '1')
            {
                top = 0;
                dfs(i, j);
                auto s = get_hash();
                char c = get_id(s);
                for (int k = 0; k < top; k ++ )
                    g[q[k].x][q[k].y] = c;
            }

    for (int i = 0; i < n; i ++ ) cout << g[i] << endl;
    return 0;
}
//


const int N = 5010;

int n;
int w[N], f[N][N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> w[i];

    int res = 0;
    for (int i = n; i; i -- )
        for (int j = n; j > i; j -- )
        {
            if (j == n || w[j] - w[i] != w[j + 1] - w[i + 1])
                f[i][j] = 1;
            else
                f[i][j] = f[i + 1][j + 1] + 1;
            res = max(res, min(f[i][j], j - i));
        }
    if (res < 5) res = 0;
    cout << res << endl;

    return 0;
}

//

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 130;

int n, res;
int g[N][N];

//  上左下右
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
void dfs(int x, int y, int dir, int step)
{
    if(x < 1 or x > n or y < 1 or y > n or g[x][y])  return;

    int a, b;
    stack<PII> stk;
    while(true)
    {
        g[x][y] = 2;
        step ++;
        stk.push({x, y});

        a = x + dx[dir], b = y + dy[dir];
        if(a > n or a < 1 or b > n or b < 1 or g[a][b])  break;
        x = a, y = b;
    }
    res = max(res, step);
    if(g[a][b] != 2)
    {
        for(int i = 0; i < 4; i ++)
        {
            int a = x + dx[i], b = y + dy[i];
            dfs(a, b, i, step);
        }
    }
    while(stk.size())
    {
        int x = stk.top().x, y = stk.top().y;  stk.pop();
        g[x][y] = 0;
    }
}

int main()
{
    int m;
    scanf("%d%d", &n, &m);
    while(m --)
    {
        char s[20];
        scanf("%s", s);
        int x = 0, y = s[0] - 'A' + 1;
        for(int i = 1; s[i]; i ++)  x = x * 10 + s[i] - '0';
        g[x][y] = 1;
    }

    dfs(1, 1, 2, 0);
    dfs(1, 1, 3, 0);

    printf("%d\n", res);

    return 0;
}

作者：滑稽_ωﾉ
链接：https://www.acwing.com/activity/content/code/content/1294399/
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
const int N = 130;

int n;
int g[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int ans;

void dfs(int x, int y, int d, int k)
{
    if (!x || x > n || !y || y > n || g[x][y]) return;
    stack<PII> stk;
    while (x && x <= n && y && y <= n && !g[x][y])
    {
        g[x][y] = 2;
        stk.push({x, y});
        x += dx[d], y += dy[d];
        k ++ ;
    }
    ans = max(ans, k);
    if (!x || x > n || !y || y > n || g[x][y] == 1)
    {
        x -= dx[d], y -= dy[d];
        for (int i = 0; i < 4; i ++ )
            if ((i + d) % 2)
                dfs(x + dx[i], y + dy[i], i, k);
    }

    while (stk.size())
    {
        auto t = stk.top();
        stk.pop();
        g[t.x][t.y] = 0;
    }
}

int main()
{
    int m;
    cin >> n >> m;
    while (m -- )
    {
        char a;
        int b;
        cin >> a >> b;
        a = a - 'A' + 1;
        g[b][a] = 1;
    }
    dfs(1, 1, 1, 0);
    dfs(1, 1, 2, 0);
    cout << ans << endl;
    return 0;
}

//


const int N = 110, M = 20010, INF = 0x3f3f3f3f;

int n, m;
int v[N], f[N][M];
vector<int> ans, path;

void dfs(int i, int j)
{
    if (!i)
    {
        if (ans.empty() || ans > path) ans = path;
        return;
    }
    if (f[i][j] == f[i - 1][j]) dfs(i - 1, j);

    path.push_back(v[i]);
    for (int k = j - v[i]; k >= 0; k -= v[i])
        if (f[i][j] == f[i - 1][k] + 1)
            dfs(i - 1, k);
    path.pop_back();
}

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i ++ ) cin >> v[i];
    sort(v + 1, v + n + 1, greater<int>());
    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;
    for (int i = 1; i <= n; i ++ )
        for (int j = 0; j < v[i]; j ++ )
        {
            int minf = INF;
            for (int k = j; k <= m; k += v[i])
            {
                f[i][k] = min(f[i - 1][k], minf + 1);
                minf = min(minf, f[i - 1][k]);
            }
        }

    cout << f[n][m] << ' ';
    dfs(n, m);
    for (auto x: ans) cout << x << ' ';
    cout << endl;

    return 0;
}

//
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

struct Rect
{
    char c;
    PII a, b;
};
list<Rect> rect;

int get_intersection(int a, int b, int c, int d)
{
    if (b <= c || d <= a) return 0;
    return min(b, d) - max(a, c);
}

double get_area(char c)
{
    vector<Rect> cur;
    for (auto r: rect)
        if (r.c == c || cur.size())
            cur.push_back(r);
    vector<int> xs;
    for (int i = 0; i < cur.size(); i ++ )
    {
        auto& r = cur[i];
        if (r.a.x >= cur[0].a.x && r.a.x <= cur[0].b.x)
            xs.push_back(r.a.x);
        if (r.b.x >= cur[0].a.x && r.b.x <= cur[0].b.x)
            xs.push_back(r.b.x);
    }
    sort(xs.begin(), xs.end());
    int res = 0;
    for (int i = 0; i + 1 < xs.size(); i ++ )
        if (xs[i] != xs[i + 1])
        {
            int a = xs[i], b = xs[i + 1];
            vector<PII> q;
            for (int j = 1; j < cur.size(); j ++ )
            {
                auto& r = cur[j];
                if (r.a.x <= a && r.b.x >= b)
                    q.push_back({r.a.y, r.b.y});
            }
            if (q.size())
            {
                sort(q.begin(), q.end());
                int st = q[0].x, ed = q[0].y;
                for (int j = 1; j < q.size(); j ++ )
                    if (q[j].x <= ed) ed = max(ed, q[j].y);
                    else
                    {
                        res += get_intersection(st, ed, cur[0].a.y, cur[0].b.y) * (b - a);
                        st = q[j].x, ed = q[j].y;
                    }
                res += get_intersection(st, ed, cur[0].a.y, cur[0].b.y) * (b - a);
            }
        }
    return (1 - (double)res / (cur[0].b.x - cur[0].a.x) / (cur[0].b.y - cur[0].a.y)) * 100;
}

int main()
{
    char op;
    while (cin >> op)
    {
        if (op == 'w')
        {
            char c;
            int x1, y1, x2, y2;
            scanf("(%c,%d,%d,%d,%d)", &c, &x1, &y1, &x2, &y2);
            rect.push_back({c, {min(x1, x2), min(y1, y2)}, {max(x1, x2), max(y1, y2)}});
        }
        else
        {
            char c;
            scanf("(%c)", &c);
            list<Rect>::iterator it;
            for (auto i = rect.begin(); i != rect.end(); i ++ )
                if (i->c == c)
                {
                    it = i;
                    break;
                }
            if (op == 't') rect.push_back(*it), rect.erase(it);
            else if (op == 'b') rect.push_front(*it), rect.erase(it);
            else if (op == 'd') rect.erase(it);
            else printf("%.3lf\n", get_area(c));
        }
    }

    return 0;
}

//

const int N = 100010, M = N << 1;

int h[N], e[M], ne[M], idx;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int n;

int dfn[N], low[N], tot;
int id[N], cnt;
int q[N], tt = -1;
bool st[N];

void tarjan(int u)
{
    dfn[u] = low[u] = ++ tot;
    q[++ tt] = u;
    st[u] = true;

    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(!dfn[j])
        {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        }else if(st[j])
            low[u] = min(low[u], dfn[j]);
    }

    if(dfn[u] == low[u])
    {
        ++ cnt;
        int y;
        do{
            y = q[tt --];
            st[y] = false;
            id[y] = cnt;
        }while(y != u);
    }
}

int din[N], dout[N];

int main()
{
    memset(h, -1, sizeof h);

    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
    {
        int x;
        while(scanf("%d", &x), x)  add(i, x);
    }

    for(int i = 1; i <= n; i ++)
        if(!dfn[i])  tarjan(i);

    for(int i = 1; i <= n; i ++)
        for(int j = h[i]; ~j; j = ne[j])
        {
            int k = e[j];
            int a = id[i], b = id[k];
            if(a != b)  dout[a] ++, din[b] ++;
        }

    int x = 0, y = 0;
    for(int i = 1; i <= cnt; i ++)
    {
        if(!din[i])  x ++;
        if(!dout[i])  y ++;
    }
    printf("%d\n%d\n", x, cnt == 1 ? 0 : max(x, y));
    return 0;
}

作者：滑稽_ωﾉ
链接：https://www.acwing.com/activity/content/code/content/1294297/
//有向图的强连通分量

const int N = 110, M = N * N;

int n;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], ts;
int stk[N], top;
int cnt, id[N];
bool instk[N];
int din[N], dout[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++ ts;
    stk[ ++ top] = u, instk[u] = true;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (!dfn[j])
        {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        }
        else if (instk[j]) low[u] = min(low[u], dfn[j]);
    }
    if (dfn[u] == low[u])
    {
        ++ cnt;
        int y;
        do
        {
            y = stk[top -- ];
            instk[y] = false;
            id[y] = cnt;
        } while (y != u);
    }
}

int main()
{
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i ++ )
    {
        int t;
        while (cin >> t, t) add(i, t);
    }
    for (int i = 1; i <= n; i ++ )
        if (!dfn[i])
            tarjan(i);

    for (int i = 1; i <= n; i ++ )
        for (int j = h[i]; ~j; j = ne[j])
        {
            int a = id[i], b = id[e[j]];
            if (a != b)
            {
                dout[a] ++ ;
                din[b] ++ ;
            }
        }

    int p = 0, q = 0;
    for (int i = 1; i <= cnt; i ++ )
    {
        if (!din[i]) p ++ ;
        if (!dout[i]) q ++ ;
    }
    cout << p << endl;
    if (cnt == 1) puts("0");
    else cout << max(p, q) << endl;

    return 0;}


const int N = 1010;

bool st[N][N];
int f[N][N];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    while(k --)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        st[x][y] = true;
    }

    int res = 0;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            if(st[i][j])  continue;
            else
            {
                f[i][j] = min(min(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1]) + 1;
                res = max(res, f[i][j]);
            }
    printf("%d\n", res);
    return 0;
}

作者：滑稽_ωﾉ
链接：https://www.acwing.com/activity/content/code/content/1294290/



const int N = 1010;

int n, m;
int g[N][N], f[N][N];

int main()
{
    cin >> n >> m;
    while (m -- )
    {
        int x, y;
        cin >> x >> y;
        g[x][y] = 1;
    }

    int res = 0;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            if (!g[i][j])
            {
                f[i][j] = min(f[i - 1][j], min(f[i][j - 1], f[i - 1][j - 1])) + 1;
                res = max(res, f[i][j]);
            }
    cout << res << endl;
    return 0;
}

const int N = 110;

int n, m;
unordered_map<string, int> id;
int f[N][N];
bool g[N][N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
    {
        string name;
        cin >> name;
        id[name] = i;
    }
    while (m -- )
    {
        string a, b;
        cin >> a >> b;
        g[id[a]][id[b]] = g[id[b]][id[a]] = true;
    }

    memset(f, -1, sizeof f);
    f[1][1] = 1;
    for (int i = 1; i <= n; i ++ )
        for (int j = i + 1; j <= n; j ++ )
            for (int k = 1; k < j; k ++ )
                if (f[i][k] > 0 && g[k][j])
                {
                    f[i][j] = f[j][i] = max(f[i][j], f[i][k] + 1);
                }

    int res = 1;
    for (int i = 1; i <= n; i ++ )
        if (f[i][n] > 0 && g[i][n])
            res = max(res, f[i][n]);
    cout << res << endl;

    return 0;
}
//
const int N=110;

int n,m;
map<string,int> id;
int f[N][N];
bool g[N][N];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        string name;
        cin>>name;
        id[name]=i;
    }
    while(m--){
        string a,b;
        cin>>a>>b;
        g[id[a]][id[b]]=g[id[b]][id[a]]=true;
    }

    memset(f,-1,sizeof f);
    f[1][1]=1;
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
            for(int k=1;k<j;++k)
                if(f[i][k]>0 && g[k][j])
                    f[i][j]=f[j][i]=max(f[i][j],f[i][k]+1);

    int ans=1;
    for(int i=1;i<=n;++i)
        if(f[i][n]>0 && g[i][n])
            ans=max(ans,f[i][n]);
    cout<<ans;
    return 0;
}

作者：cqh
链接：https://www.acwing.com/activity/content/code/content/1469533/

const int N = 210, M = 2610, INF = 1e8;

int n, m, S, T;
int h[N], e[M], f[M], ne[M], idx;
int q[N], d[N], cur[N];

void add(int a, int b, int c)
{
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx ++ ;
}

bool bfs()
{
    int hh = 0, tt = 0;
    memset(d, -1, sizeof d);
    q[0] = S, d[S] = 0, cur[S] = h[S];
    while (hh <= tt)
    {
        int t = q[hh ++ ];
        for (int i = h[t]; ~i; i = ne[i])
        {
            int ver = e[i];
            if (d[ver] == -1 && f[i])
            {
                d[ver] = d[t] + 1;
                cur[ver] = h[ver];
                if (ver == T) return true;
                q[ ++ tt] = ver;
            }
        }
    }
    return false;
}

int find(int u, int limit)
{
    if (u == T) return limit;
    int flow = 0;
    for (int i = cur[u]; ~i && flow < limit; i = ne[i])
    {
        cur[u] = i;
        int ver = e[i];
        if (d[ver] == d[u] + 1 && f[i])
        {
            int t = find(ver, min(f[i], limit - flow));
            if (!t) d[ver] = -1;
            f[i] -= t, f[i ^ 1] += t, flow += t;
        }
    }
    return flow;
}

int dinic()
{
    int r = 0, flow;
    while (bfs()) while (flow = find(S, INF)) r += flow;
    return r;
}

void init()
{
    for (int i = 0; i < idx; i += 2)
    {
        f[i] += f[i ^ 1];
        f[i ^ 1] = 0;
    }
}

int main()
{
    cin >> n >> m >> S >> T;
    S += n;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i ++ ) add(i, i + n, 1);
    while (m -- )
    {
        int a, b;
        cin >> a >> b;
        add(a + n, b, INF);
        add(b + n, a, INF);
    }

    int res = dinic();
    cout << res << endl;
    for (int i = 1; i <= n; i ++ )
    {
        init();
        int j = (i - 1) * 2;
        f[j] = 0;
        int t = dinic();
        if (res == t + 1)
        {
            cout << i << ' ';
            res -- ;
        }
        else f[j] = 1;
    }
    return 0;
}
//

const int N=210,M=2610,INF=0x3f3f3f3f;

int n,m,S,T;
int h[N],to[M],c[M],ne[M],idx;
int d[N],cur[N],q[N];

inline void add(int u,int v,int w){
    to[idx]=v,c[idx]=w,ne[idx]=h[u],h[u]=idx++;
    to[idx]=u,c[idx]=0,ne[idx]=h[v],h[v]=idx++;
}

inline void init(){
    for(int i=0;i<idx;i+=2){
        c[i]+=c[i^1];
        c[i^1]=0;
    }
}

bool bfs(){
    int hh=0,tt=0;
    memset(d,-1,sizeof d);
    q[0]=S,d[S]=0,cur[S]=h[S];
    while(hh <= tt){
        int t=q[hh++];
        for(int i=h[t];~i;i=ne[i]){
            int ver=to[i];
            if(d[ver]==-1 && c[i]){
                d[ver]=d[t]+1;
                cur[ver]=h[ver];
                if(ver == T) return true;
                q[++tt]=ver;
            }
        }
    }
    return false;
}

int find(int u,int limit){
    if(u == T) return limit;
    int flow=0;
    for(int i=cur[u];~i && flow<limit;i=ne[i]){
        cur[u]=i;
        int ver=to[i];
        if(d[ver]==d[u]+1 && c[i]){
            int t=find(ver,min(c[i],limit-flow));
            if(!t) d[ver]=-1;
            c[i]-=t,c[i^1]+=t,flow+=t;
        }
    }
    return flow;
}

int dinic(){
    int res=0,flow;
    while(bfs()) while(flow=find(S,INF)) res+=flow;
    return res;
}

int main(){
    memset(h,-1,sizeof h);
    cin>>n>>m>>S>>T;
    S+=n;
    for(int i=1;i<=n;++i) add(i,i+n,1);
    while(m--){
        int a,b;
        cin>>a>>b;
        add(a+n,b,INF);
        add(b+n,a,INF);
    }

    int res=dinic();
    cout<<res<<endl;
    for(int i=1;i<=n;++i){
        init();
        int j=(i-1)*2;
        c[j]=0;
        int t=dinic();
        if(res == t+1){
            cout<<i<<' ';
            res--;
        }
        else c[j]=1;
    }
    return 0;
}

作者：cqh
链接：https://www.acwing.com/activity/content/code/content/1473140/


#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
const int N = 5010;

int n;
struct Rect
{
    PII a, b;
}rect[N];

int get_range_len(int a, int b)
{
    vector<PII> q;
    for (int i = 0; i < n; i ++ )
    {
        auto& r = rect[i];
        if (r.a.x <= a && r.b.x >= b)
            q.push_back({r.a.y, r.b.y});
    }
    if (q.empty()) return 0;
    sort(q.begin(), q.end());
    int res = 0, st = q[0].x, ed = q[0].y;
    for (int i = 1; i < q.size(); i ++ )
        if (q[i].x <= ed) ed = max(ed, q[i].y);
        else
        {
            res += (b - a) * 2;
            st = q[i].x, ed = q[i].y;
        }
    res += (b - a) * 2;
    return res;
}

int get_len()
{
    vector<int> xs;
    for (int i = 0; i < n; i ++ )
    {
        xs.push_back(rect[i].a.x);
        xs.push_back(rect[i].b.x);
    }
    sort(xs.begin(), xs.end());
    int res = 0;
    for (int i = 0; i + 1 < xs.size(); i ++ )
        if (xs[i] != xs[i + 1])
            res += get_range_len(xs[i], xs[i + 1]);
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ )
    {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        rect[i] = {{x1, y1}, {x2, y2}};
    }
    int res = get_len();
    for (int i = 0; i < n; i ++ )
    {
        swap(rect[i].a.x, rect[i].a.y);
        swap(rect[i].b.x, rect[i].b.y);
    }
    cout << res + get_len() << endl;

    return 0;
}
//

const int N = 200010;

int n;
string s;

int get_min()
{
    int i = 0, j = 1;
    while (i < n && j < n)
    {
        int k = 0;
        while (k < n && s[i + k] == s[j + k]) k ++ ;
        if (k == n) break;
        if (s[i + k] > s[j + k]) i += k + 1;
        else j += k + 1;
        if (i == j) j ++ ;
    }
    return min(i, j);
}

int main()
{
    scanf("%d", &n);
    string line;
    while (cin >> line) s += line;
    s += s;
    printf("%d\n", get_min());
    return 0;
}

//

const int N = 6;

int f[N][N][N][N][N];
int p[30];
bool st[30];
int id[N][N];

bool check(int a, int b)
{
    return p[b] == -1 || p[b] == a;
}

int dp(int a, int b, int c, int d, int e, int k)
{
    if (k == 25) return 1;
    auto& v = f[a][b][c][d][e];
    if (v != -1) return v;
    v = 0;
    if (a < 5 && check(k, id[1][a + 1])) v += dp(a + 1, b, c, d, e, k + 1);
    if (b < a && check(k, id[2][b + 1])) v += dp(a, b + 1, c, d, e, k + 1);
    if (c < b && check(k, id[3][c + 1])) v += dp(a, b, c + 1, d, e, k + 1);
    if (d < c && check(k, id[4][d + 1])) v += dp(a, b, c, d + 1, e, k + 1);
    if (e < d && check(k, id[5][e + 1])) v += dp(a, b, c, d, e + 1, k + 1);
    return v;
}

void work1()
{
    int n;
    cin >> n;
    memset(p, -1, sizeof p);
    for (int i = 1; i <= 25; i ++ )
        for (int j = 0; j < 25; j ++ )
        {
            if (st[j]) continue;
            p[i] = j, st[j] = true;
            memset(f, -1, sizeof f);
            int t = dp(0, 0, 0, 0, 0, 0);
            if (t >= n) break;
            n -= t;
            p[i] = -1, st[j] = false;
        }

    string res;
    for (int i = 1; i <= 25; i ++ ) res += p[i] + 'A';
    cout << res << endl;
}

void work2()
{
    char str[30];
    cin >> str + 1;
    int res = 0;
    memset(p, -1, sizeof p);
    for (int i = 1; i <= 25; i ++ )
    {
        int u = str[i] - 'A';
        for (int j = 0; j < u; j ++ )
        {
            if (st[j]) continue;
            p[i] = j, st[j] = true;
            memset(f, -1, sizeof f);
            res += dp(0, 0, 0, 0, 0, 0);
            p[i] = -1, st[j] = false;
        }
        p[i] = u, st[u] = false;
    }
    cout << res + 1 << endl;
}

int main()
{
    for (int i = 1, k = 1; i <= 5; i ++ )
        for (int j = 1; j <= 5; j ++, k ++ )
            id[i][j] = k;

    char op;
    cin >> op;
    if (op == 'N') work1();
    else work2();

    return 0;
}
// above two five - last of section 5

//section 6
const int N = 1010, M = 1000;

int n;
int f[N][6][M];
int w[6][6] = {
    {1, 0, 1, 1, 0, 0},
    {0, 1, 0, 0, 1, 0},
    {0, 1, 0, 0, 1, 0},
    {0, 1, 0, 0, 1, 0},
    {1, 0, 1, 1, 0, 1},
    {0, 0, 0, 0, 1, 0},
};

void add(int a[], int b[])
{
    for (int i = 0, t = 0; i < M; i ++ )
    {
        t += a[i] + b[i];
        a[i] = t % 10;
        t /= 10;
    }
}

int main()
{
    cin >> n;
    f[1][4][0] = f[1][1][0] = 1;
    for (int i = 2; i < n; i ++ )
        for (int j = 0; j < 6; j ++ )
            for (int k = 0; k < 6; k ++ )
                if (w[k][j])
                    add(f[i][j], f[i - 1][k]);
    int res[M] = {0};
    add(res, f[n - 1][0]), add(res, f[n - 1][4]);
    add(res, res);
    int k = M - 1;
    while (k > 0 && !res[k]) k -- ;
    for (int i = k; i >= 0; i -- ) cout << res[i];
    cout << endl;
    return 0;
}

//

const int N = 3010;

int n, m;
int g[N][N], h[N][N];
int l[N], r[N], stk[N];

int work(int h[])
{
    int top = 0;
    for (int i = 1; i <= m; i ++ )
    {
        while (top && h[stk[top]] >= h[i]) top -- ;
        if (!top) l[i] = 0;
        else l[i] = stk[top];
        stk[ ++ top] = i;
    }
    top = 0;
    for (int i = m; i; i -- )
    {
        while (top && h[stk[top]] >= h[i]) top -- ;
        if (!top) r[i] = m + 1;
        else r[i] = stk[top];
        stk[ ++ top] = i;
    }
    int res = 0;
    for (int i = 1; i <= m; i ++ )
        res = max(res, h[i] * (r[i] - l[i] - 1));
    return res;
}

int main()
{
    int p;
    scanf("%d%d%d", &n, &m, &p);
    while (p -- )
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x][y] = 1;
    }
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            if (!g[i][j])
                h[i][j] = h[i - 1][j] + 1;

    int res = 0;
    for (int i = 1; i <= n; i ++ ) res = max(res, work(h[i]));
    printf("%d\n", res);

    return 0;
}

//
const int N = 100010;

int n;
int s[N], son[2100000][2], id[2100000], idx;

void insert(int x, int k)
{
    int p = 0;
    for (int i = 20; i >= 0; i -- )
    {
        int u = x >> i & 1;
        if (!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
    id[p] = k;
}

int search(int x)
{
    int p = 0;
    for (int i = 20; i >= 0; i -- )
    {
        int u = x >> i & 1;
        if (son[p][!u]) p = son[p][!u];
        else p = son[p][u];
    }
    return id[p];
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )
    {
        int x;
        scanf("%d", &x);
        s[i] = s[i - 1] ^ x;
    }

    int res = -1, a, b;
    insert(s[0], 0);
    for (int i = 1; i <= n; i ++ )
    {
        int k = search(s[i]);
        int t = s[i] ^ s[k];
        if (t > res) res = t, a = k + 1, b = i;
        insert(s[i], i);
    }
    printf("%d %d %d\n", res, a, b);
    return 0;
}

//

const int N = 20010;

int n, m;
char a[N], b[N];
int p[N];

int main()
{
    while ((a[n] = getchar()) != -1) n ++ ;

    for (int i = 0; i < n; i ++ )
    {
        char c = tolower(a[i]);
        if (c >= 'a' && c <= 'z')
        {
            b[m] = c;
            p[m] = i;
            m ++ ;
        }
    }

    int res = -1, l, r;
    for (int i = 0; i < m; i ++ )
    {
        for (int j = 0; i - j >= 0 && i + j < m && b[i - j] == b[i + j]; j ++ )
        {
            int len = j * 2 + 1;
            if (len > res) res = len, l = i - j, r = i + j;
        }
        for (int j = 0; i - j >= 0 && i + 1 + j < m && b[i - j] == b[i + 1 + j]; j ++ )
        {
            int len = j * 2 + 2;
            if (len > res) res = len, l = i - j, r = i + 1 + j;
        }
    }

    cout << res << endl;
    for (int i = p[l]; i <= p[r]; i ++ ) putchar(a[i]);
    return 0;
}

//

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
const int N = 4;

PII rt[N];
int p[N] = {0, 1, 2, 3};
vector<PII> ans;

void update(int a, int b)
{
    if (a > b) swap(a, b);
    if (ans.empty() || a * b < ans[0].x * ans[0].y) ans = {{a, b}};
    else if (a * b == ans[0].x * ans[0].y) ans.push_back({a, b});
}

void work()
{
    auto a = rt[p[0]], b = rt[p[1]], c = rt[p[2]], d = rt[p[3]];
    update(a.x + b.x + c.x + d.x, max(a.y, max(b.y, max(c.y, d.y))));
    update(max(a.x + b.x + c.x, d.x), d.y + max(a.y, max(b.y, c.y)));
    update(max(a.x + b.x, d.x) + c.x, max(max(a.y, b.y) + d.y, c.y));
    update(a.x + d.x + max(b.x, c.x), max(a.y, max(d.y, b.y + c.y)));
    update(max(a.x, d.x) + b.x + c.x, max(b.y, max(c.y, a.y + d.y)));
    if (b.x >= a.x && c.y >= b.y)
    {
        if (c.y < a.y + b.y)
        {
            if (d.x + a.x <= b.x + c.x) update(b.x + c.x, max(a.y + b.y, c.y + d.y));
        }
        else
        {
            update(max(d.x, b.x + c.x), c.y + d.y);
        }
    }
}

int main()
{
    for (int i = 0; i < 4; i ++ ) cin >> rt[i].x >> rt[i].y;

    for (int i = 0; i < 24; i ++ )
    {
        for (int j = 0; j < 16; j ++ )
        {
            for (int k = 0; k < 4; k ++ )
                if (j >> k & 1) swap(rt[p[k]].x, rt[p[k]].y);
            work();
            for (int k = 0; k < 4; k ++ )
                if (j >> k & 1) swap(rt[p[k]].x, rt[p[k]].y);
        }
        next_permutation(p, p + 4);
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    cout << ans[0].x * ans[0].y << endl;
    for (auto& a: ans) cout << a.x << ' ' << a.y << endl;

    return 0;
}
//



#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
const int N = 1010, M = 25010;

int A, B, n;
struct Rect
{
    PII a, b;
    int c;
}rt[N];
int ans[M];
int p[10010];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int draw(int a, int b)
{
    int res = 0;
    for (int i = find(a); i <= b; i = find(i))
    {
        p[i] = i + 1;
        res ++ ;
    }
    return res;
}

void get_range(int a, int b)
{
    for (int i = 1; i <= B + 1; i ++ ) p[i] = i;
    for (int i = n - 1; i >= 0; i -- )
    {
        auto& r = rt[i];
        if (r.a.x <= a && r.b.x >= b)
            ans[r.c] += draw(r.a.y + 1, r.b.y) * (b - a);
    }
    ans[1] += draw(1, B) * (b - a);
}

int main()
{
    scanf("%d%d%d", &A, &B, &n);
    vector<int> xs;
    for (int i = 0; i < n; i ++ )
    {
        int x1, y1, x2, y2, c;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        rt[i] = {{x1, y1}, {x2, y2}, c};
        xs.push_back(x1), xs.push_back(x2);
    }
    xs.push_back(0), xs.push_back(A);

    sort(xs.begin(), xs.end());
    for (int i = 0; i + 1 < xs.size(); i ++ )
        if (xs[i] != xs[i + 1])
            get_range(xs[i], xs[i + 1]);

    for (int i = 1; i < M; i ++ )
        if (ans[i])
            printf("%d %d\n", i, ans[i]);
    return 0;
}


const int N = 55, M = 1050;

int n, m;
int board[N], rail[M], sum[M], tot;
int mid;

bool dfs(int u, int start)
{
    if (!u) return true;
    if (tot < sum[u]) return false;
    if (u + 1 > mid || rail[u] != rail[u + 1]) start = 1;
    for (int i = start; i <= n; i ++ )
    {
        if (i > start && board[i] == board[i - 1]) continue;
        if (board[i] >= rail[u])
        {
            tot -= rail[u];
            board[i] -= rail[u];
            if (board[i] < rail[1]) tot -= board[i];
            if (dfs(u - 1, i))
            {
                if (board[i] < rail[1]) tot += board[i];
                board[i] += rail[u];
                tot += rail[u];
                return true;
            }
            if (board[i] < rail[1]) tot += board[i];
            board[i] += rail[u];
            tot += rail[u];
        }
    }
    return false;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> board[i], tot += board[i];
    cin >> m;
    for (int i = 1; i <= m; i ++ ) cin >> rail[i];
    sort(board + 1, board + n + 1);
    sort(rail + 1, rail + m + 1);
    for (int i = 1; i <= m; i ++ ) sum[i] = sum[i - 1] + rail[i];

    int l = 0, r = m;
    while (l < r)
    {
        mid = l + r + 1 >> 1;
        if (!dfs(mid, 1)) r = mid - 1;
        else l = mid;
    }
    cout << r << endl;
    return 0;
}

//


typedef unsigned long long ULL;
const int P = 131;

string target = "Begin the Escape execution at the Break of Dawn";
unordered_set<ULL> S, valid;

bool check1(string state)
{
    int c = 0, o = 0, w = 0;
    string a = target, b;
    for (auto x: state)
        if (x == 'C') c ++ ;
        else if (x == 'O') o ++ ;
        else if (x == 'W') w ++ ;
        else b += x;
    sort(a.begin(), a.end()), sort(b.begin(), b.end());
    return a == b;
}

ULL get_hash(string state)
{
    ULL res = 0;
    for (auto c: state) res = res * P + c;
    return res;
}

bool check2(string state)
{
    if (state.size() == target.size()) return false;
    int l = 0, r = state.size() - 1;
    while (state[l] != 'C' && state[l] != 'O' && state[l] != 'W') l ++ ;
    while (state[r] != 'C' && state[r] != 'O' && state[r] != 'W') r -- ;
    if (state[l] != 'C' || state[r] != 'W') return false;
    if (state.substr(0, l) != target.substr(0, l)) return false;
    if (state.substr(r + 1) != target.substr(target.size() - (state.size() - r - 1))) return false;
    string s;
    for (int i = l + 1; i <= r; i ++ )
    {
        auto c = state[i];
        if (c == 'C' || c == 'O' || c == 'W')
        {
            if (valid.count(get_hash(s)) == 0) return false;
            s.clear();
        }
        else s += c;
    }
    return true;
}

bool dfs(string state)
{
    if (state == target) return true;
    if (!check2(state)) return false;
    auto h = get_hash(state);
    if (S.count(h)) return false;
    S.insert(h);

    for (int o = 0; o < state.size(); o ++ )
    {
        if (state[o] != 'O') continue;
        for (int c = 0; c < o; c ++ )
        {
            if (state[c] != 'C') continue;
            for (int w = o + 1; w < state.size(); w ++ )
            {
                if (state[w] != 'W') continue;
                auto s1 = state.substr(0, c), s2 = state.substr(c + 1, o - c - 1);
                auto s3 = state.substr(o + 1, w - o - 1), s4 = state.substr(w + 1);
                if (dfs(s1 + s3 + s2 + s4)) return true;
            }
        }
    }
    return false;
}

int main()
{
    valid.insert(0);
    for (int i = 0; i < target.size(); i ++ )
        for (int j = i; j < target.size(); j ++ )
            valid.insert(get_hash(target.substr(i, j - i + 1)));

    string start;
    getline(cin, start);
    if (!check1(start)) puts("0 0");
    else if (!dfs(start)) puts("0 0");
    else cout << 1 << ' ' << (start.size() - target.size()) /  3 << endl;

    return 0;
}
//


const int N = 100010, M = 10;

int n, m;
int primes[N], cnt;
bool st[N];
vector<int> c1[M], c3[M], c15[M][M], c124[M][M][M];
int g[6][6];
vector<string> ans;

int get(int x, int k)
{
    int t = 1;
    for (int i = 0; i < 5 - k; i ++ ) t *= 10;
    return x / t % 10;
}

void init()
{
    for (int i = 2; i < N; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] * i < N; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }

    for (int i = 0; i < cnt; i ++ )
    {
        int p = primes[i];
        if (p < 10000 || p > 99999) continue;
        int n1 = get(p, 1), n2 = get(p, 2), n3 = get(p, 3), n4 = get(p, 4), n5 = get(p, 5);
        if (n1 + n2 + n3 + n4 + n5 != n) continue;
        c1[n1].push_back(p);
        c3[n3].push_back(p);
        if (n2 && n3 && n4)
            c15[n1][n5].push_back(p);
        c124[n1][n2][n4].push_back(p);
    }
}

bool check(int x1, int y1, int x2, int y2)
{
    int s = 0;
    for (int i = x1; i <= x2; i ++ )
        for (int j = y1; j <= y2; j ++ )
        {
            int x = g[i][j];
            if (x < 0 || x > 9) return false;
            s = s * 10 + x;
        }
    return !st[s];
}

void dfs(int u)
{
    if (u > 7)
    {
        g[3][5] = n - g[3][1] - g[3][2] - g[3][3] - g[3][4];
        g[4][5] = n - g[1][5] - g[2][5] - g[3][5] - g[5][5];
        g[4][3] = n - g[4][1] - g[4][2] - g[4][4] - g[4][5];
        g[5][3] = n - g[5][1] - g[5][2] - g[5][4] - g[5][5];

        if (check(1, 3, 5, 3) && check(1, 5, 5, 5) && check(3, 1, 3, 5) &&
            check(4, 1, 4, 5) && check(5, 1, 5, 5))
        {
            string s;
            for (int i = 1; i <= 5; i ++ )
                for (int j = 1; j <= 5; j ++ )
                    s += to_string(g[i][j]);
            ans.push_back(s);
        }
        return;
    }
    if (u == 1)
    {
        for (auto x: c1[g[1][1]])
        {
            g[2][2] = get(x, 2), g[3][3] = get(x, 3), g[4][4] = get(x, 4), g[5][5] = get(x, 5);
            dfs(u + 1);
        }
    }
    else if (u == 2)
    {
        for (auto x: c3[g[3][3]])
        {
            g[5][1] = get(x, 1), g[4][2] = get(x, 2), g[2][4] = get(x, 4), g[1][5] = get(x, 5);
            dfs(u + 1);
        }
    }
    else if (u == 3)
    {
        for (auto x: c15[g[1][1]][g[1][5]])
        {
            g[1][2] = get(x, 2), g[1][3] = get(x, 3), g[1][4] = get(x, 4);
            dfs(u + 1);
        }
    }
    else if (u == 4)
    {
        for (auto x: c124[g[1][2]][g[2][2]][g[4][2]])
        {
            g[3][2] = get(x, 3), g[5][2] = get(x, 5);
            dfs(u + 1);
        }
    }
    else if (u == 5)
    {
        for (auto x: c124[g[1][4]][g[2][4]][g[4][4]])
        {
            g[3][4] = get(x, 3), g[5][4] = get(x, 5);
            dfs(u + 1);
        }
    }
    else if (u == 6)
    {
        for (auto x: c15[g[1][1]][g[5][1]])
        {
            g[2][1] = get(x, 2), g[3][1] = get(x, 3), g[4][1] = get(x, 4);
            dfs(u + 1);
        }
    }
    else
    {
        for (auto x: c124[g[2][1]][g[2][2]][g[2][4]])
        {
            g[2][3] = get(x, 3), g[2][5] = get(x, 5);
            dfs(u + 1);
        }
    }
}

int main()
{
    cin >> n >> m;
    init();

    g[1][1] = m;
    dfs(1);

    if (ans.empty()) puts("NONE");
    else
    {
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i ++ )
        {
            for (int j = 0; j < 25; j ++ )
            {
                cout << ans[i][j];
                if ((j + 1) % 5 == 0) cout << endl;
            }
            if (i + 1 < ans.size()) cout << endl;
        }
    }

    return 0;
}

//

#define x first
#define y second

using namespace std;

typedef pair<double, double> PDD;
const int N = 160;
const double eps = 1e-6;

int n;
struct Segment
{
    PDD a, b;
}seg[N];

double get_dist(PDD a, PDD b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double f(double x, double y)
{
    double s = 0;
    for (int i = 0; i < n; i ++ )
    {
        auto a = seg[i].a, b = seg[i].b;
        double da = get_dist({x, y}, a);
        double db = get_dist({x, y}, b);
        double d = min(da, db);
        if (x >= a.x && x <= b.x) d = fabs(y - a.y);
        else if (y >= a.y && y <= b.y) d = fabs(x - a.x);
        s += d;
    }
    return s;
}

double g(double x, double& y)
{
    double l = 0, r = 100;
    while (r - l > eps)
    {
        double m1 = l + (r - l) / 3, m2 = l + (r - l) / 3 * 2;
        if (f(x, m1) >= f(x, m2)) l = m1;
        else r = m2;
    }
    y = r;
    return f(x, y);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ )
    {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        seg[i] = {{x1, y1}, {x2, y2}};
    }

    double l = 0, r = 100, y;
    while (r - l > eps)
    {
        double m1 = l + (r - l) / 3, m2 = l + (r - l) / 3 * 2;
        if (g(m1, y) >= g(m2, y)) l = m1;
        else r = m2;
    }

    double d = f(r, y);
    printf("%.1lf %.1lf %.1lf\n", r, y, d);

    return 0;
}

//

const int N = 5;

char g[N][N];
int num[] = {3, 3, 3, 4, 3};
bool st[N][N];
int ans;
struct Node
{
    char c;
    int a, b;
}path[N * N];

bool check(int a, int b, char c)
{
    for (int i = a - 1; i <= a + 1; i ++ )
        for (int j = b - 1; j <= b + 1; j ++ )
            if (i >= 0 && i < 4 && j >= 0 && j < 4 && g[i][j] == c)
                return false;
    return true;
}

void dfs(char c, int u)
{
    if (u == 16)
    {
        ans ++ ;
        if (ans == 1)
        {
            for (int i = 0; i < 16; i ++ )
                cout << path[i].c << ' ' << path[i].a + 1 << ' ' << path[i].b + 1 << endl;
        }
        return;
    }

    for (int i = 0; i < 4; i ++ )
        for (int j = 0; j < 4; j ++ )
            if (!st[i][j] && check(i, j, c))
            {
                st[i][j] = true;
                char t = g[i][j];
                g[i][j] = c;
                path[u] = {c, i, j};
                num[c - 'A'] -- ;
                if (u == 15) dfs('A', u + 1);
                else
                {
                    for (int k = 0; k < 5; k ++ )
                        if (num[k] > 0)
                            dfs(k + 'A', u + 1);
                }
                num[c - 'A'] ++ ;
                g[i][j] = t;
                st[i][j] = false;
            }
}

int main()
{
    for (int i = 0; i < 4; i ++ ) cin >> g[i];
    dfs('D', 0);
    cout << ans << endl;
    return 0;
}

//


typedef long long LL;
const int N = 10;

int n;
int g[N][N];
bool row[N][N], col[N][N];
map<vector<int>, int> f;

void put(int x, int y, int k)
{
    g[x][y] = k;
    row[x][k] = true;
    col[y][k] = true;
}

void unput(int x, int y)
{
    int k = g[x][y];
    row[x][k] = false;
    col[y][k] = false;
    g[x][y] = 0;
}

int dfs(int x, int y)
{
    if (y > n) x ++ , y = 2;
    if (x == n) return 1;

    if (x == 3 && y == 2)
    {
        vector<int> line;
        bool st[N] = {0};
        for (int i = 1; i <= n; i ++ )
        {
            if (st[i]) continue;
            int s = 0;
            for (int j = i; !st[j]; j = g[2][j])
            {
                s ++ ;
                st[j] = true;
            }
            line.push_back(s);
        }
        sort(line.begin(), line.end());
        if (f.count(line)) return f[line];
        int res = 0;
        for (int i = 1; i <= n; i ++ )
            if (!row[x][i] && !col[y][i])
            {
                put(x, y, i);
                res += dfs(x, y + 1);
                unput(x, y);
            }
        return f[line] = res;
    }

    int res = 0;
    for (int i = 1; i <= n; i ++ )
        if (!row[x][i] && !col[y][i])
        {
            put(x, y, i);
            res += dfs(x, y + 1);
            unput(x, y);
        }
    return res;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        put(1, i, i);
        put(i, 1, i);
    }

    LL res = dfs(2, 2);
    for (int i = 1; i <= n - 1; i ++ ) res *= i;
    cout << res << endl;

    return 0;
}
//

#define x first
#define y second

using namespace std;

typedef pair<double, double> PDD;
typedef pair<int, int> PII;
const int N = 210;
const double eps = 1e-8, INF = 1e8;

int n;
PDD q[N];
vector<PII> ans;

int sign(double x)
{
    if (fabs(x) < eps) return 0;
    if (x < 0) return -1;
    return 1;
}

int dcmp(double x, double y)
{
    if (fabs(x - y) < eps) return 0;
    if (x < y) return -1;
    return 1;
}

PDD operator+ (PDD a, PDD b)
{
    return {a.x + b.x, a.y + b.y};
}

PDD operator- (PDD a, PDD b)
{
    return {a.x - b.x, a.y - b.y};
}

PDD operator* (PDD a, double t)
{
    return {a.x * t, a.y * t};
}

double operator* (PDD a, PDD b)
{
    return a.x * b.y - a.y * b.x;
}

double operator& (PDD a, PDD b)
{
    return a.x * b.x + a.y * b.y;
}

PDD rotate(PDD a, double b)
{
    return {a.x * cos(b) + a.y * sin(b), -a.x * sin(b) + a.y * cos(b)};
}

double area(PDD a, PDD b, PDD c)
{
    return (b - a) * (c - a);
}

PDD get_line_intersection(PDD p, PDD v, PDD q, PDD w)
{
    auto u = p - q;
    auto t = (w * u) / (v * w);
    return p + v * t;
}

bool is_seg_intersection_1d(double a, double b, double c, double d)
{
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    if (dcmp(b, c) < 0 || dcmp(d, a) < 0) return false;
    return true;
}

bool is_seg_intersection(PDD a, PDD b, PDD c, PDD d)
{
    if (!is_seg_intersection_1d(a.x, b.x, c.x, d.x)) return false;
    if (!is_seg_intersection_1d(a.y, b.y, c.y, d.y)) return false;

    return sign(area(a, b, c)) * sign(area(a, b, d)) <= 0 &&
        sign(area(c, d, a)) * sign(area(c, d, b)) <= 0;
}

bool is_seg_intersection2(PDD a, PDD b, PDD c)
{
    if (sign(area(a, b, c))) return false;
    return sign((a - b) & (c - b)) > 0;
}

bool on_segment(PDD p, PDD a, PDD b)
{
    return sign((p - a) & (p - b)) <= 0;
}

void see(PDD a, PDD b)
{
    int id = -1;
    double mind = INF;
    for (int i = 0; i < n; i ++ )
    {
        auto c = q[i], d = q[(i + 1) % n];
        if (!sign(b * (d - c))) continue;
        auto o = get_line_intersection(a, b, c, d - c);
        if (!on_segment(o, c, d)) continue;
        auto t = (o - a) & b;
        if (sign(t) <= 0) continue;
        if (t < mind) id = i, mind = t;
    }
    if (id != -1)
        ans.push_back({id, (id + 1) % n});
}

int main()
{
    cin >> n;
    PDD source;
    cin >> source.x >> source.y;
    set<PDD> S;
    for (int i = 0; i < n; i ++ )
    {
        cin >> q[i].x >> q[i].y;
        if (S.count(q[i]))
        {
            puts("NOFENCE");
            return 0;
        }
        S.insert(q[i]);
    }

    for (int i = 0; i < n; i ++ )
    {
        auto a = q[i], b = q[(i + 1) % n];
        for (int j = 0; j < n - 3; j ++ )
        {
            auto c = q[(i + j + 2) % n], d = q[(i + j + 3) % n];
            if (is_seg_intersection(a, b, c, d))
            {
                puts("NOFENCE");
                return 0;
            }
        }
        auto c = q[(i + 2) % n], d = q[(i + n - 1) % n];
        if (is_seg_intersection2(a, b, c) || is_seg_intersection2(b, a, d))
        {
            puts("NOFENCE");
            return 0;
        }
    }

    for (int i = 0; i < n; i ++ )
    {
        auto r = q[i] - source;
        auto a = rotate(r, 1e-4), b = rotate(r, -1e-4);
        see(source, a), see(source, b);
    }

    for (auto& p: ans)
        if (p.x < p.y)
            swap(p.x, p.y);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << endl;
    for (auto p: ans)
        printf("%.0lf %.0lf %.0lf %.0lf\n", q[p.y].x, q[p.y].y, q[p.x].x, q[p.x].y);

    return 0;
}

//


const int N = 10;

int n;
bool st[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

bool check(int x, int y)
{
    int cnt = 0;
    for (int i = 0; i < 4; i ++ )
    {
        int a = x + dx[i], b = y + dy[i];
        if (!st[a][b])
            cnt ++ ;
    }
    return cnt <= 1;
}

int dfs(int x, int y, int u)
{
    if (x == n && y == 1)
    {
        if (u == n * n) return 1;
        return 0;
    }

    if (st[x - 1][y] && st[x + 1][y] && !st[x][y - 1] && !st[x][y + 1] ||
        st[x][y - 1] && st[x][y + 1] && !st[x - 1][y] && !st[x + 1][y])
        return 0;

    int cnt = 0, sx, sy;
    for (int i = 0; i < 4; i ++ )
    {
        int a = x + dx[i], b = y + dy[i];
        if (!(a == n && b == 1) && !st[a][b] && check(a, b))
        {
            cnt ++ ;
            sx = a, sy = b;
        }
    }

    int res = 0;
    if (cnt > 1) return 0;
    else if (cnt == 1)
    {
        st[sx][sy] = true;
        res += dfs(sx, sy, u + 1);
        st[sx][sy] = false;
    }
    else
    {
        for (int i = 0; i < 4; i ++ )
        {
            int a = x + dx[i], b = y + dy[i];
            if (!st[a][b])
            {
                st[a][b] = true;
                res += dfs(a, b, u + 1);
                st[a][b] = false;
            }
        }
    }
    return res;
}

int main()
{
    cin >> n;
    for (int i = 0; i <= n + 1; i ++ )
        st[i][0] = st[i][n + 1] = st[0][i] = st[n + 1][i] = true;

    st[1][1] = true;
    cout << dfs(1, 1, 1) << endl;
    return 0;
}

//

const int N = 10;

int g[N];
vector<int> ans, path;
string ops[9] = {
    "ABDE", "ABC", "BCEF", "ADG", "BDEFH",
    "CFI,", "DEGH", "GHI", "EFHI"
};

bool check()
{
    for (int i = 0; i < 9; i ++ )
        if (g[i] != 12)
            return false;
    return true;
}

void rotate(int u)
{
    for (auto c: ops[u])
    {
        int k = c - 'A';
        g[k] += 3;
        if (g[k] == 15) g[k] = 3;
    }
}

void dfs(int u)
{
    if (u == 9)
    {
        if (check())
        {
            if (ans.empty() || ans.size() > path.size() ||
                ans.size() == path.size() && ans > path)
                ans = path;
        }
        return;
    }

    for (int i = 0; i < 4; i ++ )
    {
        dfs(u + 1);
        path.push_back(u + 1);
        rotate(u);
    }

    for (int i = 0; i < 4; i ++ ) path.pop_back();
}

int main()
{
    for (int i = 0; i < 9; i ++ ) cin >> g[i];
    dfs(0);

    for (auto x: ans) cout << x << ' ';
    cout << endl;

    return 0;
}
//

const int N = 15;

int n;
bool col[N], d[N * 2], ud[N * 2];
int ans, path[N];

void dfs(int x)
{
    if (x > n)
    {
        ans ++ ;
        if (ans <= 3)
        {
            for (int i = 1; i <= n; i ++ ) cout << path[i] << ' ';
            cout << endl;
        }
        return;
    }

    for (int y = 1; y <= n; y ++ )
        if (!col[y] && !d[x + y] && !ud[x - y + n])
        {
            col[y] = d[x + y] = ud[x - y + n] = true;
            path[x] = y;
            dfs(x + 1);
            col[y] = d[x + y] = ud[x - y + n] = false;
        }
}

int main()
{
    cin >> n;
    dfs(1);
    cout << ans << endl;
    return 0;
}




```
