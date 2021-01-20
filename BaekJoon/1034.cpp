#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n,m,k,ret=0,cnt0,cntRow;
    string s[50];
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> s[i];
    cin >> k;

    for(int i=0;i<n;i++){
        cntRow=cnt0=0;
        for(int j=0;j<m;j++){
            cnt0+= s[i][j]=='0'?1:0;
        }
        if(cnt0<=k && cnt0%2==k%2){
            for(int k=0;k<n;k++){
                cntRow+= s[i]==s[k]?1:0;
            }
            ret=max(ret,cntRow);
        }
    }
    cout << ret;
}