#include "Framebuffer.h"


FrameBuffer::FrameBuffer(int width, int height): width(width), height(height), pixels(width*height) { }

void FrameBuffer::putPixel(int x, int y, Color color){
    if(x < 0 || x >= width || y < 0 || y >= height){
        return;
    }
    pixels[y * width + x] = color;
}