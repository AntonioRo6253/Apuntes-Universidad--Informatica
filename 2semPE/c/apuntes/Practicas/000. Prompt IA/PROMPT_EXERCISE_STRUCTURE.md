# Practice Exercise Authoring Prompt (Template & Structure Guide)

Use this prompt whenever you create a new practice exercise inside the `Practicas` collection. It standardizes clarity, pedagogy, and consistency across all topics (Variables, Operators, Conditionals, Loops, Arrays, Functions, Pointers, Dynamic Memory, Recursion, Debugging, etc.).

---
## 1. Metadata Block (YAML Front Matter)
Place at the top of the exercise `README.md`.
```yaml
title: <Short Descriptive Title>
topic: <Main Topic Category>
subtopics: [list, of, secondary, ideas]
difficulty: beginner | easy | medium | hard | challenge
estimated_time: <minutes>
prerequisites: [links / prior exercises]
learning_mode: concept | guided | project | challenge
author: <Your Name>
version: 1.0
last_update: YYYY-MM-DD
```

---
## 2. Overview
A concise paragraph (3–5 lines) explaining the real-world motivation or conceptual value.

---
## 3. Learning Objectives (Action Verbs)
List 3–6 measurable outcomes starting with verbs. Example:
- Understand how to declare and initialize arrays in C.
- Apply pointer arithmetic to traverse memory safely.
- Distinguish between stack and heap allocation.

---
## 4. Context / Scenario (Optional if Purely Technical)
If helpful, provide a short narrative. Keep it under 120 words. Avoid fluff.

---
## 5. Problem Statement (Crystal Clear)
State exactly what the learner must build or solve. Avoid ambiguity. Use bullet points for multi-step requirements. Each requirement SHOULD be testable.

---
## 6. Input Specification
Describe:
- Source (stdin? function parameters? file?)
- Format (types, order, delimiters)
- Valid ranges
- Invalid / edge behaviors (ignore? reject? sanitize?)

Example:
```
Input: Two integers N and M (1 <= N, M <= 10^6) separated by a single space.
```

---
## 7. Output Specification
State EXACT required output formatting. If multiple lines, enumerate them.
```
Output: A single line containing the sum of N and M.
```
Mention trailing newline expectations if relevant.

---
## 8. Constraints & Limits
Include computational, memory, stylistic, or time constraints. Example:
- Time: O(n)
- Memory: <= 64 MB
- No global mutable state
- Must not use recursion (unless recursion topic)

---
## 9. Examples (At Least 2–3)
Each example must include Input + Output blocks. One should cover a normal case, one an edge case, optionally one invalid case (if handled). Format:
```
Example 1
Input:
5 7
Output:
12

Example 2 (Edge: max values)
Input:
1000000 1000000
Output:
2000000
```

---
## 10. Edge Cases to Consider
Provide a bullet list the student must consciously test (do not solve for them):
- Minimum valid values (e.g., N = 0)
- Maximum boundary
- Repeated elements / duplicates
- Empty input (if relevant)
- Overflow risk scenarios

---
## 11. Step-by-Step Guidance (Optional Tiered Hints)
If exercise is guided, provide progressive hint levels:
1. High-level decomposition
2. Data structure or algorithm suggestion
3. Pseudocode (NOT full solution)
Label this section clearly; omit for challenge tasks.

---
## 12. Required Folder & File Structure
Every exercise folder should look like:
```
<exercise-folder>/
  <learning_mode>--<difficulty>.md   # This template instantiated (SEE NAMING CONVENTION BELOW)
  src/
    main.c                # Or designated entry point
    (other .c/.h files)   # Modularized logic
  tests/                  # (Optional) Manual or automated test drivers
    test_input_01.txt
    test_expected_01.txt
  respuestas/             # Student's solutions or reflection answers
    REFLEXION.md          # Post-exercise reflection prompts answered
  docs/ (optional)        # Extra diagrams, design notes
```
If the course uses Doxygen later: add `include/` for headers.

### 12.1 File Naming Convention (IMPORTANT)
The main specification file that previously would be named `README.md` MUST instead be named using the following pattern:

```
<learning_mode>--<difficulty>.md
```

Where:
- `<learning_mode>` is the exact value of the `learning_mode` field in the metadata block (e.g., `concept`, `guided`, `project`, `challenge`).
- `<difficulty>` is the exact value of the `difficulty` field in the metadata block (e.g., `beginner`, `easy`, `medium`, `hard`, `challenge`).

Rules:
- Use all lowercase.
- Separate the two parts with exactly two hyphens (`--`).
- No spaces or additional suffixes/prefixes.
- The file must reside inside the folder corresponding to its topic, e.g.:
  ```
  Practicas/
    3. Variables/
      my-variables-exercise/   # Folder name is flexible but descriptive
        concept--beginner.md   # Specification file (this template applied)
        src/
        respuestas/
  ```
- One exercise = one folder containing exactly one specification file following this convention.
- If multiple exercises share the same topic, each still has its own folder and one spec file named by this convention.

Examples:
```
concept--beginner.md
guided--medium.md
project--hard.md
challenge--challenge.md
```

Rationale: This naming scheme allows automated tooling to classify exercises by pedagogical mode and difficulty without parsing file contents.

