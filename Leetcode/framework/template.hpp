//
//  template.hpp
//  framework
//
//  Created by dsh on 2021/8/2.
//

#ifndef FREAMEWORK_TEMPLATE_HPP
#define FREAMEWORK_TEMPLATE_HPP

#include <vector>

class Variable {
  public:
    Variable() = default;
    ~Variable() = default;
    
    virtual void UpdateVariable() = 0;
    virtual void ClearVariable() = 0;
    bool IsUpdated() { return _isUpdated; }
    
  protected:
    bool _isUpdated = false;
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
    bool ISUpdated() { return _isUpdated; }
    
  protected:
    bool _isUpdated = false;
};

class Planner1Result : public Result {
  public:
    struct RelativeData {
        double n;
        std::vector<double> values1;
        std::vector<std::vector<int>> values2;
    };
    
    explicit Planner1Result(std::shared_ptr<const Variable> variable)
        : _variable(variable) {}
    ~Planner1Result() = default;
    
    void UpdateResult();
    void ClearResult();
    void Variable2Result();
    auto GetResult() const { return _result; }
    
  private:
    std::shared_ptr<const Variable> _variable;
    RelativeData _relativeData;
    std::pair<std::shared_ptr<const Variable>, std::shared_ptr<const RelativeData>> _result;
};

class Planner2Result : public Result {
  public:
    struct RelativeData {
        double n;
    };
    explicit Planner2Result(std::shared_ptr<const Variable> variable)
        : _variable(variable) {}
    ~Planner2Result() = default;
    
    void UpdateResult();
    void ClearResult();
    void Variable2Result();
    auto GetResult() const { return _result; }
    
  private:
    std::shared_ptr<const Variable> _variable;
    RelativeData _relativeData;
    std::pair<std::shared_ptr<const Variable>, std::shared_ptr<const RelativeData>> _result;
};

class Section;

struct PreDependency {
    std::pair<std::shared_ptr<const Result>, std::shared_ptr<const Section>> preDependency;
};

struct NextDependency {
    std::shared_ptr<const Section> nextDependency;
};

struct PreSectionDependencies {
    std::vector<std::shared_ptr<const PreDependency>> preSectionDependencies;
};

struct NextSectionDependencies {
    std::vector<std::shared_ptr<const NextDependency>> nextSectionDependencies;
};

class Dependencies {
  public:
    Dependencies() = default;
    ~Dependencies() = default;
    
    void AddDependency(std::shared_ptr<const PreDependency> add,
                       std::shared_ptr<PreSectionDependencies> sectionDependencies);
    void AddDependency(std::shared_ptr<const NextDependency> add,
                       std::shared_ptr<NextSectionDependencies> sectionDependencies);
};

class Section1PreDependencies : public Dependencies {
  public:
    explicit Section1PreDependencies() {
        // TODO: build _preSectionDependencies
    }
    ~Section1PreDependencies() = default;
    
    PreSectionDependencies GetSectionDependencies() const {
        return _preSectionDependencies;
    }
    
 private:
    PreSectionDependencies _preSectionDependencies;
};

class Section1NextDependencies : public Dependencies {
  public:
    explicit Section1NextDependencies() {
        // TODO: build _nextSectionDependencies
    }
    ~Section1NextDependencies() = default;
    
    NextSectionDependencies GetSectionDependencies() const {
        return _nextSectionDependencies;
    }
    
 private:
    NextSectionDependencies _nextSectionDependencies;
};

class Constraint;
class Cost;
class Targets;

class Section {
  public:
    explicit Section(std::shared_ptr<const Dependencies> preDependencies,
                     std::shared_ptr<const Dependencies> nextDependencies,
                     std::shared_ptr<const Targets> targets,
                     std::shared_ptr<Constraint> constraint,
                     std::shared_ptr<Cost> cost)
        : _preDependencies(preDependencies), _nextDependencies(nextDependencies),
          _targets(targets), _constraint(constraint), _cost(cost) {}
    ~Section();
    
    auto GetPreDependencies() const { return _preDependencies; }
    auto GetNextDependencies() const { return _nextDependencies; }
    auto GetTargets() const { return _targets; }
    auto GetConstraint() const { return _constraint; }
    auto GetCost() const { return _cost; }
        
  protected:
    virtual void BuildConstraint() = 0;
    virtual void BuildCost() = 0;
    
    std::shared_ptr<const Dependencies> _preDependencies;
    std::shared_ptr<const Dependencies> _nextDependencies;
    std::shared_ptr<const Targets> _targets;
    std::shared_ptr<Constraint> _constraint;
    std::shared_ptr<Cost> _cost;
};

class Section1 : public Section {
    // TODO:
};

class Section2 : public Section {
    // TODO:
};

class Planner {
  public:
    explicit Planner() {}
    ~Planner();
    
    virtual Variable MakePlan();
    
  protected:
    std::unique_ptr<const Section> _section;
    Variable _variable;
};

class Planner1 : public Planner {
    // TODO:
};

#endif /* FREAMEWORK_TEMPLATE_HPP */
