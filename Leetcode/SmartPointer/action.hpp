//
//  action.hpp
//  SmartPointer
//
//  Created by dsh on 2021/9/6.
//

#ifndef SMART_POINTER_ACTION_HPP
#define SMART_POINTER_ACTION_HPP

#include <memory>

enum class Type {
    NotDefine,
    Motion,
    Decision,
};

class Action {
public:
    explicit Action(Type type) : _type(type) {}
    ~Action() = default;
    
    Type type() const { return _type; }
    
private:
    Type _type = Type::NotDefine;
    
};

class MotionAction : public Action {
public:
    explicit MotionAction(int index) : Action(Type::Motion), _index(index) {}
    ~MotionAction() = default;
    
    int index() const { return _index; }
        
private:
    int _index = 0;
    // data
};

class DecisionAction : public Action {
public:
    explicit DecisionAction(int index) : Action(Type::Decision), _index(index) {}
    ~DecisionAction() = default;
    
    int index() const { return _index; }
    
private:
    int _index = 0;
    // data
};

#endif  /* SMART_POINTER_ACTION_HPP */
