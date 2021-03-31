#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>

int comps=0;
int MaxSize1 =100;
typedef struct ListNode
{
	long data;
	struct ListNode *next;
}HashItem;
void CreatBinaryLargeNumber(int n);
int BinarySearch(int a[],int n,int x);
void sort(int a[],int n);
void CreateData(int a[], int n);
void CreateBinaryByKeyborad(int n);
int LinearSearch(int a[],int n,int x);
void CreateLinearByKeyborad(int n);
void CreatLinearLargeNumber(int n);
int InterpolationSearch(int a[],int n,int x);
void CreateInterpoyByKeyborad(int n);
void CreatInterpoyLargeNumber(int n);
int Jump_Search(int L[],int n,int x);
void CreateJumpByKeyborad(int n);
void CreatJumpLargeNumber(int n);
int min(int b, int n);
void CreateOpenHashTable(int HashTable[],int len,int num);
int OpenHashSearch(int HashTable[],int len,int x);
int Hash(int key,int len);
void CreateHashOpenByKeyborad(int n);
void CreatHashOpenLargeNumber(int n);
void InitLinkHashTable( HashItem *HashTable[],int len);
int FindNode(HashItem *head,int x);
void CreateChainedLinkHashTable(HashItem *HashTable[],int len,int num);
long LinkHashSearch(HashItem *HashTable[],int len,int x);
void CreateChainedHashOpenByKeyborad(HashItem *HashTable[],int n);
void CreatchainedHashLargeNumber(HashItem *HashTable[],int n);
int main()
{
	 int *a;
	 HashItem *HashTable;
	 int n,x;
	 int select;
	 int TestMethod;
	 do{
		printf("\n********************* The MANUE *********************\n");
		printf("0.Exit\n");
		printf("1.Linear search\n");
		printf("2.Binary search\n");
		printf("3.Iterpolation search\n");
		printf("4.Jump search\n");
		printf("5.Hash(open address)\n");
		printf("6.Hash(chained address)\n");
		printf("Enter your select:");
		scanf("%d",&select);
		switch(select){
				case 2:
					printf("Enter the totall numbers for test search:");
					scanf("%d",&TestMethod);
					if(TestMethod<20){
					CreateBinaryByKeyborad(TestMethod);
					}
					else{	
					CreatBinaryLargeNumber(TestMethod);
					}
					printf("Done!");
					break;
				case 1:
					printf("Enter the totall numbers for test search:");
					scanf("%d",&TestMethod);
					if(TestMethod<20){
					CreateLinearByKeyborad(TestMethod);
					}
					else{	
					CreatLinearLargeNumber(TestMethod);
					}
					printf("Done!");
					break;
				case 3:
					printf("Enter the totall numbers for test search:");
					scanf("%d",&TestMethod);
					if(TestMethod<20){
					CreateInterpoyByKeyborad(TestMethod);
					}
					else{	
					CreatInterpoyLargeNumber(TestMethod);
					}
					printf("Done!");
					break;
				case 4:
					printf("Enter the totall numbers for test search:");
					scanf("%d",&TestMethod);
					if(TestMethod<20){
					CreateJumpByKeyborad(TestMethod);
					}
					else{	
					CreatJumpLargeNumber(TestMethod);
					}
					printf("Done!");
					break;
				case 5:
					printf("Enter the totall numbers for test search:");
					scanf("%d",&TestMethod);
					if(TestMethod<20){
						CreateHashOpenByKeyborad(TestMethod);
					}else{
						CreatHashOpenLargeNumber(TestMethod);
					}
					printf("Done!");
					break;
				case 6:
					printf("Enter the totall numbers for test search:");
					scanf("%d",&TestMethod);
					if(TestMethod<20){
						CreateChainedHashOpenByKeyborad(&HashTable,TestMethod);
					}else{
						CreatchainedHashLargeNumber(&HashTable,TestMethod);
					}
					break;
				}
	 }while(select!=0);
	   return 0;
}
/*Binary Search*/
void CreatBinaryLargeNumber(int n)
{
	 int x,*a;
	 a=(int *) malloc(sizeof(int) *n);//100000000
	 CreateData(a,n);//100000
	 sort(a,n);
	 double findlength=0;
	 int findcount=0;
	 double notfindlength=0;
	 int notfindcount=0;
	 for(int i=0;i<2*n;i++)
	 {
			x=rand();
			if(BinarySearch(a,n,x)==1)//found comps, not found
			{	
				findcount++;
				findlength+=comps;
			}
			else
			 {
				notfindcount++;
				notfindlength+=comps;
			}   
	 }
	printf("ASLsucc = %.2lf ASLunsucc=%.2lf\n",findlength/findcount, notfindlength/notfindcount);
	free(a);
}

