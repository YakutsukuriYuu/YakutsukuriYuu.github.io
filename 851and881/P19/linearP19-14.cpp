
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
ElemType abs(ElemType a,ElemType b){
    return (a-b>=0?a-b:b-a);
}
int getDistance(List s1,List s2,List s3){
    int dis=abs(s1.data[0]-s2.data[0])+abs(s2.data[0]-s3.data[0])+abs(s3.data[0]-s1.data[0]);
    for(int i=0;i<s1.length;i++){
        for(int j=0;j<s2.length;j++){
            for(int k=0;k<s3.length;k++){
                int temp=abs(s1.data[i]-s2.data[j])+abs(s2.data[j]-s3.data[k])+abs(s3.data[k]-s1.data[i]);
                if(dis>temp) dis=temp;
            }
        }
    }
    return dis;
}

bool xIs_min(int a,int b,int c){
    if (a<=b&&a<=c) return true;
    return false;
}


int getD(List s1,List s2,List s3){
    int i=0,j=0,k=0,D_min=0x7fffffff,D;
    while(i<s1.length && j<s2.length && k<s3.length && D_min>0){
        D=abs(s1.data[i]-s2.data[j])+abs(s2.data[j]-s3.data[k])+abs(s3.data[k]-s1.data[i]);
        if(D<D_min) D_min=D;
        if(xIs_min(s1.data[i],s2.data[j],s3.data[k])) i++;
        else if(xIs_min(s2.data[j],s3.data[k],s1.data[i])) j++;
        else k++;
    }
    return D_min;
}
int main(){
    List s1,s2,s3;
    s1.length=0;
    s2.length=0;
    s3.length=0;
    int len1,len2,len3;
    cin>>len1>>len2>>len3;
    for(int i=0;i<len1;i++){
        cin>>s1.data[i];
        s1.length++;
    }
    for(int i=0;i<len2;i++){
        cin>>s2.data[i];
        s2.length++;
    }
    for(int i=0;i<len3;i++){
        cin>>s3.data[i];
        s3.length++;
    }

    //function
    //cout<<getDistance(s1,s2,s3);
    cout<<getD(s1,s2,s3);


    return 0;
}


