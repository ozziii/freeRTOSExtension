#ifndef OZ_TASK_H
#define OZ_TASK_H

#include "FreeRTOS.h"
#include "freertos/event_groups.h"


#define MAX_REVERSE_SEMAPHORE_COUNT 65535


#define ReverseSemaphoreHandle_t EventGroupHandle_t

/**
 * @brief 
 * 
 * 
 * 
 * 
 * @param size 
 * @return ReverseSemaphoreHandle_t 
 */
ReverseSemaphoreHandle_t xReverseSemaphoreCreate();


/**
 * @brief 
 * 
 * 
 * 
 * @param xSemaphore 
 * @return BaseType_t 
 */
BaseType_t xReverseSemaphoreIncrese(ReverseSemaphoreHandle_t xSemaphore );



/**
 * @brief 
 * 
 * 
 * 
 * @param xSemaphore 
 * @return BaseType_t 
 */
BaseType_t xReverseSemaphoreDecrese(ReverseSemaphoreHandle_t xSemaphore );



/**
 * @brief 
 * 
 * 
 * 
 * @param xSemaphore 
 * @param xTicksToWait 
 * @return BaseType_t 
 */
BaseType_t xReverseSemaphoreWaitForZero(ReverseSemaphoreHandle_t xSemaphore, TickType_t xTicksToWait);