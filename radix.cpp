#include<iostream>
using namespace std;
int getmax(int *a,int n){
	int m=*(a+0);
	for(int i=0;i<n;i++)
	{
		if(m<*(a+i))
			m=*(a+i);
	}
	return m;
}
int getmaxbit(int *a,int n,int ex){
	int m=(*(a+0)/ex)%10;
	for(int i=0;i<n;i++)
	{
		if(m<(*(a+i)/ex)%10)
			m=(*(a+i)/ex)%10;
	}
	return m;
}
void in(int a[],int n){
	for(int i=0;i<n;i++)
		cin>>a[i];

}
void show(int a[],int n){
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	cout<<endl<<"-------------------------"<<endl;
}
void countsort(int a[],int n,int ex){
	int k,j,i;
	k=getmaxbit(a,n,ex);
	
	int cnt[k+1];
	int op[n];
	for(int i=0;i<=k;i++){
		cnt[i]=0;
	}
	for(i=0;i<n;i++){
		cnt[(a[i]/ex)%10]++;
	}
	for(i=1;i<=k;i++){
		cnt[i]+=cnt[i-1];
	}
	for(i=n-1;i>=0;i--){
		j=cnt[(a[i]/ex)%10]-1;
		op[j]=a[i];
		cnt[(a[i]/ex)%10]--;
	}	
	for(i=0;i<n;i++)
		a[i]=op[i];
}
void radix(int a[],int n){
	int m,i=0;
	int ex=1;
	m=getmax(a,n);
	while((m/ex)!=0){
		countsort(a,n,ex);
		ex*=10;
		cout<<"Pass "<<i<<endl;
		show(a,n);
		i++;
	}
}
int main(void){
	int n;
	cout<<"Enter size ";
	cin>>n;
	int a[n];
	in(a,n);
	radix(a,n);
	show(a,n);
}
