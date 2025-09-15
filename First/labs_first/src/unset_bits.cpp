#include "unset_bits.h"

long eliminate_unset_bits(string number){
    int len = number.length();
    int count = 0;
    for(int i = 0; i < len; i++){
        if (number[i] == '1'){
            number[count++] = '1';
        }
    }
    number.resize(count);
    long data = (number == "") ? 0 : stol(number, nullptr, 2);
    return data;
}