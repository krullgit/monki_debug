#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_SNAPPABLE|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_s1_bg);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
        }
        {
            // ui_s1_arc_1
            lv_obj_t *obj = lv_arc_create(parent_obj);
            objects.ui_s1_arc_1 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 466, 466);
            lv_arc_set_value(obj, 100);
            lv_arc_set_bg_start_angle(obj, 40);
            lv_arc_set_bg_end_angle(obj, 140);
            lv_arc_set_mode(obj, LV_ARC_MODE_REVERSE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0xff4a4c4a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_width(obj, 18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff7bf00), LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, -1, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, -1, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, -1, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, -1, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_hex(theme_colors[0][3]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_width(obj, 18, LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
        {
            // s1_label_percentage_of_max
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s1_label_percentage_of_max = obj;
            lv_obj_set_pos(obj, 363, 248);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "40%");
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff4a4c4a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s1_label_grip_type
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s1_label_grip_type = obj;
            lv_obj_set_pos(obj, 39, 248);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "O");
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff834cc5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_arc_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 466, 466);
            lv_arc_set_value(obj, 0);
            lv_arc_set_bg_start_angle(obj, 192);
            lv_arc_set_bg_end_angle(obj, 349);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_arc_rounded(obj, false, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_hex(theme_colors[0][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_width(obj, 18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_arc_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, -1, 0);
            lv_obj_set_size(obj, 466, 466);
            lv_arc_set_value(obj, 0);
            lv_arc_set_bg_start_angle(obj, 238);
            lv_arc_set_bg_end_angle(obj, 302);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_arc_rounded(obj, false, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_width(obj, 29, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 122, 97);
            lv_obj_set_size(obj, 254, 102);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_KNOB | LV_STATE_DEFAULT);
            {
                static lv_coord_t dsc[] = {LV_GRID_TEMPLATE_LAST};
                lv_obj_set_style_grid_column_dsc_array(obj, dsc, LV_PART_KNOB | LV_STATE_DEFAULT);
            }
            {
                static lv_coord_t dsc[] = {LV_GRID_TEMPLATE_LAST};
                lv_obj_set_style_grid_row_dsc_array(obj, dsc, LV_PART_KNOB | LV_STATE_DEFAULT);
            }
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // ui_label_rpm
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.ui_label_rpm = obj;
                    lv_obj_set_pos(obj, 182, -17);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "0");
                    lv_obj_set_style_text_font(obj, &ui_font_main_medium_100, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, -15, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // ui_label_rpm2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.ui_label_rpm2 = obj;
                    lv_obj_set_pos(obj, 153, 43);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, ".4");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff39fa9c), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_main_medium_40, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 60, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // s1_label_time_remaining
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s1_label_time_remaining = obj;
            lv_obj_set_pos(obj, 199, 424);
            lv_obj_set_size(obj, 69, 34);
            lv_label_set_text(obj, "10");
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfff7bf00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xfff7bf00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s1_label_percentage_max
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s1_label_percentage_max = obj;
            lv_obj_set_pos(obj, 317, 64);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "+5");
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff808080), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s1_label_percentage_min
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s1_label_percentage_min = obj;
            lv_obj_set_pos(obj, 121, 64);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "-5");
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff808080), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s1_label_percentage_target
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s1_label_percentage_target = obj;
            lv_obj_set_pos(obj, 208, 35);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "35%");
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // ui_s1_arc_needle
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.ui_s1_arc_needle = obj;
            lv_obj_set_pos(obj, 221, 411);
            lv_obj_set_size(obj, 12, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_transform_angle(obj, 1010, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_transform_pivot_y(obj, -178, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_transform_pivot_x(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // ui_s1_flex_container2
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.ui_s1_flex_container2 = obj;
            lv_obj_set_pos(obj, 84, 248);
            lv_obj_set_size(obj, 300, 154);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS|LV_OBJ_FLAG_SCROLL_ONE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
            lv_obj_set_scroll_snap_x(obj, LV_DIR_HOR);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, 267, 199);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s1_hand_r_11111);
                }
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, 195, 198);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s1_hand_l_00100);
                }
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, 77, 198);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s1_hand_l_00111);
                }
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, 245, 269);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s1_hand_r_00100);
                }
            }
        }
    }
}

void tick_screen_main() {
}

