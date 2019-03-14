#include<iostream>
#include<string>
#define N 1001
using namespace std;

string dp[N];

string string_reverse(string s){
    string r;
    r.resize(s.length());
    for(int i=s.length()-1;i>=0;i--)
        r[i] = s[s.length()-1-i];
    return r;

}
string add(string s1,string s2){
    int l = max(s1.length(),s2.length());
    s1 = string_reverse(s1);
    s2 = string_reverse(s2);

    string r;
    r.resize(l+1);
    for(int i=0;i<=l;i++)
        r[i] = (i<s1.length()?s1[i]-'0':0) + (i<s2.length()?s2[i]-'0':0);


    for(int i=0;i<=l;i++){

        if(r[i]>=10){
            r[i+1]++;
            r[i]-=10;
        }

        r[i]+='0';
    }

    r = string_reverse(r);

    if(r[0]=='0'){
        string temp = r;
        r.resize(l);
        for(int i=0;i<l;i++)
            r[i] = temp[i+1];
    }

    return r;

}

int main(){
    dp[1] = "2";
    dp[2] = "5";
    dp[3] = "13";


    for(int i=4;i<N;i++){
        string t1,t2;
        t1 = add(dp[i-1],dp[i-1]);
        t2 = add(dp[i-2],dp[i-3]);
        dp[i] = add(t1,t2);
    }
    int in;
    while(cin>>in)
        cout<<dp[in]<<endl;

    return 0;
}
