#include "Linear.h"
using namespace std;

void swap(ElemType& a,ElemType& b){
    ElemType t;
    t=a;
    a=b;
    b=t;
}
void swapmn(List& list,int m,int n){
    List temp;
    temp.length=list.length;
    for(int i=0;i<=m-1;i++){
        temp.data[n+i]=list.data[i];
    }
    for(int i=m;i<=m+n-1;i++){
        temp.data[i-m]=list.data[i];
    }
    list=temp; 
}

int main(){
    List list;
    list.length=0;
    int n,p;
    cin>>n>>p;
    for(int i=0;i<n;i++){
        cin>>list.data[i];
        list.length++;
    }

    swapmn(list,p,n-p);
    for(int i=0;i<list.length;i++){
        cout<<list.data[i];
    }

    return 0;
}


