
#include "Linear.h"
using namespace std;

void swap(ElemType& a,ElemType& b){
    ElemType t;
    t=a;
    a=b;
    b=t;
}

/*
给定 三个序列A、B、C，长度均为n ，且均为无重复元素的递增序列，请设计一个时间 上尽可能高效的算法，逐行输出同时存在于这三个序列中的所有元素 。例如，数组A为 {1 , 2 , 3 ]， 数 组 B 为 {2 , 3 ， 4 ]， 数 组 C 为 {- 1 , 0 . 2 }， 则 输 出 2 。 要 求 :
1 )给出算法的基本设计思想。
2 )根据设计思想，采用C 或C++语言描述算法，关键之处给出注释。
3 )说明你的算法的时间复杂度和空间复杂度。
*/
ElemType min(ElemType a,ElemType b,ElemType c){
    a=(a>=b?a:b);
    return (a>=c?a:c);
}
List mergeAll(List A,List B,List C){
    List All;
    All.length=A.length+B.length+C.length;
    for(int i=0;i<A.length;i++){
        All.data[i]=A.data[i];
        All.data[i+A.length]=B.data[i];
        All.data[i+A.length+B.length]=C.data[i];
    }
    // for(int i=0;i<All.length;i++){
    //     cout<<All.data[i]<<" ";
    // }
    for(int i=0;i<All.length-1;i++){
        for(int j=i+1;j<All.length;j++){
            if(All.data[i]>All.data[j]){
                swap(All.data[i],All.data[j]);
            }
        }
    }//bubble
    return All;
}
List MergeList(List l1,List l2,List l3){
    List all;
    all.length=l1.length+l2.length+l3.length;
    int i=0,j=0,l=0;
    int k=0;
    while(i<l1.length && j<l2.length && l<l3.length){
        if(l1.data[i]<=l2.data[j] && l1.data[i]<=l3.data[l]){ //这里要不严格小于 用小于要加else
            all.data[k++]=l1.data[i++];
        }
        else if(l2.data[j]<=l1.data[i] && l2.data[j]<=l3.data[l]){
            all.data[k++]=l2.data[j++];
        }
        else if(l3.data[l]<=l1.data[i] && l3.data[l]<=l2.data[j]){
            all.data[k++]=l3.data[l++];
        }
    }
    while(i<l1.length && j<l2.length){ //处理l1 和 l2
        if(l1.data[i]<l2.data[j]){     //这里严不严格都可以
            all.data[k++]=l1.data[i++];
        }     
        else{
            all.data[k++]=l2.data[j++];
        }  

    }
    while(i<l1.length && l<l3.length){ //l1 l3 
        if(l1.data[i]<l3.data[l]){
            all.data[k++]=l1.data[i++];
        }
        else{
            all.data[k++]=l3.data[l++];
        }
    }
    while(j<l2.length && l<l3.length){//l2 l3
        if(l2.data[j]<l3.data[l]){
            all.data[k++]=l2.data[j++];
        }
        else{
            all.data[k++]=l3.data[l++];
        }
    }
    while(i<l1.length) all.data[k++]=l1.data[i++]; //处理剩余
    while(j<l2.length) all.data[k++]=l2.data[j++];
    while(l<l3.length) all.data[k++]=l3.data[l++];
    return all;

}
List MergeList2(List l1,List l2){
    List all;
    all.length=l1.length+l2.length;
    int i=0,j=0,k=0;
    while(i<l1.length && j<l2.length){
        if(l1.data[i]<l2.data[j]) all.data[k++]=l1.data[i++];
        else all.data[k++]=l2.data[j++];
    }
    while(i<l1.length) all.data[k++]=l1.data[i++];
    while(j<l2.length) all.data[k++]=l2.data[j++];
    return all;
}
List Function(List l1,List l2,List l3){
    return MergeList2(l3,MergeList2(l1,l2));   
}
int main(){
    List list1,list2,list3;
    list1.length=0;
    list2.length=0;
    list3.length=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>list1.data[i];
        list1.length++;
    }
    for(int i=0;i<n;i++){
        cin>>list2.data[i];
        list2.length++;
    }
    for(int i=0;i<n;i++){
        cin>>list3.data[i];
        list3.length++;
    }
   // List list=mergeAll(list1,list2,list3);
    //List list=MergeList(list1,list2,list3);
    List list=Function(list1,list2,list3);
    //function




    for(int i=0;i<list.length;i++){
        cout<<list.data[i]<<" ";
    }

    return 0;
}


