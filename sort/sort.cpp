#include <iostream>
#include <string>

using namespace std;

void Quicksort(int number[],int a,int b,int c,int d)
{	if(a<b)
	{
		int pk =number[a];
		int i=a,j=b+1;
		do
		{	
			do
			{	
			    i++;
			}while(number[i]<pk);
			
			do
			{
			    j--;
			}while(number[j]>pk);
			if(i<j)
			{	
			   	int temp = number[i];
				number[i] = number[j];
				number[j] = temp;
				
			}
		}while(j>i);
		int temp = number[a];
		number[a] = number[j];
		number[j] = temp;
		
		
		cout << "[" ;
		for(int z=c ; d>=z ; z=z+1 )
		{	
		    cout << number[z] ;
		    if(z!=d)  
			{
				cout << ", " ;
			}
		}
			cout << "]" ;
			cout << "" <<endl;
			
		Quicksort(number,a,j-1,c,d);
		Quicksort(number,j+1,b,c,d);
	}	
}		

	
void ListMerge(int number[], int l, int u, int m,int c,int d) 
{	cout << ""<<endl ;
	int n1 = m - l + 1;
	int n2 = u - m;
	
	int* L = new int[n1];
	int* R = new int[n2];

	for (int i = 0; i < n1; i++) 
	{
		L[i] = number[l+i]; 
	}
	for (int i = 0; i < n2; i++) 
	{
		R[i] =number[i+m+1]; 
	}
	L[n1] = 9999999;
	R[n2] = 9999999;
	int i = 0, j = 0;
	
	cout << "[" ;
	for (int k = l; k <= u; k++) 
	{	
		if (L[i] <= R[j]) {
			number[k] = L[i];
			i++;
		}
		else {
			number[k] = R[j];
			j++;
		}
		cout << number[k] ;
		    if(k!=u)  
			{
				cout << ", " ;
			}
	}
	cout << "]" ;
	
	
/*	cout << "[" ;
		for(int z=c ; d>=z ; z=z+1 )
		{	
		    cout << number[z] ;
		    if(z!=d)  
			{
				cout << ", " ;
			}
		}
			cout << "]" ;
			cout << "" <<endl; */ 
	
}

void Mergesort(int number[], int l, int u,int c,int d) 
{
	if (l < u) 
	{
		int m = (l + u ) / 2;
		Mergesort(number, l, m,c,d);  
		Mergesort(number, m + 1, u,c,d); 
		
		ListMerge(number, l, u, m,c,d);  
		
	}
}

void HeapAdjust(int number[],int a,int i)
{
    int b;
    b=number[a];	
    for(int j=2*a;j<=i;j=j*2)
    {	
    	
	    if(j<i)
	    {
	        if (number[j]<number[j+1]) j++;
	    }
	    if(b>number[j]) break;
	    number[a]=number[j];
		a=j;
		
    }
    number[a]=b;
}
void HeapSort(int number[],int i,int c,int d)
{	
    int temp,a;
    for(a=i/2;a>0;a--)
    {	
        HeapAdjust(number,a,i);
    }
    cout << ""<<endl;
    cout << "初始max heap:";
    cout << "[" ;
		for(int z=c ; d>=z ; z=z+1 )
		{	
		    cout << number[z] ;
		    if(z!=d)  
			{
				cout << ", " ;
			}
		}
			cout << "]" ;
			cout << "" <<endl;
			
    cout << "" <<endl;
    for(a=i;a>0;a--)  
    {
        temp=number[1];
        number[1]=number[a];
        number[a]=temp;        			
        HeapAdjust(number,1,a-1);
        
        cout << "[" ;
        for(int z=c ; d>=z ; z=z+1 )
		{	
		    cout << number[z] ;
		    if(z!=d)  
			{
				cout << ", " ;
			}
		}
			cout << "]" ;
			cout << "" <<endl;
    }
}	

void Insert(int number[],int r, int i)
{

} 

void Insort (int number[],int n)
{
	
}

int main(void)
{ 	
  	int input;
   	cout << "1.Bubble Sort ; 2.Quick Sort ; 3.Merge Sort ; 4.Heap Sort ; 5.Insertion Sort"<<endl;
   	cout << ""<<endl;
	cout << "請選擇排序種類:";	
	cin>>input;
	cout << ""<<endl;
	cout << "輸入需排序字串:";	
	
	
		int number[100];    					
    	int i=0;
    	char y;
    
    	do
   		{
    		cin >> number[i];
    		i++;
   		}while(y=getchar()!='\n');
	
    
    

	if(input==1)
	{	
		cout << "使用的是Bubble Sort"<<endl;
			for(int a=0;a<i;a++)
			{	int f=0;
				for(int b=0;b<i-1-a;b++)
				{	
					if(number[b]>number[b+1])
					{
						int temp = number[b];
						number[b] = number[b+1];
						number[b+1] = temp;
						f=1;
						cout << "[" ;
					for(int j=0 ; j<i ; j=j+1 )
	    			{	
	       				cout << number[j] ;
	        			if(j!=i-1)  
						{
							cout << ", " ;
						}
	    			}
					cout << "]"<<endl ;
					} 
					
				}
				if(f==0) break;
			}
		
	}
		
	else if(input==2)
	{		
		cout << "使用的是Quick Sort"<<endl;	
		int b=i+1;
		
		Quicksort(number,0,i-1,0,i-1);
		
	}
	else if(input==3)
	{		
		cout << "使用的是Merge Sort"<<endl;	
		Mergesort(number, 0, i-1,0,i-1);
	}
	else if(input==4)
	{	
		cout << "使用的是Heap Sort"<<endl;
		for(int a=i-1;a>=0;a--)
		{
			number[a+1] = number[a];
			
		}
		
		HeapSort(number,i,1,i);
	}
	else if(input==5)
	{		
		cout << "使用的是Insertion Sort"<<endl;	
		
		for (int j = 0; j < i; j++) 
			{
    			int a = j;
    			while (a > 0 && (number[a - 1] > number[a]) )
				{
      				int temp = number[a];
      				number[a] = number[a - 1];
      				number[a - 1] = temp;
      				a--;
      				
	      			cout << "[" ;
					for(int j=0 ; j<i ; j=j+1 )
					{	
					    cout << number[j] ;
					    if(j!=i-1)  
						{
							cout << ", " ;
						}
					}
						
						cout << "]" <<endl;
	    		}
	    			
  			}
		
	}

	if(input!=4)
	{
		cout << ""<<endl;	
		cout << ""<<endl;
		cout << "result:[" ;
		for(int j=0 ; j<i ; j=j+1 )
		{	
		    cout << number[j] ;
		    if(j!=i-1)  
			{
				cout << ", " ;
			}
		}
			cout << "]" ;
	} 
	
	if(input==4)
	{
		cout << ""<<endl;	
		cout << ""<<endl;
		cout << "result:[" ;
		for(int j=1 ; j<i+1 ; j=j+1 )
		{	
		    cout << number[j] ;
		    if(j!=i)  
			{
				cout << ", " ;
			}
		}
			cout << "]" ;
	} 
	    
	
	 return 0;
}


