#include "unset_bits.h"

int main() {
    string number;
    cout << "Enter string: ";
    cin >> number;
    
    cout << eliminate_unset_bits(number) << endl;

    return 0;
}