#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;
class MedianFinder{
public:
priority_queue<int> left;
priority_queue<int,vector<int> , greater<int>> right;
MedianFinder(){}
void addnum(int num){
    if(left.size() == right.size()){
       right.push(num);
       left.push(right.top());
       right.pop(); 
    } else {
        left.push(num);
        right.push(left.top());
        left.pop();
    }
}
double FindMedian(){
    if(left.size() == right.size()){
        return (left.top() + right.top())/2.0;
    } else {
        return left.top()*1.0;
    }
}
};
int main(){
    MedianFinder mf;

    mf.addnum(10);
    cout << mf.FindMedian() << endl;

    mf.addnum(20);
    cout << mf.FindMedian() << endl;

    mf.addnum(30);
    cout << mf.FindMedian() << endl;

    mf.addnum(40);
    cout << mf.FindMedian() << endl;
return 0;
}