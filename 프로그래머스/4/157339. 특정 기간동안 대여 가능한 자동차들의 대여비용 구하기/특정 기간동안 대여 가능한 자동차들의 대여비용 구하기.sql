-- 코드를 입력하세요
SELECT 
    CAR_AVA.CAR_ID, 
    CAR_AVA.CAR_TYPE,
    FLOOR(DAILY_FEE*30*(100-DISCOUNT_RATE)/100) as FEE
FROM 
    ( SELECT 
            CAR_ID,
            CAR_TYPE,
            DAILY_FEE
        FROM 
            CAR_RENTAL_COMPANY_CAR 
        WHERE CAR_ID NOT IN ( SELECT DISTINCT CAR_ID
                                    FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
                                    WHERE (date_format(START_DATE,'%Y-%m-%d') <= '2022-11-30')
                                           AND
                                           (date_format(END_DATE,'%Y-%m-%d') >= '2022-11-01')
                                ) 
    ) as CAR_AVA 
     JOIN
    ( SELECT 
            CAR_TYPE,
            DISCOUNT_RATE
        FROM CAR_RENTAL_COMPANY_DISCOUNT_PLAN
        WHERE DURATION_TYPE="30일 이상"
    ) as CAR_DIS
    ON
    CAR_AVA.CAR_TYPE = CAR_DIS.CAR_TYPE
WHERE 
    (CAR_AVA.CAR_TYPE = '세단' 
     OR CAR_AVA.CAR_TYPE = 'SUV')
     AND DAILY_FEE*30*(100-DISCOUNT_RATE)/100 BETWEEN 500000 AND 1999999
ORDER BY FEE DESC, CAR_TYPE ASC, CAR_ID DESC




# SELECT 
#         *
#         FROM 
#             CAR_RENTAL_COMPANY_CAR 
#             JOIN
#             CAR_RENTAL_COMPANY_RENTAL_HISTORY
#             ON
#             CAR_RENTAL_COMPANY_CAR.CAR_ID = CAR_RENTAL_COMPANY_RENTAL_HISTORY.CAR_ID
#         WHERE CAR_RENTAL_COMPANY_CAR.CAR_TYPE = '세단' 
#                 or CAR_RENTAL_COMPANY_CAR.CAR_TYPE = 'SUV'
#                 and date_format(end_date,'%Y-%m-%d') <= "2022-11-01"
#         ORDER BY end_date

# SELECT 
#     CAR_RENTAL_COMPANY_CAR.*
# FROM 
#     CAR_RENTAL_COMPANY_CAR 
# WHERE (CAR_TYPE = '세단' 
#         OR CAR_TYPE = 'SUV')
#          AND CAR_ID NOT IN (SELECT CAR_ID
#                         FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
#                         WHERE (date_format(START_DATE,'%Y-%m-%d') BETWEEN '2022-11-01' AND '2022-11-31')
#                                 OR 
#                                 (date_format(END_DATE,'%Y-%m-%d') BETWEEN '2022-11-01' AND '2022-11-31')
#                        )



# SELECT *, if((date_format(START_DATE,'%Y-%m-%d') <= '2022-11-30')
#                AND
#                (date_format(END_DATE,'%Y-%m-%d') > '2022-11-01'),
#                 'X','O') as ava
# FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
# ORDER BY START_DATE DESC