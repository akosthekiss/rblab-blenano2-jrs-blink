// Copyright (c) 2017 Akos Kiss.
//
// Licensed under the BSD 3-Clause License
// <LICENSE.md or https://opensource.org/licenses/BSD-3-Clause>.
// This file may not be copied, modified, or distributed except
// according to those terms.

#include "jerryscript-port.h"
#include "jerryscript-ext/handler.h"

#include "main.h"
#include "Morse.h"


bool jerry_port_get_time_zone(jerry_time_zone_t *tz_p) /**< [out] time zone structure to fill */
{
    tz_p->offset = 0;
    tz_p->daylight_saving_time = 0;
    return true;
}

double jerry_port_get_current_time(void)
{
    return time(NULL) * 1000.0; // seconds precision only
}

void jerry_port_fatal(jerry_fatal_code_t code)
{
    Morse morse(led1);

    while (true)
        morse.puts("SOS ", true);
}

void jerry_port_log(jerry_log_level_t level, /**< log level */
                    const char *format, /**< format string */
                    ...)  /**< parameters */
{
}

void jerryx_port_handler_print_char(char c) /**< the character to print */
{
    if (c == '\n')
        usb.printf("\r\n");
    else
        usb.printf("%c", c);
} /* jerryx_port_handler_print_char */
