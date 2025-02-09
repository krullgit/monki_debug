#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *screen_s1_2;
    lv_obj_t *screen_s1_3;
    lv_obj_t *screen_s2_1;
    lv_obj_t *screen_s3_1;
    lv_obj_t *screen_s3_2;
    lv_obj_t *screen_s4_1;
    lv_obj_t *screen_s4_2;
    lv_obj_t *screen_s4_3;
    lv_obj_t *screen_s4_4;
    lv_obj_t *screen_s5_1;
    lv_obj_t *screen_s5_2;
    lv_obj_t *screen_s5_3;
    lv_obj_t *screen_s5_4;
    lv_obj_t *screen_s5_5;
    lv_obj_t *screen_s6_1;
    lv_obj_t *screen_s6_2;
    lv_obj_t *screen_s6_3;
    lv_obj_t *screen_s6_4;
    lv_obj_t *screen_s6_5;
    lv_obj_t *screen_s6_6;
    lv_obj_t *screen_confirm;
    lv_obj_t *screen_s6_7;
    lv_obj_t *screen_s6_8;
    lv_obj_t *screen_s6_9;
    lv_obj_t *screen_s7_1;
    lv_obj_t *screen_s7_2;
    lv_obj_t *screen_s7_3;
    lv_obj_t *screen_s7_4;
    lv_obj_t *screen_s7_5;
    lv_obj_t *screen_s7_6;
    lv_obj_t *screen_s7_7;
    lv_obj_t *ui_s1_arc_1;
    lv_obj_t *s1_label_percentage_of_max;
    lv_obj_t *s1_label_grip_type;
    lv_obj_t *obj0;
    lv_obj_t *obj1;
    lv_obj_t *ui_label_rpm;
    lv_obj_t *ui_label_rpm2;
    lv_obj_t *s1_label_time_remaining;
    lv_obj_t *s1_label_percentage_max;
    lv_obj_t *s1_label_percentage_min;
    lv_obj_t *s1_label_percentage_target;
    lv_obj_t *ui_s1_arc_needle;
    lv_obj_t *ui_s1_flex_container2;
    lv_obj_t *s1_2_btn_finish_set;
    lv_obj_t *s1_2_btn_go_to_s2_1;
    lv_obj_t *s1_2_bar_progress_of_sets;
    lv_obj_t *s1_2_label_progress_of_sets;
    lv_obj_t *s1_2_bar_progress_of_session;
    lv_obj_t *s1_2_label_progress_of_session;
    lv_obj_t *obj2;
    lv_obj_t *s1_4;
    lv_obj_t *s1_5;
    lv_obj_t *s1_6;
    lv_obj_t *s1_3_label_progress_of_session;
    lv_obj_t *s1_3_btn_go_to_s2_1;
    lv_obj_t *obj3;
    lv_obj_t *s1_3_bar_progress_of_session;
    lv_obj_t *s1_3_btn_train_now;
    lv_obj_t *s1_3_label_pause_time_left;
    lv_obj_t *s2_1_flex_container1;
    lv_obj_t *s2_1_cf;
    lv_obj_t *s2_1_max;
    lv_obj_t *s2_1_sets;
    lv_obj_t *s2_1_settings;
    lv_obj_t *s2_1_train;
    lv_obj_t *s2_1_focussed_ring;
    lv_obj_t *s2_1_label_focussed_text;
    lv_obj_t *s3_1_flex_container1;
    lv_obj_t *s2_3;
    lv_obj_t *s2_4;
    lv_obj_t *s2_5;
    lv_obj_t *s2_6;
    lv_obj_t *s2_7;
    lv_obj_t *s3_1_focussed_ring;
    lv_obj_t *s3_1_label_focussed_text;
    lv_obj_t *s3_1_img_edit;
    lv_obj_t *s3_1_btn_rename;
    lv_obj_t *s3_2_roller_per_of_max;
    lv_obj_t *s3_2_roller_train;
    lv_obj_t *s3_2_roller_pause;
    lv_obj_t *s3_2_checkbox_active;
    lv_obj_t *s3_2_roller_grip_type;
    lv_obj_t *s3_2_flex_container1;
    lv_obj_t *s2_8;
    lv_obj_t *s2_9;
    lv_obj_t *s2_10;
    lv_obj_t *s2_11;
    lv_obj_t *s2_12;
    lv_obj_t *s3_2_roller_grip_edge;
    lv_obj_t *s3_2_btn_right;
    lv_obj_t *s3_2_btn_left;
    lv_obj_t *obj4;
    lv_obj_t *s4_1_btn_measure;
    lv_obj_t *obj5;
    lv_obj_t *s4_1_btn_grip_type;
    lv_obj_t *obj6;
    lv_obj_t *s4_1_btn_chart;
    lv_obj_t *obj7;
    lv_obj_t *s4_1_flex_container1;
    lv_obj_t *s2_13;
    lv_obj_t *s2_14;
    lv_obj_t *s2_15;
    lv_obj_t *s2_16;
    lv_obj_t *s2_17;
    lv_obj_t *s4_1_label_kg_1;
    lv_obj_t *s4_1_label_kg_2;
    lv_obj_t *s4_1_btn_left_or_right;
    lv_obj_t *obj8;
    lv_obj_t *s4_2_arc1;
    lv_obj_t *s4_2_label_kg_new_1_a;
    lv_obj_t *obj9;
    lv_obj_t *s4_2_label_kg;
    lv_obj_t *obj10;
    lv_obj_t *s4_2_label_per_new;
    lv_obj_t *s4_2_img_combo;
    lv_obj_t *s4_2_label_kg_new_1_b;
    lv_obj_t *s4_2_label_kg_new_2_a;
    lv_obj_t *s4_2_label_kg_new_2_b;
    lv_obj_t *s4_2_label_kg_old_1_a;
    lv_obj_t *s4_2_label_kg_old_1_b;
    lv_obj_t *s4_2_label_kg_old_2_a;
    lv_obj_t *s4_2_label_kg_old_2_b;
    lv_obj_t *s4_2_label_grip_type;
    lv_obj_t *s4_3_label_cf;
    lv_obj_t *s4_3_chart;
    lv_obj_t *s4_4_timestamp;
    lv_obj_t *obj11;
    lv_obj_t *s6_19;
    lv_obj_t *s4_4_label_kg;
    lv_obj_t *s6_13;
    lv_obj_t *s4_4_label_per_to_first;
    lv_obj_t *s6_21;
    lv_obj_t *s4_4_label_per_to_prev;
    lv_obj_t *s4_4_img_prev;
    lv_obj_t *s4_4_img_next;
    lv_obj_t *s4_4_btn_prev;
    lv_obj_t *s4_4_btn_next;
    lv_obj_t *s4_4_btn_delete;
    lv_obj_t *s5_1_label_focussed_text;
    lv_obj_t *s5_1_flex_container1;
    lv_obj_t *s2_18;
    lv_obj_t *s2_19;
    lv_obj_t *s2_20;
    lv_obj_t *s2_21;
    lv_obj_t *s2_22;
    lv_obj_t *s5_1_focussed_ring;
    lv_obj_t *s5_1_btn_rename;
    lv_obj_t *s5_1_img_edit;
    lv_obj_t *s5_2_flex_container1;
    lv_obj_t *s2_23;
    lv_obj_t *s2_24;
    lv_obj_t *s2_26;
    lv_obj_t *s5_2_focussed_ring;
    lv_obj_t *s5_2_label_focussed_text;
    lv_obj_t *s5_2_label_session_name;
    lv_obj_t *s5_3_roller_range;
    lv_obj_t *s1_3;
    lv_obj_t *obj12;
    lv_obj_t *obj13;
    lv_obj_t *s5_5_roller_set;
    lv_obj_t *obj14;
    lv_obj_t *s4_3;
    lv_obj_t *obj15;
    lv_obj_t *s5_5_roller_break;
    lv_obj_t *obj16;
    lv_obj_t *s4_4;
    lv_obj_t *obj17;
    lv_obj_t *s5_5_checkbox_active;
    lv_obj_t *s4_5;
    lv_obj_t *s5_5_flex_container1;
    lv_obj_t *s2_25;
    lv_obj_t *s2_27;
    lv_obj_t *s2_28;
    lv_obj_t *s2_29;
    lv_obj_t *s2_30;
    lv_obj_t *s6_1_flex_container1;
    lv_obj_t *s2_31;
    lv_obj_t *s2_32;
    lv_obj_t *s2_33;
    lv_obj_t *s2_34;
    lv_obj_t *s2_40;
    lv_obj_t *s2_41;
    lv_obj_t *s2_42;
    lv_obj_t *s6_1_label_focussed_text;
    lv_obj_t *s6_1_focussed_ring;
    lv_obj_t *obj18;
    lv_obj_t *obj19;
    lv_obj_t *s6_2_roller_volume;
    lv_obj_t *s6_2_label_text;
    lv_obj_t *s6_2_checkbox_active;
    lv_obj_t *obj20;
    lv_obj_t *s6_2_roller_tone;
    lv_obj_t *s6_3;
    lv_obj_t *s6_4;
    lv_obj_t *s3_4;
    lv_obj_t *s6_2_btn_right;
    lv_obj_t *s6_2_btn_left;
    lv_obj_t *obj21;
    lv_obj_t *obj22;
    lv_obj_t *s6_3_roller_value;
    lv_obj_t *s6_3_label_text;
    lv_obj_t *obj23;
    lv_obj_t *s3_5;
    lv_obj_t *s6_3_btn_right;
    lv_obj_t *s6_3_btn_left;
    lv_obj_t *s6_5;
    lv_obj_t *s6_5_btn_reset;
    lv_obj_t *obj24;
    lv_obj_t *s6_6;
    lv_obj_t *s6_7;
    lv_obj_t *s6_6_btn_reset;
    lv_obj_t *obj25;
    lv_obj_t *s6_6_btn_cancel;
    lv_obj_t *obj26;
    lv_obj_t *s6_10;
    lv_obj_t *s6_15;
    lv_obj_t *obj27;
    lv_obj_t *s6_22;
    lv_obj_t *obj28;
    lv_obj_t *s6_7_roller_kg;
    lv_obj_t *s6_16;
    lv_obj_t *obj29;
    lv_obj_t *s6_7_roller_g;
    lv_obj_t *s6_17;
    lv_obj_t *s6_24;
    lv_obj_t *s6_25;
    lv_obj_t *s6_9_label_old;
    lv_obj_t *s6_9_label_new;
    lv_obj_t *s6_26;
    lv_obj_t *s6_27;
    lv_obj_t *s6_28;
    lv_obj_t *obj30;
    lv_obj_t *s6_9_img_tare;
    lv_obj_t *s6_9_img_start;
    lv_obj_t *s7_1_label_focussed_text;
    lv_obj_t *s7_1_flex_container1;
    lv_obj_t *s2_35;
    lv_obj_t *s2_36;
    lv_obj_t *s2_37;
    lv_obj_t *s2_38;
    lv_obj_t *s2_39;
    lv_obj_t *s7_1_focussed_ring;
    lv_obj_t *s6_8;
    lv_obj_t *s7_3_arc1;
    lv_obj_t *s7_3_label_seconds;
    lv_obj_t *obj31;
    lv_obj_t *s7_3_label_instruction;
    lv_obj_t *s7_3_img_combo;
    lv_obj_t *s4_2_label_kg_new_4;
    lv_obj_t *s7_3_label_round;
    lv_obj_t *s4_2_label_kg_new_6;
    lv_obj_t *s7_3_label_kg;
    lv_obj_t *s7_4_chart;
    lv_obj_t *s7_4_label_cf;
    lv_obj_t *s7_5_timestamp;
    lv_obj_t *obj32;
    lv_obj_t *s6_11;
    lv_obj_t *s7_5_btn_prev;
    lv_obj_t *s6_14;
    lv_obj_t *s7_5_btn_next;
    lv_obj_t *s7_5_img_prev;
    lv_obj_t *s7_5_img_next;
    lv_obj_t *s6_18;
    lv_obj_t *s7_5_label_cf_kg;
    lv_obj_t *s7_5_label_cf_body;
    lv_obj_t *s6_12;
    lv_obj_t *s6_20;
    lv_obj_t *s7_5_label_per_to_prev;
    lv_obj_t *s7_5_label_per_to_first;
    lv_obj_t *s1_2_btn_delete;
    lv_obj_t *s7_6_chart;
    lv_obj_t *s7_6_label_cf;
    lv_obj_t *s6_9;
    lv_obj_t *s7_7_btn_cancel;
    lv_obj_t *obj33;
    lv_obj_t *s7_7_btn_delete;
    lv_obj_t *obj34;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_SCREEN_S1_2 = 2,
    SCREEN_ID_SCREEN_S1_3 = 3,
    SCREEN_ID_SCREEN_S2_1 = 4,
    SCREEN_ID_SCREEN_S3_1 = 5,
    SCREEN_ID_SCREEN_S3_2 = 6,
    SCREEN_ID_SCREEN_S4_1 = 7,
    SCREEN_ID_SCREEN_S4_2 = 8,
    SCREEN_ID_SCREEN_S4_3 = 9,
    SCREEN_ID_SCREEN_S4_4 = 10,
    SCREEN_ID_SCREEN_S5_1 = 11,
    SCREEN_ID_SCREEN_S5_2 = 12,
    SCREEN_ID_SCREEN_S5_3 = 13,
    SCREEN_ID_SCREEN_S5_4 = 14,
    SCREEN_ID_SCREEN_S5_5 = 15,
    SCREEN_ID_SCREEN_S6_1 = 16,
    SCREEN_ID_SCREEN_S6_2 = 17,
    SCREEN_ID_SCREEN_S6_3 = 18,
    SCREEN_ID_SCREEN_S6_4 = 19,
    SCREEN_ID_SCREEN_S6_5 = 20,
    SCREEN_ID_SCREEN_S6_6 = 21,
    SCREEN_ID_SCREEN_CONFIRM = 22,
    SCREEN_ID_SCREEN_S6_7 = 23,
    SCREEN_ID_SCREEN_S6_8 = 24,
    SCREEN_ID_SCREEN_S6_9 = 25,
    SCREEN_ID_SCREEN_S7_1 = 26,
    SCREEN_ID_SCREEN_S7_2 = 27,
    SCREEN_ID_SCREEN_S7_3 = 28,
    SCREEN_ID_SCREEN_S7_4 = 29,
    SCREEN_ID_SCREEN_S7_5 = 30,
    SCREEN_ID_SCREEN_S7_6 = 31,
    SCREEN_ID_SCREEN_S7_7 = 32,
};

