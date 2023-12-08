template<class T>
void Heap<T>::push(T item){
    ensureCapacity(capacity);
    elements[count]=item;
    reheapUp(count);
    count++;
}

template<class T>
void Heap<T>::ensureCapacity(int minCapacity){
    if(count<capacity) return;
    capacity++;
    T*elementsnew =new T[capacity];
    for(int i=0;i<count;i++){
        elementsnew[i]=elements[i];
    }
    delete[]elements;
    elements=elementsnew;
}

template<class T>
void Heap<T>::reheapUp(int position){
    int n=(position-1)/2;
    if(position==0||elements[n]>=elements[position]) 
        return;
    else{
        T temp=elements[position];
        elements[position]=elements[n];
        elements[n]=temp;
        reheapUp(n);
    }
}