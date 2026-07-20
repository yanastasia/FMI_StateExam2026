# FMI State Exam Prep — Software Engineering

Study materials for the Bachelor's State Exam ("Държавен изпит"), Software Engineering
program, Faculty of Mathematics and Informatics (FMI), Sofia University. Organized by
**course → topic**, following the official 2025 syllabus (Konspekt), so it's easy to
navigate on GitHub and easy to feed into NotebookLM one topic at a time.

The official syllabus covers 30 exam topics grouped into 3 broad areas (Core CS,
Software Engineering, Mathematics), but day-to-day you think in terms of the actual
university courses each topic belongs to — so within each area, material is organized
by course (e.g. "Databases" for topics 9–10), not by raw topic number.

## How it's organized

```
Computer_Science/
  01_ДСТР_Discrete_Structures/        (topics 1-4)
  03_ОС_Operating_Systems/            (topic 7)
  05_БД_Databases/                    (topics 9-10)
  06_УП_Procedural_Programming/       (topics 11-12)
  07_ООП_OOP/                         (topics 13-14)
  08_СДА_Data_Structures/             (topic 15)

Software_Engineering/
  09_УСИ_Software_Engineering_Intro/  (topic 16)
  10_РСА_Distributed_Architectures/   (topic 17)
  11_ПЧМИ_User_Interface_Design/      (topic 18)
  12_УК_Quality_Management_Testing/   (topic 19)
  13_САРС_Software_Architecture/      (topic 20)
  14_АСИ_Requirements_Engineering/    (topic 21)
  15_ПИСС_Systems_Design_Integration/ (topic 22)
  16_УПроект_Project_Management/      (topic 23)
  17_XML/                             (topic 24)

Math/
  18_ДИС_Calculus/                    (topics 25-26)
  19_Алгебра_Linear_Algebra/          (topic 27)
  20_Геометрия_Analytic_Geometry/     (topics 28-29)
  21_Статистика_Probability_Statistics/ (topic 30)

Others/
  02_КАРХ_Computer_Architecture/      (topics 5-6)
  04_КМрежи_Computer_Networks/        (topic 8)

General_Resources/
Past_Exams/
```

`Computer_Science`, `Software_Engineering`, `Math`, and `Others` are the four
top-level study areas — `Others` holds Computer Architecture and Networks, which
didn't fit neatly with the rest of the CS-core topics. Inside each area, every
**course** folder contains:

- `Topic_NN_.../` — one folder per exam topic in that course. Inside, you'll find every
  PDF, DOCX, slide deck, cheat sheet, flashcard set, and code sample that's relevant to
  that specific topic, plus a `Syllabus_Annotation_Topic_NN.txt` file — the exact
  official syllabus text for that question, extracted from the 2025 Konspekt.
- `Course_Materials/` — broader lecture material for the course that isn't tied to one
  specific topic (e.g. a full semester of OOP slides, or general Linear Algebra
  background covering more than just topic 27).
- `Tasks_and_Past_Exams/` — practice tasks, solved exercises, and consultation notes
  specific to that course.

Two extra top-level folders:

- `General_Resources/` — the syllabus itself (Konspekt), the grading formula, the
  curriculum plan, general planning docs, and materials that span many topics at once
  (e.g. the "cheatsheets_all_topics.pdf" combined cheat sheet).
- `Past_Exams/` — full past exam papers (practical + theory), covering all topics in one
  document, not split by course.

### Course → topic map

Grouped the same way as the folders above (Computer Science, Software Engineering,
Math, Others):

**Computer Science**
- **01_ДСТР_Discrete_Structures** — T1: Графи. Дървета. Обхождане на графи; T2: Булеви функции. Пълнота; T3: Характеризация на регулярните езици. Теорема на Майхил-Нероуд; T4: Лема за разрастването за контекстносвободни езици
- **03_ОС_Operating_Systems** — T7: Процеси и комуникация в ОС
- **05_БД_Databases** — T9: Релационен модел; T10: Нормални форми
- **06_УП_Procedural_Programming** — T11: Основни конструкции; T12: Указатели, масиви, рекурсия
- **07_ООП_OOP** — T13: Класове, наследяване, капсулация; T14: Полиморфизъм, множествено наследяване
- **08_СДА_Data_Structures** — T15: Стек, опашка, списък, дърво

