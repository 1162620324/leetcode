#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int n, x, y, z;
    cin >> n >> x >> y >> z;

    int cnt = 0;
    int upNum_a = n / x + 1, upNum_b = 1, upNum_c = 1;

    for (int i = 0; i <= upNum_a; i ++){
        upNum_b += ((n - i * x) / y);
        for(int j = 0; j <= upNum_b; j ++){
            int rem = n - i * x - j * y;
            if (rem >= 0 && rem % z == 0){
                 cnt ++;
            }
        }
    }

    cout << cnt;
}




// int main()
// {
//     int n, m;

//     scanf ("%d%d", &n, &m);
//     for (int i = 0; i < n; i ++) scanf ("%d", &h[i]);

//     while(m --)
//     {
//         int order, k;
//         cin >> order >> k;
//         if ( order == 1 )
//             sort(h, h + k);
//         else
//             sort(h, h + k, greater<int>());
//     }

//     for (int i = 0; i < n; i ++) printf("%d ", h[i]);

//     return 0;
// }
