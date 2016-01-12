

#ifndef OFX_SIMDFLOATS_INLINES_H_INCLUDED
#define OFX_SIMDFLOATS_INLINES_H_INCLUDED


//DEFINITION OF FORCED INLINE---------------------------------------------------------------
#ifndef inline_f
    #ifdef _MSC_VER
        #define inline_f __forceinline
    #else
        #define inline_f __inline__ __attribute__((always_inline))
    #endif
#endif

#ifndef ROUND_DOWN
    #define ROUND_DOWN(x, s) ((x) & ~((s)-1))
    // rounds down x to a multiple of s (i.e. ROUND_DOWN(5, 4) becomes 4)
#endif

//to put before and after declared array (non pointers) to make them aligned
//e.g.  ALIGNPRE float myArray[8] ALIGNPOST;
#if defined ALIGNPRE || defined ALIGNPOST
#else
    #if defined OFX_SIMD_USE_SSE || defined OFX_SIMD_USE_NEON
        #ifdef _MSC_VER
            #define ALIGNPRE __declspec(align(16))
            #define ALIGNPOST
        #else
            #define ALIGNPRE
            #define ALIGNPOST __attribute__((aligned(16)));
        #endif
    #else
        #define ALIGNPRE
        #define ALIGNPOST
    #endif
#endif


#ifndef NOEXCEPT 
    #ifndef _MSC_VER
    #define NOEXCEPT noexcept
    #else
    #define NOEXCEPT
    #endif
#endif

#ifndef M_TAU
    #define M_TAU 6.28318530717958647692528
#endif

#ifndef M_TAU_DOUBLE
    #define M_TAU_DOUBLE 6.283185307179586476925286766559005768L
#endif

#ifndef M_PI_DOUBLE
    #define M_PI_DOUBLE 3.141592653589793238462643383279502884L
#endif


#endif  // OFX_SIMDFLOATS_INLINES_H_INCLUDED
