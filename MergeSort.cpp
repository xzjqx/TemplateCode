/*
TASK: MergeSort
LANG: C++
NOTE: Descending Order
*/
#include <cstdio>

int sum;

void Merge(int src[],int tmp[],int start,int mid,int end) {
    int i=start,j=m+1,k=start;
    while(i!=m+1&&j!=end+1) {
        if(src[i]<=src[j])
            tmp[k++]=src[i++];
        else {
            tmp[k++]=src[j++];
            sum+=(m-start-i+1);
        }
    }
    while(i!=m+1)
        tmp[k++]=src[i++];
    while(j!=end+1)
        tmp[k++]=src[j++];
    for(i=start;i<=end;i++)
        src[i]=tmp[i];
}

void MergeSort(int src[],int tmp(),int start,int end) {
    int m;
    if(start<end) {
        m=(end+start)/2;
        MergeSort(src,tmp,start,m);
        MergeSort(src,tmp,m+1,end);
        Merge(src,tmp,start,m,end);
    }
}

int main()
{

}
