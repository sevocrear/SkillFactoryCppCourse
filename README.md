# SkillFactoryCppCourse

Добавьте в ваш проект чата логгирование сообщений от других участников чата и своих сообщений.

Для этого напишите класс Logger, через который будет проходить вся работа с файлом логов. Сохраняйте сообщения в файл на диске, можете назвать его log.txt. При создании объекта логгера должно производиться открытие файла, а при его разрушении — закрытие файла (концепт RAII).

Реализуйте в классе два метода:

запись строки логов в файл;
чтение одной строки из файла.
Конечно же, запись и чтение должны быть потокобезопасными — при одновременном вызове нескольких потоков с записью в файл и чтением из файла, не должно происходить взаимоблокировок и гонок данных.

Не забывайте про принципы инкапсуляции: код, пользующийся вашими методами чтения и записи, не должен знать про многопоточность.

# Reqs
```
sudo apt-get install libpq-dev postgresql-server-dev-all
sudo apt-get install postgresql
```

# Prepare database
```
sudo -u postgres psql -c 'create database chat_database;'
sudo -u postgres psql chat_database
```
1. Set password
```
ALTER USER postgres WITH PASSWORD 'pass';
```
2. Create `messages` table
```
CREATE TABLE messages (
    id SERIAL PRIMARY KEY,
    "to" VARCHAR(100) NOT NULL,
    "from" VARCHAR(100) NOT NULL,
    text TEXT NOT NULL,
    date DATE NOT NULL
);
```
3. Create `users` table
```
CREATE TABLE users (
    id SERIAL PRIMARY KEY,
    alias VARCHAR(100) UNIQUE NOT NULL,
    name VARCHAR(100) NOT NULL,
    surname VARCHAR(100) NOT NULL,
    login VARCHAR(100) UNIQUE NOT NULL;
);
```
4. Create `password_hashes` table
```
CREATE TABLE password_hashes (
    id SERIAL PRIMARY KEY,
    user_id INTEGER UNIQUE NOT NULL,
    hash VARCHAR(100)
);
```
5. **Добавить возможность:** при добавлении пользователя в таблицу пользователей также создаётся пользователь в таблице хэш паролей, при этом _id_ пользователя совпадает, а хэш пароля — `NULL`.

Для этого создадим триггер и определим функцию.

`Функция`
```
CREATE FUNCTION add_password_hash()
    RETURNS TRIGGER AS $$
BEGIN
    INSERT INTO password_hashes (user_id, hash)
    VALUES (NEW.id, NULL);
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;
```
`Триггер`
```
CREATE TRIGGER add_password_hash
    AFTER INSERT ON users
    FOR EACH ROW
    EXECUTE FUNCTION add_password_hash();
```
6. При удалении пользователя из таблицы users данные о нём должны удаляться из таблицы хэша паролей

> Необходимо создать триггер и функцию, которые будут выполнять это действие.

```
CREATE FUNCTION delete_password_hash()
    RETURNS TRIGGER AS $$
BEGIN
    DELETE FROM password_hashes WHERE user_id = OLD.id;
    RETURN OLD;
END;
$$ LANGUAGE plpgsql;
```
```
CREATE TRIGGER delete_password_hash
    AFTER DELETE ON users
    FOR EACH ROW
    EXECUTE FUNCTION delete_password_hash();
```

7.  Создание внешнего ключа между таблицами `users` и `password_hashes`

> Чтобы связать таблицы `users` и `password_hashes`, необходимо создать внешний ключ на поле `user_id` таблицы `password_hashes`. При удалении записи из таблицы `users` также будут удаляться все записи из таблицы `password_hashes`, связанные с этой записью.

```
ALTER TABLE password_hashes
ADD CONSTRAINT fk_user_id
FOREIGN KEY (user_id)
REFERENCES users (id)
ON DELETE CASCADE;
```

8.  Создание внешнего ключа между таблицами `messages` и `users`

Проблема, возникающая при удалении пользователя, заключается в том, что его alias, который используется в таблице `messages` в качестве внешнего ключа, останется в таблице сообщений, что может привести к ошибкам при последующих запросах.

Для решения этой проблемы можно использовать оператор `ON DELETE CASCADE` при создании внешнего ключа между таблицами `messages` и `users`.


```
ALTER TABLE messages
ADD CONSTRAINT fk_to
FOREIGN KEY ("to")
REFERENCES users (alias)
ON DELETE CASCADE;

ALTER TABLE messages
ADD CONSTRAINT fk_from
FOREIGN KEY ("from")
REFERENCES users (alias)
ON DELETE CASCADE;
```

Теперь, при удалении пользователя из таблицы `users`, все записи в таблице `messages`, где его `alias` использовался в качестве `to` или `from`, также будут удалены.

9. Добавьте юзера `all`:
```
INSERT INTO users (alias, name, surname, login)
VALUES ('all', 'all', 'all', 'all');
```

10. Если нужно удалить юзера:
```
DELETE FROM users WHERE alias = 'Viking2';
```

# CMake Execute
```
cd Chat && mkdir build && cd build
cmake .. && cmake --build .
```

Chat Program with PostgreSQL Database

* Using this library: [taopq](https://github.com/taocpp/taopq)

![Structure of database](Chat/database.png)

# TODO:

&#9744; Hide DB login and password


# References
* [Guide to work with files](https://www.studyplan.dev/pro-cpp/file-streams)