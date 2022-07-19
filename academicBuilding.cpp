#include <utility>
#include "academicBuilding.h"
#include "monopolyBlock.h"
#include "error.h"
#include "player.h"

AcademicBuilding::AcademicBuilding(std::string name, double cost, std::vector<double> tuition, MonopolyBlock &mb) :
    Property{std::move(name), cost}, tuition{std::move(tuition)}, mb{&mb} {
    mb.addNewBuilding(*this);
}

double AcademicBuilding::calculateRent() const {
    int improve = mb->getImproveNum();
    return tuition[improve];
}

int AcademicBuilding::getImproveNum() const {
    return mb->getImproveNum();
}

void AcademicBuilding::addImprove() {
    mb->addImprove();
}

void AcademicBuilding::removeImprove() {
    mb->removeImprove();
}


