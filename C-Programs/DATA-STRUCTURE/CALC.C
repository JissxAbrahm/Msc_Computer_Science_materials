import os
from github import Github, GithubException

# 1. Retrieve the token from environment variables
token = os.getenv("GITHUB_TOKEN")

if not token:
    raise ValueError("Error: GITHUB_TOKEN environment variable is missing.")

# 2. Authenticate with GitHub
g = Github(token)
user = g.get_user()

try:
    # 3. Create a public repository with a description
    repo = user.create_repo(
        name="automated-demo-repo",
        description="Public repository created via automated Python script.",
        private=False  # Sets visibility to public
    )
    print(f"Successfully created public repository: {repo.html_url}")

    # 4. Generate directory structure and upload a file
    # Folders (e.g., 'src/utils/') are created automatically by defining the path
    repo.create_file(
        path="src/utils/config.py",
        message="Initial upload: Add config file",
        content="# Auto-generated configuration file\nAPI_ENV = 'production'\n",
        branch="main"
    )
    print("File successfully uploaded into directory: src/utils/config.py")

except GithubException as e:
    print(f"GitHub API Error: {e.status} - {e.data.get('message')}")
