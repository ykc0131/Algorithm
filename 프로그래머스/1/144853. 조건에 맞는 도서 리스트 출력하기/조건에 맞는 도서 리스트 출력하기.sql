-- 코드를 입력하세요
SELECT BOOK_ID, date_format(PUBLISHED_DATE,'%Y-%m-%d') as date_format
FROM BOOK
WHERE CATEGORY='인문' and date_format(PUBLISHED_DATE,'%Y')="2021"
ORDER BY PUBLISHED_DATE ASC