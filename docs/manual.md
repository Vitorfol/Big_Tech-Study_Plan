# 00 — Big Tech Prep Operations Manual

Status: living but stable document  
Function: system guide/base/bible  
Standard cadence: 8h/week  
Unit: 1 quarter = 45 minutes  
Standard week: 10 fixed quarters on weekdays + 0.5–1 quarter of buffer on the weekend  

---

## 1. Purpose

This manual defines the preparation system for Big Tech interviews.

The goal is not to study sporadically or merely solve LeetCode problems. The goal is to maintain a long-term system that develops:

1. Coding / Data Structures / Algorithms
2. System Design
3. Mock / Interview / Career readiness

This document changes very little. It explains **how the system works**.  
Cycles change. They explain **what to study during a specific period**.

---

## 2. Document Structure

```text
docs/manual.md
    Stable system foundation.

docs/cycle_template.md
    Copyable template for building 4-week cycles.

cycles/
    Directory with real cycle instances.
    Example: 0.md, 1.md, 2.md

docs/contents.md
    Living list of content studied, organized by track, status, and last review.

code/lc/
    LeetCode and interview problems.

code/study/
    Experiments, implementations, prototypes and deeper explorations.

prompts/
    Prompt files used to distinct agents.
```

Practical rule:

- The **manual** changes very little.
- The **cycle template** changes rarely.
- The **cycle_X.md** changes every cycle.
- The **content tracker** changes constantly.

> Suggestion (not yet adopted): the mistake log, System Design notes, and behavioral story bank are currently referenced conceptually (see Sections 5, 10) but have no dedicated file. If mistake tracking, SD notes, or STAR/CARL stories grow enough to need their own space, consider adding:
> - `docs/mistake_log.md` — recurring mistakes across cycles.
> - `docs/system_design_notes.md` — accumulated System Design notes.
> - `docs/behavioral_story_bank.md` — STAR/CARL story bank.
> Until then, this content lives inside cycle files and contents.md.

---

## 3. Time Model

```text
1 quarter = 45 minutes
2 quarters = 1 weekday session = 1h30
5 weekdays = 10 quarters
weekend = 0.5–1 quarter of buffer
```

The weekend buffer is not a mandatory sixth day. It exists to finish notes, review mistakes, complete pending work, and prepare for the next week.

---

## 4. Tracks

### 4.1 Coding / DS

Primary track.

Includes:
- data structures;
- algorithms;
- coding interview patterns;
- C++ implementation;
- problem solving;
- review;
- mistake tracking;
- timed coding performance.

Typical resources:
- Grind 75;
- NeetCode 150;
- Blind 75;
- LeetCode;
- Coding Interview University;
- Cracking the Coding Interview;
- cppreference / C++ documentation when necessary.

### 4.2 System Design

Secondary but continuous track.

Includes:
- architecture fundamentals;
- scalability;
- trade-offs;
- conceptual reading;
- guided questions;
- mini designs;
- oral explanation.

Typical resources:
- System Design Primer;
- Tech Interview Handbook;
- personal notes;
- personal diagrams.

### 4.3 Mock / Interview / Career

Flexible track.

Includes:
- behavioral;
- STAR/CARL;
- resume;
- LinkedIn;
- application strategy;
- referrals;
- company research;
- mock coding;
- mock behavioral;
- interview communication.

This track should adapt to the current situation.

---

## 5. Modes

A mode defines the type of work done in a quarter.

### 5.1 Coding / DS

General flow:

```text
Reading → Pattern → Practice → Performance → Review
```

#### Reading Mode

Objective:
- refresh theory;
- understand a pattern;
- reduce a conceptual gap.

Use:
- when starting a new topic;
- when the topic is rusty;
- when repeated mistakes indicate a lack of understanding.

Rule:
Every new topic starts with reading/refresh. If the topic is strong, it can be brief: 10–15 minutes.

#### Pattern Mode

Objective:
- identify the central pattern;
- define when to use it;
- write a compact note.

Output:
- pattern;
- recognition signals;
- common pitfalls.

#### Topic Practice Mode

Objective:
- solve problems from the week's main topic.

Output:
- solved problem;
- C++ implementation;
- complexity;
- recorded mistake, if any.

#### List Progression Mode

Objective:
- progress through a general curated list.

Use:
- when the week's topic should not be the only focus;
- to practice mixed recognition;
- to measure overall progress.

#### Coding Performance Mode

Objective:
- simulate interview pressure.

Rules:
- choose a problem;
- set a 35–45 minute timer;
- explain the reasoning out loud;
- do not open a hint too early;
- review afterward.

#### Review / Mistake Log Mode

Objective:
- consolidate learning;
- prevent repeated mistakes.

#### C++ Interview Skills Mode

Objective:
- improve C++ implementation fluency.

Topics:
- STL containers;
- iterators;
- sorting and custom comparators;
- priority_queue;
- unordered_map/set;
- graph representation;
- BFS/DFS templates;
- recursion;
- overflow;
- references/copies.

### 5.2 System Design

General flow:

```text
Reading → Guided Questions → Mini Design → Trade-offs → Review
```

#### Reading / Concept Study Mode

Objective:
- study an architecture concept.

Exemplos:
- APIs;
- HTTP;
- cache;
- load balancer;
- database indexes;
- queues;
- replication;
- sharding;
- consistency;
- rate limiting;
- observability.

#### Guided Questions Mode

Objective:
- turn reading into decisions.

Typical questions:

```text
- What problem does this solve?
- Where would I use it?
- When would I not use it?
- What trade-off appears?
- What breaks?
- What would I choose in a simple system?
```

This mode is especially important at the beginning. It prevents memorizing designs without understanding the decisions.

#### Mini Design Mode

