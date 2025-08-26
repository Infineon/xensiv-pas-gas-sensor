/***********************************************************************************************//**
 * \file xensiv_pas_gas_r290.h
 *
 * Description: This file contains the functions for interacting with the
 *              XENSIV™ PAS R290 sensor.
 *
 ***************************************************************************************************
 * \copyright
 * Copyright 2025-2026 Infineon Technologies AG
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 **************************************************************************************************/


#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "xensiv_pas_gas.h"

/************************************** Macros *******************************************/
#define XENSIV_PAS_GAS_R290_MEAS_RATE_MIN            (3U)

/********************************* Type definitions **************************************/

/** Enum defining the different device commands */
typedef enum
{
    XENSIV_PAS_GAS_R290_CMD_SOFT_RESET = 0xA3U,         /**< Soft reset the sensor */
} xensiv_pas_gas_r290_cmd_t;

/** Structure of the R290 sensor's status register (SENS_STS) */
typedef union
{
    xensiv_pas_gas_status_t base;                       /*<! Base status structure */
    struct
    {
        uint32_t : 3;
        uint32_t iccerr : 1;                            /*!< Communication error notification bit (R290). */
        uint32_t orvs : 1;                              /*!< Out-of-range VDD12V error bit (R290). */
        uint32_t ortmp : 1;                             /*!< Out-of-range temperature error bit (R290). */
        uint32_t sen_rdy : 1;                           /*!< Sensor ready bit (R290). */
        uint32_t : 1;
    } b;                                                /*!< Structure used for bit  access */
    uint8_t u;                                          /*!< Type used for byte access */
} xensiv_pas_gas_r290_status_t;

/**
 * @brief Initializes the XENSIV™ PAS GAS R290 device.
 * It initializes the dev structure, verifies the integrity of the communication layer of the serial communication interface, and checks whether the sensor is ready
 *
 * @param[in out] dev Pointer to a XENSIV™ PAS GAS R290 sensor device structure allocated by the user,
 * but the init function will initialize its contents
 * @param[in] itf Communication interface (I2C/UART)
 * @param[in] ctx Pointer to the platform-specific specific protocol communication handler
 * @return XENSIV_PAS_GAS_OK if the initialization was successful; an error indicating what went wrong otherwise
 */
int32_t xensiv_pas_gas_r290_init(xensiv_pas_gas_t *dev, xensiv_pas_gas_interface_t itf, void *ctx);

/**
 * @brief Reads the device ID of the XENSIV™ PAS GAS R290 sensor.
 *
 * @param[in] dev Pointer to a XENSIV™ PAS GAS R290 sensor device structure
 * @param[out] dev_id Pointer to a buffer to store the device ID
 * @return XENSIV_PAS_GAS_OK if the read was successful; an error indicating what went wrong otherwise
 */
int32_t xensiv_pas_gas_r290_get_device_id(const xensiv_pas_gas_t *dev, void *dev_id);

/**
 * @brief Configures the ABOC prefill value.
 *
 * @param[in] dev Pointer to a XENSIV™ PAS GAS R290 sensor device structure
 * @param[in] prefill The number of hours to prefill the flash table from 0 to the maximum hours value.The maximum hours value is the ABOC cycle minus one hour.
  * For example, if the ABOC cycle is set to 10 hours, the maximum prefill value is 9 hours.
 * @return XENSIV_PAS_GAS_OK if the configuration was successful; an error indicating what went wrong otherwise
 */
int32_t xensiv_pas_gas_r290_aboc_prefill(const xensiv_pas_gas_t *dev, uint8_t prefill);