---
## 13. Coding Requirements / Style
- Use clear, self-documenting identifiers (English)
- No magic numbers (define constants)
- Functions <= ~40 LOC when possible
- One responsibility per function
- Header files only for declarations, no logic
- Always check return values (e.g., `malloc`, `scanf`)
- Free all dynamically allocated memory
- Avoid undefined behavior (document assumptions)

---
## 14. Documentation Requirements
Inside code:
- File header comment: purpose + author + date
- Function comments: purpose, params, return, side effects, error conditions
Example function doc (Doxygen-ready):
```c
/**
 * Calculates the average of an integer array.
 * @param arr Pointer to the first element.
 * @param len Number of elements (must be > 0).
 * @return The floating-point average.
 */
```

---
## 15. Testing Instructions
Describe how the learner can test manually or with provided scripts.
Example:
```
Compile:
  gcc -Wall -Wextra -std=c11 -O2 -o main src/*.c
Run:
  ./main < tests/test_input_01.txt
Compare:
  diff -u tests/test_expected_01.txt output.txt
```
Encourage building additional edge test cases.

---
## 16. Evaluation / Grading Rubric
| Criterion | Weight | Description |
|-----------|--------|-------------|
| Correctness | 40% | Produces required outputs across test set |
| Memory Safety | 15% | No leaks, no UB, proper frees |
| Code Clarity | 15% | Readable, modular, documented |
| Adherence to Spec | 15% | Matches input/output/constraints exactly |
| Edge Cases | 10% | Explicitly handled / validated |
| Reflection | 5% | Thoughtful answers in `respuestas/REFLEXION.md` |

---
## 17. Reflection Prompts (to place in `respuestas/REFLEXION.md`)
Students answer after solving:
1. What was the most challenging part and why?
2. Which edge case forced you to rethink your design?
3. If you refactored: what improved (complexity? clarity?)
4. What would you test next if given more time?
5. One concept to review before the next exercise.

---
## 18. Suggested Extensions (Optional)
List 2–4 optional improvements increasing difficulty (e.g., add dynamic resizing, support negative inputs, implement recursive variant, measure performance).

---
## 19. Common Mistakes (Preemptive Warnings)
- Forgetting `\n` in final output
- Not validating `scanf` return count
- Off-by-one loop boundaries
- Using uninitialized pointers
- Memory leaks after early returns

---
## 20. Glossary (If Terms Introduced)
Define new or advanced terms briefly: e.g., "heap", "segmentation fault", "pointer decay".

---
## 21. Version Control Guidance
Minimum recommended commit sequence:
1. Initialize repo / add skeleton
2. Parse input & stub functions
3. Implement core logic
4. Add edge case handling
5. Add tests & verify
6. Refactor & document
7. Final cleanup & reflection

Commit messages: imperative mood (e.g., "Add input parsing for matrix size").

---
## 22. Quality Checklist (Author Pre-Publish)
Before releasing the exercise ensure:
- [ ] All sections above populated
- [ ] Examples compile & run
- [ ] No ambiguous wording in spec
- [ ] At least one non-trivial edge case included
- [ ] Learning objectives are measurable
- [ ] Reflection prompts present
- [ ] Folder structure matches template

---
## 23. Mini Author Prompt (Reusable Snippet)
Paste this into your own assistant when drafting a new exercise:
```
Create a C programming practice exercise following this structure:
- Provide metadata (title, topic, difficulty, time)
- Write a concise overview and clear problem statement
- Define precise input/output specifications and constraints
- Supply at least 2 normal examples + 1 edge example
- List explicit edge cases (not solved, only listed)
- Include learning objectives and optional narrative context
- Provide a rubric table with weights summing to 100%
- Add reflection questions and 2–3 extension ideas
- Enforce coding style: modular, documented, safe memory usage
- Include folder layout (README.md, src/, tests/, respuestas/)
Keep wording unambiguous, technical, and student-friendly.
```

---
## 24. Minimal Filled Example (Illustrative)
```
Title: Sum of Two Numbers
Topic: Variables
Difficulty: beginner
Problem: Read two integers and print their sum followed by a newline.
Input: Two integers A B (|A|, |B| <= 10^6) separated by space.
Output: Single integer (A + B) with newline.
Constraints: Use 32-bit signed int, handle negative values.
Examples:
 Input: 5 7   -> Output: 12
 Input: -3 9  -> Output: 6
 Edge: 1000000 1000000 -> 2000000
Edge Cases: negatives, large boundaries, zero values
Reflection Prompt: What error would overflow cause and why does it not happen here?
Extensions: Add overflow detection; support arbitrary length using strings.
```

---
## 25. Tone & Language Rules
- Write all exercise content in clear, neutral instructional Spanish.
- Avoid slang, jokes, or cultural references.
- Prefer active voice ("Implement a function..." not "A function should be implemented").

---
## 26. Accessibility & Inclusivity Notes
- Use gender-neutral language.
- Avoid assuming prior informal knowledge (define terms when first used).
- Keep color references optional (for visually impaired learners).

---
## 27. Maintenance Notes
If updating exercise:
- Bump `version` & update `last_update`
- Add a short CHANGELOG section at bottom listing modifications

---
## 28. CHANGELOG (Template Section for Future)
```
### Changelog
- 1.0 (YYYY-MM-DD): Initial release.
```

---
## Final Reminder
Consistency > Cleverness. Your goal is to reduce ambiguity so the learner focuses on mastering the concept, not guessing intentions.

> Use this file as the single source of truth when authoring new practice exercises.
