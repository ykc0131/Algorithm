-- 코드를 입력하세요
SELECT BOOK_ID, AUTHOR_NAME, date_format(PUBLISHED_DATE,'%Y-%m-%d') as PUBLISHED_DATE
FROM BOOK join AUTHOR on BOOK.AUTHOR_ID = AUTHOR.AUTHOR_ID
WHERE CATEGORY='경제'
ORDER BY PUBLISHED_DATE ASC