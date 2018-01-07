# Float Wrapper #

This is a simple wrapper for floating-point values

## Why? ##

At the beginning, I wanted to check if two floating-point values are equals.
Since the basic operator '==' isn't very precise, I used a function I took
from this [project](https://github.com/Nerdylicious/FloatingPointComparison).

I integrated this function in [one](https://github.com/Gumichan01/lunatix)
of my projects, but I needed to use it in any projects.
I could just put it in a new header file and use this same file,
but even if it would be very useful in a C project, it was not very convenient in a
C++ project that uses OOP. So, I decided to just create a Float class
that wrap floating-point values, to integrate the comparison into its operators,
and to provide convenient conversions between a Float object and a float primitive value.

## Example ##

TODO

## Compilation ##

    make
    ./float-wrapper

## License ##

This project is under the MIT license
