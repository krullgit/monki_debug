#include "styles.h"
#include "images.h"
#include "fonts.h"

#include "screens.h"

//
// Style: button_mid
//

void init_style_button_mid_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[0][2]));
    lv_style_set_text_font(style, &ui_font_main_medium_40);
    lv_style_set_radius(style, 1000);
    lv_style_set_pad_top(style, 15);
    lv_style_set_pad_left(style, 100);
    lv_style_set_pad_right(style, 100);
    lv_style_set_pad_bottom(style, 15);
};

lv_style_t *get_style_button_mid_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_button_mid_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_button_mid(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_button_mid_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_button_mid(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_button_mid_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
//
//

void add_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*AddStyleFunc)(lv_obj_t *obj);
    static const AddStyleFunc add_style_funcs[] = {
        add_style_button_mid,
    };
    add_style_funcs[styleIndex](obj);
}

void remove_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*RemoveStyleFunc)(lv_obj_t *obj);
    static const RemoveStyleFunc remove_style_funcs[] = {
        remove_style_button_mid,
    };
    remove_style_funcs[styleIndex](obj);
}

