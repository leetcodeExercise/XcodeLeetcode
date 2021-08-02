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

class Planner1Variable {
  public:
    Planner1Variable() = default;
    explicit Planner1Variable(int id, int* pointer) : index(id), ptr(pointer) {}
    ~Planner1Variable() {
        if (ptr) free(ptr);
        std::cout << " ~Planner1Variable() succeed! " << std::endl;
    }
    
    int index;
    int* ptr;
};

class Planner2Variable {
  public:
    Planner2Variable() = default;
    explicit Planner2Variable(int id, std::vector<char> objects) :
    index(id), value(objects) {}
    ~Planner2Variable() {}
    
    int index;
    std::vector<char> value;
};

class Planner1Result {
  public:
    explicit Planner1Result(Planner1Variable variable_init) : x(variable_init) {}
    ~Planner1Result() {}
    Planner1Variable x;
    double n;
    std::vector<double> values1;
    std::vector<std::vector<int>> values2;
};

class Planner2Result {
  public:
    explicit Planner2Result(Planner2Variable variable_init) : x(variable_init) {}
    ~Planner2Result() {}
    Planner2Variable x;
    double n;
};

template<class Variable, class Result>
class SectionResult {
  public:
    explicit SectionResult(Variable variable, Result result) :
    _variable(_variable), _result(result) {}
    ~SectionResult() {}
    
    virtual void Variable2ResultMapping() = 0;
    void set_variable(Variable set_variable) { _variable = set_variable; }
    Result get_result() const { return _result; }
    
  private:
    Variable _variable;
    Result _result;
};

class Section1Result : public SectionResult<Planner1Variable, Planner1Result> {
  public:
    explicit Section1Result(Planner1Variable v, Planner1Result r) : SectionResult(v, r) {}
    ~Section1Result() {}
    
    void Variable2ResultMapping() {
        std::cout << "Section1Result: Variable2ResultMapping" << std::endl;
    }
};

class Section2Result : public SectionResult<Planner2Variable, Planner2Result> {
  public:
    explicit Section2Result(Planner2Variable v, Planner2Result r) : SectionResult(v, r) {}
    ~Section2Result() {}
    
    void Variable2ResultMapping() {
        std::cout << "Section2Result: Variable2ResultMapping" << std::endl;
    }
};

template<class Result, class DependencyData>
class Section {
  public:
    explicit Section() {}
    ~Section() {};
    
  private:
    Result _sectionResult;
    std::vector<DependencyData> _dependencies;
    Section* _nextSection;
};

class Section1Dependency {
  public:
    Section1Dependency() = default;
    ~Section1Dependency() {}
  private:
    Section2Result _data;
    // TODO: 怎么实现？
    // Section* _preSection
};

// TODO: 怎么实现？
// class Section1 public : Section<Section1Result, Section1Dependency> {};

class Section2 {};

#endif /* FREAMEWORK_TEMPLATE_HPP */
