ofxSIMDFloats
==============
An addon for openFrameworks that implements allocation of arrays of memory-aligned floats and SIMD-accelerated mathematical operations on those arrays. Works with SSE2 on x86 processors and NEON on ARM, works Linux, Window, OSX, iOS and Android (with compatible devices).   
Remember to compile with optimizations enabled ( -O2 or -O3 ).
Check example-guide for a quick tutorial.
Remember to execute example-performance and check the performance improvements on all the operations, sometimes the compiler already generating accelerated code, but remember that the example is easy to vectorize for the compiler and by simply restructuring your code as structs-of-arrays you can achieve a performance boost. I've seen the best improvements on the Raspberry Pi and on a Window i3 machine, and the code for all the mathematical functions (sin, cos, log ... ) are always faster (when compiled with -O3 ).

This addon is also based on [this article](http://fastcpp.blogspot.com/2013/03/efficient-processing-of-arrays-using.html) and uses a [library of mathematical functions](http://gruntthepeon.free.fr/ssemath/) coded by Julien Pommer.

Nicola Pisanti, MIT License 2016. Some files by Julien Pommer 2007-2011, with zlib license. Check license.md for more.
