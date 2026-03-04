#include <iostream>
#include <vector>
using namespace std;

bool prim(int x) {
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}


void generare(int n) {
    int count=0;
    int numar=2;

    while (count<n) {
        if (prim(numar)) {
            cout<<numar<<" ";
            count++;
        }
        numar++;
    }

    cout<<endl;
}


int gcd(int a,int b) {
    while (b!= 0) {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}


void subsecventaRelativPrime() {
    int n;
    cout<<"Numar elemente vector: ";
    cin>>n;

    int v[n];


    for (int i=0;i<n;i++) {
        cout<<"Introduceti elementele:";
        cin>>v[i];
    }

    int maxm=1;
    int len=1;
    int start=0;
    int bests=0;

    for (int i=1;i<n;i++) {
        if (gcd(v[i], v[i - 1])==1) {
            len++;
        } else {
            if (len>maxm) {
                maxm=len;
                bests=start;
            }
            len=1;
            start=i;
        }
    }

    if (len>maxm) {
        maxm=len;
        bests=start;
    }

    cout << "Cea mai lunga subsecventa este:";
    for (int i=bests;i<bests+maxm;i++) {
        cout << v[i] << " ";
    }

    cout << endl;
}

int main() {
    int n;
    cout <<"Introduceti n: ";
    cin >> n;

    generare(n);
    subsecventaRelativPrime();

    return 0;
}