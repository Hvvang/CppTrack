#pragma once

template <class T, class...Ts>
T sumOfArguments(T t, Ts...args) {
    return t + (args + ...);
}
