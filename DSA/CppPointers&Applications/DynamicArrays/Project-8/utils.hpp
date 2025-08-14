#pragma once

template <typename SourceT, typename DestT>
DestT Copy(SourceT begin, SourceT end, DestT dest)
{
    for (; begin != end; ++begin, ++dest)
    {
        *dest = *begin;
    }

    return dest;
}
