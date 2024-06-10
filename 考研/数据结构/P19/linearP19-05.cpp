#include "Linear.h"
#include <cstdlib>
#include <list>
using namespace std;
void swap(ElemType&a ,ElemType& b){
    ElemType t;
    t=a;
    a=b;
    b=t;
}

//k维护合法的数
void Del_x(List& list,ElemType x,int l,int r){
    int k=0;
    for(int i=l;i<=r;++i){
        if(list.data[i]!=x){
            list.data[k]=list.data[i];
            k++;
        }

    }


}
void Del_same(List& list){
    int p=-1;
    for(int i=0;i<list.length;++i){
        if(list.data[i]==0){
            p=i;
            break;
        }
    }
    int len=0;
    for(int i=0;i<=list.length-2;i++){
        for(int j=i+1;j<=list.length-1;++j){
            if(list.data[i]==list.data[j] && list.data[j]>=list.data[i]){
                list.data[j]=0;
            }
        }
    }
    for(int i=0;i<list.length;++i){
        if(list.data[i]!=0) len++;
    }
    //for(int i=0;i<list.length;++i)
    //    cout<<list.data[i];
    //cout<<endl;
    
    Del_x(list,0,0,p-1);
    Del_x(list,0,p+1,list.length-1);
    //cout<<"len:"<<len<<endl;
    list.length=len+(p>=0?1:0);
    //cout<<"length"<<list.length<<endl;

}
//有序表，i维护有序表，j一轮扫描
bool Del_same1(List& list){
    if(list.length==0) return false;
    int i,j;
    for(i=0,j=1;j<=list.length-1;j++){
        if(list.data[j]!=list.data[i]){
            list.data[++i]=list.data[j];
        }
    }
    list.length=i+1;
    return true;
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

    Del_same(list);


    for(int i=0;i<list.length;i++){
        cout<<list.data[i];
    }

    return 0;
}