Objective:
- apply concepts to a small system.

Exemplos:
- URL shortener;
- rate limiter;
- notification service;
- file upload service;
- simple chat;
- simple feed;
- logging/monitoring pipeline.

#### Trade-off Review Mode

Objective:
- compare choices and justify decisions.

#### Explanation Mode

Objective:
- explain the design orally.

Output:
- 5-minute explanation;
- trade-offs;
- bottlenecks;
- failure modes.

### 5.3 Mock / Interview / Career

Modes:
- Behavioral Story Mode;
- Resume / CV Mode;
- Company / Role Research Mode;
- Mock Coding Mode;
- Mock Behavioral Mode.

The Mock/Career track is flexible: during an application-focused week, the resume and job openings may take priority; during an interview week, mocks may take priority.

---

## 6. Weekly Allocation

### Week A — Coding-heavy

```text
Coding / DS: 8 quarters
System Design: 2 quarters
Mock / Career: 0 quarters
Buffer: 0.5–1 quarter
```

### Week B — With Mock/Career

```text
Coding / DS: 7 quarters
System Design: 2 quarters
Mock / Career: 1 quarter
Buffer: 0.5–1 quarter
```

---

## 7. Topic Selection

At the beginning of each week, define:

```text
Main topic:
Maintenance topic:
List base:
System Design topic:
Mock/Career focus:
Minimum outputs:
Good outputs:
Excellent outputs:
```

### Main Topic

Receives most of the Coding/DS energy.

Choose based on:
1. known weakness;
2. importance for interviews;
3. recent mistake log;
4. review from the previous cycle;
5. upcoming interview/application.

### Maintenance Topic

Keeps strong topics alive.

Exemplos:
- Arrays & Hashing;
- Binary Search;
- Two Pointers;
- Sliding Window.

### List Base

Choose one main list per cycle.

Recommended order:
1. Grind 75 / Blind 75;
2. NeetCode 150;
3. LeetCode Top Interview 150;
4. NeetCode 250.

---

## 8. Initial Coding / DS Roadmap

```text
0. Diagnostic: Arrays & Hashing, Two Pointers, Sliding Window, Binary Search
1. Trees / DFS / BFS
2. Graphs / BFS / DFS
3. Stack
4. Heap / Priority Queue
5. Backtracking
6. Dynamic Programming 1D
7. Dynamic Programming 2D
8. Greedy
9. Intervals
10. Linked List
11. Tries
12. Mixed practice and performance
```

### Status by topic

```text
Red:
- needs to see the solution early;
- does not recognize the pattern;
- implementation frequently breaks.

Yellow:
- recognizes the pattern;
- solves with difficulty;
- makes mistakes with edge cases or implementation.

Green:
- solves medium problems alone;
- explains the solution;
- implements in C++ confidently.

Blue:
- solves under time pressure;
- recognizes variations;
- can teach the pattern.
```

Move on when the topic is at least Green for the current level.

---

## 9. Session Flow

### Coding / DS

```text
1. Identify the topic and mode.
2. Do reading/refresh if it is a new or weak topic.
3. Solve or implement.
4. Review.
5. Record the output.
```

### System Design

At the beginning of a topic:

```text
Quarter 1:
- reading/concept study
- notes

Quarter 2:
- guided questions
- small decisions
- notes
```

When there is already sufficient familiarity:

```text
Quarter 1:
- mini design
- components

Quarter 2:
- trade-offs
- failure modes
- oral explanation
```

### Mock / Career

Choose one output:
- a STAR/CARL story;
- a resume section;
- a mock response;
- a job/company analysis;
- a referral/application plan;
- a coding mock.

---

## 10. Output Tracking

### Coding / DS

```text
Problem:
Source:
Topic:
Difficulty:
Mode:
Time:
Solved alone? Yes/No
Main idea:
Complexity:
Mistake:
What should I recognize next time?
Review date:
Status: Red / Yellow / Green / Blue
```

### System Design

```text
Topic:
Concepts studied:
Guided questions answered:
Mini design:
Main components:
Trade-offs:
Bottlenecks:
Failure modes:
What I could not explain well:
Next review:
```

### Mock / Career

```text
Mode:
Target:
Output produced:
Feedback:
Next action:
```

---

## 11. Weekly Quality Levels

| Track | Minimum | Acceptable | Good | Excellent |
|---|---|---|---|---|
| Overall | 6 real hours, 3 coding problems, some tracking | 8h, 4–5 coding problems, 1 SD block | 8h, 5–6 coding problems, 1 applied design, review | 8h+, 7+ problems, 1 timed problem, 1 strong output |
| Coding / DS | 3 problems in C++ + 1 review | 4–5 problems + mistake log | 6 problems + 1 timed problem + 1 repeated problem | 7–8 problems + complete review |
| System Design | 45 min concept study | 1h30 with notes | concept + guided questions or mini design | mini design + oral explanation + trade-offs |
| Mock / Career | 30–45 min every two weeks | 1 concrete output | 1 STAR/CARL story, resume edit, or analysis | mock + feedback + documented improvement |

---

## 12. System Rules

```text
1. Lists guide practice; they do not replace reasoning.
2. CIU/CTCI are used for theory and gaps, not as an endless queue.
3. Every new topic starts with a short reading/refresh.
4. Code is the main driver of progress in Coding/DS.
5. System Design starts early, but carries less weight than Coding/DS.
6. System Design progresses from Reading to Guided Questions before Mini Design.
7. Mock/Career adapts to the current situation.
8. Repetition is expected and should be documented.
9. A topic advances when it reaches Green, not when it merely feels familiar.
10. The weekend buffer is for cleanup, not guilt.
11. Outputs matter more than logged hours.
```
