#include <sstream>
#include <iostream>
#include <type_traits>

using namespace std;

template <class T>
class Sorting {
private:
    static T* Partition(T* start, T* end) ;
public:
    static void QuickSort(T* start, T* end) ;
};

template <class T>
 T* Sorting<T>::Partition(T* start, T* end) {
    T* arr = start;
    int low = 0, high = end - start - 1;
    int pivot = arr[low];
    int i = low, j = high + 1;
 
    do {
        // Find leftmost element greater than
        // or equal to pivot
 //! Tìm phần tử bên trái đầu tiên lớn hơn hoặc bằng pivot
        do {
            i++;
        } while (arr[i] < pivot);
 
        // Find rightmost element smaller than
        // or equal to pivot
 //!     Tìm phần tử bên phải đầu tiên nhỏ hơn hoặc bằng pivot
        do {
            j--;
        } while (arr[j] > pivot);
 
        // If two pointers met.
        if (i >= j){
            break;
        }
 //! Đổi chỗ hai phần tử không đúng thứ tự
        swap(arr[i], arr[j]);
    }   while(i <= j);
//!         Đưa pivot vào vị trí đúng trong mảng con bên trái.
    if(i <= j) swap(arr[i], arr[j]);
    swap(arr[low], arr[j]);
    cout << j << " ";
    return start + j;
}
template <class T>
 void  Sorting<T>::QuickSort(T* start, T* end) {
    if(start < end){
        T* privot = Partition(start, end);
        QuickSort(start, privot);
        QuickSort(privot+1,end);
    }
}

int main(){
    int array[] = { 3, 5, 7, 10 ,12, 14, 15, 13, 1, 2, 9, 6, 4, 8, 11, 16, 17, 18, 20, 19 };
    cout << "Index of pivots: ";
    Sorting<int>::QuickSort(&array[0], &array[20]);
    cout << "\n";
    cout << "Array after sorting: ";
    for (int i : array) cout << i << " ";
}