//
//  section.hpp
//  SmartPointer
//
//  Created by dsh on 2021/9/7.
//

#ifndef SMART_POINTER_SECTION_HPP
#define SMART_POINTER_SECTION_HPP

#include <memory>

#include "action.hpp"

class Section {
public:
    explicit Section(Type type) : _type(type) {}
    ~Section() = default;
    
    Type type() const { return _type; }
    
private:
    Type _type = Type::NotDefine;
};

class MotionSection : public Section {
public:
    explicit MotionSection(int index) : Section(Type::Motion), _index(index) {}
    ~MotionSection() = default;
    
private:
    int _index;
    // data
};

class DecisionSection : public Section {
public:
    explicit DecisionSection(int index) : Section(Type::Decision), _index(index) {}
    ~DecisionSection() = default;
    
private:
    int _index;
    // data
};

class MotionSectionCreator {
public:
    explicit MotionSectionCreator(std::shared_ptr<const Action> action, int index)
    : _action(action), _section(index) {
//        std::shared_ptr<const DecisionAction> decisionAction =
//            static_cast<std::shared_ptr<const DecisionAction>>(
//                static_cast<const DecisionAction*>(actionGroup[0].get()));
        }
    ~MotionSectionCreator() = default;
    
    std::shared_ptr<const Section> section() const {
        return std::make_shared<const Section>(_section);
    }
    
private:
    MotionSection _section;
    std::shared_ptr<const Action> _action;
};

class DecisionSectionCreator {
public:
    explicit DecisionSectionCreator(std::shared_ptr<const Action> action, int index)
    : _action(action), _section(index) {
//        std::shared_ptr<const DecisionAction> decisionAction =
//            static_cast<std::shared_ptr<const DecisionAction>>(
//                static_cast<const DecisionAction*>(actionGroup[0].get()));
        }
    ~DecisionSectionCreator() = default;
    
    std::shared_ptr<const Section> section() const {
        return std::make_shared<const Section>(_section);
    }
    
private:
    DecisionSection _section;
    std::shared_ptr<const Action> _action;
};
#endif  /* SMART_POINTER_SECTION_HPP */
