//
//  source.hpp
//  SmartPointer
//
//  Created by dsh on 2021/9/6.
//

#ifndef SMART_POINTER_SOURCE_HPP
#define SMART_POINTER_SOURCE_HPP

#include <memory>

class Section;

typedef std::vector<std::shared_ptr<const Section>> TopLevelGraph;

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

class Section {
public:
    explicit Section(Type type) : _type(type) {}
    ~Section() = default;
    
    Type type() const { return _type; }
    
private:
    Type _type = Type::NotDefine;
};

class SectionCreator {
public:
    explicit SectionCreator(std::shared_ptr<const Action> action)
    : _action(action), _section(action.get()->type()) {}
    ~SectionCreator() = default;
    
    std::shared_ptr<const Section> section() const {
        return std::make_shared<const Section>(_section);
    }
    
private:
    Section _section;
    std::shared_ptr<const Action> _action;
};

#endif  /* SMART_POINTER_SOURCE_HPP */
