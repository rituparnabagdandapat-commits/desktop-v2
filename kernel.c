#include "limine.h"
#include <stdint.h>
static volatile struct limine_framebuffer_request fb_req = {.id=LIMINE_FRAMEBUFFER_REQUEST,.revision=0};
void _start(void){
    if(fb_req.response==0||fb_req.response->framebuffer_count<1) for(;;) __asm__("hlt");
    struct limine_framebuffer *fb=fb_req.response->framebuffers[0];
    for(uint64_t y=0;y<fb->height;y++){
        uint8_t *line=(uint8_t*)fb->address + y*fb->pitch;
        for(uint64_t x=0;x<fb->width;x++){ line[x*4+0]=0x8A; line[x*4+1]=0x3A; line[x*4+2]=0x1E; }
    }
    for(;;) __asm__("hlt");
}
