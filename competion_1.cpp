#include <iostream>
 using namespace std;
 
double sum_mutiple(int n){
    double sum=0;
    int mutiple_3=n/3;
    int mutiple_5=n/5;
    int mutiple_15=n/15;
    cout<<(3*(mutiple_3+1)*mutiple_3)/2<<" "<<(5*(mutiple_5+1)*mutiple_5)/2<<endl;
    sum=(3*(mutiple_3+1)*mutiple_3)/2+(5*(mutiple_5+1)*mutiple_5)/2-(15*(mutiple_15+1)*mutiple_15)/2;
    return sum;
}
int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        printf("%.0lf\n",sum_mutiple(n-1));
    }
    return 0;
}