void CreateBinaryByKeyborad(int n)
{
	 int x;
	 int a[100];
	 int i;
	 double findlength=0;
	 int findcount=0;
	 double notfindlength=0;
	 int notfindcount=0;
	 printf("Enter test data:\n");
	 for(i=0;i<n;i++)
	 {
	      scanf("%d",&a[i]);
	 }
	 printf("Enter num to search(-1 to end):\n");
	 scanf("%d",&x);
	 while(x>=1)
	 {
		if(BinarySearch(a,n,x)==1)//found comps, not found
		{	
			printf("%d Found, need %d comps\n",x,comps);
			findcount++;
			findlength+=comps;
			
		}
		else
		{
			printf("%d not found, need %d comps\n",x,comps);
			notfindcount++;
			notfindlength+=comps;
		}
		printf("---------------------------\n");
		scanf("%d",&x);
	 }
	 printf("ASLsucc = %.2lf ASLunsucc=%.2lf\n",findlength/findcount, notfindlength/notfindcount);
}

int BinarySearch(int a[],int n,int x)
{
	int l=0;
	int r=n-1;
	comps=0;
	while(l<=r)
	 {
			int mid=(r+l)/2;
			comps++;
			if(a[mid]==x)
				return 1;
			else if(x<a[mid])
				r=mid-1;
			else
				l=mid+1;

	}	
	 return 0;
}
void sort(int a[],int n)
{
	 int i,j;
	 int temp;
	 for(i=1;i<n;i++)
	    for(j=0;j<n-i;j++)
	        if(a[j]>a[j+1])
	       {
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
	       }

}
void CreateData(int a[], int n)
{
	 int i;
	 for(i=0;i<n;i++)
		a[i]=rand();
}
/*Linear Search*/
int LinearSearch(int a[],int n,int x)
{
	comps=0;
	for(int i=0;i<n;i++)
	{
		comps++;
		if(a[i]==x)
			return 1;
	}
	return -1;
}
void CreateLinearByKeyborad(int n)
{
	 int x;
	 int a[100];
	 int i;
	 double findlength=0;
	 int findcount=0;
	 double notfindlength=0;
	 int notfindcount=0;
	 printf("Enter test data:\n");
	 for(i=0;i<n;i++)
	 {
	      scanf("%d",&a[i]);
	 }
	 printf("Enter num to search(-1 to end):\n");
	 scanf("%d",&x);
	 while(x>=1)
	 {
		if(LinearSearch(a,n,x)==1)//found comps, not found
		{	
			printf("%d Found, need %d comps\n",x,comps);
			findcount++;
			findlength+=comps;
			
		}
		else
		{
			printf("%d not found, need %d comps\n",x,comps);
			notfindcount++;
			notfindlength+=comps;		}
		printf("---------------------------\n");
		scanf("%d",&x);
	 }
	 printf("ASLsucc = %.2lf ASLunsucc=%.2lf\n",findlength/findcount, notfindlength/notfindcount);
}

