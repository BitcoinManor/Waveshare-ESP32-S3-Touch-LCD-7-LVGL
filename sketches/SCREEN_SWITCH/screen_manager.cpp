#include "screen_manager.h"
#include "screen_a.h"
#include "screen_b.h"
#include <lvgl.h>

void screen_manager_init() {
  lv_scr_load(create_screen_a());
}

void load_screen(int index) {
  if (index == 0) {
    lv_scr_load(create_screen_a());
  } else if (index == 1) {
    lv_scr_load(create_screen_b());
  }
}