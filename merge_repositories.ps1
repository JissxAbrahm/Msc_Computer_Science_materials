
# ==========================================
# MSC COMPUTER SCIENCE MATERIALS
# GITHUB REPOSITORY CONSOLIDATION
# ==========================================

$Username = "JissxAbrahm"

# Repository names and destination folders
$Repos = @(
    @{ Name = "DS-2"; Path = "C-Programs/DS-2" },
    @{ Name = "DS-3"; Path = "C-Programs/DS-3" },
    @{ Name = "ds-4"; Path = "C-Programs/ds-4" },
    @{ Name = "QUEUE"; Path = "C-Programs/QUEUE" },
    @{ Name = "queue-2"; Path = "C-Programs/queue-2" },
    @{ Name = "queue-3"; Path = "C-Programs/queue-3" },
    @{ Name = "DATA-STRUCTURE"; Path = "C-Programs/DATA-STRUCTURE" },
    @{ Name = "Calculator."; Path = "C-Programs/Calculator." },
    @{ Name = "Calculator"; Path = "C-Programs/Calculator" },
    @{ Name = "blank"; Path = "C-Programs/blank" },
    @{ Name = "SQL---Pgms-Assignments"; Path = "SQL---Pgms-Assignments" },
    @{ Name = "Python-Programs"; Path = "Python-Programs" }
)

# Check destination repository
if (-not (Test-Path ".git")) {
    Write-Host "ERROR: Open the destination repository first!" -ForegroundColor Red
    exit
}

if ((git status --porcelain) -and (git status --porcelain).Count -gt 0) {
    Write-Host "ERROR: Working directory is not clean." -ForegroundColor Red
    exit
}

# Create C-Programs parent directory
New-Item -ItemType Directory -Force -Path "C-Programs" | Out-Null

# Import repositories
foreach ($Repo in $Repos) {

    $Name = $Repo.Name
    $Path = $Repo.Path
    $URL = "https://github.com/$Username/$Name.git"
    $Remote = "source_" + [guid]::NewGuid().ToString("N")

    Write-Host "`n================================" -ForegroundColor Cyan
    Write-Host "IMPORTING: $Name" -ForegroundColor Cyan
    Write-Host "DESTINATION: $Path" -ForegroundColor Cyan
    Write-Host "================================" -ForegroundColor Cyan

    # Fetch source repository
    git remote add $Remote $URL

    git fetch $Remote

    if ($LASTEXITCODE -ne 0) {
        Write-Host "FAILED: Unable to fetch $Name" -ForegroundColor Red
        continue
    }

    # Detect default branch
    $Head = git ls-remote --symref $URL HEAD

    $BranchLine = $Head | Where-Object {
        $_ -match '^ref: refs/heads/'
    } | Select-Object -First 1

    if (-not $BranchLine) {
        Write-Host "FAILED: Default branch not found" -ForegroundColor Red
        continue
    }

    $Branch = ($BranchLine -split '\s+')[1] -replace '^refs/heads/', ''

    # Import repository and preserve history
    git subtree add --prefix="$Path" $Remote $Branch

    if ($LASTEXITCODE -eq 0) {
        Write-Host "SUCCESS: $Name imported!" -ForegroundColor Green
    }
    else {
        Write-Host "FAILED: Subtree import failed for $Name" -ForegroundColor Red
    }
}

Write-Host "`n================================" -ForegroundColor Green
Write-Host "IMPORT PROCESS FINISHED" -ForegroundColor Green
Write-Host "================================" -ForegroundColor Green

git status
