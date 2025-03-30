#include "GlobalVariables.h"

#define GPIO_ENABLE(GPIO,VALUE, BUS)     \
    void GPIO##_PCLK_EN(void)            \
    {                                    \
        RCC->BUS |= (1 << VALUE);        \
    }                                    

GPIO_PCLK_CONFIGURE(GPIO_ENABLE)

#define GPIO_DISABLE(GPIO,VALUE,BUS)   \
    void GPIO##_PCLK_DI(void)          \
    {                                  \
        RCC->BUS &= ~(1 << VALUE);     \
    }                                  

GPIO_PCLK_CONFIGURE(GPIO_DISABLE)

#define SPI_ENABLE(SPI,VALUE,BUS)      \
    void SPI##_PCLK_EN(void)           \
    {                                  \
        RCC->BUS |= (1 << VALUE);      \
    }                                  

SPI_PCLK_CONFIGURE(SPI_ENABLE)

#define SPI_DISABLE(SPI,VALUE,BUS)     \
    void SPI##_PCLK_DI(void)           \
    {                                  \
        RCC->BUS &= ~(1 << VALUE);     \
    }    

SPI_PCLK_CONFIGURE(SPI_DISABLE)

#define I2C_ENABLE(I2C,VALUE,BUS)      \
    void I2C##_PCLK_EN(void)           \
    {                                  \
        RCC->BUS |= (1 << VALUE);      \
    }

I2C_PCLK_CONFIGURE(I2C_ENABLE)    

#define I2C_DISABLE(I2C,VALUE,BUS)     \
    void I2C##_PCLK_DI(void)           \
    {                                  \
        RCC->BUS &= ~(1 << VALUE);     \
    }

I2C_PCLK_CONFIGURE(I2C_DISABLE)

#define USART_ENABLE(USART,VALUE,BUS)	 \
    void USART##_PCLK_EN(void)           \
    {                                    \
        RCC->BUS |= (1 << VALUE);        \
    }
