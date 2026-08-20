# App Launch Planner - Deployment Instructions

This site is deployed to GitHub Pages. Follow these steps to set up automatic deployment.

## Prerequisites

1. Repository must be named `djphamdev/app-launch-planner` or you must update the workflow
2. GitHub Pages enabled in repository settings

## Setup

### Option 1: Personal Site (Recommended for djphamdev)

Since the repo is under `djphamdev`, GitHub Pages can be a personal site at:
**https://djphamdev.github.io/** (root documents)

Or a project site at:
**https://djphamdev.github.io/app-launch-planner/**

### Option 2: Custom Domain

Add a `CNAME` file:
```
applaunchplanner.com
```

Then configure DNS:
- CNAME record pointing to `djphamdev.github.io`

## Deployment Configuration

The `.github/workflows/deploy.yml` file configures automatic deployment on every push to `main`.

**Important:** You must use the `djphamdev` GitHub token for this to work with your account.

## Manual Deploy (Local Testing)

```bash
# Preview locally
npx serve . -p 3000

# Build and preview
npm run preview
```

## Push to GitHub

```bash
git add -A
git commit -m "Update content"
git push origin main
```

The action will automatically deploy within 30-60 seconds.

## Verification

After first deploy:
1. Go to: https://djphamdev.github.io
2. Homepage should show the App Launch Planner
3. All phases should be reachable

## For DJ Pham (djphamdev) - Using Your Token

Since you're djphamdev, you can authorize this action by:
1. Setting up `secrets.GITHUB_TOKEN` in the repo settings
2. Or replace the workflow to use a personal token

The deployment will work automatically when you push to `main`.