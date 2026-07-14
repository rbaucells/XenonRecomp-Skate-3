#pragma once

#include <cassert>
#include <cstdint>
#if defined(_MSC_VER)
#include <intrin.h>
#endif

template<typename T>
inline T ByteSwap(T value)
{
    if constexpr (sizeof(T) == 1) {
        return value;
    }
    else if constexpr (sizeof(T) == 2) {
#if defined(__has_builtin)
#if __has_builtin(__builtin_bswap16)
        return static_cast<T>(__builtin_bswap16(static_cast<std::uint16_t>(value)));
#endif
#elif defined(_MSC_VER)
        return static_cast<T>(_byteswap_ushort(static_cast<std::uint16_t>(value)));
#endif
    }
    else if constexpr (sizeof(T) == 4) {
#if defined(__has_builtin)
#if __has_builtin(__builtin_bswap32)
        return static_cast<T>(__builtin_bswap32(static_cast<std::uint32_t>(value)));
#endif
#elif defined(_MSC_VER)
        return static_cast<T>(_byteswap_ulong(static_cast<std::uint32_t>(value)));
#endif
    }
    else if constexpr (sizeof(T) == 8) {
#if defined(__has_builtin)
#if __has_builtin(__builtin_bswap64) // Fixed typo here from bswap32 to bswap64
        return static_cast<T>(__builtin_bswap64(static_cast<std::uint64_t>(value)));
#endif
#elif defined(_MSC_VER)
        return static_cast<T>(_byteswap_uint64(static_cast<std::uint64_t>(value)));
#endif
    }

    assert(false && "Unexpected byte size.");
    return value;
}

template<typename T>
inline void ByteSwapInplace(T& value)
{
    value = ByteSwap(value);
}