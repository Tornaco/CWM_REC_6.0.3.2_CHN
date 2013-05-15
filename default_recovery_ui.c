/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <linux/input.h>

#include "recovery_ui.h"
#include "common.h"
#include "extendedcommands.h"

char* MENU_HEADERS[] = { "基于CWM_V6.0.3.2的安卓中文刷机/恢复系统"};

char* MENU_ITEMS[] = { "立即重启到安卓系统",
                       "从内存卡选择刷机包刷机",
                       "使用adb sideload模式刷机",
                       "抹掉data/全部用户数据",
                       "抹掉cache/缓存数据",
                       "系统备份与恢复",
                       "分区格式化与挂载",
                       "高级选项",
                       "关闭手机",
                       "一键刷机(初次使用请看帮助)",
                       "帮助信息",
                       NULL };

void device_ui_init(UIParameters* ui_parameters) {
}

int device_recovery_start() {
    return 0;
}

int device_reboot_now(volatile char* key_pressed, int key_code) {
    return 0;
}

int device_perform_action(int which) {
    return which;
}

int device_wipe_data() {
    return 0;
}
