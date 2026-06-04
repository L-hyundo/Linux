import socket

s = socket.socket()

s.connect(("127.0.0.1", 9000))

s.send("안녕하세요". encode())
