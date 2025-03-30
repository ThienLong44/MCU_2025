#ifndef __GLOBAL_VARIABLES_H
#define __GLOBAL_VARIABLES_H

#include<stddef.h>
#include<stdint.h>

#define __vo volatile
#define __weak __attribute__((weak))


// =========================================== Processor Specific Details =========================================== //

/*
 * ARM Coxtex M4 NVIC
 */
#define NVIC_BASEADDR		((__vo uint32_t*)0xE000E000U)

#define NVIC_ISRx      ((__vo uint32_t*)0xE000E100U)
#define NVIC_ICRx      ((__vo uint32_t*)0xE000E180U)
/*
 * ARM Cortex M4 basse addrss of Flash and SRAM memories
 */
#define FLASH_BASEADDR			     0x08000000U
#define SRAM1_BASEADDR			     0x20000000U
#define SRAM2_BASEADDR			     0x2001C000U
#define ROM_BASEADDR			       0x1FFF0000U
#define SRAM 				             SRAM1_BASEADDR

/*
 * AHBx and APBx Bus Peripheral base addresses
 */
#define PERIPH_BASEADDR 		       0x40000000U
#define APB1PERIPH_BASEADDR		     PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR		     0x40010000U
#define AHB1PERIPH_BASEADDR		     0x40020000U
#define AHB2PERIPH_BASEADDR		     0x50000000U

/*
 * AHB1 Peripheral base addresses
 */
/* GPIO base address */
#define GPIOA_BASEADDR                      (AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR                      (AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR                      (AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR                      (AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR                      (AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR                      (AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR                      (AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR                      (AHB1PERIPH_BASEADDR + 0x1C00)
#define GPIOI_BASEADDR                      (AHB1PERIPH_BASEADDR + 0x2000)

/* RCC base address */
#define RCC_BASEADDR                        (AHB1PERIPH_BASEADDR + 0x3800)

/*
 * APB1 Peripheral base addresses
 */

/* I2C Peripherals */
#define I2C1_BASEADDR			      (APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR			      (APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR			      (APB1PERIPH_BASEADDR + 0x5C00)

/* SPI Peripherals */
#define SPI1_BASEADDR			      (APB2PERIPH_BASEADDR + 0x3000) 
#define SPI2_BASEADDR			      (APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR			      (APB1PERIPH_BASEADDR + 0x3C00)
#define SPI4_BASEADDR			      (APB1PERIPH_BASEADDR + 0x3400)

/* USART Peripherals */
#define USART2_BASEADDR			    (APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR			    (APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR			    (APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR			    (APB1PERIPH_BASEADDR + 0x5000)

/*
 * APB2 Peripheral base addresses   
 */
#define EXTI_BASEADDR			      (APB2PERIPH_BASEADDR + 0x3C00)
#define SPI1_BASEADDR			      (APB2PERIPH_BASEADDR + 0x3000)
#define SYSCFG_BASEADDR         (APB2PERIPH_BASEADDR + 0x3800)
#define USART1_BASEADDR			    (APB2PERIPH_BASEADDR + 0x1000)
#define USART6_BASEADDR			    (APB2PERIPH_BASEADDR + 0x1400)

// =========================================== Peripheral register definition structures =========================================== //

typedef struct
{
  __vo uint32_t MODER;                        
  __vo uint32_t OTYPER;                       
  __vo uint32_t OSPEEDR;
  __vo uint32_t PUPDR;
  __vo uint32_t IDR;
  __vo uint32_t ODR;
  __vo uint32_t BSRR;
  __vo uint32_t LCKR;
  __vo uint32_t AFR[2];					 
}GPIO_RegDef_t;

typedef struct
{
  __vo uint32_t CR;            
  __vo uint32_t PLLCFGR;       
  __vo uint32_t CFGR;          
  __vo uint32_t CIR;           
  __vo uint32_t AHB1RSTR;      
  __vo uint32_t AHB2RSTR;      
  __vo uint32_t AHB3RSTR;      
  uint32_t      RESERVED0;     
  __vo uint32_t APB1RSTR;      
  __vo uint32_t APB2RSTR;      
  uint32_t      RESERVED1[2];  
  __vo uint32_t AHB1ENR;       
  __vo uint32_t AHB2ENR;       
  __vo uint32_t AHB3ENR;       
  uint32_t      RESERVED2;     
  __vo uint32_t APB1ENR;       
  __vo uint32_t APB2ENR;       
  uint32_t      RESERVED3[2];  
  __vo uint32_t AHB1LPENR;     
  __vo uint32_t AHB2LPENR;     
  __vo uint32_t AHB3LPENR;     
  uint32_t      RESERVED4;     
  __vo uint32_t APB1LPENR;     
  __vo uint32_t APB2LPENR;     
  uint32_t      RESERVED5[2];  
  __vo uint32_t BDCR;          
  __vo uint32_t CSR;           
  uint32_t      RESERVED6[2];  
  __vo uint32_t SSCGR;         
  __vo uint32_t PLLI2SCFGR;    
  __vo uint32_t PLLSAICFGR;    
  __vo uint32_t DCKCFGR;       
  __vo uint32_t CKGATENR;      
  __vo uint32_t DCKCFGR2;      
} RCC_RegDef_t;

typedef struct
{
  __vo uint32_t IMR;   
  __vo uint32_t EMR;   
  __vo uint32_t RTSR;  
  __vo uint32_t FTSR;  
  __vo uint32_t SWIER;  
  __vo uint32_t PR;     
}EXTI_RegDef_t;

