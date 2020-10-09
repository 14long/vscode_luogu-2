#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> q;
    q.push_back(1);
    q.push_back(2);
    q.erase(q.begin());
    cout<<q.front()<<endl;
    return 0;
}