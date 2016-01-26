/*
三位一逗号的标准数字格式输出a+b 
*/
#include<stdio.h>
#include<math.h>
int main()
{
	freopen("xx.in","r",stdin);
	freopen("xx.out","w",stdout);
	int a,b;
	scanf("%d%d",&a,&b);
	int sum=a+b;
	int part1,part2,part3;//逗号间隔开最多三部分 
	
	if((abs(sum))<1000) 
	printf("%d",sum);//无逗号
	 
	else if((abs(sum))<1000000) //一逗号 
	{
		part2=sum%1000;
		part1=sum/1000;
	 	printf("%d,%03d",part1,abs(part2)); 
	}
	
	else //两逗号
	{
		part3=sum%1000;
		sum/=1000;
		part2=sum%1000;
		part1=sum/1000;	
		printf("%d,%03d,%03d",part1,abs(part2),abs(part3));
	}
	
	return 0;
}