typedef struct
{
  __vo uint32_t CR1;       
  __vo uint32_t CR2;       
  __vo uint32_t SR;        
  __vo uint32_t DR;        
  __vo uint32_t CRCPR;     
  __vo uint32_t RXCRCR;    
  __vo uint32_t TXCRCR;    
  __vo uint32_t I2SCFGR;   
  __vo uint32_t I2SPR;     
} SPI_RegDef_t;

typedef struct
{
  __vo uint32_t MEMRMP;       
  __vo uint32_t PMC;          
  __vo uint32_t EXTICR[4];    
  uint32_t      RESERVED1[2]; 
  __vo uint32_t CMPCR;        
  uint32_t      RESERVED2[2]; 
  __vo uint32_t CFGR;         
} SYSCFG_RegDef_t;

typedef struct
{
  __vo uint32_t CR1;        
  __vo uint32_t CR2;        
  __vo uint32_t OAR1;       
  __vo uint32_t OAR2;       
  __vo uint32_t DR;         
  __vo uint32_t SR1;        
  __vo uint32_t SR2;        
  __vo uint32_t CCR;        
  __vo uint32_t TRISE;      
  __vo uint32_t FLTR;       
}I2C_RegDef_t;

typedef struct
{
  __vo uint32_t SR;         
  __vo uint32_t DR;         
  __vo uint32_t BRR;        
  __vo uint32_t CR1;        
  __vo uint32_t CR2;        
  __vo uint32_t CR3;        
  __vo uint32_t GTPR;       
} USART_RegDef_t;

typedef struct
{
  __vo uint32_t ISER0;
  __vo uint32_t ISER1;
  __vo uint32_t ISER2;
  __vo uint32_t ISER3;
}NVIC_RegDef_t;

typedef struct
{
  __vo uint32_t ICER0;
  __vo uint32_t ICER1;
  __vo uint32_t ICER2;
  __vo uint32_t ICER3;
}NVIC_ICER_RegDef_t;

// =========================================== Peripheral Definitions =========================================== //

#define GPIOA  				((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB  				((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC  				((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD  				((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE  				((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF  				((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG  				((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH  				((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI  				((GPIO_RegDef_t*)GPIOI_BASEADDR)

#define RCC 				  ((RCC_RegDef_t*)RCC_BASEADDR)
#define EXTI				  ((EXTI_RegDef_t*)EXTI_BASEADDR)
#define SYSCFG				((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)


#define SPI1  				((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2  				((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3  				((SPI_RegDef_t*)SPI3_BASEADDR)

#define I2C1  				((I2C_RegDef_t*)I2C1_BASEADDR)
#define I2C2  				((I2C_RegDef_t*)I2C2_BASEADDR)
#define I2C3  				((I2C_RegDef_t*)I2C3_BASEADDR)

#define USART1  			((USART_RegDef_t*)USART1_BASEADDR)
#define USART2  			((USART_RegDef_t*)USART2_BASEADDR)
#define USART3  			((USART_RegDef_t*)USART3_BASEADDR)
#define UART4  				((USART_RegDef_t*)UART4_BASEADDR)
#define UART5  				((USART_RegDef_t*)UART5_BASEADDR)
#define USART6  			((USART_RegDef_t*)USART6_BASEADDR)

#define NVIC_ISER     ((NVIC_RegDef_t*)NVIC_BASEADDR)
#define NVIC_ICER     ((NVIC_ICER_RegDef_t*)NVIC_BASEADDR)
// =========================================== Clock Enable and Disable =========================================== //
#define GPIO_PCLK_CONFIGURE(func)                               \
        func(GPIOA, 0, AHB1ENR)                                 \
        func(GPIOB, 1, AHB1ENR)                                 \
        func(GPIOC, 2, AHB1ENR)                                 \
        func(GPIOD, 3, AHB1ENR)                                 \
        func(GPIOE, 4, AHB1ENR)                                 \
        func(GPIOF, 5, AHB1ENR)                                 \
        func(GPIOG, 6, AHB1ENR)                                 \
        func(GPIOH, 7, AHB1ENR)                                 \
        func(GPIOI, 8, AHB1ENR)                                 \

#define SPI_PCLK_CONFIGURE(func)                                \
        func(SPI1, 12, APB2ENR)                                 \
        func(SPI2, 14, APB1ENR)                                 \
        func(SPI3, 15, APB1ENR)                                 \
        func(SPI4, 13, APB2ENR)                                 \
        
#define I2C_PCLK_CONFIGURE(func)                                \
        func(I2C1, 21, APB1ENR)                                 \
        func(I2C2, 22, APB1ENR)                                 \
        func(I2C3, 23, APB1ENR)                                 \

#define USART_PCLK_CONFIGURE(func)                              \
        func(USART1, 4, APB2ENR)                                \
        func(USART2, 17, APB1ENR)                               \
        func(USART3, 18, APB1ENR)                               \
        func(UART4, 19, APB1ENR)                                \
        func(UART5, 20, APB1ENR)                                \
        func(USART6, 5, APB1ENR)                                \

#define SYSCFG_PCLK_CONFIGURE(func)                             \
        func(SYSCFG, 14, APB2ENR)                               \

/* Prototype */
#define DECLARATION_FUNCS(NAME,VALUE,REG)                       \
        void NAME##_PCLK_EN(void);                              \
        void NAME##_PCLK_DI(void);                              \

/* Function Declaration */
GPIO_PCLK_CONFIGURE(DECLARATION_FUNCS);
SPI_PCLK_CONFIGURE(DECLARATION_FUNCS);
I2C_PCLK_CONFIGURE(DECLARATION_FUNCS);
USART_PCLK_CONFIGURE(DECLARATION_FUNCS);
SYSCFG_PCLK_CONFIGURE(DECLARATION_FUNCS);


#endif // __GLOBAL_VARIABLES_H
