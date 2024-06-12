
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
ElemType findMid(List l1,List l2){
    List l3;
    l3.length=l1.length+l2.length;
    for(int i=0;i<l1.length;i++){
        l3.data[i]=l1.data[i];
        //l3.data[i+l1.length]=l2.data[i];
    }
    for(int i=0;i<l2.length;i++){
        l3.data[i+l1.length]=l2.data[i];
    }
    
    //debug(l3);
    for(int i=0;i<l3.length-1;i++){ //bubble
        for(int j=i+1;j<l3.length;j++){
            if(l3.data[i]>l3.data[j]){
                swap(l3.data[i],l3.data[j]);
            }
        }
    }
    debug(l3);
    int mid=(1.0*l3.length)/2+0.5;//向上取整 mid的小数点数字只可能是0.5
    return l3.data[mid];
}
//归并算法是效率最高的，
ElemType MergeFindMid(List l1,List l2){
    List l3;
    l3.length=l1.length+l2.length;
    int i=0,j=0,k=0;
    while(i<l1.length || j<l2.length){
        if(l1.data[i]<l2.data[j]){
            l3.data[k++]=l1.data[i++];
        }
        else{
            l3.data[k++]=l2.data[j++];
        }
    }
    while(i<l1.length) l3.data[k++]=l1.data[i++];
    while(j<l2.length) l3.data[k++]=l2.data[j++];
    int mid=(1.0*l3.length)/2+0.5;//向上取整 mid的小数点数字只可能是0.5
    return l3.data[mid];
}
int main(){
    List list1,list2;
    list1.length=0;
    list2.length=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>list1.data[i];
        list1.length++;
    }
    debug(list1);
    for(int i=0;i<n;i++){
        cin>>list2.data[i];
        list2.length++;
    }
    debug(list2);
    //cout<<MergeFindMid(list1,list2);
    cout<<findMid(list1,list2);
    return 0;
}