void create_screen_screen_s1_2() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_s1_2 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // s1_2_btn_finish_set
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.s1_2_btn_finish_set = obj;
            lv_obj_set_pos(obj, 312, 278);
            lv_obj_set_size(obj, 70, 70);
            add_style_button_mid(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -6, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // s1_2_btn_go_to_s2_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.s1_2_btn_go_to_s2_1 = obj;
            lv_obj_set_pos(obj, 312, 113);
            lv_obj_set_size(obj, 70, 70);
            add_style_button_mid(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // s1_2_bar_progress_of_sets
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.s1_2_bar_progress_of_sets = obj;
            lv_obj_set_pos(obj, 88, 308);
            lv_obj_set_size(obj, 200, 10);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][3]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
        {
            // s1_2_label_progress_of_sets
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s1_2_label_progress_of_sets = obj;
            lv_obj_set_pos(obj, 136, 331);
            lv_obj_set_size(obj, 117, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "(1/20)");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s1_2_bar_progress_of_session
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.s1_2_bar_progress_of_session = obj;
            lv_obj_set_pos(obj, 88, 143);
            lv_obj_set_size(obj, 200, 10);
            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][3]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
        {
            // s1_2_label_progress_of_session
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s1_2_label_progress_of_session = obj;
            lv_obj_set_pos(obj, 136, 98);
            lv_obj_set_size(obj, 117, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "(1/10)");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            static lv_point_t line_points[] = {
                { 0, 0 },
                { 350, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            objects.obj2 = obj;
            lv_obj_set_pos(obj, 58, 232);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_line_color(obj, lv_color_hex(theme_colors[0][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 334, 135);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_cross_x);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 334, 301);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_cross_x);
        }
        {
            // s1_4
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s1_4 = obj;
            lv_obj_set_pos(obj, 136, 69);
            lv_obj_set_size(obj, 117, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "SET");
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s1_5
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s1_5 = obj;
            lv_obj_set_pos(obj, 136, 359);
            lv_obj_set_size(obj, 117, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "COMBO");
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_screen_s1_2() {
}

void create_screen_screen_s1_3() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_s1_3 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // s1_6
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s1_6 = obj;
            lv_obj_set_pos(obj, 136, 69);
            lv_obj_set_size(obj, 117, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "SET");
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s1_3_label_progress_of_session
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s1_3_label_progress_of_session = obj;
            lv_obj_set_pos(obj, 136, 98);
            lv_obj_set_size(obj, 117, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "(1/10)");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s1_3_btn_go_to_s2_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.s1_3_btn_go_to_s2_1 = obj;
            lv_obj_set_pos(obj, 312, 113);
            lv_obj_set_size(obj, 70, 70);
            add_style_button_mid(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 334, 135);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_cross_x);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            static lv_point_t line_points[] = {
                { 0, 0 },
                { 350, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            objects.obj3 = obj;
            lv_obj_set_pos(obj, 58, 232);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_line_color(obj, lv_color_hex(theme_colors[0][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s1_3_bar_progress_of_session
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.s1_3_bar_progress_of_session = obj;
            lv_obj_set_pos(obj, 88, 143);
            lv_obj_set_size(obj, 200, 10);
            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][3]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
        {
            // s1_3_btn_train_now
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.s1_3_btn_train_now = obj;
            lv_obj_set_pos(obj, 312, 278);
            lv_obj_set_size(obj, 70, 70);
            add_style_button_mid(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -6, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 333, 296);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_s1_3_arrow);
        }
        {
            // s1_3_label_pause_time_left
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s1_3_label_pause_time_left = obj;
            lv_obj_set_pos(obj, 86, 267);
            lv_obj_set_size(obj, 205, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "12:34");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_75, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_screen_s1_3() {
}

void create_screen_screen_s2_1() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_s2_1 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_SNAPPABLE|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER);
    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_scroll_snap_x(obj, LV_DIR_NONE);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // s2_1_flex_container1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.s2_1_flex_container1 = obj;
            lv_obj_set_pos(obj, 301, 0);
            lv_obj_set_size(obj, 94, 466);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
            lv_obj_set_scroll_snap_x(obj, LV_DIR_VER);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // s2_1_cf
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_1_cf = obj;
                    lv_obj_set_pos(obj, 70, 155);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s2_1_cf);
                }
                {
                    // s2_1_max
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_1_max = obj;
                    lv_obj_set_pos(obj, -3, 184);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s2_1_max);
                }
                {
                    // s2_1_sets
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_1_sets = obj;
                    lv_obj_set_pos(obj, 314, 134);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s2_1_sets);
                }
                {
                    // s2_1_settings
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_1_settings = obj;
                    lv_obj_set_pos(obj, 111, 144);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s2_1_settings);
                }
                {
                    // s2_1_train
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_1_train = obj;
                    lv_obj_set_pos(obj, 70, 133);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s2_1_train);
                }
            }
        }
        {
            // s2_1_focussed_ring
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.s2_1_focussed_ring = obj;
            lv_obj_set_pos(obj, 301, 186);
            lv_obj_set_size(obj, 94, 94);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s2_1_label_focussed_text
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s2_1_label_focussed_text = obj;
            lv_obj_set_pos(obj, -26, 209);
            lv_obj_set_size(obj, 298, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Left Hand");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_40, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_screen_s2_1() {
}

void create_screen_screen_s3_1() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_s3_1 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // s3_1_flex_container1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.s3_1_flex_container1 = obj;
            lv_obj_set_pos(obj, 301, 0);
            lv_obj_set_size(obj, 94, 466);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
            lv_obj_set_scroll_snap_x(obj, LV_DIR_VER);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // s2_3
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_3 = obj;
                    lv_obj_set_pos(obj, 70, 155);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s3_1_set1);
                }
                {
                    // s2_4
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_4 = obj;
                    lv_obj_set_pos(obj, -3, 184);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s3_1_set2);
                }
                {
                    // s2_5
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_5 = obj;
                    lv_obj_set_pos(obj, 314, 134);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s3_1_set3);
                }
                {
                    // s2_6
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_6 = obj;
                    lv_obj_set_pos(obj, 111, 144);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s3_1_set4);
                }
                {
                    // s2_7
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_7 = obj;
                    lv_obj_set_pos(obj, 70, 133);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s3_1_set5);
                }
            }
        }
        {
            // s3_1_focussed_ring
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.s3_1_focussed_ring = obj;
            lv_obj_set_pos(obj, 301, 186);
            lv_obj_set_size(obj, 94, 94);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s3_1_label_focussed_text
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s3_1_label_focussed_text = obj;
            lv_obj_set_pos(obj, 16, 209);
            lv_obj_set_size(obj, 256, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Set 1");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_40, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s3_1_img_edit
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.s3_1_img_edit = obj;
            lv_obj_set_pos(obj, 236, 302);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_edit_pen1);
            lv_obj_set_style_img_opa(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s3_1_btn_rename
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.s3_1_btn_rename = obj;
            lv_obj_set_pos(obj, 152, 299);
            lv_obj_set_size(obj, 114, 67);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_screen_s3_1() {
}

void create_screen_screen_s3_2() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_s3_2 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(obj, lv_color_hex(theme_colors[0][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_s3_2_bg);
        }
        {
            // s3_2_roller_per_of_max
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.s3_2_roller_per_of_max = obj;
            lv_obj_set_pos(obj, 38, 172);
            lv_obj_set_size(obj, 80, 122);
            lv_roller_set_options(obj, "40\n41\n42\n43\n44\n45", LV_ROLLER_MODE_NORMAL);
            lv_roller_set_selected(obj, 1, LV_ANIM_OFF);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[0][4]), LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 5, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_SELECTED | LV_STATE_DEFAULT);
        }
        {
            // s3_2_roller_train
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.s3_2_roller_train = obj;
            lv_obj_set_pos(obj, 138, 172);
            lv_obj_set_size(obj, 80, 122);
            lv_roller_set_options(obj, "10\n11\n12", LV_ROLLER_MODE_NORMAL);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[0][3]), LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 5, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_SELECTED | LV_STATE_DEFAULT);
        }
        {
            // s3_2_roller_pause
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.s3_2_roller_pause = obj;
            lv_obj_set_pos(obj, 237, 172);
            lv_obj_set_size(obj, 80, 122);
            lv_roller_set_options(obj, "10\n11\n12", LV_ROLLER_MODE_NORMAL);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[0][3]), LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 5, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_SELECTED | LV_STATE_DEFAULT);
        }
        {
            // s3_2_checkbox_active
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.s3_2_checkbox_active = obj;
            lv_obj_set_pos(obj, 252, 50);
            lv_obj_set_size(obj, 69, 68);
            lv_checkbox_set_text(obj, "");
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_ON_FOCUS|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_INDICATOR | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_INDICATOR | LV_STATE_CHECKED);
            lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                static lv_coord_t dsc[] = {LV_GRID_TEMPLATE_LAST};
                lv_obj_set_style_grid_row_dsc_array(obj, dsc, LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                static lv_coord_t dsc[] = {LV_GRID_TEMPLATE_LAST};
                lv_obj_set_style_grid_column_dsc_array(obj, dsc, LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s3_2_roller_grip_type
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.s3_2_roller_grip_type = obj;
            lv_obj_set_pos(obj, 237, 312);
            lv_obj_set_size(obj, 80, 122);
            lv_roller_set_options(obj, "O\nHC\nC\nPIN\n\n", LV_ROLLER_MODE_NORMAL);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[0][0]), LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 5, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_SELECTED | LV_STATE_DEFAULT);
        }
        {
            // s3_2_flex_container1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.s3_2_flex_container1 = obj;
            lv_obj_set_pos(obj, 356, 0);
            lv_obj_set_size(obj, 94, 466);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
            lv_obj_set_scroll_snap_x(obj, LV_DIR_VER);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // s2_8
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_8 = obj;
                    lv_obj_set_pos(obj, 70, 155);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s1_hand_l_00001_small);
                }
                {
                    // s2_9
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_9 = obj;
                    lv_obj_set_pos(obj, -3, 184);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s1_hand_l_00010_small);
                }
                {
                    // s2_10
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_10 = obj;
                    lv_obj_set_pos(obj, 314, 134);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s1_hand_l_00100_small);
                }
                {
                    // s2_11
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_11 = obj;
                    lv_obj_set_pos(obj, 111, 144);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s1_hand_l_00110_small);
                }
                {
                    // s2_12
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_12 = obj;
                    lv_obj_set_pos(obj, 70, 133);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s1_hand_r_00100_small);
                }
            }
        }
        {
            // s3_2_roller_grip_edge
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.s3_2_roller_grip_edge = obj;
            lv_obj_set_pos(obj, 139, 313);
            lv_obj_set_size(obj, 80, 122);
            lv_roller_set_options(obj, "10mm\n11mm\n12 mm", LV_ROLLER_MODE_NORMAL);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[0][3]), LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 5, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_SELECTED | LV_STATE_DEFAULT);
        }
        {
            // s3_2_btn_right
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.s3_2_btn_right = obj;
            lv_obj_set_pos(obj, 152, 39);
            lv_obj_set_size(obj, 70, 90);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // s3_2_btn_left
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.s3_2_btn_left = obj;
            lv_obj_set_pos(obj, 82, 39);
            lv_obj_set_size(obj, 70, 90);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            static lv_point_t line_points[] = {
                { 90, 0 },
                { 90, 350 }
            };
            lv_line_set_points(obj, line_points, 2);
            objects.obj4 = obj;
            lv_obj_set_pos(obj, 252, 58);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_line_color(obj, lv_color_hex(theme_colors[0][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_screen_s3_2() {
}

void create_screen_screen_s4_1() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_s4_1 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // s4_1_btn_measure
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.s4_1_btn_measure = obj;
            lv_obj_set_pos(obj, 80, 184);
            lv_obj_set_size(obj, 150, 82);
            add_style_button_mid(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj5 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Measure");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // s4_1_btn_grip_type
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.s4_1_btn_grip_type = obj;
            lv_obj_set_pos(obj, 170, 278);
            lv_obj_set_size(obj, 150, 82);
            add_style_button_mid(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj6 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "half cr.");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // s4_1_btn_chart
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.s4_1_btn_chart = obj;
            lv_obj_set_pos(obj, 80, 278);
            lv_obj_set_size(obj, 82, 82);
            add_style_button_mid(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 99, 310);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_s4_1_chart_small);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            static lv_point_t line_points[] = {
                { 90, 0 },
                { 90, 350 }
            };
            lv_line_set_points(obj, line_points, 2);
            objects.obj7 = obj;
            lv_obj_set_pos(obj, 252, 58);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_line_color(obj, lv_color_hex(theme_colors[0][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_line_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s4_1_flex_container1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.s4_1_flex_container1 = obj;
            lv_obj_set_pos(obj, 356, 0);
            lv_obj_set_size(obj, 94, 466);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
            lv_obj_set_scroll_snap_x(obj, LV_DIR_VER);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // s2_13
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_13 = obj;
                    lv_obj_set_pos(obj, 70, 155);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s1_hand_l_00001_small);
                }
                {
                    // s2_14
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_14 = obj;
                    lv_obj_set_pos(obj, -3, 184);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s1_hand_l_00010_small);
                }
                {
                    // s2_15
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_15 = obj;
                    lv_obj_set_pos(obj, 314, 134);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s1_hand_l_00100_small);
                }
                {
                    // s2_16
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_16 = obj;
                    lv_obj_set_pos(obj, 111, 144);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s1_hand_l_00110_small);
                }
                {
                    // s2_17
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_17 = obj;
                    lv_obj_set_pos(obj, 70, 133);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s1_hand_r_00100_small);
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 83, 77);
            lv_obj_set_size(obj, 254, 102);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_KNOB | LV_STATE_DEFAULT);
            {
                static lv_coord_t dsc[] = {LV_GRID_TEMPLATE_LAST};
                lv_obj_set_style_grid_column_dsc_array(obj, dsc, LV_PART_KNOB | LV_STATE_DEFAULT);
            }
            {
                static lv_coord_t dsc[] = {LV_GRID_TEMPLATE_LAST};
                lv_obj_set_style_grid_row_dsc_array(obj, dsc, LV_PART_KNOB | LV_STATE_DEFAULT);
            }
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // s4_1_label_kg_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.s4_1_label_kg_1 = obj;
                    lv_obj_set_pos(obj, 183, -8);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "0");
                    lv_obj_set_style_text_font(obj, &ui_font_main_medium_75, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, -15, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 170, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // s4_1_label_kg_2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.s4_1_label_kg_2 = obj;
                    lv_obj_set_pos(obj, 153, 43);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, ".4");
                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_main_medium_40, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 35, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 170, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // s4_1_btn_left_or_right
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.s4_1_btn_left_or_right = obj;
            lv_obj_set_pos(obj, 239, 185);
            lv_obj_set_size(obj, 82, 82);
            add_style_button_mid(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[0][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj8 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "L");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
}

