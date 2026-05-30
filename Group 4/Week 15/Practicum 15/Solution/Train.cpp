//
// Created by Boris Bozhilov on 5/30/2026.
//

#include "Train.h"

Train::Train(const unsigned int mechanicsCount, const unsigned int wagonCount, const unsigned int seatsCount,
        const unsigned int standingCount) :
    mechanicsCount(mechanicsCount), wagonCount(wagonCount), seatsCount(seatsCount), standingCount(standingCount) {
}

std::unique_ptr<Vehicle> Train::clone() const {

    return std::make_unique<Train>(*this);
}
