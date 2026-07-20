# Тема 9: Бази от данни. Релационен модел на данните.

---

## ТЕОРИЯ

### 1. Основни понятия на релационния модел

**Домейн (Domain)** — именувано множество от допустими стойности на атрибут (напр. INTEGER, VARCHAR(50), DATE). Може да е безкрайно или крайно.

**Релация (Relation)** — подмножество на декартовото произведение D₁ × D₂ × … × Dₙ. В контекста на БД: **двумерна таблица** от данни.

**Кортеж (Tuple)** — ред в релацията; конкретна n-торка от стойности. Всеки кортеж е уникален (множество, не мултимножество).

**Атрибут (Attribute)** — именувана колона на релацията, асоциирана с домейн.

**Схема на релация** = Име + списък от атрибути:  
`Movies(title, year, length, filmType, studioName)`

**Схема на база от данни** = множество от схемите на всички релации в БД.

**Екземпляр на релация** = текущото множество от кортежи (съдържанието в даден момент).

**Ключ** = минимален набор атрибути, които уникално идентифицират всеки кортеж.  
**Първичен ключ (PK)** = избраният ключ. **Чужд ключ (FK)** = атрибут, сочещ PK на друга релация.

**Атомарност**: всяка стойност в кортеж трябва да е атомарна (без масиви/списъци) — **1-ва нормална форма**.

---

### 2. Видове операции върху релационна БД

| Категория | Операции | Кога |
|-----------|---------|------|
| **DML** (Data Manipulation Language) | SELECT, INSERT, UPDATE, DELETE | Манипулация на данни; изисква COMMIT |
| **DDL** (Data Definition Language) | CREATE, DROP, ALTER | Промяна на схемата; автоматично COMMIT |
| **DCL** (Data Control Language) | GRANT, REVOKE | Права за достъп |

---

### 3. Релационна алгебра

#### Съвместимост на релации
R(A₁,…,Aₙ) и S(B₁,…,Bₙ) са **съвместими** ако: еднаква степен n + dom(Aₖ) = dom(Bₖ) за всяко k.

#### Основни операции (5)

| Операция | Нотация | Описание | SQL еквивалент |
|----------|---------|---------|----------------|
| **Обединение** | R ∪ S | Всички кортежи от R и S (без дублирания). Изисква съвместимост. | `UNION` |
| **Разлика** | R − S | Кортежите в R, които ги няма в S. **Не е комутативна.** | `EXCEPT` |
| **Декартово произведение** | R × S | Всички комбинации от кортежи. Резултат: (m+n) атрибута. | `CROSS JOIN` |
| **Проекция** | π<sub>A₁,…,Aₖ</sub>(R) | Избира само колони A₁…Aₖ (намаляване в ширина). Дубликатите се премахват. | `SELECT A1, A2…` |
| **Селекция** | σ<sub>F</sub>(R) | Избира редовете, удовлетворяващи условие F (намаляване в дълбочина). | `WHERE` |

#### Допълнителни операции (4) — изразими чрез основните

| Операция | Нотация | Описание | Изразима чрез |
|----------|---------|---------|---------------|
| **Сечение** | R ∩ S | Общите кортежи. | R ∩ S = R − (R − S) |
| **Частно (Division)** | R ÷ S | Кортежи от R, съчетани с ВСИЧКИ кортежи от S. „За всеки…" | Комбинация |
| **Съединение (θ-join)** | R ▷◁<sub>C</sub> S | Декартово × + селекция по условие C | σ<sub>C</sub>(R × S) |
| **Естествено съединение** | R ▷◁ S | Съединение по всички атрибути с еднакви имена; дублираните колони се премахват. | π<sub>L</sub>(σ<sub>C</sub>(R × S)) |

**Преименуване**: ρ<sub>R1(A1,…,An)</sub>(R2) — дава ново име на релация/атрибути.

#### Приоритет на операциите (от висок към нисък):
1. Унарни: σ, π, ρ
2. × и ▷◁
3. ∩
4. ∪ и −

---

## КАК СЕ РЕШАВАТ ЗАДАЧИ

> **Task 5** на практическия изпит (2021–2025) е **SQL заявка**. Стандартни бази: Ships, Movies или PC. Форматът е: напиши заявка + избери вярната от 4 предложени.

---

### Стандартни схеми от изпита

#### Ships DB (Кораби)
```sql
Classes(class, type, country, numGuns, bore, displacement)
Ships(name, class, launched)
Battles(name, date)
Outcomes(ship, battle, result)   -- result: 'sunk'/'damaged'/'ok'
```

#### Movies DB (Филми)
```sql
Movie(title, year, length, filmType, studioName, producerC#)
StarsIn(movieTitle, movieYear, starName)
MovieStar(name, address, gender, birthdate)
MovieExec(name, address, cert#, netWorth)
Studio(name, address, presC#)
```

#### PC DB (Компютри)
```sql
Product(maker, model, type)       -- type: 'PC'/'Laptop'/'Printer'
PC(code, model, speed, ram, hd, cd, price)
Laptop(code, model, speed, ram, hd, screen, price)
Printer(code, model, color, type, price)
```

---

### DDL команди

