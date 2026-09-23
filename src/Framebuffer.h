#pragma once

#include "Color.h"


#include <vector>


class FrameBuffer{
    public:
        FrameBuffer(int width, int height);

        void putPixel(int x, int y, Color color);
    private:
        int height;
        int width;

        std::vector<Color> pixels;
};
