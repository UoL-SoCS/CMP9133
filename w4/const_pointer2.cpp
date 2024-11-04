
void main(){
    int x1 = 10;
    int x2 = 20;

    int* const y = &x1;
    y = &x2;
}