/**
 * @brief  Stack data structure in C
 * @author Shady nabil
 * @date   April 23, 2023
*/
#ifndef _STACK_H_
#define _STACK_H_

#include <stdlib.h>
#include <stdarg.h>
#include "Platform_Types.h"

#define ZERO_ELEMENTS -1

typedef enum
{
    FALSE,
    TRUE,
} bool_t;

typedef union
{
    struct
    {
        uint8 stackCreatFlag : 1;
        uint8 stackDestroyFlag : 1;
        uint8 nullAgrgsFlag : 1;
        uint8 nullStackFlag : 1;
        uint8 emptyStackFlag : 1;
        uint8 fullStackFlag : 1;
        uint8 stackReadyFlag : 1;
        uint8 stackReallocFlag : 1;
    };
    unsigned char allStatus;
} stackStatus_t;

typedef enum
{
    CHK_FOR_PUSH,
    CHK_FOR_POP,
    CHK_FOR_CREATE,
    CHK_FOR_DESTROY,
    CHK_FOR_REALLOC,
} stackCheck_t;

typedef struct
{
    void **Stackdata; /*Pointer to the data located in the heap*/
    uint32 stackSize; /*Vairable carry the max number of elements that the stack can carry*/
    uint32 stackTop;  /*variable carry the index of the first elements in the stack*/
} stack_t;

extern stackStatus_t stackStatus; /*variable carry the status of the last operation done on the stack*/

/**
 * @brief  This function allocates the stackData in the heap
 * @param  stackPtr is a pointer the the struct of the stack
 */
void stackCreate(stack_t *stackPtr);

/**
 * @brief  This function pushes data to the stack
 * @param  stackPtr is a pointer the the struct of the stack
 * @param  data is a pointer to the data to be pushed
 */
void stackPush(stack_t *stackPtr, uint16 argsNum, ...);

/**
 * @brief  This function pop data to the stack
 * @param  stackPtr is a pointer the the struct of the stack
 * @retval The first element of the stack as a void pointer
 */
void *stackPop(stack_t *stackPtr);

/**
 * @brief  This function feaches the first element of the stack
 * @param  stackPtr is a pointer the the struct of the stack
 * @retval The first element of the stack
 */
void *stackGetTop(stack_t *stackPtr);

/**
 * @brief  This function check the status of the stack
 * @param  stackPtr is a pointer the the struct of the stack
 * @param  argsNum the number of the args passed to this function
 */
static void stackCheck(stackCheck_t t, stack_t *stackPtr, uint16 *argsNumPtr, va_list args);

/**
 * @brief  This function deallocates the stackData from the heap
 * @param  stackPtr is a pointer the the struct of the stack
 */
void stackDestroy(stack_t *stackPtr);

/**
 * @brief  This function reallocates the size of the stack
 * @param  stackPtr is a pointer the the struct of the stack
 * @param  newSize The new size of the stack
 */
void stackChangeSize(stack_t *stackPtr, uint32 newSize);

#endif