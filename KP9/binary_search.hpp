#include "reading.hpp"

int binary_search(int e){
    int low = 0, high = 28, middle;
    while(low <= high){
        middle = (high+low)/2;

        if(e>middle)low = middle+1;
        else if(e<middle) high = middle-1;
        else return middle;
    }
    return -1;

}
