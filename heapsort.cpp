#include<iostream>
using namespace std;
void swap(int *a,int *b){
	int t=*b;
	*b=*a;
	*a=t;
}
void show(int a[],int n){
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
void in(int a[],int n){
	for(int i=0;i<n;i++)
		cin>>a[i];
}
int lchild(int i){
	return 2*i;
}
int rchild(int i){
	return 2*i+1;
}
void heapadjust(int a[],int k,int N){
//	show(a,N);
	int n=N-1;
	if(k>N/2){
	//	cout<<"hola"<<endl;
		return;	
	}

	if(a[k-1]<a[lchild(k)-1] && lchild(k)-1<N)
		swap(&a[k-1],&a[lchild(k)-1]);
	if(a[k-1]<a[rchild(k)-1]&& rchild(k)-1<N)
		swap(&a[k-1],&a[rchild(k)-1]);		
}
void heapify(int a[],int n){
	for(int i=n/2;i>0;i--)
		heapadjust(a,i,n);
}
void heapsort(int a[],int n){
	heapify(a,n);
	//show(a,n);
	int t;
	for(int i=n;i>1;i--){
		//show(a,n);
		swap(&a[i-1],&a[0]);
		heapify(a,i-1);
		show(a,n);
	}
}
int main(void){
	int n;
	cout<<"SIZE OF THE ARRAY--";
	cin>>n;
	int a[n];
	cout<<"ENTER THE ARRAY "<<endl;
	in(a,n);
	heapsort(a,n);
	cout<<"--SORTED ARRAY--"<<endl;
	show(a,n);
	return 23;
}
