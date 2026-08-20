# AppLaunch Planner

> A comprehensive, local-first app development sherpa platform for iOS/Android indie developers. Built to validate, plan, and launch profitable apps without guessing.

**Live:** https://djphamdev.github.io/app-launch-planner/

---

## 🎯 What This Is

AppLaunch Planner is a **complete offline-first toolkit** that guides you from raw idea → validated concept → launched app. It combines:

1. **4-Phase Framework** - Systematic validation before building
2. **Interactive Calculators** - Market size, unit economics, break-even, ROI
3. **Legal/IP Guide** - Trademark, patents, contracts, App Store compliance
4. **Prompt Engineering** - AI-safe templates with injection defense
5. **Notes & Ideas Platform** - Tagged, searchable, phase-organized research
6. **Idea Validator** - 7-factor scoring algorithm with live feedback
7. **Resource Library** - Curated tools with alternatives for every stage
8. **Collaboration Export** - Share complete research packages with teammates

**All data stays in your browser** (localStorage/IndexedDB). No backend, no accounts, no tracking.

---

## 🚀 Quick Start

```bash
# Clone
git clone https://github.com/djphamdev/app-launch-planner.git
cd app-launch-planner

# Serve locally (for development)
npx serve . -p 3000
# or
python3 -m http.server 3000

# Open http://localhost:3000
```

**Deploy to GitHub Pages:**
1. Push to `main` branch
2. Enable Pages in repo settings: Source = `main` / `/ (root)`
3. Live at `https://djphamdev.github.io/app-launch-planner/`

---

## 📁 Project Structure

```
app-launch-planner/
├── index.html                 # Main hub with phase navigation
├── quick-start.html           # 4-hour fast-track guide
├── app-core.js                # CORE ENGINE (see below)
├── calculators.html           # 6 business calculators
├── legal.html                 # Legal/IP guide with checklists
├── prompts.html               # Prompt engineering + injection defense
├── notes.html                 # Notes/ideas platform with tags
├── validator.html             # 7-factor idea validator
├── resources.html             # Curated resource library
├── execution-log.html         # Project history
├── phases/
│   ├── 1-market-mining.html   # Phase 1 detail
│   ├── 2-competitive-analysis.html
│   ├── 3-pain-point-validation.html
│   └── 4-build-roadmap.html
├── checklists/
│   └── paywall-checklist.md   # Paywall optimization checklist
├── .github/workflows/
│   └── deploy.yml             # GitHub Pages auto-deploy
├── README.md                  # This file
├── DECISION.md                # Architecture decisions
├── DEPLOYMENT.md              # Deployment guide
├── package.json               # Metadata
└── app_launch_planner.hpp     # C++ types (reference)
```

---

## ⚙️ Core Engine: `app-core.js`

The entire platform runs on a single **zero-dependency** JavaScript module loaded on every page.

### StorageManager
```javascript
// Auto-initializes on DOMContentLoaded
AppLaunch.storage.getAll('applaunch_notes')     // → Promise<Note[]>
AppLaunch.storage.set('applaunch_ideas', idea)  // → Promise<bool>
AppLaunch.storage.exportAll()                    // → Full backup object
AppLaunch.storage.importAll(data)                // → Restore from backup
```

**Features:**
- localStorage primary, IndexedDB fallback (larger quotas)
- Auto-migration from legacy keys
- Quota cleanup (keeps 100 most recent per store)
- Full export/import for collaboration

### Data Models
```javascript
// Note - Research notes with phase tagging
new AppLaunch.models.Note({
  title: "Market Research: Fitness",
  content: "# Findings\n...",
  tags: ["fitness", "tam"],
  phase: 1,           // 0=Inbox, 1-4=phases
  pinned: false
})

// Idea - Complete app concept with validation
new AppLaunch.models.Idea({
  title: "StrengthTracker for Teens",
  problem: "Teen athletes...",
  solution: "Age-appropriate tracking...",
  targetAudience: "Teen athletes 13-18...",
  category: "fitness",
  platform: "both",           // ios, android, both
  monetization: "subscription",
  price: 7.99,
  status: "raw",              // raw, validated, building, launched
  score: 72.5,
  validationData: {...},
  calculations: {...}
})

// Validation - Experiment tracking
new AppLaunch.models.Validation({
  ideaId: "uuid",
  type: "landing_page",
  metrics: {visitors: 100, clicks: 8},
  results: {ctr: 0.08},
  decision: "proceed"         // proceed, pivot, kill
})
```

