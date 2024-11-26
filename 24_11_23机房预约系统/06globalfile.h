//
// Created by tianya on 2024/11/23.
//

#ifndef INC_2024_11_23_GLOBAL_H
#define INC_2024_11_23_GLOBAL_H

//global 全局文件
#pragma once
//写成宏  编译器会智能提示 防止写错
//不需要在源文件目录提前创建对应txt，编译时会自动生成，也可以提前写好空文件
//管理员文件
#define ADMIN_FILE      "admin.txt"
//学生文件
#define STUDENT_FILE    "student.txt"
//教师文件
#define TEACHER_FILE    "teacher.txt"
//机房信息文件
#define COMPUTER_FILE   "computerRoom.txt"
//订单文件
#define ORDER_FILE      "order.txt"

#endif //INC_2024_11_23_GLOBAL_H