void CreatLinearLargeNumber(int n)
{
	 int x,*a;
	 a=(int *) malloc(sizeof(int) *n);//100000000
	 CreateData(a,n);//100000
	 double findlength=0;
	 int findcount=0;
	 double notfindlength=0;
	 int notfindcount=0;
	 //printf("Enter positive number to search(-1 to end):");
	 for(int i=0;i<2*n;i++)
	 {
			x=rand();
			if(LinearSearch(a,n,x)==1)//found comps, not found
			{	
				findcount++;
				findlength+=comps;
			}
			else
			 {
				notfindcount++;
				notfindlength+=comps;
			}   
	 }
	printf("ASLsucc = %.2lf ASLunsucc=%.2lf\n",findlength/findcount, notfindlength/notfindcount);
	free(a);
}
/*InterpolationSearch*/
int InterpolationSearch(int a[],int n,int x)
{
	int mid;
	int low = 0;
	int high=n-1;
	comps=0;
	while(low<= high)
	 {
			if(x<a[low] || x>a[high])
				break;
			mid= low +(high -low ) * (x-a[low]) / (a[high] - a[low]);
			comps++;
			if(x == a[mid])
				return 1;
			else if(x < a[mid])
				high = mid - 1;
			else
				low = mid + 1;

	}	
	 return 0;
}
void CreateInterpoyByKeyborad(int n)
{
	 int x;
	 int a[100];
	 int i;
	 double findlength=0;
	 int findcount=0;
	 double notfindlength=0;
	 int notfindcount=0;
	 printf("Enter test data:\n");
	 for(i=0;i<n;i++)
	 {
	      scanf("%d",&a[i]);
	 }
	 printf("Enter num to search(-1 to end):\n");
	 scanf("%d",&x);
	 while(x>=1)
	 {
		if(InterpolationSearch(a,n,x)==1)//found comps, not found
		{	
			printf("%d Found, need %d comps\n",x,comps);
			findcount++;
			findlength+=comps;
		}
		else
		{
			printf("%d not found, need %d comps\n",x,comps);
			notfindcount++;
			notfindlength+=comps;
		}
		printf("---------------------------\n");
		scanf("%d",&x);
	 }
	 printf("ASLsucc = %.2lf ASLunsucc=%.2lf\n",findlength/findcount, notfindlength/notfindcount);
}
void CreatInterpoyLargeNumber(int n)
{
	 int x,*a;
	 a=(int *) malloc(sizeof(int) *n);//100000000
	 CreateData(a,n);//100000
	 sort(a,n);
	 double findlength=0;
	 int findcount=0;
	 double notfindlength=0;
	 int notfindcount=0;
	 for(int i=0;i<2*n;i++)
	 {
			x=rand();
			if(InterpolationSearch(a,n,x)==1)//found comps, not found
			{	
				findcount++;
				findlength+=comps;
			}
			else
			 {
				notfindcount++;
				notfindlength+=comps;
			}   
	 }
	printf("ASLsucc = %.2lf ASLunsucc=%.2lf\n",findlength/findcount, notfindlength/notfindcount);
	free(a);
}
/*Jump search*/
int Jump_Search(int L[],int n,int x)
{
	int a = 0;
	int seglen=sqrt(n*1.0);
	int b = seglen;
// b is the block length, equal length for all block
    comps=0;// record comparion time
	while( L[min(b-1,n-1)] < x )
	{   
		comps++;
		a=b;//move to next block
		b = b + seglen;
		if (a >= n) // if it go out of bound,
			return -1;
	}
	while ( L[a] < x )
	{
		comps++;
		a = a + 1;
		if (a == min(b,n))
			return -1;
	}
		comps++;
		if ( L[a]== x )
			return 1;
		else
			return -1;
}
int min(int b, int n)
{
	if(b>n)
		return n;
	else
		return b;
}
void CreateJumpByKeyborad(int n)
{
	 int x;
	 int a[100];
	 int i;
	 double findlength=0;
	 int findcount=0;
	 double notfindlength=0;
	 int notfindcount=0;
	 printf("Enter test data:\n");
	 for(i=0;i<n;i++)
	 {
	      scanf("%d",&a[i]);
	 }
	 printf("Enter num to search(-1 to end):\n");
	 scanf("%d",&x);
	 while(x>=1)
	 {
		if(Jump_Search(a,n,x)==1)//found comps, not found
		{	
			printf("%d Found, need %d comps\n",x,comps);
			findcount++;
			findlength+=comps;
		}
		else
		{
			printf("%d not found, need %d comps\n",x,comps);
			notfindcount++;
			notfindlength+=comps;
		}
		printf("---------------------------\n");
		scanf("%d",&x);
	 }
	 printf("ASLsucc = %.2lf ASLunsucc=%.2lf\n",findlength/findcount, notfindlength/notfindcount);
}
void CreatJumpLargeNumber(int n)
{
	 int x,*a;
	 a=(int *) malloc(sizeof(int) *n);//100000000
	 CreateData(a,n);//100000
	 sort(a,n);
	 double findlength=0;
	 int findcount=0;
	 double notfindlength=0;
	 int notfindcount=0;
	 for(int i=0;i<2*n;i++)
	 {
			x=rand();
			if(Jump_Search(a,n,x)==1)//found comps, not found
			{	
				findcount++;
				findlength+=comps;
			}
			else
			 {
				notfindcount++;
				notfindlength+=comps;
			}   
	 }
	printf("ASLsucc = %.2lf ASLunsucc=%.2lf\n",findlength/findcount, notfindlength/notfindcount);
	free(a);
}
/*Open Hash table*/
//Create Open Hash table
//len is the size of hash table
// num is number of values to be inserted into the hashtable
void CreateOpenHashTable(int HashTable[],int len,int num)
{
  int i;
  for(i=0;i<MaxSize1;i++)
     HashTable[i]=-1;
	
   bool finished;
   int key;
   int index;
	

    for(i=0;i<num;i++)
	{
		finished=false;
		scanf("%d",&key);
	
		index = Hash(key,len);
		do
		{			
			if(HashTable[index]==-1)
			{
			    HashTable[index]=key;
			    finished=true;
			    printf("insert %d at pos=%d \n",key,index);
			}
			else if(HashTable[index]==key)
			{
			     finished=true;
			     printf("%d is already in the hash table at pos=%d \n",key,index);
			}
			else
			{
			    index=Hash(index+1,len);
			}

		}while(!finished);

	}
}

