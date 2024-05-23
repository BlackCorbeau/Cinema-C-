#pragma once
#define STEP_CAPACITY 15

enum archive_State { empty, Busy, Deleted };

namespace algorithms {
    template<typename T>
    inline void swap(T& val_1, T& val_2) noexcept {
        T tmp = val_1;
        val_1 = val_2;
        val_2 = tmp;
    }

    template<typename T>
    T Max(T val_1, T val_2) {
        if (val_1 > val_2) return val_1;
        else return val_2;
    }

    template<typename T>
    T min(T val_1, T val_2) {
        if (val_1 < val_2) return val_1;
        else return val_2;
    }
}
