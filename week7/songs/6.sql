-- The names of songs that are by Post Malone.
SELECT name
FROM songs
WHERE artist_id =
(
    SELECT id
    FROM artists
    WHERE name = 'Post Malone'
);

-- OR

-- SELECT * FROM songs
-- JOIN artists ON songs.artist_id = artists.id
-- WHERE artists.name = 'Post Malone';