void create_screen_main();
void tick_screen_main();

void create_screen_screen_s1_2();
void tick_screen_screen_s1_2();

void create_screen_screen_s1_3();
void tick_screen_screen_s1_3();

void create_screen_screen_s2_1();
void tick_screen_screen_s2_1();

void create_screen_screen_s3_1();
void tick_screen_screen_s3_1();

void create_screen_screen_s3_2();
void tick_screen_screen_s3_2();

void create_screen_screen_s4_1();
void tick_screen_screen_s4_1();

void create_screen_screen_s4_2();
void tick_screen_screen_s4_2();

void create_screen_screen_s4_3();
void tick_screen_screen_s4_3();

void create_screen_screen_s4_4();
void tick_screen_screen_s4_4();

void create_screen_screen_s5_1();
void tick_screen_screen_s5_1();

void create_screen_screen_s5_2();
void tick_screen_screen_s5_2();

void create_screen_screen_s5_3();
void tick_screen_screen_s5_3();

void create_screen_screen_s5_4();
void tick_screen_screen_s5_4();

void create_screen_screen_s5_5();
void tick_screen_screen_s5_5();

void create_screen_screen_s6_1();
void tick_screen_screen_s6_1();

void create_screen_screen_s6_2();
void tick_screen_screen_s6_2();

