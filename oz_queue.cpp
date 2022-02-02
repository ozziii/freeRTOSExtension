#include "oz_queue.h"


ReverseSemaphoreHandle_t xReverseSemaphoreCreate()
{
    ReverseSemaphoreHandle_t xSemaphore = xEventGroupCreate();
    xEventGroupSetBits( xSemaphore,MAX_REVERSE_SEMAPHORE_COUNT );
    return xSemaphore;
}

BaseType_t xReverseSemaphoreIncrese(ReverseSemaphoreHandle_t xSemaphore )
{
    EventBits_t bit = xEventGroupGetBits( xSemaphore );
    xEventGroupClearBits( xSemaphore , MAX_REVERSE_SEMAPHORE_COUNT);
    xEventGroupSetBits( xSemaphore , bit-1);

    return 1;
}

BaseType_t xReverseSemaphoreDecrese(ReverseSemaphoreHandle_t xSemaphore )
{
    EventBits_t bit = xEventGroupGetBits( xSemaphore );
    xEventGroupClearBits( xSemaphore , MAX_REVERSE_SEMAPHORE_COUNT);
    xEventGroupSetBits( xSemaphore , bit+1);

    return 1;
}

BaseType_t xReverseSemaphoreWaitForZero(ReverseSemaphoreHandle_t xSemaphore, TickType_t xTicksToWait)
{
    return xEventGroupWaitBits(xSemaphore,MAX_REVERSE_SEMAPHORE_COUNT,pdFALSE,pdTRUE,xTicksToWait);
}


void xReverseSemaphoreDelete(ReverseSemaphoreHandle_t xSemaphore )
{
    vEventGroupDelete(xSemaphore);
}   


