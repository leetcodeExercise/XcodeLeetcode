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

#include "action.hpp"
#include "section.hpp"

typedef std::vector<std::shared_ptr<const Section>> TopLevelGraph;
typedef std::vector<std::shared_ptr<Action>> ActionGroup;
typedef std::unordered_map<std::shared_ptr<const Action>, std::shared_ptr<const Section>> ASMap;

int main(int argc, const char* argv[]) {
    TopLevelGraph topLevelGraph = {};
    ASMap map;
    ActionGroup actionGroup;
    MotionAction ma1(0), ma2(1), ma3(2);
    DecisionAction da1(3), da2(4);
    actionGroup.push_back(std::make_shared<MotionAction>(ma1));
    actionGroup.push_back(std::make_shared<MotionAction>(ma2));
    actionGroup.push_back(std::make_shared<MotionAction>(ma3));
    actionGroup.push_back(std::make_shared<DecisionAction>(da1));
    actionGroup.push_back(std::make_shared<DecisionAction>(da2));
    
    // Do not use get to initialize or assign another smart pointer
    std::shared_ptr<int> p(new int(42));  // reference count is 1
    std::cout << "p count: " << p.use_count() << std::endl;
    int *q = p.get();  // ok
    std::cout << "p count: " << p.use_count() << std::endl;  // 1
    {
        // new block
        // undefined: two independent shared_ptr point to the same memory
        (std::shared_ptr<int>(q));
        std::cout << "p count: " << p.use_count() << std::endl;  // 1
    }  // block end, q is destroyed, and the memory to which q points is free
    std::cout << "p count: " << p.use_count() << std::endl;
    int foo = *p;  // undefined, the memory to which p points is free
    std::cout << "foo: " << foo << std::endl;  // 0

    for (int i = 0; i < actionGroup.size(); i++) {
        switch (actionGroup[i].get()->type()) {
            case Type::Motion: {
                MotionSectionCreator sectionCreator(actionGroup[i], i);
                topLevelGraph.push_back(sectionCreator.section());
                map[actionGroup[i]] = sectionCreator.section();
                break;
            }
            case Type::Decision: {
                DecisionSectionCreator sectionCreator(actionGroup[i], i);
                topLevelGraph.push_back(sectionCreator.section());
                map[actionGroup[i]] = sectionCreator.section();
                break;
            }
            case Type::NotDefine: {
                std::cout << "Type not defined" << std::endl;
                break;
            }
        }
    }
    
    for (int i = 0; i < topLevelGraph.size(); i++) {
        std::cout << "TopLevelGraph[" << i << "]: "
            << static_cast<int>(topLevelGraph[i].get()->type()) << std::endl;
    }
    return 0;
}
