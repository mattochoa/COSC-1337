# COSC-1337 GitHub Repository Setup & Workflow

> **In-Class Showcase + Student Quick Reference**  
> A single-stop guide for setting up, organizing, publishing, and maintaining COSC-1337 lab work with GitHub and GitHub Desktop.

**Example repository:** https://github.com/mattochoa/COSC-1337

---

## Demo Goal

By the end of this walkthrough, you should understand how to:

1. Create your own `COSC-1337` GitHub repository.
2. Clone it to your computer with GitHub Desktop.
3. Separate **source files**, **working files**, **final files**, and **published files**.
4. Add completed lab files to the repository.
5. Maintain a navigable `README.md`.
6. **Commit** your changes locally.
7. **Push** those commits to GitHub.
8. Verify that the submitted version actually exists online.

> **Important:** My repository is the example. For your own coursework, create and publish to **your own repository**. You can clone my public repository as a reference copy, but you cannot push changes back to it without repository permissions.

---

# 1. Understand the Workflow First

The entire system can be reduced to one pipeline:

```text
Instructor Files
      ↓
0_IMPORT
(source copy — leave unchanged)
      ↓ copy
1_WORKING
(active development copy)
      ↓ when complete
2_FINALS
(finalized local copy)
      ↓ copy
GitHub Repo / Labs / <Lab Folder>
(published course copy)
      ↓
COMMIT
(record the change locally)
      ↓
PUSH
(send the commit to GitHub.com)
```

### The two Git concepts that matter most

| Action | What it does | Where the change exists afterward |
|---|---|---|
| **Commit** | Records a snapshot of your repository changes in Git. | Your **local repository** |
| **Push** | Sends your local commits to the remote GitHub repository. | **GitHub.com** |

A commit that has **not** been pushed still exists only on your computer.

> Before an assignment is considered safely published, verify that the completed files are **committed, pushed, and visible on GitHub.com**.

---

# 2. Recommended Course Folder Structure

Keep your development workspace separate from the repository you publish.

```text
Programming Fundamentals II/
│
├── 0_CLASS_FILES/
│   └── Non-lab course files, references, notes, etc.
│
├── 1_GITHUB/
│   └── COSC-1337/                  ← cloned Git repository
│       ├── README.md
│       └── Labs/
│           └── 00__U2_1.2/
│               ├── ochoa_Unit2laba.cpp
│               └── ochoa_Unit2laba_IPO.pdf
│
└── 2_PROJECTS/
    └── U2_lab_1.2/
        ├── 0_IMPORT/               ← instructor/source copy
        ├── 1_WORKING/              ← files actively being edited
        └── 2_FINALS/               ← completed local version
```

## Why separate these folders?

### `0_IMPORT`
Store the original files supplied by the instructor.

- Treat these as your **source/reference copy**.
- Do not develop directly inside this folder.
- Copy the files into `1_WORKING` before editing them.

### `1_WORKING`
This is your active development workspace.

- Write and test your program here.
- Make revisions here.
- Continue working here until the lab is complete.

### `2_FINALS`
Store the version you consider complete.

- Copy the finished project here.
- Perform your final review here.
- This becomes the source for the version you publish to GitHub.

### `1_GITHUB/COSC-1337`
This is the local clone of your GitHub repository.

- Publish only the files you intend to submit or preserve in the course repository.
- Each lab gets its own folder under `Labs/`.

---

# 3. One-Time Repository Setup

## A. Create the remote repository

1. Sign in to **GitHub.com**.
2. Create a new repository.
3. Name it:

```text
COSC-1337
```

4. Finish creating the repository.

---

## B. Install GitHub Desktop

Download GitHub Desktop:

https://desktop.github.com/download/

Official documentation:

https://docs.github.com/en/desktop

> GitHub Desktop is officially supported on **Windows and macOS**. Linux users should use Git from the terminal or another instructor-approved Git client.

---

## C. Sign in to GitHub Desktop

1. Open **GitHub Desktop**.
2. Sign in to your GitHub account.
3. Complete the browser authentication when prompted.

---

## D. Clone your repository

In GitHub Desktop:

1. Select **File → Clone repository**.
2. Select your `COSC-1337` repository.
3. For the local path, select your `1_GITHUB` folder.
4. GitHub Desktop will normally create the repository folder beneath it:

```text
1_GITHUB/COSC-1337/
```

5. Select **Clone**.

You now have:

```text
GitHub.com repository
        ↕
local COSC-1337 repository
```

The local folder is where you make repository changes. GitHub Desktop synchronizes those changes with GitHub through commits, pushes, pulls, and fetches.

---

# 4. Create the Repository Structure

Inside the cloned `COSC-1337` repository, use this basic structure:

```text
COSC-1337/
├── README.md
└── Labs/
    └── <individual lab folder>/
```

Example from the showcase repository:

```text
COSC-1337/
├── README.md
└── Labs/
    └── 00__U2_1.2/
        ├── ochoa_Unit2laba.cpp
        └── ochoa_Unit2laba_IPO.pdf
```

For each lab, include the files required for that project—for example:

- `.cpp` source files
- additional required project files
- scanned or photographed handwritten work
- assignment documentation or PDFs when required

---

# 5. Publish a Completed Lab

When a lab is finished:

### Step 1 — Finish the working version

```text
2_PROJECTS/<Lab>/1_WORKING/
```

### Step 2 — Copy the completed version into

```text
2_PROJECTS/<Lab>/2_FINALS/
```

### Step 3 — Copy the final submission files into

```text
1_GITHUB/COSC-1337/Labs/<Lab Folder>/
```

Example:

```text
2_PROJECTS/U2_lab_1.2/2_FINALS/
        ↓
1_GITHUB/COSC-1337/Labs/00__U2_1.2/
```

