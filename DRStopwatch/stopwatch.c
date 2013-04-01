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

#include "stopwatch.h"

struct timespec sw_collect_time();

void sw_start(Stopwatch *s) {
    s->start = sw_collect_time();
    s->status = STARTED;
}

void sw_stop(Stopwatch *s) {
    s->end = sw_collect_time();
    s->status = FINISHED;
}

double sw_get_elapsed_milliseconds(Stopwatch *s) {
    if (s->status == CREATED) return 0;
    struct timespec a = s->start;
    struct timespec b = s->status != FINISHED ? sw_collect_time() : s->end;
    double seconds = b.tv_sec  - a.tv_sec;
    double nseconds = b.tv_nsec - a.tv_nsec;
    return ((seconds) * 1e3 + (nseconds/1e6));
}

double sw_get_elapsed_seconds(Stopwatch *s) {
    struct timespec a = s->start;
    struct timespec b = s->status != FINISHED ? sw_collect_time() : s->end;
    double seconds = b.tv_sec  - a.tv_sec;
    double nseconds = b.tv_nsec - a.tv_nsec;
    return (seconds + (nseconds/1e9));
}

struct timespec sw_collect_time() {
    struct timespec time_result;
#ifdef __MACH__
    clock_serv_t cclock;
    mach_timespec_t mts;
    host_get_clock_service(mach_host_self(), SYSTEM_CLOCK, &cclock);
    clock_get_time(cclock, &mts);
    mach_port_deallocate(mach_task_self(), cclock);
    time_result.tv_sec = mts.tv_sec;
    time_result.tv_nsec = mts.tv_nsec;
#else
    clock_gettime(CLOCK_REALTIME, &time_result);
#endif
    return time_result;
}
