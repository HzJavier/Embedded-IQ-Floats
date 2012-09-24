//
//  multiplication.c
//  QFloats
//
//  Created by Arturo Javier Hernández Barrón on 8/28/12.
//  Copyright (c) 2012 Arturo Javier Hernández Barrón. All rights reserved.
//

#include <stdio.h>
#include "multiplication.h"

uint16_t normalizeMultiplication(uint16_t number, uint8_t *sign)
{
    *sign+=1;
    *sign%=2;
    return ( (~number )+1 );
}


uint16_t performMultiplication(uint16_t operandA,uint8_t qFormatA,uint16_t operandB,uint8_t qFormatB, uint8_t qFormatResult)
{
    uint32_t temporalResult;
    uint16_t opA,opB;
    volatile uint16_t realResult;
    uint8_t operationSign = 0;
    
    // Set values as positives
    opA = (operandA & 0x8000)?(normalizeMultiplication(operandA, &operationSign)):operandA;
    opB = (operandB & 0x8000)?(normalizeMultiplication(operandB, &operationSign)):operandB;
    
    // Perform the operation
    temporalResult = (uint32_t)opA*(uint32_t)opB;
    
    // Center the result
    temporalResult <<= (16-(qFormatA+qFormatB));
    
    // Set the sign of result
    if (operationSign)
    {
        temporalResult = (~temporalResult)+1;
    }
    
    // Fit the result in the needed format
    realResult = temporalResult>>(16-qFormatResult);
    return realResult;
}