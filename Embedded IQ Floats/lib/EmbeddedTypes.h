/************************************************************************************
* This file holds type definitions that maps the standard c-types into types
* with guaranteed sizes. The types are target/platform specific and must be edited
* for each new target/platform.
*
* The header file also provides definitions for TRUE, FALSE and NULL.
*************************************************************************************/

#ifndef _EMBEDDEDTYPES_H_
#define _EMBEDDEDTYPES_H_

typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed long int32_t;
typedef unsigned long uint32_t;


#define TRUE 1
#define FALSE 0



#endif /* _EMBEDDEDTYPES_H_ */
