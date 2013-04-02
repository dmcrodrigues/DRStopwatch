DRStopwatch
====
DRStopwatch provides a simpler API to measure times from applications written in C/C++ to applications for iOS and Mac OS X. This project has two main goals: be simple and be precise.

> **Note** 
> Support for Linux and Apple hardware (iOS and Mac OS X)

## Installation
Just drag `DRStopwatch` folder to your project.

## Usage

### C/C++

To use `DRStopwatch` you only need to declare a structure `Stopwatch` and use the following API.

```C
void sw_start(Stopwatch *s);
void sw_stop(Stopwatch *s);
double sw_get_elapsed_milliseconds(Stopwatch *s);
double sw_get_elapsed_seconds(Stopwatch *s);
```

> **Warning**
> On Linux you may need to link with the `librt` library using `-lrt`.

### Objective-C

The support for Objective-C is made of a wrapper around the C/C++ API, the class `DRStopwatch`. This class provides the following API.

```Objective-C
+ (id)stopwatch;
+ (id)stopwatchStartingNow;
- (id)init;
- (void)start;
- (void)stop;
- (double)elapsedTime:(DRTimeOption)option;
```

> **Note**
> `DRTimeOption` can take the values `kElapsedTimeSeconds` and `kElapsedTimeMilliseconds` to specified the time unit.

## Licence
[MIT License](http://en.wikipedia.org/wiki/MIT_License) (c) [David Rodrigues](mailto:david.ndh@gmail.com)
