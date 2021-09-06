//
//  main.cpp
//  SmartPointer
//
//  Created by dsh on 2021/9/6.
//

#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>
#include "source.hpp"

int main(int argc, const char* argv[]) {
    TopLevelGraph topLevelGraph = {};
    std::unordered_map<std::shared_ptr<const Action>, std::shared_ptr<const Section>> map;
    std::vector<Type> type = {Type::Motion, Type::Decision, Type::Motion};
    std::vector<std::shared_ptr<const Action>> actionGroup;
    for (size_t i = 0; i < type.size(); i++) {
        Action action(type[i]);
        actionGroup.push_back(std::make_shared<const Action>(action));
    }
    for (size_t i = 0; i < actionGroup.size(); i++) {
        switch (actionGroup[i].get()->type()) {
            case Type::Motion: {
                SectionCreator sectionCreator(actionGroup[i]);
                topLevelGraph.push_back(sectionCreator.section());
                map[actionGroup[i]] = sectionCreator.section();
                break;
            }
            case Type::Decision: {
                SectionCreator sectionCreator(actionGroup[i]);
                topLevelGraph.push_back(sectionCreator.section());
                map[actionGroup[i]] = sectionCreator.section();
                break;
            }
            case Type::NotDefine: {
                SectionCreator sectionCreator(actionGroup[i]);
                topLevelGraph.push_back(sectionCreator.section());
                map[actionGroup[i]] = sectionCreator.section();
                break;
            }
        }
    }
    
    for (size_t i = 0; i < topLevelGraph.size(); i++) {
        std::cout << "TopLevelGraph[" << i << "]: "
            << static_cast<int>(topLevelGraph[i].get()->type()) << std::endl;
    }
    return 0;
}
