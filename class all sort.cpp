#include<iostream>
#include<stdlib.h>
#define size 15
using namespace std;
void push(int a[],int n){
	for(int i=0;i<n;i++)
		cin>>a[i];
}
void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}
class sorting{
	public:
	int arr[size];
	int a[size];
	int n;
	void in(int ar[],int c){
		for(int i=0;i<c;i++)
			arr[i]=ar[i];
		n=c;
	}
	void put(){
		for(int i=0;i<n;i++)
			a[i]=arr[i];
	}
	void show()
	{
		for(int i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	int bubblesort(){
		int pass=0,com=0;
		int i,j,t=0;
		for(i=0;i<n;i++){
			t=0;
			for(j=0;j<n-i-1;j++){
				if(a[j]>a[j+1]){
					swap(&a[j],&a[j+1]);
					com++;
					t++;
				}
					
				pass++;
				cout<<"compairing "<<a[j+1]<<" and "<<a[j]<<" pass "<<pass<<"- ";
				show();

			}
				if(t==0)
					break;
		}
		cout<<"No of swaps "<<com<<endl;
		cout<<"Total pass "<<pass<<endl;
		return pass;
	}
	int selectionsort(){
		int pass=0,com=0;
		int i,j;
		for(i=0;i<n-1;i++){
			int m=a[i];
			int mi=i;
			for(j=i+1;j<n;j++){
				if(m>a[j]){
					m=a[j];
					mi=j;
				}
			pass++;
			cout<<"compairing "<<a[i]<<" and "<<a[mi]<<" pass "<<pass<<"- ";	
			show();											
			}
			if(mi!=i){
				swap(&a[mi],&a[i]);
				com++;
			}
				
		}
		show();
		cout<<"No of swaps "<<com<<endl;
		cout<<"Total pass "<<pass<<endl;
		return pass;
	}
	int insertionsort(){
		int i,j,k,pass=0;
		for(i=1;i<n;i++){
			int t=a[i];
			j=i-1;
			cout<<"compairing "<<a[j]<<" and "<<t<<" pass "<<pass<<"- ";
			while(pass++ &&t<a[j] && j>=0){
				
					a[j+1]=a[j];
					j--;
				cout<<"swaping"<<a[j]<<" and "<<t<<" pass "<<pass<<"- ";
				show();
					
				}
			a[j+1]=t;
	
			
		}
		show();
		cout<<"Total pass "<<pass<<endl;
		return pass;
	}
	
	void allsort(){
		int p=0,i;
		cout<<"                   Bubble sort "<<endl;
		put();
		p=bubblesort();
		if(p<=n*n && p>n)
			cout<<"Time complexity O(n^2)"<<endl;
		else if(p<=n)
			cout<<"Time complexity O(n)"<<endl;
		
		cout<<endl;
		cout<<"Press 1 for next ";
		cin>>i;
		if(i==1){
			system("CLS");
			cout<<"                Selection sort "<<endl;
			put();
			p=selectionsort();
		if(p<=n*n && p>n)
			cout<<"Time complexity O(n^2)"<<endl;
		else if(p<=n)
			cout<<"Time complexity O(n)"<<endl;			
		}
		cout<<endl;
		cout<<"Press 1 for next ";
		cin>>i;
		if(i==1){
			system("CLS");
			cout<<"                inserti0n sort "<<endl;
			put();
			p=insertionsort();
		if(p<=n*n && p>n)
			cout<<"Time complexity O(n^2)"<<endl;
		else if(p<=n)
			cout<<"Time complexity O(n)"<<endl;			
		}
									
	}
};
int main(void){
	int n;
	cout<<"Enter size";
	cin>>n;
	int ar[n];
	push(ar,n);
	sorting x;
	x.in(ar,n);
	x.allsort();
	return 0;
}
