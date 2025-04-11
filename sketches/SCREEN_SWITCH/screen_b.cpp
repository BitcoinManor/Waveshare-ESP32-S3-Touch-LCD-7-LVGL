#include <Arduino.h>
#include "screen_b.h"
#include "screen_manager.h"

extern lv_obj_t* backBtn;


//bool isRightOn = false;



static void onTouchEvent(lv_event_t* e) {
  lv_obj_t* target = lv_event_get_target(e);

  if (target == backBtn) {
    Serial.println("➡️ Back button pressed: Switching to Screen A");
    load_screen(0);
  }
}


lv_obj_t* create_screen_b() {
  lv_obj_t* scr = lv_obj_create(NULL);
  lv_obj_set_style_bg_color(scr, lv_color_hex(0x303030), 0); //Slate Grey
  //lv_obj_set_style_bg_opa(scr, LV_OPA_COVER, 0);
  lv_obj_set_style_bg_opa(scr, LV_OPA_COVER, LV_PART_MAIN);


  // Label in center
  lv_obj_t* label = lv_label_create(scr);
  //lv_obj_set_style_text_font(label, &lv_font_unscii_16, 0); 
  lv_obj_set_style_text_font(label, &lv_font_montserrat_36, 0);  
  lv_obj_set_style_text_color(label, lv_color_hex(0xFFFFFF), 0);  // White text
  lv_label_set_text(label, "SCREEN B");
  lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 20);



  //BUTTONS

  // Left side Back Button
  backBtn = lv_obj_create(scr);
  lv_obj_set_size(backBtn, 21, 21);
  lv_obj_align(backBtn, LV_ALIGN_LEFT_MID, 40, 0);
  lv_obj_add_style(backBtn, &orangeStyle, 0);
  lv_obj_add_event_cb(backBtn, onTouchEvent, LV_EVENT_CLICKED, NULL);

  

  return scr;
}