void create_screen_screen_s6_3();
void tick_screen_screen_s6_3();

void create_screen_screen_s6_4();
void tick_screen_screen_s6_4();

void create_screen_screen_s6_5();
void tick_screen_screen_s6_5();

void create_screen_screen_s6_6();
void tick_screen_screen_s6_6();

void create_screen_screen_confirm();
void tick_screen_screen_confirm();

void create_screen_screen_s6_7();
void tick_screen_screen_s6_7();

void create_screen_screen_s6_8();
void tick_screen_screen_s6_8();

void create_screen_screen_s6_9();
void tick_screen_screen_s6_9();

void create_screen_screen_s7_1();
void tick_screen_screen_s7_1();

void create_screen_screen_s7_2();
void tick_screen_screen_s7_2();

void create_screen_screen_s7_3();
void tick_screen_screen_s7_3();

void create_screen_screen_s7_4();
void tick_screen_screen_s7_4();

void create_screen_screen_s7_5();
void tick_screen_screen_s7_5();

void create_screen_screen_s7_6();
void tick_screen_screen_s7_6();

void create_screen_screen_s7_7();
void tick_screen_screen_s7_7();

enum Themes {
    THEME_ID_DEFAULT,
    THEME_ID_THEME_1,
};
enum Colors {
    COLOR_ID_VIOLETTE,
    COLOR_ID_GREEN,
    COLOR_ID_GREY_BG,
    COLOR_ID_ORANGE,
    COLOR_ID_GREY_TEXT,
    COLOR_ID_GREY_BG_2,
};
void change_color_theme(uint32_t themeIndex);
extern uint32_t theme_colors[2][6];

void create_screens();
void tick_screen(int screen_index);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/