```sql
-- Създаване на таблица
CREATE TABLE Students (
    id          INTEGER         PRIMARY KEY,
    name        VARCHAR(100)    NOT NULL,
    faculty_num CHAR(10)        UNIQUE,
    grade       DECIMAL(3,2)    DEFAULT 3.00,
    dept_id     INTEGER         REFERENCES Departments(id)
                                ON DELETE SET NULL
                                ON UPDATE CASCADE
);

-- Промяна на таблица
ALTER TABLE Students ADD COLUMN email VARCHAR(100);
ALTER TABLE Students DROP COLUMN email;
ALTER TABLE Students ALTER COLUMN name SET NOT NULL;

-- Изтриване на таблица
DROP TABLE Students;
DROP TABLE IF EXISTS Students;

-- Индекс
CREATE INDEX idx_name ON Students(name);
CREATE UNIQUE INDEX idx_fn ON Students(faculty_num);
```

**Ограничения (Constraints):**
```sql
PRIMARY KEY (id)                      -- уникален, NOT NULL
FOREIGN KEY (dept_id) REFERENCES Departments(id)
UNIQUE (faculty_num)
NOT NULL
CHECK (grade >= 2.00 AND grade <= 6.00)
DEFAULT 3.00
```

---

### DML команди

```sql
-- SELECT — основна структура
SELECT [DISTINCT] колони / *
FROM   таблица [alias]
[JOIN  таблица ON условие]
[WHERE условие]
[GROUP BY колони]
[HAVING условие_върху_групи]
[ORDER BY колони [ASC|DESC]]
[LIMIT n];

-- INSERT
INSERT INTO Students (name, faculty_num, grade)
VALUES ('Иван Иванов', 'FN12345', 5.50);

-- UPDATE
UPDATE Students
SET grade = 6.00
WHERE faculty_num = 'FN12345';

-- DELETE
DELETE FROM Students
WHERE grade < 3.00;
```

---

### JOIN видове

```sql
-- INNER JOIN: само съвпадащи редове
SELECT s.name, d.name
FROM Students s
INNER JOIN Departments d ON s.dept_id = d.id;

-- LEFT JOIN: всички от лявата + съвпадащи от дясната (NULL за несъвпадащи)
SELECT s.name, d.name
FROM Students s
LEFT JOIN Departments d ON s.dept_id = d.id;

-- RIGHT JOIN: всички от дясната + съвпадащи от лявата
-- FULL OUTER JOIN: всички от двете
-- CROSS JOIN: декартово произведение
SELECT * FROM A CROSS JOIN B;

-- NATURAL JOIN: съединява по всички атрибути с едно и също име
SELECT * FROM Ships NATURAL JOIN Classes;
```

---

### Агрегатни функции и GROUP BY

```sql
SELECT studioName, COUNT(*) AS брой, AVG(length) AS средна_дължина
FROM Movie
GROUP BY studioName
HAVING COUNT(*) > 5
ORDER BY средна_дължина DESC;
```

**Функции**: `COUNT(*)`, `COUNT(col)`, `SUM(col)`, `AVG(col)`, `MAX(col)`, `MIN(col)`

> `WHERE` филтрира **редове преди** групиране. `HAVING` филтрира **групи след** групиране.

---

### Подзаявки (Subqueries)

```sql
-- В WHERE
SELECT name FROM Ships
WHERE class IN (
    SELECT class FROM Classes WHERE country = 'USA'
);

-- EXISTS
SELECT name FROM MovieStar s
WHERE EXISTS (
    SELECT * FROM StarsIn
    WHERE starName = s.name AND movieYear > 2000
);

-- Скаларна подзаявка
SELECT name FROM MovieExec
WHERE netWorth > (SELECT AVG(netWorth) FROM MovieExec);

-- Correlated subquery
SELECT title FROM Movie m
WHERE length = (
    SELECT MAX(length) FROM Movie WHERE studioName = m.studioName
);
```

---

### Типични задачи от изпита

**Намери кораби потопени в битки:**
```sql
SELECT ship FROM Outcomes WHERE result = 'sunk';
```

**Намери класове, при които всички кораби са потопени:**
```sql
SELECT class FROM Ships s
WHERE NOT EXISTS (
    SELECT * FROM Outcomes o
    WHERE o.ship = s.name AND o.result <> 'sunk'
);
```

**Намери производители, правещи и PC, и Laptop:**
```sql
SELECT maker FROM Product WHERE type = 'PC'
INTERSECT
SELECT maker FROM Product WHERE type = 'Laptop';
```

**Намери филми с всички актьори от дадено студио:**
```sql
SELECT DISTINCT movieTitle FROM StarsIn si
JOIN MovieStar ms ON si.starName = ms.name
-- (Division pattern: за всеки актьор...)
```

**NULL обработка:**
```sql
WHERE col IS NULL
WHERE col IS NOT NULL
COALESCE(col, default_value)
```

---

### Бърза справка

| Понятие | Ключ |
|---------|------|
| Релация | Таблица = множество от уникални кортежи |
| Домейн | Тип / множество от допустими стойности |
| Схема | Релация(атрибут1, атрибут2, …) |
| DML | SELECT, INSERT, UPDATE, DELETE |
| DDL | CREATE, DROP, ALTER |
| σ (селекция) | WHERE |
| π (проекция) | SELECT col1, col2 |
| R ∪ S | UNION |
| R − S | EXCEPT |
| R × S | CROSS JOIN |
| R ▷◁ S | NATURAL JOIN / JOIN ON |
| WHERE vs HAVING | WHERE = редове; HAVING = групи |
| LEFT JOIN | Всички от ляво + NULL за несъвпадащи |
