#pragma once

#include "watch_config.h"
    
/* PebbleKit JS, Message Keys, Pebble config keys */
// FIXME why can't this be generated from the json settings file into a header?
#define KEY_TIME_COLOR 0
#define KEY_VIBRATE_ON_DISCONNECT 1
#define KEY_BACKGROUND_COLOR 2

#ifndef BLUETOOTH_DISCONNECTED_STR
#define BLUETOOTH_DISCONNECTED_STR "BT Disconnected"
#endif /* BLUETOOTH_DISCONNECTED_STR */

#ifndef DATE_FMT_STR
#define DATE_FMT_STR "%a, %d %b"  /* TODO review %d for day */
#endif /* DATE_FMT_STR */
#define MAX_DATE_STR "Thu, 00 Aug"

#define MAX_TIME_STR "00:00"

#define BAT_FMT_STR "Bat: %d%%"
#define MAX_BAT_STR "Bat: ??%"  // When Battery is 100, the percent symbol is deliberately not shown (buffer full/truncated)

extern Window    *s_main_window;
extern TextLayer *s_time_layer;
extern TextLayer *s_date_layer;
extern TextLayer *s_battery_layer;
extern TextLayer *s_bluetooth_layer;

extern GFont       s_time_font;
extern BitmapLayer *s_background_layer;
extern GBitmap     *s_background_bitmap;
/* For colors, see http://developer.getpebble.com/tools/color-picker/#0000FF */
extern GColor       time_color;  /* NOTE used for date too */
extern GColor       background_color;
extern int          config_time_color;
extern int          config_background_color;
extern bool         config_time_vib_on_disconnect;

extern int last_day;
extern bool bluetooth_state;

extern void handle_bluetooth(bool connected);
extern void setup_bluetooth(Window *window);
extern void cleanup_bluetooth();
extern void handle_battery(BatteryChargeState charge_state);
extern void setup_battery(Window *window);
extern void cleanup_battery();
extern void update_date(struct tm *tick_time);
extern void setup_date(Window *window);
extern void cleanup_date();
extern void update_time();
extern void main_window_load(Window *window);
extern void main_window_unload(Window *window);
extern void tick_handler(struct tm *tick_time, TimeUnits units_changed);
extern void in_recv_handler(DictionaryIterator *iterator, void *context);
extern void init();
extern void deinit();
