# Как се решават XML задачи на изпита

Типична задача: *„По описание на обекти и връзки — напиши XML документ + DTD или XML Schema."*

---

## СТЪПКА 1: Четеш описанието и извличаш структурата

Прочети задачата и отговори на:
- Кои са **обектите** (неща в системата)?
- Кои са **атрибутите** им (свойства)?
- Какви са **връзките** между тях (кое съдържа кое)?
- Кое е **задължително** и кое е **незадължително**?
- Кое се **повтаря** (0 пъти, 1 път, много пъти)?

### Ключови думи → XML конструкции

| Описание в задачата | XML елемент |
|---------------------|-------------|
| „Каталог от книги" | Корен елемент `<BookCatalog>` |
| „Всяка книга има заглавие" | Задължителен дъщерен елемент `<Title>` |
| „Може да има автори" | Незадължителен елемент `?` или `*` |
| „Списък от автори" | Повторяем елемент `+` или `*` |
| „ID на книга" | Атрибут `id` от тип `ID` |
| „Препратка към автор" | Атрибут от тип `IDREF` |
| „Типът е Fiction или NonFiction" | Изброен атрибут `(Fiction\|NonFiction)` |

---

## СТЪПКА 2: Нарисувай дървото

Преди да пишеш код, нарисувай йерархията:

```
LibraryCatalog [атр: version]
├── Author* (0 или повече)
│   ├── Name (#PCDATA)
│   └── Country (#PCDATA)?
└── Book+ (1 или повече)
    ├── Title (#PCDATA)
    ├── Year (#PCDATA)
    └── Genre (#PCDATA)?
    [атр: id ID, authorRef IDREF]
```

---

## СТЪПКА 3: Пишеш DTD

