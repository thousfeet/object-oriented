#include<iostream>
#include<cstdio>
using namespace std;

struct list
{
	int address;
	int data;
	int nextAdd;
	struct list *next;
}dot1[100010],dot2[100010];

int arr[100010];

int read(int n,int add0)
{		
	int i,j;
	
	//arr[address]=输入乱序 
	for(i = 1; i <= n; i++)
	{
		scanf("%d%d%d",&dot1[i].address,&dot1[i].data,&dot1[i].nextAdd);
		arr[dot1[i].address] = i;
	}
	

	if(!arr[add0]) return 0;
	
	dot2[1] = dot1[arr[add0]];
		
	int count = 1;
	
	//dot2为顺序 
	while(dot2[count].nextAdd!= -1)
	{
		dot2[++count] = dot1[arr[dot2[count-1].nextAdd]];
	}
	
//	for(i = 1; i <=count;i++)
//		cout << dot2[i].address <<" "<< dot2[i].data <<endl; 
//	cout <<count<<endl;

	return count;
}

struct list *create(int count)
{

	list *head = new list;
	list *p1 = new list;
	list *p2;
	
	p1->address = dot2[1].address;
	p1->data = dot2[1].data;
	p1->nextAdd = dot2[1].nextAdd;
	p1->next = NULL;
	
	head->next = p1;

	for(int i = 2;i <= count; i++)
	{
		p2= new list;
		p2->address = dot2[i].address;
		p2->data = dot2[i].data;
		p2->nextAdd = dot2[i].nextAdd;
		p2->next = NULL;
		
		p1->next = p2;
		p1 = p2;
	}
	
	p1 = NULL;
	p2 = NULL;
	 
//	list *before = new list;
//	for(before = head->next;before!=NULL;before = before->next)
//		cout << before->data<<endl;
 
	 
	return head;
} 

void trans(list *head,int n,int k,int count)
{
	list *before = new list;
	list *now = new list;
	list *stop = new list;
	
	before = head;
	stop = before->next;
	now = stop->next;
	
	if(count/k < 1) return ;
 
	for(int i = 0; i < count/k; i++) //转count/k组 
	{
		for(int j = 1; j < k; j++) //每组转k-1个节点 
		{
			stop->next = now->next;
			now->next = before->next;
			before->next = now;
			if(stop->next!=NULL) now = stop->next;
		}
		before = stop;
		if(before->next!=NULL) stop = before->next;
		if(stop->next!=NULL) now = stop->next;
	}
	
	
	//判断末尾结点 
	before = head -> next;
	for(int i = 1; i <count;i++,before= before->next);
	before->next = NULL;

//	for(before = head->next;before!=NULL;before = before->next)
//		cout << before->data<<endl;
}

void print(list *head)
{
	list *before = new list;
	list *now = new list;
		
	before = head->next;
	printf("%05d %d ",before->address,before->data);
	delete(head);
	head = NULL;
	
	now = before->next;
	delete(before);
	before = NULL;
	

	for(;now!=NULL;)
	{
		printf("%05d\n",now->address);
		printf("%05d %d ",now->address,now->data);
		
		before = now;
		now = now->next;
		delete(before);
	}
	delete(now);
	now = NULL;
	cout <<"-1";
}


int main()
{
	freopen("xx.in","r",stdin);
	freopen("xx.out","w",stdout);

	int add0,n,k;
	cin >> add0 >> n >> k;
	
	int count = read(n,add0);   //转为顺序
	
	if(!count) return 0;
	
	//链表操作 	
	list *head = new list;
	head = create(count);	//创建链表 
	trans(head,n,k,count);	//就地转置
	print(head);	//顺序输出 
	
	
	return 0;
} 
