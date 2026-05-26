#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Pair{

public:

    int a;
    int b;

    Pair(int x,int y){

        a = x;
        b = y;
    }
};

bool increasing(Pair p1, Pair p2){

    return p1.a < p2.a;
}

bool decreasing(Pair p1, Pair p2){

    return p1.a > p2.a;
}

int main(){

    vector<Pair> arr;

    arr.push_back(Pair(10,3));
    arr.push_back(Pair(20,6));
    arr.push_back(Pair(15,8));
    arr.push_back(Pair(5,4));

    // Increasing order
    sort(arr.begin(), arr.end(), increasing);

    cout << "Increasing Order:\n";

    for(Pair p : arr){

        cout << "(" << p.a << "," << p.b << ") ";
    }

    cout << endl;

    // Decreasing order
    sort(arr.begin(), arr.end(), decreasing);

    cout << "Decreasing Order:\n";

    for(Pair p : arr){

        cout << "(" << p.a << "," << p.b << ") ";
    }

    return 0;
}