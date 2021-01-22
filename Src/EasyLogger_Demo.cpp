// EasyLogger_Demo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define LOG_TAG     "main"
#include <iostream>
#include <windows.h>
#include "elog.h"
#include <io.h>
#include <direct.h>

static void test_elog(void);

int main()
{
    //std::cout << "Hello World!\n";
    elog_init();
    /* set EasyLogger log format */
    elog_set_fmt(ELOG_LVL_ASSERT, ELOG_FMT_ALL);
    elog_set_fmt(ELOG_LVL_ERROR, ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME);
    elog_set_fmt(ELOG_LVL_WARN, ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME);
    elog_set_fmt(ELOG_LVL_INFO, ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME);
    elog_set_fmt(ELOG_LVL_DEBUG, ELOG_FMT_ALL & ~ELOG_FMT_FUNC);
    elog_set_fmt(ELOG_LVL_VERBOSE, ELOG_FMT_ALL & ~ELOG_FMT_FUNC);
    elog_set_file_path("F:/Git/qtPro/qtPro1/qtPro2/qtPro3");
    
    /* start EasyLogger */
    elog_start();
    /* dynamic set enable or disable for output logs (true or false) */
//    elog_set_output_enabled(true);
    //elog_set_text_color_enabled(true);

    /* dynamic set output logs's level (from ELOG_LVL_ASSERT to ELOG_LVL_VERBOSE) */
//    elog_set_filter_lvl(ELOG_LVL_WARN);
    /* dynamic set output logs's filter for tag */
//    elog_set_filter_tag("main");
    /* dynamic set output logs's filter for keyword */
//    elog_set_filter_kw("WARN");
    /* dynamic set output logs's tag filter */
//    elog_set_filter_tag_lvl("main", ELOG_LVL_WARN);

    /* test logger output */
    test_elog();
}

/**
 * EasyLogger demo
 */
void test_elog(void) {
    while (true) {
        /* test log output for all level */
        log_a("Hello EasyLogger ASSERT!");
        log_e("Hello EasyLogger ERROR!");
        log_w("Hello EasyLogger WARN!");
        log_i("Hello EasyLogger INFO!");
        log_d("Hello EasyLogger DEBUG!");
        log_v("Hello EasyLogger VERBOSE!");
        //        elog_raw("Hello EasyLogger!");
        Sleep(1000);
    }
}