//search for x in open hash table
// len is length of hash table
// if found,return its position, else return -1
int OpenHashSearch(int HashTable[],int len,int x)
{
   int k=0;
   int index;
	
   index = Hash(x,len);
   int i=1;
   comps=0;
   do{
		comps++;
		if(HashTable[index]==-1)
		{
			return -1;//not found	
		}
		else if(HashTable[index]==x)
		{
			return 1; //found
		}
		else
		{
			index=Hash(index+1,len);
				
		}
			
  }while(i<MaxSize1);// MaxSize m
   return -1;
}

int Hash(int key,int len)
{
	int k = key%len;
	return k;
}
void CreateHashOpenByKeyborad(int n)
{
	 int x;
	 int a[100];
	 int i;
	 int len;
	 double findlength=0;
	 int findcount=0;
	 double notfindlength=0;
	 int notfindcount=0;
	 printf("Enter the size of the hash:\n");
	 scanf("%d",&len);
	 printf("Enter num to be insert\n");
	 CreateOpenHashTable(a,len,n);
	 printf("Enter num to search ,-1 to exit:\n");
	 scanf("%d",&x);
	 while(x>=1)
	 {
		if(OpenHashSearch(a,len,x)==1)//found comps, not found
		{	
			printf("%d Found, need %d comps\n",x,comps);
			findcount++;
			findlength+=comps;
			
		}
		else
		{
			printf("%d not found, need %d comps\n",x,comps);
			notfindcount++;
			notfindlength+=comps;
		}
		printf("---------------------------\n");
		scanf("%d",&x);
	 }
	 printf("ASLsucc = %.2lf ASLunsucc=%.2lf\n",findlength/findcount, notfindlength/notfindcount);
}
void CreatHashOpenLargeNumber(int n)
{
	 int x,*a;
	 int len;
	 a=(int *) malloc(sizeof(int) *n);//100000000
	 CreateData(a,n);//100000
	 double findlength=0;
	 int findcount=0;
	 double notfindlength=0;
	 int notfindcount=0;
	 printf("Enter the size of the Hash:\n");
	 scanf("%d",&len);
	 for(int i=0;i<2*n;i++)
	 {
			x=rand();
			if(OpenHashSearch(a,len,x)==1)//found comps, not found
			{	
				findcount++;
				findlength+=comps;
			}
			else
			{
				notfindcount++;
				notfindlength+=comps;
		    }   
	 }
	printf("ASLsucc = %.2lf ASLunsucc=%.2lf\n",findlength/findcount, notfindlength/notfindcount);
	free(a);
}

/*Chained hash*/

