#include <Arduino.h>
#include "screen_a.h"
#include "screen_manager.h"

//bool isLeftOn = true;



static lv_obj_t* leftBtn;
static lv_obj_t* rightBtn;

static lv_style_t orangeStyle, greenStyle, blueStyle;
//bool isLeftOn = false;

static void onTouchEvent(lv_event_t* e) {
  lv_obj_t* target = lv_event_get_target(e);

  if (target == leftBtn) {
    isLeftOn = !isLeftOn;
    Serial.printf("💚 Left button toggled: %s\n", isLeftOn ? "GREEN" : "ORANGE");
    lv_obj_add_style(leftBtn, isLeftOn ? &greenStyle : &orangeStyle, 0);
  } else if (target == rightBtn) {
    Serial.println("➡️ Right button pressed: Switching to new screen");
    load_screen(1);
  }
}

lv_obj_t* create_screen_a() {
  lv_obj_t* scr = lv_obj_create(NULL);
  lv_obj_set_style_bg_color(scr, lv_color_hex(0x303030), 0);  // Dark Grey
  //lv_obj_set_style_bg_opa(scr, LV_OPA_COVER, 0);
  lv_obj_set_style_bg_opa(scr, LV_OPA_COVER, LV_PART_MAIN);


  

  // Styles
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




  //BUTTONS

   // Left Button
  leftBtn = lv_obj_create(scr);
  lv_obj_set_size(leftBtn, 21, 21);
  lv_obj_align(leftBtn, LV_ALIGN_LEFT_MID, 40, 0);
  lv_obj_add_style(leftBtn, &orangeStyle, 0);
  lv_obj_add_event_cb(leftBtn, onTouchEvent, LV_EVENT_CLICKED, NULL);

  // Right Button
  rightBtn = lv_obj_create(scr);
  lv_obj_set_size(rightBtn, 21, 21);
  lv_obj_align(rightBtn, LV_ALIGN_RIGHT_MID, -40, 0);
  lv_obj_add_style(rightBtn, &blueStyle, 0);
  lv_obj_add_event_cb(rightBtn, onTouchEvent, LV_EVENT_CLICKED, NULL);




  
   // LABELS//
  
  // Screen A Label
  lv_obj_t* label = lv_label_create(scr);
  lv_obj_set_style_text_font(label, &lv_font_montserrat_36, 0);
  lv_obj_set_style_text_color(label, lv_color_hex(0xFFFFFF), 0);  // White text
  lv_label_set_text(label, "SCREEN A");
  lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 20);

  return scr;
}
