void bubble_sort(int v[],int size){
    for(int i=0;i<size;i++){
        for (int j = 0; j < size-i ; ++j) {
            if(v[j]<v[j+1]){
                int aux= v[j];
                v[j]= v[j+1];
                v[j+1]=aux;
            }
        }
    }
}

void insertion_sort(int v[],int size){
    int j,temp;
    for(int i=0;i<size;i++){
        j=i-1;
        temp=v[i];
        while(j>=0 && v[j]>temp){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=temp;
    }
}
void direct_selection_sort(int v[],int size){

    for(int i=0;i<size;i++){
        for (int j = 0; j <size ; ++j) {
            if(v[i]<v[j]){
                int temp=v[j];
                v[j]=v[i];
                v[i]=temp;
            }
        }
    }
}
