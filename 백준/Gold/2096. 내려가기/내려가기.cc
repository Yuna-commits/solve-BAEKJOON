#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;


void solution(){

    int n;
    int maxV, minV;
    int mind[3] = {0, };
    int maxd[3] = {0, };
    int input[3] = {0, };


    cin >> n;

    cin >> maxd[0] >> maxd[1] >> maxd[2];
    mind[0] = maxd[0];
    mind[1] = maxd[1];
    mind[2] = maxd[2];

    for (int i = 1; i < n; i++){
        cin >> input[0] >> input[1] >> input[2];

        int temp0 = maxd[0];
        int temp1 = maxd[1];
        int temp2 = maxd[2];

        maxd[0] = max(temp0, temp1) + input[0];
        maxd[1] = max(temp0, max(temp1, temp2)) + input[1];
        maxd[2] = max(temp1, temp2) + input[2];

        temp0 = mind[0];
        temp1 = mind[1];
        temp2 = mind[2];

        mind[0] = min(temp0, temp1) + input[0];
        mind[1] = min(temp0, min(temp1, temp2)) + input[1];
        mind[2] = min(temp1, temp2) + input[2];

        

    }

    maxV = max(maxd[0], max(maxd[1], maxd[2]));
    minV = min(mind[0], min(mind[1], mind[2]));

   

    cout << maxV << " " << minV << '\n';
}
int main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}