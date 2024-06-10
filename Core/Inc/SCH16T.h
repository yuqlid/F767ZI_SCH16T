/**
 * @file SCH16T.h
 * @author KUSAKABE Yuki (yuqlid@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-06-06
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SCT16T_H_
#define SCT16T_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

    uint64_t transfer(uint64_t frame);

    static inline int32_t getInt32data(uint64_t frame)
    {
        return ((int32_t)((frame << 4) & 0xFfFfF000UL)) >> 12;
    }
    static inline uint16_t getUint32data(uint64_t frame)
    {
        return (uint16_t)((frame >> 8) & 0x000FfFfFUL);
    }
    static inline uint16_t getUint16data(uint64_t frame)
    {
        return (uint16_t)((frame >> 8) & 0x0000FfFfUL);
    }

    static const uint64_t en_sensor = 0x0D68000001D3;
    static const uint64_t eoi = 0x0D680000038D;
    static const uint64_t read_rate_x1 = 0x0048000000AC;
    static const uint64_t read_rate_y1 = 0x00880000009A;
    static const uint64_t read_rate_z1 = 0x00C80000006D;
    static const uint64_t read_acc_x1 = 0x0108000000F6;
    static const uint64_t read_acc_y1 = 0x014800000001;
    static const uint64_t read_acc_z1 = 0x018800000037;
    static const uint64_t read_temperature = 0x0408000000B1;

#ifdef __cplusplus
}
#endif
#endif /*__ SCT16T_H_ */
