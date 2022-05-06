#include <stdio.h>
#include <stdlib.h>
#include "printf.h"

int main(){
    int result=my_printf("%c %s %d %o %x", 'A', "Hello from my friend printf", 10, 100, 1000);
}