#include "Linear.h"
using namespace std;


void swap(ElemType& a,ElemType& b){
    ElemType temp=a;
    a=b;
    b=temp;
}

void Inversion(List &list){
    for(int i=0;i<list.length/2;++i){
        swap(list.data[i],list.data[list.length-1-i]);
    }
}


int main(){

    List list;
    list.length=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>list.data[i];
        list.length++;
    }

    Inversion(list);


    for(int i=0;i<n;i++){
        cout<<list.data[i];
    }


    return 0;
}