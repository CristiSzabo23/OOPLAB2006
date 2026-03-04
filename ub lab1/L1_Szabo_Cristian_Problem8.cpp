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

void zwilling() {
    int n;
    cout << "Introduceti n:";
    if (!(cin >> n) || n <= 0) return;

    int c=0,p=2;
    while (c<n) {
        if (prim(p) && prim(p+2)) {
            cout << "("<<p<<","<< p+2<<") ";
            c++;
        }
        p++;
    }
    cout << endl;
}

void descrescatoare() {
    int n;
    cout<<"Numarul de numere in vector:";
    cin>>n;
    int v[n];
    for (int &x : v) {
        cout<<"Adaugati numarul in vector:";
        cin >> x;
    }

    int best=1,m=1,end=0;

    for (int i =1; i<n;i++) {
        if (v[i]<v[i-1]) m++;
        else m=1;

        if (m>best) {
            best=m;
            end=i;
        }
    }

    for (int i=end-best+1;i<=end;i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

int main() {
    zwilling();
    descrescatoare();
}