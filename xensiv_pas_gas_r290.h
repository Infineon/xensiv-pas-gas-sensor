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

#include "xensiv_pas_gas_regs.h"
#include "xensiv_pas_gas_platform.h"

/************************************** Macros *******************************************/
#define XENSIV_PAS_GAS_MEAS_RATE_MIN           (3U)


/********************************* Type definitions **************************************/

/** Enum defining the different device commands */
typedef enum
{
  XENSIV_PAS_GAS_CMD_SOFT_RESET = 0xA3U,               /**< Soft reset the sensor */
} xensiv_pas_gas_cmd_t;

/** Structure of the R290 sensor's status register (SENS_STS) */
typedef union
{
  struct
  {
    uint32_t :3;
    uint32_t iccerr:1;                                  /*!< Communication error notification bit (R290). */
    uint32_t orvs:1;                                    /*!< Out-of-range VDD12V error bit (R290). */
    uint32_t ortmp:1;                                   /*!< Out-of-range temperature error bit (R290). */
    uint32_t sen_rdy:1;                                 /*!< Sensor ready bit (R290). */
    uint32_t :1;
  } b;                                                  /*!< Structure used for bit  access */
  uint8_t u;                                            /*!< Type used for byte access */
} xensiv_pas_gas_status_t;

/** Structure of the R290 sensor's measurement configuration register (MEAS_CFG) */
typedef union
{
  struct
  {
    uint32_t op_mode:2;                                 /*!< @ref xensiv_pas_gas_op_mode_t */
    uint32_t boc_cfg:2;                                 /*!< @ref xensiv_pas_gas_boc_cfg_t */
  } b;                                                  /*!< Structure used for bit  access */
  uint8_t u;                                            /*!< Type used for byte access */
} xensiv_pas_gas_measurement_config_t;