At this point, GitHub Desktop should detect the newly added or modified files automatically.

---

# 6. Maintain `README.md`

The root `README.md` acts as the **index for the repository**.

A simple format is:

```md
# COSC-1337
## Programming Fundamentals II Lab Projects

- [Unit 2 Lab A (1.2)](Labs/00__U2_1.2/ochoa_Unit2laba.cpp)
```

Rendered on GitHub, this gives you a clickable list of your lab submissions.

## Relative link vs. permalink

### Relative link

```md
[Unit 2 Lab A (1.2)](Labs/00__U2_1.2/ochoa_Unit2laba.cpp)
```

Use this when you want the link to follow the current version of the file in the repository.

### GitHub permalink

A permalink points to a specific commit/version of a file.

```md
[Unit 2 Lab A (1.2)](<your GitHub permalink>)
```

Use this when you need the link to remain fixed to the exact submitted version.

To obtain one on GitHub.com:

1. Open the file or lab folder.
2. Use GitHub's **Copy permalink** option.
3. Paste the resulting URL into your Markdown link.

> The showcase repository currently uses a commit-specific permalink in its README.

---

# 7. Commit the Changes

Open **GitHub Desktop** after adding your lab files.

The **Changes** panel should show the files you added or modified.

## Write a useful commit message

A commit message should describe what changed.

Good examples:

```text
Add Unit 2 Lab A final files
```

```text
Update README with Unit 2 Lab A link
```

For the first repository setup:

```text
Initial COSC-1337 repository setup
```

Then select:

```text
Commit to main
```

### What just happened?

Git recorded those changes in the history of your **local repository**.

They are **not necessarily on GitHub.com yet**.

---

# 8. Push the Commit to GitHub

After committing, select:

```text
Push origin
```

GitHub Desktop sends your local commit(s) to the remote repository on GitHub.com.

The relationship is:

```text
FILES CHANGED
      ↓
COMMIT TO MAIN
      ↓
local Git history updated
      ↓
PUSH ORIGIN
      ↓
GitHub.com updated
```

---

# 9. Verify the Published Version

Do not stop at **Commit** or **Push**. Verify the result.

Open your repository on GitHub.com and confirm:

- [ ] The lab folder exists under `Labs/`.
- [ ] The correct `.cpp` file is present.
- [ ] Any required PDF, image, or supporting files are present.
- [ ] The files open correctly.
- [ ] `README.md` contains the new lab entry.
- [ ] The README link opens the intended file/folder.
- [ ] The newest commit is visible on GitHub.

If the files are not visible on GitHub.com, your submission is not fully published yet.

---

# 10. Repeat This Process for Every Lab

After the one-time repository setup, the recurring workflow is short:

```text
IMPORT
  ↓
WORK
  ↓
FINALIZE
  ↓
COPY TO Labs/
  ↓
UPDATE README
  ↓
COMMIT
  ↓
PUSH
  ↓
VERIFY ON GITHUB.COM
```

That is the complete course workflow.

---

# Common Mistakes

### Committing but forgetting to push

**Commit** records the version locally.  
**Push** publishes the commit to GitHub.

If you only committed, GitHub.com may still be missing your newest work.

---

### Editing the instructor/source copy

Keep `0_IMPORT` unchanged so you always retain the original files.

Develop from the copy in `1_WORKING`.

---

### Publishing the working folder instead of the final version

Your GitHub `Labs/` folder should receive the version from `2_FINALS`, not unfinished development files from `1_WORKING`.

---

### Putting the Git repository inside the project workspace

Keep these concepts separate:

```text
2_PROJECTS = development workspace
1_GITHUB   = publication/version-control workspace
```

---

### Copying another student's repository as your submission repository

A public repository can be cloned for reference, but cloning it does **not** give you permission to push to the original repository.

For coursework, publish your work to a repository owned by your own GitHub account unless your instructor directs otherwise.

---

# Quick Demo Checklist

Use this during the in-class walkthrough.

### One-time setup

- [ ] Sign in to GitHub.
- [ ] Create `COSC-1337` repository.
- [ ] Install/sign in to GitHub Desktop.
- [ ] Clone repository into `1_GITHUB/`.
- [ ] Create `Labs/`.
- [ ] Create or update `README.md`.

### Demonstrate one lab

- [ ] Show `0_IMPORT`.
- [ ] Show `1_WORKING`.
- [ ] Show `2_FINALS`.
- [ ] Copy the final lab into `COSC-1337/Labs/<Lab>/`.
- [ ] Add the lab to `README.md`.
- [ ] Open GitHub Desktop and show detected changes.
- [ ] Enter a commit message.
- [ ] **Commit to main**.
- [ ] **Push origin**.
- [ ] Open GitHub.com and verify the files.
- [ ] Click the README lab link to prove navigation works.

---

# Reference Links

### GitHub Desktop
https://desktop.github.com/download/

### GitHub Desktop Documentation
https://docs.github.com/en/desktop

### Git Command Cheat Sheet
https://git-scm.com/cheat-sheet.pdf

### ACC — Katrompas, *Git Version Control*
https://katrompas.accprofessors.com/assets/docs/versioncontrol.pdf

### Showcase Repository
https://github.com/mattochoa/COSC-1337

---

## Final Mental Model

```text
YOUR PROJECT FOLDERS
are where you DEVELOP.

YOUR LOCAL GIT REPOSITORY
is where you PREPARE AND RECORD published versions.

GITHUB.COM
is the REMOTE copy that others can access.

COMMIT
records repository history locally.

PUSH
publishes that committed history to GitHub.
```

**Development → Finalization → Repository → Commit → Push → Verify**
