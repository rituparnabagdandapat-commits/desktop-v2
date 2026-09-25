#include "limine.h"
#include <stdint.h>
static volatile struct limine_framebuffer_request fb = {.id=LIMINE_FRAMEBUFFER_REQUEST,.revision=0};
void _start(void){
 for(;;){
  if(fb.response && fb.response->framebuffer_count>0){
   struct limine_framebuffer *f=fb.response->framebuffers[0];
   for(uint64_t y=0;y<f->height;y++) for(uint64_t x=0;x<f->width;x++) ((uint32_t*)f->address)[y*(f->pitch/4)+x]=0x0078D7;
  }
  __asm__("hlt");
 }
}
