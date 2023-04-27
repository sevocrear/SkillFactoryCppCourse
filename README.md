# SkillFactoryCppCourse

В этом бранче находится реализация чата с использованием TCP. 

Проект разделен на три директории:

* **Chat** - код чата, сообщение при использовании которого сохр-ся в файл `messages_info_send.txt`
* **Chat_server** - код сервера, который получает сообщения из сети и грузит их в файл `messages_info_receive.txt`
* **Chat_client** - код клиента, который читает обновления у текущего юзера в файле `messages_info_send.txt` и в случае обновления отправляет сообщение в сеть

Формат передаваемого сообщения: `from to message`

# Порядок запуска

## Забилдите все три проекта

### Пример
```
cd Chat && mkdir build && cd build && cmake .. && make && cd ../..
cd Chat_server && mkdir build && cd build && cmake .. && make && cd ../..
cd Chat_client && mkdir build && cd build && cmake .. && make && cd ../..
```


## Запустите программы в следующем порядке:

```
./Chat/build/chat
```

```
./Chat_server/build/server
```

```
./Chat_client/build/client
```