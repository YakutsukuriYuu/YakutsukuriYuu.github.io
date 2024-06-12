#include "Linear.h"
using namespace std;

void swap(ElemType& a,ElemType& b){
    ElemType temp=a;
    a=b;
    b=temp;
}


bool Del_s_t(List& list,ElemType s,ElemType t){ 
    if(s>=t || list.length==0) return false;
    int j=list.length-1;
    for(int i=0;i<=j;++i){
        if(list.data[i]>=s && list.data[i]<=t){
            swap(list.data[i--],list.data[j--]);
            list.length--;
        }
    }
    return true;
}

//答案的写法
bool Del_s_t_01(List& list,ElemType s,ElemType t){ 
    if(s>=t || list.length==0) return false; 
    int k=0;
    for(int i=0;i<list.length;++i){
        if(list.data[i]>=s && list.data[i]<=t){ 
            k++;
        }
        else{
            list.data[i-k]=list.data[i];

        }
    }
    list.length-=k;
    return true;
}

//同理，答案没给出的写法
bool Del_s_t_02(List& list,ElemType s,ElemType t){ 
    if(s>=t || list.length==0) return false; 
    int k=0;
    for(int i=0;i<list.length;++i){
        if(list.data[i]<s || list.data[i]>t){ //注意 用或
            list.data[k]=list.data[i];
            k++;
        }
    }
    list.length=k;
    return true;
}

int main(){
    List list;
    list.length=0;
    int n;
    int s;
    int t;
    cin>>n>>s>>t;
    for(int i=0;i<n;i++){
        cin>>list.data[i];
        list.length++;
    }
    Del_s_t_01(list,s,t);
    for(int i=0;i<list.length;i++){
        cout<<list.data[i];
    }

}


