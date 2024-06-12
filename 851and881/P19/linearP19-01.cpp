#include "Linear.h"
using namespace std;

ElemType Del_min(List &list){
    if(list.length==0) return 0;
    ElemType mmin=list.data[0];
    int pos=0;
    for(int i=0;i<list.length;++i){
        if(mmin>list.data[i]){
            mmin=list.data[i];
            pos=i;
        }

    }
    ElemType min_val=list.data[pos];
    list.data[pos]=list.data[list.length-1];
    list.length--;
    return min_val;
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
    cout<<Del_min(list)<<endl;

    return 0;
}