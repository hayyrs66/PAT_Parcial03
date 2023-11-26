#include "Ejercicio03.h"
#include <map>
#include <iterator>

TimeMap::TimeMap()
{
    map = new unordered_map<string, vector<Pair*>>();
}

void TimeMap::set(string key, string value, int timestamp)
{
    (*map)[key].emplace_back(new Pair{ timestamp, value });
}

string TimeMap::get(string key, int timestamp)
{
    if (map->find(key) == map->end())
        return "";

    vector<Pair*> values = (*map)[key];

    unsigned int top = values.size();
    unsigned int bottom = 0;
    unsigned int middle;

    if (values[bottom]->timestamp > timestamp)
        return "";

    if (values[top - 1]->timestamp <= timestamp)
        return values[top - 1]->value;

    while (bottom < top) {
        middle = (top + bottom) >> 1;

        if (values[middle]->timestamp == timestamp)
            return values[middle]->value;

        if (values[middle]->timestamp < timestamp)
            bottom = middle + 1;
        else
            top = middle;
    }

    return values[middle]->value;
}

TimeMap::~TimeMap()
{
    for (auto& entry : *map) {
        for (auto& pair : entry.second) {
            delete pair;
        }
    }
    delete map;
}