void tick_screen_screen_s4_1() {
}

void create_screen_screen_s4_2() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_s4_2 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_s4_2_bg);
            lv_obj_set_style_img_opa(obj, 220, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s4_2_arc1
            lv_obj_t *obj = lv_arc_create(parent_obj);
            objects.s4_2_arc1 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 466, 466);
            lv_arc_set_value(obj, 50);
            lv_arc_set_bg_start_angle(obj, 130);
            lv_arc_set_bg_end_angle(obj, 410);
            lv_obj_set_style_arc_rounded(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_hex(theme_colors[0][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_width(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, -5, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, -5, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, -5, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, -5, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_width(obj, 20, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
        {
            // s4_2_label_kg_new_1_a
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s4_2_label_kg_new_1_a = obj;
            lv_obj_set_pos(obj, 106, 124);
            lv_obj_set_size(obj, 63, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "1");
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            static lv_point_t line_points[] = {
                { 90, 0 },
                { 90, 170 }
            };
            lv_line_set_points(obj, line_points, 2);
            objects.obj9 = obj;
            lv_obj_set_pos(obj, 142, 150);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_line_color(obj, lv_color_hex(theme_colors[0][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_line_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s4_2_label_kg
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s4_2_label_kg = obj;
            lv_obj_set_pos(obj, 197, 95);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "21.4 kg");
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            static lv_point_t line_points[] = {
                { 90, 0 },
                { 90, 20 }
            };
            lv_line_set_points(obj, line_points, 2);
            objects.obj10 = obj;
            lv_obj_set_pos(obj, 142, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_line_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_line_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s4_2_label_per_new
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s4_2_label_per_new = obj;
            lv_obj_set_pos(obj, 93, 339);
            lv_obj_set_size(obj, 148, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "?");
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s4_2_img_combo
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.s4_2_img_combo = obj;
            lv_obj_set_pos(obj, 193, 355);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_s1_hand_l_00100);
            lv_obj_set_style_img_opa(obj, 45, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s4_2_label_kg_new_1_b
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s4_2_label_kg_new_1_b = obj;
            lv_obj_set_pos(obj, 165, 124);
            lv_obj_set_size(obj, 63, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "4");
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s4_2_label_kg_new_2_a
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s4_2_label_kg_new_2_a = obj;
            lv_obj_set_pos(obj, 107, 219);
            lv_obj_set_size(obj, 63, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "6");
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s4_2_label_kg_new_2_b
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s4_2_label_kg_new_2_b = obj;
            lv_obj_set_pos(obj, 165, 219);
            lv_obj_set_size(obj, 63, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "6");
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s4_2_label_kg_old_1_a
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s4_2_label_kg_old_1_a = obj;
            lv_obj_set_pos(obj, 238, 125);
            lv_obj_set_size(obj, 63, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "5");
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s4_2_label_kg_old_1_b
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s4_2_label_kg_old_1_b = obj;
            lv_obj_set_pos(obj, 296, 125);
            lv_obj_set_size(obj, 63, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "2");
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s4_2_label_kg_old_2_a
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s4_2_label_kg_old_2_a = obj;
            lv_obj_set_pos(obj, 238, 220);
            lv_obj_set_size(obj, 63, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "7");
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s4_2_label_kg_old_2_b
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s4_2_label_kg_old_2_b = obj;
            lv_obj_set_pos(obj, 296, 220);
            lv_obj_set_size(obj, 63, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "8");
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s4_2_label_grip_type
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s4_2_label_grip_type = obj;
            lv_obj_set_pos(obj, 225, 339);
            lv_obj_set_size(obj, 148, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "?");
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_screen_s4_2() {
}

void create_screen_screen_s4_3() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_s4_3 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // s4_3_label_cf
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s4_3_label_cf = obj;
            lv_obj_set_pos(obj, 105, 45);
            lv_obj_set_size(obj, 256, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "40 kg");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s4_3_chart
            lv_obj_t *obj = lv_chart_create(parent_obj);
            objects.s4_3_chart = obj;
            lv_obj_set_pos(obj, 48, 102);
            lv_obj_set_size(obj, 370, 262);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_screen_s4_3() {
}

void create_screen_screen_s4_4() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_s4_4 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // s4_4_timestamp
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s4_4_timestamp = obj;
            lv_obj_set_pos(obj, 105, 70);
            lv_obj_set_size(obj, 256, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "12/12/24");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            static lv_point_t line_points[] = {
                { 0, 0 },
                { 350, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            objects.obj11 = obj;
            lv_obj_set_pos(obj, 147, 123);
            lv_obj_set_size(obj, 172, LV_SIZE_CONTENT);
            lv_obj_set_style_line_color(obj, lv_color_hex(theme_colors[0][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s6_19
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s6_19 = obj;
            lv_obj_set_pos(obj, 141, 165);
            lv_obj_set_size(obj, 184, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "kg");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff363636), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s4_4_label_kg
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s4_4_label_kg = obj;
            lv_obj_set_pos(obj, 157, 197);
            lv_obj_set_size(obj, 152, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "40");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s6_13
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s6_13 = obj;
            lv_obj_set_pos(obj, 51, 262);
            lv_obj_set_size(obj, 194, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "To First");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff363636), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s4_4_label_per_to_first
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s4_4_label_per_to_first = obj;
            lv_obj_set_pos(obj, 73, 297);
            lv_obj_set_size(obj, 152, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "+3.1%");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s6_21
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s6_21 = obj;
            lv_obj_set_pos(obj, 237, 262);
            lv_obj_set_size(obj, 184, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "To Previous");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff363636), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s4_4_label_per_to_prev
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s4_4_label_per_to_prev = obj;
            lv_obj_set_pos(obj, 253, 294);
            lv_obj_set_size(obj, 152, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "+1.1%");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s4_4_img_prev
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.s4_4_img_prev = obj;
            lv_obj_set_pos(obj, 32, 215);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_arrow_simple_left_1);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_PRESSED);
        }
        {
            // s4_4_img_next
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.s4_4_img_next = obj;
            lv_obj_set_pos(obj, 410, 206);
            lv_obj_set_size(obj, 20, 37);
            lv_img_set_src(obj, &img_arrow_simple_right_1);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_PRESSED);
        }
        {
            // s4_4_btn_prev
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.s4_4_btn_prev = obj;
            lv_obj_set_pos(obj, 5, 174);
            lv_obj_set_size(obj, 100, 120);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 150, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // s4_4_btn_next
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.s4_4_btn_next = obj;
            lv_obj_set_pos(obj, 362, 170);
            lv_obj_set_size(obj, 100, 120);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 150, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // s4_4_btn_delete
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.s4_4_btn_delete = obj;
            lv_obj_set_pos(obj, 198, 367);
            lv_obj_set_size(obj, 70, 70);
            add_style_button_mid(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 220, 389);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_cross_x);
        }
    }
}

void tick_screen_screen_s4_4() {
}

void create_screen_screen_s5_1() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_s5_1 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // s5_1_label_focussed_text
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s5_1_label_focussed_text = obj;
            lv_obj_set_pos(obj, 40, 209);
            lv_obj_set_size(obj, 232, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Session 1");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_40, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s5_1_flex_container1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.s5_1_flex_container1 = obj;
            lv_obj_set_pos(obj, 301, 0);
            lv_obj_set_size(obj, 94, 466);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
            lv_obj_set_scroll_snap_x(obj, LV_DIR_VER);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // s2_18
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_18 = obj;
                    lv_obj_set_pos(obj, 70, 155);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s3_1_set1);
                }
                {
                    // s2_19
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_19 = obj;
                    lv_obj_set_pos(obj, -3, 184);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s3_1_set2);
                }
                {
                    // s2_20
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_20 = obj;
                    lv_obj_set_pos(obj, 314, 134);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s3_1_set3);
                }
                {
                    // s2_21
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_21 = obj;
                    lv_obj_set_pos(obj, 111, 144);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s3_1_set4);
                }
                {
                    // s2_22
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_22 = obj;
                    lv_obj_set_pos(obj, 70, 133);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s3_1_set5);
                }
            }
        }
        {
            // s5_1_focussed_ring
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.s5_1_focussed_ring = obj;
            lv_obj_set_pos(obj, 301, 186);
            lv_obj_set_size(obj, 94, 94);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s5_1_btn_rename
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.s5_1_btn_rename = obj;
            lv_obj_set_pos(obj, 152, 299);
            lv_obj_set_size(obj, 114, 67);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s5_1_img_edit
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.s5_1_img_edit = obj;
            lv_obj_set_pos(obj, 236, 302);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_edit_pen1);
            lv_obj_set_style_img_opa(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_screen_s5_1() {
}

void create_screen_screen_s5_2() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_s5_2 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // s5_2_flex_container1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.s5_2_flex_container1 = obj;
            lv_obj_set_pos(obj, 301, 0);
            lv_obj_set_size(obj, 94, 466);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
            lv_obj_set_scroll_snap_x(obj, LV_DIR_VER);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // s2_23
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_23 = obj;
                    lv_obj_set_pos(obj, 70, 155);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s5_2_range);
                }
                {
                    // s2_24
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_24 = obj;
                    lv_obj_set_pos(obj, -3, 184);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s2_1_train);
                }
                {
                    // s2_26
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_26 = obj;
                    lv_obj_set_pos(obj, 111, 144);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s2_1_settings);
                }
            }
        }
        {
            // s5_2_focussed_ring
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.s5_2_focussed_ring = obj;
            lv_obj_set_pos(obj, 301, 186);
            lv_obj_set_size(obj, 94, 94);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s5_2_label_focussed_text
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s5_2_label_focussed_text = obj;
            lv_obj_set_pos(obj, -26, 209);
            lv_obj_set_size(obj, 298, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Range");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_40, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s5_2_label_session_name
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s5_2_label_session_name = obj;
            lv_obj_set_pos(obj, -26, 302);
            lv_obj_set_size(obj, 298, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Session X");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_screen_s5_2() {
}

void create_screen_screen_s5_3() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_s5_3 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // s5_3_roller_range
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.s5_3_roller_range = obj;
            lv_obj_set_pos(obj, 265, 172);
            lv_obj_set_size(obj, 80, 122);
            lv_roller_set_options(obj, "5%\n6%\n7%\n8%\n9%", LV_ROLLER_MODE_NORMAL);
            lv_roller_set_selected(obj, 1, LV_ANIM_OFF);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[0][4]), LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 5, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_SELECTED | LV_STATE_DEFAULT);
        }
        {
            // s1_3
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s1_3 = obj;
            lv_obj_set_pos(obj, 101, 148);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Range\nfor target\nweight.");
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            static lv_point_t line_points[] = {
                { 90, 0 },
                { 90, 170 }
            };
            lv_line_set_points(obj, line_points, 2);
            objects.obj12 = obj;
            lv_obj_set_pos(obj, 142, 148);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_line_color(obj, lv_color_hex(theme_colors[0][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_line_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_screen_s5_3() {
}

void create_screen_screen_s5_4() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_s5_4 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
}

void tick_screen_screen_s5_4() {
}

void create_screen_screen_s5_5() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_s5_5 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            static lv_point_t line_points[] = {
                { 0, 0 },
                { 350, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            objects.obj13 = obj;
            lv_obj_set_pos(obj, 84, 302);
            lv_obj_set_size(obj, 80, LV_SIZE_CONTENT);
            lv_obj_set_style_line_color(obj, lv_color_hex(theme_colors[0][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s5_5_roller_set
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.s5_5_roller_set = obj;
            lv_obj_set_pos(obj, 84, 172);
            lv_obj_set_size(obj, 80, 122);
            lv_roller_set_options(obj, "1\n2\n3", LV_ROLLER_MODE_NORMAL);
            lv_roller_set_selected(obj, 1, LV_ANIM_OFF);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[0][4]), LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 5, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_SELECTED | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            static lv_point_t line_points[] = {
                { 0, 0 },
                { 350, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            objects.obj14 = obj;
            lv_obj_set_pos(obj, 84, 164);
            lv_obj_set_size(obj, 80, LV_SIZE_CONTENT);
            lv_obj_set_style_line_color(obj, lv_color_hex(theme_colors[0][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s4_3
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s4_3 = obj;
            lv_obj_set_pos(obj, 106, 120);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "set");
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            static lv_point_t line_points[] = {
                { 0, 0 },
                { 350, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            objects.obj15 = obj;
            lv_obj_set_pos(obj, 212, 302);
            lv_obj_set_size(obj, 80, LV_SIZE_CONTENT);
            lv_obj_set_style_line_color(obj, lv_color_hex(theme_colors[0][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s5_5_roller_break
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.s5_5_roller_break = obj;
            lv_obj_set_pos(obj, 212, 172);
            lv_obj_set_size(obj, 80, 122);
            lv_roller_set_options(obj, "60\n61\n62", LV_ROLLER_MODE_NORMAL);
            lv_roller_set_selected(obj, 1, LV_ANIM_OFF);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[0][4]), LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 5, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_SELECTED | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            static lv_point_t line_points[] = {
                { 0, 0 },
                { 350, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            objects.obj16 = obj;
            lv_obj_set_pos(obj, 212, 164);
            lv_obj_set_size(obj, 80, LV_SIZE_CONTENT);
            lv_obj_set_style_line_color(obj, lv_color_hex(theme_colors[0][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s4_4
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s4_4 = obj;
            lv_obj_set_pos(obj, 199, 120);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "break (m)");
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            static lv_point_t line_points[] = {
                { 90, 0 },
                { 90, 350 }
            };
            lv_line_set_points(obj, line_points, 2);
            objects.obj17 = obj;
            lv_obj_set_pos(obj, 252, 58);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_line_color(obj, lv_color_hex(theme_colors[0][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s5_5_checkbox_active
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.s5_5_checkbox_active = obj;
            lv_obj_set_pos(obj, 218, 351);
            lv_obj_set_size(obj, 69, 68);
            lv_checkbox_set_text(obj, "");
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_ON_FOCUS|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_INDICATOR | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_INDICATOR | LV_STATE_CHECKED);
            lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                static lv_coord_t dsc[] = {LV_GRID_TEMPLATE_LAST};
                lv_obj_set_style_grid_row_dsc_array(obj, dsc, LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                static lv_coord_t dsc[] = {LV_GRID_TEMPLATE_LAST};
                lv_obj_set_style_grid_column_dsc_array(obj, dsc, LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s4_5
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s4_5 = obj;
            lv_obj_set_pos(obj, 135, 356);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "active");
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s5_5_flex_container1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.s5_5_flex_container1 = obj;
            lv_obj_set_pos(obj, 363, 0);
            lv_obj_set_size(obj, 94, 466);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
            lv_obj_set_scroll_snap_x(obj, LV_DIR_VER);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // s2_25
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_25 = obj;
                    lv_obj_set_pos(obj, 70, 155);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s1_hand_l_00001_small);
                }
                {
                    // s2_27
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_27 = obj;
                    lv_obj_set_pos(obj, -3, 184);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s1_hand_l_00010_small);
                }
                {
                    // s2_28
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_28 = obj;
                    lv_obj_set_pos(obj, 314, 134);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s1_hand_l_00100_small);
                }
                {
                    // s2_29
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_29 = obj;
                    lv_obj_set_pos(obj, 111, 144);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s1_hand_l_00110_small);
                }
                {
                    // s2_30
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_30 = obj;
                    lv_obj_set_pos(obj, 70, 133);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s1_hand_r_00100_small);
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 412, 212);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_arrow_left_1);
        }
    }
}

void tick_screen_screen_s5_5() {
}

void create_screen_screen_s6_1() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_s6_1 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // s6_1_flex_container1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.s6_1_flex_container1 = obj;
            lv_obj_set_pos(obj, 301, 0);
            lv_obj_set_size(obj, 94, 466);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
            lv_obj_set_scroll_snap_x(obj, LV_DIR_VER);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // s2_31
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_31 = obj;
                    lv_obj_set_pos(obj, 70, 155);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s6_1_sound);
                }
                {
                    // s2_32
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_32 = obj;
                    lv_obj_set_pos(obj, -3, 184);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s6_1_display);
                }
                {
                    // s2_33
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_33 = obj;
                    lv_obj_set_pos(obj, 111, 144);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s6_1_reset);
                }
                {
                    // s2_34
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_34 = obj;
                    lv_obj_set_pos(obj, 111, 144);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s6_1_info);
                }
                {
                    // s2_40
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_40 = obj;
                    lv_obj_set_pos(obj, -3, -85);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s6_1_weight);
                }
                {
                    // s2_41
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_41 = obj;
                    lv_obj_set_pos(obj, -118, -419);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s6_1_wifi);
                }
                {
                    // s2_42
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_42 = obj;
                    lv_obj_set_pos(obj, -118, -523);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s6_1_weight);
                }
            }
        }
        {
            // s6_1_label_focussed_text
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s6_1_label_focussed_text = obj;
            lv_obj_set_pos(obj, -26, 209);
            lv_obj_set_size(obj, 298, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Sound");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_40, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s6_1_focussed_ring
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.s6_1_focussed_ring = obj;
            lv_obj_set_pos(obj, 301, 186);
            lv_obj_set_size(obj, 94, 94);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_screen_s6_1() {
}

void create_screen_screen_s6_2() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_s6_2 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj18 = obj;
            lv_obj_set_pos(obj, 32, 215);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_arrow_simple_left_1);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_PRESSED);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj19 = obj;
            lv_obj_set_pos(obj, 410, 215);
            lv_obj_set_size(obj, 20, 37);
            lv_img_set_src(obj, &img_arrow_simple_right_1);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_PRESSED);
        }
        {
            // s6_2_roller_volume
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.s6_2_roller_volume = obj;
            lv_obj_set_pos(obj, 128, 259);
            lv_obj_set_size(obj, 90, 138);
            lv_roller_set_options(obj, "55%\n60%", LV_ROLLER_MODE_NORMAL);
            lv_roller_set_selected(obj, 1, LV_ANIM_OFF);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[0][4]), LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 5, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_SELECTED | LV_STATE_DEFAULT);
        }
        {
            // s6_2_label_text
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s6_2_label_text = obj;
            lv_obj_set_pos(obj, 105, 80);
            lv_obj_set_size(obj, 256, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Finishing Set");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s6_2_checkbox_active
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.s6_2_checkbox_active = obj;
            lv_obj_set_pos(obj, 189, 146);
            lv_obj_set_size(obj, 89, 55);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLL_MOMENTUM);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2f3237), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            static lv_point_t line_points[] = {
                { 0, 0 },
                { 350, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            objects.obj20 = obj;
            lv_obj_set_pos(obj, 147, 128);
            lv_obj_set_size(obj, 172, LV_SIZE_CONTENT);
            lv_obj_set_style_line_color(obj, lv_color_hex(theme_colors[0][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s6_2_roller_tone
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.s6_2_roller_tone = obj;
            lv_obj_set_pos(obj, 250, 259);
            lv_obj_set_size(obj, 90, 138);
            lv_roller_set_options(obj, "1\n2\n3", LV_ROLLER_MODE_NORMAL);
            lv_roller_set_selected(obj, 1, LV_ANIM_OFF);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[0][4]), LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 5, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_SELECTED | LV_STATE_DEFAULT);
        }
        {
            // s6_3
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s6_3 = obj;
            lv_obj_set_pos(obj, 74, 314);
            lv_obj_set_size(obj, 50, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "V");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s6_4
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s6_4 = obj;
            lv_obj_set_pos(obj, 342, 314);
            lv_obj_set_size(obj, 49, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "T");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s3_4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.s3_4 = obj;
            lv_obj_set_pos(obj, 152, 39);
            lv_obj_set_size(obj, 70, 90);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // s6_2_btn_right
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.s6_2_btn_right = obj;
            lv_obj_set_pos(obj, 361, 174);
            lv_obj_set_size(obj, 100, 120);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 150, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // s6_2_btn_left
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.s6_2_btn_left = obj;
            lv_obj_set_pos(obj, 5, 174);
            lv_obj_set_size(obj, 100, 120);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 150, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
}

void tick_screen_screen_s6_2() {
}

void create_screen_screen_s6_3() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_s6_3 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj21 = obj;
            lv_obj_set_pos(obj, 32, 215);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_arrow_simple_left_1);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_PRESSED);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj22 = obj;
            lv_obj_set_pos(obj, 410, 215);
            lv_obj_set_size(obj, 20, 37);
            lv_img_set_src(obj, &img_arrow_simple_right_1);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_PRESSED);
        }
        {
            // s6_3_roller_value
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.s6_3_roller_value = obj;
            lv_obj_set_pos(obj, 188, 234);
            lv_obj_set_size(obj, 90, 138);
            lv_roller_set_options(obj, "55%\n60%", LV_ROLLER_MODE_NORMAL);
            lv_roller_set_selected(obj, 1, LV_ANIM_OFF);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[0][4]), LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 5, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_SELECTED | LV_STATE_DEFAULT);
        }
        {
            // s6_3_label_text
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s6_3_label_text = obj;
            lv_obj_set_pos(obj, 105, 80);
            lv_obj_set_size(obj, 256, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "display brightness");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            static lv_point_t line_points[] = {
                { 0, 0 },
                { 350, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            objects.obj23 = obj;
            lv_obj_set_pos(obj, 147, 128);
            lv_obj_set_size(obj, 172, LV_SIZE_CONTENT);
            lv_obj_set_style_line_color(obj, lv_color_hex(theme_colors[0][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s3_5
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.s3_5 = obj;
            lv_obj_set_pos(obj, 152, 39);
            lv_obj_set_size(obj, 70, 90);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // s6_3_btn_right
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.s6_3_btn_right = obj;
            lv_obj_set_pos(obj, 361, 174);
            lv_obj_set_size(obj, 100, 120);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 150, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // s6_3_btn_left
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.s6_3_btn_left = obj;
            lv_obj_set_pos(obj, 2, 174);
            lv_obj_set_size(obj, 100, 120);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 150, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
}

void tick_screen_screen_s6_3() {
}

void create_screen_screen_s6_4() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_s6_4 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // s6_5
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s6_5 = obj;
            lv_obj_set_pos(obj, 21, 59);
            lv_obj_set_size(obj, 425, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Device: \nFingerNinja v1.0\nFirmware: \nv1.2.3\nLegal:\n(c) 2024 FLYNMNKY\nSystem Health:\nCPU Usage: 20%\nFree Memory: 32KB\nVisit:\nwww.fingerninja.com\n");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_screen_s6_4() {
}

void create_screen_screen_s6_5() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_s6_5 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // s6_5_btn_reset
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.s6_5_btn_reset = obj;
            lv_obj_set_pos(obj, 158, 265);
            lv_obj_set_size(obj, 150, 82);
            add_style_button_mid(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj24 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Reset");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // s6_6
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s6_6 = obj;
            lv_obj_set_pos(obj, 129, 112);
            lv_obj_set_size(obj, 209, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Reset device. \nWill delete user data and settings!");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_screen_s6_5() {
}

void create_screen_screen_s6_6() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_s6_6 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // s6_7
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s6_7 = obj;
            lv_obj_set_pos(obj, 129, 88);
            lv_obj_set_size(obj, 209, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Are you sure you want to delete all settings and data? (and reset them)?");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s6_6_btn_reset
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.s6_6_btn_reset = obj;
            lv_obj_set_pos(obj, 263, 270);
            lv_obj_set_size(obj, 150, 82);
            add_style_button_mid(obj);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj25 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Reset");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // s6_6_btn_cancel
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.s6_6_btn_cancel = obj;
            lv_obj_set_pos(obj, 71, 271);
            lv_obj_set_size(obj, 150, 82);
            add_style_button_mid(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj26 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Cancel");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
}

void tick_screen_screen_s6_6() {
}

void create_screen_screen_confirm() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_confirm = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // s6_10
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s6_10 = obj;
            lv_obj_set_pos(obj, 129, 88);
            lv_obj_set_size(obj, 209, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Do you want to save the new calibration value? (Old one is overwritten)");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s6_15
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.s6_15 = obj;
            lv_obj_set_pos(obj, 71, 271);
            lv_obj_set_size(obj, 150, 82);
            add_style_button_mid(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj27 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Cancel");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // s6_22
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.s6_22 = obj;
            lv_obj_set_pos(obj, 263, 270);
            lv_obj_set_size(obj, 150, 82);
            add_style_button_mid(obj);
            lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj28 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "SAVE");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
}

void tick_screen_screen_confirm() {
}

void create_screen_screen_s6_7() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_s6_7 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // s6_7_roller_kg
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.s6_7_roller_kg = obj;
            lv_obj_set_pos(obj, 133, 211);
            lv_obj_set_size(obj, 90, 138);
            lv_roller_set_options(obj, "10\n11\n12", LV_ROLLER_MODE_NORMAL);
            lv_roller_set_selected(obj, 1, LV_ANIM_OFF);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[0][4]), LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 5, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_SELECTED | LV_STATE_DEFAULT);
        }
        {
            // s6_16
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s6_16 = obj;
            lv_obj_set_pos(obj, 105, 68);
            lv_obj_set_size(obj, 256, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Body Weight");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            static lv_point_t line_points[] = {
                { 0, 0 },
                { 350, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            objects.obj29 = obj;
            lv_obj_set_pos(obj, 147, 116);
            lv_obj_set_size(obj, 172, LV_SIZE_CONTENT);
            lv_obj_set_style_line_color(obj, lv_color_hex(theme_colors[0][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s6_7_roller_g
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.s6_7_roller_g = obj;
            lv_obj_set_pos(obj, 242, 212);
            lv_obj_set_size(obj, 90, 138);
            lv_roller_set_options(obj, "1\n2", LV_ROLLER_MODE_NORMAL);
            lv_roller_set_selected(obj, 1, LV_ANIM_OFF);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[0][4]), LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 5, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_SELECTED | LV_STATE_DEFAULT);
        }
        {
            // s6_17
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s6_17 = obj;
            lv_obj_set_pos(obj, 212, 273);
            lv_obj_set_size(obj, 42, LV_SIZE_CONTENT);
            lv_label_set_text(obj, ".");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s6_24
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s6_24 = obj;
            lv_obj_set_pos(obj, 309, 267);
            lv_obj_set_size(obj, 107, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "kg");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s6_25
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s6_25 = obj;
            lv_obj_set_pos(obj, 106, 127);
            lv_obj_set_size(obj, 256, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Used for calculation of Critical Force (CF).");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_screen_s6_7() {
}

void create_screen_screen_s6_8() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_s6_8 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
}

void tick_screen_screen_s6_8() {
}

void create_screen_screen_s6_9() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_s6_9 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // s6_9_label_old
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s6_9_label_old = obj;
            lv_obj_set_pos(obj, 9, 191);
            lv_obj_set_size(obj, 256, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "3254.3");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_40, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s6_9_label_new
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s6_9_label_new = obj;
            lv_obj_set_pos(obj, 199, 191);
            lv_obj_set_size(obj, 256, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "3254.4");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_40, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s6_26
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s6_26 = obj;
            lv_obj_set_pos(obj, 105, 80);
            lv_obj_set_size(obj, 256, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Use a 10kg weight.");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff9c9c9c), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s6_27
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s6_27 = obj;
            lv_obj_set_pos(obj, 10, 161);
            lv_obj_set_size(obj, 256, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Old");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff9c9c9c), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s6_28
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s6_28 = obj;
            lv_obj_set_pos(obj, 200, 160);
            lv_obj_set_size(obj, 256, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "New");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff9c9c9c), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            static lv_point_t line_points[] = {
                { 0, 0 },
                { 350, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            objects.obj30 = obj;
            lv_obj_set_pos(obj, 73, 252);
            lv_obj_set_size(obj, 318, LV_SIZE_CONTENT);
            lv_obj_set_style_line_color(obj, lv_color_hex(theme_colors[0][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s6_9_img_tare
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.s6_9_img_tare = obj;
            lv_obj_set_pos(obj, 107, 277);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_s6_9_tare);
        }
        {
            // s6_9_img_start
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.s6_9_img_start = obj;
            lv_obj_set_pos(obj, 263, 277);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_s6_9_pause);
        }
    }
}

void tick_screen_screen_s6_9() {
}

void create_screen_screen_s7_1() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_s7_1 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // s7_1_label_focussed_text
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s7_1_label_focussed_text = obj;
            lv_obj_set_pos(obj, -26, 209);
            lv_obj_set_size(obj, 298, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Left Hand");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_40, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s7_1_flex_container1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.s7_1_flex_container1 = obj;
            lv_obj_set_pos(obj, 301, 0);
            lv_obj_set_size(obj, 94, 466);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
            lv_obj_set_scroll_snap_x(obj, LV_DIR_VER);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // s2_35
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_35 = obj;
                    lv_obj_set_pos(obj, 70, 155);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s7_1_left_hand);
                }
                {
                    // s2_36
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_36 = obj;
                    lv_obj_set_pos(obj, -3, 184);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s7_1_right_hand);
                }
                {
                    // s2_37
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_37 = obj;
                    lv_obj_set_pos(obj, 111, 144);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s7_1_question);
                }
                {
                    // s2_38
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_38 = obj;
                    lv_obj_set_pos(obj, 111, 144);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s7_1_right_chart);
                }
                {
                    // s2_39
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.s2_39 = obj;
                    lv_obj_set_pos(obj, -3, -85);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_s7_1_left_chart);
                }
            }
        }
        {
            // s7_1_focussed_ring
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.s7_1_focussed_ring = obj;
            lv_obj_set_pos(obj, 301, 186);
            lv_obj_set_size(obj, 94, 94);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_screen_s7_1() {
}

void create_screen_screen_s7_2() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_s7_2 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // s6_8
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s6_8 = obj;
            lv_obj_set_pos(obj, 68, 87);
            lv_obj_set_size(obj, 330, 292);
            lv_label_set_text(obj, "Critical Force (CF) represents the maximum sustainable force a climber can maintain over time, serving as a key benchmark for finger strength endurance.\n\nBefore starting, ensure you warm up thoroughly to prevent injuries and optimize performance:\n\n1. Perform light hand and finger stretches for 2 to 3 minutes to improve mobility and circulation.\n2. Use the device or a similar resistance tool to perform gentle pulls at 50% effort for 1 to  2 minutes to activate your fingers.\n3. Perform 2 to 3 short pulls at 70 to 80% of your max strength to prepare your fingers for maximal effort.\n\nOnce warmed up, follow the on screen prompts to perform maximum effort pulls. The device will measure your max strength and calculate your critical force (CF) based on your performance. Rest between attempts as guided by the device.");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_ON);
            lv_obj_set_scroll_snap_x(obj, LV_DIR_VER);
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_screen_s7_2() {
}

void create_screen_screen_s7_3() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_s7_3 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // s7_3_arc1
            lv_obj_t *obj = lv_arc_create(parent_obj);
            objects.s7_3_arc1 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 466, 466);
            lv_arc_set_value(obj, 80);
            lv_arc_set_bg_start_angle(obj, 270);
            lv_arc_set_bg_end_angle(obj, 629);
            lv_obj_set_style_arc_rounded(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_hex(theme_colors[0][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_width(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, -5, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, -5, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, -5, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, -5, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_width(obj, 20, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
        {
            // s7_3_label_seconds
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s7_3_label_seconds = obj;
            lv_obj_set_pos(obj, 202, 30);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "10s");
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_40, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            static lv_point_t line_points[] = {
                { 0, 0 },
                { 350, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            objects.obj31 = obj;
            lv_obj_set_pos(obj, 73, 232);
            lv_obj_set_size(obj, 320, LV_SIZE_CONTENT);
            lv_obj_set_style_line_color(obj, lv_color_hex(theme_colors[0][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s7_3_label_instruction
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s7_3_label_instruction = obj;
            lv_obj_set_pos(obj, 89, 123);
            lv_obj_set_size(obj, 289, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Prepare");
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_75, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s7_3_img_combo
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.s7_3_img_combo = obj;
            lv_obj_set_pos(obj, 134, 275);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_s1_hand_l_00100);
            lv_obj_set_style_img_opa(obj, 60, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s4_2_label_kg_new_4
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s4_2_label_kg_new_4 = obj;
            lv_obj_set_pos(obj, 253, 251);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Round");
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s7_3_label_round
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s7_3_label_round = obj;
            lv_obj_set_pos(obj, 253, 278);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "5/10");
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_40, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s4_2_label_kg_new_6
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s4_2_label_kg_new_6 = obj;
            lv_obj_set_pos(obj, 254, 328);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "kg");
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s7_3_label_kg
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s7_3_label_kg = obj;
            lv_obj_set_pos(obj, 254, 356);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "28.8");
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_40, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_screen_s7_3() {
}

void create_screen_screen_s7_4() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_s7_4 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // s7_4_chart
            lv_obj_t *obj = lv_chart_create(parent_obj);
            objects.s7_4_chart = obj;
            lv_obj_set_pos(obj, 48, 102);
            lv_obj_set_size(obj, 370, 262);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s7_4_label_cf
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s7_4_label_cf = obj;
            lv_obj_set_pos(obj, 105, 45);
            lv_obj_set_size(obj, 256, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "cf after measure");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_screen_s7_4() {
}

void create_screen_screen_s7_5() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_s7_5 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // s7_5_timestamp
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s7_5_timestamp = obj;
            lv_obj_set_pos(obj, 105, 70);
            lv_obj_set_size(obj, 256, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "12/12/24");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            static lv_point_t line_points[] = {
                { 0, 0 },
                { 350, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            objects.obj32 = obj;
            lv_obj_set_pos(obj, 147, 123);
            lv_obj_set_size(obj, 172, LV_SIZE_CONTENT);
            lv_obj_set_style_line_color(obj, lv_color_hex(theme_colors[0][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s6_11
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s6_11 = obj;
            lv_obj_set_pos(obj, 51, 165);
            lv_obj_set_size(obj, 194, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "CF (% Body)");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff363636), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s7_5_btn_prev
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.s7_5_btn_prev = obj;
            lv_obj_set_pos(obj, 5, 174);
            lv_obj_set_size(obj, 100, 120);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 150, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // s6_14
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.s6_14 = obj;
            lv_obj_set_pos(obj, 361, 174);
            lv_obj_set_size(obj, 100, 120);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 150, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // s7_5_btn_next
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.s7_5_btn_next = obj;
            lv_obj_set_pos(obj, 362, 170);
            lv_obj_set_size(obj, 100, 120);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 150, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // s7_5_img_prev
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.s7_5_img_prev = obj;
            lv_obj_set_pos(obj, 32, 215);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_arrow_simple_left_1);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_PRESSED);
        }
        {
            // s7_5_img_next
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.s7_5_img_next = obj;
            lv_obj_set_pos(obj, 410, 206);
            lv_obj_set_size(obj, 20, 37);
            lv_img_set_src(obj, &img_arrow_simple_right_1);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_PRESSED);
        }
        {
            // s6_18
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s6_18 = obj;
            lv_obj_set_pos(obj, 236, 165);
            lv_obj_set_size(obj, 184, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "CF (kg)");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff363636), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s7_5_label_cf_kg
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s7_5_label_cf_kg = obj;
            lv_obj_set_pos(obj, 252, 197);
            lv_obj_set_size(obj, 152, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "40%");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s7_5_label_cf_body
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s7_5_label_cf_body = obj;
            lv_obj_set_pos(obj, 72, 200);
            lv_obj_set_size(obj, 152, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "40%");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s6_12
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s6_12 = obj;
            lv_obj_set_pos(obj, 51, 262);
            lv_obj_set_size(obj, 194, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "To First");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff363636), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s6_20
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s6_20 = obj;
            lv_obj_set_pos(obj, 237, 262);
            lv_obj_set_size(obj, 184, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "To Previous");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff363636), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s7_5_label_per_to_prev
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s7_5_label_per_to_prev = obj;
            lv_obj_set_pos(obj, 253, 294);
            lv_obj_set_size(obj, 152, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "+1.1%");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s7_5_label_per_to_first
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s7_5_label_per_to_first = obj;
            lv_obj_set_pos(obj, 73, 297);
            lv_obj_set_size(obj, 152, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "+3.1%");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s1_2_btn_delete
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.s1_2_btn_delete = obj;
            lv_obj_set_pos(obj, 198, 367);
            lv_obj_set_size(obj, 70, 70);
            add_style_button_mid(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 220, 389);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_cross_x);
        }
    }
}

void tick_screen_screen_s7_5() {
}

void create_screen_screen_s7_6() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_s7_6 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // s7_6_chart
            lv_obj_t *obj = lv_chart_create(parent_obj);
            objects.s7_6_chart = obj;
            lv_obj_set_pos(obj, 48, 102);
            lv_obj_set_size(obj, 370, 262);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s7_6_label_cf
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s7_6_label_cf = obj;
            lv_obj_set_pos(obj, 105, 45);
            lv_obj_set_size(obj, 256, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "cf in overview");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_screen_s7_6() {
}

void create_screen_screen_s7_7() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_s7_7 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 466, 466);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // s6_9
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.s6_9 = obj;
            lv_obj_set_pos(obj, 129, 88);
            lv_obj_set_size(obj, 209, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Are you sure you want to delete this entry?");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_main_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s7_7_btn_cancel
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.s7_7_btn_cancel = obj;
            lv_obj_set_pos(obj, 71, 271);
            lv_obj_set_size(obj, 150, 82);
            add_style_button_mid(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[0][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj33 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Cancel");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // s7_7_btn_delete
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.s7_7_btn_delete = obj;
            lv_obj_set_pos(obj, 263, 270);
            lv_obj_set_size(obj, 150, 82);
            add_style_button_mid(obj);
            lv_obj_set_style_text_font(obj, &ui_font_main_medium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj34 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Delete");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_main_semi_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
}

void tick_screen_screen_s7_7() {
}

void change_color_theme(uint32_t theme_index) {
    lv_style_set_bg_color(get_style_button_mid_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][2]));
    
    lv_obj_set_style_arc_color(objects.ui_s1_arc_1, lv_color_hex(theme_colors[theme_index][3]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    
    lv_obj_set_style_arc_color(objects.obj0, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_arc_color(objects.obj1, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.ui_label_rpm, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s1_2_btn_finish_set, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s1_2_btn_go_to_s2_1, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s1_2_bar_progress_of_sets, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s1_2_bar_progress_of_sets, lv_color_hex(theme_colors[theme_index][3]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s1_2_bar_progress_of_session, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s1_2_bar_progress_of_session, lv_color_hex(theme_colors[theme_index][3]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    
    lv_obj_set_style_line_color(objects.obj2, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.s1_4, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.s1_5, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.s1_6, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s1_3_btn_go_to_s2_1, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_line_color(objects.obj3, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s1_3_bar_progress_of_session, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s1_3_bar_progress_of_session, lv_color_hex(theme_colors[theme_index][3]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s1_3_btn_train_now, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s2_1_focussed_ring, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.s2_1_focussed_ring, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s3_1_focussed_ring, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.s3_1_focussed_ring, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_line_color(objects.screen_s3_2, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.s3_2_roller_per_of_max, lv_color_hex(theme_colors[theme_index][4]), LV_PART_SELECTED | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.s3_2_roller_train, lv_color_hex(theme_colors[theme_index][3]), LV_PART_SELECTED | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.s3_2_roller_pause, lv_color_hex(theme_colors[theme_index][3]), LV_PART_SELECTED | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s3_2_checkbox_active, lv_color_hex(theme_colors[theme_index][1]), LV_PART_INDICATOR | LV_STATE_CHECKED);
    
    lv_obj_set_style_border_color(objects.s3_2_roller_grip_type, lv_color_hex(theme_colors[theme_index][0]), LV_PART_SELECTED | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.s3_2_roller_grip_edge, lv_color_hex(theme_colors[theme_index][3]), LV_PART_SELECTED | LV_STATE_DEFAULT);
    
    lv_obj_set_style_line_color(objects.obj4, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s4_1_btn_measure, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s4_1_btn_grip_type, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s4_1_btn_chart, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_line_color(objects.obj7, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.s4_1_label_kg_1, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.s4_1_label_kg_2, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s4_1_btn_left_or_right, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.s4_1_btn_left_or_right, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_arc_color(objects.s4_2_arc1, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s4_2_arc1, lv_color_hex(theme_colors[theme_index][1]), LV_PART_KNOB | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s4_2_arc1, lv_color_hex(theme_colors[theme_index][1]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    
    lv_obj_set_style_arc_color(objects.s4_2_arc1, lv_color_hex(theme_colors[theme_index][1]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.s4_2_label_kg_new_1_a, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_line_color(objects.obj9, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.s4_2_label_kg, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.s4_2_label_per_new, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.s4_2_label_kg_new_1_b, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.s4_2_label_kg_new_2_a, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.s4_2_label_kg_new_2_b, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.s4_2_label_kg_old_1_a, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.s4_2_label_kg_old_1_b, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.s4_2_label_kg_old_2_a, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.s4_2_label_kg_old_2_b, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.s4_2_label_grip_type, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_line_color(objects.obj11, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.s4_4_label_per_to_first, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.s4_4_label_per_to_prev, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s4_4_img_prev, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_PRESSED);
    
    lv_obj_set_style_bg_color(objects.s4_4_img_next, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_PRESSED);
    
    lv_obj_set_style_bg_color(objects.s4_4_btn_delete, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s5_1_focussed_ring, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.s5_1_focussed_ring, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s5_2_focussed_ring, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.s5_2_focussed_ring, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.s5_2_label_session_name, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.s5_3_roller_range, lv_color_hex(theme_colors[theme_index][4]), LV_PART_SELECTED | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.s1_3, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_line_color(objects.obj12, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_line_color(objects.obj13, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.s5_5_roller_set, lv_color_hex(theme_colors[theme_index][4]), LV_PART_SELECTED | LV_STATE_DEFAULT);
    
    lv_obj_set_style_line_color(objects.obj14, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.s4_3, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_line_color(objects.obj15, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.s5_5_roller_break, lv_color_hex(theme_colors[theme_index][4]), LV_PART_SELECTED | LV_STATE_DEFAULT);
    
    lv_obj_set_style_line_color(objects.obj16, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.s4_4, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_line_color(objects.obj17, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s5_5_checkbox_active, lv_color_hex(theme_colors[theme_index][1]), LV_PART_INDICATOR | LV_STATE_CHECKED);
    
    lv_obj_set_style_text_color(objects.s4_5, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s6_1_focussed_ring, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.s6_1_focussed_ring, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.obj18, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_PRESSED);
    
    lv_obj_set_style_bg_color(objects.obj19, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_PRESSED);
    
    lv_obj_set_style_border_color(objects.s6_2_roller_volume, lv_color_hex(theme_colors[theme_index][4]), LV_PART_SELECTED | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s6_2_checkbox_active, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
    
    lv_obj_set_style_line_color(objects.obj20, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.s6_2_roller_tone, lv_color_hex(theme_colors[theme_index][4]), LV_PART_SELECTED | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.s6_3, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.s6_4, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.obj21, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_PRESSED);
    
    lv_obj_set_style_bg_color(objects.obj22, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_PRESSED);
    
    lv_obj_set_style_border_color(objects.s6_3_roller_value, lv_color_hex(theme_colors[theme_index][4]), LV_PART_SELECTED | LV_STATE_DEFAULT);
    
    lv_obj_set_style_line_color(objects.obj23, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s6_5_btn_reset, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s6_6_btn_cancel, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s6_15, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s6_22, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.s6_7_roller_kg, lv_color_hex(theme_colors[theme_index][4]), LV_PART_SELECTED | LV_STATE_DEFAULT);
    
    lv_obj_set_style_line_color(objects.obj29, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.s6_7_roller_g, lv_color_hex(theme_colors[theme_index][4]), LV_PART_SELECTED | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.s6_25, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_line_color(objects.obj30, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s7_1_focussed_ring, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.s7_1_focussed_ring, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_arc_color(objects.s7_3_arc1, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s7_3_arc1, lv_color_hex(theme_colors[theme_index][1]), LV_PART_KNOB | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s7_3_arc1, lv_color_hex(theme_colors[theme_index][1]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    
    lv_obj_set_style_arc_color(objects.s7_3_arc1, lv_color_hex(theme_colors[theme_index][1]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.s7_3_label_seconds, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_line_color(objects.obj31, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.s7_3_label_instruction, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.s4_2_label_kg_new_4, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.s4_2_label_kg_new_6, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_line_color(objects.obj32, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s7_5_img_prev, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_PRESSED);
    
    lv_obj_set_style_bg_color(objects.s7_5_img_next, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_PRESSED);
    
    lv_obj_set_style_text_color(objects.s7_5_label_per_to_prev, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.s7_5_label_per_to_first, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s1_2_btn_delete, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(objects.s7_7_btn_cancel, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_invalidate(objects.main);
    lv_obj_invalidate(objects.screen_s1_2);
    lv_obj_invalidate(objects.screen_s1_3);
    lv_obj_invalidate(objects.screen_s2_1);
    lv_obj_invalidate(objects.screen_s3_1);
    lv_obj_invalidate(objects.screen_s3_2);
    lv_obj_invalidate(objects.screen_s4_1);
    lv_obj_invalidate(objects.screen_s4_2);
    lv_obj_invalidate(objects.screen_s4_3);
    lv_obj_invalidate(objects.screen_s4_4);
    lv_obj_invalidate(objects.screen_s5_1);
    lv_obj_invalidate(objects.screen_s5_2);
    lv_obj_invalidate(objects.screen_s5_3);
    lv_obj_invalidate(objects.screen_s5_4);
    lv_obj_invalidate(objects.screen_s5_5);
    lv_obj_invalidate(objects.screen_s6_1);
    lv_obj_invalidate(objects.screen_s6_2);
    lv_obj_invalidate(objects.screen_s6_3);
    lv_obj_invalidate(objects.screen_s6_4);
    lv_obj_invalidate(objects.screen_s6_5);
    lv_obj_invalidate(objects.screen_s6_6);
    lv_obj_invalidate(objects.screen_confirm);
    lv_obj_invalidate(objects.screen_s6_7);
    lv_obj_invalidate(objects.screen_s6_8);
    lv_obj_invalidate(objects.screen_s6_9);
    lv_obj_invalidate(objects.screen_s7_1);
    lv_obj_invalidate(objects.screen_s7_2);
    lv_obj_invalidate(objects.screen_s7_3);
    lv_obj_invalidate(objects.screen_s7_4);
    lv_obj_invalidate(objects.screen_s7_5);
    lv_obj_invalidate(objects.screen_s7_6);
    lv_obj_invalidate(objects.screen_s7_7);
}

uint32_t theme_colors[2][6] = {
    { 0xff804fc6, 0xff39f99f, 0xff262626, 0xfff7bf00, 0xff808080, 0xff4d4d4d },
    { 0xff804fc6, 0xff39f99f, 0xff000000, 0xff000000, 0xff000000, 0xff000000 },
};

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_screen_s1_2();
    create_screen_screen_s1_3();
    create_screen_screen_s2_1();
    create_screen_screen_s3_1();
    create_screen_screen_s3_2();
    create_screen_screen_s4_1();
    create_screen_screen_s4_2();
    create_screen_screen_s4_3();
    create_screen_screen_s4_4();
    create_screen_screen_s5_1();
    create_screen_screen_s5_2();
    create_screen_screen_s5_3();
    create_screen_screen_s5_4();
    create_screen_screen_s5_5();
    create_screen_screen_s6_1();
    create_screen_screen_s6_2();
    create_screen_screen_s6_3();
    create_screen_screen_s6_4();
    create_screen_screen_s6_5();
    create_screen_screen_s6_6();
    create_screen_screen_confirm();
    create_screen_screen_s6_7();
    create_screen_screen_s6_8();
    create_screen_screen_s6_9();
    create_screen_screen_s7_1();
    create_screen_screen_s7_2();
    create_screen_screen_s7_3();
    create_screen_screen_s7_4();
    create_screen_screen_s7_5();
    create_screen_screen_s7_6();
    create_screen_screen_s7_7();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_screen_s1_2,
    tick_screen_screen_s1_3,
    tick_screen_screen_s2_1,
    tick_screen_screen_s3_1,
    tick_screen_screen_s3_2,
    tick_screen_screen_s4_1,
    tick_screen_screen_s4_2,
    tick_screen_screen_s4_3,
    tick_screen_screen_s4_4,
    tick_screen_screen_s5_1,
    tick_screen_screen_s5_2,
    tick_screen_screen_s5_3,
    tick_screen_screen_s5_4,
    tick_screen_screen_s5_5,
    tick_screen_screen_s6_1,
    tick_screen_screen_s6_2,
    tick_screen_screen_s6_3,
    tick_screen_screen_s6_4,
    tick_screen_screen_s6_5,
    tick_screen_screen_s6_6,
    tick_screen_screen_confirm,
    tick_screen_screen_s6_7,
    tick_screen_screen_s6_8,
    tick_screen_screen_s6_9,
    tick_screen_screen_s7_1,
    tick_screen_screen_s7_2,
    tick_screen_screen_s7_3,
    tick_screen_screen_s7_4,
    tick_screen_screen_s7_5,
    tick_screen_screen_s7_6,
    tick_screen_screen_s7_7,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
