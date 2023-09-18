SELECT REPLACE('Hello World' , 'Hell' , '@#$');
-- @#$o World

SELECT CONCANT('col1' , 'text' , 'col2');

SELECT SUBSTRING('string' , 1,5);

-- 1 = start index  , 5 = length of substr

SELECT CHAR_LENGTH('string');

SELECT title, release_year FROM books
ORDER BY release_year DESC LIMIT 5,10;

-- meaning the starting point is 5, and from 5 it will give next 10 books which are available
SELECT title, release_year, 
    CASE
        WHEN release_year >= 2000 THEN 'Modern Lit'
        ELSE '20th century lit'
    END AS genere
FROM books;




SELECT events.dt , events.title, owners.full_name , owners.email_address FROM events 
JOIN owners ON 
owners.id = events.owner_id
WHERE owners.on_vacation = 0
ORDER by events.dt
LIMIT 5