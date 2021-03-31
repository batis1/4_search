#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX_SIZE
//#define MaxSize 2000000
/*
typedef int DataType ;

typedef struct
{
     DataType elem[MaxSize];
      int  len;
} SeqList;
*/
typedef struct ListNode
{
	long data;
	struct ListNode *next;
}HashItem;

int comps;
int sizeOfArray;
// methods declaration.
int binarySearch(int a[],int n,int x);
void userInput(int a[],int n);
void sort(int a[],int n);
void randomInput(int a[], int n);
void printArray(int [], int);
void calcBinarySearchASLsuccAndASLunsucc(int[], int);
int linearSearch(int a[],int size , int x);
void calcLinearSearchASLsuccAndASLunsucc(int a[], int size);
int interpolationSearch(int a[], int n, int x);
void calcInterpolationSearchASLsuccAndASLunsucc(int a[], int size);
int jumpSearch(int a[], int n, int x);
int min(int a, int b);
void calcJumpSearchASLsuccAndASLunsucc(int a[], int size);
void createOpenHashTable(int hashTable[], int a[] ,int len, int num);
int openHashSearch(int hashTable[], int len, int x);
void calcOpenHashSearchASLsuccAndASLunsucc(int a[], int size);
void InitLinkHashTable( HashItem *HashTable[],int len);
void createArray(int a[]);
void openHashInsertType(int []);
int main()
{
	int *a, *hashTable;//100000000// allocate memory of
	int n,x,options = 0, wantedElement, newElement, TypeOfInsert;
	int isOpenHashTableCreated = 0, isArrayCreated = 0, isChainTableCreated =0 ;
	while(1){
            printf("Create your array.\n");
            printf("for insert element manually enter 1.\n");
            printf("for insert element randomly enter 2.\n");
            printf("Enter your option: ");
            scanf("%d",&TypeOfInsert);
            if(TypeOfInsert == 1){
                  printf("Enter the size of your array: ");
                  scanf("%d",&sizeOfArray);
                  a=(int *) malloc(sizeof(int) *sizeOfArray);

                  userInput( a, sizeOfArray);
                  break;
            }

            else if(TypeOfInsert == 2){
                  printf("Enter the size of your array: ");
                  scanf("%d",&sizeOfArray);
                  a=(int *) malloc(sizeof(int) *sizeOfArray);

                  randomInput( a, sizeOfArray);
                  break;
                  }
            else{
                  printf("Please Enter the right options 1 or 2\n");
                  printf("come on there is no such %d option.\n", TypeOfInsert);

            }
            printf("array created successfully.\n");
            if(sizeOfArray <= 10)
                  printArray(a, sizeOfArray);
      }
	while(options != 8){
             // options
            comps = 0;
            printf("please Enter what kind of search you want to use?\n");
            printf("    1 - Sequence search\n");
            printf("    2 - Binary search \n");
            printf("    3 - Interpolation search\n");
            printf("    4 - Jump search\n");
            printf("    5 - Hash(open address)\n");
            printf("    6 - Hash(chained address)\n");
            printf("    7 - for print the array (if size bigger than 100 it won't work)\n");
            printf("    8 - for Quit the program\n");
            printf("Enter your option: ");
            scanf("%d",&options);
            // select the options that has been chose it.
            printf("###############################################\n");
            switch(options){
                  case 1:
                        printf("###############################################\n");

                        printf("what element do you want to search for?\n");
                        printf("Enter the element: ");
                        scanf("%d", &wantedElement);
                        int holdLinearSearch = linearSearch( a, sizeOfArray, wantedElement);
                        if(holdLinearSearch != -1){
                              printf("the %d element found and its index is %d.\n", wantedElement, holdLinearSearch);
                              printf("it was compare %d times\n",comps);

                        }
                        else{
                              printf("it was compare %d times\n", comps);
                              printf("the %d element not found.\n", wantedElement);

                        }
                        calcLinearSearchASLsuccAndASLunsucc(a,sizeOfArray);
                        printf("###############################################\n");
                        break;
                  case 2:
                        printf("###############################################\n");
                        printf("what element do you want to search for?\n");
                        printf("Enter the element: ");
                        scanf("%d", &wantedElement);
                        if(binarySearch( a, sizeOfArray, wantedElement)){
                              printf("the %d element found.\n", wantedElement);
                              printf("it was compare %d times\n",comps);

                        }
                        else{
                              printf("it was compare %d times\n", comps);
                              printf("the %d element not found.\n", wantedElement);

                        }
                        calcBinarySearchASLsuccAndASLunsucc(a,sizeOfArray);
                        printf("###############################################\n\n");
                        break;
                  case 3:
                        printf("###############################################\n");
                        printf("what element do you want to search for?\n");
                        printf("Enter the element: ");
                        scanf("%d", &wantedElement);
                        if(interpolationSearch( a, sizeOfArray, wantedElement) != -1 ){
                              printf("the %d element found.\n", wantedElement);
                              printf("it was compare %d times\n",comps);

                        }
                        else{
                              printf("it was compare %d times\n", comps);
                              printf("the %d element not found.\n", wantedElement);

                        }
                        calcInterpolationSearchASLsuccAndASLunsucc(a,sizeOfArray);
                        printf("###############################################\n");
                        break;
                  case 4:
                        printf("###############################################\n");
                              printf("what element do you want to search for?\n");
                              printf("Enter the element: ");
                              scanf("%d", &wantedElement);
                              if(jumpSearch( a, sizeOfArray, wantedElement) != -1 ){
                                    printf("the %d element found.\n", wantedElement);
                                    printf("it was compare %d times\n",comps);

                              }
                              else{
                                    printf("it was compare %d times\n", comps);
                                    printf("the %d element not found.\n", wantedElement);

                              }
                              calcJumpSearchASLsuccAndASLunsucc(a, sizeOfArray);
                        printf("###############################################\n");
                        break;
                  case 5:
                        printf("###############################################\n");
                              if(!isOpenHashTableCreated){
                                    hashTable=(int *) malloc(sizeof(int) *sizeOfArray+20);
                                    createOpenHashTable(hashTable,a,sizeOfArray+20,sizeOfArray);
                                    isOpenHashTableCreated = 1;
                              }


                              printf("what element do you want to search for?\n");
                              printf("Enter the element: ");
                              scanf("%d", &wantedElement);
                              if(openHashSearch(hashTable, sizeOfArray+20,wantedElement) != -1 ){
                                    printf("the %d element found.\n", wantedElement);
                                    printf("it was compare %d times\n",comps);

                              }
                              else{
                                    printf("it was compare %d times\n", comps);
                                    printf("the %d element not found.\n", wantedElement);

                              }
                              calcOpenHashSearchASLsuccAndASLunsucc(hashTable, sizeOfArray+20);
                        printf("###############################################\n");
                        break;
                  case 6:
                        printf("###############################################\n");
                        printf("###############################################\n");
                        break;
                  case 7:
                        printf("###############################################\n");
                              if(sizeOfArray <=100)
                                    printArray(a, sizeOfArray);
                        printf("###############################################\n");
                        break;
                  case 8:
                        printf("See You Next Time.\n");
                        break;
                  default:
                        printf("Please Enter the right options from 1 to 7\n");
                        printf("come on there is no such %d option.\n", options);
                        break;


            }

	}



	/*CreateData(a,n);//100000// insert the n random element of the array for 0 to n.
	sort(a,n);// sort the element.
	double findlength=0;
	int findcount=0;
	double notfindlength=0;
	int notfindcount=0;
	for(int i = 0 ;i< n ; i++)
            printf("%d ", a[i]);
      printf("\n");
	printf("enter positive number to search(-1 to end): ");*/
	/*for(int i=0;i<2*n;i++)
	{
		x=rand();
		if(BinarySearch(a,n,x)==1)//found comps, not found
		{ findcount++;
			findlength+=comps;
		}
			//printf("find %d needs %d(comparison )\n",x,comps);
		else
		{
			notfindcount++;
			notfindlength+=comps;
		}
	}
	printf("ASLsucc = %.2lf ASLunsucc=%.2lf\n",findlength/findcount, notfindlength/notfindcount);*/
	/*scanf("%d", &x);
	BinarySearch(a,n,x);
	printf("%d: \n",comps );*/

	free(a);
	free(hashTable);
	return 0;
}


