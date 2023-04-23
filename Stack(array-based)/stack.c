#include "stack.h"

stackStatus_t stackStatus;

void stackCreate(stack_t *stackPtr)
{
    stackPtr->Stackdata = (void **)calloc(stackPtr->stackSize, sizeof(void *));
    stackCheck(CHK_FOR_CREATE, stackPtr, NULL, NULL);
    if (stackStatus.stackReadyFlag == TRUE)
    {
        stackStatus.stackCreatFlag = TRUE;
        stackPtr->stackTop = ZERO_ELEMENTS;
    }
    else
    {
        /*For debugging*/
    }
}

static void stackCheck(stackCheck_t t, stack_t *stackPtr, uint16 *argsNumPtr, va_list args)
{
    stackStatus.allStatus = FALSE;
    if (stackPtr == NULL)
    {
        stackStatus.nullStackFlag = TRUE;
    }
    else
    {
        if (!(NULL == argsNumPtr))
        {
            for (uint16 i = 0; i < *argsNumPtr; i++)
            {
                if (va_arg(args, void *) == NULL)
                {
                    stackStatus.nullAgrgsFlag = TRUE;
                    return;
                }
                else
                {
                    /*For debugging*/
                }
            }
        }
        switch (t)
        {
        case CHK_FOR_NULL:
            if (NULL == stackPtr)
            {
                stackStatus.nullStackFlag = TRUE;
            }
            else
            {
                stackStatus.stackReadyFlag = TRUE;
            }
            break;

        case CHK_FOR_POP:
            if (ZERO_ELEMENTS == stackPtr->stackTop)
            {
                stackStatus.emptyStackFlag = TRUE;
            }
            else
            {
                stackStatus.stackReadyFlag = TRUE;
            }
            break;

        case CHK_FOR_PUSH:
            if (stackPtr->stackSize == stackPtr->stackTop)
            {
                stackStatus.fullStackFlag = TRUE;
            }
            else
            {
                uint16 temp = stackPtr->stackSize - stackPtr->stackTop; /*Num of elements can be pushed*/
                *argsNumPtr = (temp) >= (*argsNumPtr) ? *argsNumPtr : temp;
                stackStatus.stackReadyFlag = TRUE;
            }
            break;

        case CHK_FOR_CREATE:
            stackStatus.stackReadyFlag = TRUE;
            break;

        case CHK_FOR_REALLOC:
            if (NULL != stackPtr->Stackdata)
            {
                stackStatus.stackReadyFlag = TRUE;
            }
            else
            {
                /*For debugging*/
            }
            break;

        case CHK_FOR_DESTROY:
            stackStatus.stackReadyFlag = TRUE;
            break;

        default:
            break;
        }
    }
    return;
}

void stackPush(stack_t *stackPtr, uint16 argsNum, ...)
{
    va_list args;
    va_start(args, argsNum);
    stackCheck(CHK_FOR_PUSH, stackPtr, &argsNum, args);
    if (stackStatus.stackReadyFlag == TRUE)
    {
        for (uint16 i = 0; i < argsNum; i++)
        {
            (stackPtr->Stackdata)[stackPtr->stackTop] = va_arg(args, void *);
            (stackPtr->stackTop)++;
        }
        va_end(args);
    }
    else
    {
        /*For debugging*/
    }
}

void *stackPop(stack_t *stackPtr)
{
    void *retVal = NULL;
    stackCheck(CHK_FOR_POP, stackPtr, NULL, NULL);
    if (stackStatus.stackReadyFlag == TRUE)
    {
        (stackPtr->stackTop)--;
        retVal = stackPtr->Stackdata[stackPtr->stackTop];
    }
    else
    {
        /*For debugging*/
    }
    return retVal;
}

void *stackGetTop(stack_t *stackPtr)
{
    stackCheck(CHK_FOR_POP, stackPtr, NULL, NULL);
    if (stackStatus.stackReadyFlag == TRUE)
    {
        return stackPtr->Stackdata[(stackPtr->stackTop) - 1];
    }
    else
    {
        /*For debugging*/
    }
}

void stackDestroy(stack_t *stackPtr)
{
    stackCheck(CHK_FOR_DESTROY, stackPtr, NULL, NULL);
    if (stackStatus.stackReadyFlag == TRUE)
    {
        for (int i = 0; i <= stackPtr->stackTop; i++)
        {
            free(stackPtr->Stackdata[i]);
        }
        free(stackPtr->Stackdata);
        stackStatus.stackDestroyFlag = TRUE;
    }
    else
    {
        /*For debugging*/
    }
}

void stackChangeSize(stack_t *stackPtr, uint32 newSize)
{
    stackCheck(CHK_FOR_NULL, stackPtr, NULL, NULL);
    if (stackStatus.stackReadyFlag == TRUE)
    {
        if (newSize == stackPtr->stackSize)
        {
            /*Do nothing*/
        }
        else
        {
            if (newSize < stackPtr->stackSize)
            {
                stackPtr->stackTop = (stackPtr->stackTop > newSize) ? newSize : stackPtr->stackTop;
            }
            else
            {
            }
            stackPtr->stackSize = newSize;
            stackPtr->Stackdata = realloc(stackPtr->Stackdata, (stackPtr->stackSize) * sizeof(void **));
            stackCheck(CHK_FOR_REALLOC, stackPtr, NULL, NULL);
            if (stackStatus.stackReadyFlag == TRUE)
            {
                stackStatus.stackReallocFlag = TRUE;
            }
            else
            {
                /*For debugging*/
            }
        }
    }
}

void stackEmpty(stack_t *stackPtr)
{
    stackCheck(CHK_FOR_NULL, stackPtr, NULL, NULL);
    if (stackStatus.stackReadyFlag == TRUE)
    {
        stackPtr->stackTop = ZERO_ELEMENTS;
        stackStatus.emptyStackFlag = TRUE;
    }
    else
    {
    }
}

void stackPrint(stack_t *stackPtr)
{
    stackCheck(CHK_FOR_NULL,stackPtr,NULL,NULL);
    if(stackStatus.stackReadyFlag == TRUE)
    {
        
    }
}