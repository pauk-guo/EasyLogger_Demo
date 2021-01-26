// EasyLogger_Demo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define LOG_TAG     "main"
#include <iostream>
#include <windows.h>
#include "elog.h"


enum class LOG_LEVEL {
    LOG_LVL_ASSERT = 0,
    LOG_LVL_ERROR = 1,
    LOG_LVL_WARN = 2,
    LOG_LVL_INFO = 3,
    LOG_LVL_DEBUG = 4,
    LOG_LVL_VERBOSE = 5
};

static void test_elog(void);
void write_log(LOG_LEVEL type, const char* file, const char* func, const long line, const char* strLog);
#define WRITE_LOG_A(strLog)                                                             \
{                                                                                       \
    write_log(LOG_LEVEL::LOG_LVL_ASSERT, __FILE__, __FUNCTION__, __LINE__, strLog);	    \
}
#define WRITE_LOG_E(strLog)                                                             \
{                                                                                       \
    write_log(LOG_LEVEL::LOG_LVL_ERROR, __FILE__, __FUNCTION__, __LINE__, strLog);      \
}
#define WRITE_LOG_W(strLog)                                                             \
{                                                                                       \
    write_log(LOG_LEVEL::LOG_LVL_WARN, __FILE__, __FUNCTION__, __LINE__, strLog);       \
}
#define WRITE_LOG_I(strLog)                                                             \
{                                                                                       \
    write_log(LOG_LEVEL::LOG_LVL_INFO, __FILE__, __FUNCTION__, __LINE__, strLog);       \
}
#define WRITE_LOG_D(strLog)                                                             \
{                                                                                       \
    write_log(LOG_LEVEL::LOG_LVL_DEBUG, __FILE__, __FUNCTION__, __LINE__, strLog);      \
}
#define WRITE_LOG_V(strLog)                                                             \
{                                                                                       \
    write_log(LOG_LEVEL::LOG_LVL_VERBOSE, __FILE__, __FUNCTION__, __LINE__, strLog);	\
}

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

        WRITE_LOG_A("WRITE Hello EasyLogger ASSERT!");
        WRITE_LOG_E("WRITE Hello EasyLogger ERROR!");
        WRITE_LOG_W("WRITE Hello EasyLogger WARN!");
        WRITE_LOG_I("WRITE Hello EasyLogger INFO!");
        WRITE_LOG_D("WRITE Hello EasyLogger DEBUG!");
        WRITE_LOG_V("WRITE Hello EasyLogger VERBOSE!");

        Sleep(1000);
    }
    
}

void write_log(LOG_LEVEL type, const char* file, const char* func, const long line, const char* strLog)
{
    switch (type) {
    case LOG_LEVEL::LOG_LVL_ASSERT:
        log_a_i(file, func, line, strLog);
        break;
    case LOG_LEVEL::LOG_LVL_ERROR:
        log_e_i(file, func, line, strLog);
        break;
    case LOG_LEVEL::LOG_LVL_WARN:
        log_w_i(file, func, line, strLog);
        break;
    case LOG_LEVEL::LOG_LVL_INFO:
        log_i_i(file, func, line, strLog);
        break;
    case LOG_LEVEL::LOG_LVL_DEBUG:
        log_d_i(file, func, line, strLog);
        break;
    case LOG_LEVEL::LOG_LVL_VERBOSE:
        log_v_i(file, func, line, strLog);
        break;
    default:
        log_i_i(file, func, line, strLog);
        break;
    }
}