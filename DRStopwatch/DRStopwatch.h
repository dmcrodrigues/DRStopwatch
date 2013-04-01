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

#import <Foundation/Foundation.h>

typedef enum {
    kElapsedTimeSeconds,
    kElapsedTimeMilliseconds,
} DRTimeOption;

/**
 `DRStopwatch` measures the elapsed time from the start to the stop. Before it's 
 stopped, it measures the time from the start until the current time.

 ## Time units

 The elapsed time can be measured on seconds and milliseconds using `DRTimeOption`.
 */
@interface DRStopwatch : NSObject

/// -----------------------------------------
/// @name Creating and Initializing Stopwatch
/// -----------------------------------------

/**
 Creates and initializes an `DRStopwatch` object.
 
 @return The initialized DRtopwach object.
 */
+ (id)stopwatch;

/**
 Creates and initializes an `DRStopwatch` object and automatically starts counting time.
 
 @return The initialized DRtopwach object.
 */
+ (id)stopwatchStartingNow;

/**
 Initializes an `DRStopwatch` object.
 
 @return The initialized DRtopwach object.
 */
- (id)init;

/// -----------------------------------------
/// @name Control Stopwatch
/// -----------------------------------------

/**
 Starts counting time.
 */
- (void)start;

/**
 Stops couting time.
 */
- (void)stop;

/// -----------------------------------------
/// @name Getting Elapsed Time
/// -----------------------------------------

/**
 Calculates the elapsed time from the start to the end. If not stopped, 
 calculates the elapsed time until now.
 
 @param option The unit to calculate the elapsed time. Can be 'Seconds' or 
 'Milliseconds'.
 
 @return the elapsed time on the specified unit with double precision.
 */
- (double)elapsedTime:(DRTimeOption)option;

@end
