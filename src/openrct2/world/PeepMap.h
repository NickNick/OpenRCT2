#pragma region Copyright (c) 2014-2017 OpenRCT2 Developers
/*****************************************************************************
 * OpenRCT2, an open source clone of Roller Coaster Tycoon 2.
 *
 * OpenRCT2 is the work of many authors, a full list can be found in contributors.md
 * For more information, visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * A full copy of the GNU General Public License can be found in licence.txt
 *****************************************************************************/
#pragma endregion

#ifndef _PEEP_MAP_H_
#define _PEEP_MAP_H_

#include "Map.h"

#include <array>

auto constexpr heatmap_size = MAXIMUM_MAP_SIZE_TECHNICAL;

extern std::array<std::array<float, heatmap_size>, heatmap_size> heatmap_data;
void clear_heatmap();
void increment_guests_on_peep_map();
float get_normalized_heatmap_value_at(TileCoordsXY const xy);

#endif
