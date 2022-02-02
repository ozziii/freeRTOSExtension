#include "oz_task.h"

BaseType_t xTaskCreatePinnedToCore_WFH(TaskFunction_t pvTaskCode,
                                       const char *const pcName,
                                       const uint32_t usStackDepth,
                                       void *const pvParameters,
                                       UBaseType_t uxPriority,
                                       TaskHandle_t *const pvCreatedTask,
                                       const BaseType_t xCoreID,
                                       TickType_t xTicksToWait)
{

    BaseType_t err = -1;
    if (xTicksToWait == portMAX_DELAY)
    {
        while (true)
        {
            err = xTaskCreatePinnedToCore(pvTaskCode, pcName, usStackDepth, pvParameters, uxPriority, pvCreatedTask, xCoreID);

            if (err == -1)
                vTaskDelay(TASK_CREATE_WFH_LOOP_DELAY);
            else
                return err;
        }
    }
    else
    {
        TickType_t start = xTaskGetTickCount();//TODO

        while (xTaskGetTickCount() - start < xTicksToWait)
        {
            err = xTaskCreatePinnedToCore(pvTaskCode, pcName, usStackDepth, pvParameters, uxPriority, pvCreatedTask, xCoreID);

            if (err == -1)
                vTaskDelay(TASK_CREATE_WFH_LOOP_DELAY);
            else
                return err;
        }
    }
    return err;
}

BaseType_t xTaskCreate_WFH(
    TaskFunction_t pvTaskCode,
    const char *const pcName,
    const uint32_t usStackDepth,
    void *const pvParameters,
    UBaseType_t uxPriority,
    TaskHandle_t *const pvCreatedTask,
    TickType_t xTicksToWait)
{
    return xTaskCreatePinnedToCore_WFH(pvTaskCode, pcName, usStackDepth, pvParameters, uxPriority, pvCreatedTask, tskNO_AFFINITY, xTicksToWait);
}