void InitLinkHashTable( HashItem *HashTable[],int n){
	long i;
	for(i=0;i<n;i++)
	{
		HashTable[i]=NULL;
	}
}
//start from p, to check if x is in the link
int FindNode(HashItem *head,int x){
	HashItem *p= head;
	comps=0;
	while(p && p->data!=x)
	{
		p=p->next;
		comps++;
	}
	comps++;
	if(p==NULL)
		return -1;// it is not in the link
	else
		return 1; // it is in the link

}
void CreateChainedLinkHashTable(HashItem *HashTable[],int size,int num)
{
	InitLinkHashTable(HashTable,num);

	int val;
	int index;
	int n=0;
	while(n<num)
      {

            scanf("%d",&val);
            index = Hash(val,size);

            HashItem *head = HashTable[index];
            if( FindNode(head,val)<0)
            {
                  HashItem *p = (HashItem *) malloc(sizeof(HashItem));
                  p->data= val;
                  p->next= head;
                  HashTable[index]=p;// insert as head
                  printf("Insert key=%d successfully at index=%d\n",val,index);
                  n++;
            }
            else
            {
                  printf("key=%d already at pos %d\n",val,index);
            }
	}
}
//search for x in chained Hash table
long LinkHashSearch(HashItem *HashTable[],int len,int x)
{
      int index = Hash(x,len);
      HashItem *head = HashTable[index];
      if (FindNode(head,x)==1)
            return 1;
      return -1;

}
void CreateChainedHashOpenByKeyborad(HashItem *HashTable[],int n)
{
	 int x;
	 int i;
	 int len;
	 double findlength=0;
	 int findcount=0;
	 double notfindlength=0;
	 int notfindcount=0;
	 printf("Enter the size of the hash:\n");
	 scanf("%d",&len);
	 printf("Enter num to be insert\n");
	 CreateChainedLinkHashTable(HashTable,len,n);
	 printf("Enter num to search ,-1 to exit:\n");
	 scanf("%d",&x);
	 while(x>=1)
	 {
		if(LinkHashSearch(HashTable,len,x)==1)//found comps, not found
		{	
			printf("%d Found, need %d comps\n",x,comps);
			findcount++;
			findlength+=comps;
			
		}
		else
		{
			printf("%d not found, need %d comps\n",x,comps);
			notfindcount++;
			notfindlength+=comps;
		}
		printf("---------------------------\n");
		scanf("%d",&x);
	 }
	 printf("ASLsucc = %.2lf ASLunsucc=%.2lf\n",findlength/findcount, notfindlength/notfindcount);
}

void CreatchainedHashLargeNumber(HashItem *HashTable[],int n)
{
	 int x,*a;
	 int len;
	 a=(int *) malloc(sizeof(int) *n);//100000000
	 CreateData(a,n);//100000
	 double findlength=0;
	 int findcount=0;
	 double notfindlength=0;
	 int notfindcount=0;
	 printf("Enter the size of the Hash:\n");
	 scanf("%d",&len);
	 for(int i=0;i<2*n;i++)
	 {
			x=rand();
			if(LinkHashSearch(HashTable,len,x)==1)//found comps, not found
			{	
				findcount++;
				findlength+=comps;
			}
			else
			{
				notfindcount++;
				notfindlength+=comps;
		    }   
	 }
	printf("ASLsucc = %.2lf ASLunsucc=%.2lf\n",findlength/findcount, notfindlength/notfindcount);
	free(a);
}


/*
Test Data

Linear Search:
found : 8 18 23	 28 35 40 45 51 55 62 71 80
not found : 7 15 20 25 30 38 42 47 52 58 68 76 85
********************************
Binary Search:
found : 8 18 23	 28 35 40 45 51 55 62 71 80
not found : 7 15 20 25 30 38 42 47 52 58 68 76 85
********************************
Interp Search:
found : 8 18 23	 28 35 40 45 51 55 62 71 80
not found : 7 15 20 25 30 38 42 47 52 58 68 76 85
*******************************
Jump Search:
found : 8 18 23	 28 35 40 45 51 55 62 71 80
not found : 7 15 20 25 30 38 42 47 52 58 68 76 85
**********************************
Hash Open Search :
78 65 28 42 81 9 -1 -1 21 -1 23 49
found : 23 21 78 65 42 81 96 28 49
not found : 13 14 15 16 17 18 19 20 34 35 36 37 38
*********************************
Chianed Hash Search:
found : 64 23 15 78 65 42 81 96 28 49 84 63 55 24 18
not found : 20 21 22 33 44 45 76 87 88 89
*/