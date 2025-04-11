#pragma once
#include <lvgl.h>
extern bool isRightOn;
extern lv_style_t orangeStyle;
extern lv_obj_t* backBtn; // ✅ This tells other files it exists


lv_obj_t* create_screen_b();
