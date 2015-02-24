/* bhupkas */
 
using namespace std;
 
#include "bits/stdc++.h"
/*
struct node
{
        int x ;
        bool operator < (const struct node & other)     const {return x < other.x ;}
};
 
typedef struct node Node;
*/

long long  A[10005];
multiset < long long int > s;
multiset < long long int > :: iterator it;
int main()
{
        int t;
        cin >> t;
        while(t--)
        {
                s.clear();
                int n;
                
                long long int x;
                scanf("%d",&n);
                for(int i = 0 ; i < n ; ++i)
                {
                        scanf("%lld",&x);
                        A[i] = x;
                        s.insert(x);
                        it = s.find(x);
                        it++;
                        if(it != s.end())       s.erase(it);
                }
                int len = s.size();
                s.clear();
                long long int foo = -1;
                for(int i = 0 ; i < n ; ++i)
                {
                        x = A[i];
                        s.insert(x);
                        it = s.find(x);
                        it++;
                        if(it != s.end())       
                        {
                                if(s.size() == len + 1)     foo = max(foo , *it);       
                                s.erase(it);
                        }
                        else    
                        {
                                it = s.end();
                                it--;
                                foo = max(foo,*it);
                        }
                }
                printf("%lld\n", foo - *s.begin());                
        }
        return 0;
} 
