#include<iostream>
using namespace std;
class maxheap{
    int *arr;
    int size;
    int total_size;
    public:
    maxheap(int n){
        arr=new int[n];
        size=0;
        total_size=n;
    }
    
    void insert(int value){
        if(size==total_size){
            cout<<"overflow cant add "<<value<<"\n"<<"your list is\n";
            return ;
        }
        arr[size]=value;
        int index=size;// this index is used to insert data at its proper position
        size++;
        while(index>0&&arr[(index-1)/2]<arr[index]){
            swap(arr[(index-1)/2],arr[index]);
            index=(index-1)/2;
        }
       
    }
     void print(){
            for(int i=0;i<size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
    }
    void heapify(int index){
        int largest=index;
        int left=2*index+1;
        int right=2*index+2;
        if(left<size&&arr[left]>arr[largest])
        largest=left;
        if(right<size&&arr[right]>arr[largest])
        largest=right;
        if(largest!=index){
            swap(arr[largest],arr[index]);
            heapify(largest);
        }
    }
    void Delete(){
        if(size==0){
            cout<<"heap underflow\n";
            return ;
        }
        arr[0]=arr[size-1];
        size--;
        if(size==0)
        return;
        heapify(0);
    }
        
        
};
int main(){
    maxheap h1(5);
    h1.insert(8);
    h1.insert(5);
    h1.insert(9);
    h1.print();
    h1.Delete();
    h1.Delete();
    h1.Delete();
    h1.Delete();
    h1.insert(2);
    h1.insert(10);
    h1.insert(4);
    h1.print();
    return 0;
}
