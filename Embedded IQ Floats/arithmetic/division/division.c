//
//  division.c
//  QFloats
//
//  Created by Arturo Javier Hernández Barrón on 9/4/12.
//  Copyright (c) 2012 Arturo Javier Hernández Barrón. All rights reserved.
//

#include "division.h"


uint32_t normalizeDivision(uint16_t number, uint8_t *sign)
{
    uint32_t completedNumber=0;
    *sign +=1;
    
    completedNumber = (uint32_t)((~number)+1);
    return completedNumber;
}

uint16_t performDivision(uint16_t operandA,uint8_t qFormatA,uint16_t operandB,uint8_t qFormatB, uint8_t qFormatResult)
{
    uint32_t temporalResult, opA, opB;
    uint16_t realResult;
    uint8_t operationSign = 0;
    
    if(!operandB)
    {
        return 0;
    }
    
    // Set values as positives
    opA = (operandA & 0x8000)?(normalizeDivision(operandA, &operationSign)):operandA;

    opB = (operandB & 0x8000)?(normalizeDivision(operandB, &operationSign)):operandB;
    
    // Set the value to be divided of 32 bits
    opA <<=16;
        
    // Perform the operation
    temporalResult = opA/opB;
    
    // Set the final point where it should be
    temporalResult = (qFormatA>qFormatB)? temporalResult>>(qFormatA-qFormatB): temporalResult<<(qFormatB-qFormatA);

    // Check for negative result
    if(operationSign==1)
    {
        temporalResult = (~temporalResult)+1;
    }
    
    realResult = temporalResult >>(16-qFormatResult);

    return realResult;
}