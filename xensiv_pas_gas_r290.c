/***********************************************************************************************//**
 * \file xensiv_pas_gas_r290.c
 *
 * Description: This file contains the functions for interacting with the
 *              XENSIV™ PAS GAS R290 sensor.
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
#include "xensiv_pas_gas.h"
#include "xensiv_pas_gas_r290.h"
#include "xensiv_pas_gas_regs.h"
#include "xensiv_pas_gas_platform.h"

#define XENSIV_PAS_GAS_FCS_MEAS_RATE_S           (3)

int32_t xensiv_pas_gas_perform_forced_compensation(const xensiv_pas_gas_t *dev, uint16_t gas_ref) {
    xensiv_pas_gas_plat_assert(dev != NULL);

    xensiv_pas_gas_measurement_config_t meas_config;
    int32_t res = xensiv_pas_gas_get_measurement_config(dev, &meas_config);

    if (XENSIV_PAS_GAS_OK == res) {
        meas_config.b.op_mode = XENSIV_PAS_GAS_OP_MODE_IDLE;
        res = xensiv_pas_gas_set_measurement_config(dev, meas_config);
    }

    if (XENSIV_PAS_GAS_OK == res) {
        res = xensiv_pas_gas_set_measurement_rate(dev, XENSIV_PAS_GAS_FCS_MEAS_RATE_S);
    }

    if (XENSIV_PAS_GAS_OK == res) {
        res = xensiv_pas_gas_set_offset_compensation(dev, gas_ref);
    }

    if (XENSIV_PAS_GAS_OK == res) {
        meas_config.b.op_mode = XENSIV_PAS_GAS_OP_MODE_CONTINUOUS;
        meas_config.b.boc_cfg = XENSIV_PAS_GAS_BOC_CFG_FORCED;
        res = xensiv_pas_gas_set_measurement_config(dev, meas_config);
    }

    if (XENSIV_PAS_GAS_OK == res) {
        /* wait until the FCS is finished */
        do
        {
            res = xensiv_pas_gas_get_measurement_config(dev, &meas_config);
        } while ((XENSIV_PAS_GAS_OK != res) || (XENSIV_PAS_GAS_BOC_CFG_FORCED == meas_config.b.boc_cfg));
    }

    if (XENSIV_PAS_GAS_OK == res) {
        meas_config.b.op_mode = XENSIV_PAS_GAS_OP_MODE_IDLE;
        res = xensiv_pas_gas_set_measurement_config(dev, meas_config);
    }
    return res;
}
