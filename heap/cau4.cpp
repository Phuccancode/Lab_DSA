template<class T>
int Heap<T>::getItem(T item) {
    for(int i = 0 ; i < count ; i++){
        if(elements[i] == item){
            return i;
        }
    }
    return -1;
}

template<class T>
void Heap<T>::remove(T item) {
    // TODO: remove the element with value equal to item
    int index = getItem(item);
    
    swap(elements[count - 1], elements[index]);
    count --;
    reheapDown(index);
}

template<class T>
void Heap<T>::clear() {
    //delete[] elements;
    count = 0;
}