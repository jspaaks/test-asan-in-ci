#include <criterion/criterion.h>
#include "operations/addition.h"

Test(operations_addition, one){
    int actual = operations_add(2, 3);
    int expected = 5;
    cr_assert(actual == expected);
}

Test(operations_addition, two){
    int actual = operations_add(2, -3);
    int expected = -1;
    cr_assert(actual == expected);
}
