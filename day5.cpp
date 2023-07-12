//codechef - https://www.codechef.com/START98D/problems/FINDK3
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t-->0){
	    int x, y, z;
	    cin>>x>>y>>z;
	    int a = -1, b = -1;
	    if(x == y || x == z){
	        cout << a << " " << b << endl;
            continue;
	    }
	    if(x == y*z){
	       a = y*z;
	       b = x;
	    }else if(y == x*z){
	        a = x*z;
	        b = y;
	    }else if(z == x*y){
	        a = x*y;
	        b = z;
	    }
	    cout<<a<<" "<<b<<endl;
	}
	return 0;
}

//codechef - https://www.codechef.com/START98D/problems/AIRM
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arrival[n], departure[n];
        for (int i = 0; i < n; i++)
            cin >> arrival[i];

        for (int i = 0; i < n; i++)
            cin >> departure[i];

        sort(arrival, arrival + n);
        sort(departure, departure + n);

        int runwaysNeeded = 1, maxRunways = 1;
        int i = 1, j = 0;

        while (i < n && j < n) {
            if (arrival[i] <= departure[j]) {
                runwaysNeeded++;
                i++;
            } else {
                runwaysNeeded--;
                j++;
            }

            maxRunways = max(maxRunways, runwaysNeeded);
        }

        cout << maxRunways << endl;
    }

    return 0;
}

// codechef - https://www.codechef.com/START98D/problems/MVR
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int g1, a1, g2, a2;
	cin>>g1>>a1>>g2>>a2;
	if(g1*2 + a1 > g2*2 + a2){
	    cout<<"MESSI"<<endl;
	}else if(g1*2 + a1 < g2*2 + a2){
	    cout<<"RONALDO"<<endl;
	}else{
	    cout<<"EQUAL"<<endl;
	}
	return 0;
}

//