#include <iostream>
#include <cstring>
using namespace std;
main()
{
	int n,t,i,j,k,l; char p[4];
	cin>>n;
	i=0; j=0; k=0; l=1;
	while(n--)
	{
		cin>>p;
		if(p[2]=='2')j++;
		else if(p[0]=='1'&&p[2]=='4')i++;
		else if(p[0]=='3'&&p[2]=='4')k++;
	}
// This is a greedy problem
// we should be careful about each and every condition
//_____ In this problem we can match (3/4 & 1/4)
if(i<k){
	k-=i;//i becomes 0 and k becomes k-=i
	l+=i;	i=0; 
}else{
	i-=k;//k becomes 0 and i becomes i-=k
	l+=k;	k=0;
}
//Now we look for any left over 3/4(only. we'll see leftover 1/4 later
if(k>0)l+=k;
//__________Now 1/2 part.
// we dont match 1/2 with any other ones coz. 1/2 itself is optimal division
if(j>=2){
	l+=j/2; 
	j%2 == 0 ? l+=0 : j=1;//if j odd then single j reamains for matching with 1/4
	if(j%2 == 0)j=0;
}
// these j>=2 & i>=4 conditions are to minimize oper. time and they results
// in lower number which is easy to match further
if(i>=4){
	l+=i/4; i%4==0? i=0 : i%=4;
} 
if(i>0 && j>0)
{
	//if(i>=2)l+=2;else l+=1;
	int n = i;
	if(i>2){	// 2 pizza must in this case because i>2
		l+=2;n-=i;i=n;j=0;
	}else {
		l+=1; i=0;j=0;
	}
}
if(j>0 || i>0)l++;// one extra pizza is must because of this condition
cout<<l<<endl;
}






