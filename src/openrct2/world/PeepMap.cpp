#include "PeepMap.h"

#include "../peep/Peep.h"
#include "Map.h"
#include "Sprite.h"

#include <array>
#include <iostream>

static float                                              max_heatmap = 0;
std::array<std::array<float, heatmap_size>, heatmap_size> heatmap_data;

void clear_heatmap()
{
    float * begin = &heatmap_data[0][0];
    std::fill_n(begin, heatmap_size * heatmap_size, 0);
}

void clear_heatmap_once()
{
    static bool cleared = false;
    if (!cleared)
    {
        clear_heatmap();
        cleared = true;
    }
}

void increment_guests_on_peep_map()
{
    clear_heatmap_once();

    unsigned   sprite_index = 0;
    rct_peep * peep         = nullptr;
    FOR_ALL_GUESTS(sprite_index, peep)
    {
        auto & p = *peep;
        auto   x = p.x / 32;
        auto   y = p.y / 32;
        if (!(x < 0 || x > 256 || y < 0 || y > 256))
        {
            auto & v = heatmap_data[y][x];
            v++;
            max_heatmap = std::max(v, max_heatmap);
        }
    }

    float * begin = &heatmap_data[0][0];
    for(unsigned int i = 0; i < heatmap_size * heatmap_size; i++){
        begin[i] *= 0.99f;
    }
}

//! @returns value between [0, 1]: not busy to most busy.
float get_normalized_heatmap_value_at(TileCoordsXY const xy)
{
    auto x = xy.x;
    auto y = xy.y;
    if (!(x < 0 || x > 256 || y < 0 || y > 256))
    {
        return heatmap_data[xy.y][xy.x] / max_heatmap;
    }
    else
    {
        return 0.0f;
    }
}
