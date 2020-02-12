#include <cstdio>
int main(){
#pragma omp parallel for
    for(int i=0;i<10;i++){
        printf("%i\n",i);
    }
    return 0;
}//
// Created by Cygnus on 2/13/2020.
//

