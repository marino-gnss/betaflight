/*
 * This file is part of Betaflight.
 *
 * Betaflight is free software. You can redistribute this software
 * and/or modify this software under the terms of the GNU General
 * Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later
 * version.
 *
 * Betaflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct chirp_s {
    float f0, Ts, beta, k0, k1;
    uint32_t count, N;
    float exc, fchirp, sinarg;
    bool isFinished;
} chirp_t;

void chirpInit(chirp_t *chirp, const float f0, const float f1, const float t1, const uint32_t looptimeUs);
void chirpReset(chirp_t *chirp);
void chirpResetSignals(chirp_t *chirp);
bool chirpUpdate(chirp_t *chirp);
