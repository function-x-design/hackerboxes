#pragma once

int getBarsSignal(long rssi)
{
    int bars = 0;

    if (rssi >= -55)
        return 5;

    if (rssi >= -65)
        return 4;

    if (rssi >= -75)
        return 3;

    if (rssi >= -85)
        return 2;

    if (rssi >= -96)
        return 1;

    return bars;
}
