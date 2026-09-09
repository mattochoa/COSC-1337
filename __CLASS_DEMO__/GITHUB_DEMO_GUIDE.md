# COSC-1337 GitHub Repository Setup & Workflow

---

## Demo Materials

My repository includes a small `__CLASS_DEMO__` folder containing supporting references for the walkthrough:

- [`Git Command Cheat Sheet`](__CLASS_DEMO__/cheat-sheet.pdf)
      - These are cli commands if you aren't using the desktop app
- [`ACC — Git Version Control`](__CLASS_DEMO__/versioncontrol.pdf)
      - These are the ACC official standards for CompSci lab publication according to [Alexander Katrompas, PHD](https://katrompas.accprofessors.com/programming-fundamentals), a professor here at ACC.



---

# Walkthrough Objectives

By the end of this walkthrough, you should understand how to:

1. Create your own `COSC-1337` GitHub repository.
2. Clone the repository **inside your existing local COSC-1337 course directory**.
3. Separate **source files**, **working files**, **final files**, and **published files**.
4. Add completed lab files to the repository.
5. Maintain a navigable `README.md`.
6. **Commit** your changes locally.
7. **Push** those commits to GitHub.
8. Verify that the submitted version actually exists online.

---

## The two Git concepts that matter most

| Action | What it does | Where the change exists afterward |
|---|---|---|
| **Commit** | Records a snapshot of your repository changes in Git. | Your **local repository** |
| **Push** | Sends your local commits to the remote GitHub repository. | **GitHub.com** |

A commit that has **NOT** been pushed **EXISTS ONLY** on your computer.

> Before an assignment is considered safely published, verify that the completed files are **visible on GitHub.com!**

---

# 1. Recommended Course Folder Structure

This is my personal file and folder heirarchy and mapping I use for this class:

```text
<YOUR COSC-1337 PC/MAC COURSE DIRECTORY>/
│
├── 0_CLASS_FILES/
│   └── Non-lab course files, references, notes, etc.
│
├── 1_GITHUB/
│   └── COSC-1337/                  ← cloned Git repository
│       ├── README.md               ← index of published labs
│       └── Labs/                   ← published coursework
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

If your existing course directory uses different names, that is fine. The important separation is:

```text
COURSE DIRECTORY
├── Git repository
└── Project development workspace
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

- Keep it inside your existing course directory.
- Publish only the files you intend to submit or preserve in the course repository.
- Give each lab its own folder under `Labs/`.

---

# 2. One-Time Repository Setup

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

## D. Clone the repository into your existing course directory

This is the location step to pay attention to during the demo.

Before cloning, locate your **existing local COSC-1337 course directory**.

Inside it, create or select a GitHub subfolder such as:

```text
<YOUR COURSE DIRECTORY>/1_GITHUB/
```

Then, in GitHub Desktop:

1. Select **File → Clone repository**.
2. Select your `COSC-1337` repository.
3. Set the **Local path** so the repository will be created inside your existing course directory.
___
#### IMPORTANT
4. A recommended result is:

```text
<YOUR COURSE DIRECTORY>/1_GITHUB/COSC-1337/
```

5. Confirm that you are **not** cloning the repository to an unrelated location such as `Downloads`, the desktop, or a second duplicate course directory like:
      
      <small><em>YOUR COURSE DIRECTORY/1_GITHUB/COSC-1337/**COSC-1337/ <<**</em></small>
______

6. Select **Clone**.

You now have:

```text
GitHub.com repository
        ↕
<existing course directory>/1_GITHUB/COSC-1337/
```

The local repository folder is where Git tracks repository changes. GitHub Desktop is the interface you will use here to commit, push, pull, and fetch.

---

# 3. Understand the Showcase Repository

The class demonstration repository contains three distinct kinds of material:

```text
COSC-1337/
│
├── Labs/                            ← published coursework
|    └── 00__U2_1.2/
|        ├── ochoa_Unit2laba.cpp
|        └── ochoa_Unit2laba_IPO.pdf
|
└── README.md                        ← index of published labs
```

Keep these roles separate:

| Location | Purpose |
|---|---|
| `README.md` | Acts as the repository's lab index |
| `Labs/` | Stores published lab deliverables |

---

# 4. Create Your Repository Structure

Inside your cloned `COSC-1337` repository, the minimum course structure is:

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
2_PROJECTS/U2_lab_1.2/2_FINALS/<COPY-FILES>
        ↓
1_GITHUB/COSC-1337/Labs/00__U2_1.2/<PASTE-FILES>
```

At this point, GitHub Desktop should detect the newly added or modified files automatically.

---

# 6. Maintain `README.md`

The root `README.md` acts as the **index for the repository**.

A simple format is:

```md
# COSC-1337
## Programming Fundamentals II Lab Projects

- [yourLabName](your GitHub permalink)
```

Rendered on GitHub, this gives you a clickable list of your lab submissions.

### GitHub permalink

A permalink points to a specific commit/version of a file.

```md
- [Unit 2 Lab A (1.2)](https://github.com/mattochoa/COSC-1337/blob/1ca724957c0aef0ac4976ce7fad4bff7759683e9/Labs/00__U2_1.2/ochoa_Unit2laba.cpp)
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

Open your repository on GitHub.com and confirm. If the files are not visible on GitHub.com, your submission is not fully published yet.

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

### Cloning outside your existing course directory

Do not scatter course work across unrelated locations.

Prefer:

```text
<YOUR EXISTING COURSE DIRECTORY>/1_GITHUB/COSC-1337/
```

rather than creating another course folder elsewhere on your computer.

---

### Committing but forgetting to push

**Commit** records the version locally.  
**Push** publishes the commit to GitHub.

If you only committed, GitHub.com may still be missing your newest work.

---

# Reference Materials

### Local demo copies

- [Git Command Cheat Sheet](__CLASS_DEMO__/cheat-sheet.pdf)
- [ACC — Katrompas, *Git Version Control*](__CLASS_DEMO__/versioncontrol.pdf)

### Online resources

**GitHub Desktop**  
https://desktop.github.com/download/

**GitHub Desktop Documentation**  
https://docs.github.com/en/desktop

**Git Command Cheat Sheet**  
https://git-scm.com/cheat-sheet.pdf

**ACC — Katrompas, _Git Version Control_**  
https://katrompas.accprofessors.com/assets/docs/versioncontrol.pdf

**Showcase Repository**  
https://github.com/mattochoa/COSC-1337