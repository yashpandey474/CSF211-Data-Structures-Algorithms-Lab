//FIND MEDIAN OF FIRST, LAST AND MIDDLE ELEMENT
int median(int a, int b, int c){
    if(a<=b && b<=c || c<=b && b<=a){
        return b;
    }
    if(b<=a && b<=c || c<=a && a<=b){
        return a;
    }
    if(a<=c && c<=b || b<=c && c<=a){
        return c;
    }
}
int medianOfThree(int* arr, int lo, int hi){
    int med = median(lo, hi, (lo+hi)/2);
    if(med == arr[lo]){
        return lo;
    }
    if(med == arr[hi]){
        return hi;
    }
    return (lo+hi)/2;
}
int main(){
    
}