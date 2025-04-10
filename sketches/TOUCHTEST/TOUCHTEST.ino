#include <Arduino.h>
#include <Waveshare_ST7262_LVGL.h>
#include <lvgl.h>

lv_obj_t* touchButton;
static lv_style_t orangeStyle;
static lv_style_t greenStyle;

void onTouchEvent(lv_event_t* e) {
  lv_event_code_t code = lv_event_get_code(e);
  if (code == LV_EVENT_CLICKED) {
    Serial.println("💚 Touched!");
    lv_obj_add_style(touchButton, &greenStyle, 0);  // Change color
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("🚀 Touch Test Start");

  lcd_init();  // Initializes display + touch

  // Init LVGL styles
  lvgl_port_lock(-1);

  lv_style_init(&orangeStyle);
  lv_style_set_bg_color(&orangeStyle, lv_color_hex(0xFFA500));  // Orange
  lv_style_set_radius(&orangeStyle, 10);
  lv_style_set_bg_opa(&orangeStyle, LV_OPA_COVER);

  lv_style_init(&greenStyle);
  lv_style_set_bg_color(&greenStyle, lv_color_hex(0x00FF00));  // Green
  lv_style_set_radius(&greenStyle, 10);
  lv_style_set_bg_opa(&greenStyle, LV_OPA_COVER);

  // Create button
  touchButton = lv_obj_create(lv_scr_act());
  lv_obj_set_size(touchButton, 200, 200);
  lv_obj_center(touchButton);
  lv_obj_add_style(touchButton, &orangeStyle, 0);

  // Attach touch event
  lv_obj_add_event_cb(touchButton, onTouchEvent, LV_EVENT_ALL, NULL);

  lvgl_port_unlock();
}

void loop() {
  delay(5);
  lv_timer_handler();  // Run LVGL events
}
