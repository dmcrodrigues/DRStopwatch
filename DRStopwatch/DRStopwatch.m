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

#import "DRStopwatch.h"

#import "stopwatch.h"

@interface DRStopwatch ()
{
    @private
    Stopwatch stopwatchInstance;
}
@end

@implementation DRStopwatch

+ (id)stopwatch
{
    return [[self alloc] init];
}

+ (id)stopwatchStartingNow
{
    DRStopwatch *sw = [DRStopwatch stopwatch];
    [sw start];
    return sw;
}

- (id)init
{
    self = [super init];
    if (self) {
    }
    return self;
}

- (void)start
{
    sw_start(&stopwatchInstance);
}

- (void)stop
{
    sw_stop(&stopwatchInstance);
}


- (double)elapsedTime:(DRTimeOption)option
{
    switch (option) {
            
        case kElapsedTimeMilliseconds:
            return sw_get_elapsed_milliseconds(&stopwatchInstance);
            
        case kElapsedTimeSeconds:
            return sw_get_elapsed_seconds(&stopwatchInstance);
            
        default:
            return 0;
    }
}

@end
