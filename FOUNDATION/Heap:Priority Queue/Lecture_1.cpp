#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;
int main(){
// BY deafult in cpp this priority queue give the highest value occurence
priority_queue<int> pq;
pq.push(10);
pq.push(90);
pq.push(99);
pq.push(60);
pq.push(80);
pq.push(20);
// pq.pop();
cout<<pq.top()<<endl;

// min heap priority queue
priority_queue<int,vector<int> , greater<int>> qr;
qr.push(10);
qr.push(90);
qr.push(99);
qr.push(60);
qr.push(80);
qr.push(20);
cout<<qr.top()<<endl;
return 0;
 }