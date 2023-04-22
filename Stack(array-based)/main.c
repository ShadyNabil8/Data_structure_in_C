#include <stdio.h>
#include "stack.h"

int main()
{
    int intArr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char charArr[5] = {'S', 'H', 'A', 'D', 'Y'};

    /*Check for stack creation function*/
    stack_t stack;
    stack.stackSize = 10;
    stackCreate(&stack);
    if (stackStatus.stackCreatFlag == TRUE)
    {
        printf("STACK_CRATED \n");
    }

    /*Check for stack push and pop function*/
    stackPush(&stack, 10, &intArr[0], &intArr[1], &intArr[2], &intArr[3], &intArr[4],
              &intArr[5], &intArr[6], &intArr[7], &intArr[8], &intArr[9]);
    if (stackStatus.stackReadyFlag == TRUE)
    {
        printf("10 NUMBERS PUSHED TO STACK\n");
        for (int i = 0; i < 10; i++)
        {
            int *temp = ((int *)(stackPop(&stack)));
            if (temp != NULL)
            {
                printf("%i\t", *temp);
            }
        }
        if (stackStatus.stackReadyFlag == TRUE)
        {
            printf("\n10 NUMBERS POPED FROM STACK\n");
        }
    }

    /*Check for change size function*/
    stackChangeSize(&stack, 5);
    if (stackStatus.stackReallocFlag == TRUE)
    {
        printf("THE NEW SIZE IS 5\n");
        stackPush(&stack, 5, &charArr[0], &charArr[1], &charArr[2], &charArr[3], &charArr[4]);
        if (stackStatus.stackReadyFlag == TRUE)
        {
            printf("5 CHARS PUSHED TO STACK\n");
        }
    }
    if (stackStatus.stackReadyFlag == TRUE)
    {
        for (int i = 0; i < 5; i++)
        {
            int *temp = ((int *)(stackPop(&stack)));
            if (temp != NULL)
            {
                printf("%c\t", *temp);
            }
        }
        if (stackStatus.stackReadyFlag == TRUE)
        {
            printf("\n5 CHARS POPED FROM STACK\n");
        }
        }

    return 0;
}
