-- September 2023
SELECT ms.NAME FROM MOVIESTAR ms
inner join STARSIN s on s.STARNAME = ms.NAME
where GENDER = 'F' and MOVIEYEAR > 2000
intersect 
SELECT ms.NAME FROM MOVIESTAR ms
inner join STARSIN s on s.STARNAME = ms.NAME
where GENDER = 'F' and MOVIEYEAR <= 2000

-- July 2022
SELECT s.name, m.title
FROM MOVIE m JOIN studio s ON m.STUDIONAME = s.NAME
WHERE s.name IN (SELECT STUDIONAME
FROM MOVIE
WHERE TITLE = 'The Usual Suspects' AND year = 1995)

-- September 2021
-- â, à