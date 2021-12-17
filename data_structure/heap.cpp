#include <iostream>
#include <vector>

using namespace std;
#define ll unsigned long long
struct Heap {
public:
    int heap_size;
    vector<int> arr;

    Heap() {

        heap_size = 0;

    }

    ll parent(int i) { return (i - 1) / 2; }

    ll left_child(int i) { return (2 * i + 1); }

    ll right_child(int i) { return (2 * i + 2); }


    void insert(int k) {
        heap_size++;
        int i = heap_size - 1;
        arr.push_back(k);

        //sorting heap

        while (i != 0 && arr[parent(i)] < arr[i]) {   //change
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    int extract_root() {
        if (heap_size <= 0)
            return -1;
        return arr[0];
    }

    void delete_root() {
        if (heap_size <= 0)
            return;
        else {
            arr[0] = arr[--heap_size];
            int i = 0;
            while (left_child(i) < heap_size) {

                int leftChild = left_child(i);
                int rightChild = right_child(i);
                int minPositionChild = leftChild;


                if (arr[rightChild] > arr[leftChild]) {            //change
                    minPositionChild = rightChild;
                }


                if (arr[i] < arr[minPositionChild]) {             //change
                    swap(arr[i], arr[minPositionChild]);
                    i = minPositionChild;
                } else {
                    break;
                }
            }
        }
    }

    int shift_up(int index, int plus) {
        if (0 < index and index < heap_size) {
            arr[index - 1] += plus;
            int i = index - 1;
            while (i > 0 and arr[parent(i)] < arr[i]) {
                swap(arr[parent(i)], arr[i]);
                i = parent(i);
            }
            return ++i;
        }
        return -1;
    }

    int heapify(int i) {
        if (left_child(i) > arr.size() - 1)
            return i;

        int j = left_child(i);
        if (right_child(i) < arr.size() && arr[left_child(i)] < arr[right_child(i)])
            j = right_child(i);
        if (arr[i] < arr[j]) {
            swap(arr[i], arr[j]);
            return heapify(j);
        }
        else{
            return i;
        }

    }
    int shift_down(int i, int k){
        arr[i] -= k;
        return heapify(i);
    }

    bool empty() {
        return heap_size <= 0;
    }

    void print() {
        for (int i = 0; i < heap_size ; ++i) {
            cout << arr[i] << " ";
        }
    }
};

int main(){
    Heap hp(100);
    int a[] = { 1,24,6,8,2345,534,6,24};
    for (auto i :a) {
        hp.insert(i);
    }
    while (!hp.empty()){
        cout << hp.extract_min() << endl;
        hp.delete_heap_root();
    }

    return 0;
}