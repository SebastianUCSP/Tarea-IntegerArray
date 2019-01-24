#include <iostream>

using namespace std;

class IntegerArray {
    private:
        int *data; int size;
    public:

        IntegerArray() {
        data = new int[0];
        this->size = 0;
        }

        IntegerArray(int arr[], int size) {
        this->data = new int[size];
        this->size = size;
        for (int i = 0; i < size; ++i)
            data[i] = arr[i];
        }

        IntegerArray(IntegerArray &o) {
        data = new int[o.size];
        size = o.size;
        for (int i = 0; i < size; ++i)
            data[i] = o.data[i];
        }

        void resize(int newSize){
            int *arr = new int[newSize];

            int minSize = (newSize > size)?size:newSize;
            for(int i = 0; i < minSize; i++)
                arr[i] = data[i];

            delete[] data;
            size = newSize;
            data = arr;
        }


        void push_back(int val) {
            resize(size+1);
            //this ->size = size+1;
            int *arr = new int[size];

            for(int i=0;i<size-1;++i){
                arr[i]=data[i];
            }
            arr[size-1]=val;
            delete[] data;
            data = arr;
        }

        void insert(int val, int pos) {
            resize(size+1);
            // this->size= size +1;
            int *arr1 = new int [size];
            for( int i = 0, j = 0; i < size ; i++, j++){
                if ( i == pos ){
                    arr1[i] = val;
                    j--;
                }
                else
                    arr1[i]= data[j];
            }
            delete[] data;
            data = arr1;
        }

        void remove(int pos) {

            //this->size--;
            int *arr = new int [size];

            for (int i=0, j=0; i<size; ++i, ++j)
            {
                if (i==pos) j++;
                arr[i] = data[j];
            }

            resize(size-1);

            delete[] data;
            data = arr;
        }

        void print() {
            for(int i =0; i < size; i++){
                cout << data[i] << " ";
            }
            cout << endl;
        }

        int getSize() {
            return size;
        }

        ~IntegerArray() {
            delete[] data;
        }
};

int main() {
    int arr[] = {1,2,3,4,5};
    IntegerArray a(arr, 5);
    a.print();
    a.push_back(6);
    a.print();
    a.insert(10,5);
    a.print();
    a.remove(3);
    a.print();
    //cout << a.getSize() << endl; // 4
}
