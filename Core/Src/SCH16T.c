/**
 * @file SCT16H.c
 * @author KUSAKABE Yuki (yuqlid@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-06-06
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "SCH16T.h"
#include "spi.h"
#include "gpio.h"

uint64_t transfer(uint64_t frame)
{
    uint8_t txbuf[6];
    uint8_t rxbuf[6];
    uint64_t lower32bit, upper16bit;

    for (uint8_t i = 0; i < 6; i++)
    {
        txbuf[5 - i] = (frame >> (i * 8)) & 0xFF;
    }
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_TransmitReceive(&hspi1, (uint8_t *)txbuf, (uint8_t *)rxbuf, 6, 100);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);

    lower32bit = rxbuf[2] << 24 | rxbuf[3] << 16 | rxbuf[4] << 8 | rxbuf[5];
    upper16bit = rxbuf[0] << 8 | rxbuf[1];

    return (uint64_t)((upper16bit << 32) | lower32bit);
}
