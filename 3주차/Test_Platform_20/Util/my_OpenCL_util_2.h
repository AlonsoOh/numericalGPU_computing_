﻿//
//  my_OpenCL_util_2.cpp
//
//  Written for CSEG437_CSE5437
//  Department of Computer Science and Engineering
//  Copyright © 2020 Sogang University. All rights reserved.
//

#ifndef my_OpenCL_util_2_h
#define my_OpenCL_util_2_h

#include<stdio.h>
#include<stdlib.h>

#include <CL/cl.h>

/******************************************************************************************************/
#include <Windows.h>
// __int64 _start, _freq, _end;
#define CHECK_TIME_START(start,freq) QueryPerformanceFrequency((LARGE_INTEGER*)&freq); QueryPerformanceCounter((LARGE_INTEGER*)&start)
#define CHECK_TIME_END(start,end,freq,time) QueryPerformanceCounter((LARGE_INTEGER*)&end); time = (float)((float)(end - start) / (freq * 1.0e-3f))
/******************************************************************************************************/

#define CHECK_ERROR_CODE(a) check_error_code(a, __LINE__-1, __FILE__)

char* get_error_flag(cl_int errcode);
int check_error_code(cl_int errcode, int line, const char* file);
size_t read_kernel_from_file(const char* filename, char** source_str);
int print_build_log(cl_program program, cl_device_id device, const char* title_suppl);
int compute_elapsed_time(cl_event event, cl_ulong* time, cl_profiling_info from, cl_profiling_info to);
int print_device_time(cl_event event);
void print_device_0(cl_device_id device);
void print_platform(cl_platform_id* platforms, int i);
void print_device(cl_device_id* devices, int j);
void print_devices(cl_platform_id* platforms, int i);
int show_OpenCL_platform(void);
void printf_KernelWorkGroupInfo(cl_kernel kernel, cl_device_id device);

#endif /* my_OpenCL_util_2_h */
