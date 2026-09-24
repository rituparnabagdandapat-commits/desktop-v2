#include <stdint.h>

static volatile struct limine_framebuffer_request fb_req = {
   .id = LIMINE_FRAMEBUFFER_REQUEST,
   .revision = 0
};

void put_pixel(uint32_t* fb, int width, int x, int y, uint32_t color){
    fb[y*width + x] = color;
}
void draw_rect(uint32_t* fb, int width, int x, int y, int w, int h, uint32_t color){
    for(int j=y; j<y+h; j++)
        for(int i=x; i<x+w; i++)
            put_pixel(fb, width, i, j, color);
}

void kmain(void){
    if(fb_req.response == 0) while(1);
    struct limine_framebuffer *fb = fb_req.response->framebuffers[0];
    uint32_t* buffer = fb->address;

    // DESKTOP - BLUE LIKE WINDOWS
    draw_rect(buffer, fb->width, 0,0, fb->width, fb->height, 0x0087CEEB);
    // TASKBAR
    draw_rect(buffer, fb->width, 0, fb->height-40, fb->width, 40, 0x00111111);
    // START BUTTON
    draw_rect(buffer, fb->width, 10, fb->height-35, 80, 30, 0x00007B00);
    // WINDOW
    draw_rect(buffer, fb->width, 100,100, 600,400, 0x00FFFFFF);
    draw_rect(buffer, fb->width, 100,100, 600,30, 0x000000FF);

    while(1){}
}
