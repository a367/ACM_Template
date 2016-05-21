#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <deque>
#include <bitset>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <vector>
using namespace std;
#define ULL unsigned long long int
#define LL long long int
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR1(i,n) for(int i=1;i<=n;i++)
#define sspend ios_base::sync_with_stdio(0);cin.tie(0)
const double pi = 3.141592654;
const double esp = 1e-16;
const LL mod = 1e9 + 7;
//cout << setiosflags(ios::fixed) << setprecision(2);


int main()
{
    sspend;
    vector<bitset<100000>> vec;
    queue<int> que;
    int N, M;
    cin >> N >> M;
    while(M--)
    {
        int a, b, pos = -1;
        cin >> a >> b;
        FOR(i, vec.size())
        {
            if (vec[i].test(a) || vec[i].test(b))
            {
                if (pos!=-1)
                {
                    vec[pos] |= vec[i];
                    vec[i].reset();
                    que.push(i);
                    break;
                }
                else
                {
                    vec[i].set(a);
                    vec[i].set(b);
                    pos = i;
                }
            }
        }
        if (pos == -1)
        {
            if(que.empty())
            {
                bitset<100000> bit;
                bit.set(a);
                bit.set(b);

                vec.push_back(bit);    
            }
            else
            {
                vec[que.front()].set(a);
                vec[que.front()].set(b);
                que.pop();
            }
            
        }
    }
    bitset<100000> bit;
    int count0=0;
    FOR(i, vec.size())
    {
        if(bit.none())
            count0++;
        else
            bit |= vec[i];
    }
    cout << (N - bit.count() + vec.size() - count0) << endl;
    system("pause");
    return 0;
}