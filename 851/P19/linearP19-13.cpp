
#include "Linear.h"
using namespace std;
void swap(ElemType& a,ElemType& b){
    ElemType t;
    t=a;
    a=b;
    b=t;
}
void debug(List list){
    for(int i=0;i<list.length;i++)
        cout<<list.data[i]<<" ";
    cout<<endl; 
}


ElemType findMinZ(List list){ //正整数，直接桶排序

    ElemType max=-1;
    for(int i=0;i<list.length;i++){
        if(list.data[i]>max) max=list.data[i];
    }//找到最大值。
    //给桶分配最大空间
    List buket;
    buket.length=max;
    for(int i=0;i<=max;i++){
        buket.data[i]=0;
    }
    for(int i=0;i<list.length;i++){
        if(list.data[i]<=0) continue;
        buket.data[list.data[i]]++;
    }    
    for(int i=1;i<=max;i++){
        if(buket.data[i]==0) return i;
    }
    return max+1;
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

    //function

    cout<<findMinZ(list);


    for(int i=0;i<list.length;i++){
        cout<<list.data[i];
    }

    return 0;
}


