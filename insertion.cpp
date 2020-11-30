#include<iostream>
#include<stdlib.h>
using namespace std;
void swap(int *a,int *b){
	int t=*b;
	*b=*a;
	*a=t;
}
void in(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
}
void show(int a[],int n){
		int i;
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl<<endl;
}
int insertion(int a[],int n){
	int i,j,k,pass=0;
	for(i=1;i<n;i++){
		int t=a[i];
		j=i-1;
		while(pass++&& t<a[j] && j>=0){
				a[j+1]=a[j];
				j--;
			
				
			}
		a[j+1]=t;
			
		show(a,5);
	}
	return pass;
}
int main(void){
	int a[5],y;
	in(a,sizeof(a)/sizeof(int));
	y=insertion(a,sizeof(a)/sizeof(int));
	show(a,sizeof(a)/sizeof(int));
	cout<<y<<" No of passs"; 
	return 0;
}