**Software Engineering**
- **09_УСИ_Software_Engineering_Intro** — T16: Софтуерен процес, Agile
- **10_РСА_Distributed_Architectures** — T17: Разпределени софтуерни архитектури
- **11_ПЧМИ_User_Interface_Design** — T18: Проектиране на потребителски интерфейс
- **12_УК_Quality_Management_Testing** — T19: Управление на качеството, тестване
- **13_САРС_Software_Architecture** — T20: Софтуерна архитектура
- **14_АСИ_Requirements_Engineering** — T21: Инженеринг на софтуерните изисквания
- **15_ПИСС_Systems_Design_Integration** — T22: Проектиране и интегриране на системи
- **16_УПроект_Project_Management** — T23: Планиране на проекта
- **17_XML** — T24: XML структуриране, валидация, обработка

**Math**
- **18_ДИС_Calculus** — T25: Теорема на Ферма, средни стойности, Тейлър; T26: Определен интеграл, Нютон-Лайбниц
- **19_Алгебра_Linear_Algebra** — T27: Собствени вектори и стойности
- **20_Геометрия_Analytic_Geometry** — T28: Права в равнината; T29: Права и равнина в пространството
- **21_Статистика_Probability_Statistics** — T30: Дискретни разпределения, моменти

**Others**
- **02_КАРХ_Computer_Architecture** — T5: Компютърни архитектури, формати на данните, ЦП; T6: Йерархия на паметта, преадресация, прекъсвания
- **04_КМрежи_Computer_Networks** — T8: OSI модел, IPv4/IPv6/TCP/HTTP

## One thing to do before you push to GitHub

There's a folder called **`_EMPTY_FOLDERS_DELETE_MANUALLY/`** at the root — 33 leftover
empty `Course_Materials` / `Tasks_and_Past_Exams` folders that had nothing routed into
them yet. This sandbox can't delete files or folders on your mounted drive directly
(only move them), so instead of silently leaving empty folders around, I collected them
here for you to review and drag to the Trash yourself.

If you ever see a similar `_DELETE_THIS_FOLDER/`-style folder appear again after future
cleanup passes, it means the same thing: content Claude flagged as safe to remove but
couldn't delete outright.

A `.gitignore` is already in place to keep `.DS_Store`, virtual environments, and other
junk out of future commits.

## Study strategy: one NotebookLM notebook per topic

This is the workflow that's actually worked, in your own words — worth repeating
deliberately every time you start a new topic:

1. **Create one NotebookLM notebook per topic** (not per course, not one giant
   notebook). Use the `Topic_NN` folder as your source list.
2. **Upload everything in that topic's folder** — every PDF, slide deck, cheat sheet,
   and code sample sitting in `Topic_NN/`, plus anything relevant from that course's
   `Course_Materials/` folder if it applies.
3. **Paste the syllabus annotation into your prompt.** Every topic folder has a
   `Syllabus_Annotation_Topic_NN.txt` file — the official exam-committee wording of what
   that question must cover. Include it verbatim when you ask NotebookLM for a report or
   podcast, so the output stays anchored to what the exam actually asks for instead of
   drifting into generic textbook coverage.
4. **Generate a report first, then an audio podcast.** These two have been the most
   effective formats for actually understanding a topic — more so than quizzes. A good
   instruction to give NotebookLM:

   > "Using only the attached materials and the official syllabus wording below, produce
   > a report covering exactly what this exam question requires, in the order the
   > syllabus lists it, flagging anything the sources don't cover. Then generate an audio
   > overview aimed at someone about to sit this exam, that walks through the same
   > structure. Syllabus wording: [paste Syllabus_Annotation_Topic_NN.txt here]"

5. **Quizzes are a fine bonus**, but treat the report + podcast as the core loop — that's
   the combination that's actually built understanding rather than surface familiarity.
6. **Work topic by topic, not course by course.** Even courses with 2 topics (like
   Databases: topics 9 and 10) get two separate notebooks, since the exam grades each
   topic as its own question.

## Tips

- The exam has two separate days: a practical (tasks) day and a theory day, graded
  independently — both need ≥3.00 for the final grade to be their average; see
  `General_Resources/State Exam Grade Formula.pdf`.
- `Past_Exams/` is worth a pass once you've covered the topics in a course — it shows you
  the actual shape of questions asked, especially for the practical part.
- Topics 11, 12, 13, 14, 15 (and generally anything flagged "Забележка" in the syllabus
  annotation) can also show up as practical-exam tasks, not just theory questions — the
  annotation file tells you which ones.
- If a topic folder has multiple overlapping PDFs (e.g. a lecture, a cheat sheet, and a
  flashcard set), that's intentional — different formats suit different review passes,
  and NotebookLM will happily digest all of them together.
