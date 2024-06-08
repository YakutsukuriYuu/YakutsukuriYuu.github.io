
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

ElemType findX(List list){
    ElemType oldnum=0;
    ElemType num;
    int old=1;
    int tol=1;

    for(int i=0;i<list.length-1;i++){
        for(int j=i+1;j<list.length;j++){
            if(list.data[i]==list.data[j]){
                num=list.data[i];
                tol++;
            }
        }
        if(old<tol) {
            old=tol;
            oldnum=num;
        }
        tol=1;
    }
    if(old>list.length/2) return oldnum;
    else return -1;
}


int part(int *arr, int l, int r) {
    int i=l,j=r+1;
    int v=arr[l];
    while(1){
        while(arr[++i]<v) if(i==r) break;
        while(arr[--j]>v) if(j==l) break;
        if(i>=j) break;
        int t;
        t=arr[i];
        arr[i]=arr[j];
        arr[j]=t;
    }
    int t;
    t=arr[l];
    arr[l]=arr[j];
    arr[j]=t;
    return j;//切分位置 就是中心位置
}
void Quick(int *arr, int l,int r) {
    if(l>=r)
        return;
    int j=part(arr,l,r);
    Quick(arr,l,j-1);
    Quick(arr,j+1,r);
}


//排序后 线性扫描
//复杂度取决于排序的复杂度
ElemType findX2(List list){
    Quick(list.data,0,list.length);
    debug(list);
    int i=0,j=1;
    int len=1;
    ElemType num;
    while(j<list.length){
        if(list.data[i]==list.data[j]){
            j++;
        }
        else {
            if(j-i>len){
                len=j-i;
                num=list.data[i];
                // cout<<"i:"<<i<<endl;
                // cout<<"j:"<<j<<endl;
                // cout<<"len:"<<len<<endl;
            }
            i=j++;
        }
    }
    if(j==list.length && list.data[i]==list.data[j-1]){
        //cout<<"-----------"<<endl;
        len=j-i;
        num=list.data[i];
    }

    // cout<<"i:"<<i<<endl;
    // cout<<"j:"<<j<<endl;
    // cout<<"len:"<<len<<endl;
    if(len>list.length/2) return num;
    else return -1;
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
    cout<<findX2(list)<<endl;
    //function




    for(int i=0;i<list.length;i++){
        cout<<list.data[i];
    }

    return 0;
}


