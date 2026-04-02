#pragma once

#include <stdexcept>
#include <exception>

namespace PiSubmarine::Exceptions
{
#if defined(__cpp_exceptions) || defined(__EXCEPTIONS) || defined(_CPPUNWIND)
    inline constexpr bool Enabled = true;
#else
    inline constexpr bool Enabled = false;
#endif

    // Using a raw function pointer saves heap and is safer for ISRs
    using HandlerFunc = void(*)(const char* message);

    extern HandlerFunc GlobalHandler;

    template<typename E>
    [[noreturn]] void Throw(E&& exception)
    {
        if constexpr (Enabled)
        {
            throw std::forward<E>(exception);
        }
        else
        {
            if (GlobalHandler)
            {
                GlobalHandler(exception.what());
            }

            std::abort();
        }
    }
}