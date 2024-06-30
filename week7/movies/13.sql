-- In 13.sql, write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.

SELECT DISTINCT name FROM people, stars, movies
WHERE people.id = stars.person_id AND stars.movie_id = movies.id AND movies.id IN
(
    SELECT m2.id
    FROM stars s_kb
    JOIN movies m2 ON s_kb.movie_id = m2.id
    JOIN people p_kb ON s_kb.person_id = p_kb.id
    WHERE p_kb.name = 'Kevin Bacon'
)
AND people.name != 'Kevin Bacon';

-- OR

-- SELECT DISTINCT p.name
-- FROM people p
-- JOIN stars s ON p.id = s.person_id
-- JOIN movies m ON s.movie_id = m.id
-- WHERE m.id IN (
--     SELECT m2.id
--     FROM stars s_kb
--     JOIN movies m2 ON s_kb.movie_id = m2.id
--     JOIN people p_kb ON s_kb.person_id = p_kb.id
--     WHERE p_kb.name = 'Kevin Bacon'
-- )
-- AND p.name != 'Kevin Bacon';

-- -- OR

-- SELECT DISTINCT p.name
-- FROM people p
-- JOIN stars s ON p.id = s.person_id
-- JOIN movies m ON s.movie_id = m.id
-- JOIN stars s_kevin ON m.id = s_kevin.movie_id
-- JOIN people p_kevin ON s_kevin.person_id = p_kevin.id
-- WHERE p_kevin.name = 'Kevin Bacon'
-- AND p.id != p_kevin.id;
