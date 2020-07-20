

#include <bits/stdc++.h> 
using namespace std;

int solve(string,int ,int ,bool);
int main()
{
string s="T^F&T";
int n=s.length();
//cout<<n;
int res=solve(s,0,n-1,true);
cout<<"the number of ways is \n"<<res;
return 0;
}
int solve(string s,int i,int j,bool isTrue)
{
   
    if(i>j)
    return 0;
  if(i==j)
{
if (isTrue==true)
 
 return s[i]=='T';
 else
 return  s[i]=='F';
}
int ans=0; 
for(int k=i+1;k<=j-1;k=k+2)
{
int LT=solve(s,i,k-1,true);
int LF=solve(s,i,k-1,false);
int RT=solve(s,k+1,j,true);
int RF=solve(s,k+1,j,false);

if(s[k]=='&')
{
if(isTrue==true)
ans=ans+(LT*RT);
else
ans=ans + (LT*RF) + (LF*RT) + (LF*RF);
}

if(s[k]=='|')
{
if(isTrue==true)
ans=ans+(LT*RT)+(LT*RF) + (LF*RT);
else
ans=ans +( LF*RF);
}

if(s[k]=='^')
{
if(isTrue==true)
ans=ans+(LF*RT)+(LT*RF);
else
ans=ans + LF*RF +LT*RT;
}

}

return ans;
}
