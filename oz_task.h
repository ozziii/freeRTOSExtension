#ifndef OZ_TASK_H
#define OZ_TASK_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#if (configSUPPORT_DYNAMIC_ALLOCATION == 1)

#define TASK_CREATE_WFH_LOOP_DELAY 500

/**
 * @brief
 *
 * @param pvTaskCode
 * @param pcName
 * @param usStackDepth
 * @param pvParameters
 * @param uxPriority
 * @param pvCreatedTask
 * @param xCoreID
 * @param xTicksToWait
 * @return BaseType_t
 *
 *
 *
 *
 */
BaseType_t xTaskCreatePinnedToCore_WFH(TaskFunction_t pvTaskCode,
                                       const char *const pcName,
                                       const uint32_t usStackDepth,
                                       void *const pvParameters,
                                       UBaseType_t uxPriority,
                                       TaskHandle_t *const pvCreatedTask,
                                       const BaseType_t xCoreID,
                                       TickType_t xTicksToWait);
#endif

#if (configSUPPORT_DYNAMIC_ALLOCATION == 1)
/**
 * @brief
 *
 *
 *
 * @param pvTaskCode
 * @param pcName
 * @param usStackDepth
 * @param pvParameters
 * @param uxPriority
 * @param taskHandle
 * @param xTicksToWait
 * @return BaseType_t
 *
 *
 *
 *
 */
BaseType_t xTaskCreate_WFH(
    TaskFunction_t pvTaskCode,
    const char *const pcName,
    const uint32_t usStackDepth,
    void *const pvParameters,
    UBaseType_t uxPriority,
    TaskHandle_t *const pvCreatedTask,
    TickType_t xTicksToWait);
#endif

#endif