### IdeaValidator (7-Factor Algorithm)
```javascript
const result = AppLaunch.validator.validate(idea);
// Returns:
{
  scores: {
    marketSize: 65,        // 20% weight
    painLevel: 80,         // 25% weight
    competition: 60,       // 15% weight
    monetization: 85,      // 15% weight
    technicalFeasibility: 70, // 10% weight
    legalRisk: 65,         // 5% weight
    differentiation: 75    // 10% weight
  },
  total: 72.3,
  verdict: "🟡 Promising - Validate further",
  recommendation: "Focus on improving: marketSize (score: 65)"
}
```

**Weights are calibrated** from video research: pain level + monetization = 40% of score.

### BusinessCalculator
```javascript
// Market sizing (TAM/SAM/SOM)
AppLaunch.calculator.calculateMarketSize({
  tam: 50_000_000,
  sam: 5_000_000,
  som: 100_000,
  conversionRate: 0.03,
  price: 9.99
})

// Unit economics (LTV/CAC)
AppLaunch.calculator.calculateUnitEconomics({
  price: 4.99,
  churnRate: 0.05,
  cac: 10,
  cogs: 0.50
})

// Break-even analysis
AppLaunch.calculator.calculateBreakEven({
  fixedCosts: 5000,
  price: 4.99,
  variableCost: 0.50,
  monthlyUsers: 500,
  conversionRate: 0.02
})

// ROI projection
AppLaunch.calculator.calculateROI({
  investment: 10000,
  monthlyRevenue: 5000,
  monthlyCosts: 1000,
  months: 18
})
```

### PromptEngine (Injection-Safe)
```javascript
// Sanitize user input before sending to LLM
const safe = AppLaunch.prompts.sanitizeInput(userInput)

// Build structured system prompt
const prompt = AppLaunch.prompts.buildValidationPrompt(idea)

// Get injection defense patterns
const defense = AppLaunch.prompts.buildPromptInjectionDefense()
```

**Defense layers implemented:**
1. Input sanitization (strips ignore/role-change/delimiter patterns)
2. Delimiter isolation (clear [BEGIN USER DATA]/[END USER DATA] boundaries)
3. Output validation (check for instruction following)
4. Rate limiting guidance
5. Audit logging recommendation

### LegalGuide
```javascript
AppLaunch.legal.getTrademarkGuide()   // Classes, filing strategy, strength matrix
AppLaunch.legal.getPatentGuide()      // When to file, costs, trade secret alternative
AppLaunch.legal.getContractsGuide()   // Co-founder, contractor, user agreements, OSS licenses
```

---

## 🗺️ The 4-Phase Framework

### Phase 1: Market Mining (2-4 hrs)
**Goal:** Find 3 niches with $10K+/mo revenue proof
- Tool: AppLaunchPads Tracker
- Action: Search categories → filter $10K+ MRR → read 10 negative reviews each
- Output: "People want X but apps give Y problem"

### Phase 2: Competitive Analysis (2-3 hrs)
**Goal:** Document 3 specific weaknesses to exploit
- Tool: App Store reviews + Sensor Tower/AppTweak
- Action: 50 negative reviews per top 3 competitors → map complaints → design fixes
- Output: Opportunity matrix (Competitor | Weakness | Your Fix | Conversion Boost)

### Phase 3: Pain Point Validation (4-8 hrs)
**Goal:** Prove demand with cash before coding
- Tool: Carrd.co + Stripe Payment Links
- Action: 1-page site → drive 20 targeted visitors → 5%+ CTR or $5 pre-order
- Kill criteria: <2% CTR, 0 pre-orders after 50 visits

### Phase 4: Build Roadmap (7 days)
**Goal:** Ship MVP that converts
- Day 1: Wireframes + stack (SwiftUI/Flutter/React Native)
- Day 2: Architecture + state management
- Day 3: Core feature (problem-solving)
- Day 4: Features 2-3 + error handling
- Day 5: **Paywall integration** (RevenueCat) - critical
- Day 6: Device testing + beta feedback
- Day 7: Store submission

**Paywall Rules (from video research):**
- Show Day 0 (first open)
- iOS: "Continue" button, Android: "Start free trial"
- Copy: "Unlock lifetime insights" > "Get all features"
- Hard paywall OK for fitness/health
- Video on paywall: 2.5% → 4.7% → 6.8% conversion

---

## 💾 Data Persistence

All data stored in browser:

