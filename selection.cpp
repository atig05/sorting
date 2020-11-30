#include<iostream>
#include<stdlib.h>
using namespace std;
void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}
void in(int ar[],int n){
	cout<<"Enter elements "<<endl;
	for(int i=0;i<n;i++)
		cin>>ar[i];
}
void show(int ar[],int n){
	int i=0;
	for(i=0;i<n;i++)
		cout<<ar[i]<<" ";
	cout<<endl<<endl;
}
int selection(int a[],int n){
	int i,j,t,ti,c;
	int pass=0;
	for(i=0;i<n;i++){
		t=a[i];
		ti=0;
		c=0;
		for(j=i+1;j<n;j++){
			if(t>a[j]){
				t=a[j];
				ti=j;
				c+=1;
				
			}
			
			pass++;	
		}
		if(c!=0){
			swap(&a[i],&a[ti]);
			show(a,n);
		}
			
	}
	return pass;
}

int main(void){
	int a[5],y;
	in(a,sizeof(a)/sizeof(int));
	y=selection(a,sizeof(a)/sizeof(int));
	show(a,sizeof(a)/sizeof(int));
	cout<<y<<" No of passs"; 
	return 0;
}
