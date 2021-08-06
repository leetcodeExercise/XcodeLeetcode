//
//  template.cpp
//  framework
//
//  Created by dsh on 2021/8/2.
//

#include <iostream>

#include "template.hpp"

bool Variable::IsUpdated() const {
    return _isUpdated;
}

bool Result::ISUpdated() const {
    return _isUpdated;
}

PreSectionDependencies Section1PreDependencies::GetSectionDependencies() const {
    return _preSectionDependencies;
}

NextSectionDependencies Section1NextDependencies::GetSectionDependencies() const {
    return _nextSectionDependencies;
}

std::shared_ptr<const Dependencies> Section::GetNextDependencies() const {
    return _nextDependencies;
}

std::shared_ptr<const Targets> Section::GetTargets() const {
    return _targets;
}

std::shared_ptr<Constraint> Section::GetConstraint() const {
    return _constraint;
}

std::shared_ptr<Cost> Section::GetCost() const {
    return _cost;
}

Planner1Variable::~Planner1Variable() {
    if (_ptr) free(_ptr);
    std::cout << "~Planner1Variable succeed!" << std::endl;
}


