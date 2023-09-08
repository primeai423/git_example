#include<iostream>
#include<map>

using namespace std;

const int N = 1000000;
int n;
int stockprices[N];
int ans[N];
multimap<int, int>table;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>stockprices[i];
    }
    for(int i=0;i<n;i++){
        for(auto iter=table.begin();iter!=table.end();){
            if(iter->first<stockprices[i]){
                ans[iter->second]=i-iter->second;
                table.erase(iter++);
            }
            else break;
        }
        table.insert(pair<int,int>(stockprices[i],i));
    }
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
    return 0;
}