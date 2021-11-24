#include<iostream>
using namespace  std;
void show(int a[],int i,int n){
	for(int j=i;j<n;j++)
		cout<<a[j]<<" ";
	cout<<endl;
}
void in(int a[],int n){
	for(int i=0;i<n;i++)
		cin>>a[i];
}
void print(int a[],int n){
	for(int i=0;i<n;i++)
		cout<<a[i];
}
void merge(int a[],int l,int m,int r){
	int a1[m-l+1];
	int a2[r-m];
	int k=0;
	for(int i=0;i<=m-l;i++)
		a1[i]=a[i+l];
	k=0;
	//show(a1,)
	for(int i=0;i<r-m;i++)
		a2[i]=a[i+m+1];
	int j=0,o=0;
	k=l;
//	show(a2,0,m-l);
	while(j<m-l+1 && o<r-m){
		if(a1[j]>=a2[o])
			a[k]=a2[o++];
		else
			a[k]=a1[j++];
		k++;
	}
	while(j<=m-l){
		a[k]=a1[j];
		k++;
		j++;
	}
		
	while(o<r-m){
		a[k]=a2[o];
		k++;
		o++;
	}
		
//	show(a,l,r+1);	
}
void merge_sort(int a[],int l,int n){
	//int r=n-1;
	if(l>=n)
		return;
	int m=l+(n-l)/2;
	merge_sort(a,l,m);
	merge_sort(a,m+1,n);
	merge(a,l,m,n);
	
}
int main(void){
	int n;
	cout<<"Size of the array-";
	cin>>n;
	int a[n];
	cout<<"ENTER ELEMENTS-";
	in(a,n);
	merge_sort(a,0,sizeof(a)/sizeof(a[0]));
	show(a,0,n);
}
