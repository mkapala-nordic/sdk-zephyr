/*
 * Copyright (c) 2024 Nordic Semiconductor ASA
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_SOC_NORDIC_NRF54H_GPD_INCLUDE_NRF_GPD_H_
#define ZEPHYR_SOC_NORDIC_NRF54H_GPD_INCLUDE_NRF_GPD_H_

#include <stdint.h>

#include <zephyr/dt-bindings/power/nordic-nrf-gpd.h>

/**
 * @brief Request a global power domain.
 *
 * @param id Domain ID.
 *
 * @retval 0 If the request was successful.
 * @retval -errno If the request was not successful.
 */
int nrf_gpd_request(uint8_t id);

/**
 * @brief Release a global power domain.
 *
 * @param id Domain ID.
 *
 * @retval 0 If the request was successful.
 * @retval -errno If the request was not successful.
 */
int nrf_gpd_release(uint8_t id);

#endif /* ZEPHYR_SOC_NORDIC_NRF54H_GPD_INCLUDE_NRF_GPD_H_ */