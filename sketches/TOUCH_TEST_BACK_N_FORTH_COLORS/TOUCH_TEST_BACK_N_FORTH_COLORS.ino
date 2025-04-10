#include <Arduino.h>
#include <Waveshare_ST7262_LVGL.h>
#include <lvgl.h>

// Button pointers
lv_obj_t* leftBtn;
lv_obj_t* rightBtn;

// Styles
static lv_style_t orangeStyle, greenStyle;
static lv_style_t blueStyle, yellowStyle;

// NEW: Toggle flags
bool isLeftOn = false;
bool isRightOn = false;

void onTouchEvent(lv_event_t* e) {
  lv_obj_t* target = lv_event_get_target(e);
  lv_event_code_t code = lv_event_get_code(e);

  if (code == LV_EVENT_CLICKED) {
    if (target == leftBtn) {
      isLeftOn = !isLeftOn;
      Serial.print("💚 Left button toggled: ");
      Serial.println(isLeftOn ? "GREEN" : "ORANGE");
      lv_obj_add_style(leftBtn, isLeftOn ? &greenStyle : &orangeStyle, 0);
    } 
    else if (target == rightBtn) {
      isRightOn = !isRightOn;
      Serial.print("💛 Right button toggled: ");
      Serial.println(isRightOn ? "YELLOW" : "BLUE");
      lv_obj_add_style(rightBtn, isRightOn ? &yellowStyle : &blueStyle, 0);
    }
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("🚀 Touch Test: Dual Button Toggle Mode");

  lcd_init();

  lvgl_port_lock(-1);

  // Init styles
  lv_style_init(&orangeStyle);
  lv_style_set_bg_color(&orangeStyle, lv_color_hex(0xFFA500));
  lv_style_set_radius(&orangeStyle, 10);
  lv_style_set_bg_opa(&orangeStyle, LV_OPA_COVER);

  lv_style_init(&greenStyle);
  lv_style_set_bg_color(&greenStyle, lv_color_hex(0x00FF00));
  lv_style_set_radius(&greenStyle, 10);
  lv_style_set_bg_opa(&greenStyle, LV_OPA_COVER);

  lv_style_init(&blueStyle);
  lv_style_set_bg_color(&blueStyle, lv_color_hex(0x007BFF));
  lv_style_set_radius(&blueStyle, 10);
  lv_style_set_bg_opa(&blueStyle, LV_OPA_COVER);

  lv_style_init(&yellowStyle);
  lv_style_set_bg_color(&yellowStyle, lv_color_hex(0xFFFF00));
  lv_style_set_radius(&yellowStyle, 10);
  lv_style_set_bg_opa(&yellowStyle, LV_OPA_COVER);

  // Create left button
  leftBtn = lv_obj_create(lv_scr_act());
  lv_obj_set_size(leftBtn, 160, 160);
  lv_obj_align(leftBtn, LV_ALIGN_LEFT_MID, 40, 0);
  lv_obj_add_style(leftBtn, &orangeStyle, 0);  // Start with orange
  lv_obj_add_event_cb(leftBtn, onTouchEvent, LV_EVENT_ALL, NULL);

  // Create right button
  rightBtn = lv_obj_create(lv_scr_act());
  lv_obj_set_size(rightBtn, 160, 160);
  lv_obj_align(rightBtn, LV_ALIGN_RIGHT_MID, -40, 0);
  lv_obj_add_style(rightBtn, &blueStyle, 0);  // Start with blue
  lv_obj_add_event_cb(rightBtn, onTouchEvent, LV_EVENT_ALL, NULL);

  lvgl_port_unlock();

  Serial.println("✅ Buttons created — touch to toggle colors.");
}

void loop() {
  delay(5);
  lv_timer_handler();
}
