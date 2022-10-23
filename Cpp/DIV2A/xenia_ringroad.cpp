#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    int position = 1;
    long long int count = 0;
    for(int i=0; i<m; i++)
    {
        int present;
        scanf("%d", &present);

        if(present >= position){
            count += present - position;
        }
        else{
            count += n - (position - present);
        position = present;
        }
    }

    cout << count << endl;

    return 0;
}