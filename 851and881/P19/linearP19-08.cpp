
#include "Linear.h"
using namespace std;

bool log(List& list,ElemType x){
    ElemType l=0;
    ElemType r=list.length-1;
    ElemType p=(l+r)/2;
    bool flag=true;
    while(list.data[p]!=x){
        if(l>=r) {flag=false;break;}
        if(list.data[p]>x){
            r=p-1;
        }
        else{
            l=p+1;
        }
        p=(l+r)/2;
    }
    if(flag){
        ElemType t=list.data[p];
        list.data[p]=list.data[p+1];
        list.data[p+1]=t;
    }
    else{
        for(int i=0;i<list.length;i++)
            if(list.data[i]>x){
                for(int j=list.length-1;j>=i;j--){
                    list.data[j+1]=list.data[j];
                    
                    
                }
                list.data[i]=x;
                list.length++;
                break;
            }

    }
    return flag;
}


int main(){
    List list;
    list.length=0;
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>list.data[i];
        list.length++;
    }

    //function
    log(list,x);




    for(int i=0;i<list.length;i++){
        cout<<list.data[i];
    }

    return 0;
}


