#include <iostream>
#include "Csort.h"
using namespace std;
void Csort::ManualInput(int *arr, int n) {
    for(int i=0;i<n;i++)
        cin>>arr[i];
}

void Csort::AutoInput(int *arr, int n) {
    for(int i=0;i<n;i++)
        arr[i]=rand()%(n*1)+1;
}
void Csort::AutoOut(int *arr, int n) {
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void Csort::Bubble(int *arr, int n) {
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(arr[j]>arr[j+1]){
                int t;
                t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
            }
        }
}

void Csort::TestBubble(int arr[],int n) {
    AutoInput(arr,n);
    Bubble(arr,n);
    AutoOut(arr,n);
}

void Csort::Selection(int *arr, int n) {
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[min]>arr[j]){
                int t;
                t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
            }
        }
    }
}

void Csort::TestSelection(int *arr, int n) {
    AutoInput(arr,n);
    Selection(arr,n);
    AutoOut(arr,n);
}

void Csort::DeterministicSequence(int *arr, int n) {
    if(isDeterministic(arr,n)) cout<<"Ture"<<endl;
    else cout<<"Flase"<<endl;
}

bool Csort::isDeterministic(int *arr,int n) {
    for(int i=0;i<n-1;i++)
        if(arr[i]>arr[i+1]) return 0;
    return 1;
}

bool Csort::Cantor(int arr[],int n){
    long res=0;


    for(int i=0;i<n;i++){
        int con=0;
        for(int j=i+1;j<n;j++){//遍历第一个数到最后一个
            if(arr[i]>arr[j]){
                ++con;
            }
        }
        res+=con*factory[n-i-1];//被选中的数后面还有几个数的全排列

    }
    if(res==0) return 1;
    else return 0;

}

void Csort::Shell(int *arr, int n) {
    int h=1;//希尔系数
    while(h<n/3) h=h*3+1;
    while(h>=1){//h  能等于1说明复杂度最坏能到O(n2)
        for(int i=h;i<n;i++){
            for(int j=i;j>h&&arr[j]<arr[j-h];j-=h){
                int t;
                t=arr[j];
                arr[j]=arr[j-h];
                arr[j-h]=t;
            }

        }
        h=h/3;
    }
}

void Csort::TestShell(int *arr, int n) {
    AutoInput(arr,n);
    Shell(arr,n);
    AutoOut(arr,n);
}

void Csort::Insertion(int *arr, int n) {
    for(int i=1;i<n;i++){
        for(int j=i;j>0&&arr[j]<arr[j-1];j++){
            int t;
            t=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=arr[j];
        }
    }
}

void Csort::TestInsertion(int *arr, int n) {
    AutoInput(arr,n);
    Insertion(arr,n);
    AutoOut(arr,n);
}

void Csort::Bucket(int *arr, int n) {

    int t=0;
    int tt=0;
    int min = 0;
    int max=0;
    for (int i = 0; i < n; i++){
        if (arr[min] > arr[i]) min = i;
        if(arr[max]<arr[i]) max=i;
    }
    min=arr[min];
    max=arr[max];
    int Bucket[max-min];
    for(int i=0;i<(max-min);i++)
        Bucket[i]=0;
    for(int i=0;i<n;i++){
        arr[i]=0;
        if(min<0) arr[i]+=-min;
    }
    for(int i=0;i<n;i++)
        Bucket[arr[i]]++;
    while(Bucket[t]){
        if(Bucket[t]>0){arr[tt]=t;}
        t++;tt++;
    }
}

void Csort::TestBucket(int *arr, int n) {
    AutoInput(arr,n);
    Bucket(arr,n);
    AutoOut(arr,n);
}

void Csort::Quick(int *arr, int l,int r) {
    if(l>=r)
        return;
    int j=part(arr,l,r);
    Quick(arr,l,j-1);
    Quick(arr,j+1,r);
}
int Csort::part(int *arr, int l, int r) {
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
void Csort::TestQuick(int *arr, int n) {
    AutoInput(arr,n);
    Quick(arr,0,n);
    AutoOut(arr,n);
}

void Csort::Merge(int *arr, int l,int r) {
    if(l>=r) return;
    int mid=(l+r)/2;
    Merge(arr,l,mid);
    Merge(arr,mid+1,r);
    MergeAux(arr,l,mid,r);

}
void Csort::MergeAux(int *arr, int l,int mid, int r) {
    int i=l,j=mid+1;
    for(int k=l;k<=r;k++)
        aux[k]=arr[k];
    for(int k=l;k<=r;k++){
        if(i>mid) arr[k]=aux[j++];
        else if(j>r) arr[k]=aux[i++];
        else if(aux[i]>aux[j]) arr[k]=aux[j++];
        else   arr[k]=aux[i++];
    }

}
void Csort::TestMerge(int *arr, int n) {
    AutoInput(arr,n);
    Merge(arr,0,n);
    AutoOut(arr,n);
}
