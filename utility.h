#ifndef UTILITY_H
#define UTILITY_H

#define I2C_BUS_0   0
#define I2C_BUS_1   1
#define BMA180_DDR  0x40

struct AccelValues
{
    int x;
    int y;
    int z;
    float temp;
};

#endif // UTILITY_H
