#ifndef  MAIN_FUNCIONAL_TESTS

#define MAIN_FUNCIONAL_TESTS

#include "funcional_tests.h"

#include "../../include/Model.h"

#include "../../include/System.h"

#include "../../include/flow.h"

int main(){

    exponentialFuncionalTest();

    logisticalFuncionalTest();

    complexFuncionalTest();
    
    return 0;

}

#endif