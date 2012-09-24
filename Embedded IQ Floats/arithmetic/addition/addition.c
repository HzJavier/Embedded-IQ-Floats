/* Addition Source File */

#include "addition.h"


uint32_t normalizeAddition(uint16_t number, uint8_t *sign)
{
    uint32_t completedNumber=0;
    *sign +=1;
    
    completedNumber = (uint32_t)((~number)+1);
    return ((~number)+1);
}

uint16_t performAddition(uint16_t operandA,uint8_t qFormatA,uint16_t operandB,uint8_t qFormatB, uint8_t qFormatResult)
{
    uint32_t temporalResult,opA,opB;
    uint16_t realResult;
    
    uint8_t signA=0;
    uint8_t signB=0;
    
    opA = (operandA & 0x8000)?(normalizeAddition(operandA, &signA)):(uint32_t)operandA;
    opB = (operandB & 0x8000)?(normalizeAddition(operandB, &signB)):(uint32_t)operandB;
    
    opA <<= (16-qFormatA);
    opB <<= (16-qFormatB);
    
    if(signA==signB)
    {
        temporalResult = opA+opB;
        
        if(signA)
        {
            temporalResult = (~temporalResult)+1;
        }
    }
    else
    {
        if(opA>opB)
        {
            temporalResult = opA-opB;
            
            if(signA)
            {
                temporalResult = (~temporalResult)+1;
            }
        }
        else
        {
            temporalResult = opB-opA;
            
            if(signB)
            {
                temporalResult = (~temporalResult)+1;
            }
        }
    }
    
    realResult = temporalResult>>(16-qFormatResult);

    return realResult;
}