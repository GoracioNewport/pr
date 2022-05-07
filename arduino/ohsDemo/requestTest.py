import requests

data = {
	"chat_id":"754067951",
	"text":"Алина Я тебя люблю :))))"
}

requests.post("https://api.telegram.org/bot5260885793:AAFqbuPkUtOjAO-rD9TZLA0Gv8zfIb30Bag/sendMessage", json=data)