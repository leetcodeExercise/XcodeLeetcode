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
    bool IsUpdated() const;
    
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
    bool ISUpdated() const;
    
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
    
    typedef std::pair<std::shared_ptr<const Variable>, std::shared_ptr<const RelativeData>>
        Result;
    
    explicit Planner1Result(std::shared_ptr<const Variable> variable)
        : _variable(variable) {}
    ~Planner1Result() = default;
    
    void UpdateResult();
    void ClearResult();
    void Variable2Result();
    Result GetResult() const { return _result; }
    
  private:
    std::shared_ptr<const Variable> _variable;
    RelativeData _relativeData;
    Result _result;
};

class Planner2Result : public Result {
  public:
    struct RelativeData {
        double n;
    };
    
    typedef std::pair<std::shared_ptr<const Variable>, std::shared_ptr<const RelativeData>>
        Result;

    explicit Planner2Result(std::shared_ptr<const Variable> variable)
        : _variable(variable) {}
    ~Planner2Result() = default;
    
    void UpdateResult();
    void ClearResult();
    void Variable2Result();
    Result GetResult() const { return _result; }
    
  private:
    std::shared_ptr<const Variable> _variable;
    RelativeData _relativeData;
    Result _result;
};

class Section;

typedef std::pair<std::shared_ptr<const Result>, std::shared_ptr<const Section>>
    PreDependency;
typedef std::shared_ptr<const Section> NextDependency;
typedef std::vector<std::shared_ptr<const PreDependency>> PreSectionDependencies;
typedef std::vector<std::shared_ptr<const NextDependency>> NextSectionDependencies;

class Dependencies {
  public:
    Dependencies() = default;
    ~Dependencies() = default;
    
    void AddDependency(std::shared_ptr<const PreDependency> dependency,
                       std::shared_ptr<PreSectionDependencies> sectionDependencies);
    void AddDependency(std::shared_ptr<const NextDependency> dependency,
                       std::shared_ptr<NextSectionDependencies> sectionDependencies);
};

class Section1PreDependencies : public Dependencies {
  public:
    explicit Section1PreDependencies() {
        // TODO: build _preSectionDependencies
    }
    ~Section1PreDependencies() = default;
    
    PreSectionDependencies GetSectionDependencies() const;
    
 private:
    PreSectionDependencies _preSectionDependencies;
};

class Section1NextDependencies : public Dependencies {
  public:
    explicit Section1NextDependencies() {
        // TODO: build _nextSectionDependencies
    }
    ~Section1NextDependencies() = default;
    
    NextSectionDependencies GetSectionDependencies() const;
    
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
    
    std::shared_ptr<const Dependencies> GetPreDependencies() const;
    std::shared_ptr<const Dependencies> GetNextDependencies() const;
    std::shared_ptr<const Targets> GetTargets() const;
    std::shared_ptr<Constraint> GetConstraint() const;
    std::shared_ptr<Cost> GetCost() const;
        
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
    
    virtual Variable MakePlan() = 0;
    
  protected:
    std::unique_ptr<const Section> _section;
    Variable _variable;  // TODO:
};

class Planner1 : public Planner {
    // TODO:
};

#endif  /* FREAMEWORK_TEMPLATE_HPP */
