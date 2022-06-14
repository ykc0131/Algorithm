#1
SELECT date_format(datetime,"%H") as HOUR,count(ANIMAL_ID) as COUNT
from ANIMAL_OUTS
WHERE date_format(datetime,"%H") >=09 and date_format(datetime,"%H")<20
group by HOUR
ORDER BY HOUR

#2
SELECT *
FROM (SELECT date_format(datetime,"%H") as HOUR,count(ANIMAL_ID) as COUNT
      from ANIMAL_OUTS
      group by HOUR
      ORDER BY HOUR) as T
WHERE HOUR >=09 and HOUR<20

#왜인지는 모르겠지만 sub쿼리를 좋아함..