### Шаблон за DTD

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE RootElement [

  <!ELEMENT RootElement (Child1*, Child2+)>
  <!ATTLIST RootElement
    version CDATA #REQUIRED>

  <!ELEMENT Child1 (SubElement1, SubElement2?)>
  <!ATTLIST Child1
    id  ID    #REQUIRED>

  <!ELEMENT Child2 (SubElement1, SubElement3+)>
  <!ATTLIST Child2
    ref IDREF #IMPLIED>

  <!ELEMENT SubElement1 (#PCDATA)>
  <!ELEMENT SubElement2 (#PCDATA)>
  <!ELEMENT SubElement3 (#PCDATA)>
  <!ATTLIST SubElement3
    type (A|B|C) #IMPLIED>

]>
```

### Правилата за честота

| Символ | Значение | Пример |
|--------|----------|--------|
| (нищо) | Точно 1 път | `<!ELEMENT Book (Title, Author)>` |
| `?` | 0 или 1 | `(Description?)` |
| `+` | 1 или повече | `(Author+)` |
| `*` | 0 или повече | `(Tag*)` |
| `(A, B)` | Последователност | А после Б |
| `(A \| B)` | Избор (едно от двете) | А или Б |

### Типове атрибути

| Тип | Кога да го ползваш |
|-----|-------------------|
| `CDATA` | Обикновен текст (дата, URL, описание) |
| `ID` | Уникален идентификатор на елемент |
| `IDREF` | Препратка към един ID |
| `IDREFS` | Препратка към няколко ID (разделени с интервал) |
| `(val1\|val2\|val3)` | Изброени стойности |

| Стойност по подразбиране | Значение |
|--------------------------|----------|
| `#REQUIRED` | Задължителен атрибут |
| `#IMPLIED` | Незадължителен, без default |
| `#FIXED "val"` | Фиксирана стойност |
| `"default"` | Незадължителен с default стойност |

---

## СТЪПКА 4: Пишеш XML документа

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE LibraryCatalog [
  <!-- DTD тук или референция към .dtd файл -->
]>
<LibraryCatalog version="1.0">

  <Author id="a1">
    <Name>Иван Вазов</Name>
    <Country>България</Country>
  </Author>

  <Author id="a2">
    <Name>Елин Пелин</Name>
  </Author>

  <Book id="b1" authorRef="a1">
    <Title>Под игото</Title>
    <Year>1894</Year>
    <Genre>Fiction</Genre>
  </Book>

  <Book id="b2" authorRef="a2">
    <Title>Гераците</Title>
    <Year>1911</Year>
  </Book>

</LibraryCatalog>
```

---

## СТЪПКА 5 (алтернатива): XML Schema вместо DTD

### Шаблон за XSD

```xml
<xs:schema xmlns:xs="http://www.w3.org/2001/XMLSchema">

  <!-- Корен елемент -->
  <xs:element name="LibraryCatalog">
    <xs:complexType>
      <xs:sequence>
        <xs:element name="Author" type="AuthorType"
                    minOccurs="0" maxOccurs="unbounded"/>
        <xs:element name="Book"   type="BookType"
                    minOccurs="1" maxOccurs="unbounded"/>
      </xs:sequence>
      <xs:attribute name="version" type="xs:string" use="required"/>
    </xs:complexType>
  </xs:element>

  <!-- Тип Author -->
  <xs:complexType name="AuthorType">
    <xs:sequence>
      <xs:element name="Name"    type="xs:string"/>
      <xs:element name="Country" type="xs:string" minOccurs="0"/>
    </xs:sequence>
    <xs:attribute name="id" type="xs:ID" use="required"/>
  </xs:complexType>

  <!-- Тип Book -->
  <xs:complexType name="BookType">
    <xs:sequence>
      <xs:element name="Title" type="xs:string"/>
      <xs:element name="Year"  type="xs:gYear"/>
      <xs:element name="Genre" type="GenreType" minOccurs="0"/>
    </xs:sequence>
    <xs:attribute name="id"        type="xs:ID"    use="required"/>
    <xs:attribute name="authorRef" type="xs:IDREF" use="optional"/>
  </xs:complexType>

  <!-- Изброен тип -->
  <xs:simpleType name="GenreType">
    <xs:restriction base="xs:string">
      <xs:enumeration value="Fiction"/>
      <xs:enumeration value="NonFiction"/>
      <xs:enumeration value="Poetry"/>
    </xs:restriction>
  </xs:simpleType>

</xs:schema>
```

### DTD → XSD съответствия

| DTD | XSD |
|-----|-----|
| `(A, B, C)` | `<xs:sequence>` с трите елементи |
| `(A \| B)` | `<xs:choice>` |
| `(нищо)` | `minOccurs="1" maxOccurs="1"` (default) |
| `?` | `minOccurs="0" maxOccurs="1"` |
| `+` | `minOccurs="1" maxOccurs="unbounded"` |
| `*` | `minOccurs="0" maxOccurs="unbounded"` |
| `CDATA` | `type="xs:string"` |
| `ID` | `type="xs:ID"` |
| `IDREF` | `type="xs:IDREF"` |
| `IDREFS` | `type="xs:IDREFS"` |
| `#REQUIRED` | `use="required"` |
| `#IMPLIED` | `use="optional"` |

---

## ПЪЛЕН РЕШЕН ПРИМЕР

**Задача**: „Напиши XML за университет. Университетът има факултети. Всеки факултет има декан (задължително) и катедри (поне 1). Всяка катедра има ръководител и студенти (0 или повече). Студентите имат факултетен номер (уникален) и специалност (Информатика, Математика или Физика)."

### Стъпка 1: Дърво

```
University [name CDATA #REQUIRED]
└── Faculty+ 
    ├── Dean (#PCDATA)
    └── Department+
        ├── Head (#PCDATA)
        └── Student* [fn ID, specialty (Inf|Math|Phys) #REQUIRED]
            └── StudentName (#PCDATA)
```

### Стъпка 2: DTD

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE University [

  <!ELEMENT University (Faculty+)>
  <!ATTLIST University name CDATA #REQUIRED>

  <!ELEMENT Faculty (Dean, Department+)>
  <!ATTLIST Faculty id ID #REQUIRED>

  <!ELEMENT Dean (#PCDATA)>

  <!ELEMENT Department (Head, Student*)>

  <!ELEMENT Head (#PCDATA)>

  <!ELEMENT Student (StudentName)>
  <!ATTLIST Student
    fn        ID                              #REQUIRED
    specialty (Informatics|Mathematics|Physics) #REQUIRED>

  <!ELEMENT StudentName (#PCDATA)>

]>
```

### Стъпка 3: XML

```xml
<?xml version="1.0" encoding="UTF-8"?>
<University name="СУ Св. Климент Охридски">

  <Faculty id="fmi">
    <Dean>Проф. Иванов</Dean>

    <Department>
      <Head>Доц. Петров</Head>
      <Student fn="FN12345" specialty="Informatics">
        <StudentName>Анастасия Якимовска</StudentName>
      </Student>
      <Student fn="FN12346" specialty="Mathematics">
        <StudentName>Иван Георгиев</StudentName>
      </Student>
    </Department>

    <Department>
      <Head>Проф. Колева</Head>
    </Department>

  </Faculty>

</University>
```

---

## ЧЕСТИ ГРЕШКИ И КАК ДА ГИ ИЗБЕГНЕШ

| Грешка | Как да я избегнеш |
|--------|------------------|
| Забравен затварящ таг | Всеки `<tag>` → `</tag>` или `<tag/>` |
| ID стойности с интервали | ID не може да съдържа интервали! Ползвай `_` |
| IDREFS: забравен интервал | `authorRefs="a1 a2"` (разделени с интервал) |
| `#PCDATA` в грешно място | Смесено съдържание: `(#PCDATA | elem)*` — задължително * и #PCDATA пръв |
| Атрибут без стойност | `<Book id>` е грешно; трябва `<Book id="b1">` |
| Корен не съвпада с DOCTYPE | `<!DOCTYPE X [...]> <Y>` — X ≠ Y е грешно |
| Забравен `#REQUIRED` | Ако атрибутът е задължителен — пиши `#REQUIRED` |

---

## БЪРЗА ШПАРГАЛКА ЗА DTD

```
Елемент с деца:      <!ELEMENT Родител (Дете1, Дете2?)>
Елемент с текст:     <!ELEMENT Дете (#PCDATA)>
Елемент празен:      <!ELEMENT Img EMPTY>

Атрибут текст:       <!ATTLIST Elem attr CDATA #REQUIRED>
Атрибут уникален:    <!ATTLIST Elem id   ID    #REQUIRED>
Атрибут препратка:   <!ATTLIST Elem ref  IDREF #IMPLIED>
Атрибут изброен:     <!ATTLIST Elem type (A|B|C) "A">
```

---

## БЪРЗА ШПАРГАЛКА ЗА XSD

```xml
<!-- Прост тип с ограничение -->
<xs:simpleType name="MyType">
  <xs:restriction base="xs:string">
    <xs:enumeration value="A"/>
    <xs:enumeration value="B"/>
  </xs:restriction>
</xs:simpleType>

<!-- Прост тип с числов диапазон -->
<xs:simpleType name="Grade">
  <xs:restriction base="xs:decimal">
    <xs:minInclusive value="2.00"/>
    <xs:maxInclusive value="6.00"/>
  </xs:restriction>
</xs:simpleType>

<!-- Сложен тип с атрибут -->
<xs:complexType name="MyComplex">
  <xs:sequence>
    <xs:element name="Child" type="xs:string"/>
  </xs:sequence>
  <xs:attribute name="id" type="xs:ID" use="required"/>
</xs:complexType>
```
