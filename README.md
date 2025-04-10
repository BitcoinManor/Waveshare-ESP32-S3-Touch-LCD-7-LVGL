# Waveshare-ESP32-S3-Touch-LCD-7-LVGL

Test Suite and Working Libraries for the [Waveshare ESP32-S3 7" Touch LCD](https://www.waveshare.com/wiki/ESP32-S3-Touch-LCD-7)  
Includes display, touch, and UI demos using LVGL v8.4.0 and Arduino.

---

## 📦 What's Included

- ✅ Working `lib/` folder with **verified library versions**
- ✅ Touch + display test sketches
- ✅ Preconfigured `lv_conf.h` (for LVGL)
- ✅ Designed for **Arduino IDE or VS Code + PlatformIO**
- ✅ Fully matches Waveshare hardware defaults

---

## 🧰 Hardware Requirements

- 📟 Waveshare ESP32-S3 7" Touch LCD
- 🖥️ USB-C cable + Arduino IDE
- No soldering or external parts required

---

## 🔧 Installation (Arduino IDE)

1. Clone or download this repo
2. Open any `.ino` sketch in the `sketches/` folder
3. Make sure `lib/` folder is in the same directory as your `.ino`
4. Click "Upload" — that's it!

---

## 🧪 Test Sketches

| Sketch Folder          | Description                          |
|------------------------|--------------------------------------|
| Touch_Toggle_Buttons   | Two colored buttons that toggle color on touch |
| Touch_Single_Button    | Basic test with one reactive button |
| Touch_Drag_Physics     | *(Coming soon)* Drag an object across the screen with momentum |
| Touch_Swipe_ScreenNav  | *(Coming soon)* Swipe left/right to change screens |

---

## 📚 Libraries Used

| Library                | Version   |
|------------------------|-----------|
| lvgl                   | 8.4.0     |
| Waveshare_ST7262_LVGL  | 0.1       |
| ESP32_Display_Panel    | 0.1.4     |
| ESP32_IO_Expander      | 0.0.3     |
| esp-lib-utils          | bundled   |

---

## 🙌 Why This Exists

Setting up the Waveshare ESP32-S3 7" LCD with LVGL can be confusing — especially with library versions, includes, and touch configuration.

This repo is a 100% working setup, shared to help the community get started faster.

---

## 📜 License

MIT — use, modify, and share freely.