| Key | Content |
|-----|---------|
| `applaunch_notes` | Research notes |
| `applaunch_ideas` | App concepts with scores |
| `applaunch_calculations` | Calculator history |
| `applaunch_prompt_library` | Saved prompt templates |
| `applaunch_validations` | Experiment history |
| `applaunch_legal_checks` | Checklist progress |
| `applaunch_resource_checks` | Resource setup progress |
| `applaunch_settings` | User preferences |

**Export/Import** (for sharing with @thatguyramo25):
```javascript
// In browser console on any page:
const backup = AppLaunch.storage.exportAll();
// Save backup.json → send to teammate

// Teammate imports:
AppLaunch.storage.importAll(backup);
```

---

## 🛠️ Development with Cursor

### Recommended Setup
```json
// .cursorrules or Cursor settings
{
  "model": "claude-3.5-sonnet",
  "rules": [
    "Prefer vanilla JS/HTML/CSS - no build step",
    "All state in localStorage via AppLaunch.storage",
    "New pages: include nav-bar, link to live URL",
    "Calculators: use AppLaunch.calculator.* methods",
    "Forms: auto-save to localStorage on input",
    "No external API calls in core pages"
  ]
}
```

### Adding a New Calculator
1. Add method to `BusinessCalculator` in `app-core.js`
2. Create UI in new `.html` or add to `calculators.html`
3. Call `AppLaunch.calculator.yourMethod(data)`
4. Save with `saveCalc('type', input, result)`

### Adding a New Phase Page
1. Copy `phases/1-market-mining.html` as template
2. Update nav links in all pages
3. Add phase-specific templates to `notes.html` TEMPLATES array
4. Update `resources.html` phase-resources section

### Extending the Validator
```javascript
// In app-core.js, add to IdeaValidator:
static scoreNewFactor(idea) { ... }

// Add to weights object (must sum to 1.0)
// Update validate() to include new factor
```

---

## 🔐 Security & Privacy

- **Zero network requests** in core functionality
- **No analytics, no tracking, no cookies** (except localStorage)
- **CSP-ready**: All inline scripts can be moved to `app-core.js` for strict CSP
- **Input sanitization** on all user-facing text areas
- **Prompt injection defense** built into PromptEngine

---

## 🤝 Collaboration Workflow

```
You (djphamdev)                    Friend (@thatguyramo25)
     │                                    │
     ├─ Research Phase 1-2 ──────────────►│
     │  (notes, ideas, validations)       │
     │                                    │
     ├─ Export Package (backup.json) ────►│
     │                                    ├─ Import → sees all your research
     │                                    ├─ Adds competitive analysis
     │                                    ├─ Runs own validations
     │                                    │
     │◄──── Export Package (backup.json) ──┤
     │                                    │
     ├─ Merge insights ──────────────────►│
     │  (manual diff or re-import)        │
     │                                    │
     └─ Both build Phase 4 together ─────►│
        (separate repos, shared validator)
```

---

## 📋 Checklist for New Projects

Before starting a new app idea:
- [ ] Create new note in **Notes** (Phase 1)
- [ ] Run **Market Size** calculator with TAM/SAM/SOM
- [ ] Run **Unit Economics** with realistic CAC/churn
- [ ] Fill **Legal Checklist** (trademark search, compliance)
- [ ] Build **Validation Prompt** in Prompt Builder
- [ ] Save idea in **Validator** with score
- [ ] If score ≥ 60: proceed to landing page test
- [ ] Export package for teammate review

---

## 📚 Key References (Video Sources)

| Video | Key Insights Applied |
|-------|---------------------|
| [Paywall Strategies](https://youtu.be/vZXn_BSi5AE) | Hard paywalls, Day 0 conversion, "Unlock lifetime insights" copy, iOS/Android button text, video on paywall |
| [App Validation](https://youtu.be/eVrUkmE-j7g) | Market-first approach, negative review mining, niche over broad, validation before build, TAM/SAM/SOM |

---

## 🧭 Philosophy

> **"Users aren't looking for something completely new. They're looking for something that solves the problem better."**

> **"Building an app is usually the most expensive part of the process."**

> **"Smaller niches are often a smarter place to start."**

This platform exists to make those principles actionable. Every calculator, checklist, and template is designed to **reduce the cost of being wrong** and **increase the probability of building something people pay for**.

---

## 📄 License

MIT - Use freely for your own app ventures.

---

## 🙏 Credits

Built with insights from:
- **Steve P. Young / App Masters** - Paywall conversion data
- **App Launchpad** - Market validation methodology
- **RevenueCat** - Subscription benchmarks
- **Indie Hackers community** - Real founder data

**Made for builders, by a builder.** 

---

*Last updated: 2026-08-19 | Version 2.0*