#ifndef APP_LAUNCH_PLANNER_HPP
#define APP_LAUNCH_PLANNER_HPP

#include <string>
#include <vector>
#include <map>

namespace applaunch {

struct PainPoint {
    std::string competitor;
    std::string weakness;
    std::string your_fix;
    std::string conversion_boost;
};

struct ValidationResult {
    int target_visitors;
    int clicks_achieved;
    int preorders;
    bool proceed;
};

class AppLaunchPlanner {
private:
    std::vector<std::string> niches_;
    std::vector<PainPoint> pain_points_;
    ValidationResult validation_;

public:
    // Phase 1: Find niche with revenue potential
    void addNiche(const std::string& niche) { niches_.push_back(niche); }
    const std::vector<std::string>& getNiches() const { return niches_; }
    
    // Phase 2: Document competitive weaknesses
    void addPainPoint(const PainPoint& point) { pain_points_.push_back(point); }
    const std::vector<PainPoint>& getPainPoints() const { return pain_points_; }
    
    // Phase 3: Track validation results
    void setValidation(const ValidationResult& result) { validation_ = result; }
    ValidationResult getValidation() const { return validation_; }
    
    // Decision: Can we proceed to Phase 4?
    bool canProceed() const {
        return validation_.proceed && niches_.size() >= 3 && !pain_points_.empty();
    }
};

} // namespace applaunch

#endif // APP_LAUNCH_PLANNER_HPP