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
int bubble(int a[],int n){
	int i,j,t,pass=0;
	for(i=0;i<n-1;i++){
		t=0;
		for(j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				swap(&a[j],&a[j+1]);
				t+=1;
				
				show(a,n);
			}
			pass++;
			if(t==0)
				break;	
		}
		
	}
	return pass;
}

int main(void){
	int a[5],o;
	in(a,sizeof(a)/sizeof(int));
	o=bubble(a,sizeof(a)/sizeof(int));
	show(a,sizeof(a)/sizeof(int));
	cout<<o<<"No of comparision ";
	return 0;
}
