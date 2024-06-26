-- In 4.sql, write a SQL query to determine the number of movies with an IMDb rating of 10.0.

SELECT COUNT(*) from movies JOIN ratings ON movies.id = ratings.movie_id WHERE rating = 10.0;

-- OR

-- SELECT COUNT(*)
-- FROM movies
-- WHERE id IN (
--     SELECT movie_id
--     FROM ratings
--     WHERE rating = 10.0
-- );
