#include "app_launch_planner.hpp"
#include <iostream>
#include <iomanip>

void printPhase1Checklist() {
    std::cout << "\n=== Phase 1: Market Mining Checklist ===" << std::endl;
    std::cout << "☐ Visit AppLaunchPads - search Fitness, Finance, Productivity" << std::endl;
    std::cout << "☐ Identify 3 categories with $10K+/month revenue potential" << std::endl;
    std::cout << "☐ Read 10 negative reviews per top 3 apps in each category" << std::endl;
    std::cout << "☐ Document: 'People want X but apps give Y problem'" << std::endl;
}

void printPhase2Template() {
    std::cout << "\n=== Phase 2: Competitive Analysis Template ===" << std::endl;
    std::cout << "| Competitor | Weakness | Your Fix | Conversion Boost |" << std::endl;
    std::cout << "|------------|----------|----------|------------------|" << std::endl;
    std::cout << "| App A      |          |          |                  |" << std::endl;
    std::cout << "| App B      |          |          |                  |" << std::endl;
    std::cout << "| App C      |          |          |                  |" << std::endl;
}

void printPaywallChecklist() {
    std::cout << "\n=== Critical: Paywall Configuration ===" << std::endl;
    std::cout << "☐ RevenueCat integrated with test API keys" << std::endl;
    std::cout << "☐ Paywall shown on Day 0 (first open)" << std::endl;
    std::cout << "☐ iOS: 'Continue' button (not 'Start Free Trial')" << std::endl;
    std::cout << "☐ Android: 'Start Free Trial' button" << std::endl;
    std::cout << "☐ Copy: 'Unlock lifetime insights' NOT 'Get all features'" << std::endl;
    std::cout << "☐ Include video or visual before/after" << std::endl;
    std::cout << "☐ Social proof: 'Join 10,000+ users'" << std::endl;
}

void printBuildTimeline() {
    std::cout << "\n=== 7-Day Build Timeline ===" << std::endl;
    std::cout << "Day 1: Wireframes + Tech Stack (React Native/Flutter)" << std::endl;
    std::cout << "Day 2: Core Architecture + State Management" << std::endl;
    std::cout << "Day 3: Feature #1 (core problem solve)" << std::endl;
    std::cout << "Day 4: Features #2-3 + Error Handling" << std::endl;
    std::cout << "Day 5: Paywall Integration + Testing" << std::endl;
    std::cout << "Day 6: Device Testing + Beta Feedback" << std::endl;
    std::cout << "Day 7: Store Submission + Assets" << std::endl;
}

int main() {
    applaunch::AppLaunchPlanner planner;
    
    std::cout << "========================================" << std::endl;
    std::cout << "   APP LAUNCH PLANNER EXECUTOR v1.0" << std::cout;
    std::cout << "========================================" << std::endl;
    
    std::cout << "\n🎯 Goal: Build profitable apps in 7 days, not months" << std::endl;
    
    printPhase1Checklist();
    printPhase2Template();
    printPaywallChecklist();
    printBuildTimeline();
    
    std::cout << "\n=== Next Steps ===" << std::endl;
    std::cout << "1. Run Phase 1: ./applaunch --phase 1" << std::endl;
    std::cout << "2. Document pain points in /data/pain_points.csv" << std::endl;
    std::cout << "3. Build landing page: npx create-carrd my-app < 30min" << std::endl;
    std::cout << "4. Validate: 5%+ CTR or $5 pre-order" << std::endl;
    std::cout << "\n✓ Ready to build when validation succeeds" << std::endl;
    
    return 0;
}