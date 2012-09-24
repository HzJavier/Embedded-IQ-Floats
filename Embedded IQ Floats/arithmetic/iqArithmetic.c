//
//  division.c
//  QFloats
//
//  Created by Arturo Javier Hernández Barrón on 9/4/12.
//  Copyright (c) 2012 Arturo Javier Hernández Barrón. All rights reserved.
//

#include "iqArithmetic.h"


void performIqOperation(uint8_t operation, qParams_t * params)
{
    switch (operation)
    {
        case 0:
        {
            params->operationResult = performAddition(params->operandA, params->qFormatA, params->operandB, params->qFormatB, params->qFormatResult);
        }break;
            
        case 1:
        {
            params->operationResult = performMultiplication(params->operandA, params->qFormatA, params->operandB, params->qFormatB, params->qFormatResult);
        }break;
            
        case 2:
        {
            params->operationResult = performDivision(params->operandA, params->qFormatA, params->operandB, params->qFormatB, params->qFormatResult);
        }break;
            
        default:
            break;
    }
}