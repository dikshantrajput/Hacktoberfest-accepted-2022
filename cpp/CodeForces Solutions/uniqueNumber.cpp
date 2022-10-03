#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, robin;
        cin >> n;
        robin = n;
        if (robin < 10) cout << n << endl;
        else if (robin > 45) cout << "-1" << endl;
        else
        {
            vector<int> luffy;
            int sum = 0,b;
            for (int i = 9; i > 0; i--)
            {
                if (robin > 0 && sum < n)
                {
                    b=min(n-sum,i);
                    luffy.push_back(b);
                    robin = robin - i;
                    sum += i;
                }
                else
                {
                    break;
                }
            }
            if(sum<n) cout<<"-1"<<endl;
            else {
                reverse(luffy.begin(), luffy.end());
                for (int j = 0; j < luffy.size(); j++)
                {
                    cout<<luffy[j];                    
                }
                cout<<"\n";
            }
        }
    }
    return 0;
}
