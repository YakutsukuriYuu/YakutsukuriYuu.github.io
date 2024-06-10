#include "Linear.h"
using namespace std;

void swap(ElemType& a,ElemType& b){
    ElemType temp=a;
    a=b;
    b=temp;
}

void Del_x(List& list,ElemType x){
    int j=list.length-1;
    for(int i=0;i<=j;++i){
        if(list.data[i]==x) {
            swap(list.data[i--],list.data[j--]);
            list.length--;
        }

    }
}


void Del_x_01(List& list,ElemType x){ //答案的写法1
    int k=0;
    for(int i=0;i<list.length;++i){
        if(list.data[i]!=x){ //注意不等于
            list.data[k]=list.data[i];
            ++k;
        }
    }
    list.length=k;
}
//答案2的写法 用for也可以
void Del_x_02(List& list,ElemType x){ 
    int k=0;
    int i=0;
    while(i<list.length){
        if(list.data[i]==x){ 
            ++k;
        }
        else{
            list.data[i-k]=list.data[i]; 
        }
        i++;
    }
    list.length-=k;
}



int main(){
    List list;
    list.length=0;
    int n;
    int x;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>list.data[i];
        list.length++;
    }
    //Del_x(list,x);
    Del_x_02(list,x);
    for(int i=0;i<list.length;i++){
        cout<<list.data[i];
    }

}

//x 可能连续出现 错误代码
//     for(int i=0;i<list.length-1;++i){
//         if(list.data[i]==x) swap(list.data[i],list.data[i+1]);
//         --list.length;
//     }
//     if(list.data[list.length-1]==x) --list.length;
// }
