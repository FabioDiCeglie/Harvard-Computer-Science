-- In 11.sql, write a SQL query to list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated.

SELECT title
FROM movies, ratings, stars, people
WHERE movies.id = ratings.movie_id
AND movies.id = stars.movie_id
AND people.id = stars.person_id
AND people.name = 'Chadwick Boseman'
ORDER BY ratings.rating DESC
LIMIT 5;

-- OR

-- SELECT movies.title
-- FROM movies
-- JOIN ratings ON movies.id = ratings.movie_id
-- JOIN stars ON movies.id = stars.movie_id
-- JOIN people ON people.id = stars.person_id
-- WHERE people.name = 'Chadwick Boseman'
-- ORDER BY ratings.rating DESC
-- LIMIT 5;
