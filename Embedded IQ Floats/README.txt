//
//  main.c
//  Embedded IQ Floats
//
//  Created by Arturo Javier Hernández Barrón on 9/22/12.
//  Copyright (c) 2012 Arturo Javier Hernández Barrón. All rights reserved.
//

#include <stdio.h>
#include "iqArithmetic.h"

int main(int argc, const char * argv[])
{
    qParams_t testParams;
    testParams.operandA = 2;
    testParams.operandB = 4;
    testParams.qFormatA = 0;
    testParams.qFormatB = 0;
    testParams.qFormatResult = 0;
    
    performIqOperation(1, &testParams);

    return 0;
}

