#include "unset_bits.h"

long eliminate_unset_bits(string number){
    size_t len = number.length();
    size_t count = 0;
    for(size_t i = 0; i < len; i++){
        if (number[i] == '1'){
            number[count++] = '1';
        }
    }
    number.resize(count);
    long data = (number == "") ? 0 : stol(number, nullptr, 2);
    return data;
}