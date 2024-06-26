# UAZ24_KST8_CompSec Syllabus

Хранилище за упражнения по дисциплина "Комп. сигурност" за спец. КСТ, група 8 в Университет "Проф. д-р Асен Златаров", гр. Бургас

## Първо упражнение
- Проверка на число дали е просто чрез тривиална проверка за наличност на делители [is_prime.c](https://github.com/peshopbs2/UAZ24_KST8_CompSec/blob/main/is_prime.c)
- Решето на Ератостен [eratosten.c](https://github.com/peshopbs2/UAZ24_KST8_CompSec/blob/main/eratosten.c)

## Второ упражнение
- Цезаров шифър [caesar_cypher.c](https://github.com/peshopbs2/UAZ24_KST8_CompSec/blob/main/caesar_cypher.c)

## Трето упражнение
- Дешифриране на Цезаров шифър с въвеждане на шифъра и ключа [ceasar_decode_input.c](https://github.com/peshopbs2/UAZ24_KST8_CompSec/blob/main/ceasar_decode_input.c)
- Дешифриране на Цезаров шифър, който се въвежда от файл и въвеждане на ключ [ceasar_decode_file.c](https://github.com/peshopbs2/UAZ24_KST8_CompSec/blob/main/ceasar_decode_file.c)

```
Домашна работа:
Напишете програма, която въвежда текст и генерира Цезаров шифър на текста. Програмата трябва да поддържа малки и големи латински букви, цифри и разстояние.
Напишете и програма, която въвежда шифър и ключ и декодира въведения шифър.
Бонус: добавете поддръжка на специални символи.
Бонус 2: Добавете употреба на файлове.
```

## Четвърто упражнение
- Разбиване на Цезаров шифър с пермутации [caesar_bruteforce.c](https://github.com/peshopbs2/UAZ24_KST8_CompSec/blob/main/caesar_bruteforce.c)
- Разбиване на Цезаров шифър с анализ на честотата [ceasar_frequency_decode.c](https://github.com/peshopbs2/UAZ24_KST8_CompSec/blob/main/ceasar_frequency_decode.c)

## Пето упражнение
- Шифър на Виженер [vigenere_cypher.c](https://github.com/peshopbs2/UAZ24_KST8_CompSec/blob/main/vigenere_cypher.c)
- Разкодиране на шифър на Виженер [vigenere_decrypt.c](https://github.com/peshopbs2/UAZ24_KST8_CompSec/blob/main/vigenere_decrypt.c)

```
Домашна работа:
1. Добавете възможност на програмата да чете съобщение от файл, да се въвежда само ключ и да генерира файл с криптираното съобщение.
2. Добавете възможност на програмата да чете съобщение от файл, да чете отделен файл с ключа и да генерира файл с декриптирано съобщение.
3. Напишете програма, която разбива шифър на Виженер без да е известен ключа. Програмата да използва анализ на честотата. (проучете в Интернет как се модифицира анализа на честота, спрямо шифъра на Цезар)
4. Напишете програма, която разбива шифъра на Виженер по метода на Касиски.
```

## Шесто упражнение
- Контролна

## Седмо упражнение
- Работа с OpenSSL - криптиране с DES [des_encrypt.c](https://github.com/peshopbs2/UAZ24_KST8_CompSec/blob/main/des_encrypt.c)

## Осмо упражнение
- Работа с OpenSSL - декриптиране с DES [des_decrypt.c](https://github.com/peshopbs2/UAZ24_KST8_CompSec/blob/main/des_encrypt.c)

## Девето упражнение
- Работа с OpenSSL - генериране на RSA ключ [rsa_generate_keys.c](https://github.com/peshopbs2/UAZ24_KST8_CompSec/blob/main/rsa_generate_keys.c)
- Работа с OpenSSL - криптиране с RSA [rsa_encrypt_key.c](https://github.com/peshopbs2/UAZ24_KST8_CompSec/blob/main/rsa_encrypt_key.c)

## Десето упражнение
- Декриптиране с RSA [rsa_decrypt.c](https://github.com/peshopbs2/UAZ24_KST8_CompSec/blob/main/rsa_decrypt.c)

## Единадесето упражнение
- Хеширане с MD5 и SHA-алгоритмите

## Дванадесето упражнение
- Brute force атака на MD5/SHA-x хеш

## Тринадесето упражение
- Речникова атака на MD5/SHA-x хеш

## Четиринадесето упражнение
- Атака на /etc/shadow файл

## Петнадесето упражнение
- Общи упражнения