int binarySearch(int a[],int n,int x)
{
	int l=0;
	int r=n-1;
	comps=0;
	sort(a,n);
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
void calcBinarySearchASLsuccAndASLunsucc(int a[], int size) {
      int x;
      double findlength=0;
	int findcount=0;
	double notfindlength=0;
	int notfindcount=0;
      for(int i=0;i<2*size;i++){
            x=rand();
            //printf("here\n");
            if(binarySearch(a,size,x)){//found comps, not found
                  findcount++;
                  findlength+=comps;
            }
                  //printf("find %d needs %d(comparison )\n",x,comps);
            else
            {
                  notfindcount++;
                  notfindlength+=comps;
            }
      }
      //printf("%.2lf\n",findlength);
      double aslsucc=0,aslunsucc=0;
      if(findcount>0)
            aslsucc=findlength/findcount;
      if(notfindcount>0)
            aslunsucc=notfindlength/notfindcount;
      printf("ASLsucc = %.2lf ASLunsucc=%.2lf\n",aslsucc,aslunsucc);
}
void calcLinearSearchASLsuccAndASLunsucc(int a[], int size) {
      int x;
      double findlength=0;
	int findcount=0;
	double notfindlength=0;
	int notfindcount=0;
      for(int i=0;i<2*size;i++){
            x=rand();
            //printf("here\n");
            if(linearSearch(a,size,x) != -1){//found comps, not found
                  findcount++;
                  findlength+=comps;
            }
                  //printf("find %d needs %d(comparison )\n",x,comps);
            else
            {
                  notfindcount++;
                  notfindlength+=comps;
            }
      }
      //printf("%.2lf\n",findlength);
      double aslsucc=0,aslunsucc=0;
      if(findcount>0)
            aslsucc=findlength/findcount;
      if(notfindcount>0)
            aslunsucc=notfindlength/notfindcount;
      printf("ASLsucc = %.2lf ASLunsucc=%.2lf\n",aslsucc,aslunsucc);
}
void userInput(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
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
void randomInput(int a[], int n)
{
	int i;
	for(i=0;i<n;i++)
		a[i]=rand();

}
void printArray(int a[], int size){
      if(size == 1){
            printf("[ %d ]\n", a[0]);return;
      }

      printf("[ %d,", a[0]);
      for(int i=1 ; i < size-1 ; i++)
            printf(" %d, ", a[i]);
      printf("%d ]\n", a[size-1]);
}

int linearSearch(int a[], int size , int x){
      int i =0;
      while((i < size) && (a[i] != x)){
            i++;comps++;
      }

      if(i < size){
            comps++;return i;
      }

      return -1;

}
int interpolationSearch(int a[], int n, int x){
      int l=0;
	int r=n-1;
	comps=0;
	sort(a,n);

	while(l<=r)
	{
	      if( (x<a[l])  || (x>a[r]))
                  return -1;
		int mid= l + (r - l) * (x - a[l]) / (a[r] - a[l]);
		comps++;
		//printf("here\n");
            //printf("mid = %d\n", mid);

		if(a[mid]==x)
			return mid;
		else if(x<a[mid])
			r=mid-1;
		else
			l=mid+1;

	}
	return -1;
}
void calcInterpolationSearchASLsuccAndASLunsucc(int a[], int size){
      double findlength=0;
	int findcount=0;
	double notfindlength=0;
	int notfindcount=0;int x;
      for(int i=0;i<2*size;i++){

            x=rand();
            //printf("x = %d\n",x);
            if(interpolationSearch(a,size,x) != -1){//found comps, not found
                  findcount++;

                  findlength+=comps;
            }
                  //printf("find %d needs %d(comparison )\n",x,comps);
            else
            {
                  notfindcount++;
                  notfindlength+=comps;
            }
      }
      //printf("%.2lf\n",findlength);
      double aslsucc=0,aslunsucc=0;
      if(findcount>0)
            aslsucc=findlength/findcount;
      if(notfindcount>0)
            aslunsucc=notfindlength/notfindcount;
      printf("ASLsucc = %.2lf ASLunsucc=%.2lf\n",aslsucc,aslunsucc);

}
int jumpSearch(int a[], int n, int x){
      int aVariable = 0; // create variable.
      int seglen = sqrt(n*1.0);// divide the length first convert it to
      // double because sqrt's parameter takes double value not int.
      int b;// create variable.
      // b is the block length, equal length of all blocks
      comps = 0;
      //Finding the block where element is
      // present (if it is present)
      while(a[min(b-1,n-1)] < x ){
            //printf( "min = %d\n" ,min(b-1,n-1));
            comps++;
            aVariable = b;// move to next block
            b = b + seglen;
            if(aVariable >= n)// if it go out of bound
                  return -1;
      }
      while(a[aVariable] < x){
            comps++;
            aVariable = aVariable + 1;
            if(aVariable == min(b,n))
                  return -1;
      }
      comps++;
      if(a[aVariable] == x)
            return aVariable;
      return -1;

}
int min(int a, int b){
      //printf("a = %d, b = %d\n",a, b);
      if(a >= b)
            return b;
      return a;
}
void calcJumpSearchASLsuccAndASLunsucc(int a[], int size){
      int x;
      double findlength=0;
	int findcount=0;
	double notfindlength=0;
	int notfindcount=0;
      for(int i=0;i<2*size;i++){
            x=rand();
            //printf("here\n");
            if(jumpSearch(a,size,x) != -1){//found comps, not found
                  findcount++;
                  findlength+=comps;
            }
                  //printf("find %d needs %d(comparison )\n",x,comps);
            else
            {
                  notfindcount++;
                  notfindlength+=comps;
            }
      }
      //printf("%.2lf\n",findlength);
      double aslsucc=0,aslunsucc=0;
      if(findcount>0)
            aslsucc=findlength/findcount;
      if(notfindcount>0)
            aslunsucc=notfindlength/notfindcount;
      printf("ASLsucc = %.2lf ASLunsucc=%.2lf\n",aslsucc,aslunsucc);
}

// create open hash table
// len si the size of hash table
// num is number of values to be inserted into the hashtable
void createOpenHashTable(int hashTable[], int a[] ,int len, int num){
      int i;
      // let all the element in the hash table -1.
      // and -1 means empty
      for(i=0; i<len ; i++)
            hashTable[i] = -1;
      int finished;
      int key;
      int index;

      for(i = 0 ; i < num; i++){
            finished = 0;
            key = a[i];



            index = hash(key, len);
            do{
                  if(hashTable[index] == -1){// the place is note occupy it's empty.
                        printf(" key =  %d  \n", key);
                        hashTable[index] = key; // insert the element
                        finished = 1; // break the do/while loop
                        //printf("insert %d at pos = %d \n", key, index);// display the element and its position.
                  }
                  else if(hashTable[index] == key){// if the element is already in the hash table . means we don't have duplicate.
                        finished = 1; // break the do/while loop
                        //printf("%d is already in the hash table at pos = %d \n", key, index);
                  }
                  else{// if the place occupy.
                        index = hash( index+1, len);
                        // why we haven't use index++;
                        // okay, because we need to loop inside the array
                        // to go again from 0 for example 27%9 = 0.
                  }
            }while(!finished); // determent the do/while loop.
      }
}
// search for x in open hash table
// len is length of hash table
// if found, return its position, else return -1;
int openHashSearch(int hashTable[], int len, int x){
      int k=0;
      int index;
      comps = 0;
      index = hash(x, len);
      int i =1;
      do{
            comps++;
            /*printf("HERE\n");
            printf("index = %d\n", index);
            printf("hashTable[index]  = %d\n", hashTable[index] );*/
            if(hashTable[index] == -1){

                  return -1;// not found.
            }
            else if(hashTable[index] == x)
                  return index; // found
            else
                  index = hash(index+1, len);
      }while(i < len); // MaxSize m
      return -1;


}
int hash(int x, int len){

      return x%9;
}
void calcOpenHashSearchASLsuccAndASLunsucc(int a[], int size){
      int x;
      double findlength=0;
	int findcount=0;
	double notfindlength=0;
	int notfindcount=0;
      for(int i=0;i<2*size;i++){
            x=rand();
            //printf("here\n");
            if(openHashSearch(a,size,x) != -1){//found comps, not found
                  findcount++;
                  findlength+=comps;
            }
                  //printf("find %d needs %d(comparison )\n",x,comps);
            else
            {
                  notfindcount++;
                  notfindlength+=comps;
            }
      }
      //printf("%.2lf\n",findlength);
      double aslsucc=0,aslunsucc=0;
      if(findcount>0)
            aslsucc=findlength/findcount;
      if(notfindcount>0)
            aslunsucc=notfindlength/notfindcount;
      printf("ASLsucc = %.2lf ASLunsucc=%.2lf\n",aslsucc,aslunsucc);

}
void InitLinkHashTable( HashItem *HashTable[],int len){
	long i;
	for(i=0;i<len;i++)
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
void CreateLinkHashTable(HashItem *HashTable[],int len,int num)
{
	InitLinkHashTable(HashTable,len);

	int val;
	int index;
	int n=0;
	while(n<num)
      {

            scanf("%d",&val);
            index = hash(val,len);

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
      int index = hash(x,len);
      HashItem *head = HashTable[index];
      if (FindNode(head,x)==1)
            return index;
      return -1;

}
/*

8
7 24 18 52 36 54 11 23


*/