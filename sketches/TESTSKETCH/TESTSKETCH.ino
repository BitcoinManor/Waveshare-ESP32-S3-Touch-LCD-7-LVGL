#include <Arduino.h>
#include <Waveshare_ST7262_LVGL.h>
#include <lvgl.h>

void setup() {
  Serial.begin(115200);
  Serial.println("🚀 BLOKDBIT Spark: Trial Sketch Start");

  Serial.println("🔧 Initializing LCD...");
  lcd_init();  // Waveshare-native init

  Serial.println("🟧 Drawing Orange Square...");
  lvgl_port_lock(-1);

  // Create square
  lv_obj_t* square = lv_obj_create(lv_scr_act());
  lv_obj_set_size(square, 100, 100);  // Square dimensions
  lv_obj_center(square);              // Center on screen

  // Style it orange
  static lv_style_t style;
  lv_style_init(&style);
  lv_style_set_bg_color(&style, lv_color_hex(0xFF8000));  // Orange
  lv_style_set_bg_opa(&style, LV_OPA_COVER);
  lv_style_set_radius(&style, 8);  // Rounded corners

  lv_obj_add_style(square, &style, 0);

  lvgl_port_unlock();
  Serial.println("✅ Square Created!");
}

void loop() {
  delay(5);  // Let LVGL refresh
  lv_timer_handler();
}
