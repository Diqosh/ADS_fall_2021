#include <iostream>

using namespace std;

struct MinHeap{
    int capacity;
    int heap_size;
    int *arr;
    MinHeap(int cap){
        capacity = cap;
        heap_size = 0;
        arr = new int[capacity];
    }

    int parent(int i ) { return (i-1)/2; }
    int left_child(int i) { return (2*i + 1); }
    int right_child(int i) { return (2*i + 2); }


    void insert(int k){
        if (heap_size == capacity){
            cout << "\nOverflow: Could not insertKey\n";
            return;
        }

        heap_size++;
        int i = heap_size - 1;
        arr[i] = k;

        //sorting heap

        while(i != 0 && arr[parent(i)] < arr[i]){   //change
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    int extract_min(){
        if (heap_size <= 0)
            return INT_MAX;
        return arr[0];
    }

    void delete_heap_root(){
        if (heap_size <= 0)
            return;
        else{
            arr[0] = arr[--heap_size];
            int i = 0;
            ;           while (left_child(i) < heap_size){

                int leftChild = left_child(i);
                int rightChild = right_child(i);
                int minPositionChild = leftChild;


                if(arr[rightChild] > arr[leftChild]){            //change
                    minPositionChild = rightChild;
                }


                if(arr[i] < arr[minPositionChild]) {             //change
                    swap(arr[i], arr[minPositionChild]);
                    i = minPositionChild;
                }else{
                    break;
                }
            }
        }
    }
    int shift_up(int index, int plus){
        if (0 < index and index < heap_size){
            arr[index - 1] += plus;
            int i = index - 1;
            while(i > 0 and arr[parent(i)] < arr[i]){
                swap(arr[parent(i)] , arr[i]);
                i = parent(i);
            }
            return ++i;
        }
        return -1;
    }

    bool empty(){
        return heap_size <= 0;
    }

    void print(){
        for (int i = 0; i < heap_size; ++i) {
            cout << arr[i] << " ";
        }
    }
};

int main(){
    //freopen("D:\\kbtu\\3\\2021\\ADS\\hm3\\informatics\\1.txt", "r", stdin);
    int cap;cin >> cap;
    MinHeap hp(cap);
    int arr[cap];
    for (int i = 0; i < cap; ++i) {
        cin >> arr[i];
    }
    for ( auto i : arr){
        hp.insert(i);
    }
    int n, index, plus;cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> index >> plus;
        cout << hp.shift_up(index, plus) << endl;
    }


    hp.print();

    return 0;
}
