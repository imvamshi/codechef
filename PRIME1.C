// again trying to min. runtime

#include<stdio.h>
main()
{
	long long int t,a,b,n,i,j,just;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld %lld",&a,&b);
		if(a==1)a=2;
		long long int prime[b-a+1];
		for(i=0;i<b-a+1;i++) prime[i]=0;
		for(i=2;i*i<=b;i++)
		{
			just=a/i;	just*=i;
			for(j=just;j<=b;j+=i)
			  if(j!=i)
				 prime[j-a]=1;
		}
		
		for(i=0;i<b-a+1;i++)
		  if(prime[i]==0)
			printf("%lld\n",i+a);
		
	}
}
