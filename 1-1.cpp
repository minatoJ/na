#include<iostream>
#define _RESET_BIT(x, y) x &= ~(0x01<<(y))
#define _SET_BIT(x, y) x |= 0x01<<(y)
#define _GET_BIT(x, y) (x>>(y)) & 0x01
using namespace std;

void BitMapInit(unsigned int bitMap[], int len){
    for (int i=0; i<len; i++){
        bitMap[i] = 0;
    }
}

void BitMapSet(unsigned int bitMap[], int bit){
    _SET_BIT(bitMap[bit>>5], bit - ((bit>>5)<<5));
}

int BitMapGet(unsigned int bitMap[], int bit){
    return _GET_BIT(bitMap[bit>>5], bit - ((bit>>5)<<5)); 
}

bool IsUniqueChar(char *p){
    unsigned int bitMap[4];
    BitMapInit(bitMap, 4);

    while(*p != '\0'){
        int bit = *p++;
        cout<<bit<<endl;
        if(BitMapGet(bitMap, bit)){
            return false;
        }
        else{
            BitMapSet(bitMap,bit);
        }
    }

    return true;
}
int main(){
    unsigned int bitMap[4];
    BitMapInit(bitMap, 4);
    char *p = "abcdefa";
    cout<< IsUniqueChar(p)<<endl;

}

