#include <iostream>
using namespace std;
long *a;
long sum=0;
using namespace std;

long fibonaci(int k){
    if(k==0){
        a[0]=2;
        return a[0];
    }
    if(k==1){
        a[1]=8;
        return a[1];
    }
    if(a[k]!=0)
        return a[k];
    else {
        a=(long*)realloc(a,(k+2)*sizeof(long));
        a[k+1]=0;
        a[k]=fibonaci(k-1)*4+fibonaci(k-2);
        return a[k];
    }
}
void sum_even_fibonaci(int k, int n){
    long b=fibonaci(k);
    if(b%2==0 && b<=n){
        sum=sum+b;
    }
    if(b<n)
    {
        sum_even_fibonaci(k+1,n);
    }
}
int main(){
    a=(long*)calloc(3,sizeof(long)*3);
    int t;
    cin >> t;
    for(int a0 = 0;a0 < t;a0++){
        long n;
        cin >> n;
        sum_even_fibonaci(0,n);
        cout<<sum<<endl;
        sum=0;
    }
    return 0;
}

