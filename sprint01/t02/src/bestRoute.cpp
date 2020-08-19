#include "visitAll.h"

static std::deque<Info> backRoute(const std::deque<Info>& data, int start) {
    std::deque<Info> route;

    for (int i = start; ;) {
        route.push_back(data[i]);
        i--;
        if (i == -1) {
            i = data.size() - 1;
        }
        if (i == start) {
            break;
        }
    }
    return route;
}

static std::deque<Info> frontRoute(const std::deque<Info>& data, int start) {
    std::deque<Info> route;

    for (int i = start; ;) {
        route.push_back(data[i]);
        i++;
        if (i == data.size()) {
            i = 0;
        }
        if (i == start) {
            break;
        }
    }
    return route;
}

static int countStamina(const std::deque<Info>& data) {
    int stamina = data[0].stamina;

    for (int i = 1; i < data.size(); i++) {
        stamina -= data[i].distance;
        if (stamina < 0) return -1;
        stamina += data[i].stamina;
    }
    return stamina;
}

static int printRoute(const std::deque<Info>& best_route, int& start,
                                            const int &direct) {
    int stamina = countStamina(best_route);

    if (stamina < 0) {
        std::cerr << "Mission: Impossible" << '\n';
        return 1;
    }
    for (const auto& it : best_route) {
        std::cout << start << ". " << it.name << '\n';
        if (direct) {
            start++;
            if (start > best_route.size() - 1) start = 0;
        } else {
            start--;
            if (start < 0) start = best_route.size() - 1;
        }
    }
    return 0;
}

int bestRoute(const std::deque<Info>& data) {
    std::deque<Info> best_route = frontRoute(data, 0);
    int start = 0;
    int direct = 0;

    for (int i = 0; i < data.size(); i++) {
        std::deque<Info> front_Route = frontRoute(data, i);
        std::deque<Info> back_Route = backRoute(data, i);

        if (countStamina(best_route) < countStamina(front_Route) ||
            countStamina(best_route) < countStamina(back_Route)) {
            start = i;
            if (countStamina(front_Route) > countStamina(back_Route)) {
                best_route = front_Route;
                direct = 1;
            } else {
                best_route = back_Route;
                direct = 0;
            }
        }
    }
    return printRoute(best_route, start, direct);
}
