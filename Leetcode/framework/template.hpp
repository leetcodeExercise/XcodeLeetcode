//
//  template.hpp
//  framework
//
//  Created by dsh on 2021/8/2.
//

#ifndef FREAMEWORK_TEMPLATE_HPP
#define FREAMEWORK_TEMPLATE_HPP

#include <iostream>
#include <vector>

class Variable {
  public:
    Variable() = default;
    ~Variable() = default;
    
    virtual void UpdateVariable() = 0;
    virtual void ClearVariable() = 0;
    
  private:
    bool _isUpdate = false;
};

class Planner1Variable : public Variable {
  public:
    Planner1Variable() = default;
    ~Planner1Variable();
    
    void UpdateVariable();
    void ClearVariable();
    
  private:
    int _index;
    int* _ptr;
};

class Planner2Variable : public Variable {
  public:
    Planner2Variable() = default;
    ~Planner2Variable() = default;
  
    void UpdateVariable();
    void ClearVariable();
    
  private:
    int _index;
    std::vector<char> _value;
};

class Result {
  public:
    Result() = default;
    ~Result() = default;
    
    virtual void UpdateResult() = 0;
    virtual void ClearResult() = 0;
    virtual void Variable2Result() = 0;
    
  private:
    bool _isUpdate = false;
};

class Planner1Result : public Result {
  public:
    struct RelativeData {
        double n;
        std::vector<double> values1;
        std::vector<std::vector<int>> values2;
    };
    

    explicit Planner1Result(std::shared_ptr<Variable> variable)
        : _variable(variable) {}
    ~Planner1Result() = default;
    
    void UpdateResult();
    void ClearResult();
    void Variable2Result();
    std::pair<std::shared_ptr<Variable>, std::shared_ptr<RelativeData>>
        GetResult() const { return _result; }
    
  private:
    std::shared_ptr<Variable> _variable;
    RelativeData _relativeData;
    std::pair<std::shared_ptr<Variable>, std::shared_ptr<RelativeData>> _result;
};

class Planner2Result : public Result {
  public:
    struct RelativeData {
        double n;
    };
    explicit Planner2Result(std::shared_ptr<Variable> variable)
        : _variable(variable) {}
    ~Planner2Result() = default;
    
    void UpdateResult();
    void ClearResult();
    void Variable2Result();
    std::pair<std::shared_ptr<Variable>, std::shared_ptr<RelativeData>>
        GetResult() const { return _result; }
    
  private:
    std::shared_ptr<Variable> _variable;
    RelativeData _relativeData;
    std::pair<std::shared_ptr<Variable>, std::shared_ptr<RelativeData>> _result;
};

class Section;

class Dependency {
  public:
    explicit Dependency(std::shared_ptr<Result> result,
                        std::shared_ptr<Section> section)
        : _result(result), _section(section) {}
    ~Dependency() = default;
    
  private:
    std::shared_ptr<Result> _result;
    std::shared_ptr<Section> _section;
};

class Dependency1 : public Dependency {
    // TODO:
};

class Dependency2 : public Dependency {
    // TODO:
};

class Constraint;
class Cost;

class Section {
  public:
    explicit Section() {}
    ~Section() {}
    
    virtual Variable MakePlan();
    
  private:
    std::shared_ptr<Result> _sectionResult;
    std::vector<std::shared_ptr<Dependency>> _dependencies;
    std::shared_ptr<Section> _nextSection;
    std::shared_ptr<Constraint> _constraint;
    std::shared_ptr<Cost> _cost;
};

class Section1 : public Section {
    // TODO:
};

class Section2 : public Section {
    // TODO:
};

#endif /* FREAMEWORK_TEMPLATE_HPP */
