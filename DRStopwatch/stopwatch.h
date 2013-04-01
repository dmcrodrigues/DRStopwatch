/*
 * Copyright (c) 2013 David Rodrigues
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef __STOPWATCH_H__
#define __STOPWATCH_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifdef __MACH__
#include <mach/clock.h>
#include <mach/mach.h>
#endif

typedef enum {
	CREATED = 0,
	STARTED = 1,
	FINISHED = 2
} StopwatchStatus;

typedef struct {
	StopwatchStatus status;
	struct timespec start;
	struct timespec end;
} Stopwatch;

/**
 Starts counting time.
 */
void sw_start(Stopwatch *s);

/**
 Stops couting time.
 */
void sw_stop(Stopwatch *s);

/**
 Calculates the elapsed time from the start to the end. If not stopped, 
 calculates the elapsed time until now.
 
 @return the elapsed time in milliseconds with double precision.
 */
double sw_get_elapsed_milliseconds(Stopwatch *s);

/**
 Calculates the elapsed time from the start to the end. If not stopped, 
 calculates the elapsed time until now.
 
 @return the elapsed time in seconds with double precision.
 */
double sw_get_elapsed_seconds(Stopwatch *s);

#endif
