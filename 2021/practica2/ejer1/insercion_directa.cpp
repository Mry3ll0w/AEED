#include <iostream>
using namespace std;//Avoid using std:: ....
void orden_insercion(int *,int);
int main(){

    int v[6]={4,7,2,35,12,8};
    orden_insercion(v,6);
    for (int i = 0; i < 6; i++)
    {
        cout<<v[i]<<endl;
    }
    return 0;
    
}

void orden_insercion(int v[], int size){
 int j,temp;
    for(int i=0; i<size; i++){
        temp=v[i];
        j=i-1;
        while(j>=0 && v[j] >temp){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = temp;
 }
}