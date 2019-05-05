SELECT id,age,coins_needed,power FROM(SELECT Wands.id,Wands_Property.age,Wands.coins_needed,Wands.power,Wands_Property.is_evil 
FROM Wands 
INNER JOIN
Wands_Property ON Wands.code = Wands_Property.code) total
WHERE total.is_evil = 0 and NOT EXISTS(SELECT * FROM (SELECT Wands_Property.age,Wands.coins_needed,Wands.power FROM Wands INNER JOIN Wands_Property ON Wands.code = Wands_Property.code) t2 WHERE t2.coins_needed<total.coins_needed AND t2.age = total.age AND total.power = t2.power)
ORDER BY power desc,age desc;
