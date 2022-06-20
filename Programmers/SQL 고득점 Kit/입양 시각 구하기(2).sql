with RECURSIVE TIME as (
    select 0 as H
    union all
    select H+1 from TIME where H<23
)
SELECT TIME.H as HOUR, ifnull(C,0) as COUNT
FROM TIME left join 
     (SELECT date_format(datetime,"%H") as H,count(ANIMAL_ID) as C
      from ANIMAL_OUTS
      group by H
      ORDER BY H) as T on TIME.H = T.H
