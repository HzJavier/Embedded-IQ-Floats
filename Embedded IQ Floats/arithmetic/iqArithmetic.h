/* IQ Arithmetic Header File */
#ifndef __iqArithmetic_h_
#define __iqArithmetic_h_

#include "EmbeddedTypes.h"

#include "division.h"
#include "multiplication.h"
#include "addition.h"


typedef struct 
{
  uint16_t  operandA;
  uint16_t  operandB;
  uint16_t  operationResult;
  uint8_t   qFormatA;
  uint8_t   qFormatB;
  uint8_t   qFormatResult;

}qParams_t;


uint16_t add(void);
uint16_t multiply(void);
uint16_t divide(void);
void performIqOperation(uint8_t operation, qParams_t *params);


#endif



