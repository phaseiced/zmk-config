/*
 * Keyball patch notes on top of KOHSUK/bullwinkle3000 PMW3360 driver:
 * - irq-gpios optional; poll when absent (stock Keyball J2 has no MOTION)
 * - Keep SROM upload
 * - Default force-awake (CONFIG2=0x00) like QMK Keyball
 */
#pragma once

#include <zephyr/device.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/sensor.h>

#ifdef __cplusplus
extern "C" {
#endif

enum pixart_input_mode { MOVE = 0, SCROLL, SNIPE };

struct pixart_data {
    const struct device *dev;

    enum pixart_input_mode curr_mode;
    uint32_t curr_cpi;
    int32_t scroll_delta_x;
    int32_t scroll_delta_y;

    struct gpio_callback irq_gpio_cb;
    struct k_work trigger_work;
    struct k_work_delayable poll_work;

    struct k_work_delayable init_work;
    int async_init_step;

    bool ready;
    bool last_read_burst;
    bool polling_mode;
    int err;

    bool sw_smart_flag;
};

struct pixart_config {
    struct gpio_dt_spec irq_gpio;
    struct spi_dt_spec bus;
    struct gpio_dt_spec cs_gpio;
    uint32_t polling_interval_us;
    size_t scroll_layers_len;
    int32_t *scroll_layers;
    size_t snipe_layers_len;
    int32_t *snipe_layers;
};

#ifdef __cplusplus
}
#endif
