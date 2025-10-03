#include <criterion/criterion.h>
#include "operations/subtraction.h"

Test(operations_subtraction, one){
    int actual = operations_subtract(2, 3);
    int expected = -1;
    cr_assert(actual == expected);
}

Test(operations_subtraction, two){
    int actual = operations_subtract(2, -3);
    int expected = 5;
    cr_assert(actual == expected);
}
