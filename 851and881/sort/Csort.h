#ifndef OPP_CSORT_CSORT_H
#define OPP_CSORT_CSORT_H
class Csort {
private:
    int part(int* arr,int l,int r);
    int aux[362880];
    void MergeAux(int arr[],int l,int mid,int r);
    long int factory[11]={1,1,2,6,24,120,720,5040,40320,362880,3628800};
    bool Cantor(int arr[],int n);
    bool isDeterministic(int arr[],int n);
public:
    void ManualInput(int arr[],int n);
    void AutoInput(int arr[],int n);
    void AutoOut(int arr[],int n);
    void Bubble(int arr[],int n);//冒泡排序
    void Selection(int arr[],int n);//选择排序
    void Shell(int arr[],int n);//希尔排序
    void Insertion(int arr[],int n);//插入排序
    void Merge(int arr[],int l,int r);//归并排序
    void Quick(int arr[],int l,int r);//快速排序
    void Bucket(int arr[],int n);//桶排序
    void DeterministicSequence(int arr[],int n);//确定序列是排好的序列

    void TestBubble(int arr[],int n);
    void TestSelection(int arr[],int n);
    void TestShell(int arr[],int n);
    void TestInsertion(int arr[],int n);
    void TestMerge(int arr[],int n);
    void TestQuick(int arr[],int n);
    void TestBucket(int arr[],int n);
};
#endif //OPP_CSORT_CSORT_H