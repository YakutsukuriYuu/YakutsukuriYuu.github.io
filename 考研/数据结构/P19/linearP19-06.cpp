
#include "Linear.h"
#include <algorithm>
using namespace std;

ElemType max(ElemType a,ElemType b){
    return a>b?a:b;
}
ElemType min(ElemType a,ElemType b){
    return a<b?a:b;
}
List merge(List& list1,List& list2){
    List mlist;
    mlist.length=list1.length+list2.length;
    int j1=0,j2=0;
    for(int i=0;i<mlist.length;++i){
        if(list1.data[j1]<list2.data[j2]){
            mlist.data[i]=list1.data[j1++];
        }
        else{
            mlist.data[i]=list2.data[j2++];
            if(j2>list2.length-1) j2=list2.length-1;
        }
        if(j1==list1.length){
            for(;j2<list2.length;++j2)
                mlist.data[++i]=list2.data[j2];
                cout<<"123"<<endl;
            break;
        }
        if(j2==list2.length){
            for(;j1<list1.length;++j1)
                mlist.data[++i]=list1.data[j1++];
            break;
        }

    }
    return mlist;
}
//双指针问题，类似的问题用while会方便
List merge2(List& list1,List& list2){
    List mlist;
    mlist.length=list1.length+list2.length;
    int i=0,j=0,k=0;
    while(i<list1.length && j<list2.length){
        if(list1.data[i]<list2.data[j]) mlist.data[k++]=list1.data[i++];
        else mlist.data[k++]=list2.data[j++];
    }
    if(i<j) while(i<list1.length) mlist.data[k++]=list1.data[i++];
    else while(j<list2.length) mlist.data[k++]=list2.data[j++];
    return mlist;
}

int main(){
    List list1,list2,mlist;
    list1.length=0;
    list2.length=0;

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>list1.data[i];
        list1.length++;
    }
    for(int i=0;i<m;i++){
        cin>>list2.data[i];
        list2.length++;
    }
    //function
    mlist=merge2(list1,list2);
    for(int i=0;i<mlist.length;i++){
        cout<<mlist.data[i];
    }

    return 0;
}


